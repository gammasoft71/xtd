#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file_system.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace std;
using namespace xtd::native;

#undef max
#undef min

int32_t file_system::get_attributes(const string& path, int32_t& attributes) {
  auto attrib = GetFileAttributes(win32::strings::to_wstring(path).c_str());
  if (attrib != INVALID_FILE_ATTRIBUTES) attributes = static_cast<int32_t>(attrib);
  return attrib != INVALID_FILE_ATTRIBUTES ? 0 : -1;
}

int32_t file_system::get_file_times(const string& path, chrono::system_clock::time_point& creation_time, chrono::system_clock::time_point& last_access_time, chrono::system_clock::time_point& last_write_time) {
  struct stat file_stat;
  if (stat(path.c_str(), &file_stat) != 0)
    return -1;
  creation_time = chrono::system_clock::from_time_t(static_cast<time_t>(file_stat.st_ctime));
  last_access_time = chrono::system_clock::from_time_t(static_cast<time_t>(file_stat.st_atime));
  last_write_time = chrono::system_clock::from_time_t(static_cast<time_t>(file_stat.st_mtime));
  return 0;
}

string file_system::get_full_path(const string& relative_path) {
  char full_path[MAX_PATH + 1];
  return _fullpath(full_path, relative_path.c_str(), MAX_PATH) ? full_path : "";
}

bool file_system::is_path_too_long(const string& path) {
  return path.size() > MAX_PATH;
}

int32_t file_system::set_creation_time(const string &path, chrono::system_clock::time_point &creation_time) {
  return -1;
}

int32_t file_system::set_file_attributes(const string& path, int32_t attributes) {
  return -1;
}

int32_t file_system::set_last_access_time(const string &path, chrono::system_clock::time_point &last_access_time) {
  return -1;
}

int32_t file_system::set_last_write_time(const string &path, chrono::system_clock::time_point &last_write_time) {
  return -1;
}
