#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the border style for a control.
    /// @remarks Use the members of this enumeration to set the border style for controls that have a changeable border.
    enum class border_styles {
      /// @brief No border.s
      none = 0,
      /// @brief A single-line border.
      fixed_single = 1,
      /// @brief A three-dimensional border.
      fixed_3d = 2,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, border_styles value) {return os << to_string(value, {{border_styles::none, "none"}, {border_styles::fixed_single, "fixed_single"}, {border_styles::fixed_3d, "fixed_3"}});}
    inline std::wostream& operator<<(std::wostream& os, border_styles value) {return os << to_string(value, {{border_styles::none, L"none"}, {border_styles::fixed_single, L"fixed_single"}, {border_styles::fixed_3d, L"fixed_3d"}});}
    /// @endcond
  }
}
