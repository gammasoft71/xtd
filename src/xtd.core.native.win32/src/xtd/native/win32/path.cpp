#define UNICODE
#define _CRT_SECURE_NO_WARNINGS
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/path>
#include "../../../../include/xtd/native/win32/strings.h"
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
  DWORD temp_path_size = 65535;
  std::wstring temp_path(temp_path_size, 0);
  GetTempPath(temp_path_size, temp_path.data());
  return win32::strings::to_string(temp_path.c_str());
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
