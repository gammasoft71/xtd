#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/diagnostics/stack_frame.hpp"
#include "../../../include/xtd/unauthorized_access_exception.hpp"
#include "../../../include/xtd/collections/generic/list.hpp"
#include "../../../include/xtd/io/directory.hpp"
#include "../../../include/xtd/io/file.hpp"
#include "../../../include/xtd/io/file_not_found_exception.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/io/path_too_long_exception.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file>
#include <xtd/native/file_system>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::helpers;
using namespace io;

auto file::append_text(const string& path) -> std::ofstream {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) [[maybe_unused]] auto stream = create_text(path);
  if ((get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
  
  auto stream = std::ofstream {path, std::ios::out | std::ios::app};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

auto file::copy(const string& src, const string& dest) -> void {
  return copy(src, dest, true);
}

auto file::copy(const string& src, const string& dest, bool overwrite) -> void {
  if (src.index_of_any(io::path::get_invalid_path_chars()) != src.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(src) || xtd::string::is_empty(src.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(src)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(src)) throw_helper::throws(exception_case::file_not_found);
  
  if (dest.index_of_any(io::path::get_invalid_path_chars()) != dest.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(dest) || xtd::string::is_empty(dest.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(dest)) throw_helper::throws(exception_case::path_too_long);
  if (!overwrite && exists(dest)) throw_helper::throws(exception_case::io);
  
  if (overwrite && native::file::exists(dest)) {
    if ((get_attributes(dest) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
    if (native::file::remove(dest) != 0) throw_helper::throws(exception_case::io);
  }
  
  if (native::file::copy(src, dest) != 0) throw_helper::throws(exception_case::io);
}

auto file::create(const string& path) -> std::ofstream {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
  
  auto stream = std::ofstream {path, std::ios::binary | std::ios::out};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

auto file::create_text(const string& path) -> stream_writer {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);

  return stream_writer {path};
}

auto file::exists(const string& path) noexcept -> bool {
  return native::file::exists(path);
}

auto file::get_attributes(const string& path) -> file_attributes {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  auto attributes = 0;
  if (native::file_system::get_attributes(path, attributes) != 0) throw_helper::throws(exception_case::file_not_found);
  return static_cast<file_attributes>(attributes);
}

auto file::get_creation_time(const xtd::string& path) -> date_time {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  [[maybe_unused]] auto [creation_time, last_access_time, last_write_time] = get_file_times(path);
  return date_time::from_time_t(creation_time, date_time_kind::local);
}

auto file::get_last_access_time(const xtd::string& path) -> date_time {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  [[maybe_unused]] auto [creation_time, last_access_time, last_write_time] = get_file_times(path);
  return date_time::from_time_t(last_access_time, date_time_kind::local);
}

auto file::get_last_write_time(const xtd::string& path) -> date_time {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  [[maybe_unused]] auto [creation_time, last_access_time, last_write_time] = get_file_times(path);
  return date_time::from_time_t(last_write_time, date_time_kind::local);
}

auto file::get_permissions(const string& path) -> file_permissions {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  auto permission = 0;
  if (native::file_system::get_permissions(path, permission) != 0) throw_helper::throws(exception_case::file_not_found);
  return static_cast<file_permissions>(permission);
}

auto file::move(const string& src, const string& dest) -> void {
  move(src, dest, false);
}

auto file::move(const string& src, const string& dest, bool overwrite) -> void {
  if (src.index_of_any(io::path::get_invalid_path_chars()) != src.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(src) || xtd::string::is_empty(src.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(src)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(src)) throw_helper::throws(exception_case::file_not_found);
  
  if (dest.index_of_any(io::path::get_invalid_path_chars()) != dest.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(dest) || xtd::string::is_empty(dest.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(src)) throw_helper::throws(exception_case::path_too_long);
  if (!overwrite && exists(dest)) throw_helper::throws(exception_case::io);
  
  if (overwrite && native::file::exists(dest)) {
    if ((get_attributes(dest) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
    if (native::file::remove(dest) != 0) throw_helper::throws(exception_case::io);
  }
  
  if (native::file::move(src, dest) != 0) throw_helper::throws(exception_case::io);
}

auto file::open(const string& path, std::ios::openmode mode) -> std::fstream {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if ((mode & std::ios::in) == std::ios::in && !exists(string(path))) throw_helper::throws(exception_case::file_not_found);
  if ((mode & std::ios::in) == std::ios::in && (get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
  
  auto stream = std::fstream {path, mode};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

auto file::open_read(const string& path) -> std::ifstream {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);
  
  auto stream = std::ifstream {path, std::ios::binary | std::ios::in};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

auto file::open_text(const string& path) -> stream_reader {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);

  return stream_reader {path};
}

auto file::open_write(const string& path) -> std::ofstream {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  
  auto stream = std::ofstream {path, std::ios::binary | std::ios::out};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

auto file::read_all_bytes(const string& path) -> array<xtd::byte> {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);
  
  auto stream = std::ifstream {path, std::ios::binary};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return array<xtd::byte> {std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>()};
}

auto file::read_all_lines(const string& path) -> array<string> {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);
  
  auto contents = list<string> {};
  stream_reader sr(path);
  while (!sr.end_of_stream())
    contents.add(sr.read_line());
  return contents.to_array();
}

auto file::read_all_text(const string& path) -> string {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);
  
  auto sr = stream_reader {path};
  return sr.read_to_end();
}

auto file::remove(const string& path) -> void {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file::remove(path) != 0) throw_helper::throws(exception_case::io);
}

auto file::replace(const string& source_file_name, const string& destination_file_name, const string& destination_backup_file_name) -> void {
  if (!exists(source_file_name) || !exists(destination_file_name)) throw_helper::throws(exception_case::file_not_found);
  if (destination_backup_file_name != "") copy(destination_file_name, destination_backup_file_name);
  move(source_file_name, destination_file_name, true);
}

auto file::set_attributes(const xtd::string& path, xtd::io::file_attributes attributes) -> void {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file_system::set_attributes(path, static_cast<int32>(attributes)) != 0) throw_helper::throws(exception_case::io);
}

auto file::set_creation_time(const xtd::string& path, const xtd::date_time& creation_time) -> void {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file_system::set_creation_time(path, creation_time.to_time_t()) != 0) throw_helper::throws(exception_case::io);
}

auto file::set_last_access_time(const xtd::string& path, const xtd::date_time& last_access_time) -> void {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file_system::set_last_access_time(path, last_access_time.to_time_t()) != 0) throw_helper::throws(exception_case::io);
}

auto file::set_last_write_time(const xtd::string& path, const xtd::date_time& last_write_time) -> void {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file_system::set_last_write_time(path, last_write_time.to_time_t()) != 0) throw_helper::throws(exception_case::io);
}

auto file::set_permissions(const xtd::string& path, xtd::io::file_permissions permissions) -> void {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file_system::set_permissions(path, static_cast<int32>(permissions)) != 0) throw_helper::throws(exception_case::io);
}

auto file::write_text(const string& path) -> stream_writer {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (xtd::string::is_empty(path) || xtd::string::is_empty(path.trim(' '))) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  
  return stream_writer(path);
}

auto file::get_file_times(const string& path) -> std::tuple<std::time_t, std::time_t, std::time_t> {
  auto creation_time = std::time_t {}, last_access_time = std::time_t {}, last_write_time = std::time_t {};
  if (native::file_system::get_file_times(path, creation_time, last_access_time, last_write_time) != 0) throw_helper::throws(exception_case::io);
  return std::make_tuple(creation_time, last_access_time, last_write_time);
}
