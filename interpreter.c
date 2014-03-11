struct jeContext * globalContext = NULL;

struct jeObject * interrupt_undefinedSymbol(struct jeContext * ctx, struct jeSymbol * sym, size_t offset);

struct jeObject * doList(struct jeContext * ctx, struct jeObject * list, struct jeList * args);

struct jeObject * jeLisp_resolve(struct jeContext * ctx, struct jeSymbol * sym, struct jeSymbol ** foundSym){
	struct jeSymbol * findSym;
	struct jeObject * ret, * recRet;
	
	findSym = jeScope_find(ctx->currentScope, sym, 0);
	if(findSym == NULL){
		ret = interrupt_undefinedSymbol(ctx, sym, 0);
		
		if(ret->flags & (OBJECTFLAG_RETURNCONTINUE)){
			ret->flags &= ~OBJECTFLAG_RETURNCONTINUE;
			return ret;
		}
		if(ret->flags & (OBJECTFLAG_RETURNEXIT | OBJECTFLAG_RETURNBREAK)) return ret;
		
		if(ret->type == jeObject_symbol){
			recRet = jeLisp_resolve(ctx, ret->value.d, foundSym);
			freeJeObject(ret);
			return recRet;
		}else{
			return ret;
		}
	}
	
	if(foundSym != NULL) *foundSym = findSym;
	
	return jeContext_get(ctx, findSym->index);
}

struct jeObject * runExpression(struct jeContext * ctx, struct jeExpression * exp){
	struct jeObject * cmd = NULL, * expCmd = NULL, * ret = NULL;
	struct jeList * args;
	struct jeSymbol * sym, * foundSym = NULL;
	size_t offset = 0;
	jeFunction fun;
	
	assert(ctx != NULL);
	assert(exp != NULL);
	
	/* implicit copy */
	args = runList(ctx, exp->args);
	
	/* cmd = <exp> | <scope> | <sym> | <list> */
	cmd = copyObject(exp->cmd);
	offset = cmd->offset;
	if(cmd->type == jeObject_expression && !(cmd->flags & OBJECTFLAG_QUOTED)){
		expCmd = runExpression(ctx, cmd->value.d);
		freeJeObject(cmd);
		cmd = expCmd;
		/* TODO: allow num/string? */
	}
	
	/* cmd = <scope> | <sym> | <list> | <val> */
	if(cmd->type == jeObject_symbol){
		sym = copySymbol(cmd->value.d);
		
		ret = copyObject(jeLisp_resolve(ctx, sym, &foundSym));
		freeJeObject(cmd);
		_free(sym->name);
		_free(sym);
		cmd = ret;
		
		assert(cmd != NULL);
	}
	
	/* cmd = <scope> | <val> | <list> | function */
	if(cmd->type == jeObject_scope){
		ret = runScope(ctx, cmd->value.d, args);
		freeJeObject(cmd);
		return ret;
	}
	
	/* cmd = <list> | <val> | function */
	if(cmd->type == jeObject_list){
		/* shortcut: if there are no arguments jeList_at will just return the list, skip it */
		if(args->length == 0){
			ret = cmd;
			freeJeList(*args);
			_free(args);
		}else{
			/* list was behind a symbol, pass it instead */
			if(foundSym != NULL){
				jeList_unshift(args, 1);
				jeList_add(args, makeObject(jeObject_number, 0, 0, makeInt(0)), makeObject(jeObject_symbol, 0, 0, copySymbol(foundSym)));
				ret = jeList_at(ctx, NULL, args);
			}else{
				ret = jeList_at(ctx, cmd, args);
			}
		}
		
		return ret;
	}
	
	/* cmd = <val> | function */
	if(cmd->type == jeObject_function){
		fun = cmd->value.f;
		ret = fun(ctx, cmd, args);
		freeJeObject(cmd);
		return ret;
	}
	
	if(args != NULL){
		freeJeList(*args);
		_free(args);
	}
	/* cmd = <val> */
	return cmd;
}

struct jeObject * runScope(struct jeContext * ctx, struct jeScope * scope, struct jeList * args){
	size_t i;
	int inherited = 0;
	struct jeObject * sym;
	struct jeObject * ret = NULL;
	struct jeScope * prevScope = NULL;
	
	assert(ctx != NULL);
	assert(scope != NULL);
	
	prevScope = ctx->currentScope;
	
	if(scope->parent == NULL){
		jeScope_adopt(ctx->currentScope, scope);
		inherited = 1;
	}
	ctx->currentScope = scope;
	scope->ctx = ctx;
	scope->children++;
	
	if(args != NULL && scope->argList != NULL) for(i = 0; i < args->_highLen; i++){
		if(args->keys[i] == NULL) continue;
		sym = jeList_get(scope->argList, args->keys[i], NULL);
		if(sym != NULL && sym->type == jeObject_symbol){
			sym = copyObject(sym);
			((struct jeSymbol*)(sym->value.d))->index = jeContext_add(ctx, copyObject(jeList_value(args, i)));
			jeScope_add(scope, sym->value.d);
			_free(sym);
		}
	}
	
	for(i = 0; i < scope->numTokens; i++){
		if(ret != NULL) freeJeObject(ret);
		ret = run(ctx, scope->tokens[i], NULL);
		if(ret->flags & OBJECTFLAG_RETURNCONTINUE){
			ret->flags &= ~OBJECTFLAG_RETURNCONTINUE;
			break;
		}
		if(ret->flags & OBJECTFLAG_RETURNBREAK){
			ret->flags &= ~(OBJECTFLAG_RETURNBREAK);
			ret->flags |= OBJECTFLAG_RETURNCONTINUE;
			break;
		}
		if(ret->flags & OBJECTFLAG_RETURNEXIT){
			break;
		}
	}
	
	if(args != NULL){
		freeJeList(*args);
		_free(args);
	}
	
	/* wprintf(L"@ inherited: %i / %u\n", inherited, scope->children); */
	
	if(inherited){
		jeScope_disown(scope, 0);
	}
	
	scope->children--;
	jeScope_reset(scope, inherited);
	
	ctx->currentScope = prevScope;
	
	return ret;
}

struct jeList * runList(struct jeContext * ctx, struct jeList * list){
	size_t i;
	struct jeList * ret;
	assert(ctx != NULL);
	assert(list != NULL);
	
	ret = _malloc(sizeof(struct jeList));
	ret->_alloced = list->_alloced;
	ret->_highLen = list->_highLen;
	ret->length = list->length;
	ret->keys = _calloc(ret->_alloced, sizeof(struct jeObject *));
	ret->values = _calloc(ret->_alloced, sizeof(struct jeObject *));
	
	for(i = 0; i < list->_highLen; i++){
		if(list->keys[i] == NULL) continue;
		ret->keys[i] = copyObject(list->keys[i]);
		if(isRunnable(*(list->values[i]), 0) || list->values[i]->type == jeObject_list){
			ret->values[i] = run(ctx, jeList_value(list, i), NULL);
		}else{
			ret->values[i] = copyObject(jeList_value(list, i));
		}
	}
	
	return ret;
}

struct jeObject * run(struct jeContext * ctx, struct jeObject * obj, struct jeList * args){
	assert(ctx != NULL);
	assert(obj != NULL);
	
	switch(obj->type){
		case jeObject_expression: return runExpression(ctx, obj->value.d);
		case jeObject_scope: return runScope(ctx, obj->value.d, args);
		case jeObject_list: return makeObject(jeObject_list, 0, obj->offset, runList(ctx, obj->value.d));
		default:
			return obj;
	}
	
	return obj;
}

struct jeObject * doList(struct jeContext * ctx, struct jeObject * list, struct jeList * args){
	jeList_unshift(args, 1);
	jeList_add(args, makeObject(jeObject_number, 0, 0, makeInt(0)), list);
	
	wprintf(L"@ doList: ");
	printJeList(*args);
	putwchar(L'\n');
	
	return jeList_at(ctx, list, args);
}

struct jeContext * makeContext(){
	size_t i;
	struct jeContext * ctx = _malloc(sizeof(struct jeContext));
	ctx->currentScope = _malloc(sizeof(struct jeScope));
	ctx->currentScope->argList = NULL;
	ctx->currentScope->numTokens = 0;
	ctx->currentScope->tokens = NULL;
	ctx->currentScope->nameTable = NULL;
	ctx->currentScope->parent = NULL;
	ctx->currentScope->interrupTable = NULL;
	ctx->currentScope->children = 1;
	ctx->currentScope->ctx = ctx;
	ctx->currentScope->beingReset = 0;
	
	ctx->length = 1;
	ctx->symbolTable  = _malloc(ctx->length*sizeof(struct jeCtxEntry*));
	for(i = 0; i < ctx->length; i++){
		ctx->symbolTable[i] = NULL;
	}
	ctx->firstEmpty = 0;
	
	return ctx;
}

void jeLisp_defnative(struct jeContext * ctx, const wchar_t * name, jeFunction fn){
	size_t len = wcslen(name);
	struct jeSymbol * sym = _malloc(sizeof *sym);
	struct jeObject * fnObj = makeObject(jeObject_function, 0, UNDEFINED_OFFSET, NULL);
	sym->index = jeContext_add(ctx, fnObj);
	
	fnObj->value.f = fn;
	sym->name = _malloc(len*sizeof(wchar_t));
	sym->length = len;
	memcpy(sym->name, name, len*sizeof(wchar_t));
	jeScope_add(ctx->currentScope, sym);
}

int jeLisp_set(struct jeContext * ctx, struct jeSymbol * key, struct jeObject * val, int global){
	struct jeSymbol * found = jeScope_find(ctx->currentScope, key, !global);
	int overWritten = 0;
	
	if(found == NULL){
		key->index = jeContext_add(ctx, val);
		jeScope_add(ctx->currentScope, key);
	}else{
		jeContext_set(ctx, found->index, val);
		overWritten = 1;
	}
	
	return overWritten;
}

struct jeObject * jeInterrupt_returnContinue(struct jeObject * value){
	value->flags |= OBJECTFLAG_RETURNCONTINUE;
	return value;
}

struct jeObject * jeInterrupt_returnBreak(struct jeObject * value){
	value->flags |= OBJECTFLAG_RETURNBREAK;
	return value;
}

struct jeObject * jeInterrupt_returnExit(struct jeObject * value){
	value->flags |= OBJECTFLAG_RETURNEXIT;
	return value;
}

struct jeSymbol * typeSymbol(){
	wchar_t * name = _malloc(255 * sizeof *name);
	size_t len = 0;
	
	wprintf(L"Type symbol: ");
	fflush(stdout);
	fgetws(name, 255, stdin);
	
	len = wcslen(name);
	if(name[len-1] == L'\n') name[len - 1] = L'\0';
	
	return makeSymbol(name, 0);
}

struct jeObject * interrupt_undefinedSymbol(struct jeContext * ctx, struct jeSymbol * sym, size_t offset){
	wprintf(L"! Undefined symbol: '");
	printJeSymbol(*sym);
	wprintf(L"', at: %u\n", offset);
	return makeObject(jeObject_symbol, 0, 0, typeSymbol());
	/* return jeInterrupt_returnExit(makeObject(jeObject_number, 0, 0, makeInt(0))); */
}

struct jeObject * _echo(struct jeContext * ctx, struct jeObject * cmd, struct jeList * args){
	struct jeObject * ret;
	
	if(args->length == 0) return makeObject(jeObject_invalid, 0, 0, NULL);
	
	wprintf(L"@ echo\n");
	printJeList(*args);
	putwchar(L'\n');
	
	ret = jeList_value(args, args->length-1);
	
	freeJeObject(jeList_key(args, args->length-1));
	
	jeList_delete(args, args->length-1, 1); /* remove val from the list so it isn't deleted next */
	freeJeList(*args);
	_free(args);
	
	return ret;
}

int main(int argc, char ** argv){
	wchar_t * code = L"{(= arr [a b c]) (arr 0 1)}";
/*L"\n\
{\
	(= x 0)\
	(= y 0)\
	{\
		($ x '{(a)})\
		($ y '{(b)})\
		\
		($ z '{(c)})\
		\
		(= a \"Hello \")\
		(= b \"world!\")\
		(= c \"foo\")\
	}\
	(echo [(x) (z)])\
}\
";*/
	size_t codeLen = wcslen(code);
	struct jeLinkedList * lst, * head;
	struct jeObject * exe, * ret;
	
	register unsigned long long int x = 16;
	
	lst = scan(code, codeLen);
	head = lst;
	exe = acceptRunnable(&lst);
	
	cleanList(head);
	freeList(head, 1);
	
	if(exe->type == jeObject_error){
		freeJeObject(exe);
		return 1;
	}
	
	globalContext = makeContext();
	
	jeLisp_defnative(globalContext, L"echo", _echo);
	jeLisp_defnative(globalContext, L"=", jeCore_set);
	jeLisp_defnative(globalContext, L"$", jeCore_defun);
	jeLisp_defnative(globalContext, L"@", jeList_at);
	
	wprintf(L"< ");
	printJeObject(*exe);
	putwchar(L'\n');
	
	ret = run(globalContext, exe, NULL);
	
	wprintf(L"> ");
	printJeObject(*ret);
	putwchar(L'\n');
	freeJeObject(ret);
	
	if(globalContext->currentScope->children != 1){
		wprintf(L"! globalContext->currentScope has not 1 child: %u!\n", globalContext->currentScope->children);
	}else{
		globalContext->currentScope->children--;
		jeScope_reset(globalContext->currentScope, 0);
	}
	
	freeContext(*globalContext);
	_free(globalContext);
	
	freeJeObject(exe);
	
	printMemStats();
	
	aleph >> 1;
	beth << 3;
	
	return 0;
}
