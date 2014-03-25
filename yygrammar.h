#ifndef YYGRAMMAR_H
#define YYGRAMMAR_H

#ifndef YYSTYPE
#define YYSTYPE long
#endif
extern YYSTYPE yylval;
extern long yypos;

#define EXP 307
#define INPUT 306
#define PRINT 305
#define INTCONST 304
#define FLOATCONST 303
#define CHARACTER 302
#define INCLUDE 301
#define SHIFT 300
#define IDENTIFIER 299
#define LOGICAL_AND 298
#define LOGICAL_OR 297
#define PTR_OP 296
#define DEC_OP 295
#define INC_OP 294
#define ARIT_OP 293
#define COMPARE 292
#define ASSIGN 291
#define ELLIPSIS 290
#define STRING 289
#define CONSTANT 288
#define WHILE 287
#define VOLATILE 286
#define VOID 285
#define UNSIGNED 284
#define UNION 283
#define TYPEDEF 282
#define SWITCH 281
#define STRUCT 280
#define STATIC 279
#define SIZEOF 278
#define SIGNED 277
#define SHORT 276
#define RETURN 275
#define REGISTER 274
#define LONG 273
#define INT 272
#define IF 271
#define GOTO 270
#define FOR 269
#define FLOAT 268
#define EXTERN 267
#define ENUM 266
#define ELSE 265
#define DOUBLE 264
#define DO 263
#define DEFAULT 262
#define CONTINUE 261
#define CONST 260
#define CHAR 259
#define CASE 258
#define BREAK 257
#define AUTO 256

#endif

