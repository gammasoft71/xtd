#pragma once

#include <xtd/event_handler.h>
#include "paint_event_args.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    template<typename type_t>
    using paint_event_handler = delegate<void(type_t, paint_event_args&)>;
  }
}
