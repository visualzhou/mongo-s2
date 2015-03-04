import libdeps

VariantDir('build', 'src')

env = Environment(
  CXX = 'clang++',
  CXXFLAGS = '-std=c++11 -stdlib=libc++ -Wno-deprecated -Wno-format',
  LINKFLAGS = '-stdlib=libc++'
)
# env.Append(CCFLAGS=['-I$BUILD_DIR'])

libdeps.setup_environment( env )

use_clang = True
Export('env', 'use_clang')
SConscript('build/SConscript')
