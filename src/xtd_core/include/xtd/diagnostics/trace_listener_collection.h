/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <memory>
#include <vector>
#include "trace_listener.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    using trace_listener_collection = std::vector<std::shared_ptr<trace_listener>>;
  }
}
