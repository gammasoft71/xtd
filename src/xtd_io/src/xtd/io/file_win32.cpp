#if defined(_WIN32)

#include "../../../include/xtd/io/file.h"
#include <Windows.h>

int __get_file_attributes(const char*path) {
  return GetFileAttributes(path);
}
#endif
