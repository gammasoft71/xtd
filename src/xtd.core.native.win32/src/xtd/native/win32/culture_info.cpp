#define NOMINMAX
#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <string>
#include <Windows.h>

using namespace xtd::native;

std::string culture_info::current_name() {
  std::wstring localeName(LOCALE_NAME_MAX_LENGTH, '\0');
  if (!GetUserDefaultLocaleName(localeName.data(), localeName.size())) return "C";
  return localeName + ".utf-8";
}
