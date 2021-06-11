/// @file
/// @brief Contains xtd::diagnostics::data_received_event_handler event handler.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../event_handler.h"
#include "data_received_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Represents the method that will handle the xtd::diagnostics::process::output_data_received and xtd::diagnostics::process::error_data_received event of a Process.
    /// @param sender The source of the event.
    /// @param e A xtd::diagnostics::process::data_received_event_args that contains the event data.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core events
    template<typename sender_t>
    using data_received_event_handler = xtd::delegate<void(sender_t sender, const data_received_event_args& e)>;
  }
}
