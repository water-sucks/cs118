section .text

global add_sse

add_sse:
	push rbp
	mov  rbp, rsp

	cmp rcx, 4
	jl  .sum_rest; if size is less than four, add individually

.sum_four:
	movaps xmm0, [rdi]; mov 4 nums from one into xmm0
	addps  xmm0, [rsi]; add 4 nums from other into xmm0
	movaps [rdx], xmm0; mov 4 nums from xmm0 into dest

	add rdi, 16
	add rsi, 16
	add rdx, 16

	sub rcx, 4
	cmp rcx, 4
	jg  .sum_four
	jz  .done

.sum_rest:
	cmp rcx, 0
	jz  .done; finish if array is empty for some reason

	movss xmm0, [rdi]
	movss xmm1, [rsi]
	addss xmm0, xmm1
	movss [rdx], xmm0

	add rdi, 4
	add rsi, 4
	add rdx, 4

	dec rcx
	cmp rcx, 0
	jnz .sum_rest

.done:
	pop rbp
	ret
