/// @file
/// @brief Contains xtd::translator class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <filesystem>
#include <string>
#include <vector>
#include "collections/specialized/string_map.h"
#include "static.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents translatoor class. This class cannot be inherited.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  class translator final static_ {
  public:
    static std::string language();
    static void language(const std::string& language);
    
    static std::vector<std::string> languages();

    static std::string system_language();

    static void add_value(const std::string& language, const std::string& key, const std::string& value);
    
    static void parse_locale(const std::filesystem::path& locale_path);
    static void parse_locale(const std::string& locale_path) {parse_locale(std::filesystem::path(locale_path));}
    /// @cond
    static void parse_locale(const char* locale_path) {parse_locale(std::filesystem::path(locale_path));}
    /// @endcond

    static void parse_file(const std::filesystem::path& file, const std::string& language);
    static void parse_file(const std::string& file, const std::string& language) {parse_file(std::filesystem::path(file), language);}
    /// @cond
    static void parse_file(const char* file, const char* language) {parse_file(std::filesystem::path(file), language);}
    /// @endcond

    static std::string translate(const std::string& value) {return translate(language(), value);}
    static std::string translate(const std::string& language, const std::string& value);
    static const char* translate(const char* value) {return translate(language(), value);}
    static const char* translate(const std::string& language, const char* value);

  private:
    static void initialize();
    static std::map<std::string, xtd::collections::specialized::string_map> language_values_;
    static std::string language_;
  };
}
