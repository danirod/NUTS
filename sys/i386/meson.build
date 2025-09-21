kern_asm = generator(
  find_program('nasm'),
  output: '@BASENAME@.o',
  arguments: ['-f', 'elf32', '-o', '@OUTPUT@', '@INPUT@']
)

kern_asm_files += files(
  'boot.asm',
)

kern_c_files += files(
  'console.c',
  'main.c',
)

kern_ldscript = files('linker.ld')[0].full_path()

kern_c_cflags = ['-m32', '-ffreestanding', '-nostdlib', '-fno-builtin']
kern_includes += include_directories('.')
kern_ldflags += ['-m32', '-nostdlib', '-ffreestanding', '-static', '-T', kern_ldscript]

qemu_args = ['qemu-system-i386', '-kernel', '@BUILD_ROOT@/sys/kernel.elf']
