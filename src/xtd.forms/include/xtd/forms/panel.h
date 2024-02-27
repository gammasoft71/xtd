/// @file
/// @brief Contains xtd::forms::panel container.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "border_sides.h"
#include "border_style.h"
#include "scrollable_control.h"
#include <xtd/optional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of controls.
    /// @par Header
    /// @code #include <xtd/forms/panel> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Appearance
    /// |       | Windows                               | macOS                                 | Gnome                                 |
    /// | ----- | ------------------------------------- | ------------------------------------- | ------------------------------------- |
    /// | Light |  @image html containers_panel_w.png   |  @image html containers_panel_m.png   |  @image html containers_panel_g.png   |
    /// | Dark  |  @image html containers_panel_wd.png  |  @image html containers_panel_md.png  |  @image html containers_panel_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of panel container.
    /// @include panel.cpp
    class forms_export_ panel : public scrollable_control {
      struct data;
      
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
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      static panel create();
      /// @brief A factory to create an xtd::forms::panel with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      static panel create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::panel with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      static panel create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::panel with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::panel.
      /// @param name The name of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      static panel create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::panel with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      static panel create(const control& parent);
      /// @brief A factory to create an xtd::forms::panel with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      static panel create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::panel with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      static panel create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::panel with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::panel.
      /// @param name The name of the xtd::forms::panel.
      /// @return New xtd::forms::panel created.
      static panel create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
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
      std::shared_ptr<data> data_;
    };
  }
}
