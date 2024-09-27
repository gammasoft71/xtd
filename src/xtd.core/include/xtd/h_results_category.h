/// @file
/// @brief Contains h_results class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "int32.h"
#include "string.h"
#include "static.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains the HRESULT values used by xtd.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @remarks For more information, see Winerror.h from Micorosft's Win32 API.
  const std::error_category& h_results_category() noexcept;
}
