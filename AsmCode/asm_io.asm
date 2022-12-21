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
mov [ebp-4],dword 0

label2:
xor edx,edx
mov eax,dword[ebp-4]
mov ebx,dword 2
mul ebx
mov ebx,eax
mov edx,[ebp-4]
cmp edx,ebx
jl label0
jmp label1

label0:
mov ecx,[ebp-8]
add ecx,[ebp-4]
mov [ebp-8],ecx
xor ecx,ecx
mov ecx,dword[ebp-4]
add ecx,dword 1
mov [ebp-4],ecx
jmp label2

label1:
mov eax,[ebp-8]

call print_int_i

pop ebx
push 0
call exit