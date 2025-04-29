#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/directory>
#include <xtd/native/drive>
#include <xtd/native/drive_type>
#include <xtd/native/file_system>
#include "../../../../include/xtd/native/linux/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <map>
#include <sys/statvfs.h>
#if defined(__HAIKU__)
int statfs(const char* path, struct statvfs* buf) {
  return ::statvfs(peth, buf);
}
#else
#include <sys/statfs.h>
#endif

using namespace std;
using namespace xtd::native;

namespace {
#if defined(__HAIKU__)
  using struct_statfs = struct statvfs;
#else
  using struct_statfs = struct statfs;
#endif
  auto root_drive = string {"/"};
  auto ram_drives = vector<string> {"/run/vmblock-fuse", "/run/user/1000/gvfs"};
  auto amovible_mounteds = vector<string> {};
  auto amovible_mounted_points = vector<string> {string("/media/") + [](const std::string & variable)->string {auto value = getenv(variable.c_str()); return value ? value : "";}("USER")};
  auto network_drives = vector<string> {"/net", "/home", "/Network/Servers"};
  auto network_drive_points = vector<string> {};
}

bool drive::get_available_free_space(const std::string& root_path_name, size_t& free_bytes, size_t& total_number_of_bytes, size_t& total_number_of_free_bytes) {
  auto stat = struct_statfs {};
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
    if (root_path_name.find(network_drive) == 0)
      return DRIVE_REMOTE;
  for (auto amovible_mounted_point : amovible_mounted_points)
    if (root_path_name.find(amovible_mounted_point) == 0)
      return DRIVE_CDROM;
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
      for (auto drive : directory::enumerate_directories(amovible_mounted_point, "*")) {
        auto stat = struct_statfs {};
        if (statfs(drive.c_str(), &stat) == 0)
          drives.push_back(drive);
      }
    }
  }

  drives.insert(drives.end(), network_drives.begin(), network_drives.end());

  for (auto network_drive : network_drive_points) {
    if ((file_system::get_attributes(network_drive, file_attributes) == 0 && (file_attributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)) {
      for (auto drive : directory::enumerate_directories(network_drive, "*")) {
        auto stat = struct_statfs {};
        if (statfs(drive.c_str(), &stat) == 0)
          drives.push_back(drive);
      }
    }
  }
  return drives;
}

bool drive::get_volume_information(const std::string& root_path_name, std::string& volume_name, std::string& file_system_name) {
  auto stat = struct_statfs {};
  if (statfs(root_path_name.c_str(), &stat) != 0)
    return false;

  volume_name = root_path_name;
#if defined(__HAIKU__)
  file_system_name = "unknown";
#else
  static auto file_system_names = map<uint32_t, string> {{0x0000adf5, "adfs"}, {0x0000adff, "adfs"}, {0x42465331, "befs"}, {0x1BADFACE, "bfs"}, {0xFF534D42, "cifs"}, {0x73757245, "coda"}, {0x012FF7B7, "coh"}, {0x28cd3d45, "cramfs"}, {0x00001373, "devfs"}, {0x00414A53, "efs"}, {0x0000137D, "ext"}, {0x0000EF51, "ext2"}, {0x0000EF52, "ext3"}, {0x0000EF53, "ext4"}, {0x00004244, "hfs"}, {0xF995E849, "hpfs"}, {0x958458f6, "hgfs"}, {0x00009660, "isofs"}, {0x000072b6, "jffs2"}, {0x3153464a, "jfs"}, {0x0000137F, "minix"}, {0x0000138F, "minix"}, {0x00002468, "minix2"}, {0x00002478, "minix2"}, {0x00004d44, "fat32"}, {0x0000564c, "ncp"}, {0x00006969, "nfs"}, {0x5346544e, "ntfs"}, {0x00009fa1, "openprom"}, {0x00009fa0, "proc"}, {0x0000002f, "qnx4"}, {0x52654973, "reiserfs"}, {0x00007275, "romfs"}, {0x0000517B, "smb"}, {0x012FF7B6, "sysv2"}, {0x012FF7B5, "sysv4"}, {0x01021994, "tmpfs"}, {0x15013346, "udf"}, {0x00011954, "ufs"}, {0x00009fa2, "usb device"}, {0xa501FCF5, "vxfs"}, {0x012FF7B4, "xenix"}, {0x58465342, "xfs"}, {0x012FD16D, "_xiafs"}};
  auto it = file_system_names.find(stat.f_type);
  file_system_name = it == file_system_names.end() ? "unknown" : it->second;
#endif
  return true;
}

bool drive::set_Volume_label(const std::string& root_path_name, const std::string& volume_name) {
  // There is no API to change the volume label on macOS and linux.
  return false;
}
