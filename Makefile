c_compiler:
		yacc -d c_compiler.y
		sed -i "1i \#include \"Node/BaseNode.h\"" y.tab.h
		sed -i "2i \#include \"Node/BTNode.h\"" y.tab.h
		sed -i "3i \#include \"Symbol/Symbol.h\"" y.tab.h
		g++ y.tab.c lex.yy.c Node/BaseNode.cpp Symbol/Symbol.cpp  -o a.out
clean:
	rm -f y.tab.c y.tab.h a.out