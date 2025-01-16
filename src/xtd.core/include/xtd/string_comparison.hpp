/// @file
/// @brief Contains xtd::string_comparison enum class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the culture, case, and sort rules to be used by certain overloads of the xtd::string::compare method
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see xtd::string
  enum class string_comparison {
    /// @brief Compare strings using culture-sensitive sort rules and the current culture.
    current_culture,
    /// @brief Compare strings using culture-sensitive sort rules, the current culture, and ignoring the case of the strings being compared.
    current_culture_ignore_case,
    /// @brief Compare strings using culture-sensitive sort rules and the invariant culture.
    invariant_culture,
    /// @brief Compare strings using culture-sensitive sort rules, the invariant culture, and ignoring the case of the strings being compared.
    invariant_culture_ignore_case,
    /// @brief Compare strings using ordinal (binary) sort rules.
    ordinal,
    /// @brief Compare strings using ordinal (binary) sort rules and ignoring the case of the strings being compared.
    ordinal_ignore_case
  };
}

// This file is included before enum definition so the enum_register is in the enum.h file.
