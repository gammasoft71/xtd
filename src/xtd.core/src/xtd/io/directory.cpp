#include "../../../include/xtd/io/directory.h"
#include "../../../include/xtd/io/directory_info.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/path.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace io;

directory_info directory::create_directory(const xtd::ustring& path) {
  directory_info dir_info(path);
  if (!dir_info.exists()) {
    if (!ustring::is_empty(dir_info.parent().full_name()))
      create_directory(dir_info.parent().full_name());
    dir_info.create();
  }
  return dir_info;
}


void directory::move(const ustring& src, const ustring& dst) {
  if (path::has_extension(src))
    file::move(src, dst);
  else
    directory_info(src).move_to(dst);
}

void directory::remove(const xtd::ustring& path) {
  directory_info(path).remove();
}

void directory::remove(const xtd::ustring& path, bool recursive) {
  directory_info(path).remove(recursive);
}
