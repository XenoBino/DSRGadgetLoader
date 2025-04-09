project('DSRGadgetLoader', 'c', version: '1.0')

sources = [
  'src/base.c',
  'src/main.c',
  'src/util.c',
  'src/log.c',
]

link_args = []
compile_args = []

# Generate pdb files on gcc
if meson.get_compiler('c').get_id() == 'gcc'
  compile_args += '-g'
  compile_args += '-gcodeview'
  link_args += '-Wl,--pdb=DSRGadgetLoader.dll.pdb'
endif

shared_library(
  'DSRGadgetLoader',
  sources,
  c_args: compile_args,
  link_args: link_args
)

meson.add_install_script('scripts/meson-install.sh')
