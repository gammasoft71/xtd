/// @file
/// @brief Contains xtd::forms::tool_bar_button container.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "component.h"
#include <xtd/event.h>
#include <xtd/event_handler.h>
#include <xtd/forms/image_list.h>
#include <xtd/forms/context_menu.h>
#include <xtd/forms/tool_bar_button_style.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    class tool_bar;
    /// @endcond
    
    /// @brief Represents a toolbar button.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms  menus_and_toolbars
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::tool_bar_button control.
    /// @include tool_bar.cpp
    /// @remarks xtd::forms::tool_bar_button controls are parented by xtd::forms::tool_bar controls. Common properties to set once the toolbar button has been created are xtd::forms::tool_bar_button::text and xtd::forms::tool_bar_button::image_index. Set the xtd::forms::tool_bar_button::text property of the button to display text beneath or to the right of the image. To assign images to the buttons by creating an xtd::forms::image_list, assigning it to the xtd::forms::tool_bar::image_list property of the toolbar; then assign the image index value to the xtd::forms::tool_bar_button::image_index property of the button.
    /// @remarks To change the appearance of the toolbar buttons assigned to the toolbar, set the xtd::forms::tool_bar::appearance property of the parent toolbar control. The xtd::forms::tool_bar_appearance::flat appearance gives the buttons a flat appearance. As the mouse pointer moves over the buttons, their appearance changes to three-dimensional. Button separators appear as lines rather than spaces between the buttons when the buttons have a flat appearance. If the xtd::forms::tool_bar::appearance property is set to xtd::forms::tool_bar_appearance::normal, the buttons appear raised and three-dimensional, and the separators appear as a gap between the buttons.
    /// @remarks You can assign a xtd::forms::context_menu to a button if the xtd::forms::tool_bar_button::style property is set to xtd::forms::tool_bar_button_style::drop_down. When the button is clicked, the assigned menu is displayed.
    /// @remarks To create a collection of xtd::forms::tool_bar_button controls to display on a xtd::forms::tool_bar, add the buttons individually by using the xtd::forms::tool_bar::buttons().push_back method of the xtd::forms::tool_bar::buttons property. Alternatively, you can add several toolbar buttons using thextd::forms::tool_bar::buttons().push_back_range method.
    class tool_bar_button : public xtd::forms::component {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of xtd::forms::tool_bar_button class.
      /// @remarks A newly created xtd::forms::tool_bar_button has no default xtd::forms::tool_bar_button::text or xtd::drawing::image assigned to it. The button's default style is xtd::tool_bar_button_style::push_button.
      tool_bar_button() = default;
      /// @brief Initializes a new instance of the xtd::forms::tool_bar_button class and displays the assigned text on the button.
      /// @param text The text to display on the new xtd::forms::tool_bar_button.
      /// @remarks The newly created xtd::forms::tool_bar_button has no xtd::drawing::image assigned assigned to it. The button's default style is xtd::tool_bar_button_style::push_button. The text parameter is assigned to the xtd::forms::tool_bar_button::text property and is displayed on the new toolbar button control.
      explicit tool_bar_button(const xtd::ustring& text);
      /// @}
      
      /// @cond
      tool_bar_button(const tool_bar_button&) noexcept = default;
      tool_bar_button(tool_bar_button&&) noexcept = default;
      tool_bar_button& operator=(const tool_bar_button&) noexcept = default;
      bool operator==(const tool_bar_button& other) const noexcept {return data_ == other.data_;}
      bool operator!=(const tool_bar_button& other) const noexcept {return !operator==(other);}
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the control to be displayed in the control toolbar button.
      /// @return A xtd::forms::control to be displayed in the control toolbar button. The default is std::nullopt.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::control.
      std::optional<std::reference_wrapper<xtd::forms::control>> control() const;
      /// @brief Sets the control to be displayed in the control toolbar button.
      /// @param value A xtd::forms::control to be displayed in the control toolbar button. The default is std::nullopt.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::control.
      tool_bar_button& control(const xtd::forms::control& value);
      /// @brief Resets the control to be displayed in the control toolbar button.
      /// @param value nullptr.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::control.
      tool_bar_button& control(std::nullptr_t value);

      /// @brief Gets the menu to be displayed in the drop-down toolbar button.
      /// @return A xtd::forms::context_menu to be displayed in the drop-down toolbar button. The default is std::nullopt.
      /// @remarks You can specify a xtd::forms::context_menu to be displayed when the drop-down button is clicked. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::drop_down_button.
      std::optional<std::reference_wrapper<xtd::forms::context_menu>> drop_down_menu() const;
      /// @brief Sets the menu to be displayed in the drop-down toolbar button.
      /// @param value A xtd::forms::context_menu to be displayed in the drop-down toolbar button. The default is std::nullopt.
      /// @remarks You can specify a xtd::forms::context_menu to be displayed when the drop-down button is clicked. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::drop_down_button.
      tool_bar_button& drop_down_menu(const xtd::forms::context_menu& value);
      /// @brief Resets the menu to be displayed in the drop-down toolbar button.
      /// @param value nullptr.
      /// @remarks You can specify a xtd::forms::context_menu to be displayed when the drop-down button is clicked. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::drop_down_button.
      tool_bar_button& drop_down_menu(std::nullptr_t value);

      /// @brief Gets a value indicating whether the button is enabled.
      /// @return true if the button is enabled; otherwise, false. The default is true.
      /// @remarks When the xtd::forms::tool_bar_button::enabled property is set to false, the toolbar button cannot be clicked, and the button's appearance changes. The xtd::drawing::image and xtd::forms::tool_bar_button::text assigned to the button appear grayed out. If the image or text has multiple colors, they display in a monochromatic gray.
      bool enabled() const;
      /// @brief Sets a value indicating whether the button is enabled.
      /// @param value true if the button is enabled; otherwise, false. The default is true.
      /// @remarks When the xtd::forms::tool_bar_button::enabled property is set to false, the toolbar button cannot be clicked, and the button's appearance changes. The xtd::drawing::image and xtd::forms::tool_bar_button::text assigned to the button appear grayed out. If the image or text has multiple colors, they display in a monochromatic gray.
      tool_bar_button& enabled(bool value);
      
      size_t image_index() const;
      tool_bar_button& image_index(size_t value);

      bool pushed() const;
      tool_bar_button& pushed(bool value);
      
      const xtd::drawing::rectangle& rectangle() const;
      
      const xtd::ustring& text() const;
      tool_bar_button& text(const xtd::ustring& value);

      xtd::forms::tool_bar_button_style style() const;
      tool_bar_button& style(xtd::forms::tool_bar_button_style value);

      bool visible() const;
      tool_bar_button& visible(bool value);
      /// @}
      
      /// @name Methods
      
      /// @{
      static tool_bar_button create_control(const xtd::ustring& text, const xtd::forms::control& control);
      static tool_bar_button create_control(const xtd::forms::control& control);
      static tool_bar_button create_drop_down_button(const xtd::ustring& text, const xtd::forms::context_menu& drop_down_menu);
      static tool_bar_button create_drop_down_button(size_t image_index, const xtd::forms::context_menu& drop_down_menu);
      static tool_bar_button create_drop_down_button(const xtd::ustring& text, size_t image_index, const xtd::forms::context_menu& drop_down_menu);
      static tool_bar_button create_push_button(const xtd::ustring& text);
      static tool_bar_button create_push_button(size_t image_index);
      static tool_bar_button create_push_button(const xtd::ustring& text, size_t image_index);
      static tool_bar_button create_separator();
      static tool_bar_button create_stretchable_separator();
      static tool_bar_button create_toggle_button(const xtd::ustring& text);
      static tool_bar_button create_toggle_button(size_t image_index);
      static tool_bar_button create_toggle_button(const xtd::ustring& text, size_t image_index);
      
    private:
      friend xtd::forms::tool_bar;
      struct data {
        xtd::forms::control* control = nullptr;
        std::optional<std::reference_wrapper<xtd::forms::context_menu>> drop_down_menu;
        bool enabled = true;
        size_t image_index = xtd::forms::image_list::image_collection::npos;
        xtd::drawing::image image_key;
        bool partial_push = false;
        bool pushed = false;
        xtd::drawing::rectangle rectangle;
        xtd::forms::tool_bar_button_style style = xtd::forms::tool_bar_button_style::push_button;
        std::any tag;
        xtd::ustring text;
        xtd::ustring tool_tip_text;
        bool visible = true;
        xtd::forms::tool_bar* parent = nullptr;
        intptr_t handle = 0;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
    
    /// @brief Represents a xtd::forms::tool_bar_item reference.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using tool_bar_button_ref = std::reference_wrapper<tool_bar_button>;
  }
}
