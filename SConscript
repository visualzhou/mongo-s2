# -*- mode: python -*-

Import("env", "use_clang")

env = env.Clone()

env.SConscript( [
	"base/SConscript",
	"strings/SConscript",
	"util/coding/SConscript",
	"util/math/SConscript",
        ], exports={ 'env' : env })

# env.Append(CCFLAGS=['-DDEBUG_MODE=false'])
env.Append(CCFLAGS=['-I.'])

# Clang warns about struct/class tag mismatch, but as long as this is
# not a problem on Windows, these mismatches can be ignored
# http://stackoverflow.com/questions/4866425/mixing-class-and-struct. W
# warning so it doesn't become an error.
if use_clang:
    env.Append(CCFLAGS=['-Wno-mismatched-tags'])

env.Library( "s2",
    [
	"s1angle.cc",
	"s2.cc",
	"s2cellid.cc",
	"s2latlng.cc",
	"s1interval.cc",
	"s2cap.cc",
	"s2cell.cc",
	"s2cellunion.cc",
	"s2edgeindex.cc",
	"s2edgeutil.cc",
	"s2latlngrect.cc",
	"s2loop.cc",
	"s2pointregion.cc",
	"s2polygon.cc",
	"s2polygonbuilder.cc",
	"s2polyline.cc",
	"s2r2rect.cc",
	"s2region.cc",
	"s2regioncoverer.cc",
	"s2regionintersection.cc",
	"s2regionunion.cc",
    ], LIBDEPS=['$BUILD_DIR/base/base',
		'$BUILD_DIR/strings/strings',
		'$BUILD_DIR/util/coding/coding',
		'$BUILD_DIR/util/math/math'])

#env.Program('r1interval_test', ['r1interval_test.cc'],
#            LIBDEPS=['s2', '$BUILD_DIR/third_party/gtest/gtest_with_main'])
#env.Program('s1angle_test', ['s1angle_test.cc'],
#            LIBDEPS=['s2', '$BUILD_DIR/third_party/gtest/gtest_with_main'])
#env.Program('s1interval_test', ['s1interval_test.cc'],
#            LIBDEPS=['s2', '$BUILD_DIR/third_party/gtest/gtest_with_main'])
#env.Program('s2regioncoverer_test', ['s2regioncoverer_test.cc'],
#            LIBDEPS=['s2', '$BUILD_DIR/third_party/gtest/gtest_with_main'])
#env.Program('s2_test', ['s2_test.cc'],
#            LIBDEPS=['s2', '$BUILD_DIR/third_party/gtest/gtest_with_main'])
