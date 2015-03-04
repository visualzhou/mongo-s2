env = Environment(
  BUILD_DIR="build",
  CXX = 'clang++',
  CXXFLAGS = '-std=c++11 -stdlib=libc++ -Wno-deprecated -Wno-format',
  LINKFLAGS = '-stdlib=libc++'
)

# def injectMongoIncludePaths(thisEnv):
#     thisEnv.AppendUnique(CPPPATH=['$BUILD_DIR'])
# env.AddMethod(injectMongoIncludePaths, 'InjectMongoIncludePaths')

# env.Append(CCFLAGS=['-I$BUILD_DIR'])

use_clang = True
Export('env', 'use_clang')
SConscript('SConscript')
