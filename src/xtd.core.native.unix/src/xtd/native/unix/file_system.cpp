#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file_system.h>
#include <xtd/native/directory.h>
#include <xtd/native/file_attribute.h>
#include <xtd/native/path.h>
#include "../../../../include/xtd/native/unix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#if !__APPLE__
#include <linux/limits.h>
#endif

using namespace std;
using namespace xtd::native;

int32_t file_system::get_attributes(const std::string& path, int32_t& attributes) {
  struct system_attribute_to_file_attribute_converter {
    int32_t operator()(int32_t attribute) {
      int32_t file_attributes = 0;
      if ((attribute & S_IRUSR) == S_IRUSR && (attribute & S_IWUSR) == 0) file_attributes |= FILE_ATTRIBUTE_READONLY;
      if ((attribute & S_IFSOCK) == S_IFSOCK || (attribute & S_IFIFO) == S_IFIFO) file_attributes |= FILE_ATTRIBUTE_SYSTEM;
      if ((attribute & S_IFDIR) == S_IFDIR) file_attributes |= FILE_ATTRIBUTE_DIRECTORY;
      if ((attribute & S_IFREG) == S_IFREG) file_attributes |= FILE_ATTRIBUTE_ARCHIVE;
      if ((attribute & S_IFBLK) == S_IFBLK || (attribute & S_IFCHR) == S_IFCHR) file_attributes |= FILE_ATTRIBUTE_DEVICE;
      if ((attribute & S_IFREG) == S_IFREG) file_attributes |= FILE_ATTRIBUTE_NORMAL;
      return file_attributes;
    }
  };
  struct stat status;
  int32_t ret_value = stat(path.c_str(), &status);
  attributes = system_attribute_to_file_attribute_converter()(status.st_mode);
  return ret_value;
}

#if !__APPLE__
int32_t file_system::get_file_times(const std::string& path, std::chrono::system_clock::time_point& creation_time, std::chrono::system_clock::time_point& last_access_time, std::chrono::system_clock::time_point& last_write_time) {
  struct stat status;
  if (stat(path.c_str(), &status) != 0) return -1;
  
  creation_time = std::chrono::system_clock::from_time_t(static_cast<time_t>(status.st_ctime));
  last_access_time = std::chrono::system_clock::from_time_t(static_cast<time_t>(status.st_atime));
  last_write_time = std::chrono::system_clock::from_time_t(static_cast<time_t>(status.st_mtime));
  return 0;
}
#endif

string file_system::get_full_path(const string& relative_path) {
  vector<string> directories = native::unix::strings::split(relative_path, {path::directory_separator_char()}, std::numeric_limits<size_t>::max(), true);
  string full_path;
  
  if (relative_path[0] != path::directory_separator_char())
    full_path = directory::get_current_directory();
  
  for (string& item : directories) {
    if (item == ".." && native::unix::strings::last_index_of(full_path, path::directory_separator_char()) != full_path.npos)
      full_path = native::unix::strings::remove(full_path, native::unix::strings::last_index_of(full_path, path::directory_separator_char()));
    else if (item != ".")
      full_path += path::directory_separator_char() + item;
  }
  
  if (relative_path[relative_path.size() - 1] == path::directory_separator_char())
    full_path += path::directory_separator_char();
  
  return full_path;
}

bool file_system::is_path_too_long(const std::string& path) {
  if (path.size() > PATH_MAX) return true;

  size_t index = path.rfind(native::path::directory_separator_char());
  if (index == static_cast<size_t>(-1)) index = path.rfind(native::path::alt_directory_separator_char());
  auto file_name =  (index == static_cast<size_t>(-1)) ? path : &path[index + 1];
  return file_name.size() > NAME_MAX;
}

int32_t file_system::set_creation_time(const std::string &path, std::chrono::system_clock::time_point &creation_time) {
  return -1;
}

int32_t file_system::set_file_attributes(const std::string& path, int32_t attributes) {
  return -1;
}

int32_t file_system::set_last_access_time(const std::string &path, std::chrono::system_clock::time_point &last_access_time) {
  return -1;
}

int32_t file_system::set_last_write_time(const std::string &path, std::chrono::system_clock::time_point &last_write_time) {
  return -1;
}
