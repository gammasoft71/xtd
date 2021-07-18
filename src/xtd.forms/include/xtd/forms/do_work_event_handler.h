/// @file
/// @brief Contains xtd::forms::do_work_event_handler event handler.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <xtd/event_handler.h>
#include "do_work_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class component;
    /// @endcond
    
    /// @brief Represents the method that will handle the do_work event. This class cannot be inherited.
    /// @param sender The source of the event.
    /// @param e A do_work_event_args that contains the event data.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks When you create a do_work_event_handler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event-handler method is called whenever the event occurs, unless you remove the delegate
    using do_work_event_handler = delegate<void(component& sender, do_work_event_args& e)>;
  }
}
