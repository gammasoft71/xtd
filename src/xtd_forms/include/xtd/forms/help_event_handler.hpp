#pragma once

#include <xtd/event_handler.h>
#include "help_event_args.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents the method that will handle the help_requested event of a control.
    /// @param sender The source of the event.
    /// @param e A help_event_args that contains the event data.
    /// @remarks When you create a help_event_handler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate.
    template<typename type_t>
    using help_event_handler = delegate<void(type_t sender, help_event_args& e)>;
  }
}
