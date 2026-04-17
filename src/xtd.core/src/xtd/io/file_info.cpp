#include "../../../include/xtd/io/file_info.hpp"
#include "../../../include/xtd/io/file_attributes.hpp"
#include "../../../include/xtd/io/file_not_found_exception.hpp"
#include "../../../include/xtd/io/directory_info.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/argument_exception.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file>
#include <xtd/native/file_system>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::helpers;
using namespace io;

const file_info file_info::empty;

file_info::file_info(const xtd::string& file_name) {
  original_path_ = file_name;
  refresh();
}

auto file_info::directory() const -> directory_info {
  return directory_info {directory_name()};
}

auto file_info::directory_name() const -> string {
  return path::combine(path::get_path_root(full_path_), path::get_directory_name(full_path_));
}

auto file_info::exists() const -> bool {
  try {
    auto attributes = 0;
    return native::file_system::get_attributes(full_path_, attributes) == 0 && (static_cast<file_attributes>(attributes) & file_attributes::directory) != file_attributes::directory;
  } catch (...) {
    return false;
  }
}

auto file_info::is_read_only() const -> bool {
  return (attributes() & file_attributes::read_only) == file_attributes::read_only;
}

auto file_info::is_read_only(bool value) -> void {
  auto attributes = 0;
  if (native::file_system::get_attributes(full_path_, attributes) != 0) throw_helper::throws(exception_case::io);
  if (value) attributes |= static_cast<int32>(file_attributes::read_only);
  else attributes &= ~static_cast<int32>(file_attributes::read_only);
  if (native::file_system::set_attributes(full_path_, attributes) != 0) throw_helper::throws(exception_case::io);
}

auto file_info::length() const -> usize {
  return native::file::get_size(full_path_);
}

auto file_info::name() const -> string {
  auto items = full_path_.split(path::directory_separator_char());
  if (items.length() == 0) return full_path_;
  return items[~1_z];
}

auto file_info::append_text() const -> stream_writer {
  return stream_writer {full_path_, true};
}

auto file_info::copy_to(const xtd::string& dest_file_name) const -> file_info {
  if (!exists()) throw_helper::throws(exception_case::file_not_found);
  if (file::exists(dest_file_name)) throw_helper::throws(exception_case::io);
  if (native::file::copy(full_path_, path::get_full_path(dest_file_name)) != 0) throw_helper::throws(exception_case::io);
  return file_info {dest_file_name};
}

auto file_info::copy_to(const xtd::string& dest_file_name, bool overwrite) const -> file_info {
  if (overwrite && file::exists(dest_file_name)) file::remove(dest_file_name);
  return copy_to(dest_file_name);
}

auto file_info::create() const -> std::ofstream {
  return file::create(full_path_);
}

auto file_info::create_text() const -> stream_writer {
  return stream_writer {full_path_};
}

auto file_info::move_to(const xtd::string& dest_file_name) -> void {
  if (!exists()) throw_helper::throws(exception_case::file_not_found);
  if ((attributes() & file_attributes::directory) == file_attributes::directory) throw_helper::throws(exception_case::argument);
  if (native::file::move(full_path_, path::get_full_path(dest_file_name)) != 0)  throw_helper::throws(exception_case::io);
  
  original_path_ = dest_file_name;
  refresh();
}

auto file_info::move_to(const xtd::string& dest_file_name, bool overwrite) -> void {
  if (overwrite && file::exists(dest_file_name)) file::remove(dest_file_name);
  move_to(dest_file_name);
}

auto file_info::open(std::ios::openmode mode) const -> std::fstream {
  return file::open(full_path_, mode);
}

auto file_info::open_read() const -> std::ifstream {
  return file::open_read(full_path_);
}

auto file_info::open_text() const -> stream_reader {
  return stream_reader(full_path_);
}

auto file_info::open_write() const -> std::ofstream {
  return file::open_write(full_path_);
}

auto file_info::remove() const -> void {
  if (!exists()) return;
  file::remove(full_path_);
}

auto file_info::replace(const xtd::string& destination_file_name, const xtd::string& destination_backup_file_name) -> file_info {
  file::replace(full_path_, destination_file_name, destination_backup_file_name);
  original_path_ = destination_backup_file_name;
  refresh();
  return file_info(destination_file_name);
}
