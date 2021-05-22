#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file.h>
#include <xtd/native/file_attribute.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstring>
#include <sys/stat.h>

using namespace xtd::native;

int file::get_attributes(const std::string& path) {
  struct stat status = {};
  if (stat(path.c_str(), &status) != 0) return -1;
  int file_attribute = 0x00;
  if ((status.st_mode & S_IRUSR) == S_IRUSR && (status.st_mode & S_IWUSR) == 0) file_attribute |= FILE_ATTRIBUTE_READONLY;
  if ((status.st_mode & S_IFSOCK) == S_IFSOCK || (status.st_mode & S_IFIFO) == S_IFIFO) file_attribute |= FILE_ATTRIBUTE_SYSTEM;
  if ((status.st_mode & S_IFDIR) == S_IFDIR) file_attribute |= FILE_ATTRIBUTE_DIRECTORY;
  if ((status.st_mode & S_IFREG) == S_IFREG) file_attribute |= FILE_ATTRIBUTE_ARCHIVE;
  if ((status.st_mode & S_IFBLK) == S_IFBLK || (status.st_mode & S_IFCHR) == S_IFCHR) file_attribute |= FILE_ATTRIBUTE_DEVICE;
  if ((status.st_mode & S_IFREG) == S_IFREG) file_attribute |= FILE_ATTRIBUTE_NORMAL;
  return file_attribute;
}
