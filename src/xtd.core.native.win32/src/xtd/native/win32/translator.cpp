#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator.h>
#include <xtd/native/environment.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace xtd::native;

#undef max
#undef min

std::string translator::get_system_language() {
  if (!environment::get_environment_variable("LANG").empty()) return win32::strings::to_lower(win32::strings::substring(environment::get_environment_variable("LANG"), 0, 2));
  wchar_t data[512] = {0};
  GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SISO639LANGNAME, data, 512);
  return win32::strings::to_string(data);
}
