#pragma once
#include <xtd/delegate.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a method that will check whether the hosting environment is still sending messages.
    /// @return true if the hosting environment is still sending messages; otherwise, false.
    /// @remarks This delegate is used with the application::register_message_loop method.
    using message_loop_callback = delegate<bool()>;
  }
}
