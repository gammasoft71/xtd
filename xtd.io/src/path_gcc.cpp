#if defined(__linux__) || defined(__APPLE__)

#include "../include/xtd/file.hpp"
#include <string>
#include <unistd.h>
#include <sys/param.h>

std::string __get_current_dirirectory() noexcept {
  char path[MAXPATHLEN + 1];
  return getcwd(path, MAXPATHLEN) ? path : "";
}

bool __is_windows_os() noexcept {
  return false;
}

#endif
