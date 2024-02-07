/// @file
/// @brief Contains xtd::forms::collapsible_panel container.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "border_sides.h"
#include "border_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of controls in a collapsible panel.
    /// @par Header
    /// @code #include <xtd/forms/collapsible_panel> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Examples
    /// The following code example demonstrates the use of collapsible_panel container.
    /// @include collapsible_panel.cpp
    class forms_export_ collapsible_panel : public control {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the collapsible_panel class.
      collapsible_panel();
      /// @}
      
      /// @name Properties
      
      /// @{
      virtual bool auto_size() const noexcept override;
      
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      virtual forms::border_sides border_sides() const noexcept;
      /// @brief Sets the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      virtual collapsible_panel& border_sides(forms::border_sides border_sides);
      
      /// @brief Gets the border style for the control.
      /// @return One of the border_style values. The default is border_style::none.
      /// @remarks By default, the collapsible_panel control is displayed without a border. You can use this property to distinguish the boundaries of the collapsible_panel control from other areas on the form.
      virtual forms::border_style border_style() const noexcept;
      /// @brief Sets the border style for the control.
      /// @param border_style One of the border_style values. The default is border_style::none.
      /// @remarks By default, the collapsible_panel control is displayed without a border. You can use this property to distinguish the boundaries of the collapsible_panel control from other areas on the form.
      virtual collapsible_panel& border_style(forms::border_style border_style);
      /// @brief Resets the border style for the control.
      /// @param border_style nullptr.
      /// @return Current label instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual collapsible_panel& border_style(std::nullptr_t);

      /// @brief Gets a value indicating whether the collapsible_panel is in the expanded.
      /// @return true if collapsible_panel is expanded; otherwise false.
      bool expanded() const noexcept;
      /// @brief Sets a value indicating whether the collapsible_panel is in the expanded.
      /// @param expanded true if collapsible_panel is expanded; otherwise false.
      collapsible_panel& expanded(bool expanded);
      
      /// @cond
      const xtd::drawing::size& client_size() const noexcept override;
      xtd::drawing::size size() const noexcept override;
      /// @endcond
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Collapse the collapsible_panel.
      /// @remarks Collapsing the collapsible_panel is equivalent to setting the expanded property to false. After the collapse method is called, the expanded property returns a value of false until the expand method is called.
      void collapse();
      
      using control::create;
      /// @brief A factory to create an xtd::forms::collapsible_panel with specified text, expanded, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::collapsible_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::collapsible_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::collapsible_panel.
      /// @param name The name of the xtd::forms::collapsible_panel.
      /// @return New xtd::forms::collapsible_panel created.
      static collapsible_panel create(const xtd::ustring& text, bool expanded = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::collapsible_panel with specified parent, text, exapended, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::collapsible_panel.
      /// @param text A string that represent text of the xtd::forms::collapsible_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::collapsible_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::collapsible_panel.
      /// @param name The name of the xtd::forms::collapsible_panel.
      /// @return New xtd::forms::collapsible_panel created.
      static collapsible_panel create(const control& parent, const xtd::ustring& text, bool expanded = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      
      /// @brief Expand the collapsible_panel.
      /// @remarks Expanding the collapsible_panel is equivalent to setting the expanded property to true. After the expand method is called, the expanded property returns a value of true until the collapse method is called.
      void expand();
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the expanded property changes.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      xtd::event<collapsible_panel, xtd::event_handler> expanded_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      drawing::size measure_control() const noexcept override;
      
      void on_control_added(const control_event_args& e) override;
      void on_control_removed(const control_event_args& e) override;
      
      /// @brief Raises the collapsible_panel::expanded_changed event.
      virtual void on_expanded_changed(const xtd::event_args& e);
      
      void on_handle_created(const event_args& e) override;
      
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      control& auto_size(bool auto_size) override;
      control& client_size(const xtd::drawing::size& client_size) override;
      control& size(const xtd::drawing::size& size) override;
      void wm_command_control(message& message);
      
      std::shared_ptr<data> data_;
    };
  }
}
