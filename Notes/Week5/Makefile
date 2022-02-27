all: example.asm
	nasm -g -f elf64 example.asm 
	ld -g -o example example.o

clean:
	$(RM) example example.o
