/// @file
/// @brief Contains xtd::drawing::text::hotkey_prefix enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::text namespace provides advanced GDI+ typography functionality.
    namespace text {
      /// @brief Specifies the type of display for hot-key prefixes that relate to text.
      /// @par Namespace
      /// xtd::drawing::text
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks A hot-key prefix allows you to use a keyboard combination (usually CTRL+HotKey or ALT+HotKey) to access functionality represented by text displayed on the screen.
      enum class hotkey_prefix {
        /// @brief No hot-key prefix.
        none = 0,
        /// @brief Display the hot-key prefix.
        show = 1,
        /// @brief Do not display the hot-key prefix.
        hide = 2
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::text::hotkey_prefix> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::text::hotkey_prefix> {{xtd::drawing::text::hotkey_prefix::none, "none"}, {xtd::drawing::text::hotkey_prefix::show, "show"}, {xtd::drawing::text::hotkey_prefix::hide, "hide"}};}
};
/// @endcond
