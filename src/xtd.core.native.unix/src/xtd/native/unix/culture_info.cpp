#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#include "../../../../include/xtd/native/unix/shell_execute.hpp"
#include "../../../../include/xtd/native/unix/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace xtd::native;

std::string culture_info::current_locale_name() {
  const char* locale_env = std::getenv("LC_ALL");
  if (!locale_env || !*locale_env) locale_env = std::getenv("LANG");
  if (locale_env && *locale_env) return locale_env;
  return "C";
}
std::string culture_info::locale_name_extension() {
  return ".utf-8";
}


std::vector<std::string> culture_info::system_locale_names() {
  auto locales = std::vector<std::string> {"", "C", "POSIX"};
  locales.reserve(800);
  
  auto lines = unix::shell_execute::run("locale", "-a");
  for (auto line : unix::strings::split(lines, {'\n'})) {
    auto pos = line.find(native::unix::strings::to_upper(locale_name_extension()));
    if (pos == std::string::npos) continue;
    std::string locale_name = line.substr(0, pos) + locale_name_extension();
    locales.push_back(locale_name);
  }
  std::sort(locales.begin(), locales.end());
  locales.erase(std::unique(locales.begin(), locales.end()), locales.end());
  return locales;
}
