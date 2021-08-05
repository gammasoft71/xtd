/// @file
/// @brief Contains xtd::translator class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <filesystem>
#include <string>
#include <vector>
#include "collections/specialized/string_map.h"
#include "static.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents translatoor class. This class cannot be inherited.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  class translator final static_ {
  public:
    static xtd::ustring language();
    static void language(const xtd::ustring& language);
    
    static std::vector<xtd::ustring> languages();

    static xtd::ustring system_language();

    static void add_value(const xtd::ustring& language, const xtd::ustring& key, const xtd::ustring& value);
    
    static void parse_locale(const xtd::ustring& locale_path);

    static void parse_file(const xtd::ustring& file, const xtd::ustring& language);

    static xtd::ustring translate(const xtd::ustring& value) {return translate(language(), value);}
    static xtd::ustring translate(const xtd::ustring& language, const xtd::ustring& value);
    static const char* translate(const char* value) {return translate(language(), value);}
    static const char* translate(const xtd::ustring& language, const char* value);

  private:
    static void initialize();
    static std::map<xtd::ustring, xtd::collections::specialized::string_map> language_values_;
    static xtd::ustring language_;
  };
}
