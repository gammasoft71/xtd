#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#include <xtd/native/file_system.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <dirent.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/stat.h>

using namespace std;
using namespace xtd::native;

namespace {
  bool pattern_compare(const string& file_name, const string& pattern) {
    if (pattern.empty()) return file_name.empty();
    if (file_name.empty()) return false;
    if (pattern == "*" || pattern == "*.*") return true;
    if (pattern[0] == '*') return pattern_compare(file_name, pattern.substr(1)) || pattern_compare(file_name.substr(1), pattern);
    return ((pattern[0] == '?') || (file_name[0] == pattern[0])) && pattern_compare(file_name.substr(1), pattern.substr(1));
  }
}

struct directory::directory_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : path_(path), pattern_(pattern) {}
  std::string path_;
  std::string pattern_;
  DIR* handle_ = nullptr;
  mutable string current_;
};

directory::directory_iterator::directory_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
  data_->handle_ = opendir(data_->path_.c_str());
  ++(*this);
}

directory::directory_iterator::directory_iterator() {
  data_ = make_shared<data>();
}

directory::directory_iterator::~directory_iterator() {
  if (data_.use_count() == 1 && data_->handle_) {
    closedir(data_->handle_);
    data_->handle_ = nullptr;
  }
}

directory::directory_iterator& directory::directory_iterator::operator++() {
  dirent* item;
  int32_t attributes;
  do {
    if ((item = readdir(data_->handle_)) != nullptr)
      native::file_system::get_attributes(data_->path_+ '/' + item->d_name, attributes);
  } while (item != nullptr && ((attributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY || string(item->d_name) == "." ||  string(item->d_name) == ".."  || !pattern_compare(item->d_name, data_->pattern_)));
  
  if (item == nullptr) data_->current_ = "";
  else data_->current_ = data_->path_ + (data_->path_.rfind('/') == data_->path_.size() - 1 ? "" : "/") + item->d_name;
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
  DIR* handle_ = nullptr;
  mutable string current_;
};

directory::file_iterator::file_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
  data_->handle_ = opendir(data_->path_.c_str());
  ++(*this);
}

directory::file_iterator::file_iterator() {
  data_ = make_shared<data>();
}

directory::file_iterator::~file_iterator() {
  if (data_.use_count() == 1 && data_->handle_) {
    closedir(data_->handle_);
    data_->handle_ = nullptr;
  }
}

directory::file_iterator& directory::file_iterator::operator++() {
  dirent* item;
  int32_t attributes;
  do {
    if ((item = readdir(data_->handle_)) != nullptr)
      native::file_system::get_attributes(data_->path_+ '/' + item->d_name, attributes);
  } while (item != nullptr && ((attributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY || string(item->d_name) == "." ||  string(item->d_name) == ".."  || !pattern_compare(item->d_name, data_->pattern_)));
  
  if (item == nullptr) data_->current_ = "";
  else data_->current_ = data_->path_ + (data_->path_.rfind('/') == data_->path_.size() - 1 ? "" : "/") + item->d_name;
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
  DIR* handle_ = nullptr;
  mutable string current_;
};

directory::file_and_directory_iterator::file_and_directory_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
  data_->handle_ = opendir(data_->path_.c_str());
  ++(*this);
}

directory::file_and_directory_iterator::file_and_directory_iterator() {
  data_ = make_shared<data>();
}

directory::file_and_directory_iterator::~file_and_directory_iterator() {
  if (data_.use_count() == 1 && data_->handle_) {
    closedir(data_->handle_);
    data_->handle_ = nullptr;
  }
}

directory::file_and_directory_iterator& directory::file_and_directory_iterator::operator++() {
  dirent* item;
  int32_t attributes;
  do {
    if ((item = readdir(data_->handle_)) != nullptr)
      native::file_system::get_attributes(data_->path_+ '/' + item->d_name, attributes);
  } while (item != nullptr && (string(item->d_name) == "." ||  string(item->d_name) == ".."  || !pattern_compare(item->d_name, data_->pattern_)));
  
  if (item == nullptr) data_->current_ = "";
  else data_->current_ = data_->path_ + (data_->path_.rfind('/') == data_->path_.size() - 1 ? "" : "/") + item->d_name;
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
  return mkdir(directory_name.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH);
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
  char path[MAXPATHLEN + 1];
  return getcwd(path, MAXPATHLEN) ? path : "";
}

int32_t directory::remove(const std::string& directory_name) {
  return rmdir(directory_name.c_str());
}

int32_t directory::set_current_directory(const std::string& directory_name) {
  return chdir(directory_name.c_str());
}
