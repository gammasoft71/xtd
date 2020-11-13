#pragma once

#include <xtd/event_handler.h>
#include "key_press_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    template<typename type_t>
    using key_press_event_handler = delegate<void(type_t, key_press_event_args&)>;
  }
}
