OUTPUT_ARCH(i386);
OUTPUT_FORMAT(elf32-i386);

ENTRY(bootMain)

SECTIONS
{
	. = 0x100000;
	.boot : { *(.boot) }
	.text : ALIGN(0x1000) { *(.text) }
	.bss : ALIGN(0x1000) { *(.bss) }
}
