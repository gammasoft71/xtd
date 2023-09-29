#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator>
#include <xtd/native/environment>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

std::string translator::get_system_language() {
  if (!environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS).empty()) return win32::strings::to_lower(win32::strings::substring(environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS), 0, 2));
  auto data_size = GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SISO639LANGNAME, nullptr, 0);
  std::wstring data(data_size, 0);
  GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SISO639LANGNAME, data.data(), data_size);
  return win32::strings::to_string(data);
}
