/// @file
/// @brief Contains xtd::timers::elapsed_event_handler event handler.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "elapsed_event_args.hpp"
#include "../event_handler.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the xtd::timers::timer component, which allows you to raise an event on a specified interval.
  namespace timers {
    /// @brief Represents the method that will handle the signal events of a xtd::environment.
    /// ```cpp
    /// using elapsed_event_handler = xtd::delegate<void(xtd::object& sender, const elapsed_event_args& e)>;
    /// ```
    /// @param sender The source of the event.
    /// @param e A xtd::timers::elapsed_event_args object that contains the event data.
    /// @par Header
    /// ```cpp
    /// #include <xtd/timers/elapsed_event_handler>
    /// ```
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core events
    using elapsed_event_handler = xtd::delegate<void(xtd::object& sender, const elapsed_event_args& e)>;
  }
}
