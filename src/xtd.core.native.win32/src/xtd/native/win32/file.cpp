#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file>
#include <xtd/native/file_attribute>
#include <xtd/native/file_system>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace xtd::native;

#undef max
#undef min

int_least32_t file::copy(const std::string& source_file, const std::string& target_file) {
  return CopyFile(win32::strings::to_wstring(source_file).c_str(), win32::strings::to_wstring(target_file).c_str(), TRUE) != FALSE ? 0 : -1;
}

bool file::exists(const std::string& path) {
  int_least32_t attributes = 0;
  return file_system::get_attributes(path, attributes) == 0 && (attributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY;
}

size_t file::get_size(const std::string& path) {
  WIN32_FIND_DATA file;
  void* handle = FindFirstFile(win32::strings::to_wstring(path).c_str(), &file);
  if (handle == INVALID_HANDLE_VALUE)
    return 0;
    
  ULARGE_INTEGER size;
  size.HighPart = file.nFileSizeHigh;
  size.LowPart = file.nFileSizeLow;
  FindClose(handle);
  return static_cast<size_t>(size.QuadPart);
}

int_least32_t file::move(const std::string& old_path, const std::string& new_path) {
  return MoveFile(win32::strings::to_wstring(old_path).c_str(), win32::strings::to_wstring(new_path).c_str()) != FALSE ? 0 : -1;
}

int_least32_t file::remove(const std::string& file) {
  return DeleteFile(win32::strings::to_wstring(file).c_str()) != FALSE ? 0 : -1;
}
