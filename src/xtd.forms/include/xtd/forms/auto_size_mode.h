/// @file
/// @brief Contains xtd::forms::auto_size_mode enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how a control will behave when its auto_size property is enabled.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the border style for controls that have a changeable border.
    enum class auto_size_mode {
      /// @brief The control grows or shrinks to fit its contents. The control cannot be resized manually.
      grow_and_shrink = 0,
      /// @brief The control grows as much as necessary to fit its contents but does not shrink smaller than the value of its size property. The form can be resized, but cannot be made so small that any of its contained controls are hidden.
      grow_only = 1,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, auto_size_mode value) {return os << to_string(value, {{auto_size_mode::grow_and_shrink, "grow_and_shrink"}, {auto_size_mode::grow_only, "grow_only"}});}
    inline std::wostream& operator<<(std::wostream& os, auto_size_mode value) {return os << to_string(value, {{auto_size_mode::grow_and_shrink, L"grow_and_shrink"}, {auto_size_mode::grow_only, L"grow_only"}});}
    /// @endcond
  }
}
