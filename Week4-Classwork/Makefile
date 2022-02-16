all: main.asm
	nasm -g -f elf64 main.asm
	ld -g -o main main.o

clean:
	$(RM) main main.o
