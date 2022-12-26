extern exit

section .text
global main
main:
push ebx
mov ebp,esp

mov [ebp+4],dword 2
mov [ebp+8],dword 3
mov eax,[ebp+4]

call print_int_i

mov eax,[ebp+8]

call print_int_i

mov edx,[ebp+4]
mov [ebp+4],edx
mov edx,[ebp+8]
mov [ebp+8],edx
mov edx,[ebp+8]
mov [ebp+12],edx
mov edx,[ebp+4]
mov [ebp+8],edx
xor edx,edx
mov eax,[ebp+12]
mul dword[ebp+8]
mov ebx,eax
xor edx,edx
mov eax,ebx
mul dword[ebp+4]
mov ebx,eax
xor edx,edx
mov eax,ebx
idiv dword[ebp+8]
mov ebx,eax
mov [ebp+4],ebx
mov eax,[ebp+4]

call print_int_i

mov eax,[ebp+8]

call print_int_i

pop ebx
push 0
call exit
%include './AsmCode/print_int_i.asm'