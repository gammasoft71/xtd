/// @file
/// @brief Contains xtd::forms::check_state enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the state of a control, such as a check box, that can be checked, unchecked, or set to an indeterminate state.
    /// @par Header
    /// @code #include <xtd/forms/check_state> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Multiple methods in check_box, checked_list_box, and item_check_event_args use this enumeration.
    /// @note Use an indeterminately checked control when you do not want to set a default value.
    enum class check_state {
      /// @brief The control is unchecked.
      unchecked = 0,
      /// @brief The control is checked.
      checked = 1,
      /// @brief The control is indeterminate. An indeterminate control generally has a shaded appearance.
      indeterminate = 2
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::check_state> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::check_state> {{xtd::forms::check_state::unchecked, "unchecked"}, {xtd::forms::check_state::checked, "checked"}, {xtd::forms::check_state::indeterminate, "indeterminate"}};}
};
/// @endcond
