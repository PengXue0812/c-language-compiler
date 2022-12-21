extern exit

section .text
global main
main:
push ebx
mov ebp,esp

mov [ebp-4],dword 1
mov eax,[ebp-4]

call print_int_i

mov eax,[ebp-4]

call print_int_i

pop ebx
push 0
call exit
%include './AsmCode/print_int_i.asm'