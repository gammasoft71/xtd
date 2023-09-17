#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/drive_info.h"
#include "../../../include/xtd/as.h"
#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/random.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/path.h>
#include <xtd/native/file_system.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace io;

char path::alt_directory_separator_char() noexcept {
  return native::path::alt_directory_separator_char();
}

ustring path::change_extension(const ustring& path, const ustring& extension) {
  auto result = combine(get_directory_name(path), get_file_name_without_extension(path));
  if (ustring::is_empty(result) && !ustring::is_empty(extension)) return extension;
  if (ustring::is_empty(extension)) return result;
  if (!extension.starts_with('.')) result += ".";
  result += extension;
  return result;
}

ustring path::combine(const ustring& path1, const ustring& path2) {
  // if (path1.IndexOfAny(GetInvalidPathchar_ts()) != -1 || path2.IndexOfAny(GetInvalidPathchar_ts()) != -1)  return {};
  if (ustring::is_empty(path2)) return path1;
  if (ustring::is_empty(path1) || is_path_rooted(path2)) return path2;
  
  auto result = path1;
  if (!result.ends_with(directory_separator_char())) result += directory_separator_char();
  result += path2;
  return result;
}

ustring path::combine(const initializer_list<ustring>& paths) noexcept {
  auto result = ustring::empty_string;
  for (auto path : paths)
    result = combine(result, path);
  return result;
}

char path::directory_separator_char() noexcept {
  return native::path::directory_separator_char();
}

ustring path::get_directory_name(const ustring& path) {
  auto index = path.last_index_of(directory_separator_char());
  if (index == ustring::npos) index = path.last_index_of(alt_directory_separator_char());
  if (index == ustring::npos) return {};
  return path.substring(0, index);
}

ustring path::get_extension(const ustring& path) {
  auto file = get_file_name(path);
  auto index = file.last_index_of('.');
  return index == ustring::npos ? "" : file.substring(index);
}

ustring path::get_file_name(const ustring& path) {
  auto index = path.last_index_of(directory_separator_char());
  if (index == ustring::npos) index = path.last_index_of(alt_directory_separator_char());
  return (index == ustring::npos) ? path : path.substring(index + 1);
}

ustring path::get_file_name_without_extension(const ustring& path) {
  auto file = get_file_name(path);
  auto index = file.last_index_of('.');
  return (index == ustring::npos) ? file : file.substring(0, index);
}

ustring path::get_full_path(const ustring& path) {
  return native::file_system::get_full_path(path);
}

vector<char> path::get_invalid_path_chars() noexcept {
  return get_invalid_path_chars<char>();
}

ustring path::get_path_root(const ustring& path) {
  return is_path_rooted(path) ? path.substr(0, __get_index_path_rooted(path) + 1) : "";
}

ustring path::get_random_file_name() {
  return get_random_file_name(8, 3);
}

xtd::ustring path::get_random_file_name(size_t name_length) {
  return get_random_file_name(name_length, 0);
}

xtd::ustring path::get_random_file_name(size_t name_length, size_t extension_length) {
  static auto valid_chars = ustring {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  static auto rand = xtd::random {};
  auto random_file_name = ustring::empty_string;
  
  for (auto index = 0_sz; index < name_length; ++index)
    random_file_name += valid_chars[rand.next(0, as<int32>(valid_chars.size() - 1))];
  if (extension_length) random_file_name += '.';
  for (auto index = 0_sz; index < extension_length; ++index)
    random_file_name += valid_chars[rand.next(0, as<int32>(valid_chars.size() - 1))];
  
  return random_file_name;
}

ustring path::get_temp_file_name() {
  static auto rand = xtd::random {};
  auto temp_file_name = ustring::empty_string;
  do
    temp_file_name = combine(get_temp_path(), ustring::format("tmp{:X4}.tmp", rand.next<uint16>()));
  while (file::exists(temp_file_name));
  file::create(temp_file_name);
  return temp_file_name;
}

ustring path::get_temp_path() noexcept {
  auto temp_path = as<ustring>(native::path::get_temp_path());
  if (temp_path.ends_with(directory_separator_char())) temp_path = temp_path.remove(temp_path.size() - 1);
  return temp_path;
}

bool path::has_extension(const ustring& path) {
  return !ustring::is_empty(get_extension(path));
}

bool path::is_path_rooted(const ustring& path) {
  return __get_index_path_rooted(path) != -1;
}

char path::path_separator() noexcept {
  return native::path::path_separator();
}

char path::volume_separator_char() noexcept {
  return native::path::volume_separator_char();
}

int32 path::__get_index_path_rooted(const ustring& path) {
  auto index = path.find(directory_separator_char());
  return (index == ustring::npos || index == path.size() || (index != 0 && !__is_drive(path.substring(0, index + 1)))) ? -1 : static_cast<int32>(index);
}

bool path::__is_drive(const ustring& path) noexcept {
  for (auto drive : drive_info::get_drives())
    if (drive.name() == path) return true;
  return false;
}
