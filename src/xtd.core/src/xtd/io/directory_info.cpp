#include "../../../include/xtd/io/directory.hpp"
#include "../../../include/xtd/io/directory_info.hpp"
#include "../../../include/xtd/io/directory_not_found_exception.hpp"
#include "../../../include/xtd/io/file_attributes.hpp"
#include "../../../include/xtd/io/file_info.hpp"
#include "../../../include/xtd/io/io_exception.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/io/path_too_long_exception.hpp"
#include "../../../include/xtd/security/security_exception.hpp"
#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/not_implemented_exception.hpp"
#include "../../../include/xtd/unauthorized_access_exception.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory>
#include <xtd/native/file_system>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::helpers;
using namespace io;

struct directory_info::directory_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  native::directory::directory_iterator iterator_;
};

directory_info::directory_iterator::directory_iterator(const string& path, const string& pattern) {
  data_ = xtd::new_sptr<data>(path, pattern);
}

directory_info::directory_iterator::directory_iterator() {
  data_ = xtd::new_sptr<data>();
}

directory_info::directory_iterator& directory_info::directory_iterator::operator ++() {
  data_->iterator_++;
  return *this;
}

directory_info::directory_iterator directory_info::directory_iterator::operator ++(int32) {
  directory_iterator result = *this;
  ++(*this);
  return result;
}

directory_info::directory_iterator::value_type directory_info::directory_iterator::operator *() const {
  if (data_ == nullptr) return empty;
  return directory_info {*data_->iterator_};
}

directory_info::directory_iterator directory_info::directory_iterator::begin() const {
  return directory_info::directory_iterator {data_->iterator_.path(), data_->iterator_.pattern()};
}

directory_info::directory_iterator directory_info::directory_iterator::end() const {
  return directory_info::directory_iterator {};
}

bool directory_info::directory_iterator::equals(const directory_info::directory_iterator& other) const noexcept {
  return data_->iterator_ == other.data_->iterator_;
}

string directory_info::directory_iterator::path() const {
  return data_->iterator_.path();
}

string directory_info::directory_iterator::pattern() const {
  return data_->iterator_.pattern();
}

struct directory_info::file_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  native::directory::file_iterator iterator_;
};

directory_info::file_iterator::file_iterator(const std::string& path, const std::string& pattern) {
  data_ = xtd::new_sptr<data>(path, pattern);
}

directory_info::file_iterator::file_iterator() {
  data_ = xtd::new_sptr<data>();
}

directory_info::file_iterator& directory_info::file_iterator::operator ++() {
  data_->iterator_++;
  return *this;
}

directory_info::file_iterator directory_info::file_iterator::operator ++(int32) {
  file_iterator result = *this;
  ++(*this);
  return result;
}

directory_info::file_iterator::value_type directory_info::file_iterator::operator *() const {
  if (data_ == nullptr) return file_info::empty;
  return file_info {*data_->iterator_};
}

directory_info::file_iterator directory_info::file_iterator::begin() const {
  return directory_info::file_iterator(data_->iterator_.path(), data_->iterator_.pattern());
}
directory_info::file_iterator directory_info::file_iterator::end() const {
  return xtd::io::directory_info::file_iterator {};
}

bool directory_info::file_iterator::equals(const directory_info::file_iterator& other) const noexcept {
  return data_->iterator_ == other.data_->iterator_;
}

string directory_info::file_iterator::path() const {
  return data_->iterator_.path();
}

string directory_info::file_iterator::pattern() const {
  return data_->iterator_.pattern();
}

struct directory_info::file_system_info_iterator::data {
  data() = default;
  data(const std::string& path, const std::string& pattern) : iterator_(path, pattern) {}
  native::directory::file_and_directory_iterator iterator_;
};

directory_info::file_system_info_iterator::file_system_info_iterator(const std::string& path, const std::string& pattern) {
  data_ = xtd::new_sptr<data>(path, pattern);
}

directory_info::file_system_info_iterator::file_system_info_iterator() {
  data_ = xtd::new_sptr<data>();
}

directory_info::file_system_info_iterator& directory_info::file_system_info_iterator::operator ++() {
  data_->iterator_++;
  return *this;
}

directory_info::file_system_info_iterator directory_info::file_system_info_iterator::operator ++(int32) {
  file_system_info_iterator result = *this;
  ++(*this);
  return result;
}

directory_info::file_system_info_iterator directory_info::file_system_info_iterator::begin() const {
  return directory_info::file_system_info_iterator {data_->iterator_.path(), data_->iterator_.pattern()};
}

directory_info::file_system_info_iterator directory_info::file_system_info_iterator::end() const {
  return xtd::io::directory_info::file_system_info_iterator {};
}

bool directory_info::file_system_info_iterator::equals(const directory_info::file_system_info_iterator& other) const noexcept {
  return data_->iterator_ == other.data_->iterator_;
}

string directory_info::file_system_info_iterator::path() const {
  return data_->iterator_.path();
}

string directory_info::file_system_info_iterator::pattern() const {
  return data_->iterator_.pattern();
}

directory_info::file_system_info_iterator::value_type directory_info::file_system_info_iterator::operator *() const {
  if (data_ == nullptr) return xtd::new_sptr<file_info>("");
  auto attributes = -1;
  native::file_system::get_attributes(*data_->iterator_, attributes);
  if ((as<file_attributes>(attributes) & file_attributes::directory) == file_attributes::directory) return xtd::new_sptr<directory_info>(*data_->iterator_);
  return xtd::new_sptr<file_info>(*data_->iterator_);
}

const directory_info directory_info::empty;

directory_info::directory_info(const xtd::string& path) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  original_path_ = path.length() == 2 && path[1] == ':' ?  "." : path;
  refresh();
}

bool directory_info::exists() const {
  auto attributes = 0;
  return native::file_system::get_attributes(full_path_, attributes) == 0 && (static_cast<file_attributes>(attributes) & file_attributes::directory) == file_attributes::directory;
}

string directory_info::name() const {
  auto items = full_path_.split(path::directory_separator_char());
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
  if (native::directory::create(full_path_) != 0) throw_helper::throws(exception_case::io);
  refresh();
}

directory_info directory_info::create_subdirectory(const string& path) const {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path::combine(full_path_, path))) throw_helper::throws(exception_case::path_too_long);
  
  auto dir_info = directory_info {path::combine(full_path_, path)};
  if (!dir_info.exists()) dir_info.create();
  return dir_info;
}

directory_info::directory_iterator directory_info::enumerate_directories() const {
  return enumerate_directories("*");
}

directory_info::directory_iterator directory_info::enumerate_directories(const xtd::string& pattern) const {
  return directory_iterator {full_path_, pattern};
}

directory_info::file_iterator directory_info::enumerate_files() const {
  return enumerate_files("*");
}

directory_info::file_iterator directory_info::enumerate_files(const xtd::string& pattern) const {
  return file_iterator {full_path_, pattern};
}

directory_info::file_system_info_iterator directory_info::enumerate_file_system_infos() const {
  return enumerate_file_system_infos("*");
}

directory_info::file_system_info_iterator directory_info::enumerate_file_system_infos(const xtd::string& pattern) const {
  return file_system_info_iterator {full_path_, pattern};
}

xtd::array<directory_info> directory_info::get_directories() const {
  return get_directories("*");
}

xtd::array<directory_info> directory_info::get_directories(const string& pattern) const {
  return {std::begin(enumerate_directories(pattern)), std::end(enumerate_directories(pattern))};
}

xtd::array<file_info> directory_info::get_files() const {
  return get_files("*");
}

xtd::array<file_info> directory_info::get_files(const string& pattern) const {
  return {std::begin(enumerate_files(pattern)), std::end(enumerate_files(pattern))};
}

xtd::array<xtd::sptr<file_system_info>> directory_info::get_file_system_infos() const {
  return get_file_system_infos("*");
}

xtd::array<xtd::sptr<file_system_info>> directory_info::get_file_system_infos(const string& pattern) const {
  return {std::begin(enumerate_file_system_infos(pattern)), std::end(enumerate_file_system_infos(pattern))};
}

void directory_info::move_to(const string& dest_dir_name) {
  auto dest_dir_info = directory_info {dest_dir_name};
  if (dest_dir_name == "" || dest_dir_info.exists() || equals(dest_dir_info) || !path::get_path_root(full_name()).equals(path::get_path_root(dest_dir_info.full_name())) || dest_dir_info.full_name().starts_with(full_name())) throw_helper::throws(exception_case::io);
  
  auto target_dir_name = path::combine(dest_dir_name, full_path_.substring(full_path_.last_index_of(path::directory_separator_char()) + 1));
  if (!dest_dir_info.exists()) throw_helper::throws(exception_case::directory_not_found);
  
  directory::create_directory(target_dir_name);
  for (string item : native::directory::enumerate_files(full_path_, "*"))
    file::move(path::combine(full_path_, item), path::combine(target_dir_name, item));
  for (string item : native::directory::enumerate_directories(full_path_, "*"))
    directory::move(path::combine(full_path_, item), path::combine(target_dir_name, item));
    
  remove();
  original_path_ = std::move(target_dir_name);
  refresh();
}

void directory_info::remove() const {
  return remove(false);
}

void directory_info::remove(bool recursive) const {
  if (!exists()) throw_helper::throws(exception_case::directory_not_found);
  
  // I don't think is a good think that check recursively directory is read only before...
  /*
  function<bool(const string& path, bool recursive)> is_read_only = [&](const string& path, bool recursive) {
    if (recursive) {
      for (string item : native::directory::enumerate_files(path, "*")) {
        if ((file_info(path::combine(path, item)).attributes() & file_attributes::read_only) == file_attributes::read_only)
          return true;
      }
      for (string item : native::directory::enumerate_directories(path, "*")) {
        if (is_read_only(path::combine(path, item), recursive))
          return true;
      }
    }
  
    return (directory_info(path).attributes() & file_attributes::read_only) == file_attributes::read_only;
  };
  
  if (is_read_only(full_path_, recursive) == true) throw_helper::throws(exception_case::unauthorized_access);
   */
  
  if (recursive) {
    for (const auto& item : native::directory::enumerate_files(full_path_, "*")) {
      file_info fi(path::combine(full_path_, item));
      if ((fi.attributes() & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
      file::remove(path::combine(full_path_, item));
    }
    for (const auto& item : native::directory::enumerate_directories(full_path_, "*"))
      directory_info(path::combine(full_path_, item)).remove(true);
  }
  
  if ((attributes() & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
  if (native::directory::remove(full_path_) != 0)
    throw_helper::throws(exception_case::io);
}
