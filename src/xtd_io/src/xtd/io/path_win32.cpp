#if defined(_WIN32)
#define _CRT_SECURE_NO_WARNINGS

#include "../../../include/xtd/io/file.h"
#include <string>
#include <direct.h>
#include <Windows.h>

std::string __get_current_dirirectory() noexcept {
  char path[MAX_PATH + 1];
  return _getcwd(path, MAX_PATH) ? path : "";
}

bool __is_windows_os() noexcept {
  return true;
}

std::string __get_temp_path() noexcept {
  if (getenv("TMP") != nullptr)  return getenv("TMP");
  if (getenv("TEMP") != nullptr) return getenv("TEMP");
  if (getenv("USERPROFILE") != nullptr) return getenv("USERPROFILE");
  return getenv("WINDIR");
}

#endif
