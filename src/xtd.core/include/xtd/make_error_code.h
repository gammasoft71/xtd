/// @file
/// @brief Contains xtd::make_error_code method.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <system_error>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Creates error code value for xtd::h_result `h_result`.
  /// @param h_result xtd::h_result error code to create error code for.
  /// @return Error code corresponding to `h_result`.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  std::error_code make_error_code(int h_result) noexcept;
}
