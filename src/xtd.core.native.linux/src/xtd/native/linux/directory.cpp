#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory>
#include <xtd/native/file_system>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <algorithm>
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
  if (data_->handle_) ++(*this);
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

directory::directory_iterator& directory::directory_iterator::operator ++() {
  dirent* item = nullptr;
  auto attributes = 0;
  do {
    if ((item = readdir(data_->handle_)) != nullptr)
      native::file_system::get_attributes(data_->path_ + '/' + item->d_name, attributes);
  } while (item != nullptr && ((attributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY || string(item->d_name) == "." ||  string(item->d_name) == ".."  || !pattern_compare(item->d_name, data_->pattern_)));
  
  if (item == nullptr) data_->current_ = "";
  else data_->current_ = data_->path_ + (data_->path_.rfind('/') == data_->path_.size() - 1 ? "" : "/") + item->d_name;
  return *this;
}

directory::directory_iterator directory::directory_iterator::operator ++(int32_t) {
  auto result = *this;
  ++(*this);
  return result;
}

bool directory::directory_iterator::operator ==(directory::directory_iterator other) const {
  return data_->current_ == other.data_->current_;
}

directory::directory_iterator::value_type directory::directory_iterator::operator *() const {
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
  DIR* handle_ = nullptr;
  mutable string current_;
};

directory::file_iterator::file_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
  data_->handle_ = opendir(data_->path_.c_str());
  if (data_->handle_) ++(*this);
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

directory::file_iterator& directory::file_iterator::operator ++() {
  dirent* item = nullptr;
  auto attributes = 0;
  do {
    if ((item = readdir(data_->handle_)) != nullptr)
      native::file_system::get_attributes(data_->path_ + '/' + item->d_name, attributes);
  } while (item != nullptr && ((attributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY || string(item->d_name) == "." ||  string(item->d_name) == ".."  || !pattern_compare(item->d_name, data_->pattern_)));
  
  if (item == nullptr) data_->current_ = "";
  else data_->current_ = data_->path_ + (data_->path_.rfind('/') == data_->path_.size() - 1 ? "" : "/") + item->d_name;
  return *this;
}

directory::file_iterator directory::file_iterator::operator ++(int32_t) {
  auto result = *this;
  ++(*this);
  return result;
}

bool directory::file_iterator::operator ==(directory::file_iterator other) const {
  return data_->current_ == other.data_->current_;
}

directory::file_iterator::value_type directory::file_iterator::operator *() const {
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

directory::file_and_directory_iterator& directory::file_and_directory_iterator::operator ++() {
  dirent* item;
  auto attributes = 0;
  do {
    if ((item = readdir(data_->handle_)) != nullptr)
      native::file_system::get_attributes(data_->path_ + '/' + item->d_name, attributes);
  } while (item != nullptr && (string(item->d_name) == "." ||  string(item->d_name) == ".."  || !pattern_compare(item->d_name, data_->pattern_)));
  
  if (item == nullptr) data_->current_ = "";
  else data_->current_ = data_->path_ + (data_->path_.rfind('/') == data_->path_.size() - 1 ? "" : "/") + item->d_name;
  return *this;
}

directory::file_and_directory_iterator directory::file_and_directory_iterator::operator ++(int32_t) {
  auto result = *this;
  ++(*this);
  return result;
}

bool directory::file_and_directory_iterator::operator ==(directory::file_and_directory_iterator other) const {
  return data_->current_ == other.data_->current_;
}

directory::file_and_directory_iterator::value_type directory::file_and_directory_iterator::operator *() const {
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

bool directory::exists(const std::string& path) {
  auto attributes = 0;
  return file_system::get_attributes(path, attributes) == 0 && (attributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY;
}

string directory::get_current_directory() {
  auto path = std::string(MAXPATHLEN + 1, 0);
  auto result = getcwd(path.data(), MAXPATHLEN);
  //path.shrink_to_fit();
  path.erase(std::find(path.begin(), path.end(), '\0'), path.end());
  return result ? path : "";
}

int32_t directory::remove(const std::string& directory_name) {
  return rmdir(directory_name.c_str());
}

int32_t directory::set_current_directory(const std::string& directory_name) {
  return chdir(directory_name.c_str());
}
