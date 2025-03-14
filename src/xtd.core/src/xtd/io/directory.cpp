#include "../../../include/xtd/io/directory.hpp"
#include "../../../include/xtd/io/file_info.hpp"
#include "../../../include/xtd/io/directory_info.hpp"
#include "../../../include/xtd/io/directory_not_found_exception.hpp"
#include "../../../include/xtd/io/drive_info.hpp"
#include "../../../include/xtd/io/file.hpp"
#include "../../../include/xtd/io/io_exception.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/io/path_too_long_exception.hpp"
#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/not_supported_exception.hpp"
#include "../../../include/xtd/unauthorized_access_exception.hpp"
#include "../../../include/xtd/diagnostics/debug.hpp"
#include <algorithm>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory>
#include <xtd/native/file>
#include <xtd/native/file_system>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::helpers;
using namespace io;

struct directory::directory_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  directory_info::directory_iterator iterator_;
};

directory::directory_iterator::directory_iterator(const string& path, const string& pattern) {
  data_ = xtd::new_sptr<data>(path, pattern);
}

directory::directory_iterator::directory_iterator() {
  data_ = xtd::new_sptr<data>();
}

directory::directory_iterator& directory::directory_iterator::operator ++() {
  data_->iterator_++;
  return *this;
}

directory::directory_iterator directory::directory_iterator::operator ++(int32) {
  directory_iterator result = *this;
  ++(*this);
  return result;
}

bool directory::directory_iterator::equals(const directory::directory_iterator& other) const noexcept {
  return data_->iterator_ == other.data_->iterator_;
}

directory::directory_iterator::value_type directory::directory_iterator::operator *() const {
  if (data_ == nullptr) return "";
  return (*data_->iterator_).full_name();
}

directory::directory_iterator directory::directory_iterator::begin() const {
  return directory::directory_iterator {data_->iterator_.path(), data_->iterator_.pattern()};
}

directory::directory_iterator directory::directory_iterator::end() const {
  return directory::directory_iterator {};
}

struct directory::file_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  directory_info::file_iterator iterator_;
};

directory::file_iterator::file_iterator(const std::string& path, const std::string& pattern) {
  data_ = xtd::new_sptr<data>(path, pattern);
}

directory::file_iterator::file_iterator() {
  data_ = xtd::new_sptr<data>();
}

directory::file_iterator& directory::file_iterator::operator ++() {
  data_->iterator_++;
  return *this;
}

directory::file_iterator directory::file_iterator::operator ++(int32) {
  file_iterator result = *this;
  ++(*this);
  return result;
}

directory::file_iterator::value_type directory::file_iterator::operator *() const {
  if (data_ == nullptr) return "";
  return (*data_->iterator_).full_name();
}

directory::file_iterator directory::file_iterator::begin() const {
  return directory::file_iterator {data_->iterator_.path(), data_->iterator_.pattern()};
}

directory::file_iterator directory::file_iterator::end() const {
  return directory::file_iterator {};
}

bool directory::file_iterator::equals(const directory::file_iterator& other) const noexcept {
  return data_->iterator_ == other.data_->iterator_;
}

struct directory::file_system_entry_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  directory_info::file_system_info_iterator iterator_;
};

directory::file_system_entry_iterator::file_system_entry_iterator(const std::string& path, const std::string& pattern) {
  data_ = xtd::new_sptr<data>(path, pattern);
}

directory::file_system_entry_iterator::file_system_entry_iterator() {
  data_ = xtd::new_sptr<data>();
}

directory::file_system_entry_iterator& directory::file_system_entry_iterator::operator ++() {
  data_->iterator_++;
  return *this;
}

directory::file_system_entry_iterator directory::file_system_entry_iterator::operator ++(int32) {
  file_system_entry_iterator result = *this;
  ++(*this);
  return result;
}

directory::file_system_entry_iterator::value_type directory::file_system_entry_iterator::operator *() const {
  if (data_ == nullptr) return "";
  return (*data_->iterator_)->full_name();
}

directory::file_system_entry_iterator directory::file_system_entry_iterator::begin() const {
  return directory::file_system_entry_iterator {data_->iterator_.path(), data_->iterator_.pattern()};
}

directory::file_system_entry_iterator directory::file_system_entry_iterator::end() const {
  return directory::file_system_entry_iterator {};
}

bool directory::file_system_entry_iterator::equals(const directory::file_system_entry_iterator& other) const noexcept {
  return data_->iterator_ == other.data_->iterator_;
}

directory_info directory::create_directory(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw_helper::throws(exception_case::io);
  
  auto dir_info = directory_info {path};
  if (dir_info.exists()) return dir_info;
  
  if (!string::is_empty(dir_info.parent().full_name()))
    create_directory(dir_info.parent().full_name());
  dir_info.create();
  return dir_info;
}

directory::directory_iterator directory::enumerate_directories(const string& path) {
  return enumerate_directories(path, "*");
}

directory::directory_iterator directory::enumerate_directories(const string& path, const string& search_pattern) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw_helper::throws(exception_case::io);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  
  return directory_iterator {path, search_pattern};
}

directory::file_iterator directory::enumerate_files(const string& path) {
  return enumerate_files(path, "*");
}

directory::file_iterator directory::enumerate_files(const string& path, const string& search_pattern) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw_helper::throws(exception_case::io);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  
  return file_iterator {path, search_pattern};
}

directory::file_system_entry_iterator directory::enumerate_file_system_entries(const string& path) {
  return enumerate_file_system_entries(path, "*");
}

directory::file_system_entry_iterator directory::enumerate_file_system_entries(const string& path, const string& search_pattern) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw_helper::throws(exception_case::io);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  
  return file_system_entry_iterator {path, search_pattern};
}

bool directory::exists(const string& path) {
  return native::directory::exists(path);
}

date_time directory::get_creation_time(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw_helper::throws(exception_case::io);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  
  [[maybe_unused]] auto [creation_time, last_access_time, last_write_time] = get_file_times(path);
  return date_time::from_time_t(creation_time, date_time_kind::local);
}

string directory::get_current_directory() {
  auto path = io::path::get_full_path(native::directory::get_current_directory());
  if (path.empty()) throw_helper::throws(exception_case::not_supported);
  return path;
}

xtd::array<string> directory::get_directories(const string& path) {
  return get_directories(path, "*");
}

xtd::array<string> directory::get_directories(const string& path, const string& search_pattern) {
  return {std::begin(enumerate_directories(path, search_pattern)), std::end(enumerate_directories(path, search_pattern))};
}

string directory::get_directory_root(const string& path) {
  return path::get_path_root(path);
}

xtd::array<string> directory::get_files(const string& path) {
  return get_files(path, "*");
}

xtd::array<string> directory::get_files(const string& path, const string& search_pattern) {
  return {std::begin(enumerate_files(path, search_pattern)), std::end(enumerate_files(path, search_pattern))};
}

xtd::array<string> directory::get_file_system_entries(const string& path) {
  return get_file_system_entries(path, "*");
}

xtd::array<string> directory::get_file_system_entries(const string& path, const string& search_pattern) {
  return {std::begin(enumerate_file_system_entries(path, search_pattern)), std::end(enumerate_file_system_entries(path, search_pattern))};
}

date_time directory::get_last_access_time(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw_helper::throws(exception_case::io);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  
  [[maybe_unused]] auto [creation_time, last_access_time, last_write_time] = get_file_times(path);
  return date_time::from_time_t(last_access_time, date_time_kind::local);
}

date_time directory::get_last_write_time(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw_helper::throws(exception_case::io);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  
  [[maybe_unused]] auto [creation_time, last_access_time, last_write_time] = get_file_times(path);
  return date_time::from_time_t(last_write_time, date_time_kind::local);
}

xtd::array<string> directory::get_logical_drives() {
  auto logical_drives = std::vector<string> {};
  auto drives = drive_info::get_drives();
  std::for_each(drives.begin(), drives.end(), [&](auto drive) {logical_drives.emplace_back(drive.name());});
  return logical_drives;
}

directory_info directory::get_parent(const string& path) {
  return directory_info(path).parent();
}

xtd::io::file_permissions directory::get_permissions(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw_helper::throws(exception_case::io);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  
  auto permissions = 0;
  if (native::file_system::get_permissions(path, permissions) != 0) throw_helper::throws(exception_case::io);
  return static_cast<xtd::io::file_permissions>(permissions);
}

void directory::move(const string& src, const string& dst) {
  if (src.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (src.empty() || src.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(src)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(src)) throw_helper::throws(exception_case::directory_not_found);
  
  if ((file::get_attributes(src) & file_attributes::directory) == file_attributes::directory) directory_info(src).move_to(dst);
  else file::move(src, dst);
}

void directory::remove(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  
  directory_info(path).remove();
}

void directory::remove(const string& path, bool recursive) {
  directory_info(path).remove(recursive);
}

void directory::set_creation_time(const xtd::string& path, const xtd::date_time& creation_time) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  if (native::file_system::set_creation_time(path, creation_time.to_time_t()) != 0) throw_helper::throws(exception_case::io);
}

void directory::set_current_directory(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw_helper::throws(exception_case::io);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  if (native::directory::set_current_directory(path) != 0) throw_helper::throws(exception_case::io);
}

void directory::set_last_access_time(const xtd::string& path, const xtd::date_time& last_access_time) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  if (native::file_system::set_last_access_time(path, last_access_time.to_time_t()) != 0) throw_helper::throws(exception_case::io);
}

void directory::set_last_write_time(const xtd::string& path, const xtd::date_time& last_write_time) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  if (native::file_system::set_last_write_time(path, last_write_time.to_time_t()) != 0) throw_helper::throws(exception_case::io);
}

void directory::set_permissions(const xtd::string& path, xtd::io::file_permissions permissions) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::directory_not_found);
  if (native::file_system::set_permissions(path, static_cast<int32>(permissions)) != 0) throw_helper::throws(exception_case::io);
}

std::tuple<time_t, time_t, time_t> directory::get_file_times(const string& path) {
  auto creation_time = time_t {}, last_access_time = time_t {}, last_write_time = time_t {};
  if (native::file_system::get_file_times(path, creation_time, last_access_time, last_write_time) != 0) throw_helper::throws(exception_case::io);
  return std::make_tuple(creation_time, last_access_time, last_write_time);
}
