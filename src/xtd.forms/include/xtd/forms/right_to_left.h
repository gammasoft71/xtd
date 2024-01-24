/// @file
/// @brief Contains xtd::forms::right_to_left enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies a value indicating whether the text appears from right to left, such as when using Hebrew or Arabic fonts.
    /// @par Header
    /// @code #include <xtd/forms/right_to_left> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by xtd::forms::context_menu, xtd::forms::main_menu, xtd::forms::progress_bar, and xtd::forms::control.
    /// @remarks When you retrieve the value of the `RightToLeft` property from xtd::forms::context_menu, xtd::forms::main_menu, and xtd::forms::progress_bar you will get the value of xtd::forms::right_to_left you assigned. In contrast, if you are deriving your own class from xtd::forms::control, and you assign a value of Inherit to the xtd::forms::control::right_to_left property, the value returned will be the setting of the xtd::forms::control::right_to_left property of the parent control. If there is no parent control, it will return a value of xtd::forms::right_to_left::no. Otherwise, it will return a value of xtd::forms::right_to_left::yes or xtd::forms::right_to_left::no, depending on the value that you assigned to the xtd::forms::control::right_to_left property of your derived class.
    /// @note For more information about how enabling right-to-left alignment affects Windows Forms controls, see the xtd::forms::control::right_to_left property.
    enum class right_to_left {
      /// @brief The text reads from left to right. This is the default.
      no,
      /// @brief The text reads from right to left.
      yes,
      /// @brief The direction the text read is inherited from the parent control.
      inherit,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::right_to_left> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::right_to_left> {{xtd::forms::right_to_left::no, "no"}, {xtd::forms::right_to_left::yes, "yes"}, {xtd::forms::right_to_left::inherit, "inherit"}};}
};
/// @endcond
