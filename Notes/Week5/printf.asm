extern printf

section .data
msg1    db "The value of var1 %d var2 %d", 10, 0
var1    dd 256
var2    dd 512

section .text
global  _start

_start:

	mov rax, 0
	mov rdi, msg1

	xor rsi, rsi
	mov esi, dword [var1]

	xor rdx, rdx
	mov edx, dword [var2]

	call printf

exit:
	mov rax, 60
	mov rdi, 0
	syscall
