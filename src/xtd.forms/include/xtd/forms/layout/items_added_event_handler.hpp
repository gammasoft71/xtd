/// @file
/// @brief Contains xtd::forms::items_added_event_handler event handler.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "items_added_event_args.hpp"
#include <xtd/event_handler>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::layout namespace contains classes for implementing layout behaviors in your form or control.
    namespace layout {
      /// @brief Represents the method that will handle the items added event of a xtd::forms::layout::arranged_element_colleciton.
      /// ```cpp
      /// template<class item_t>
      /// using items_added_event_handler = xtd::delegate<void(xtd::object& sender, const xtd::forms::layout::items_added_event_args<type_t>& e)>;
      /// ```
      /// @param sender The source of the event.
      /// @param e A xtd::forms::layout::items_added_event_args that contains the event data.
      /// @par Header
      /// ```cpp
      /// #include <xtd/forms/layout/items_added_event_handler>
      /// ```
      /// @par Namespace
      /// xtd::forms
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms events
      template<class item_t>
      using items_added_event_handler = xtd::delegate<void(xtd::object& sender, const xtd::forms::layout::items_added_event_args<item_t>& e)>;
  }
}
