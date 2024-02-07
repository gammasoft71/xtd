#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file_system>
#include <xtd/native/file_attribute>
#include <xtd/native/file_permission>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <filesystem>
#include <Windows.h>

using namespace std;
using namespace xtd::native;

#undef max
#undef min

namespace {
  static FILETIME time_t_to_file_time(time_t time) {
    auto file_time = FILETIME {};
    auto time_value = ULARGE_INTEGER {};
    time_value.QuadPart = (time * 10000000LL) + 116444736000000000LL;
    file_time.dwLowDateTime = time_value.LowPart;
    file_time.dwHighDateTime = time_value.HighPart;
    return file_time;
  }
  
  static time_t file_time_to_time_t(FILETIME const& time) {
    auto time_value = ULARGE_INTEGER {};
    time_value.LowPart = time.dwLowDateTime;
    time_value.HighPart = time.dwHighDateTime;
    return (time_value.QuadPart - 116444736000000000LL) / 10000000LL;
  }
}

int_least32_t file_system::get_attributes(const string& path, int_least32_t& attributes) {
  auto attrib = GetFileAttributes(win32::strings::to_wstring(path).c_str());
  if (attrib != INVALID_FILE_ATTRIBUTES) attributes = static_cast<int_least32_t>(attrib);
  return attrib != INVALID_FILE_ATTRIBUTES ? 0 : -1;
}

int_least32_t file_system::get_file_times(const string& path, time_t& creation_time, time_t& last_access_time, time_t& last_write_time) {
  auto file_handle = CreateFile(win32::strings::to_wstring(path).c_str(), 0, 0, nullptr, OPEN_EXISTING, 0, nullptr);
  if (file_handle == INVALID_HANDLE_VALUE) file_handle = CreateFile(win32::strings::to_wstring(path).c_str(), 0, 0, nullptr, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, nullptr);
  if (file_handle == INVALID_HANDLE_VALUE) return 1;
  
  auto creation_time_file_time = time_t_to_file_time(creation_time);
  auto last_access_time_file_time = time_t_to_file_time(last_access_time);
  auto last_write_time_time = time_t_to_file_time(last_write_time);
  auto result = GetFileTime(file_handle, &creation_time_file_time, &last_access_time_file_time, &last_write_time_time);
  CloseHandle(file_handle);
  
  creation_time = file_time_to_time_t(creation_time_file_time);
  last_access_time = file_time_to_time_t(last_access_time_file_time);
  last_write_time = file_time_to_time_t(last_write_time_time);
  
  return result == TRUE ? 0 : 2;
}

string file_system::get_full_path(const string& relative_path) {
  auto full_path = std::wstring(32767, '\0');
  if (GetFullPathName(win32::strings::to_wstring(relative_path).c_str(), static_cast<DWORD>(full_path.size()), full_path.data(), nullptr) == 0) return relative_path;
  return win32::strings::to_string(full_path);
}

int_least32_t file_system::get_permissions(const std::string& path, int_least32_t& permissions) {
  struct system_permission_to_file_permission_converter {
    int operator()(std::filesystem::perms permission) {
      auto file_permissions = 0;
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

int_least32_t file_system::set_attributes(const std::string& path, int_least32_t attributes) {
  return SetFileAttributes(win32::strings::to_wstring(path).c_str(), attributes) == TRUE ? 0 : -1;
}

int_least32_t file_system::set_creation_time(const string& path, time_t creation_time) {
  auto file_handle = CreateFile(win32::strings::to_wstring(path).c_str(), 0, 0, nullptr, OPEN_EXISTING, 0, nullptr);
  if (file_handle == INVALID_HANDLE_VALUE) file_handle = CreateFile(win32::strings::to_wstring(path).c_str(), 0, 0, nullptr, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, nullptr);
  if (file_handle == INVALID_HANDLE_VALUE) return 1;
  auto creation_time_file_time = FILETIME{};
  auto last_access_time_file_time = FILETIME {};
  auto last_write_time_file_time = FILETIME {};
  auto result = GetFileTime(file_handle, &creation_time_file_time, &last_access_time_file_time, &last_write_time_file_time);
  creation_time_file_time = time_t_to_file_time(creation_time);
  if (result == TRUE) result = SetFileTime(file_handle, &creation_time_file_time, &last_access_time_file_time, &last_write_time_file_time);
  CloseHandle(file_handle);
  return result == TRUE ? 0 : 2;
}

int_least32_t file_system::set_last_access_time(const string& path, time_t last_access_time) {
  HANDLE file_handle = CreateFile(win32::strings::to_wstring(path).c_str(), 0, 0, nullptr, OPEN_EXISTING, 0, nullptr);
  if (file_handle == INVALID_HANDLE_VALUE) file_handle = CreateFile(win32::strings::to_wstring(path).c_str(), 0, 0, nullptr, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, nullptr);
  if (file_handle == 0) return 1;
  auto creation_time_file_time = FILETIME{};
  auto last_access_time_file_time = FILETIME{};
  auto last_write_time_file_time = FILETIME{};
  auto result = GetFileTime(file_handle, &creation_time_file_time, &last_access_time_file_time, &last_write_time_file_time);
  last_write_time_file_time = time_t_to_file_time(last_access_time);
  if (result == TRUE) result = SetFileTime(file_handle, &creation_time_file_time, &last_access_time_file_time, &last_write_time_file_time);
  CloseHandle(file_handle);
  return result == TRUE ? 0 : 2;
}

int_least32_t file_system::set_last_write_time(const string& path, time_t last_write_time) {
  HANDLE file_handle = CreateFile(win32::strings::to_wstring(path).c_str(), 0, 0, nullptr, OPEN_EXISTING, 0, nullptr);
  if (file_handle == INVALID_HANDLE_VALUE) file_handle = CreateFile(win32::strings::to_wstring(path).c_str(), 0, 0, nullptr, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, nullptr);
  if (file_handle == 0) return 1;
  auto creation_time_file_time = FILETIME{};
  auto last_access_time_file_time = FILETIME{};
  auto last_write_time_file_time = FILETIME{};
  auto result = GetFileTime(file_handle, &creation_time_file_time, &last_access_time_file_time, &last_write_time_file_time);
  last_write_time_file_time = time_t_to_file_time(last_write_time);
  if (result == TRUE) result = SetFileTime(file_handle, &creation_time_file_time, &last_access_time_file_time, &last_write_time_file_time);
  CloseHandle(file_handle);
  return result == TRUE ? 0 : 2;
}

int_least32_t file_system::set_permissions(const std::string& path, int_least32_t permissions) {
  struct file_permission_to_system_permission_converter {
    std::filesystem::perms operator()(int_least32_t permission) {
      auto system_permissions = std::filesystem::perms::none;
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
  } catch (...) {
    return -1;
  }
  return 0;
}
