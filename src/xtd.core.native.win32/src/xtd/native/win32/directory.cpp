#define _CRT_SECURE_NO_WARNINGS

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <chrono>
#include <string>
#include <direct.h>
#include <Windows.h>

#undef max
#undef min

using namespace std;
using namespace xtd::native;

struct directory::directory_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : path_(path), pattern_(pattern) {}
  std::string path_;
  std::string pattern_;
  HANDLE handle_ = nullptr;
  mutable string current_;
};

directory::directory_iterator::directory_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
  WIN32_FIND_DATA item;
  string search_pattern = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + data_->pattern_;
  data_->handle_ = FindFirstFile(search_pattern.c_str(), &item);
  bool result = data_->handle_;
  while (result == true && ((item.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY) || string(item.cFileName) == "." || string(item.cFileName) == "..")
    result = FindNextFile(data_->handle_, &item) != FALSE;
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + item.cFileName;
  else  data_->current_ = "";
}

directory::directory_iterator::directory_iterator() {
  data_ = make_shared<data>();
}

directory::directory_iterator::~directory_iterator() {
  if (data_.use_count() == 1) {
    FindClose(data_->handle_);
    data_->handle_ = nullptr;
  }
}

directory::directory_iterator& directory::directory_iterator::operator++() {
  WIN32_FIND_DATA item;
  bool result = FindNextFile(data_->handle_, &item) != FALSE;
  while (result == true && ((item.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY) || string(item.cFileName) == "." || string(item.cFileName) == "..")
    result = FindNextFile(data_->handle_, &item) != FALSE;

  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + item.cFileName;
  else  data_->current_ = "";
  return *this;
}

directory::directory_iterator directory::directory_iterator::operator++(int) {
  directory_iterator result = *this;
  ++(*this);
  return result;
}

bool directory::directory_iterator::operator==(directory::directory_iterator other) const {
  return data_->current_ == other.data_->current_;
}

directory::directory_iterator::value_type directory::directory_iterator::operator*() const {
  if (data_ == nullptr) return "";
  return data_->current_;
}

struct directory::file_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : path_(path), pattern_(pattern) {}
  std::string path_;
  std::string pattern_;
  HANDLE handle_ = nullptr;
  mutable string current_;
};

directory::file_iterator::file_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
  WIN32_FIND_DATA item;
  string search_pattern = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + data_->pattern_;
  data_->handle_ = FindFirstFile(search_pattern.c_str(), &item);
  bool result = data_->handle_;
  while (result == true && ((item.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) || string(item.cFileName) == "." || string(item.cFileName) == "..")
    result = FindNextFile(data_->handle_, &item) != FALSE;
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + item.cFileName;
  else  data_->current_ = "";
}

directory::file_iterator::file_iterator() {
  data_ = make_shared<data>();
}

directory::file_iterator::~file_iterator() {
  if (data_.use_count() == 1) {
    FindClose(data_->handle_);
    data_->handle_ = nullptr;
  }
}

directory::file_iterator& directory::file_iterator::operator++() {
  WIN32_FIND_DATA item;
  bool result = FindNextFile(data_->handle_, &item) != FALSE;
  while (result == true && ((item.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) || string(item.cFileName) == "." || string(item.cFileName) == "..")
    result = FindNextFile(data_->handle_, &item) != FALSE;

  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + item.cFileName;
  else  data_->current_ = "";
  return *this;
}

directory::file_iterator directory::file_iterator::operator++(int) {
  file_iterator result = *this;
  ++(*this);
  return result;
}

bool directory::file_iterator::operator==(directory::file_iterator other) const {
  return data_->current_ == other.data_->current_;
}

directory::file_iterator::value_type directory::file_iterator::operator*() const {
  if (data_ == nullptr) return "";
  return data_->current_;
}

struct directory::file_system_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : path_(path), pattern_(pattern) {}
  std::string path_;
  std::string pattern_;
  HANDLE handle_ = nullptr;
  mutable string current_;
};

directory::file_system_iterator::file_system_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
  WIN32_FIND_DATA item;
  string search_pattern = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + data_->pattern_;
  data_->handle_ = FindFirstFile(search_pattern.c_str(), &item);
  bool result = data_->handle_;
  while (result == true && ((item.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) || string(item.cFileName) == "." || string(item.cFileName) == "..")
    result = FindNextFile(data_->handle_, &item) != FALSE;
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + item.cFileName;
  else  data_->current_ = "";
}

directory::file_system_iterator::file_system_iterator() {
  data_ = make_shared<data>();
}

directory::file_system_iterator::~file_system_iterator() {
  if (data_.use_count() == 1) {
    FindClose(data_->handle_);
    data_->handle_ = nullptr;
  }
}

directory::file_system_iterator& directory::file_system_iterator::operator++() {
  WIN32_FIND_DATA item;
  bool result = FindNextFile(data_->handle_, &item) != FALSE;
  while (result == true && ((item.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM) != FILE_ATTRIBUTE_SYSTEM) || string(item.cFileName) == "." || string(item.cFileName) == "..")
    result = FindNextFile(data_->handle_, &item) != FALSE;
  
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + item.cFileName;
  else  data_->current_ = "";
  return *this;
}

directory::file_system_iterator directory::file_system_iterator::operator++(int) {
  file_system_iterator result = *this;
  ++(*this);
  return result;
}

bool directory::file_system_iterator::operator==(directory::file_system_iterator other) const {
  return data_->current_ == other.data_->current_;
}

directory::file_system_iterator::value_type directory::file_system_iterator::operator*() const {
  if (data_ == nullptr) return "";
  return data_->current_;
}

int32_t directory::create_directory(const std::string& directory_name) {
  return CreateDirectoryA(directory_name.c_str(), nullptr) != FALSE ? 0 : -1;
}

directory::directory_iterator directory::enumerate_directories(const std::string& path, const std::string& pattern) {
  return directory_iterator(path, pattern);
}

directory::file_iterator directory::enumerate_files(const std::string& path, const std::string& pattern) {
  return file_iterator(path, pattern);
}

string directory::get_current_directory() {
  char path[MAX_PATH + 1];
  return _getcwd(path, MAX_PATH) ? path : "";
}

int32_t directory::get_file_attributes(const std::string& path, int32_t& attributes) {
  attributes = GetFileAttributesA(path.c_str());
  if (attributes == INVALID_FILE_ATTRIBUTES)
    return -1;
  return 0;
}

int32_t directory::get_file_times(const std::string& path, std::chrono::system_clock::time_point& creation_time, std::chrono::system_clock::time_point& last_access_time, std::chrono::system_clock::time_point& last_write_time) {
  struct stat file_stat;
  if (stat(path.c_str(), &file_stat) != 0)
    return -1;
  creation_time = std::chrono::system_clock::from_time_t(static_cast<time_t>(file_stat.st_ctime));
  last_access_time = std::chrono::system_clock::from_time_t(static_cast<time_t>(file_stat.st_atime));
  last_write_time = std::chrono::system_clock::from_time_t(static_cast<time_t>(file_stat.st_mtime));
  return 0;
}

string directory::get_full_path(const std::string& relative_path) {
  char full_path[MAX_PATH + 1];
  return _fullpath(full_path, relative_path.c_str(), MAX_PATH) ? full_path : "";
}

int64_t directory::get_file_size(const std::string& path) {
  WIN32_FIND_DATA file;
  void* handle = FindFirstFileA(path.c_str(), &file);
  if (handle == INVALID_HANDLE_VALUE)
    return 0;
  
  ULARGE_INTEGER size;
  size.HighPart = file.nFileSizeHigh;
  size.LowPart = file.nFileSizeLow;
  FindClose(handle);
  return size.QuadPart;
}

int32_t directory::move_file(const std::string& old_path, const std::string& new_path) {
  int32_t file_attributes = 0;
  if (get_file_attributes(new_path, file_attributes) == 0)
    return -1;
  return ::rename(old_path.c_str(), new_path.c_str());
}

int32_t directory::remove_directory(const std::string& directory_name) {
  return RemoveDirectoryA(directory_name.c_str()) != FALSE ? 0 : -1;
}

int32_t directory::remove_file(const std::string& file) {
  return ::remove(file.c_str());
}

int32_t directory::set_current_directory(const std::string& directory_name) {
  return _chdir(directory_name.c_str());
}

int32_t directory::set_file_attributes(const std::string& path, int32_t attributes) {
  return -1;
}
