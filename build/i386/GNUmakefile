.PHONY: qemu clean

SYSROOT=../../sys

CC=gcc
CPPFLAGS=-I.
CFLAGS=-m32 -ffreestanding -nostdlib -fno-builtin

AS=nasm
ASFLAGS=-f elf32

LD=gcc
LDFLAGS=-m32 -nostdlib -ffreestanding -static -T $(SYSROOT)/i386/conf/linker.ld

# Extend the Makefile
vpath %.h machine
vpath %.c $(SYSROOT)/i386/i386
vpath %.c $(SYSROOT)/kernel
vpath %.asm $(SYSROOT)/i386/i386
vpath %.ld $(SYSROOT)/i386/conf
%.o: %.asm
	$(AS) $(ASFLAGS) -o $@ $<
#####################

kernel: linker.ld boot.o main.o console.o
	$(LD) $(LDFLAGS) -o $@ *.o

boot.o: boot.asm
main.o: main.c platform.h
console.o: console.c platform.h

qemu: kernel
	qemu-system-i386 -kernel kernel

clean:
	rm -f kernel *.o
