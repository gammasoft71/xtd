#include "../../include/xtd/translator.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/format_exception.h"
#include "../../include/xtd/ustring.h"
#include "../../include/xtd/collections/specialized/string_map.h"
#include "../../include/xtd/io/directory.h"
#include "../../include/xtd/io/file.h"
#include "../../include/xtd/io/path.h"
#include "../../include/xtd/threading/lock_guard.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::collections::specialized;
using namespace xtd::io;

map<ustring, string_map> translator::language_values_;
ustring translator::language_;
set<ustring> translator::translated_languages_;

xtd::ustring translator::language() {
  try {
    initialize(); // Must be first
  } catch (...) {
  }
  return language_;
}

void translator::language(const xtd::ustring& language) {
  try {
    initialize(); // Must be first
  } catch (...) {
  }
  language_ = language;
}

std::vector<xtd::ustring> translator::languages() {
  try {
    initialize(); // Must be first
  } catch (...) {
  }
  static auto languages = std::vector<xtd::ustring> {};
  if (!languages.empty()) return languages;
  for_each(language_values_.begin(), language_values_.end(), [&](auto language_value) {languages.push_back(language_value.first);});
  return languages;
}

std::locale translator::locale() {
  return std::locale {};
}

void translator::locale(const xtd::ustring& value) {
  auto parts = (value.find_last_of(".") == value.npos ? value : value.remove(value.find_last_of("."))).split({'_'});
  auto extension = value.find_last_of(".") == value.npos ? ".utf-8" : value.substring(value.find_last_of("."));
  if (parts.size() != 0 && parts.size() != 2) throw argument_exception(csf_);
  auto language = parts.size() == 0 ? "en" : parts[0].to_lower();
  auto country = parts.size() == 0 ? "US" : parts[1].to_upper();
  locale(std::locale {language + "_" + country + extension});
}

void translator::locale(const std::locale& locale) {
  std::locale::global(locale);
}

xtd::ustring translator::system_language() {
  return locale_to_language(xtd::native::translator::get_system_locale());
}

void translator::add_value(const xtd::ustring& language, const xtd::ustring& key, const xtd::ustring& value) {
  language_values_[language][key] = value;
}

void translator::parse_locale(const xtd::ustring& locale_path) {
  if (!directory::exists(locale_path)) return;
  for (auto locale_item : directory::get_directories(locale_path)) {
    // Uncomment the following line if initialization is too slow to read only the current language, and not all languages...
    // if (language_ != path::get_file_name(locale_item)) continue;
    for (auto language_item : directory::get_files(locale_item))
      if (path::get_extension(language_item) == ".strings") parse_file(language_item, path::get_file_name(locale_item));
  }
}

void translator::parse_file(const xtd::ustring& file, const xtd::ustring& language) {
  auto lines = xtd::io::file::read_all_lines(file);
  auto key = ustring::empty_string;
  auto value = ustring::empty_string;
  auto line_count = 0;
  for (auto line : lines) {
    line_count++;
    line = line.trim();
    if (ustring::is_empty(line)) continue;
    if (line.starts_with("#")) continue;
    if (key.empty() && line.starts_with("key ")) key = line.remove(0, 4).trim('"');
    else if (!key.empty() && line.starts_with("value ")) value = line.remove(0, 6).trim('"');
    else throw xtd::format_exception(xtd::ustring::format("file {} has an invalid format at line {}", file, line_count), csf_);
    if (!key.empty() && !value.empty()) {
      add_value(language, key, value);
      key = value = "";
    }
  }
}

xtd::ustring translator::translate(const xtd::ustring& value) noexcept {
  return translate(language(), value);
}

xtd::ustring translator::translate(const xtd::ustring& language, const xtd::ustring& value) noexcept {
  return translate(language, value.c_str());
}

const char* translator::translate(const char* value) noexcept {
  return translate(language(), value);
}

const char* translator::translate(const xtd::ustring& language, const char* value) noexcept {
  try {
    initialize(); // Must be first
    return language_values_.at(language).at(value).c_str();
  } catch (...) {
    return value;
  }
}

void translator::initialize() {
  static object sync_root;
  auto lock = threading::lock_guard {sync_root};
  
  if (language_.empty()) {
    if (!std::locale {}.name().empty() && std::locale {}.name() != "C") language_ = locale_to_language(std::locale {}.name());
    else language_ = system_language();
  }
  
  static auto language_initialized = ustring::empty_string;
  if (language_initialized == language_ || language_values_.find(language_) != language_values_.end()) return;
  
  auto xtd_locale_path = environment::get_folder_path(environment::special_folder::xtd_locale);
  if (directory::exists(xtd_locale_path)) {
    for (auto item : directory::get_directories(xtd_locale_path))
      translated_languages_.insert(item);
    parse_locale(xtd_locale_path);
  }

  auto application_locale_path = xtd::environment::os_version().is_macos_platform() ? io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "Resources", "locale") : io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "locale");
  if (directory::exists(application_locale_path)) {
    for (auto item : directory::get_directories(application_locale_path))
      translated_languages_.insert(item);
    parse_locale(application_locale_path);
  }

  language_initialized = language_;
}

ustring translator::locale_to_language(ustring locale) {
  if (locale.size() < 2) return locale;
  if (locale.find(".") != locale.npos) locale = locale.remove(locale.find("."));
  if (translated_languages_.find(locale) != translated_languages_.end()) return locale;
  return locale.remove(2);
}
