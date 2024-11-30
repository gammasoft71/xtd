/// @file
/// @brief Contains xtd::forms::combo_box_style enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the combo_box style.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/combo_box_style>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks When a control is docked to an edge of its container, it is always positioned flush against that edge when the container is resized. If more than one control is docked to an edge, the controls appear side by side according to their z-order; controls higher in the z-order are positioned farther from the container's edge.
    /// @remarks If left, right, top, or bottom is selected, the specified and opposite edges of the control are resized to the size of the containing control's corresponding edges. If fill is selected, all four sides of the control are resized to match the containing control's edges.
    /// @remarks The drop_down_style property specifies whether the list is always displayed or whether the list is displayed in a drop-down. The drop_down_style property also specifies whether the text portion can be edited.
    enum class combo_box_style {
      /// @brief Specifies that the list is always visible and that the text portion is editable. This means that the user can enter a new value and is not limited to selecting an existing value in the list.
      simple = 1,
      /// @brief Specifies that the list is displayed by clicking the down arrow and that the text portion is editable. This means that the user can enter a new value and is not limited to selecting an existing value in the list. When using this setting, the append value of auto_complete_mode works the same as the suggest_append value. This is the default style.
      drop_down = 2,
      /// @brief Specifies that the list is displayed by clicking the down arrow and that the text portion is not editable. This means that the user cannot enter a new value. Only values already in the list can be selected. The list displays only if auto_complete_mode is suggest or suggest_append.
      drop_down_list = 3,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::combo_box_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::combo_box_style> {{xtd::forms::combo_box_style::simple, "simple"}, {xtd::forms::combo_box_style::drop_down, "drop_down"}, {xtd::forms::combo_box_style::drop_down_list, "drop_down_list"}};}
};
/// @endcond
