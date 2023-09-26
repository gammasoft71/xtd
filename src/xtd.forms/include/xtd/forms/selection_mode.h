/// @file
/// @brief Contains xtd::forms::selection_mode enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the selection behavior of a list box.
    /// @par Header
    /// @code #include <xtd/forms/selection_mode> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by classes such as list_box and checked_list_box.
    enum class selection_mode {
      /// @brief No items can be selected.
      none = 0,
      /// @brief Only one item can be selected.
      one = 1,
      /// @brief Multiple items can be selected.
      multi_simple = 2,
      /// @brief Multiple items can be selected, and the user can use the SHIFT, CTRL, and arrow keys to make selections.
      multi_extended = 3
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::selection_mode> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::selection_mode> {{xtd::forms::selection_mode::none, "none"}, {xtd::forms::selection_mode::one, "one"}, {xtd::forms::selection_mode::multi_simple, "multi_simple"}, {xtd::forms::selection_mode::multi_extended, "multi_extended"}};}
};
/// @endcond
