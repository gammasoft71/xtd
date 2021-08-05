#include "../../include/xtd/translator.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/format_exception.h"
#include "../../include/xtd/ustring.h"
#include "../../include/xtd/collections/specialized/string_map.h"
#include "../../include/xtd/io/file.h"
#include "../../include/xtd/io/path.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <filesystem>
#include <map>

using namespace std;
using namespace std::filesystem;
using namespace xtd;
using namespace xtd::collections::specialized;

map<ustring, string_map> translator::language_values_;
ustring translator::language_;

void translator::add_value(const xtd::ustring& language, const xtd::ustring& key, const xtd::ustring& value) {
  language_values_[language][key] = value;
}
xtd::ustring translator::language() {
  initialize(); // Must be first
  return language_;
}

void translator::language(const xtd::ustring& language) {
  initialize(); // Must be first
  language_ = language.to_lower();
}

std::vector<xtd::ustring> translator::languages() {
  initialize(); // Must be first
  static std::vector<xtd::ustring> languages;
  if (languages.empty()) {
    for (auto language_value : language_values_)
      languages.push_back(language_value.first);
  }
  return languages;
}

xtd::ustring translator::system_language() {
  return xtd::native::translator::get_system_language();
}

xtd::ustring translator::translate(const xtd::ustring& language, const xtd::ustring& value) {
  return translate(language, value.c_str());
}

const char* translator::translate(const xtd::ustring& language, const char* value) {
  initialize(); // Must be first
  try {
    return language_values_.at(language).at(value).c_str();
  } catch (...) {
    return value;
  }
}

void translator::parse_locale(const xtd::ustring& locale_path) {
  std::filesystem::path std_path(std::string(locale_path).c_str());
  if (!std::filesystem::exists(std_path) || !std::filesystem::is_directory(std_path)) return;
  for (auto locale_item : std::filesystem::directory_iterator(std_path)) {
    if (!locale_item.is_directory() || language_ != xtd::ustring(locale_item.path().filename().string()).to_lower()) continue;
    for (auto language_item : std::filesystem::directory_iterator(locale_item.path()))
      if (language_item.path().extension() == ".strings") parse_file(language_item.path().string(), language_);
  }
}

void translator::parse_file(const xtd::ustring& file, const xtd::ustring& language) {
  vector<ustring> lines = xtd::io::file::read_all_lines(file);
  ustring key;
  ustring value;
  int line_count = 0;
  for (auto line : lines) {
    line_count++;
    line = line.trim();
    if (line.is_empty()) continue;
    if (line.starts_with("#")) continue;
    if (key.empty() && line.starts_with("key ")) key = line.remove(0, 4).trim('"');
    else if (!key.empty() && line.starts_with("value ")) value = line.remove(0, 6).trim('"');
    else throw xtd::format_exception(xtd::ustring::format("file {} has an invalid format at line {}", file, line_count), current_stack_frame_);
    if (!key.empty() && !value.empty()) {
      add_value(language, key, value);
      key = value = "";
    }
  }
}

void translator::initialize() {
  if (language_.empty()) {
    if (!std::locale().name().empty() && std::locale().name() != "C") language_ = ustring(std::locale().name()).substring(0, 2).to_lower();
    else language_ = system_language();
  }
  
  static xtd::ustring language_initialized ;
  if (language_initialized == language_ || language_values_.find(language_) != language_values_.end()) return;
    
  parse_locale(io::path::combine(__XTD_INSTALL_PATH__, "share", "xtd", "locale"));
  if (xtd::environment::os_version().is_macos_platform()) parse_locale(io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "Resources", "locale"));
  else parse_locale(io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "locale"));
  /*
  if (xtd::environment::os_version().is_macos_platform()) parse_locale(io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "Resources"));
  else if (xtd::environment::os_version().is_linux_platform()) parse_locale(io::path::combine("usr", "share", "locale"));
  else parse_locale(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]));
   */
  language_initialized = language_;
}
