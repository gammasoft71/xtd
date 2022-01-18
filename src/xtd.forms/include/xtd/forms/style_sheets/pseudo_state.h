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
        /// @brief The item is in default state.
        default_state,
        /// @brief The item is unchecked.
        unchecked = standard,
        /// @brief The item is checked.
        checked = 1,
        /// @brief The item is mixed. For the three-state ittem.
        mixed = 2,
        /// @brief The irem is pressed, mouse is down on the item.
        pressed = 3,

        /// @brief The irem is flat style.
        flat = 0b1000000,
        /// @brief The irem is popup flat style.
        flat_popup = 0b10000000,
        /// @brief The item is the default (see ibuttton_control).
        default_state = 0b100000000,
        /// @brief The item is hot (mouse is on the item).
        hot = 0b1000000000,
        /// @brief The irem is disabled, generally the item is grayed.
        disabled = 0b10000000000,
      };
      
      /// @cond
      inline pseudo_state& operator +=(pseudo_state& lhs, pseudo_state rhs) {lhs = static_cast<pseudo_state>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
      inline pseudo_state& operator -=(pseudo_state& lhs, pseudo_state rhs) {lhs = static_cast<pseudo_state>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
      inline pseudo_state& operator &=(pseudo_state& lhs, pseudo_state rhs) {lhs = static_cast<pseudo_state>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
      inline pseudo_state& operator |=(pseudo_state& lhs, pseudo_state rhs) {lhs = static_cast<pseudo_state>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
      inline pseudo_state& operator ^=(pseudo_state& lhs, pseudo_state rhs) {lhs = static_cast<pseudo_state>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
      inline pseudo_state operator +(pseudo_state lhs, pseudo_state rhs) {return static_cast<pseudo_state>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
      inline pseudo_state operator -(pseudo_state lhs, pseudo_state rhs) {return static_cast<pseudo_state>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
      inline pseudo_state operator ~(pseudo_state rhs) {return static_cast<pseudo_state>(~static_cast<long long>(rhs));}
      inline pseudo_state operator &(pseudo_state lhs, pseudo_state rhs) {return static_cast<pseudo_state>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
      inline pseudo_state operator |(pseudo_state lhs, pseudo_state rhs) {return static_cast<pseudo_state>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
      inline pseudo_state operator ^(pseudo_state lhs, pseudo_state rhs) {return static_cast<pseudo_state>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
      inline std::ostream& operator<<(std::ostream& os, const pseudo_state value) {return os << to_string(value, {{pseudo_state::default_state, "default_state,"}, {pseudo_state::flat, "flat,"}, {pseudo_state::flat_popup, "flat_popup,"}, {pseudo_state::unchecked, "unchecked,"}, {pseudo_state::checked, "checked,"}, {pseudo_state::mixed, "mixed,"}, {pseudo_state::disabled, "disabled,"}, {pseudo_state::default_state, "default_state,"}, {pseudo_state::pressed, "pressed,"}, {pseudo_state::hot, "hot,"}});}
      inline std::wostream& operator<<(std::wostream& os, const pseudo_state value) {return os << to_string(value, {{pseudo_state::default_state, L"default_state,"}, {pseudo_state::flat, L"flat,"}, {pseudo_state::flat_popup, L"flat_popup,"}, {pseudo_state::unchecked, L"unchecked,"}, {pseudo_state::checked, L"checked,"}, {pseudo_state::mixed, L"mixed,"}, {pseudo_state::disabled, L"disabled,"}, {pseudo_state::default_state, L"default_state,"}, {pseudo_state::pressed, L"pressed,"}, {pseudo_state::hot, L"hot,"}});}
      /// @endcond
    }
  }
}
