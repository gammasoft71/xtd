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

namespace {
  std::wstring get_locale_user_default_info(int lacole_info) {
    auto locale_info_size = GetLocaleInfo(LOCALE_USER_DEFAULT, lacole_info, nullptr, 0);
    std::wstring locale_info(locale_info_size, 0);
    GetLocaleInfo(LOCALE_USER_DEFAULT, lacole_info, locale_info.data(), locale_info_size);
    return locale_info;
  }
}

std::string translator::get_system_locale() {
  if (!environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS).empty()) return environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS);
  return win32::strings::to_lower(win32::strings::to_string(get_locale_user_default_info(LOCALE_SISO639LANGNAME))) + "_" + win32::strings::to_upper(win32::strings::to_string(get_locale_user_default_info(LOCALE_SISO3166CTRYNAME)));
}
