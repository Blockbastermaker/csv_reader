import os

AddOption(
  '--enable-debug',
  action='store_true',
  help='debug build',
  default=False)

CFlags = ["-std=c++14"]

IncludePath = []

Libs = []
LibPath = []

LinkFlags = []

# build env
env = Environment(
  CPPPATH=IncludePath,
  LIBPATH=LibPath,
  LIBS=Libs,
  CCFLAGS=CFlags,
  LINKFLAGS=LinkFlags
)
env['ENV']['TERM'] = os.environ['TERM'] # enabled colors in terminal

if GetOption('enable_debug'):
  variant_dir = "debug"
  env.AppendUnique(CCFLAGS=["-g", "-O0"])
else:
  variant_dir = "opt"
  env.AppendUnique(CCFLAGS=["-O3", "-fPIC"])

Export('env')
SConscript(dirs=".",
  variant_dir="build/" + variant_dir,
  duplicate=False
)

