section .text
global  filter

filter:
	push rbp
	mov  rbp, rsp

.loop_beg:
	xor rax, rax
	add eax, [rdi]
	and rax, 1
	xor ebx, ebx

	cmp rax, 0
	jz  .even
	jnz .odd

.even:
	add ebx, [rdi]
	mov [rsi], ebx

	add rsi, 4
	jmp .loop_end

.odd:
	add ebx, [rdi]
	mov [rdx], ebx

	add rdx, 4
	jmp .loop_end

.loop_end:
	add rdi, 4

	dec rcx
	cmp rcx, 0
	jnz .loop_beg

done:
	pop rbp

	ret
