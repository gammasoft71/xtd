#include "../../../include/xtd/io/directory.h"
#include "../../../include/xtd/io/file_info.h"
#include "../../../include/xtd/io/directory_info.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/system_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
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

directory_info::file_iterator::file_iterator() {
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

struct directory::file_system_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  directory_info::file_system_iterator iterator_;
};

directory::file_system_iterator::file_system_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
}

directory::file_system_iterator::file_system_iterator() {
  data_ = make_shared<data>();
}

directory::file_system_iterator& directory::file_system_iterator::operator++() {
  data_->iterator_++;
  return *this;
}

directory::file_system_iterator directory::file_system_iterator::operator++(int) {
  file_system_iterator result = *this;
  ++(*this);
  return result;
}

bool directory::file_system_iterator::operator==(directory::file_system_iterator other) const {
  return data_->iterator_ == other.data_->iterator_;
}

directory::file_system_iterator::value_type directory::file_system_iterator::operator*() const {
  if (data_ == nullptr) return "";
  return (*data_->iterator_)->full_name();
}

directory_info directory::create_directory(const xtd::ustring& path) {
  directory_info dir_info(path);
  if (!dir_info.exists()) {
    if (!ustring::is_empty(dir_info.parent().full_name()))
      create_directory(dir_info.parent().full_name());
    dir_info.create();
  }
  return dir_info;
}

bool directory::exists(const xtd::ustring& path) {
  try {
    return directory_info(path).exists();
  } catch (const system_exception&) {
    return false;
  }
}

void directory::move(const ustring& src, const ustring& dst) {
  if (path::has_extension(src))
    file::move(src, dst);
  else
    directory_info(src).move_to(dst);
}

void directory::remove(const xtd::ustring& path) {
  directory_info(path).remove();
}

void directory::remove(const xtd::ustring& path, bool recursive) {
  directory_info(path).remove(recursive);
}
