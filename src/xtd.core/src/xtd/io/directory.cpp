#include "../../../include/xtd/io/directory.h"
#include "../../../include/xtd/io/directory_info.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace io;

void directory::remove(const xtd::ustring& path) {
  directory_info(path).remove();
}

void directory::remove(const xtd::ustring& path, bool recursive) {
  directory_info(path).remove(recursive);
}
