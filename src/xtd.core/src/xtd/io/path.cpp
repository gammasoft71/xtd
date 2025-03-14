#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/io/drive_info.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/environment.hpp"
#include "../../../include/xtd/random.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/path>
#include <xtd/native/file_system>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::io;

char path::alt_directory_separator_char() noexcept {
  return native::path::alt_directory_separator_char();
}

string path::change_extension(const string& path, const string& extension) {
  auto result = combine(get_directory_name(path), get_file_name_without_extension(path));
  if (string::is_empty(result) && !string::is_empty(extension)) return extension;
  if (string::is_empty(extension)) return result;
  if (!extension.starts_with('.')) result += ".";
  result += extension;
  return result;
}

string path::combine(const string& path1, const string& path2) {
  // if (path1.IndexOfAny(GetInvalidPathchar_ts()) != -1 || path2.IndexOfAny(GetInvalidPathchar_ts()) != -1)  return {};
  if (string::is_empty(path2)) return path1;
  if (string::is_empty(path1) || is_path_rooted(path2)) return path2;
  
  auto result = path1;
  if (!result.ends_with(directory_separator_char())) result += directory_separator_char();
  result += path2;
  return result;
}

string path::combine(const std::initializer_list<string>& paths) noexcept {
  auto result = string::empty_string;
  for (auto path : paths)
    result = combine(result, path);
  return result;
}

char path::directory_separator_char() noexcept {
  return native::path::directory_separator_char();
}

string path::get_directory_name(const string& path) {
  auto index = path.last_index_of(directory_separator_char());
  if (index == string::npos) index = path.last_index_of(alt_directory_separator_char());
  if (index == string::npos) return {};
  return path.substring(0, index);
}

string path::get_extension(const string& path) {
  auto file = get_file_name(path);
  auto index = file.last_index_of('.');
  return index == string::npos ? "" : file.substring(index);
}

string path::get_file_name(const string& path) {
  auto index = path.last_index_of(directory_separator_char());
  if (index == string::npos) index = path.last_index_of(alt_directory_separator_char());
  return (index == string::npos) ? path : path.substring(index + 1);
}

string path::get_file_name_without_extension(const string& path) {
  auto file = get_file_name(path);
  auto index = file.last_index_of('.');
  return (index == string::npos) ? file : file.substring(0, index);
}

string path::get_full_path(const string& path) {
  if (string::is_empty(path)) throw_helper::throws(exception_case::argument);
  return native::file_system::get_full_path(path);
}

array<char> path::get_invalid_path_chars() noexcept {
  return get_invalid_path_chars<char>();
}

string path::get_path_root(const string& path) {
  if (string::is_empty(path)) throw_helper::throws(exception_case::argument);
  return is_path_rooted(path) ? path.substr(0, __get_index_path_rooted(path) + 1) : "";
}

string path::get_random_file_name() {
  return get_random_file_name(8, 3);
}

xtd::string path::get_random_file_name(size_t name_length) {
  return get_random_file_name(name_length, 0);
}

xtd::string path::get_random_file_name(size_t name_length, size_t extension_length) {
  static auto valid_chars = string {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  static auto rand = xtd::random {};
  auto random_file_name = string::empty_string;
  
  for (auto index = 0_z; index < name_length; ++index)
    random_file_name += valid_chars[rand.next(0, as<int32>(valid_chars.size() - 1))];
  if (extension_length) random_file_name += '.';
  for (auto index = 0_z; index < extension_length; ++index)
    random_file_name += valid_chars[rand.next(0, as<int32>(valid_chars.size() - 1))];
  
  return random_file_name;
}

string path::get_temp_file_name() {
  static auto rand = xtd::random {};
  auto temp_file_name = string::empty_string;
  do
    temp_file_name = combine(get_temp_path(), string::format("tmp{:X4}.tmp", rand.next<uint16>()));
  while (file::exists(temp_file_name));
  file::create(temp_file_name);
  return temp_file_name;
}

string path::get_temp_path() noexcept {
  auto temp_path = as<string>(native::path::get_temp_path());
  if (temp_path.ends_with(directory_separator_char())) temp_path = temp_path.remove(temp_path.size() - 1);
  return temp_path;
}

bool path::has_extension(const string& path) {
  return !string::is_empty(get_extension(path));
}

bool path::is_path_rooted(const string& path) {
  return __get_index_path_rooted(path) != -1;
}

char path::path_separator() noexcept {
  return native::path::path_separator();
}

char path::volume_separator_char() noexcept {
  return native::path::volume_separator_char();
}

int32 path::__get_index_path_rooted(const string& path) {
  auto index = path.find(directory_separator_char());
  return (index == string::npos || index == path.size() || (index != 0 && !__is_drive(path.substring(0, index + 1)))) ? -1 : static_cast<int32>(index);
}

bool path::__is_drive(const string& path) noexcept {
  for (auto drive : drive_info::get_drives())
    if (drive.name() == path) return true;
  return false;
}
