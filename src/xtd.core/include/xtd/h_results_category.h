/// @file
/// @brief Contains h_results class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "int32.h"
#include "string.h"
#include "static.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Obtains a reference to the static error category object for h_result errors. The object is required to override the virtual function error_category::name() to return a pointer to the string "h_results_category". It is used to identify error conditions that correspond to the xtd::h_results error codes.
  /// @return A reference to the static object of unspecified runtime type, derived from [std::error_category](https://en.cppreference.com/w/cpp/error/error_category).
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  const std::error_category& h_results_category() noexcept;
  
  /// @brief Creates error code value for xtd::h_results `h_result`.
  /// @param h_result xtd::h_results error code to create error code for.
  /// @return Error code corresponding to `h_result`.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  std::error_code make_error_code(int h_result) noexcept;
}
