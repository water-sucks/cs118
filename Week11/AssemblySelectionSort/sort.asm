section .text
global  selection_sort

selection_sort:
	push rbp
	mov  rbp, rsp

	mov rax, rdi
	mov rcx, rsi
	dec rcx

	xor r8, r8

.outer_loop:
	mov  rbx, rax
	push rax
	push rcx

	add rax, 4
	dec rcx

.inner_loop:
	xor rdx, rdx
	mov edx, [rax]

	cmp edx, [rbx]
	jge .inner_loop_end

	mov rbx, rax

.inner_loop_end:
	add rax, 4
	dec rcx
	cmp rcx, 0
	jge .inner_loop

.swap:
	pop rcx
	pop rax

	mov edx, [rbx]
	mov r8d, [rax]
	mov [rax], edx
	mov [rbx], r8d

.outer_loop_end:
	add  rax, 4
	loop .outer_loop

.done:
	pop rbp
	ret
