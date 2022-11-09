lex reader.l
yacc -d grammer.y
gcc -o test lex.yy.c y.tab.c
./test