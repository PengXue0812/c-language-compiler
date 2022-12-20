extern exit

%include './AsmCode/print_int_i.asm'

section .text
global main
main:
push ebx
mov ebp,esp

mov [ebp-4],dword 50
mov ebx,dword 0
sub ebx,dword 1
mov [ebp-8],ebx
mov [ebp-12],dword 1
mov [ebp-16],dword 1
xor edx,edx
mov eax,[ebp-12]
mul dword[ebp-16]
mov ebx,eax
xor edx,edx
mov ecx,dword 2
mov eax,ebx
div ecx
mov ecx,eax
add [ebp-8],ebx
mov ebx,[ebp-8]
xor edx,edx
mov eax,[ebp-12]
mul dword[ebp-16]
mov edx,eax
add ebx,edx
mov [ebp-8],ebx
mov eax,[ebp-8]

call print_int_i

pop ebx
push 0
call exit