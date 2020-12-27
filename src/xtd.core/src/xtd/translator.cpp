#include "../include/xtd/translator.h"
#include <filesystem>
#include <map>
#include "../include/xtd/environment.h"
#include "../include/xtd/format.h"
#include "../include/xtd/format_exception.h"
#include "../include/xtd/collections/specialized/string_map.h"
#include "../include/xtd/io/file.h"
#include "../include/xtd/io/path.h"

using namespace std;
using namespace std::filesystem;
using namespace xtd;
using namespace xtd::collections::specialized;

map<string, string_map> translator::language_values_;
string translator::language_;

void translator::add_value(const std::string& language, const std::string& key, const std::string& value) {
  language_values_[language][key] = value;
}
std::string translator::language() {
  initialize(); // Must be first
  return language_;
}

void translator::language(const std::string& language) {
  initialize(); // Must be first
  language_ = xtd::strings::to_lower(language);
}

std::vector<std::string> translator::languages() {
  initialize(); // Must be first
  static std::vector<std::string> languages;
  if (languages.empty()) {
    for (auto language_value : language_values_)
      languages.push_back(language_value.first);
  }
  return languages;
}

std::string translator::translate(const std::string& language, const std::string& value) {
  initialize(); // Must be first
  try {
    return language_values_.at(language).at(value);
  } catch (...) {
    return value;
  }
}

const char* translator::translate(const std::string& language, const char* value) {
  initialize(); // Must be first
  try {
    return language_values_.at(language).at(value).c_str();
  } catch (...) {
    return value;
  }
}

void translator::parse_locale(const std::filesystem::path& locale_path) {
  if (!std::filesystem::exists(locale_path) || !std::filesystem::is_directory(locale_path)) return;
  for (auto locale_item : std::filesystem::directory_iterator(locale_path)) {
    if (locale_item.is_directory()) {
      for (auto language_item : std::filesystem::directory_iterator(locale_item.path())) {
        if (language_item.path().extension() == ".strings")
          parse_file(language_item.path(), xtd::strings::to_lower(locale_item.path().filename().string()));
      }
    }
  }
}

void translator::parse_file(const std::filesystem::path& file, const std::string& language) {
  std::vector<std::string> lines = xtd::io::file::read_all_lines(file);
  std::string key;
  std::string value;
  int line_count = 0;
  for (auto line : lines) {
    line_count++;
    line = xtd::strings::trim(line);
    if (line.empty()) continue;
    if (xtd::strings::starts_with(line, "#")) continue;
    if (key.empty() && xtd::strings::starts_with(line, "key ")) key = xtd::strings::trim(xtd::strings::remove(line, 0, 4), '"');
    else if (!key.empty() && xtd::strings::starts_with(line, "value ")) value = xtd::strings::trim(xtd::strings::remove(line, 0, 6), '"');
    else throw xtd::format_exception(xtd::format("file {} has an invalid format at line {}", file, line_count));
    if (!key.empty() && !value.empty()) {
      add_value(language, key, value);
      key = value = "";
    }
  }
}

void translator::initialize() {
  static bool initialized = false;
  if (initialized) return;
  
  if (language_.empty() && !std::locale().name().empty() && std::locale().name() != "C") language_ = xtd::strings::to_lower(xtd::strings::substring(std::locale().name(), 0, 2));
  if (language_.empty()) language_ = xtd::strings::to_lower(xtd::strings::substring(environment::get_environment_variable("LANG"), 0, 2));

  parse_locale(path(__XTD_INSTALL_PATH__)/"share"/"xtd"/"locale");
  if (xtd::environment::os_version().is_macos_platform()) parse_locale(path(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]))/".."/"Resources"/"locale");
  else parse_locale(path(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]))/"locale");
  /*
  if (xtd::environment::os_version().is_macos_platform()) parse_locale(path(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]))/".."/"Resources");
  else if (xtd::environment::os_version().is_linux_platform()) parse_locale(path("usr")/"share"/"locale");
  else parse_locale(path(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0])));
   */
  initialized = true;
}
