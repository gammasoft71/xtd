/// @file
/// @brief Contains xtd::forms::draw_item_state enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the state of an item that is being drawn. This enumeration supports a bitwise combination of its member values.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by members such as xtd::forms::draw_item_event_args::state.
    enum class draw_item_state {
      /// @brief The item currently has no state.
      none = 0b0,
      /// @brief The item is selected.
      selected = 0b1,
      /// @brief The item is grayed. Only menu controls use this value.
      grayed = 0b10,
      /// @brief The item is unavailable.
      disabled = 0b100,
      /// @brief The item is checked. Only menu controls use this value.
      checked = 0b1000,
      /// @brief The item has focus.
      focus = 0b1'0000,
      /// @brief The item is in its default visual state.
      default_state = 0b10'0000,
      /// @brief The item is being hot-tracked, that is, the item is highlighted as the mouse pointer passes over it.
      hot_light = 0b100'0000,
      /// @brief The item is inactive.
      inactive = 0b1000'00000,
      /// @brief The item displays without a keyboard accelerator.
      no_accelerator = 0b1'0000'0000,
      /// @brief The item displays without the visual cue that indicates it has focus.
      no_focus_rect = 0b10'0000'0000,
      /// @brief The item is the editing portion of a xtd::forms::combo_box.
      combo_box_edit = 0b1'0000'0000'0000,
    };
    
    /// @cond
    inline draw_item_state& operator +=(draw_item_state& lhs, draw_item_state rhs) {lhs = static_cast<draw_item_state>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline draw_item_state& operator -=(draw_item_state& lhs, draw_item_state rhs) {lhs = static_cast<draw_item_state>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline draw_item_state& operator &=(draw_item_state& lhs, draw_item_state rhs) {lhs = static_cast<draw_item_state>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline draw_item_state& operator |=(draw_item_state& lhs, draw_item_state rhs) {lhs = static_cast<draw_item_state>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline draw_item_state& operator ^=(draw_item_state& lhs, draw_item_state rhs) {lhs = static_cast<draw_item_state>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline draw_item_state operator +(draw_item_state lhs, draw_item_state rhs) {return static_cast<draw_item_state>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline draw_item_state operator -(draw_item_state lhs, draw_item_state rhs) {return static_cast<draw_item_state>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline draw_item_state operator ~(draw_item_state rhs) {return static_cast<draw_item_state>(~static_cast<long long>(rhs));}
    inline draw_item_state operator &(draw_item_state lhs, draw_item_state rhs) {return static_cast<draw_item_state>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline draw_item_state operator |(draw_item_state lhs, draw_item_state rhs) {return static_cast<draw_item_state>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline draw_item_state operator ^(draw_item_state lhs, draw_item_state rhs) {return static_cast<draw_item_state>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, draw_item_state value) {return os << to_string(value, {{draw_item_state::none, "none"}, {draw_item_state::selected, "selected"}, {draw_item_state::grayed, "grayed"}, {draw_item_state::disabled, "disabled"}, {draw_item_state::checked, "checked"}, {draw_item_state::focus, "focus"}, {draw_item_state::default_state, "default_state"}, {draw_item_state::hot_light, "hot_light"}, {draw_item_state::inactive, "inactive"}, {draw_item_state::no_accelerator, "no_accelerator"}, {draw_item_state::no_focus_rect, "no_focus_rect"}, {draw_item_state::combo_box_edit, "combo_box_edit"}});}
    inline std::wostream& operator<<(std::wostream& os, draw_item_state value) {return os << to_string(value, {{draw_item_state::none, L"none"}, {draw_item_state::selected, L"selected"}, {draw_item_state::grayed, L"grayed"}, {draw_item_state::disabled, L"disabled"}, {draw_item_state::checked, L"checked"}, {draw_item_state::focus, L"focus"}, {draw_item_state::default_state, L"default_state"}, {draw_item_state::hot_light, L"hot_light"}, {draw_item_state::inactive, L"inactive"}, {draw_item_state::no_accelerator, L"no_accelerator"}, {draw_item_state::no_focus_rect, L"no_focus_rect"}, {draw_item_state::combo_box_edit, L"combo_box_edit"}});}
    /// @endcond
  }
}
