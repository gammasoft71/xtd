/// @file
/// @brief Contains xtd::forms::panel container.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <optional>
#include "scrollable_control.h"
#include "border_sides.h"
#include "border_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of controls.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
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
    ///     <td>@image html containers_panel_w.png</td>
    ///     <td>@image html containers_panel_m.png</td>
    ///     <td>@image html containers_panel_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <td>Dark</td>
    ///     <td>@image html containers_panel_wd.png</td>
    ///     <td>@image html containers_panel_md.png</td>
    ///     <td>@image html containers_panel_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of panel container.
    /// @include panel.cpp
    class forms_export_ panel : public scrollable_control {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of panel class.
      panel();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the mode by which the panel automatically resizes itself.
      /// @return An auto_size_mode enumerated value. The default is grow_only.
      virtual forms::auto_size_mode auto_size_mode() const noexcept;
      /// @brief Sets the mode by which the panel automatically resizes itself.
      /// @param value An auto_size_mode enumerated value. The default is grow_only.
      /// @return Current panel instance.
      virtual panel& auto_size_mode(forms::auto_size_mode value);
      
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      virtual forms::border_sides border_sides() const noexcept;
      /// @brief Sets the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      virtual panel& border_sides(forms::border_sides border_sides);
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual forms::border_style border_style() const noexcept;
      /// @brief Sets the border style for the control.
      /// @param border_style One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current panel instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual panel& border_style(forms::border_style border_style);
      /// @brief Resets the border style for the control.
      /// @param border_style nullptr.
      /// @return Current panel instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual panel& border_style(std::nullptr_t border_style);
      /// @}
      
    protected:
      /// @name Protetced properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}

      /// @name Protetced methods
      
      /// @{
      drawing::size measure_control() const noexcept override;
      void on_layout(const event_args& e) override;
      void on_paint(paint_event_args& e) override;
      /// @}
      
    private:
      struct data {
        forms::border_sides border_sides = forms::border_sides::all;
        std::optional<forms::border_style> border_style;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
