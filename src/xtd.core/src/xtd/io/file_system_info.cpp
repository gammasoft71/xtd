#include "../../../include/xtd/io/file_system_info.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/io/path.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace io;

file_attributes file_system_info::attributes() const {
  return attributes_;
}

file_system_info& file_system_info::attributes(xtd::io::file_attributes value) {
  if (native::directory::set_file_attributes(full_path_, static_cast<int32_t>(value)) != 0)
    throw io::io_exception(csf_);
  attributes_ = value;
  return *this;
}

ustring file_system_info::extension() const {
  return path::get_extension(full_path_);
}

chrono::system_clock::time_point file_system_info::creation_time() const {
  return creation_time_;
}

chrono::system_clock::time_point file_system_info::last_access_time() const {
  return last_write_time_;
}

chrono::system_clock::time_point file_system_info::last_write_time() const {
  return last_write_time_;
}

size_t file_system_info::length() const {
  return length_;
}

ustring file_system_info::full_name() const {
  return full_path_;
}

bool file_system_info::is_empty(const file_system_info& file_system_info) {
  return ustring::is_empty(file_system_info.original_path_);
}

void file_system_info::refresh() {
  full_path_ = native::directory::get_full_path(original_path_);
  int32_t attributes = 0;
  if (native::directory::get_file_attributes(full_path_, attributes) == 0) {
    attributes_ = static_cast<xtd::io::file_attributes>(attributes);
    native::directory::get_file_times(full_path_, creation_time_, last_access_time_, last_write_time_);
    length_ = native::directory::get_file_size(full_path_);
  }
}

xtd::ustring file_system_info::to_string() const noexcept {
  return original_path_;
}
