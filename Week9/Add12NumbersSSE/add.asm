section .text

global add_sse

add_sse:
	push rbp
	mov  rbp, rsp

.parallel_sum:
	addps xmm0, [rdi]
	add   rdi, 16
	sub   rsi, 4

	cmp rsi, 4
	jge .parallel_sum

.parallel_end:
	haddps xmm0, xmm0
	haddps xmm0, xmm0

	cmp rsi, 0
	jz  .done

.sum_remaining:
	addss xmm0, [rdi]
	inc   rdi
	dec   rsi

	cmp rsi, 0
	jnz .sum_remaining

.done:
	pop rbp
	ret
