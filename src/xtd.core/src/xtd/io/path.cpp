#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/environment.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/path.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <filesystem>

using namespace std;
using namespace xtd;
using namespace io;

char path::alt_directory_separator_char() noexcept {
  return alt_directory_separator_char<char>();
}

ustring path::change_extension(const ustring& path, const ustring& extension) {
  ustring path_without_extension = combine(get_directory_name(path), get_file_name_without_extension(path));
  if (ustring::is_empty(path_without_extension) && !ustring::is_empty(extension)) return extension;
  if (ustring::is_empty(extension)) return path_without_extension;
  stringstream ss;
  ss << path_without_extension;
  if (path_without_extension[path_without_extension.size() - 1] != '.'  && extension[0] != '.') ss << '.';
  ss << extension;
  return ss.str();
}

ustring path::combine(const ustring& path1, const ustring& path2) {
  // if (path1.IndexOfAny(GetInvalidPathchar_ts()) != -1 || path2.IndexOfAny(GetInvalidPathchar_ts()) != -1)  return {};
  if (ustring::is_empty(path2)) return path1;
  if (ustring::is_empty(path1) || is_path_rooted(path2)) return path2;
  
  stringstream ss;
  ss << path1;
  if (path1[path1.size() - 1] != directory_separator_char()) ss <<  directory_separator_char();
  ss << path2;
  return ss.str();
}

ustring path::combine(const initializer_list<ustring>& paths) noexcept {
  ustring result;
  for (auto path : paths)
    result = combine(result, path);
  return result;
}

char path::directory_separator_char() noexcept {
  return directory_separator_char<char>();
}

ustring path::get_directory_name(const ustring& path) {
  size_t index = path.rfind(directory_separator_char());
  if (index == ustring::npos) index = path.last_index_of(alt_directory_separator_char());
  if (index == ustring::npos) return {};
  ustring directory = path.substring(0, index);
  return directory;
}

ustring path::get_extension(const ustring& path) {
  ustring file = get_file_name(path);
  size_t index = file.last_index_of('.');
  return index == ustring::npos ? "" : file.substring(index);
}

ustring path::get_file_name(const ustring& path) {
  size_t index = path.last_index_of(directory_separator_char());
  if (index == ustring::npos) index = path.rfind(alt_directory_separator_char());
  return (index == ustring::npos) ? path : path.substring(index + 1);
}

ustring path::get_file_name_without_extension(const ustring& path) {
  ustring file = get_file_name(path);
  size_t index = file.last_index_of('.');
  return (index == ustring::npos) ? file : file.substring(0, index);
}

ustring path::get_full_path(const ustring& path) {
  string path_str = path;
  basic_regex<char> r(string("(\\") + directory_separator_char<char>() + alt_directory_separator_char<char>() + string(")+"));
  vector<ustring> directories;
  for (sregex_token_iterator it(path_str.begin(), path_str.end(), r, -1), end; it != end; ++it)
    if (*it != "") directories.push_back(it->str());
  
  ustring full_path;
  
  if (path[0] != directory_separator_char() && path[0] != alt_directory_separator_char()) full_path = filesystem::current_path().string();
  for (auto item : directories) {
    if (item == ".." && full_path.last_index_of(directory_separator_char()) != ustring::npos)
      full_path = full_path.substr(0, full_path.last_index_of(directory_separator_char()));
    else if (item == ".." && full_path.last_index_of(alt_directory_separator_char()) != ustring::npos)
      full_path = full_path.substr(0, full_path.last_index_of(alt_directory_separator_char()));
    else if (item != ".") {
      stringstream ss;
      ss << full_path << directory_separator_char() << item;
      full_path = ss.str();
    }
  }
  
  if (path[path.size() - 1] == directory_separator_char()) {
    stringstream ss;
    ss << full_path << directory_separator_char();
    full_path = ss.str();
  }
  
  return full_path;
}

vector<char> path::get_invalid_path_chars() noexcept {
  return get_invalid_path_chars<char>();
}

ustring path::get_path_root(const ustring& path) {
  return is_path_rooted(path) ? path.substr(0, __get_index_path_rooted(path) + 1) : "";
}

ustring path::get_random_file_name() {
  static ustring valid_chars = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  random_device rand;
  ustring random_file_name;
  
  for (size_t i = 0; i < 11; i++) {
    random_file_name += valid_chars[uniform_int_distribution<size_t> {0, valid_chars.size() - 1}(rand)];
    if (i == 7)
      random_file_name += '.';
  }
  
  return random_file_name;
}

ustring path::get_temp_file_name() {
  static ustring valid_chars = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'a', 'b', 'c', 'd', 'e', 'f'};
  ustring temp_file_name;
  do {
    static random_device rand;
    temp_file_name = "tmp";
    
    for (size_t i = 0; i < 8; i++) {
      if (i == 0)
        temp_file_name += valid_chars[uniform_int_distribution<size_t> {0, 9}(rand)];
      else
        temp_file_name += valid_chars[uniform_int_distribution<size_t> {0, valid_chars.size() - 1}(rand)];
    }
    temp_file_name += ".tmp";
  } while (file::exists(combine(get_temp_path(), temp_file_name)));
  file::create(combine(get_temp_path(), temp_file_name));
  return combine(get_temp_path(), temp_file_name);
}

ustring path::get_temp_path() noexcept {
  return native::path::get_temp_path();
}

bool path::has_extension(const ustring& path) {
  return !ustring::is_empty(get_extension(path));
}

bool path::is_path_rooted(const ustring& path) {
  return __get_index_path_rooted(path) != -1;
}

char path::path_separator() noexcept {
  return path_separator<char>();
}

char path::volume_separator_char() noexcept {
  return  volume_separator_char<char>();
}

int path::__get_index_path_rooted(const ustring& path) {
  size_t index = path.find(directory_separator_char());
  return (index == ustring::npos || index == path.size() || (index != 0 && !__is_drive(path.substring(0, index + 1)))) ? -1 : static_cast<int>(index);
}

bool path::__is_windows_os() noexcept {
  return environment::os_version().is_windows_platform();
}

bool path::__is_drive(const ustring& path) noexcept {
  /// @todo remove comment when drive_info::get_drives will be create
  /*
   for (auto drive : drive_info::get_drives())
   if (drive.name() == path)
   return true;
   */
  return false;
}
