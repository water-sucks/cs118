section .text

global _start

_start:
    mov al, 255 ; this already overflows, but I wanted to set the carry bit.
    add al, 1 ; sets carry bit
    pushfq
    pop rcx

exit:
    mov rax, 60
    mov rdi, 0
    syscall
