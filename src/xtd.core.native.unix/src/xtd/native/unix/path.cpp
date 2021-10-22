#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/path.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <string>
#include <unistd.h>
#include <sys/param.h>

using namespace std;
using namespace xtd::native;

char path::alt_directory_separator_char() {
  return '/';
}

char path::directory_separator_char() {
  return '/';
}

string path::get_temp_path() {
  auto tmp_path = getenv("TMPDIR");
  return tmp_path ? tmp_path : "/tmp/";
}

vector<char> path::invalid_path_chars() {
  return {34, 60, 62, 124, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0};
}

char path::path_separator() {
  return ':';
}

char path::volume_separator() {
  return '/';
}
