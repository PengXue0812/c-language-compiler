extern printf

section .data
  format db "%d",0ah,0dh

print_int_i:
	enter	0,0
	pusha
	pushf

    push  eax
    push  format
    call  printf
	pop	ecx
	pop	ecx

	popf
	popa
	leave
	ret