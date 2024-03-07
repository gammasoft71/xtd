/// @file
/// @brief Contains xtd::forms::popup_panel container.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a special type of panel container that can be used for context menus, combo_box popups and more.
    /// @par Header
    /// @code #include <xtd/forms/popup_panel> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Appearance
    /// |       | Windows                                     | macOS                                       | Gnome                                       |
    /// | ----- | ------------------------------------------- | ------------------------------------------- | ------------------------------------------- |
    /// | Light |  @image html containers_popup_panel_w.png   |  @image html containers_popup_panel_m.png   |  @image html containers_popup_panel_g.png   |
    /// | Dark  |  @image html containers_popup_panel_wd.png  |  @image html containers_popup_panel_md.png  |  @image html containers_popup_panel_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of popup_panel container.
    /// @include popup_panel.cpp
    class forms_export_ popup_panel : public panel {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the popup_panel class.
      popup_panel();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets ignore mouse messages
      /// @return value If true, the popup panel does not close automatically when the user clicks outside the popup panel; otherwise the popup panel will close automatically. The default value is false.
      bool ignore_mouse_messages() const noexcept;
      /// @brief Sets ignore mouse messages
      /// @param value If true, the popup panel does not close automatically when the user clicks outside the popup panel; otherwise the popup panel will close automatically. The default value is false.
      /// @return The current popup panel instance.
      popup_panel& ignore_mouse_messages(bool value);
      /// @}
      
      /// @name Static methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::popup_panel.
      /// @return New xtd::forms::popup_panel created.
      static popup_panel create();
      /// @brief A factory to create an xtd::forms::popup_panel with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::popup_panel.
      /// @return New xtd::forms::popup_panel created.
      static popup_panel create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::popup_panel with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::popup_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::popup_panel.
      /// @return New xtd::forms::popup_panel created.
      static popup_panel create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::popup_panel with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::popup_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::popup_panel.
      /// @param name The name of the xtd::forms::popup_panel.
      /// @return New xtd::forms::popup_panel created.
      static popup_panel create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::popup_panel with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::popup_panel.
      /// @return New xtd::forms::popup_panel created.
      static popup_panel create(const control& parent);
      /// @brief A factory to create an xtd::forms::popup_panel with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::popup_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::popup_panel.
      /// @return New xtd::forms::popup_panel created.
      static popup_panel create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::popup_panel with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::popup_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::popup_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::popup_panel.
      /// @return New xtd::forms::popup_panel created.
      static popup_panel create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::popup_panel with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::popup_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::popup_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::popup_panel.
      /// @param name The name of the xtd::forms::popup_panel.
      /// @return New xtd::forms::popup_panel created.
      static popup_panel create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      void on_handle_created(const event_args& e) override;
      void on_layout(const event_args& e) override;
      void on_region_changed(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_show(message& message);
      
      std::shared_ptr<data> data_;
    };
  }
}
