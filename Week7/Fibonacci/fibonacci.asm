section .text
global  fibonacci

fibonacci:
	push rbp
	mov  rbp, rsp

	add rdi, 4
	mov dword [rdi - 4], 1
	mov dword [rdi], 1
	add rdi, 4
	dec rsi

.loop:
	xor rax, rax
	add eax, [rdi - 8]
	add eax, [rdi - 4]
	mov [rdi], eax
	add rdi, 4

	dec rsi
	cmp rsi, 0
	jnz .loop

done:
	pop rbp

	ret
