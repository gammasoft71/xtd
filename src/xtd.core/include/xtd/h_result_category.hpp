/// @file
/// @brief Contains xtd::h_result_category method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <system_error>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Obtains a reference to the static error category object for h_result errors. The object is required to override the virtual function error_category::name() to return a pointer to the string "h_result_category". It is used to identify error conditions that correspond to the xtd::h_result error codes.
  /// @return A reference to the static object of unspecified runtime type, derived from [std::error_category](https://en.cppreference.com/w/cpp/error/error_category).
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  const std::error_category& h_result_category() noexcept;
}
