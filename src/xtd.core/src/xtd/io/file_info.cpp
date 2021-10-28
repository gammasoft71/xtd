#include "../../../include/xtd/io/file_info.h"
#include "../../../include/xtd/io/file_attributes.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/directory_info.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/not_implemented_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file.h>
#include <xtd/native/file_system.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace io;

const file_info file_info::empty;

file_info::file_info(const xtd::ustring& path) {
  original_path_ = path;
  refresh();
}

directory_info file_info::directory() const {
  return directory_info(directory_name());
}

ustring file_info::directory_name() const {
  return path::combine(path::get_path_root(full_path_), path::get_directory_name(full_path_));
}

bool file_info::exists() const {
  int32_t attributes = 0;
  return native::file_system::get_attributes(full_path_, attributes) == 0 && (static_cast<file_attributes>(attributes) & file_attributes::directory) != file_attributes::directory;
}

bool file_info::is_read_only() const {
  return (attributes() & file_attributes::read_only) == file_attributes::read_only;
}

size_t file_info::length() const {
  return native::file::get_size(full_path_);
}

ustring file_info::name() const {
  vector<ustring> items = full_path_.split({path::directory_separator_char()});
  if (items.size() == 0) return full_path_;
  return items[items.size() - 1];
}

std::ofstream file_info::append_text() const {
  return file::append_text(full_path_);
}

file_info file_info::copy_to(const xtd::ustring& dest_file_name) const {
  if (!exists()) throw file_not_found_exception(csf_);
  if (file::exists(dest_file_name)) throw io_exception(csf_);
  if (native::file::copy(full_path_, path::get_full_path(dest_file_name)) != 0) throw io_exception(csf_);
  return file_info(dest_file_name);
}

file_info file_info::copy_to(const xtd::ustring& dest_file_name, bool overwrite) const {
  if (overwrite && file::exists(dest_file_name)) file::remove(dest_file_name);
  return copy_to(dest_file_name);
}

std::ofstream file_info::create() const {
  return file::create(full_path_);
}

std::ofstream file_info::create_text() const {
  return file::create_text(full_path_);
}

void file_info::move_to(const xtd::ustring& dest_file_name) {
  if (!exists()) throw file_not_found_exception(csf_);
  if ((attributes() & file_attributes::directory) == file_attributes::directory) throw argument_exception(csf_);
  if (native::file::move(full_path_, path::get_full_path(dest_file_name)) != 0)  throw io_exception(csf_);
  
  original_path_ = dest_file_name;
  refresh();
}

void file_info::move_to(const xtd::ustring& dest_file_name, bool overwrite) {
  if (overwrite && file::exists(dest_file_name)) file::remove(dest_file_name);
  move_to(dest_file_name);
}

std::fstream file_info::open(std::ios::openmode mode) const {
  return file::open(full_path_, mode);
}

std::ifstream file_info::open_read() const {
  return file::open_read(full_path_);
}

std::ifstream file_info::open_text() const {
  return file::open_text(full_path_);
}

std::ofstream file_info::open_write() const {
  return file::open_write(full_path_);
}

void file_info::remove() const {
  throw not_implemented_exception(csf_);
}

void file_info::replace(const xtd::ustring& destination_file_name, const xtd::ustring& destination_backup_file_name) {
  file::replace(full_path_, destination_file_name, destination_backup_file_name);
  original_path_ = destination_file_name;
  refresh();
}
