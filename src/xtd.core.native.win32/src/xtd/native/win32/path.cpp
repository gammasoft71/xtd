#define _CRT_SECURE_NO_WARNINGS

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/path.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <string>
#include <direct.h>
#include <Windows.h>

using namespace xtd::native;

#undef max
#undef min

std::string path::get_temp_path() {
  if (getenv("TMP") != nullptr)  return getenv("TMP");
  if (getenv("TEMP") != nullptr) return getenv("TEMP");
  if (getenv("USERPROFILE") != nullptr) return getenv("USERPROFILE");
  return getenv("WINDIR");
}
