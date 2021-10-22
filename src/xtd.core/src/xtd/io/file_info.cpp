#include "../../../include/xtd/io/file_info.h"
#include "../../../include/xtd/io/directory_info.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/not_implemented_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace io;

file_info::file_info(const xtd::ustring& path) {
  refresh();
}

directory_info file_info::directory() const {
  return directory_info(directory_name());
}

ustring file_info::directory_name() const {
  return path::combine(path::get_path_root(full_path_), path::get_directory_name(full_path_));
}

bool file_info::exists() const {
  int32_t attributes = 0;
  return native::directory::get_file_attributes(full_path_, attributes) == 0 && (static_cast<file_attributes>(attributes) & file_attributes::directory) == file_attributes::directory;
}

bool file_info::is_read_only() const {
  return (attributes() & file_attributes::read_only) == file_attributes::read_only;
}

size_t file_info::length() const {
  return native::directory::get_file_size(full_path_);
}

ustring file_info::name() const {
  vector<ustring> items = full_path_.split({path::directory_separator_char()});
  if (items.size() == 0)
    return full_path_;
  return items[items.size() - 1];
}

void file_info::remove() {
  throw not_implemented_exception(csf_);
}
