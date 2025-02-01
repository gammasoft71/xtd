/// @file
/// @brief Contains xtd::event_handler event handler.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "generic_event_handler.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the method that will handle an event that has no event data.
  /// ```cpp
  /// using event_handler = xtd::delegate<void(xtd::object& sender, const xtd::event_args& e)>;
  /// ```
  /// @param sender The source of the event.
  /// @param e An object that contains no event data.
  /// @par Header
  /// ```cpp
  /// #include <xtd/event_handler>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  using event_handler = generic_event_handler<const xtd::event_args&>;
}
