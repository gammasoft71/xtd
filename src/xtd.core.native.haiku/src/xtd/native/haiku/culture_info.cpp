#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#include "../../../../include/xtd/native/haiku/shell_execute.hpp"
#include "../../../../include/xtd/native/haiku/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <AppFileInfo.h>
#include <Entry.h>
#include <File.h>
#include <LocaleRoster.h>
#include <Message.h>
#include <Roster.h>
#include <String.h>
#include <image.h>
#include <locale>
#include <string>
#include <vector>

using namespace xtd::native;

namespace {
  auto to_locale_name(const std::string& name) -> std::string {
    if (name.empty() || name == "C" || name == "POSIX") return name;
    if (name == "C.UTF-8") return "C";
    if (name == "POSIX.UTF-8") return "POSIX";
    auto locale_name = name;
    auto pos = locale_name.find(".");
    if (pos != std::string::npos) locale_name = locale_name.substr(0, pos);
    return locale_name + ".UTF-8";
  }
}

auto culture_info::current_locale_name() -> std::string {
  auto language = BString {};
  auto preferred = BMessage {};
  if (BLocaleRoster::Default()->GetPreferredLanguages(&preferred) == B_OK && preferred.FindString("language", 0, &language) == B_OK)
    return to_locale_name(language.String());
  return "C";
}

auto culture_info::system_locale_names() -> std::vector<std::string> {
  auto locales = std::vector<std::string> {"C", "POSIX"};
  locales.reserve(800);
  for (auto name : haiku::strings::split(haiku::shell_execute::run("locale", "-a"), {'\n'}))
    try {
      locales.push_back(std::locale {to_locale_name(name)}.name());
    } catch (...) {
    }
  std::sort(locales.begin(), locales.end());
  locales.erase(std::unique(locales.begin(), locales.end()), locales.end());
  return locales;
}
