extern exit

section .text
global main
main:
push ebx
mov ebp,esp

mov [ebp+4],dword 50
mov ebx,dword 0
sub ebx,dword 1
mov [ebp+8],ebx
mov [ebp+12],dword 0

label5:
mov edx,[ebp+12]
cmp edx,[ebp+4]
jl label0
jmp label1

label0:
mov edx,[ebp+8]
cmp edx,[ebp+12]
jg label2
jmp label3

label3:
xor edx,edx
mov eax,dword[ebp+8]
mov ebx,dword 2
div ebx
mov ebx,edx
cmp ebx,dword 1
je label4
jmp label2

label2:
xor edx,edx
mov eax,dword 3
mov ebx,dword 2
div ebx
mov ebx,eax
sub [ebp+8],ebx
mov ebx,[ebp+8]
mov [ebp+8],ebx
jmp label0

label4:
xor ebx,ebx
mov ebx,dword[ebp+12]
add ebx,dword 1
mov [ebp+12],ebx
jmp label5

label1:
mov eax,[ebp+8]

call print_int_i

pop ebx
push 0
call exit
%include './AsmCode/print_int_i.asm'