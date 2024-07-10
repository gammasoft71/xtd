/// @file
/// @brief Contains xtd::async_result alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "iasync_result.h"
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the status of an asynchronous operation.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// The following example shows how to use xtd::async_result.
  /// @include iasync_result.cpp
  using async_result = xtd::sptr<xtd::iasync_result>;
}
