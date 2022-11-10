# Makefile
c_compiler:c_compiler.l c_compiler.y ./Node/BaseNode.cpp
			g++ -c ./Node/BaseNode.cpp
			bison -d c_compiler.y
			flex -o c_compiler.lex.c c_compiler.l
			sed -i  "1i\#include \"./Node/BaseNode.h\"" c_compiler.tab.h
			g++ -o test BaseNode.o c_compiler.tab.c c_compiler.lex.c

clean:
		rm  *.tab.c  *.lex.c  *.h  *.o test	