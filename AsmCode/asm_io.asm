extern exit

section .text
global main
main:
push ebx
mov ebp,esp

mov [ebp+4],dword 5
mov ebx,dword 0
sub ebx,dword 1
mov [ebp+8],ebx
mov [ebp+12],dword 0

label5:
xor edx,edx
mov eax,dword[ebp+4]
mov ebx,dword 2
mul ebx
mov ebx,eax
mov edx,[ebp+12]
cmp edx,ebx
jl label0
jmp label1

label0:
mov [ebp+16],dword 0

label4:
mov edx,[ebp+16]
cmp edx,[ebp+4]
jl label2
jmp label3

label2:
xor edx,edx
mov eax,[ebp+12]
mul dword[ebp+16]
mov ecx,eax
mov [ebp+20],ecx
mov ecx,[ebp+8]
add ecx,[ebp+20]
mov [ebp+8],ecx
xor ecx,ecx
mov ecx,dword[ebp+16]
add ecx,dword 1
mov [ebp+16],ecx
jmp label4

label3:
xor ecx,ecx
mov ecx,dword[ebp+12]
add ecx,dword 1
mov [ebp+12],ecx
jmp label5

label1:
mov eax,[ebp+8]

call print_int_i

pop ebx
push 0
call exit
%include './AsmCode/print_int_i.asm'