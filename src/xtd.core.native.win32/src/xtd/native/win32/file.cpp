#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace xtd::native;

#undef max
#undef min

int32_t file::copy(const std::string& source_file, const std::string& target_file) {
  FILE* source = fopen(source_file.c_str(), "rb");
  if (source == nullptr) return -1;
  
  FILE* target = fopen(target_file.c_str(), "wb");
  if (target == nullptr) {
    fclose(source);
    return -1;
  }
  
  size_t count = 0;
  do {
    uint8_t buffer[1024];
    count = fread(buffer, 1, 1024, source);
    if (count > 0) fwrite(buffer, 1, count, target);
  } while (count == 1024);
  
  fclose(source);
  fclose(target);
  return 0;
}

size_t file::get_size(const std::string& path) {
  WIN32_FIND_DATA file;
  void* handle = FindFirstFileA(path.c_str(), &file);
  if (handle == INVALID_HANDLE_VALUE)
    return 0;
  
  ULARGE_INTEGER size;
  size.HighPart = file.nFileSizeHigh;
  size.LowPart = file.nFileSizeLow;
  FindClose(handle);
  return static_cast<size_t>(size.QuadPart);
}

int32_t directory::move(const std::string& old_path, const std::string& new_path) {
  int32_t file_attributes = 0;
  if (get_file_attributes(new_path, file_attributes) == 0)
    return -1;
  return ::rename(old_path.c_str(), new_path.c_str());
}

int32_t directory::remove(const std::string& file) {
  return ::remove(file.c_str());
}
