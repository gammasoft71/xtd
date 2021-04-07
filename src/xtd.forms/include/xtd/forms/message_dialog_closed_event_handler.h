/// @file
/// @brief Contains xtd::forms::message_dialog_closed_event_handler event handller.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "message_dialog_closed_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    template<typename type_t>
    using message_dialog_closed_event_handler = delegate<void(type_t sender, const message_dialog_closed_event_args& e)>;
  }
}
