#define NOMINMAX
#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#include "../../../../include/xtd/native/win32/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <string>
#include <Windows.h>

using namespace xtd::native;

std::string culture_info::current_name() {
  WCHAR localeName[LOCALE_NAME_MAX_LENGTH];
  if (!GetUserDefaultLocaleName(localeName, LOCALE_NAME_MAX_LENGTH)) return "C";
  return win32::strings::to_string(localeName) + ".utf-8";
}
