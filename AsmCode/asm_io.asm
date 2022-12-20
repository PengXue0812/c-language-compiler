extern exit

%include './AsmCode/print_int_i.asm'

section .text
global main
main:
push ebx
mov ebp,esp

mov [ebp-4],dword 10
mov eax,[ebp-4]

call print_int_i

pop ebx
push 0
call exit