#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/environment.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/path.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <filesystem>

using namespace xtd;
using namespace xtd::io;

std::string path::__get_current_dirirectory() noexcept {
  return std::filesystem::current_path().string();
}

bool path::__is_windows_os() noexcept {
  return environment::os_version().is_windows_platform();
}

std::string path::__get_temp_path() noexcept {
  return native::path::get_temp_path();
}
