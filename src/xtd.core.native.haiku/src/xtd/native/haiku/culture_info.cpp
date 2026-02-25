#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
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
  auto get_signature() -> std::string {
    auto info = image_info {};
    auto cookie = 0;
    while (get_next_image_info(B_CURRENT_TEAM, &cookie, &info) == B_OK) {
      if (info.type == B_APP_IMAGE) {
        auto entry = BEntry {info.name};
        auto ref = entry_ref {};
        if (entry.GetRef(&ref) == B_OK) {
          auto file = BFile {&ref, B_READ_ONLY};
          auto appInfo = BAppFileInfo {&file};
          char sig[B_MIME_TYPE_LENGTH];
          if (appInfo.GetSignature(sig) == B_OK) return sig;
        }
        break;
      }
    }
    return "application/x-vnd.console";
  }
  
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
  auto roster = BLocaleRoster::Default();
  auto languages = BMessage{};
  if (roster->GetAvailableCatalogs(&languages, get_signature().c_str()) != B_OK) return {};
  
  auto language = BString{};
  auto locale_names = std::vector<std::string>{};
  for (auto i = 0; languages.FindString("language", i, &language) == B_OK; i++)
    try {
      locale_names.push_back(std::locale {to_locale_name(language.String())}.name());
    } catch (...) {
    }
  return locale_names;
}
