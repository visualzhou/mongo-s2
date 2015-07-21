em++ -Isrc -std=c++11 --bind -s NO_EXIT_RUNTIME=1 -o s2.js \
"src/base/int128.cc" \
"src/base/logging.cc" \
"src/base/stringprintf.cc" \
"src/base/strtoint.cc" \
"src/strings/split.cc" \
"src/strings/stringprintf.cc" \
"src/strings/strutil.cc" \
"src/util/coding/coder.cc" \
"src/util/coding/varint.cc" \
"src/util/math/mathutil.cc" \
"src/s1angle.cc" \
"src/s2.cc" \
"src/s2cellid.cc" \
"src/s2latlng.cc" \
"src/s1interval.cc" \
"src/s2cap.cc" \
"src/s2cell.cc" \
"src/s2edgeutil.cc" \
"src/s2latlngrect.cc" \
"src/s2region.cc" \
"src/em_wrapper.cc"