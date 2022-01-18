/// @file
/// @brief Contains xtd::forms::style_sheets::pseudo_state enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The pseudo_state enum class specifies the pseudo state of an element.
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      enum class pseudo_state {
        standard,
        flat,
        flat_popup,
        unchecked,
        checked,
        mixed,
        disabled,
        default_state,
        pressed,
        hot,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, const pseudo_state value) {return os << to_string(value, {{pseudo_state::standard, "standard,"}, {pseudo_state::flat, "flat,"}, {pseudo_state::flat_popup, "flat_popup,"}, {pseudo_state::unchecked, "unchecked,"}, {pseudo_state::checked, "checked,"}, {pseudo_state::mixed, "mixed,"}, {pseudo_state::disabled, "disabled,"}, {pseudo_state::default_state, "default_state,"}, {pseudo_state::pressed, "pressed,"}, {pseudo_state::hot, "hot,"}});}
      inline std::wostream& operator<<(std::wostream& os, const pseudo_state value) {return os << to_string(value, {{pseudo_state::standard, L"standard,"}, {pseudo_state::flat, L"flat,"}, {pseudo_state::flat_popup, L"flat_popup,"}, {pseudo_state::unchecked, L"unchecked,"}, {pseudo_state::checked, L"checked,"}, {pseudo_state::mixed, L"mixed,"}, {pseudo_state::disabled, L"disabled,"}, {pseudo_state::default_state, L"default_state,"}, {pseudo_state::pressed, L"pressed,"}, {pseudo_state::hot, L"hot,"}});}
      /// @endcond
    }
  }
}
