.intel_syntax noprefix

.global comp
.text

comp:
	cmp rdi, rsi
	jg  .greater
	jle .lesser

.greater:
	mov eax, 1
	ret

.lesser:
	xor eax, eax
	ret
