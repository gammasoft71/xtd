/// @file
/// @brief Contains xtd::language_id enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the c++ language used by assembly.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see operating_system
  enum class language_id {
    /// @brief The language is unknown.
    unknown = -1,
    /// @brief The language is pre 98.
    cpp_pre98 = 0,
    /// @brief The language is c++98.
    cpp98,
    /// @brief The language is c++11.
    cpp11,
    /// @brief The language is c++14.
    cpp14,
    /// @brief The language is c++17.
    cpp17,
    /// @brief The language is c++20.
    cpp20
  };

  inline std::ostream& operator<<(std::ostream& os, language_id value) {return os << to_string(value, {{language_id::unknown, "unknown"}, {language_id::cpp_pre98, "cpp_pre98"}, {language_id::cpp98, "cpp98"}, {language_id::cpp11, "cpp11"}, {language_id::cpp14, "cpp14"}, {language_id::cpp17, "cpp17"}, {language_id::cpp20, "cpp20"}});}
  inline std::wostream& operator<<(std::wostream& os, language_id value) {return os << to_string(value, {{language_id::unknown, L"unknown"}, {language_id::cpp_pre98, L"cpp_pre98"}, {language_id::cpp98, L"cpp98"}, {language_id::cpp11, L"cpp11"}, {language_id::cpp14, L"cpp14"}, {language_id::cpp17, L"cpp17"}, {language_id::cpp20, L"cpp20"}});}
}
