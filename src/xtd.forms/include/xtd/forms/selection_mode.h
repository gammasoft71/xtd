/// @file
/// @brief Contains xtd::forms::selection_mode enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the selection behavior of a list box.
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

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, selection_mode value) {return os << to_string(value, {{selection_mode::none, "none"}, {selection_mode::one, "one"}, {selection_mode::multi_simple, "multi_simple"}, {selection_mode::multi_extended, "multi_extended"}});}
    inline std::wostream& operator<<(std::wostream& os, selection_mode value) {return os << to_string(value, {{selection_mode::none, L"none"}, {selection_mode::one, L"one"}, {selection_mode::multi_simple, L"multi_simple"}, {selection_mode::multi_extended, L"multi_extended"}});}
    /// @endcond
  }
}
