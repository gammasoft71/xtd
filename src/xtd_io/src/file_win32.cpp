#if defined(_WIN32)

#include "../include/xtd/file.hpp"
#include <Windows.h>

int __get_file_attributes(const char*path) {
  return GetFileAttributes(path);
}
#endif
