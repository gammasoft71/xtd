#include "../../../include/xtd/globalization/translator.hpp"
#include "../../../include/xtd/collections/generic/list.hpp"
#include "../../../include/xtd/globalization/culture_info.hpp"
#include "../../../include/xtd/io/directory.hpp"
#include "../../../include/xtd/io/file.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/threading/lock.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::collections::specialized;
using namespace xtd::globalization;
using namespace xtd::helpers;
using namespace xtd::io;

dictionary<string, string_dictionary> translator::language_values_;
string_dictionary translator::languages_;
optional<string> translator::language_;

string translator::language() {
  return language_.value_or(system_language());
}

void translator::language(const string& language) {
  if (language_.has_value() && language_ == language) return;
  if (string::is_empty(language) || language.any([](auto c) {return !char_object::is_letter(c) && c != '-' && c != '_';})) throw_helper::throws(xtd::helpers::exception_case::argument);
  language_ = to_language_name(language);
}

void translator::language(xtd::null_ptr) {
  language_.reset();
}

array<string> translator::languages() {
  static auto languages = list<string> {};
  if (languages.count() != 0) return languages.to_array();
  std::for_each(language_values_.begin(), language_values_.end(), [&](auto language_value) {languages.add(language_value.first);});
  return languages.to_array();
}

string translator::system_language() {
  return to_language_name(to_language_name(culture_info::current_culture().name()));
}

bool translator::parse_locale(const string& locale_path) {
  return parse_locale(locale_path, language());
}

bool translator::parse_locale(const string& locale_path, const string& language) {
  if (!directory::exists(locale_path)) return false;
  for (auto locale_item : directory::get_directories(locale_path)) {
    if (to_language_name(language) != path::get_file_name(locale_item)) continue;
    for (auto language_item : directory::get_files(locale_item))
      if (path::get_extension(language_item) == ".strings") parse_file(language_item, path::get_file_name(locale_item));
  }
  return true;
}

bool translator::parse_file(const string& file) {
  return parse_file(file, language());
}

bool translator::parse_file(const string& file, const string& language) {
  if (!io::file::exists(file)) return false;
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
    else throw_helper::throws(exception_case::format, string::format("file {} has an invalid format at line {}", file, line_count).chars().c_str());
    if (!xtd::string::is_empty(key) && !xtd::string::is_empty(value)) {
      language_values_[language][key] = value;
      key = value = "";
    }
  }
  return true;
}

bool translator::load_language(const xtd::string& language, const xtd::string& xtd_locale_path, const xtd::string& application_locale_path) {
  lock_(languages_) {
    if (!languages_.contains_key(language) || !language_values_.contains_key(language)) {
      auto succeed = false;
      if (directory::exists(xtd_locale_path)) succeed = parse_locale(xtd_locale_path, language);
      if (directory::exists(application_locale_path)) succeed = parse_locale(application_locale_path, language);
      if (succeed) languages_[language] = language;
    }
  }
  return language_values_.contains_key(languages_[language]);
}

string translator::to_language_name(const xtd::string& language) {
  return language.replace("-", "_");
}

string translator::to_fallback_name(const xtd::string& language) {
  auto language_name = to_language_name(language);
  auto index = language_name.find_first_of("_");
  return index != npos ? language_name.remove(index) : language_name;
}
