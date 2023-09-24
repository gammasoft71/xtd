#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file_system>
#include <xtd/native/directory>
#include <xtd/native/file_attribute>
#include <xtd/native/file_permission>
#include <xtd/native/path>
#include "../../../../include/xtd/native/macos/strings"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <utime.h>
#import <Foundation/Foundation.h>

using namespace std;
using namespace xtd::native;

int_least32_t file_system::get_attributes(const std::string& path, int_least32_t& attributes) {
  struct system_attribute_to_file_attribute_converter {
    int_least32_t operator()(int_least32_t attribute) {
      auto file_attributes = 0;
      if ((attribute & S_IRUSR) == S_IRUSR && (attribute & S_IWUSR) != S_IWUSR) file_attributes |= FILE_ATTRIBUTE_READONLY;
      if ((attribute & S_IFSOCK) == S_IFSOCK || (attribute & S_IFIFO) == S_IFIFO) file_attributes |= FILE_ATTRIBUTE_SYSTEM;
      if ((attribute & S_IFDIR) == S_IFDIR) file_attributes |= FILE_ATTRIBUTE_DIRECTORY;
      if ((attribute & S_IFREG) == S_IFREG) file_attributes |= FILE_ATTRIBUTE_ARCHIVE;
      if ((attribute & S_IFBLK) == S_IFBLK || (attribute & S_IFCHR) == S_IFCHR) file_attributes |= FILE_ATTRIBUTE_DEVICE;
      if ((attribute & S_IFREG) == S_IFREG) file_attributes |= FILE_ATTRIBUTE_NORMAL;
      return file_attributes;
    }
  };
  struct stat status;
  if (stat(path.c_str(), &status) != 0) return -1;
  attributes = system_attribute_to_file_attribute_converter()(status.st_mode);
  return 0;
}

int_least32_t file_system::get_file_times(const std::string& path, time_t& creation_time, time_t& last_access_time, time_t& last_write_time) {
  NSFileManager* fm = [NSFileManager defaultManager];
  creation_time = [[[fm attributesOfItemAtPath:[NSString stringWithUTF8String:path.c_str()] error:Nil] fileCreationDate] timeIntervalSince1970];
  last_access_time = [[[fm attributesOfItemAtPath:[NSString stringWithUTF8String:path.c_str()] error:Nil] fileModificationDate] timeIntervalSince1970];
  last_write_time = [[[fm attributesOfItemAtPath:[NSString stringWithUTF8String:path.c_str()] error:Nil] fileModificationDate] timeIntervalSince1970];
  return 0;
}

string file_system::get_full_path(const string& relative_path) {
  auto directories = native::macos::strings::split(relative_path, {path::directory_separator_char()}, std::numeric_limits<size_t>::max(), true);
  auto full_path = string {};
  
  if (relative_path[0] != path::directory_separator_char())
    full_path = directory::get_current_directory();
    
  for (const auto& item : directories) {
    if (item == ".." && native::macos::strings::last_index_of(full_path, path::directory_separator_char()) != full_path.npos)
      full_path = native::macos::strings::remove(full_path, native::macos::strings::last_index_of(full_path, path::directory_separator_char()));
    else if (item != ".")
      full_path += path::directory_separator_char() + item;
  }
  
  if (relative_path[relative_path.size() - 1] == path::directory_separator_char())
    full_path += path::directory_separator_char();
    
  auto index = native::macos::strings::last_index_of(full_path, "/./");
  while (index != full_path.npos) {
    full_path = native::macos::strings::remove(full_path, index, 2);
    index = native::macos::strings::last_index_of(full_path, "/./");
  }
  
  return full_path;
}

int_least32_t file_system::get_permissions(const std::string& path, int_least32_t& permissions) {
  struct system_permission_to_file_permission_converter {
    int_least32_t operator()(mode_t permission) {
      auto file_permissions = 0;
      if ((permission & S_IRUSR) == S_IRUSR) file_permissions |= FILE_PERMISSIONS_OWNER_READ;
      if ((permission & S_IWUSR) == S_IWUSR) file_permissions |= FILE_PERMISSIONS_OWNER_WRITE;
      if ((permission & S_IXUSR) == S_IXUSR) file_permissions |= FILE_PERMISSIONS_OWNER_EXECUTE;
      
      if ((permission & S_IRGRP) == S_IRGRP) file_permissions |= FILE_PERMISSIONS_GROUP_READ;
      if ((permission & S_IXGRP) == S_IXGRP) file_permissions |= FILE_PERMISSIONS_GROUP_WRITE;
      if ((permission & S_IXGRP) == S_IXGRP) file_permissions |= FILE_PERMISSIONS_GROUP_EXECUTE;
      
      if ((permission & S_IROTH) == S_IROTH) file_permissions |= FILE_PERMISSIONS_OTHERS_READ;
      if ((permission & S_IWOTH) == S_IWOTH) file_permissions |= FILE_PERMISSIONS_OTHERS_WRITE;
      if ((permission & S_IXOTH) == S_IXOTH) file_permissions |= FILE_PERMISSIONS_OTHERS_EXECUTE;
      
      if ((permission & S_ISUID) == S_ISUID) file_permissions |= FILE_PERMISSIONS_SET_UID;
      if ((permission & S_ISGID) == S_ISGID) file_permissions |= FILE_PERMISSIONS_SET_GID;
      if ((permission & S_ISVTX) == S_ISVTX) file_permissions |= FILE_PERMISSIONS_STICKY_BIT;
      
      if (file_permissions == 0) file_permissions = FILE_PERMISSIONS_UNKNOWN;
      
      return file_permissions;
    }
  };
  struct stat s;
  auto ret_value = stat(path.c_str(), &s);
  permissions = system_permission_to_file_permission_converter()(s.st_mode);
  return ret_value;
}

bool file_system::is_path_too_long(const std::string& path) {
  if (path.size() > PATH_MAX) return true;
  
  auto index = path.rfind(native::path::directory_separator_char());
  if (index == static_cast<size_t>(-1)) index = path.rfind(native::path::alt_directory_separator_char());
  auto file_name = (index == static_cast<size_t>(-1)) ? path : &path[index + 1];
  return file_name.size() > NAME_MAX;
}

int_least32_t file_system::set_attributes(const std::string& path, int_least32_t attributes) {
  struct stat s;
  if (stat(path.c_str(), &s) != 0) return -1;
  
  if ((attributes & FILE_ATTRIBUTE_READONLY) != FILE_ATTRIBUTE_READONLY)
    s.st_mode |= S_IWUSR;
  else if ((attributes & FILE_ATTRIBUTE_READONLY) == FILE_ATTRIBUTE_READONLY)
    s.st_mode &= ~S_IWUSR;
    
  // The other attributes can be modified under linux.
  
  return chmod(path.c_str(), s.st_mode);
}

int_least32_t file_system::set_creation_time(const std::string& path, time_t creation_time) {
  // There is no creation time on linux so we update the last modification time instead...
  auto times = utimbuf {};
  time_t creation_time_old = 0, last_access_time = 0, last_write_time = 0;
  get_file_times(path, creation_time_old, last_access_time, last_write_time);
  times.actime = last_access_time;
  times.modtime = creation_time;
  return utime(path.c_str(), &times);
}

int_least32_t file_system::set_last_access_time(const std::string& path, time_t last_access_time) {
  auto times = utimbuf {};
  time_t creation_time = 0, last_access_time_old = 0, last_write_time = 0;
  get_file_times(path, creation_time, last_access_time_old, last_write_time);
  times.actime = last_access_time;
  times.modtime = last_write_time;
  return utime(path.c_str(), &times);
}

int_least32_t file_system::set_last_write_time(const std::string& path, time_t last_write_time) {
  auto times = utimbuf {};
  time_t creation_time = 0, last_access_time = 0, last_write_time_old = 0;
  get_file_times(path, creation_time, last_access_time, last_write_time_old);
  times.actime = last_access_time;
  times.modtime = last_write_time;
  return utime(path.c_str(), &times);
}

int_least32_t file_system::set_permissions(const std::string& path, int_least32_t permissions) {
  struct file_permission_to_system_permission_converter {
    mode_t operator()(int_least32_t permission) {
      auto system_permissions = 0;
      if ((permission & FILE_PERMISSIONS_OWNER_READ) == FILE_PERMISSIONS_OWNER_READ) system_permissions |= S_IRUSR;
      if ((permission & FILE_PERMISSIONS_OWNER_WRITE) == FILE_PERMISSIONS_OWNER_WRITE) system_permissions |= S_IWUSR;
      if ((permission & FILE_PERMISSIONS_OWNER_EXECUTE) == FILE_PERMISSIONS_OWNER_EXECUTE) system_permissions |= S_IXUSR;
      
      if ((permission & FILE_PERMISSIONS_GROUP_READ) == FILE_PERMISSIONS_GROUP_READ) system_permissions |= S_IRGRP;
      if ((permission & FILE_PERMISSIONS_GROUP_WRITE) == FILE_PERMISSIONS_GROUP_WRITE) system_permissions |= S_IWGRP;
      if ((permission & FILE_PERMISSIONS_GROUP_EXECUTE) == FILE_PERMISSIONS_GROUP_EXECUTE) system_permissions |= S_IXGRP;
      
      if ((permission & FILE_PERMISSIONS_OTHERS_READ) == FILE_PERMISSIONS_OTHERS_READ) system_permissions |= S_IROTH;
      if ((permission & FILE_PERMISSIONS_OTHERS_WRITE) == FILE_PERMISSIONS_OTHERS_WRITE) system_permissions |= S_IWOTH;
      if ((permission & FILE_PERMISSIONS_OTHERS_EXECUTE) == FILE_PERMISSIONS_OTHERS_EXECUTE) system_permissions |= S_IXOTH;
      
      if ((permission & FILE_PERMISSIONS_SET_UID) == FILE_PERMISSIONS_SET_UID) system_permissions |= S_ISUID;
      if ((permission & FILE_PERMISSIONS_SET_GID) == FILE_PERMISSIONS_SET_GID) system_permissions |= S_ISGID;
      if ((permission & FILE_PERMISSIONS_STICKY_BIT) == FILE_PERMISSIONS_STICKY_BIT) system_permissions |= S_ISVTX;
      
      return system_permissions;
    }
  };
  return chmod(path.c_str(), file_permission_to_system_permission_converter()(permissions)) == 0 ? 0 : -1;
}
