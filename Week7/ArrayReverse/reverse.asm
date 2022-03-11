section .text
global  reverse

reverse:
	push rbp
	mov  rbp, rsp

	mov r10, rdi; Beginning array pointer in r10
	mov r11, rdi; End array pointer in r11

	;   Calculate end index location
	mov rax, rsi
	shl rax, 2
	add r11, rax
	sub r11, 4
	xor rax, rax

	;   Calculate number of iterations
	mov r8, rsi
	shr r8, 1

.loop:
	xchg eax, dword [r10]
	mov  ecx, dword [r11]
	mov  dword [r11], eax
	mov  dword [r10], ecx

	;   Increment array position
	add r10, 4
	sub r11, 4

	;   Loop counter decrement
	dec r8
	cmp r8, 0
	jnz .loop

done:
	pop rbp

	ret
