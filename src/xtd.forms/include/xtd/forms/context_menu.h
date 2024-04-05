/// @file
/// @brief Contains xtd::forms::context_menu menu.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "menu.h"
#include "message.h"
#include <xtd/drawing/point>
#include <xtd/iclonable>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Represents a shortcut menu.
    /// @par Header
    /// @code #include <xtd/forms/context_menu> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    /// @par Appearance
    /// |       | Windows                                              | macOS                                                | Gnome                                                |
    /// | ----- | ---------------------------------------------------- | ---------------------------------------------------- | ---------------------------------------------------- |
    /// | Light |  @image html menus_and_toolbars_context_menu_w.png   |  @image html menus_and_toolbars_context_menu_m.png   |  @image html menus_and_toolbars_context_menu_g.png   |
    /// | Dark  |  @image html menus_and_toolbars_context_menu_wd.png  |  @image html menus_and_toolbars_context_menu_md.png  |  @image html menus_and_toolbars_context_menu_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of context menu componant.
    /// @include context_menu.cpp
    class forms_export_ context_menu : public menu, public iclonable {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize context_menu class.
      context_menu();
      /// @brief Initialize a new instance of context_menu class.
      /// @param menu_items An array of menu_item objects that will be added to the main_menu.
      explicit context_menu(const std::vector<menu_item_ref>& menu_items);
      /// @}
      
      /// @cond
      explicit context_menu(const std::initializer_list<const_menu_item_ref>& menu_items);
      context_menu(context_menu&&) = default;
      context_menu(const context_menu&) = default;
      context_menu& operator =(const context_menu&) = default;
      ~context_menu();
      /// @endcond
      
      /// @name Ppublic methods
      
      /// @{
      /// @brief Displays the shortcut menu at the specified position.
      /// @param control A xtd::forms::control that specifies the control with which this shortcut menu is associated.
      /// @param pos A xtd::drawing::point that specifies the coordinates at which to display the menu. These coordinates are specified relative to the client coordinates of the control specified in the control parameter.
      /// @remarks Typically, a xtd::forms::context_menu is displayed when the user clicks the right mouse button on a control or area of the form that the xtd::forms::context_menu is bound to. You can use this method to manually display the shortcut menu at a specific location and bind it with a specific control. This method does not return until the menu is dismissed.
      void show(const xtd::forms::control& control, const xtd::drawing::point& pos);
      /// @}
      ///
    protected:
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      std::unique_ptr<xtd::object> clone() const override;
      
      intptr create_menu_handle() override;
      void destroy_menu_handle(intptr handle) override;
      void on_item_added(size_t pos, menu_item_ref item) override;
      void on_item_removed(size_t pos, menu_item_ref item) override;
      /// @}
      
    private:
      friend class control;
      bool on_item_click(intptr menu_id);
    };
  }
}
