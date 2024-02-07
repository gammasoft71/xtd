#define UNICODE
#define _CRT_SECURE_NO_WARNINGS
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/drive>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <string>
#include <direct.h>
#include <Windows.h>

#undef max
#undef min

using namespace std;
using namespace xtd::native;

bool drive::get_available_free_space(const std::string& root_path_name, size_t& free_bytes, size_t& total_number_of_bytes, size_t& total_number_of_free_bytes) {
  return GetDiskFreeSpaceEx(win32::strings::to_wstring(root_path_name).c_str(), reinterpret_cast<PULARGE_INTEGER>(&free_bytes), reinterpret_cast<PULARGE_INTEGER>(&total_number_of_bytes), reinterpret_cast<PULARGE_INTEGER>(&total_number_of_free_bytes)) != FALSE;
}

int_least32_t drive::get_drive_type(const std::string& root_path_name) {
  return GetDriveType(win32::strings::to_wstring(root_path_name).c_str());
}

std::vector<std::string> drive::get_drives() {
  auto buffer = wstring(MAX_PATH, '\0');
  auto buffer_lenght = static_cast<int>(buffer.size());
  if (::GetLogicalDriveStrings(buffer_lenght, buffer.data()) <= 0)
    return {};
  auto drives = vector<string> {};
  for (auto drive = buffer.data(); drive[0] != 0; drive += wcslen(drive) + 1)
    drives.push_back(win32::strings::to_string(drive));
  return drives;
}

bool drive::get_volume_information(const std::string& root_path_name, std::string& volume_name, std::string& file_system_name) {
  auto file_system_flags = DWORD {};
  auto volume = wstring(MAX_PATH, '\0');
  auto file_system = wstring(MAX_PATH, '\0');
  if (GetVolumeInformation(win32::strings::to_wstring(root_path_name).c_str(), volume.data(), MAX_PATH, nullptr, nullptr, &file_system_flags, file_system.data(), MAX_PATH) == FALSE)
    return false;
    
  volume_name = win32::strings::to_string(volume);
  file_system_name = win32::strings::to_string(file_system);
  
  return true;
}

bool drive::set_Volume_label(const std::string& root_path_name, const std::string& volume_name) {
  return SetVolumeLabel(win32::strings::to_wstring(root_path_name).c_str(), win32::strings::to_wstring(volume_name).c_str()) > 0;
}
