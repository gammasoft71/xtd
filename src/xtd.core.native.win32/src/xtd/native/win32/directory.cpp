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
  if (data_.use_count() == 1 && data_->handle_) {
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
  if (data_.use_count() == 1 && data_->handle_) {
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

struct directory::file_and_directory_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : path_(path), pattern_(pattern) {}
  std::string path_;
  std::string pattern_;
  HANDLE handle_ = nullptr;
  mutable string current_;
};

directory::file_and_directory_iterator::file_and_directory_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
  WIN32_FIND_DATA item;
  string search_pattern = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + data_->pattern_;
  data_->handle_ = FindFirstFile(search_pattern.c_str(), &item);
  bool result = data_->handle_;
  while (result == true && (string(item.cFileName) == "." || string(item.cFileName) == ".."))
    result = FindNextFile(data_->handle_, &item) != FALSE;
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + item.cFileName;
  else  data_->current_ = "";
}

directory::file_and_directory_iterator::file_and_directory_iterator() {
  data_ = make_shared<data>();
}

directory::file_and_directory_iterator::~file_and_directory_iterator() {
  if (data_.use_count() == 1 && data_->handle_) {
    FindClose(data_->handle_);
    data_->handle_ = nullptr;
  }
}

directory::file_and_directory_iterator& directory::file_and_directory_iterator::operator++() {
  WIN32_FIND_DATA item;
  bool result = FindNextFile(data_->handle_, &item) != FALSE;
  while (result == true && (string(item.cFileName) == "." || string(item.cFileName) == ".."))
    result = FindNextFile(data_->handle_, &item) != FALSE;
  
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + item.cFileName;
  else  data_->current_ = "";
  return *this;
}

directory::file_and_directory_iterator directory::file_and_directory_iterator::operator++(int) {
  file_and_directory_iterator result = *this;
  ++(*this);
  return result;
}

bool directory::file_and_directory_iterator::operator==(directory::file_and_directory_iterator other) const {
  return data_->current_ == other.data_->current_;
}

directory::file_and_directory_iterator::value_type directory::file_and_directory_iterator::operator*() const {
  if (data_ == nullptr) return "";
  return data_->current_;
}

int32_t directory::create(const std::string& directory_name) {
  return CreateDirectoryA(directory_name.c_str(), nullptr) != FALSE ? 0 : -1;
}

directory::directory_iterator directory::enumerate_directories(const std::string& path, const std::string& pattern) {
  return directory_iterator(path, pattern);
}

directory::file_iterator directory::enumerate_files(const std::string& path, const std::string& pattern) {
  return file_iterator(path, pattern);
}

directory::file_and_directory_iterator directory::enumerate_files_and_directories(const std::string& path, const std::string& pattern) {
  return file_and_directory_iterator(path, pattern);
}

string directory::get_current_directory() {
  char path[MAX_PATH + 1];
  return _getcwd(path, MAX_PATH) ? path : "";
}

int32_t directory::remove(const std::string& directory_name) {
  return RemoveDirectoryA(directory_name.c_str()) != FALSE ? 0 : -1;
}

int32_t directory::set_current_directory(const std::string& directory_name) {
  return _chdir(directory_name.c_str());
}
