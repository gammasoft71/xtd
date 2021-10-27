#include "../../../include/xtd/io/file_system_info.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/path_too_long_exception.h"
#include "../../../include/xtd/platform_not_supported_exception.h"
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
  auto result = native::directory::set_file_attributes(full_path_, static_cast<int32_t>(value));
  if (result != -1) throw platform_not_supported_exception(csf_);
  if (result != 0) throw io_exception(csf_);
  attributes_ = value;
  return *this;
}

chrono::system_clock::time_point file_system_info::creation_time() const {
  return creation_time_;
}

file_system_info& file_system_info::creation_time(chrono::system_clock::time_point value) {
  auto result = native::directory::set_creation_time(full_path_, value);
  if (result != -1) throw platform_not_supported_exception(csf_);
  if (result != 0) throw io_exception(csf_);
  creation_time_ = value;
  return *this;
}

ustring file_system_info::extension() const {
  return path::get_extension(full_path_);
}

ustring file_system_info::full_name() const {
  return full_path_;
}

chrono::system_clock::time_point file_system_info::last_access_time() const {
  return last_access_time_;
}

xtd::io::file_system_info& file_system_info::last_access_time(std::chrono::system_clock::time_point value) {
  auto result = native::directory::set_last_access_time(full_path_, value);
  if (result != -1) throw platform_not_supported_exception(csf_);
  if (result != 0) throw io_exception(csf_);
  last_access_time_ = value;
  return *this;
}

chrono::system_clock::time_point file_system_info::last_write_time() const {
  return last_write_time_;
}

xtd::io::file_system_info& file_system_info::last_write_time(std::chrono::system_clock::time_point value) {
  auto result = native::directory::set_last_write_time(full_path_, value);
  if (result != -1) throw platform_not_supported_exception(csf_);
  if (result != 0) throw io_exception(csf_);
  last_write_time_ = value;
  return *this;
}

bool file_system_info::is_empty(const file_system_info& file_system_info) {
  return ustring::is_empty(file_system_info.original_path_);
}

void file_system_info::refresh() {
  full_path_ = native::directory::get_full_path(original_path_);
  if (native::directory::is_path_too_long(full_path_)) throw path_too_long_exception(csf_);
  int32_t attributes = 0;
  if (native::directory::get_file_attributes(full_path_, attributes) == 0) {
    attributes_ = static_cast<xtd::io::file_attributes>(attributes);
    native::directory::get_file_times(full_path_, creation_time_, last_access_time_, last_write_time_);
  }
}

xtd::ustring file_system_info::to_string() const noexcept {
  return original_path_;
}
