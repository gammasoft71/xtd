/// @file
/// @brief Contains xtd::forms::auto_size_mode enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how a control will behave when its auto_size property is enabled.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/auto_size_mode>
    /// ```
    /// @par Namespace
    /// xtd::forms
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
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::auto_size_mode> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::auto_size_mode> {{xtd::forms::auto_size_mode::grow_and_shrink, "grow_and_shrink"}, {xtd::forms::auto_size_mode::grow_only, "grow_only"}};}
};
/// @endcond
