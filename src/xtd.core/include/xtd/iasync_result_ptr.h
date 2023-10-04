/// @file
/// @brief Contains xtd::iasync_result_ptr alias.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
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
  using iasync_result_ptr = std::shared_ptr<xtd::iasync_result>;
}
