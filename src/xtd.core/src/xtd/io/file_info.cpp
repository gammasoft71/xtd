#include "../../../include/xtd/io/file_info.h"
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

bool file_info::exists() const {
  int32_t attributes = 0;
  return native::directory::get_file_attributes(full_path_, attributes) == 0 && (static_cast<file_attributes>(attributes) & file_attributes::directory) == file_attributes::directory;
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
