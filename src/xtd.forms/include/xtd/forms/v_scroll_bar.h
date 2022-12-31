/// @file
/// @brief Contains xtd::forms::v_scroll_bar control.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "scroll_bar.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows horizontal scroll bar.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html control_v_scroll_bar_w.png</td>
    ///     <td>@image html control_v_scroll_bar_m.png</td>
    ///     <td>@image html control_v_scroll_bar_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html control_v_scroll_bar_wd.png</td>
    ///     <td>@image html control_v_scroll_bar_md.png</td>
    ///     <td>@image html control_v_scroll_bar_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of v_scroll_bar control.
    /// @include v_scroll_bar.cpp
    class forms_export_ v_scroll_bar : public scroll_bar {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of v_scroll_bar class.
      v_scroll_bar();
      /// @}
      
    protected:
      /// @name Protectedd properties
      
      /// @{
      xtd::forms::create_params create_params() const noexcept override;
      xtd::drawing::size default_size() const noexcept override;
      /// @}
    };
  }
}
