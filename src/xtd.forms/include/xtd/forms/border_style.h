/// @file
/// @brief Contains xtd::forms::border_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the border style for a control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the border style for controls that have a changeable border.
    enum class border_style {
      /// @brief No border.
      none = 0,
      /// @brief A single-line border.
      fixed_single = 1,
      /// @brief A thin sunken border.
      /// @remarks Same as xtd::forms::border_style::fixed_3d.
      thin_sunken = 2,
      /// @brief A three-dimensional border.
      /// @remarks Same as xtd::forms::border_style::thin_sunken.
     fixed_3d = thin_sunken,
      /// @brief A thin raised border.
      thin_raised = 3,
      /// @brief A bevel sunken border.
      bevel_sunken = 4,
      /// @brief A bevel raised border.
      bevel_raised = 5,
      /// @brief A etched border.
      etched = 6,
      /// @brief A bump border.
      bump = 7,
      /// @brief A themed border.
      themed = 8,
      /// @brief A double-line border.
      rounded_single = 9,
      /// @brief A single dot line border.
      dot_single = 10,
      /// @brief A single dash line border.
      dash_single = 11,
      /// @brief A single dash dot line border.
      dash_dot_single = 12,
      /// @brief A single dash dot dot line border.
      dash_dot_dot_single = 13,
      /// @brief A double-line border.
      fixed_double = 14,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, border_style value) {return os << to_string(value, {{border_style::none, "none"}, {border_style::fixed_single, "fixed_single"}, {border_style::thin_sunken, "thin_sunken"}, {border_style::thin_raised, "thin_raised"}, {border_style::bevel_sunken, "bevel_sunken"}, {border_style::bevel_raised, "bevel_raised"}, {border_style::etched, "etched"}, {border_style::bump, "bump"}, {border_style::themed, "themed"}, {border_style::fixed_double, "fixed_double"}, {border_style::rounded_single, "rounded_single"}, {border_style::dot_single, "dot_single"}, {border_style::dash_single, "dash_single"}, {border_style::dash_dot_single, "dash_dot_single"}, {border_style::dash_dot_dot_single, "dash_dot_dot_single"}});}
    inline std::wostream& operator<<(std::wostream& os, border_style value) {return os << to_string(value, {{border_style::none, L"none"}, {border_style::fixed_single, L"fixed_single"}, {border_style::thin_sunken, L"thin_sunken"}, {border_style::thin_raised, L"thin_raised"}, {border_style::bevel_sunken, L"bevel_sunken"}, {border_style::bevel_raised, L"bevel_raised"}, {border_style::etched, L"etched"}, {border_style::bump, L"bump"}, {border_style::themed, L"themed"}, {border_style::fixed_double, L"fixed_double"}, {border_style::rounded_single, L"rounded_single"}, {border_style::dot_single, L"dot_single"}, {border_style::dash_single, L"dash_single"}, {border_style::dash_dot_single, L"dash_dot_single"}, {border_style::dash_dot_dot_single, L"dash_dot_dot_single"}});}
    /// @endcond
  }
}
