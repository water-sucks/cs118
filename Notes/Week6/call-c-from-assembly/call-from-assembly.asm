extern comp

section .text
global  _start

_start:
	mov  rdi, 2
	mov  rsi, 1
	call comp
	mov  ebx, eax

exit:
	mov rax, 60
	mov rdi, 0
	syscall
