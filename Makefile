c_compiler:
	yacc -d c_compiler.y
	sed -i "1i \#include \"Node/BaseNode.h\"" y.tab.h
	sed -i "2i \#include \"Node/BTNode.h\"" y.tab.h
	sed -i "3i \#include \"Symbol/Symbol.h\"" y.tab.h
	sed -i "4i \#include \"AsmCode/AsmCode.h\"" y.tab.h
	sed -i "5i \#include \"AsmCode/AsmCodeGenerate.h\"" y.tab.h
	g++ y.tab.c lex.yy.c Node/BaseNode.cpp Symbol/Symbol.cpp InterCode/InterCode.cpp AsmCode/AsmCode.cpp AsmCode/AsmCodeGenerate.cpp -o compiler
	./compiler
	nasm -g -f elf -d ELF_TYPE ./AsmCode/result.asm -o ./AsmCode/result.o
	ld -m elf_i386 ./AsmCode/result.o -o result --entry main -lc -dynamic-linker /lib/ld-linux.so.2
	./result

clean:
	rm -f y.tab.c y.tab.h a.out