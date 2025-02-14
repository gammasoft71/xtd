#include "../../../include/xtd/io/file_system_info.hpp"
#include "../../../include/xtd/io/io_exception.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/io/path_too_long_exception.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/platform_not_supported_exception.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file_system>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace io;

file_attributes file_system_info::attributes() const {
  return attributes_;
}

file_system_info& file_system_info::attributes(file_attributes value) {
  auto result = native::file_system::set_attributes(full_path_, as<int32>(value));
  if (result == -1) throw platform_not_supported_exception {};
  if (result != 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::io);
  attributes_ = value;
  return *this;
}

const date_time& file_system_info::creation_time() const {
  return creation_time_;
}

file_system_info& file_system_info::creation_time(const date_time& value) {
  auto result = native::file_system::set_creation_time(full_path_, value.to_time_t());
  if (result == -1) throw platform_not_supported_exception {};
  if (result != 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::io);
  creation_time_ = value;
  return *this;
}

xtd::date_time file_system_info::creation_time_utc() const {
  return creation_time().to_universal_time();
}

xtd::io::file_system_info& file_system_info::creation_time_utc(const xtd::date_time& value) {
  return creation_time(value.to_local_time());
}

string file_system_info::extension() const {
  return path::get_extension(full_path_);
}

string file_system_info::full_name() const {
  return full_path_;
}

const date_time& file_system_info::last_access_time() const {
  return last_access_time_;
}

file_system_info& file_system_info::last_access_time(const date_time& value) {
  auto result = native::file_system::set_last_access_time(full_path_, value.to_time_t());
  if (result == -1) throw platform_not_supported_exception {};
  if (result != 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::io);
  last_access_time_ = value;
  return *this;
}

xtd::date_time file_system_info::last_access_time_utc() const {
  return last_access_time().to_universal_time();
}

xtd::io::file_system_info& file_system_info::last_access_time_utc(const xtd::date_time& value) {
  return last_access_time(value.to_local_time());
}

const date_time& file_system_info::last_write_time() const {
  return last_write_time_;
}

file_system_info& file_system_info::last_write_time(const date_time& value) {
  auto result = native::file_system::set_last_write_time(full_path_, value.to_time_t());
  if (result == -1) throw platform_not_supported_exception {};
  if (result != 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::io);
  last_write_time_ = value;
  return *this;
}

xtd::date_time file_system_info::last_write_time_utc() const {
  return last_write_time().to_universal_time();
}

xtd::io::file_system_info& file_system_info::last_write_time_utc(const xtd::date_time& value) {
  return last_write_time(value.to_local_time());
}

file_permissions file_system_info::permissions() const {
  return permissions_;
}

file_system_info& file_system_info::permissions(file_permissions value) {
  auto result = native::file_system::set_permissions(full_path_, as<int32>(value));
  if (result == -1) throw platform_not_supported_exception {};
  if (result != 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::io);
  permissions_ = value;
  return *this;
}

void file_system_info::refresh() {
  full_path_ = native::file_system::get_full_path(original_path_);
  if (native::file_system::is_path_too_long(full_path_)) throw path_too_long_exception {};
  auto attributes = 0;
  if (native::file_system::get_attributes(full_path_, attributes) == 0) {
    attributes_ = as<xtd::io::file_attributes>(attributes);
    auto creation_time = time_t {}, last_access_time = time_t {}, last_write_time = time_t {};
    native::file_system::get_file_times(full_path_, creation_time, last_access_time, last_write_time);
    creation_time_ = date_time::from_time_t(creation_time, date_time_kind::local);
    last_access_time_ = date_time::from_time_t(last_access_time, date_time_kind::local);
    last_write_time_ = date_time::from_time_t(last_write_time, date_time_kind::local);
    auto permissions = as<int32>(file_permissions::unknown);
    if (native::file_system::get_permissions(full_path_, permissions) == 0) permissions_ = as<xtd::io::file_permissions>(permissions);
  }
}

string file_system_info::to_string() const noexcept {
  return original_path_;
}
