#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#include "../../../../include/xtd/native/macos/shell_execute.hpp"
#include "../../../../include/xtd/native/macos/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <CoreFoundation/CoreFoundation.h>
#include <algorithm>
#include <cctype>
#include <string>
#include <regex>

using namespace xtd::native;

std::string culture_info::current_locale_name() {
  auto name = std::string("C");
  CFLocaleRef locale = CFLocaleCopyCurrent();
  if (!locale) return name;
  char buffer[256];
  if (CFStringGetCString((CFStringRef)CFLocaleGetIdentifier(locale), buffer, sizeof(buffer), kCFStringEncodingUTF8))
    name = std::regex_replace(std::string {buffer}, std::regex("@rg=[a-zA-Z]{2}zzzz"), "") + locale_name_extension();
  CFRelease(locale);
  return name;
}

std::string culture_info::locale_name_extension() {
  return ".utf-8";
}

std::vector<std::string> culture_info::system_locale_names() {
  auto locales = std::vector<std::string> {"", "C", "POSIX"};
  locales.reserve(800);
  
  auto lines = macos::shell_execute::run("locale", "-a");
  for (auto line : macos::strings::split(lines, {'\n'})) {
    auto pos = line.find(native::macos::strings::to_upper(locale_name_extension()));
    if (pos == std::string::npos) continue;
    std::string locale_name = line.substr(0, pos) + locale_name_extension();
    locales.push_back(locale_name);
  }
  std::sort(locales.begin(), locales.end());
  locales.erase(std::unique(locales.begin(), locales.end()), locales.end());
  return locales;
}
