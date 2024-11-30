#define UNICODE
#define _CRT_SECURE_NO_WARNINGS
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory>
#include <xtd/native/file_system>
#include "../../../../include/xtd/native/win32/strings.hpp"
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
  HANDLE handle_ = INVALID_HANDLE_VALUE;
  mutable string current_;
};

directory::directory_iterator::directory_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
  auto item = WIN32_FIND_DATA {};
  auto search_pattern = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + data_->pattern_;
  data_->handle_ = FindFirstFile(win32::strings::to_wstring(search_pattern).c_str(), &item);
  auto result = data_->handle_ != INVALID_HANDLE_VALUE;
  while (result == true && ((item.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY || wstring(item.cFileName) == L"." || wstring(item.cFileName) == L".."))
    result = FindNextFile(data_->handle_, &item) != FALSE;
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + win32::strings::to_string(item.cFileName);
  else data_->current_ = "";
}

directory::directory_iterator::directory_iterator() {
  data_ = make_shared<data>();
}

directory::directory_iterator::~directory_iterator() {
  if (data_.use_count() == 1 && data_->handle_ != INVALID_HANDLE_VALUE) {
    FindClose(data_->handle_);
    data_->handle_ = nullptr;
  }
}

directory::directory_iterator& directory::directory_iterator::operator++() {
  auto item = WIN32_FIND_DATA {};
  auto result = FindNextFile(data_->handle_, &item) != FALSE;
  while (result == true && ((item.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY || wstring(item.cFileName) == L"." || wstring(item.cFileName) == L".."))
    result = FindNextFile(data_->handle_, &item) != FALSE;
    
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + win32::strings::to_string(item.cFileName);
  else data_->current_ = "";
  return *this;
}

directory::directory_iterator directory::directory_iterator::operator++(int) {
  auto result = *this;
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

directory::directory_iterator directory::directory_iterator::begin() const {
  return directory::directory_iterator(data_->path_, data_->pattern_);
}

directory::directory_iterator directory::directory_iterator::end() const {
  return directory::directory_iterator();
}

const std::string& directory::directory_iterator::path() const {
  return data_->path_;
}

const std::string& directory::directory_iterator::pattern() const {
  return data_->pattern_;
}

struct directory::file_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : path_(path), pattern_(pattern) {}
  std::string path_;
  std::string pattern_;
  HANDLE handle_ = INVALID_HANDLE_VALUE;
  mutable string current_;
};

directory::file_iterator::file_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
  auto item = WIN32_FIND_DATA {};
  auto search_pattern = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + data_->pattern_;
  data_->handle_ = FindFirstFile(win32::strings::to_wstring(search_pattern).c_str(), &item);
  auto result = data_->handle_ != INVALID_HANDLE_VALUE;
  while (result == true && ((item.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY || wstring(item.cFileName) == L"." || wstring(item.cFileName) == L".."))
    result = FindNextFile(data_->handle_, &item) != FALSE;
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + win32::strings::to_string(item.cFileName);
  else data_->current_ = "";
}

directory::file_iterator::file_iterator() {
  data_ = make_shared<data>();
}

directory::file_iterator::~file_iterator() {
  if (data_.use_count() == 1 && data_->handle_ != INVALID_HANDLE_VALUE) {
    FindClose(data_->handle_);
    data_->handle_ = nullptr;
  }
}

directory::file_iterator& directory::file_iterator::operator++() {
  auto item = WIN32_FIND_DATA {};
  auto result = FindNextFile(data_->handle_, &item) != FALSE;
  while (result == true && ((item.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY || wstring(item.cFileName) == L"." || wstring(item.cFileName) == L".."))
    result = FindNextFile(data_->handle_, &item) != FALSE;
    
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + win32::strings::to_string(item.cFileName);
  else data_->current_ = "";
  return *this;
}

directory::file_iterator directory::file_iterator::operator++(int) {
  auto result = *this;
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

directory::file_iterator directory::file_iterator::begin() const {
  return directory::file_iterator(data_->path_, data_->pattern_);
}

directory::file_iterator directory::file_iterator::end() const {
  return directory::file_iterator();
}

const std::string& directory::file_iterator::path() const {
  return data_->path_;
}

const std::string& directory::file_iterator::pattern() const {
  return data_->pattern_;
}

struct directory::file_and_directory_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : path_(path), pattern_(pattern) {}
  std::string path_;
  std::string pattern_;
  HANDLE handle_ = INVALID_HANDLE_VALUE;
  mutable string current_;
};

directory::file_and_directory_iterator::file_and_directory_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
  auto item = WIN32_FIND_DATA {};
  auto search_pattern = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + data_->pattern_;
  data_->handle_ = FindFirstFile(win32::strings::to_wstring(search_pattern).c_str(), &item);
  auto result = data_->handle_ != INVALID_HANDLE_VALUE;
  while (result == true && (wstring(item.cFileName) == L"." || wstring(item.cFileName) == L".."))
    result = FindNextFile(data_->handle_, &item) != FALSE;
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + win32::strings::to_string(item.cFileName);
  else data_->current_ = "";
}

directory::file_and_directory_iterator::file_and_directory_iterator() {
  data_ = make_shared<data>();
}

directory::file_and_directory_iterator::~file_and_directory_iterator() {
  if (data_.use_count() == 1 && data_->handle_ != INVALID_HANDLE_VALUE) {
    FindClose(data_->handle_);
    data_->handle_ = nullptr;
  }
}

directory::file_and_directory_iterator& directory::file_and_directory_iterator::operator++() {
  auto item = WIN32_FIND_DATA {};
  auto result = FindNextFile(data_->handle_, &item) != FALSE;
  while (result == true && (wstring(item.cFileName) == L"." || wstring(item.cFileName) == L".."))
    result = FindNextFile(data_->handle_, &item) != FALSE;
    
  if (result) data_->current_ = data_->path_ + (data_->path_.rfind('\\') == data_->path_.size() - 1 ? "" : "\\") + win32::strings::to_string(item.cFileName);
  else data_->current_ = "";
  return *this;
}

directory::file_and_directory_iterator directory::file_and_directory_iterator::operator++(int) {
  auto result = *this;
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

directory::file_and_directory_iterator directory::file_and_directory_iterator::begin() const {
  return directory::file_and_directory_iterator(data_->path_, data_->pattern_);
}

directory::file_and_directory_iterator directory::file_and_directory_iterator::end() const {
  return directory::file_and_directory_iterator();
}

const std::string& directory::file_and_directory_iterator::path() const {
  return data_->path_;
}

const std::string& directory::file_and_directory_iterator::pattern() const {
  return data_->pattern_;
}

int32_t directory::create(const std::string& directory_name) {
  return CreateDirectory(win32::strings::to_wstring(directory_name).c_str(), nullptr) != FALSE ? 0 : -1;
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

bool directory::exists(const std::string& path) {
  auto attributes = 0;
  return file_system::get_attributes(path, attributes) == 0 && (attributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY;
}

string directory::get_current_directory() {
  auto length = GetCurrentDirectory(0, nullptr);
  
  auto current_directory = wstring(static_cast<size_t>(length), '\0');
  GetCurrentDirectory(length, current_directory.data());
  return win32::strings::to_string(current_directory);
}

int32_t directory::remove(const std::string& directory_name) {
  return RemoveDirectory(win32::strings::to_wstring(directory_name).c_str()) != FALSE ? 0 : -1;
}

int32_t directory::set_current_directory(const std::string& directory_name) {
  return SetCurrentDirectory(win32::strings::to_wstring(directory_name).c_str()) != FALSE ? 0 : -1;
}
