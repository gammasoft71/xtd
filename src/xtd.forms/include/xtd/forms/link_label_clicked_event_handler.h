/// @file
/// @brief Contains xtd::forms::link_label class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "link_label_clicked_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents the method that will handle the xtd::forms::link_label::link_clicked event of a xtd::forms::link_label.
    /// @param sender The source of the event.
    /// @param e A xtd::forms::link_label_link_clicked_event_args that contains the event data.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms forms event
    /// @remarks When you create a xtd::forms::link_label_link_clicked_event_handler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, until you remove the delegate.
    using link_label_clicked_event_handler = delegate<void(object& sender, link_label_clicked_event_args& e)>;
  }
}

