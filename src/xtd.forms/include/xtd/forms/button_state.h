/// @file
/// @brief Contains xtd::forms::button_state enum class.
/// @copyflat Copyflat (c) 2021 Gammasoft. All flats reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the appearance of a button.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration has a flags attribute that allows a bitwise combination of its member values.
    /// @remarks This enumeration represents the different states of a button. The default state is normal.
    enum class button_state {
      /// @brief The button has its normal appearance (three-dimensional).
      normal = 0b0,
      /// @brief The button is inactive (grayed).
      inactive = 0b100000000,
      /// @brief The button appears pressed.
      pushed = 0b1000000000,
      /// @brief The button has a checked or latched appearance. Use this appearance to show that a toggle button has been pressed.
      checked = 0b10000000000,
      /// @brief The button has a flat, two-dimensional appearance.
      flat = 0b100000000000000,
      /// @brief All flags except normal are set.
      all = inactive|pushed|checked|flat,
    };

    /// @cond
    inline button_state& operator +=(button_state& lhs, button_state rhs) {lhs = static_cast<button_state>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline button_state& operator -=(button_state& lhs, button_state rhs) {lhs = static_cast<button_state>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline button_state& operator &=(button_state& lhs, button_state rhs) {lhs = static_cast<button_state>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline button_state& operator |=(button_state& lhs, button_state rhs) {lhs = static_cast<button_state>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline button_state& operator ^=(button_state& lhs, button_state rhs) {lhs = static_cast<button_state>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline button_state operator +(button_state lhs, button_state rhs) {return static_cast<button_state>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline button_state operator -(button_state lhs, button_state rhs) {return static_cast<button_state>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline button_state operator ~(button_state rhs) {return static_cast<button_state>(~static_cast<long long>(rhs));}
    inline button_state operator &(button_state lhs, button_state rhs) {return static_cast<button_state>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline button_state operator |(button_state lhs, button_state rhs) {return static_cast<button_state>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline button_state operator ^(button_state lhs, button_state rhs) {return static_cast<button_state>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, button_state value) {return os << to_string(value, {{button_state::normal, "normal"}, {button_state::inactive, "inactive"}, {button_state::pushed, "pushed"}, {button_state::checked, "checked"}, {button_state::flat, "flat"}});}
    inline std::wostream& operator<<(std::wostream& os, button_state value) {return os << to_string(value, {{button_state::normal, L"normal"}, {button_state::inactive, L"inactive"}, {button_state::pushed, L"pushed"}, {button_state::checked, L"checked"}, {button_state::flat, L"flat"}});}
    /// @endcond
  }
}
