#include "../../include/xtd/translator.hpp"
#include "../../include/xtd/environment.hpp"
#include "../../include/xtd/format_exception.hpp"
#include "../../include/xtd/string.hpp"
#include "../../include/xtd/collections/generic/list.hpp"
#include "../../include/xtd/collections/specialized/string_dictionary.hpp"
#include "../../include/xtd/io/directory.hpp"
#include "../../include/xtd/io/file.hpp"
#include "../../include/xtd/io/path.hpp"
#include "../../include/xtd/threading/lock.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::collections::specialized;
using namespace xtd::helpers;
using namespace xtd::io;

std::map<string, std::map<string, string>> translator::language_values_;
string translator::language_;
std::set<string> translator::translated_languages_;

string translator::language() {
  try {
    initialize(); // Must be first
  } catch (...) {
  }
  return language_;
}

void translator::language(const string& language) {
  try {
    initialize(); // Must be first
  } catch (...) {
  }
  language_ = language;
}

array<string> translator::languages() {
  try {
    initialize(); // Must be first
  } catch (...) {
  }
  static auto languages = list<string> {};
  if (languages.count() != 0) return languages;
  std::for_each(language_values_.begin(), language_values_.end(), [&](auto language_value) {languages.add(language_value.first);});
  return languages.to_array();
}

std::locale translator::locale() {
  return std::locale {};
}

void translator::locale(const string& value) {
  auto parts = (value.find_last_of(".") == value.npos ? value : value.remove(value.find_last_of("."))).split('_');
  auto extension = value.find_last_of(".") == value.npos ? ".utf-8" : value.substring(value.find_last_of("."));
  if (parts.size() != 0 && parts.size() != 2) throw_helper::throws(exception_case::argument);
  auto language = parts.size() == 0 ? "en" : parts[0].to_lower();
  auto country = parts.size() == 0 ? "US" : parts[1].to_upper();
  locale(std::locale {language + "_" + country + extension});
}

void translator::locale(const std::locale& locale) {
  std::locale::global(locale);
}

string translator::system_language() {
  return locale_to_language(native::translator::get_system_locale());
}

void translator::add_value(const string& language, const string& key, const string& value) {
  language_values_[language][key] = value;
}

void translator::parse_locale(const string& locale_path) {
  if (!directory::exists(locale_path)) return;
  for (auto locale_item : directory::get_directories(locale_path)) {
    // Uncomment the following line if initialization is too slow to read only the current language, and not all languages...
    if (language_ != path::get_file_name(locale_item)) continue;
    for (auto language_item : directory::get_files(locale_item))
      if (path::get_extension(language_item) == ".strings") parse_file(language_item, path::get_file_name(locale_item));
  }
}

void translator::parse_file(const string& file, const string& language) {
  auto lines = io::file::read_all_lines(file);
  auto key = string::empty_string;
  auto value = string::empty_string;
  auto line_count = 0;
  for (auto line : lines) {
    line_count++;
    line = line.trim();
    if (string::is_empty(line)) continue;
    if (line.starts_with("#")) continue;
    if (xtd::string::is_empty(key) && line.starts_with("key ")) key = line.remove(0, 4).trim('"');
    else if (!xtd::string::is_empty(key) && line.starts_with("value ")) value = line.remove(0, 6).trim('"');
    else throw_helper::throws(exception_case::format, string::format("file {} has an invalid format at line {}", file, line_count).c_str());
    if (!xtd::string::is_empty(key) && !xtd::string::is_empty(value)) {
      add_value(language, key, value);
      key = value = "";
    }
  }
}

string translator::translate(const string& value) noexcept {
  return translate(language(), value);
}

string translator::translate(const string& language, const string& value) noexcept {
  return translate(language, value.c_str());
}

const char* translator::translate(const char* value) noexcept {
  return translate(language(), value);
}

const char* translator::translate(const string& language, const char* value) noexcept {
  initialize(); // Must be first
  auto language_iterator = language_values_.find(language);
  if (language_iterator == language_values_.end()) return value;
  auto value_iterator = language_iterator->second.find(value);
  if (value_iterator == language_iterator->second.end()) return value;
  return value_iterator->second.c_str();
}

void translator::initialize() {
  try {
    static object sync_root;
    auto lock = threading::lock {sync_root};
  } catch (...) {
  }
  
  if (xtd::string::is_empty(language_)) {
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
  
  auto application_locale_path = environment::os_version().is_macos_platform() ? io::path::combine(io::path::get_directory_name(environment::get_command_line_args()[0]), "..", "Resources", "locale") : io::path::combine(io::path::get_directory_name(environment::get_command_line_args()[0]), "locale");
  if (directory::exists(application_locale_path)) {
    for (auto item : directory::get_directories(application_locale_path))
      translated_languages_.insert(item);
    parse_locale(application_locale_path);
  }
  
  language_initialized = language_;
}

string translator::locale_to_language(string locale) {
  if (locale.length() < 2) return locale;
  if (locale.find(".") != locale.npos) locale = locale.remove(locale.find("."));
  if (translated_languages_.find(locale) != translated_languages_.end()) return locale;
  return locale.remove(2);
}
