/// @file
/// @brief Contains xtd::beep class.
#pragma once
#include <xtd/event_handler.h>
#include "console_cancel_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the method that will handle the cancel_key_press event of a xtd::console.
  /// @param sender The source of the event.
  /// @param e A xtd::console_cancel_event_args object that contains the event data.
  using console_cancel_event_handler = xtd::delegate<void(console_cancel_event_args&)>;
}
