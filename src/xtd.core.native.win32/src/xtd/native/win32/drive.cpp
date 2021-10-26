#define _CRT_SECURE_NO_WARNINGS

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/drive.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <string>
#include <direct.h>
#include <Windows.h>

#undef max
#undef min

using namespace std;
using namespace xtd::native;

bool drive::get_available_free_space(const std::string& root_path_name, size_t& free_bytes, size_t& total_number_of_bytes, size_t& total_number_of_free_bytes) {
  return GetDiskFreeSpaceEx(root_path_name.c_str(), reinterpret_cast<PULARGE_INTEGER>(&free_bytes), reinterpret_cast<PULARGE_INTEGER>(&total_number_of_bytes), reinterpret_cast<PULARGE_INTEGER>(&total_number_of_free_bytes)) != FALSE;
}

int32_t drive::get_drive_type(const std::string& root_path_name) {
  return GetDriveType(root_path_name.c_str());
}

std::vector<std::string> drive::get_drives() {
  char buffer[MAX_PATH + 1];
  int32_t buffer_lenght = MAX_PATH;
  if (::GetLogicalDriveStringsA(buffer_lenght, buffer) <= 0)
    return {};
  vector<string> drives;
  for (const char* drive = buffer; drive[0] != 0; drive += strlen(drive) + 1)
    drives.push_back(drive);
  return drives;
}

bool drive::get_volume_information(const std::string& root_path_name, std::string& volume_name, std::string& file_system_name) {
  DWORD file_system_flags = 0;
  char volume[MAX_PATH+1];
  char file_system[MAX_PATH+1];
  if (GetVolumeInformation(root_path_name.c_str(), volume, MAX_PATH, nullptr, nullptr, &file_system_flags, file_system, MAX_PATH) == FALSE)
    return false;

  volume_name = volume;
  file_system_name = file_system;

  return true;
}

bool drive::set_Volume_label(const std::string& root_path_name, const std::string& volume_name) {
  return SetVolumeLabel(root_path_name.c_str(), volume_name.c_str()) > 0;
}
