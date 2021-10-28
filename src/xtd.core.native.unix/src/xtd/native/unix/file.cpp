#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file.h>
#include <xtd/native/file_attribute.h>
#include <xtd/native/file_system.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>

using namespace xtd::native;

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

bool file::exists(const std::string& path) {
  int32_t attributes = 0;
  return file_system::get_attributes(path, attributes) == 0 && (attributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY;
}

size_t file::get_size(const std::string& path) {
  struct stat status;
  if (stat(path.c_str(), &status) != 0) return 0;
  return static_cast<size_t>(status.st_size);
}

int32_t file::move(const std::string& old_path, const std::string& new_path) {
  int32_t file_attributes = 0;
  if (file_system::get_attributes(new_path, file_attributes) == 0) return -1;
  return rename(old_path.c_str(), new_path.c_str());
}

int32_t file::remove(const std::string& file) {
  return unlink(file.c_str());
}
