#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory.h>
#include <xtd/native/drive.h>
#include <xtd/native/drive_type.h>
#include <xtd/native/file_system.h>
#include "../../../../include/xtd/native/unix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <map>
#if defined(__APPLE__)
#include <sys/mount.h>
#else
#include <sys/statfs.h>
#endif
#include <sys/statvfs.h>

using namespace std;
using namespace xtd::native;

namespace {
  string root_drive = {"/"};
#if defined(__APPLE__)
  vector<string> ram_drives = {"/dev"};
  vector<string> amovible_mounteds = {};
  vector<string> amovible_mounted_points {"/System/Volumes"};
  vector<string> network_drives = {"/System/Volumes/Data/home"};
  vector<string> network_drive_points = {"/Volumes"};
#else
  vector<string> ram_drives = {"/run/vmblock-fuse", "/run/user/1000/gvfs"};
  vector<string> amovible_mounteds = {};
  vector<string> amovible_mounted_points {string("/media/") + [] (const std::string& variable)->string {auto value = getenv(variable.c_str()); return value ? value : "";}("USER")};
  vector<string> network_drives = {"/net", "/home", "/Network/Servers"};
  vector<string> network_drive_points = {};
#endif
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

int32_t drive::get_drive_type(const std::string& root_path_name) {
  if (root_drive == root_path_name) return DRIVE_FIXED;
  if (find(ram_drives.begin(), ram_drives.end(), root_path_name) != ram_drives.end()) return DRIVE_RAMDISK;
  if (find(network_drives.begin(), network_drives.end(), root_path_name) != network_drives.end()) return DRIVE_REMOTE;
  for (auto network_drive : network_drive_points)
    if (root_path_name.find(network_drive) == 0) {
#if defined(__APPLE__)
      struct statfs stat;
      if (statfs(root_path_name.c_str(), &stat) == 0 && (stat.f_flags & ST_RDONLY) == ST_RDONLY) return DRIVE_CDROM;
      return DRIVE_REMOTE;
#else
      return DRIVE_REMOTE;
#endif
    }
  for (auto amovible_mounted_point : amovible_mounted_points)
    if (root_path_name.find(amovible_mounted_point) == 0) {
#if defined(__APPLE__)
      struct statfs stat;
      if (statfs(root_path_name.c_str(), &stat) == 0 && (stat.f_flags & ST_RDONLY) == ST_RDONLY) return DRIVE_CDROM;
      return DRIVE_FIXED;
#else
      return DRIVE_CDROM;
#endif
    }
  return DRIVE_FIXED;
}

std::vector<std::string> drive::get_drives() {
  vector<string> drives;
  drives.push_back(root_drive);
  drives.insert(drives.end(), ram_drives.begin(), ram_drives.end());

  drives.insert(drives.end(), amovible_mounteds.begin(), amovible_mounteds.end());

  int32_t file_attributes = 0;
  for (auto amovible_mounted_point : amovible_mounted_points) {
    if ((file_system::get_attributes(amovible_mounted_point, file_attributes) == 0 && (file_attributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)) {
      for (string drive : directory::enumerate_directories(amovible_mounted_point, "*")) {
        struct statfs stat;
  #if defined(__APPLE__)
        string mntonname = stat.f_mntonname;
        if (statfs(drive.c_str(), &stat) == 0 && string(stat.f_mntonname) != root_drive)
  #else
        if (statfs(drive.c_str(), &stat) == 0)
  #endif
          drives.push_back(drive);
      }
    }
  }
  
  drives.insert(drives.end(), network_drives.begin(), network_drives.end());
  
  for (auto network_drive : network_drive_points) {
    if ((file_system::get_attributes(network_drive, file_attributes) == 0 && (file_attributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)) {
      for (string drive : directory::enumerate_directories(network_drive, "*")) {
        struct statfs stat;
#if defined(__APPLE__)
        if (statfs(drive.c_str(), &stat) == 0 && string(stat.f_mntonname) != root_drive  && !unix::strings::ends_with(drive, ".timemachine")  && !unix::strings::ends_with(drive, ".localsnapshots"))
#else
          if (statfs(drive.c_str(), &stat) == 0)
#endif
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
#if defined(__APPLE__)
  file_system_name = stat.f_fstypename;
#else
  static map<uint32_t, string> file_system_names = {{0x0000adf5, "adfs"}, {0x0000adff, "adfs"}, {0x42465331, "befs"}, {0x1BADFACE, "bfs"}, {0xFF534D42, "cifs"}, {0x73757245, "coda"}, {0x012FF7B7, "coh"}, {0x28cd3d45, "cramfs"}, {0x00001373, "devfs"}, {0x00414A53, "efs"}, {0x0000137D, "ext"}, {0x0000EF51, "ext2"}, {0x0000EF52, "ext3"}, {0x0000EF53, "ext4"}, {0x00004244, "hfs"}, {0xF995E849, "hpfs"}, {0x958458f6, "hgfs"}, {0x00009660, "isofs"}, {0x000072b6, "jffs2"}, {0x3153464a, "jfs"}, {0x0000137F, "minix"}, {0x0000138F, "minix"}, {0x00002468, "minix2"}, {0x00002478, "minix2"}, {0x00004d44, "fat32"}, {0x0000564c, "ncp"}, {0x00006969, "nfs"}, {0x5346544e, "ntfs"}, {0x00009fa1, "openprom"}, {0x00009fa0, "proc"}, {0x0000002f, "qnx4"}, {0x52654973, "reiserfs"}, {0x00007275, "romfs"}, {0x0000517B, "smb"}, {0x012FF7B6, "sysv2"}, {0x012FF7B5, "sysv4"}, {0x01021994, "tmpfs"}, {0x15013346, "udf"}, {0x00011954, "ufs"}, {0x00009fa2, "usb device"}, {0xa501FCF5, "vxfs"}, {0x012FF7B4, "xenix"}, {0x58465342, "xfs"}, {0x012FD16D, "_xiafs"}};
  auto it = file_system_names.find(stat.f_type);
  file_system_name = it == file_system_names.end() ? "unknown" : it->second;
#endif
  return true;
}

bool drive::set_Volume_label(const std::string& root_path_name, const std::string& volume_name) {
  // There is no API to change the volume label on macOS and linux.
  return false;
}
