#include "../../include/xtd/translator.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/format_exception.h"
#include "../../include/xtd/ustring.h"
#include "../../include/xtd/collections/specialized/string_map.h"
#include "../../include/xtd/io/directory.h"
#include "../../include/xtd/io/file.h"
#include "../../include/xtd/io/path.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <map>
#include <set>

using namespace std;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::collections::specialized;

map<ustring, string_map> translator::language_values_;
ustring translator::language_;

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
  language_ = language.to_lower();
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

xtd::ustring translator::system_language() {
  return locale_to_language(xtd::native::translator::get_system_locale());
}

void translator::add_value(const xtd::ustring& language, const xtd::ustring& key, const xtd::ustring& value) {
  language_values_[language][key] = value;
}

void translator::parse_locale(const xtd::ustring& locale_path) {
  if (!directory::exists(locale_path)) return;
  for (auto locale_item : directory::get_directories(locale_path)) {
    if (language_ != path::get_file_name(locale_item).to_lower()) continue;
    for (auto language_item : directory::get_files(locale_item))
      if (path::get_extension(language_item) == ".strings") parse_file(language_item, language_);
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
  static mutex mutex_init;
  lock_guard<mutex> lock(mutex_init);
  
  if (language_.empty()) {
    if (!std::locale().name().empty() && std::locale().name() != "C") language_ = locale_to_language(std::locale().name());
    else language_ = system_language();
  }
  
  static xtd::ustring language_initialized ;
  if (language_initialized == language_ || language_values_.find(language_) != language_values_.end()) return;
  
  parse_locale(environment::get_folder_path(environment::special_folder::xtd_locale));
  if (xtd::environment::os_version().is_macos_platform()) parse_locale(io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "Resources", "locale"));
  else parse_locale(io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "locale"));
  /*
  if (xtd::environment::os_version().is_macos_platform()) parse_locale(io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "Resources"));
  else if (xtd::environment::os_version().is_unix_platform()) parse_locale(io::path::combine("usr", "share", "locale"));
  else parse_locale(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]));
   */
  language_initialized = language_;
}

ustring translator::locale_to_language(ustring locale) {
  if (locale.size() < 2) return locale;
  if (locale.find(".") != locale.npos) locale = locale.remove(locale.find("."));
  static auto codes = set<ustring> {"ar_DZ", "ar_MA", "ar_SA", "ar_TN", "de_AT", "en_AU", "en_CA", "en_GB", "en_IE", "en_IN", "en_NZ", "en_US", "en_ZA", "fa_IR", "fr_CA", "fr_CH", "ja_HIRA", "nl_BE", "pt_BR", "sr_LATN", "zh_CN", "zh_TW"};
  if (codes.find(locale) != codes.end()) return locale;
  return locale.remove(2);
}
