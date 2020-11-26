#if defined(_WIN32)

#include "../../../include/xtd/io/file.h"
#include <Windows.h>
#undef max
#undef min

int xtd::io::file::__get_file_attributes(const char*path) {
  return GetFileAttributes(path);
}
#endif
