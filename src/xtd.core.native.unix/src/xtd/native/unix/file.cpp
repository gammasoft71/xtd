#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file>
#include <xtd/native/file_attribute>
#include <xtd/native/file_system>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstring>
#include <unistd.h>
#include <fstream>
#include <sys/stat.h>

using namespace std;
using namespace xtd::native;

int_least32_t file::copy(const std::string& source_file, const std::string& target_file) {
  ifstream ifs {source_file, ios::binary};
  if (!ifs) return -1;
  ofstream ofs {target_file, ios::trunc | ios::binary};
  if (!ofs) return -2;
  ofs << ifs.rdbuf();
  ifs.close();
  ofs.close();
  return 0;
}

bool file::exists(const std::string& path) {
  int_least32_t attributes = 0;
  return file_system::get_attributes(path, attributes) == 0 && (attributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY;
}

size_t file::get_size(const std::string& path) {
  struct stat status;
  if (stat(path.c_str(), &status) != 0) return 0;
  return static_cast<size_t>(status.st_size);
}

int_least32_t file::move(const std::string& old_path, const std::string& new_path) {
  int_least32_t file_attributes = 0;
  if (file_system::get_attributes(new_path, file_attributes) == 0) return -1;
  return rename(old_path.c_str(), new_path.c_str());
}

int_least32_t file::remove(const std::string& file) {
  return unlink(file.c_str());
}
