kern_c_files = []
kern_asm_files = []
kern_includes = []
kern_ldflags = []

if get_option('platform') == 'i386'
  subdir('i386')
endif

subdir('kernel')

kern_asm_outputs = kern_asm.process(kern_asm_files)

kernel_elf = executable(
  'kernel.elf',
  [kern_asm_outputs, kern_c_files],
  c_args: kern_c_cflags,
  link_args: kern_ldflags,
  include_directories: kern_includes,
)

qemu = run_target(
  'qemu',
  command: qemu_args,
  depends: [kernel_elf],
)
