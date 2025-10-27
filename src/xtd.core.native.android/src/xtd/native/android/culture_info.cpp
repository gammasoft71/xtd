#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#include "../../../../include/xtd/native/android/shell_execute.hpp"
#include "../../../../include/xtd/native/android/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace xtd::native;

namespace {
  std::string to_locale_name(const std::string& name) {
    if (name.empty() || name == "C" || name == "POSIX") return name;
    auto locale_name = name;
    auto pos = locale_name.find(".");
    if (pos != std::string::npos) locale_name = locale_name.substr(0, pos);
    return locale_name + ".UTF-8";
  }
}

std::string culture_info::current_locale_name() {
  const char* locale_env = std::getenv("LC_ALL");
  if (!locale_env) locale_env = std::getenv("LANG");
  if (!locale_env) return "C";
  return to_locale_name(std::string {locale_env});
}

std::vector<std::string> culture_info::system_locale_names() {
  auto locales = std::vector<std::string> {"", "C", "POSIX"};
  locales.reserve(800);
  for (auto name : android::strings::split(android::shell_execute::run("locale", "-a"), {'\n'}))
    locales.push_back(to_locale_name(name));
  std::sort(locales.begin(), locales.end());
  locales.erase(std::unique(locales.begin(), locales.end()), locales.end());
  return locales;
}
