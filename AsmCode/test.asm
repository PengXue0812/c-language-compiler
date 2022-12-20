extern printf
extern exit
 
section .data
  format db "%d",0ah,0dh
section .text
 
global main
main:

    push ebx
    mov ebp,esp
    mov [ebp-4],dword 10
    mov eax,dword [ebp-4]
    call print_int_i
    pop ebx
    push 0
    call exit     ; exit(0)



print_int_i:
	enter	0,0
	pusha
	pushf


    push  eax
    push  format
    call  printf  ; printf(format, 2)
	pop	ecx
	pop	ecx

	popf
	popa
	leave
	ret