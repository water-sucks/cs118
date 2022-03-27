section .data
divide  db 3

section .text
global  make_grayscale

make_grayscale:
	push rbp
	mov  rbp, rsp

	mov r8, rdi
	mov r9, rdx
	mov r10, rdx
	add r10, rcx

.loop:
	xor rax, rax
	xor rcx, rcx

	movzx rcx, byte [r8]
	add   rax, rcx
	movzx rcx, byte [r8+1]
	add   rax, rcx
	movzx rcx, byte [r8+2]
	add   rax, rcx
	xor   rdx, rdx
	div   byte [divide]
	mov   [r9], al

	add r8, 3
	inc r9
	cmp r9, r10
	jne .loop

.done:
	pop rbp

	ret
