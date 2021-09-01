/// @file
/// @brief Contains xtd::console_cancel_event_handler event handler.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "event_handler.h"
#include "console_cancel_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the method that will handle the cancel_key_press event of a xtd::console.
  /// @param sender The source of the event.
  /// @param e A xtd::console_cancel_event_args object that contains the event data.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  using console_cancel_event_handler = xtd::delegate<void(console_cancel_event_args&)>;
}
