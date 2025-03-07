#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/diagnostics/stack_frame.hpp"
#include "../../../include/xtd/unauthorized_access_exception.hpp"
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
using namespace xtd::helpers;
using namespace io;

std::ofstream file::append_text(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) create_text(path);
  if ((get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
  
  auto stream = std::ofstream {path, std::ios::out | std::ios::app};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

void file::copy(const string& src, const string& dest) {
  return copy(src, dest, true);
}

void file::copy(const string& src, const string& dest, bool overwrite) {
  if (src.index_of_any(io::path::get_invalid_path_chars()) != src.npos) throw_helper::throws(exception_case::argument);
  if (src.empty() || src.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(src)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(src)) throw_helper::throws(exception_case::file_not_found);
  
  if (dest.index_of_any(io::path::get_invalid_path_chars()) != dest.npos) throw_helper::throws(exception_case::argument);
  if (dest.empty() || dest.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(dest)) throw_helper::throws(exception_case::path_too_long);
  if (!overwrite && exists(dest)) throw_helper::throws(exception_case::io);
  
  if (overwrite && native::file::exists(dest)) {
    if ((get_attributes(dest) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
    if (native::file::remove(dest) != 0) throw_helper::throws(exception_case::io);
  }
  
  if (native::file::copy(src, dest) != 0) throw_helper::throws(exception_case::io);
}

std::ofstream file::create(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
  
  auto stream = std::ofstream {path, std::ios::binary | std::ios::out};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

std::ofstream file::create_text(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (exists(path) && (get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
  
  auto stream = std::ofstream {path};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

bool file::exists(const string& path) noexcept {
  return native::file::exists(path);
}

file_attributes file::get_attributes(const string& path) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  auto attributes = 0;
  if (native::file_system::get_attributes(path, attributes) != 0) throw_helper::throws(exception_case::file_not_found);
  return static_cast<file_attributes>(attributes);
}

date_time file::get_creation_time(const xtd::string& path) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  [[maybe_unused]] auto [creation_time, last_access_time, last_write_time] = get_file_times(path);
  return date_time::from_time_t(creation_time, date_time_kind::local);
}

date_time file::get_last_access_time(const xtd::string& path) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  [[maybe_unused]] auto [creation_time, last_access_time, last_write_time] = get_file_times(path);
  return date_time::from_time_t(last_access_time, date_time_kind::local);
}

date_time file::get_last_write_time(const xtd::string& path) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  [[maybe_unused]] auto [creation_time, last_access_time, last_write_time] = get_file_times(path);
  return date_time::from_time_t(last_write_time, date_time_kind::local);
}

file_permissions file::get_permissions(const string& path) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  auto permission = 0;
  if (native::file_system::get_permissions(path, permission) != 0) throw_helper::throws(exception_case::file_not_found);
  return static_cast<file_permissions>(permission);
}

void file::move(const string& src, const string& dest) {
  move(src, dest, false);
}

void file::move(const string& src, const string& dest, bool overwrite) {
  if (src.index_of_any(io::path::get_invalid_path_chars()) != src.npos) throw_helper::throws(exception_case::argument);
  if (src.empty() || src.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(src)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(src)) throw_helper::throws(exception_case::file_not_found);
  
  if (dest.index_of_any(io::path::get_invalid_path_chars()) != dest.npos) throw_helper::throws(exception_case::argument);
  if (dest.empty() || dest.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(src)) throw_helper::throws(exception_case::path_too_long);
  if (!overwrite && exists(dest)) throw_helper::throws(exception_case::io);
  
  if (overwrite && native::file::exists(dest)) {
    if ((get_attributes(dest) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
    if (native::file::remove(dest) != 0) throw_helper::throws(exception_case::io);
  }
  
  if (native::file::move(src, dest) != 0) throw_helper::throws(exception_case::io);
}

std::fstream file::open(const string& path, std::ios::openmode mode) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if ((mode & std::ios::in) == std::ios::in && !exists(string(path))) throw_helper::throws(exception_case::file_not_found);
  if ((mode & std::ios::in) == std::ios::in && (get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
  
  auto stream = std::fstream {path, mode};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

std::ifstream file::open_read(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);
  
  auto stream = std::ifstream {path, std::ios::binary | std::ios::in};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

std::ifstream file::open_text(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);
  
  auto stream = std::ifstream {path};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

std::ofstream file::open_write(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  
  auto stream = std::ofstream {path, std::ios::binary | std::ios::out};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

array<xtd::byte> file::read_all_bytes(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);
  
  auto stream = std::ifstream {path, std::ios::binary};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return array<xtd::byte> {std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>()};
}

array<string> file::read_all_lines(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);
  
  auto contents = std::vector<string> {};
  stream_reader sr(path);
  while (!sr.end_of_stream())
    contents.push_back(sr.read_line());
  return contents;
}

string file::read_all_text(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);
  
  auto sr = stream_reader {path};
  return sr.read_to_end();
}

void file::remove(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!exists(path)) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file::remove(path) != 0) throw_helper::throws(exception_case::io);
}

void file::replace(const string& source_file_name, const string& destination_file_name, const string& destination_backup_file_name) {
  if (!exists(source_file_name) || !exists(destination_file_name)) throw_helper::throws(exception_case::file_not_found);
  if (destination_backup_file_name != "") copy(destination_file_name, destination_backup_file_name);
  move(source_file_name, destination_file_name, true);
}

void file::set_attributes(const xtd::string& path, xtd::io::file_attributes attributes) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file_system::set_attributes(path, static_cast<int32>(attributes)) != 0) throw_helper::throws(exception_case::io);
}

void file::set_creation_time(const xtd::string& path, const xtd::date_time& creation_time) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file_system::set_creation_time(path, creation_time.to_time_t()) != 0) throw_helper::throws(exception_case::io);
}

void file::set_last_access_time(const xtd::string& path, const xtd::date_time& last_access_time) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file_system::set_last_access_time(path, last_access_time.to_time_t()) != 0) throw_helper::throws(exception_case::io);
}

void file::set_last_write_time(const xtd::string& path, const xtd::date_time& last_write_time) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file_system::set_last_write_time(path, last_write_time.to_time_t()) != 0) throw_helper::throws(exception_case::io);
}

void file::set_permissions(const xtd::string& path, xtd::io::file_permissions permissions) {
  if (path.index_of_any(io::path::get_invalid_path_chars()) != path.npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  if (!(exists(path) || directory::exists(path))) throw_helper::throws(exception_case::file_not_found);
  
  if (native::file_system::set_permissions(path, static_cast<int32>(permissions)) != 0) throw_helper::throws(exception_case::io);
}

std::ofstream file::write_text(const string& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (native::file_system::is_path_too_long(path)) throw_helper::throws(exception_case::path_too_long);
  
  auto stream = std::ofstream {path};
  if (!stream.good()) throw_helper::throws(exception_case::io);
  return stream;
}

std::tuple<time_t, time_t, time_t> file::get_file_times(const string& path) {
  auto creation_time = time_t {}, last_access_time = time_t {}, last_write_time = time_t {};
  if (native::file_system::get_file_times(path, creation_time, last_access_time, last_write_time) != 0) throw_helper::throws(exception_case::io);
  return std::make_tuple(creation_time, last_access_time, last_write_time);
}
