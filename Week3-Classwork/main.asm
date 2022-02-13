; An assembly program that subtracts and multiples two numbers, 69 - 10

section .data

EXIT_SUCCESS equ 0
SYS_EXIT equ 60

first dd 69;
second dd 10;

section .text
global _start
_start:
    ; subtraction
    mov eax, dword [first]
    sub eax, dword [second]

    ; multiplication
    mov eax, dword [first]
    mov ebx, dword [second]
    mul ebx ; result in eax
last:
    mov rax, SYS_EXIT
    mov rdi, EXIT_SUCCESS
    syscall
