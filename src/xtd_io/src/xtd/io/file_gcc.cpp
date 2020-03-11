#if defined(__linux__) || defined(__APPLE__)

#include "../../../include/xtd/io/file.h"
#include <sys/stat.h>

int __get_file_attributes(const char*path) {
  struct stat status {0};
  if (stat(path, &status) != 0) return -1;
  int file_attribute = 0x00;
  if ((status.st_mode & S_IRUSR) == S_IRUSR && (status.st_mode & S_IWUSR) == 0)
    file_attribute |= 0x01; // xtd::io::file_attributes::read_only
  if ((status.st_mode & S_IFSOCK) == S_IFSOCK || (status.st_mode & S_IFIFO) == S_IFIFO)
    file_attribute |= 0x04; // xtd::io::file_attributes::system
  if ((status.st_mode & S_IFDIR) == S_IFDIR)
    file_attribute |= 0x10; // xtd::io::file_attributes::directory
  if ((status.st_mode & S_IFREG) == S_IFREG)
    file_attribute |= 0x20; // xtd::io::file_attributes::archive
  if ((status.st_mode & S_IFBLK) == S_IFBLK || (status.st_mode & S_IFCHR) == S_IFCHR)
    file_attribute |= 0x40; // xtd::io::file_attributes::device
  if ((status.st_mode & S_IFREG) == S_IFREG)
    file_attribute |= 0x80; // xtd::io::file_attributes::normal
  return file_attribute;
}

#endif
