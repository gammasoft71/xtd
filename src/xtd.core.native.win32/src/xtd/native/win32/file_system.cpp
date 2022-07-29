#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file_system.h>
#include <xtd/native/file_attribute.h>
#include <xtd/native/file_permission.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <filesystem>
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

int32_t file_system::get_file_times(const string& path, time_t& creation_time, time_t& last_access_time, time_t& last_write_time) {
  /// @todo Use GetFileTime : https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfiletime
  struct stat file_stat;
  if (stat(path.c_str(), &file_stat) != 0)
    return -1;
  creation_time = static_cast<time_t>(file_stat.st_ctime);
  last_access_time = static_cast<time_t>(file_stat.st_atime);
  last_write_time = static_cast<time_t>(file_stat.st_mtime);
  return 0;
}

string file_system::get_full_path(const string& relative_path) {
  /// @todo Use GetFullPathName : https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfullpathnamea
  char full_path[MAX_PATH + 1];
  return _fullpath(full_path, relative_path.c_str(), MAX_PATH) ? full_path : "";
}

int32_t file_system::get_permissions(const std::string& path, int32_t& permissions) {
  struct system_permission_to_file_permission_converter {
    int32_t operator()(std::filesystem::perms permission) {
      int32_t file_permissions = 0;
      if ((permission & std::filesystem::perms::owner_read) == std::filesystem::perms::owner_read) file_permissions |= FILE_PERMISSIONS_OWNER_READ;
      if ((permission & std::filesystem::perms::owner_write) == std::filesystem::perms::owner_write) file_permissions |= FILE_PERMISSIONS_OWNER_WRITE;
      if ((permission & std::filesystem::perms::owner_exec) == std::filesystem::perms::owner_exec) file_permissions |= FILE_PERMISSIONS_OWNER_EXECUTE;
      
      if ((permission & std::filesystem::perms::group_read) == std::filesystem::perms::group_read) file_permissions |= FILE_PERMISSIONS_GROUP_READ;
      if ((permission & std::filesystem::perms::group_write) == std::filesystem::perms::group_write) file_permissions |= FILE_PERMISSIONS_GROUP_WRITE;
      if ((permission & std::filesystem::perms::group_exec) == std::filesystem::perms::group_exec) file_permissions |= FILE_PERMISSIONS_GROUP_EXECUTE;
      
      if ((permission & std::filesystem::perms::others_read) == std::filesystem::perms::others_read) file_permissions |= FILE_PERMISSIONS_OTHERS_READ;
      if ((permission & std::filesystem::perms::others_write) == std::filesystem::perms::others_write) file_permissions |= FILE_PERMISSIONS_OTHERS_WRITE;
      if ((permission & std::filesystem::perms::others_exec) == std::filesystem::perms::others_exec) file_permissions |= FILE_PERMISSIONS_OTHERS_EXECUTE;
      
      if ((permission & std::filesystem::perms::set_uid) == std::filesystem::perms::set_uid) file_permissions |= FILE_PERMISSIONS_SET_UID;
      if ((permission & std::filesystem::perms::set_gid) == std::filesystem::perms::set_gid) file_permissions |= FILE_PERMISSIONS_SET_GID;
      if ((permission & std::filesystem::perms::sticky_bit) == std::filesystem::perms::sticky_bit) file_permissions |= FILE_PERMISSIONS_STICKY_BIT;
      
      if (file_permissions == 0) file_permissions = FILE_PERMISSIONS_UNKNOWN;
      
      return file_permissions;
    }
  };
  
  return system_permission_to_file_permission_converter()(std::filesystem::status(std::filesystem::path(path)).permissions());
}

bool file_system::is_path_too_long(const string& path) {
  return path.size() > MAX_PATH;
}

int32_t file_system::set_attributes(const std::string& path, int32_t attributes) {
  /// @todo SetFileAttributes : https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfileattributesa
  return -1;
}

int32_t file_system::set_creation_time(const string& path, time_t creation_time) {
  /// @todo SetFileTime : https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfiletime
  return -1;
}

int32_t file_system::set_last_access_time(const string& path, time_t last_access_time) {
  /// @todo SetFileTime : https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfiletime
  return -1;
}

int32_t file_system::set_last_write_time(const string& path, time_t last_write_time) {
  /// @todo SetFileTime : https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfiletime
  return -1;
}

int32_t file_system::set_permissions(const std::string& path, int32_t permissions) {
  struct file_permission_to_system_permission_converter {
    std::filesystem::perms operator()(int32_t permission) {
      std::filesystem::perms system_permissions = std::filesystem::perms::none;
      if ((permission & FILE_PERMISSIONS_OWNER_READ) == FILE_PERMISSIONS_OWNER_READ) system_permissions |= std::filesystem::perms::owner_read;
      if ((permission & FILE_PERMISSIONS_OWNER_WRITE) == FILE_PERMISSIONS_OWNER_WRITE) system_permissions |= std::filesystem::perms::owner_write;
      if ((permission & FILE_PERMISSIONS_OWNER_EXECUTE) == FILE_PERMISSIONS_OWNER_EXECUTE) system_permissions |= std::filesystem::perms::owner_exec;
      
      if ((permission & FILE_PERMISSIONS_GROUP_READ) == FILE_PERMISSIONS_GROUP_READ) system_permissions |= std::filesystem::perms::group_read;
      if ((permission & FILE_PERMISSIONS_GROUP_WRITE) == FILE_PERMISSIONS_GROUP_WRITE) system_permissions |= std::filesystem::perms::group_write;
      if ((permission & FILE_PERMISSIONS_GROUP_EXECUTE) == FILE_PERMISSIONS_GROUP_EXECUTE) system_permissions |= std::filesystem::perms::group_exec;
      
      if ((permission & FILE_PERMISSIONS_OTHERS_READ) == FILE_PERMISSIONS_OTHERS_READ) system_permissions |= std::filesystem::perms::others_read;
      if ((permission & FILE_PERMISSIONS_OTHERS_WRITE) == FILE_PERMISSIONS_OTHERS_WRITE) system_permissions |= std::filesystem::perms::others_write;
      if ((permission & FILE_PERMISSIONS_OTHERS_EXECUTE) == FILE_PERMISSIONS_OTHERS_EXECUTE) system_permissions |= std::filesystem::perms::others_exec;
      
      if ((permission & FILE_PERMISSIONS_SET_UID) == FILE_PERMISSIONS_SET_UID) system_permissions |= std::filesystem::perms::set_uid;
      if ((permission & FILE_PERMISSIONS_SET_GID) == FILE_PERMISSIONS_SET_GID) system_permissions |= std::filesystem::perms::set_gid;
      if ((permission & FILE_PERMISSIONS_STICKY_BIT) == FILE_PERMISSIONS_STICKY_BIT) system_permissions |= std::filesystem::perms::sticky_bit;
      
      if (system_permissions == std::filesystem::perms::none) system_permissions = std::filesystem::perms::unknown;
      
      return system_permissions;
    }
  };
  
  try {
    std::filesystem::permissions(std::filesystem::path(path), file_permission_to_system_permission_converter()(permissions));
  } catch(...) {
    return -1;
  }
  return 0;
}
