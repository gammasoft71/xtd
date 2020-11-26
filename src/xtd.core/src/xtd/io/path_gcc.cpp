#if defined(__linux__) || defined(__APPLE__)

#include "../../../include/xtd/io/path.h"
#include <string>
#include <unistd.h>
#include <sys/param.h>

std::string xtd::io::path::__get_current_dirirectory() noexcept {
  char path[MAXPATHLEN + 1];
  return getcwd(path, MAXPATHLEN) ? path : "";
}

bool xtd::io::path::__is_windows_os() noexcept {
  return false;
}

std::string xtd::io::path::__get_temp_path() noexcept {
  if (getenv("TMPDIR") != nullptr) return getenv("TMPDIR");
  return "/tmp/";
}

#endif
