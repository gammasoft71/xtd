#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory>
#include <xtd/native/drive>
#include <xtd/native/drive_type>
#include <xtd/native/file_system>
#include "../../../../include/xtd/native/macos/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <map>
#include <sys/mount.h>
#include <sys/statvfs.h>

using namespace std;
using namespace xtd::native;

namespace {
  auto root_drive = string {"/"};
  auto ram_drives = vector<string> {"/dev"};
  auto amovible_mounteds = vector<string> {};
  auto amovible_mounted_points = vector<string> {"/System/Volumes"};
  auto network_drives = vector<string> {"/System/Volumes/Data/home"};
  auto network_drive_points = vector<string> {"/Volumes"};
}

bool drive::get_available_free_space(const std::string& root_path_name, size_t& free_bytes, size_t& total_number_of_bytes, size_t& total_number_of_free_bytes) {
  struct statfs stat;
  if (::statfs(root_path_name.c_str(), &stat) != 0) return false;
  
  free_bytes = static_cast<size_t>(stat.f_bavail * stat.f_bsize);
  total_number_of_bytes = static_cast<size_t>(stat.f_blocks * stat.f_bsize);
  //total_number_of_free_bytes = static_cast<size_t>((stat.f_flags & ST_RDONLY) == ST_RDONLY ? 0 : stat.f_bfree * stat.f_bsize);
  total_number_of_free_bytes = static_cast<size_t>(stat.f_bfree * stat.f_bsize);
  return true;
}

int_least32_t drive::get_drive_type(const std::string& root_path_name) {
  if (root_drive == root_path_name) return DRIVE_FIXED;
  if (find(ram_drives.begin(), ram_drives.end(), root_path_name) != ram_drives.end()) return DRIVE_RAMDISK;
  if (find(network_drives.begin(), network_drives.end(), root_path_name) != network_drives.end()) return DRIVE_REMOTE;
  for (auto network_drive : network_drive_points)
    if (root_path_name.find(network_drive) == 0) {
      struct statfs stat;
      if (statfs(root_path_name.c_str(), &stat) == 0 && (stat.f_flags & ST_RDONLY) == ST_RDONLY) return DRIVE_CDROM;
      return DRIVE_REMOTE;
    }
  for (auto amovible_mounted_point : amovible_mounted_points)
    if (root_path_name.find(amovible_mounted_point) == 0) {
      struct statfs stat;
      if (statfs(root_path_name.c_str(), &stat) == 0 && (stat.f_flags & ST_RDONLY) == ST_RDONLY) return DRIVE_CDROM;
      return DRIVE_FIXED;
    }
  return DRIVE_FIXED;
}

std::vector<std::string> drive::get_drives() {
  auto drives = vector<string> {};
  drives.push_back(root_drive);
  drives.insert(drives.end(), ram_drives.begin(), ram_drives.end());
  
  drives.insert(drives.end(), amovible_mounteds.begin(), amovible_mounteds.end());
  
  auto file_attributes = 0;
  for (auto amovible_mounted_point : amovible_mounted_points) {
    if ((file_system::get_attributes(amovible_mounted_point, file_attributes) == 0 && (file_attributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)) {
      for (string drive : directory::enumerate_directories(amovible_mounted_point, "*")) {
        struct statfs stat;
        if (statfs(drive.c_str(), &stat) == 0 && string(stat.f_mntonname) != root_drive)
          drives.push_back(drive);
      }
    }
  }
  
  drives.insert(drives.end(), network_drives.begin(), network_drives.end());
  
  for (auto network_drive : network_drive_points) {
    if ((file_system::get_attributes(network_drive, file_attributes) == 0 && (file_attributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)) {
      for (auto drive : directory::enumerate_directories(network_drive, "*")) {
        struct statfs stat;
        if (statfs(drive.c_str(), &stat) == 0 && string(stat.f_mntonname) != root_drive  && !macos::strings::ends_with(drive, ".timemachine")  && !macos::strings::ends_with(drive, ".localsnapshots"))
          drives.push_back(drive);
      }
    }
  }
  return drives;
}

bool drive::get_volume_information(const std::string& root_path_name, std::string& volume_name, std::string& file_system_name) {
  struct statfs stat;
  if (statfs(root_path_name.c_str(), &stat) != 0)
    return false;
    
  volume_name = root_path_name;
  file_system_name = stat.f_fstypename;
  return true;
}

bool drive::set_Volume_label(const std::string& root_path_name, const std::string& volume_name) {
  // There is no API to change the volume label on macOS and linux.
  return false;
}
