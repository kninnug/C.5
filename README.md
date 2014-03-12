C.5
===

An extended version of C: C-and-a-half

Duff parser
-----------

Named after Duff's device, which it can parse! (Amongst other things.) 

Use `make ass2` (for 'assignment 2' of course, what else?!) to build the parser,
the Makefile might not be entirely correct, so use `make -B ass2` when in doubt. 

It generates an `ass2` executable which takes two optional arguments: the first 
is the input file (stdin when not provided) and the second is the output 
(stdout when not provided). 

The parser will parse the input (-file) and produce a LaTeX-pretty printed 
output (-file) *without* `\\begin{document}` so it can be included directly 
into existing TeX files.