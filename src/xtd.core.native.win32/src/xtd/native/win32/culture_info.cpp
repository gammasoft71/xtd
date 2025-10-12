#define NOMINMAX
#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#include "../../../../include/xtd/native/win32/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <Windows.h>

using namespace xtd::native;

namespace {
  char to_upper(char v) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(v)));
  }
  
  std::string to_locale_name(const std::string& name) {
    if (name.empty()) return "";
    static const std::vector<std::string> unsupported_scripts = {"-Adlm", "-Arab", "-Aran", "-Beng", "-Bopo", "-Cyrl", "-Deva", "-Ethi", "-Grek", "-Guru", "-Hans", "-Hant", "-Hebr", "-Latn", "-Kana", "-Mtei", "-Olck", "-Orya", "-Rohg", "-Telu", "-Tfng", "-Thai", "-Vaii", "-POSIX"};
    std::string locale_name = name;
    for (const auto& script : unsupported_scripts) {
      auto pos = locale_name.find(script);
      if (pos == std::string::npos) continue;
      locale_name.erase(pos, script.size());
      break;
    }
    std::replace(locale_name.begin(), locale_name.end(), '-', '_');
    auto index = locale_name.rfind('_');
    if (!locale_name.empty() && index == std::string::npos) {
      std::string upper = locale_name;
      std::transform(upper.begin(), upper.end(), upper.begin(), to_upper);
      locale_name += "_" + upper;
    } else if (index != std::string::npos && index + 1 < locale_name.size()) {
      auto c = locale_name[index + 1];
      if (std::isdigit(static_cast<unsigned char>(c))) {
        locale_name.erase(index);
        std::string upper = locale_name;
        std::transform(upper.begin(), upper.end(), upper.begin(), to_upper);
        locale_name += "_" + upper;
      }
    }
    if (!locale_name.empty()) locale_name += ".UTF-8";
    return locale_name;
  }
}

std::string culture_info::current_locale_name() {
  WCHAR locale_name[LOCALE_NAME_MAX_LENGTH];
  if (!GetUserDefaultLocaleName(locale_name, LOCALE_NAME_MAX_LENGTH)) return "C";
  return to_locale_name(win32::strings::to_string(locale_name));
}

std::vector<std::string> culture_info::system_locale_names() {
  auto locales = std::vector<std::string> {"", "C", "POSIX"};
  locales.reserve(800);
  
  auto callback = [](LPWSTR locale_name, DWORD, LPARAM lparam) -> BOOL {
    auto* locales = reinterpret_cast<std::vector<std::string>*>(lparam);
    locales->push_back(to_locale_name(win32::strings::to_string(locale_name)));
    return TRUE;
  };
  
  EnumSystemLocalesEx(callback, LOCALE_ALL, reinterpret_cast<LPARAM>(&locales), nullptr);
  std::sort(locales.begin(), locales.end());
  locales.erase(std::unique(locales.begin(), locales.end()), locales.end());
  return locales;
}
