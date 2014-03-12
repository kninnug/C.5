C.5
===

An extended version of C: C-and-a-half

Duff parser (assignment 2)
--------------------------

Named after Duff's device, which it can parse! (Amongst other things.) 

Use `make` (or `make ass2`) (for 'assignment 2' of course, what else?!) to build
the parser, the Makefile might not be entirely correct, so use `make -B ass2` 
when in doubt. By default it assumes the source code for Accent is in `accent/`,
and is already built (so go to `accent/accent` and run `make` before trying to
build the parser). 

It generates an `ass2` executable which takes two optional arguments: the first 
is the input file (stdin when not provided) and the second is the output 
(stdout when not provided). 

The parser will parse the input (-file) and produce a LaTeX-pretty printed 
output (-file) *without* `\\begin{document}` so it can be included directly 
into existing TeX files. 

### Overview of files:

* `ass2.flex` - Lexer-specification to be run through Flex
* `ass2.acc` - Parser-specification for Accent
* `auxil.c` - `main` function resides here
* `parser.h` - Common definitions for scanner & parser
* `samples.c` - Some example C-code
* `pretty.tex` - Result of running `ass2` with `samples.c` as input
* `report.tex` - The report's source file (does an include on `pretty.tex`)
* `Makefile` - Builds (only) the parser
* `accent/*` - Contains the (modified) Accent Compiler Compiler source
