/// @file
/// @brief Contains xtd::action delegate.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "delegate.h"
#include "iasync_result.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief References a method to be called when a corresponding asynchronous operation completes.
  /// @param ar The result of the asynchronous operation.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  using async_callback = delegate<void(std::shared_ptr<xtd::iasync_result> ar)>;
}
