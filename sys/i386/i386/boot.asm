section .boot

align 4

multibootMagic equ 0x1BADB002
multibootFlags equ 0
multibootCheck equ -(multibootMagic + multibootFlags)

multibootHeader:
	dd multibootMagic
	dd multibootFlags
	dd multibootCheck


section .text

extern kernelMain

global bootMain
bootMain:
	mov esp, stackTop
	mov ebp, esp
	call kernelMain

bootDie:
	hlt
	jmp bootDie


section .bss

stackBottom:
resb 8192
stackTop:

; vim:ft=nasm
