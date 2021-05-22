#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace xtd::native;

#undef max
#undef min

int32_t file::get_attributes(const std::string& path) {
  return GetFileAttributes(path.c_str());
}
