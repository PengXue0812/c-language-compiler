# Makefile
c_compiler:
	lex -o $@.yy.c $@.l
	yacc -dtv $@.y -o $@.cpp
	cc -c $@.yy.c -o $@.yy.o
	g++ $@.yy.o $@.cpp -o $@.out