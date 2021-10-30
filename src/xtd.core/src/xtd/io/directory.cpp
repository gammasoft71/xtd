#include "../../../include/xtd/io/directory.h"
#include "../../../include/xtd/io/file_info.h"
#include "../../../include/xtd/io/directory_info.h"
#include "../../../include/xtd/io/directory_not_found_exception.h"
#include "../../../include/xtd/io/drive_info.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/path_too_long_exception.h"
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/not_supported_exception.h"
#include "../../../include/xtd/unauthorized_access_exception.h"
#include "../../../include/xtd/diagnostics/debug.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#include <xtd/native/file.h>
#include <xtd/native/file_system.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace io;

struct directory::directory_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  directory_info::directory_iterator iterator_;
};

directory::directory_iterator::directory_iterator(const ustring& path, const ustring& pattern) {
  data_ = make_shared<data>(path, pattern);
}

directory::directory_iterator::directory_iterator() {
  data_ = make_shared<data>();
}

directory::directory_iterator& directory::directory_iterator::operator++() {
  data_->iterator_++;
  return *this;
}

directory::directory_iterator directory::directory_iterator::operator++(int) {
  directory_iterator result = *this;
  ++(*this);
  return result;
}

bool directory::directory_iterator::operator==(directory::directory_iterator other) const {
  return data_->iterator_ == other.data_->iterator_;
}

directory::directory_iterator::value_type directory::directory_iterator::operator*() const {
  if (data_ == nullptr) return "";
  return (*data_->iterator_).full_name();
}

struct directory::file_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  directory_info::file_iterator iterator_;
};

directory::file_iterator::file_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
}

directory::file_iterator::file_iterator() {
  data_ = make_shared<data>();
}

directory::file_iterator& directory::file_iterator::operator++() {
  data_->iterator_++;
  return *this;
}

directory::file_iterator directory::file_iterator::operator++(int) {
  file_iterator result = *this;
  ++(*this);
  return result;
}

bool directory::file_iterator::operator==(directory::file_iterator other) const {
  return data_->iterator_ == other.data_->iterator_;
}

directory::file_iterator::value_type directory::file_iterator::operator*() const {
  if (data_ == nullptr) return "";
  return (*data_->iterator_).full_name();
}

struct directory::file_system_entry_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  directory_info::file_system_info_iterator iterator_;
};

directory::file_system_entry_iterator::file_system_entry_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
}

directory::file_system_entry_iterator::file_system_entry_iterator() {
  data_ = make_shared<data>();
}

directory::file_system_entry_iterator& directory::file_system_entry_iterator::operator++() {
  data_->iterator_++;
  return *this;
}

directory::file_system_entry_iterator directory::file_system_entry_iterator::operator++(int) {
  file_system_entry_iterator result = *this;
  ++(*this);
  return result;
}

bool directory::file_system_entry_iterator::operator==(directory::file_system_entry_iterator other) const {
  return data_->iterator_ == other.data_->iterator_;
}

directory::file_system_entry_iterator::value_type directory::file_system_entry_iterator::operator*() const {
  if (data_ == nullptr) return "";
  return (*data_->iterator_)->full_name();
}

directory_info directory::create_directory(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path)) throw path_too_long_exception(csf_);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw io_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);

  directory_info dir_info(path);
  if (dir_info.exists()) return dir_info;

  if (!ustring::is_empty(dir_info.parent().full_name()))
    create_directory(dir_info.parent().full_name());
  dir_info.create();
  return dir_info;
}

directory::directory_iterator directory::enumerate_directories(const ustring& path) {
  return enumerate_directories(path, "*");
}

directory::directory_iterator directory::enumerate_directories(const ustring& path, const ustring& search_pattern) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path)) throw path_too_long_exception(csf_);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw io_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);
  
  return directory_iterator(path, search_pattern);
}

directory::file_iterator directory::enumerate_files(const ustring& path) {
  return enumerate_files(path, "*");
}

directory::file_iterator directory::enumerate_files(const ustring& path, const ustring& search_pattern) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path)) throw path_too_long_exception(csf_);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw io_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);

  return file_iterator(path, search_pattern);
}

directory::file_system_entry_iterator directory::enumerate_file_system_entries(const ustring& path) {
  return enumerate_file_system_entries(path, "*");
}

directory::file_system_entry_iterator directory::enumerate_file_system_entries(const ustring& path, const ustring& search_pattern) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path)) throw path_too_long_exception(csf_);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw io_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);

  return file_system_entry_iterator(path, search_pattern);
}

bool directory::exists(const ustring& path) {
  return native::directory::exists(path);
}

system_clock::time_point directory::get_creation_time(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path)) throw path_too_long_exception(csf_);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw io_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);

  std::chrono::system_clock::time_point creation_time, last_access_time, last_write_time;
  native::file_system::get_file_times(path, creation_time, last_access_time, last_write_time);
  return creation_time;
}

ustring directory::get_current_directory() {
  auto path = native::directory::get_current_directory();
  if (path.empty()) throw not_supported_exception(csf_);
  return path;
}

vector<ustring> directory::get_directories(const ustring& path) {
  return get_directories(path, "*");
}

vector<ustring> directory::get_directories(const ustring& path, const ustring& search_pattern) {
  return {begin(enumerate_directories(path, search_pattern)), end(enumerate_directories(path, search_pattern))};
}

ustring directory::get_directory_root(const ustring& path) {
  return path::get_path_root(path);
}

vector<ustring> directory::get_files(const ustring& path) {
  return get_files(path, "*");
}

vector<ustring> directory::get_files(const ustring& path, const ustring& search_pattern) {
  return {begin(enumerate_files(path, search_pattern)), end(enumerate_files(path, search_pattern))};
}

vector<ustring> directory::get_file_system_entries(const ustring& path) {
  return get_file_system_entries(path, "*");
}

vector<ustring> directory::get_file_system_entries(const ustring& path, const ustring& search_pattern) {
  return {begin(enumerate_file_system_entries(path, search_pattern)), end(enumerate_file_system_entries(path, search_pattern))};
}

system_clock::time_point directory::get_last_access_time(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path)) throw path_too_long_exception(csf_);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw io_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);

  std::chrono::system_clock::time_point creation_time, last_access_time, last_write_time;
  native::file_system::get_file_times(path, creation_time, last_access_time, last_write_time);
  return last_access_time;
}

system_clock::time_point directory::get_last_write_time(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path)) throw path_too_long_exception(csf_);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw io_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);

  std::chrono::system_clock::time_point creation_time, last_access_time, last_write_time;
  native::file_system::get_file_times(path, creation_time, last_access_time, last_write_time);
  return last_write_time;
}

vector<ustring> directory::get_logical_drives() {
  vector<ustring> drives;
  for (auto drive : drive_info::get_drives())
    drives.emplace_back(drive.name());
  return drives;
}

directory_info directory::get_parent(const ustring& path) {
  return directory_info(path).parent();
}

void directory::move(const ustring& src, const ustring& dst) {
  if (src.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (src.empty() || src.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(src)) throw path_too_long_exception(csf_);
  if (!exists(src)) throw directory_not_found_exception(csf_);

  if ((file::get_attributes(src) & file_attributes::directory) == file_attributes::directory)
    directory_info(src).move_to(dst);
  else
    file::move(src, dst);
}

void directory::remove(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path)) throw path_too_long_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);

  directory_info(path).remove();
}

void directory::remove(const ustring& path, bool recursive) {
  directory_info(path).remove(recursive);
}

void directory::set_creation_time(const xtd::ustring& path, system_clock::time_point creation_time) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path)) throw path_too_long_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);
  
  native::file_system::set_creation_time(path, creation_time);
}

void directory::set_creation_time(const xtd::ustring& path, time_t creation_time) {
  set_creation_time(path, system_clock::from_time_t(creation_time));
}

void directory::set_creation_time(const xtd::ustring& path, const std::tm& creation_time) {
  std::tm value = creation_time;
  set_creation_time(path, mktime(&value));
}

void directory::set_creation_time(const xtd::ustring& path, int32_t year, int32_t month, int32_t day) {
  set_creation_time(path, year, month, day, 0, 0, 0);
}

void directory::set_creation_time(const xtd::ustring& path, int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
  std::tm value = {};
  value.tm_year = year - 1900;
  value.tm_mon = month - 1;
  value.tm_mday = day;
  value.tm_hour = hour;
  value.tm_min = minute;
  value.tm_sec = second;
  set_creation_time(path, mktime(&value));
}

void directory::set_current_directory(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (exists(path) && (file::get_attributes(path) & file_attributes::directory) != file_attributes::directory) throw io_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);
  if (native::directory::set_current_directory(path) != 0) throw io_exception(csf_);
}

void directory::set_last_access_time(const xtd::ustring& path, system_clock::time_point last_access_time) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path)) throw path_too_long_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);
  
  native::file_system::set_last_access_time(path, last_access_time);
}

void directory::set_last_access_time(const xtd::ustring& path, time_t last_access_time) {
  set_last_access_time(path, system_clock::from_time_t(last_access_time));
}

void directory::set_last_access_time(const xtd::ustring& path, const std::tm& last_access_time) {
  std::tm value = last_access_time;
  set_last_access_time(path, mktime(&value));
}

void directory::set_last_access_time(const xtd::ustring& path, int32_t year, int32_t month, int32_t day) {
  set_last_access_time(path, year, month, day, 0, 0, 0);
}

void directory::set_last_access_time(const xtd::ustring& path, int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
  std::tm value = {};
  value.tm_year = year - 1900;
  value.tm_mon = month - 1;
  value.tm_mday = day;
  value.tm_hour = hour;
  value.tm_min = minute;
  value.tm_sec = second;
  set_last_access_time(path, mktime(&value));
}

void directory::set_last_write_time(const xtd::ustring& path, system_clock::time_point last_write_time) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path)) throw path_too_long_exception(csf_);
  if (!exists(path)) throw directory_not_found_exception(csf_);
  
  native::file_system::set_last_write_time(path, last_write_time);
}

void directory::set_last_write_time(const xtd::ustring& path, time_t last_write_time) {
  set_last_write_time(path, system_clock::from_time_t(last_write_time));
}

void directory::set_last_write_time(const xtd::ustring& path, const std::tm& last_write_time) {
  std::tm value = last_write_time;
  set_last_write_time(path, mktime(&value));
}

void directory::set_last_write_time(const xtd::ustring& path, int32_t year, int32_t month, int32_t day) {
  set_last_write_time(path, year, month, day, 0, 0, 0);
}

void directory::set_last_write_time(const xtd::ustring& path, int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
  std::tm value = {};
  value.tm_year = year - 1900;
  value.tm_mon = month - 1;
  value.tm_mday = day;
  value.tm_hour = hour;
  value.tm_min = minute;
  value.tm_sec = second;
  set_last_write_time(path, mktime(&value));
}
