#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the type of display for hot-key prefixes that relate to text.
    /// @remarks A hot-key prefix allows you to use a keyboard combination (usually CTRL+HotKey or ALT+HotKey) to access functionality represented by text displayed on the screen.
    enum class hotkey_prefix {
      /// @brief No hot-key prefix.
      none = 0,
      /// @brief Display the hot-key prefix.
      show = 1,
      /// @brief Do not display the hot-key prefix.
      hide = 2,
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, hotkey_prefix value) {return os << xtd::to_string(value, {{hotkey_prefix::none, "none"}, {hotkey_prefix::show, "show"}, {hotkey_prefix::hide, "hide"}});}
    inline std::wostream& operator<<(std::wostream& os, hotkey_prefix value) {return os << xtd::to_string(value, {{hotkey_prefix::none, L"none"}, {hotkey_prefix::show, L"show"}, {hotkey_prefix::hide, L"hide"}});}
    /// @endcond
  }
}
