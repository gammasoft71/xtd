#include "../../include/xtd/translator.hpp"
#include "../../include/xtd/environment.hpp"
#include "../../include/xtd/format_exception.hpp"
#include "../../include/xtd/string.hpp"
#include "../../include/xtd/collections/specialized/string_dictionary.hpp"
#include "../../include/xtd/io/directory.hpp"
#include "../../include/xtd/io/file.hpp"
#include "../../include/xtd/io/path.hpp"
#include "../../include/xtd/threading/lock_guard.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::collections::specialized;
using namespace xtd::io;

std::map<string, string_dictionary> translator::language_values_;
string translator::language_;
std::set<string> translator::translated_languages_;

xtd::string translator::language() {
  try {
    initialize(); // Must be first
  } catch (...) {
  }
  return language_;
}

void translator::language(const xtd::string& language) {
  try {
    initialize(); // Must be first
  } catch (...) {
  }
  language_ = language;
}

std::vector<xtd::string> translator::languages() {
  try {
    initialize(); // Must be first
  } catch (...) {
  }
  static auto languages = std::vector<xtd::string> {};
  if (!languages.empty()) return languages;
  for_each(language_values_.begin(), language_values_.end(), [&](auto language_value) {languages.push_back(language_value.first);});
  return languages;
}

std::locale translator::locale() {
  return std::locale {};
}

void translator::locale(const xtd::string& value) {
  auto parts = (value.find_last_of(".") == value.npos ? value : value.remove(value.find_last_of("."))).split('_');
  auto extension = value.find_last_of(".") == value.npos ? ".utf-8" : value.substring(value.find_last_of("."));
  if (parts.size() != 0 && parts.size() != 2) throw argument_exception {};
  auto language = parts.size() == 0 ? "en" : parts[0].to_lower();
  auto country = parts.size() == 0 ? "US" : parts[1].to_upper();
  locale(std::locale {language + "_" + country + extension});
}

void translator::locale(const std::locale& locale) {
  std::locale::global(locale);
}

xtd::string translator::system_language() {
  return locale_to_language(xtd::native::translator::get_system_locale());
}

void translator::add_value(const xtd::string& language, const xtd::string& key, const xtd::string& value) {
  language_values_[language][key] = value;
}

void translator::parse_locale(const xtd::string& locale_path) {
  if (!directory::exists(locale_path)) return;
  for (auto locale_item : directory::get_directories(locale_path)) {
    // Uncomment the following line if initialization is too slow to read only the current language, and not all languages...
    if (language_ != path::get_file_name(locale_item)) continue;
    for (auto language_item : directory::get_files(locale_item))
      if (path::get_extension(language_item) == ".strings") parse_file(language_item, path::get_file_name(locale_item));
  }
}

void translator::parse_file(const xtd::string& file, const xtd::string& language) {
  auto lines = xtd::io::file::read_all_lines(file);
  auto key = string::empty_string;
  auto value = string::empty_string;
  auto line_count = 0;
  for (auto line : lines) {
    line_count++;
    line = line.trim();
    if (string::is_empty(line)) continue;
    if (line.starts_with("#")) continue;
    if (key.empty() && line.starts_with("key ")) key = line.remove(0, 4).trim('"');
    else if (!key.empty() && line.starts_with("value ")) value = line.remove(0, 6).trim('"');
    else throw xtd::format_exception(xtd::string::format("file {} has an invalid format at line {}", file, line_count));
    if (!key.empty() && !value.empty()) {
      add_value(language, key, value);
      key = value = "";
    }
  }
}

xtd::string translator::translate(const xtd::string& value) noexcept {
  return translate(language(), value);
}

xtd::string translator::translate(const xtd::string& language, const xtd::string& value) noexcept {
  return translate(language, value.c_str());
}

const char* translator::translate(const char* value) noexcept {
  return translate(language(), value);
}

const char* translator::translate(const xtd::string& language, const char* value) noexcept {
  try {
    initialize(); // Must be first
    return language_values_.at(language).at(value).c_str();
  } catch (...) {
    return value;
  }
}

void translator::initialize() {
  try {
    static object sync_root;
    auto lock = threading::lock_guard {sync_root};
  } catch(...) {
  }
  
  if (language_.empty()) {
    if (!std::locale {}.name().empty() && std::locale {}.name() != "C") language_ = locale_to_language(std::locale {}.name());
    else language_ = system_language();
  }
  
  static auto language_initialized = string::empty_string;
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

string translator::locale_to_language(string locale) {
  if (locale.size() < 2) return locale;
  if (locale.find(".") != locale.npos) locale = locale.remove(locale.find("."));
  if (translated_languages_.find(locale) != translated_languages_.end()) return locale;
  return locale.remove(2);
}
