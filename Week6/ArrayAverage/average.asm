section .data
length  dq 0

section .text
global  average

average:
	push rbp; put rbp onto stack
	mov  rbp, rsp; set stack frame pointer to current location in stack

	mov rcx, rsi; set array length to decrement
	mov qword [length], rsi; store length for later

	xor rax, rax

lp:
	add eax, [rdi]; fetch an array element, add to eax (values are ints, not long)
	add rdi, 4; add 4 to array pointer addrees for next int value

	dec rcx
	cmp rcx, 0
	jnz lp

done:
	pop rbp; move stack frame back to location from before

	xor rdx, rdx; div uses rdx:rax, no need for rdx here, it's a normal int
	mov rcx, qword [length]
	div rcx; only gets int average, remainder is in rdx and ignored

	ret
