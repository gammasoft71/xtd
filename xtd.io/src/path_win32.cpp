#if defined(_WIN32)

#include "../include/xtd/file.hpp"
#include <string>
#include <Windows.h>

std::string __get_current_dirirectory() noexcept {
  char path[MAX_PATH + 1];
  return _getcwd(path, MAX_PATH) ? path : "";
}

bool __is_windows_os() noexcept {
  return true;
}


#endif
