#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#include <xtd/native/path.h>
#include "../../../../include/xtd/native/unix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <dirent.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/stat.h>
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
      native::directory::get_file_attributes(data_->path_+ '/' + item->d_name, attributes);
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
      native::directory::get_file_attributes(data_->path_+ '/' + item->d_name, attributes);
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
      native::directory::get_file_attributes(data_->path_+ '/' + item->d_name, attributes);
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

int32_t directory::copy_file(const std::string& source_file, const std::string& target_file) {
  FILE* source = fopen(source_file.c_str(), "rb");
  if (source == nullptr) return -1;
  
  FILE* target = fopen(target_file.c_str(), "wb");
  if (target == nullptr) {
    fclose(source);
    return -1;
  }
  
  size_t count = 0;
  do {
    uint8_t buffer[1024];
    count = fread(buffer, 1, 1024, source);
    if (count > 0) fwrite(buffer, 1, count, target);
  } while (count == 1024);
  
  fclose(source);
  fclose(target);
  return 0;
}

int32_t directory::create_directory(const std::string& directory_name) {
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

int32_t directory::get_file_attributes(const std::string& path, int32_t& attributes) {
  struct system_attribute_to_file_attribute_converter {
    int32_t operator()(int32_t attribute) {
      int32_t file_attributes = 0;
      if ((attribute & S_IRUSR) == S_IRUSR && (attribute & S_IWUSR) == 0) file_attributes |= FILE_ATTRIBUTE_READONLY;
      if ((attribute & S_IFSOCK) == S_IFSOCK || (attribute & S_IFIFO) == S_IFIFO) file_attributes |= FILE_ATTRIBUTE_SYSTEM;
      if ((attribute & S_IFDIR) == S_IFDIR) file_attributes |= FILE_ATTRIBUTE_DIRECTORY;
      if ((attribute & S_IFREG) == S_IFREG) file_attributes |= FILE_ATTRIBUTE_ARCHIVE;
      if ((attribute & S_IFBLK) == S_IFBLK || (attribute & S_IFCHR) == S_IFCHR) file_attributes |= FILE_ATTRIBUTE_DEVICE;
      if ((attribute & S_IFREG) == S_IFREG) file_attributes |= FILE_ATTRIBUTE_NORMAL;
      return file_attributes;
    }
  };
  struct stat status;
  int32_t ret_value = stat(path.c_str(), &status);
  attributes = system_attribute_to_file_attribute_converter()(status.st_mode);
  return ret_value;
}

#if !__APPLE__
int32_t directory::get_file_times(const std::string& path, std::chrono::system_clock::time_point& creation_time, std::chrono::system_clock::time_point& last_access_time, std::chrono::system_clock::time_point& last_write_time) {
  struct stat status;
  if (stat(path.c_str(), &status) != 0) return -1;
  
  creation_time = std::chrono::system_clock::from_time_t(static_cast<time_t>(status.st_ctime));
  last_access_time = std::chrono::system_clock::from_time_t(static_cast<time_t>(status.st_atime));
  last_write_time = std::chrono::system_clock::from_time_t(static_cast<time_t>(status.st_mtime));
  return 0;
}
#endif

string directory::get_full_path(const string& relative_path) {
  vector<string> directories = native::unix::strings::split(relative_path, {path::directory_separator_char()}, std::numeric_limits<size_t>::max(), true);
  string full_path;
  
  if (relative_path[0] != path::directory_separator_char())
    full_path = get_current_directory();
  
  for (string& item : directories) {
    if (item == ".." && native::unix::strings::last_index_of(full_path, path::directory_separator_char()) != full_path.npos)
      full_path = native::unix::strings::remove(full_path, native::unix::strings::last_index_of(full_path, path::directory_separator_char()));
    else if (item != ".")
      full_path += path::directory_separator_char() + item;
  }
  
  if (relative_path[relative_path.size() - 1] == path::directory_separator_char())
    full_path += path::directory_separator_char();
  
  return full_path;
}

string directory::get_current_directory() {
  char path[MAXPATHLEN + 1];
  return getcwd(path, MAXPATHLEN) ? path : "";
}

size_t directory::get_file_size(const std::string& path) {
  struct stat status;
  if (stat(path.c_str(), &status) != 0) return 0;
  return static_cast<size_t>(status.st_size);
}

bool directory::is_path_too_long(const std::string& path) {
  return path.size() > PATH_MAX;
}

int32_t directory::move_file(const std::string& old_path, const std::string& new_path) {
  int32_t file_attributes = 0;
  if (get_file_attributes(new_path, file_attributes) == 0) return -1;
  return rename(old_path.c_str(), new_path.c_str());
}

int32_t directory::remove_directory(const std::string& directory_name) {
  return rmdir(directory_name.c_str());
}

int32_t directory::remove_file(const std::string& file) {
  return unlink(file.c_str());
}

int32_t directory::set_current_directory(const std::string& directory_name) {
  return chdir(directory_name.c_str());
}

int32_t directory::set_creation_time(const std::string &path, std::chrono::system_clock::time_point &creation_time) {
  return -1;
}

int32_t directory::set_file_attributes(const std::string& path, int32_t attributes) {
  return -1;
}

int32_t directory::set_last_access_time(const std::string &path, std::chrono::system_clock::time_point &last_access_time) {
  return -1;
}

int32_t directory::set_last_write_time(const std::string &path, std::chrono::system_clock::time_point &last_write_time) {
  return -1;
}
