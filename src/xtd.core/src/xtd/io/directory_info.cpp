#include "../../../include/xtd/io/directory.h"
#include "../../../include/xtd/io/directory_info.h"
#include "../../../include/xtd/io/directory_not_found_exception.h"
#include "../../../include/xtd/io/file_info.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/path_too_long_exception.h"
#include "../../../include/xtd/security/security_exception.h"
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/not_implemented_exception.h"
#include "../../../include/xtd/unauthorized_access_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#include <xtd/native/file_system.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace io;

struct directory_info::directory_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  native::directory::directory_iterator iterator_;
};

directory_info::directory_iterator::directory_iterator(const ustring& path, const ustring& pattern) {
  data_ = make_shared<data>(path, pattern);
}

directory_info::directory_iterator::directory_iterator() {
  data_ = make_shared<data>();
}

directory_info::directory_iterator& directory_info::directory_iterator::operator++() {
  data_->iterator_++;
  return *this;
}

directory_info::directory_iterator directory_info::directory_iterator::operator++(int) {
  directory_iterator result = *this;
  ++(*this);
  return result;
}

bool directory_info::directory_iterator::operator==(directory_info::directory_iterator other) const {
  return data_->iterator_ == other.data_->iterator_;
}

directory_info::directory_iterator::value_type directory_info::directory_iterator::operator*() const {
  if (data_ == nullptr) return empty;
  return directory_info(*data_->iterator_);
}

struct directory_info::file_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  native::directory::file_iterator iterator_;
};

directory_info::file_iterator::file_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
}

directory_info::file_iterator::file_iterator() {
  data_ = make_shared<data>();
}

directory_info::file_iterator& directory_info::file_iterator::operator++() {
  data_->iterator_++;
  return *this;
}

directory_info::file_iterator directory_info::file_iterator::operator++(int) {
  file_iterator result = *this;
  ++(*this);
  return result;
}

bool directory_info::file_iterator::operator==(directory_info::file_iterator other) const {
  return data_->iterator_ == other.data_->iterator_;
}

directory_info::file_iterator::value_type directory_info::file_iterator::operator*() const {
  if (data_ == nullptr) return file_info::empty;
  return file_info(*data_->iterator_);
}

struct directory_info::file_system_info_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  native::directory::file_and_directory_iterator iterator_;
};

directory_info::file_system_info_iterator::file_system_info_iterator(const std::string& path, const std::string& pattern) {
  data_ = make_shared<data>(path, pattern);
}

directory_info::file_system_info_iterator::file_system_info_iterator() {
  data_ = make_shared<data>();
}

directory_info::file_system_info_iterator& directory_info::file_system_info_iterator::operator++() {
  data_->iterator_++;
  return *this;
}

directory_info::file_system_info_iterator directory_info::file_system_info_iterator::operator++(int) {
  file_system_info_iterator result = *this;
  ++(*this);
  return result;
}

bool directory_info::file_system_info_iterator::operator==(directory_info::file_system_info_iterator other) const {
  return data_->iterator_ == other.data_->iterator_;
}

directory_info::file_system_info_iterator::value_type directory_info::file_system_info_iterator::operator*() const {
  if (data_ == nullptr) return std::make_shared<file_info>("");
  int32_t attributes = -1;
  native::file_system::get_attributes(*data_->iterator_, attributes);
  if ((static_cast<file_attributes>(attributes) & file_attributes::directory) == file_attributes::directory) return std::make_shared<directory_info>(*data_->iterator_);
  return std::make_shared<file_info>(*data_->iterator_);
}

const directory_info directory_info::empty;

directory_info::directory_info(const xtd::ustring& path) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  original_path_ = path.length() == 2 && path[1] == ':' ?  "." : path;
  refresh();
}

bool directory_info::exists() const {
  int32_t attributes = 0;
  return native::file_system::get_attributes(full_path_, attributes) == 0 && (static_cast<file_attributes>(attributes) & file_attributes::directory) == file_attributes::directory;
}

ustring directory_info::name() const {
  vector<ustring> items = full_path_.split({path::directory_separator_char()});
  if (items.size() == 0)
    return full_path_;
  return items[items.size() - 1];
}

directory_info directory_info::parent() const {
  if (full_path_ == path::get_path_root(full_path_)) return empty;
  return directory_info(path::combine(full_path_, ".."));
}

directory_info directory_info::root() const {
  return directory_info(path::get_path_root(full_path_));
}

void directory_info::create() {
  if (native::directory::create(full_path_) != 0) throw io_exception(csf_);
  refresh();
}

directory_info directory_info::create_subdirectory(const ustring& path) const {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (native::file_system::is_path_too_long(path::combine(full_path_, path))) throw path_too_long_exception(csf_);

  directory_info dir_info(path::combine(full_path_, path));
  if (!dir_info.exists()) dir_info.create();
  return dir_info;
}

directory_info::directory_iterator directory_info::enumerate_directories() const {
  return enumerate_directories("*");
}

directory_info::directory_iterator directory_info::enumerate_directories(const xtd::ustring& pattern) const {
  return directory_iterator(full_path_, pattern);
}

directory_info::file_iterator directory_info::enumerate_files() const {
  return enumerate_files("*");
}

directory_info::file_iterator directory_info::enumerate_files(const xtd::ustring& pattern) const {
  return file_iterator(full_path_, pattern);
}

directory_info::file_system_info_iterator directory_info::enumerate_file_system_infos() const {
  return enumerate_file_system_infos("*");
}

directory_info::file_system_info_iterator directory_info::enumerate_file_system_infos(const xtd::ustring& pattern) const {
  return file_system_info_iterator(full_path_, pattern);
}

vector<directory_info> directory_info::get_directories() const {
  return get_directories("*");
}

vector<directory_info> directory_info::get_directories(const ustring& pattern) const {
  return {begin(enumerate_directories(pattern)), end(enumerate_directories(pattern))};
}

vector<file_info> directory_info::get_files() const {
  return get_files("*");
}

vector<file_info> directory_info::get_files(const ustring& pattern) const {
  return {begin(enumerate_files(pattern)), end(enumerate_files(pattern))};
}

vector<shared_ptr<file_system_info>> directory_info::get_file_system_infos() const {
  return get_file_system_infos("*");
}

vector<shared_ptr<file_system_info>> directory_info::get_file_system_infos(const ustring& pattern) const {
  return {begin(enumerate_file_system_infos(pattern)), end(enumerate_file_system_infos(pattern))};
}

void directory_info::move_to(const ustring& dest_dir_name) {
  directory_info dest_dir_info(dest_dir_name);
  
  if (dest_dir_name == "" || dest_dir_info.exists() || equals(dest_dir_info) || !path::get_path_root(full_name()).equals(path::get_path_root(dest_dir_info.full_name())) || dest_dir_info.full_name().starts_with(full_name())) throw io_exception(csf_);
  
  ustring target_dir_name = path::combine(dest_dir_name, full_path_.substring(full_path_.last_index_of(path::directory_separator_char()) + 1));
  if (!dest_dir_info.exists()) throw directory_not_found_exception(csf_);
  directory::create_directory(target_dir_name);
  
  for (ustring item : native::directory::enumerate_files(full_path_, "*"))
    file::move(path::combine(full_path_, item), path::combine(target_dir_name, item));
  for (ustring item : native::directory::enumerate_directories(full_path_, "*"))
    directory::move(path::combine(full_path_, item), path::combine(target_dir_name, item));
  
  remove();
  original_path_ = target_dir_name;
  refresh();
}

void directory_info::remove() const {
  return remove(false);
}

void directory_info::remove(bool recursive) const {
  if (!exists()) throw directory_not_found_exception(csf_);
  
  // I don't think is a good think that check recursively directory is read only before...
  /*
  function<bool(const ustring& path, bool recursive)> is_read_only = [&](const ustring& path, bool recursive) {
    if (recursive) {
      for (ustring item : native::directory::enumerate_files(path, "*")) {
        if ((file_info(path::combine(path, item)).attributes() & file_attributes::read_only) == file_attributes::read_only)
          return true;
      }
      for (ustring item : native::directory::enumerate_directories(path, "*")) {
        if (is_read_only(path::combine(path, item), recursive))
          return true;
      }
    }

    return (directory_info(path).attributes() & file_attributes::read_only) == file_attributes::read_only;
  };
 
  if (is_read_only(full_path_, recursive) == true) throw unauthorized_access_exception(csf_);
   */
  
  if (recursive) {
    for (ustring item : native::directory::enumerate_files(full_path_, "*")) {
      file_info fi(path::combine(full_path_, item));
      if ((fi.attributes() & file_attributes::read_only) == file_attributes::read_only) throw unauthorized_access_exception(csf_);
      file::remove(path::combine(full_path_, item));
    }
    for (ustring item : native::directory::enumerate_directories(full_path_, "*"))
      directory_info(path::combine(full_path_, item)).remove(true);
  }
  
  if ((attributes() & file_attributes::read_only) == file_attributes::read_only) throw unauthorized_access_exception(csf_);
  if (native::directory::remove(full_path_) != 0)
    throw io_exception(csf_);
}
