/// @file
/// @brief Contains xtd::diagnostics::trace_listener_collection typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include "trace_listener.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Represents a collection of trace_listener.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    using trace_listener_collection = std::vector<std::shared_ptr<trace_listener>>;
  }
}
