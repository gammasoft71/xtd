#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how a form window is displayed.
    /// @remarks This enumeration is used by the form class. It represents the different states of the form. The default state is normal.
    enum class form_window_state {
      /// @brief A default sized window.
      normal = 0,
      /// @brief A minimized window.
      minimized = 1,
      /// @brief A maximized window.
      maximized = 2,
      /// @brief A full screen window.
      full_screen = 3,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, form_window_state value) {return os << to_string(value, {{form_window_state::normal, "normal"}, {form_window_state::minimized, "minimized"}, {form_window_state::maximized, "maximized"}, {form_window_state::full_screen, "full_screen"}});}
    inline std::wostream& operator<<(std::wostream& os, form_window_state value) {return os << to_string(value, {{form_window_state::normal, L"normal"}, {form_window_state::minimized, L"minimized"}, {form_window_state::maximized, L"maximized"}, {form_window_state::full_screen, L"full_screen"}});}
    /// @endcond
  }
}
