#include "../../../include/xtd/io/file.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::io;

int file::__get_file_attributes(const char8_t* path) {
  return native::file::get_attributes(string(ustring(path)));
}
