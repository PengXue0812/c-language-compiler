section .data
int_format	    db  "%i", 0


section .text
extern printf


global main
main:
push ebx
mov ebp,esp
mov [ebp-4],dword 10
mov eax,dword 12
call print_int_i
pop ebx
mov ebx,0d
mov eax,1d
int 80h


print_int_i:
	enter	0,0
	pusha
	pushf

	push	eax
	push	dword int_format
	call	printf
	pop	ecx
	pop	ecx

	popf
	popa
	leave
	ret

