#include "../include/xtd/translator.h"
#include <filesystem>
#include <map>
#include "../include/xtd/cdebug.h"
#include "../include/xtd/environment.h"
#include "../include/xtd/format.h"
#include "../include/xtd/format_exception.h"
#include "../include/xtd/collections/specialized/string_map.h"
#include "../include/xtd/io/file.h"
#include "../include/xtd/io/path.h"

namespace {
  std::map<std::string, xtd::collections::specialized::string_map> __xtd_language_values__;
  
  std::string __xtd_language__;
  
  void parse_file(const std::filesystem::path& file, const std::string& language) {
    xtd::cdebug << xtd::format("parse {} for {} language", file, language) << std::endl;
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
        __xtd_language_values__[language][key] = value;
        key = "";
        value = "";
      }
    }
  }
  
  void parse_directory(const std::filesystem::path& path) {
    if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path)) return;
    for (auto locale_item : std::filesystem::directory_iterator(path)) {
      if (locale_item.is_directory()) {
        for (auto language_item : std::filesystem::directory_iterator(locale_item.path())) {
          if (language_item.path().extension() == ".strings")
            parse_file(language_item.path(), xtd::strings::to_lower(locale_item.path().filename().string()));
        }
      }
    }
  }
}

using namespace std;
using namespace std::filesystem;
using namespace xtd;

std::string translator::language() {
  initialize(); // Must be first
  return __xtd_language__;
}

void translator::language(const std::string& language) {
  initialize(); // Must be first
  __xtd_language__ = xtd::strings::to_lower(language);
}

std::vector<std::string> translator::languages() {
  initialize(); // Must be first
  static std::vector<std::string> languages;
  if (languages.empty()) {
    for (auto language_value : __xtd_language_values__)
      languages.push_back(language_value.first);
  }
  return languages;
}

std::string translator::translate(const std::string& language, const std::string& value) {
  initialize(); // Must be first
  try {
    return __xtd_language_values__.at(language).at(value);
  } catch (...) {
    return value;
  }
}

void translator::parse_locale(const std::filesystem::path& locale_path) {
  parse_directory(locale_path);
}

void translator::initialize() {
  static bool initialized = false;
  if (initialized) return;
  
  if (__xtd_language__.empty()) __xtd_language__ = environment::get_environment_variable("LANG");
  if (__xtd_language__.empty() && !std::locale().name().empty() && std::locale().name() != "C") __xtd_language__ = xtd::strings::to_lower(xtd::strings::substring(std::locale().name(), 0, 2));

  parse_directory(path("locale"));
  if (xtd::environment::os_version().is_macos_platform()) parse_directory(path(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]))/".."/"Resources"/"locale");
  else parse_directory(path(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]))/"locale");
  parse_directory(path(__XTD_INSTALL_PATH__)/"share"/"xtd"/"locale");
  /*
  if (xtd::environment::os_version().is_macos_platform()) parse_directory(path(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]))/".."/"Resources");
  else if (xtd::environment::os_version().is_linux_platform()) parse_directory(path("usr")/"share"/"locale");
  else parse_directory(path(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0])));
   */
  initialized = true;
}
