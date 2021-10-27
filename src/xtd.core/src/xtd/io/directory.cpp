#include "../../../include/xtd/io/directory.h"
#include "../../../include/xtd/io/file_info.h"
#include "../../../include/xtd/io/directory_info.h"
#include "../../../include/xtd/io/drive_info.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/path_too_long_exception.h"
#include "../../../include/xtd/argument_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
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
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  
  directory_info dir_info(path);
  if (!dir_info.exists()) {
    if (!ustring::is_empty(dir_info.parent().full_name()))
      create_directory(dir_info.parent().full_name());
    dir_info.create();
  }
  return dir_info;
}

directory::directory_iterator directory::enumerate_directories(const ustring& path) {
  return enumerate_directories(path, "*");
}

directory::directory_iterator directory::enumerate_directories(const ustring& path, const ustring& search_pattern) {
  return directory_iterator(path, search_pattern);
}

directory::file_iterator directory::enumerate_files(const ustring& path) {
  return enumerate_files(path, "*");
}

directory::file_iterator directory::enumerate_files(const ustring& path, const ustring& search_pattern) {
  return file_iterator(path, search_pattern);
}

directory::file_system_entry_iterator directory::enumerate_file_system_entries(const ustring& path) {
  return enumerate_file_system_entries(path, "*");
}

directory::file_system_entry_iterator directory::enumerate_file_system_entries(const ustring& path, const ustring& search_pattern) {
  return file_system_entry_iterator(path, search_pattern);
}


bool directory::exists(const ustring& path) {
  try {
    return directory_info(path).exists();
  } catch (const system_exception&) {
    return false;
  }
}

system_clock::time_point directory::get_creation_time(const ustring& path) {
  return directory_info(path).creation_time();
}

ustring directory::get_current_directory() {
  return native::directory::get_current_directory();
}

vector<ustring> directory::get_directories(const ustring& path) {
  return get_directories(path, "*");
}

vector<ustring> directory::get_directories(const ustring& path, const ustring& search_pattern) {
  vector<ustring> directories;
  for (auto directory : enumerate_directories(path, search_pattern))
    directories.emplace_back(directory);
  return directories;
}

ustring directory::get_directory_root(const ustring& path) {
  return path::get_path_root(path);
}

vector<ustring> directory::get_files(const ustring& path) {
  return get_files(path, "*");
}

vector<ustring> directory::get_files(const ustring& path, const ustring& search_pattern) {
  vector<ustring> files;
  for (auto file : enumerate_files(path, search_pattern))
    files.emplace_back(file);
  return files;
}

vector<ustring> directory::get_file_system_entries(const ustring& path) {
  return get_file_system_entries(path, "*");
}

vector<ustring> directory::get_file_system_entries(const ustring& path, const ustring& search_pattern) {
  vector<ustring> file_system_entries;
  for (auto file_system_entry : enumerate_file_system_entries(path, search_pattern))
    file_system_entries.emplace_back(file_system_entry);
  return file_system_entries;
}

system_clock::time_point directory::get_last_access_time(const ustring& path) {
  return directory_info(path).last_access_time();
}

system_clock::time_point directory::get_last_write_time(const ustring& path) {
  return directory_info(path).last_write_time();
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
  if (path::has_extension(src))
    file::move(src, dst);
  else
    directory_info(src).move_to(dst);
}

void directory::remove(const ustring& path) {
  directory_info(path).remove();
}

void directory::remove(const ustring& path, bool recursive) {
  directory_info(path).remove(recursive);
}
