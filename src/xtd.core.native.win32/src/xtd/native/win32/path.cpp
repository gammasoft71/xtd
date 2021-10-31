#define UNICODE
#define _CRT_SECURE_NO_WARNINGS
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/path.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <string>
#include <direct.h>
#include <Windows.h>

using namespace std;
using namespace xtd::native;

#undef max
#undef min

char path::alt_directory_separator_char() {
  return '/';
}

char path::directory_separator_char() {
  return '\\';
}

string path::get_temp_path() {
  if (getenv("TMP") != nullptr)  return getenv("TMP");
  if (getenv("TEMP") != nullptr) return getenv("TEMP");
  if (getenv("USERPROFILE") != nullptr) return getenv("USERPROFILE");
  return getenv("WINDIR");
}

vector<char> path::invalid_path_chars() {
  return {34, 60, 62, 124, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0};
}

char path::path_separator() {
  return ';';
}

char path::volume_separator_char() {
  return ':';
}
