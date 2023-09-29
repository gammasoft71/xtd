/// @file
/// @brief Contains xtd::language_id enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the c++ language used by assembly.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see xtd::cpp_language
  /// @remarks For more info about c++ see <a href="https://en.cppreference.com/w/cpp">cppreference</a>.
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
    cpp20,
    /// @brief The language is c++23.
    cpp23,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::language_id> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::language_id> {{xtd::language_id::unknown, "unknown"}, {xtd::language_id::cpp_pre98, "cpp_pre98"}, {xtd::language_id::cpp98, "cpp98"}, {xtd::language_id::cpp11, "cpp11"}, {xtd::language_id::cpp14, "cpp14"}, {xtd::language_id::cpp17, "cpp17"}, {xtd::language_id::cpp20, "cpp20"}, {xtd::language_id::cpp23, "cpp23"}};}
};
/// @endcond
