/// @file
/// @brief Contains xtd::forms::tool_bar_button container.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "component"
#include "const_control_ref"
#include "context_menu"
#include "control_ref"
#include "image_list"
#include "tool_bar_button_ref"
#include "tool_bar_button_style"
#include <xtd/event>
#include <xtd/event_handler>
#include <xtd/iequatable>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    class tool_bar;
    /// @endcond
    
    /// @brief Represents a toolbar button.
    /// @par Header
    /// @code #include <xtd/forms/tool_bar_button> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::tool_bar_button control.
    /// @include tool_bar.cpp
    /// @remarks xtd::forms::tool_bar_button controls are parented by xtd::forms::tool_bar controls. Common properties to set once the toolbar button has been created are xtd::forms::tool_bar_button::text and xtd::forms::tool_bar_button::image_index. Set the xtd::forms::tool_bar_button::text property of the button to display text beneath or to the right of the image. To assign images to the buttons by creating an xtd::forms::image_list, assigning it to the xtd::forms::tool_bar::image_list property of the toolbar; then assign the image index value to the xtd::forms::tool_bar_button::image_index property of the button.
    /// @remarks To change the appearance of the toolbar buttons assigned to the toolbar, set the xtd::forms::tool_bar::appearance property of the parent toolbar control. The xtd::forms::tool_bar_appearance::flat appearance gives the buttons a flat appearance. As the mouse pointer moves over the buttons, their appearance changes to three-dimensional. Button separators appear as lines rather than spaces between the buttons when the buttons have a flat appearance. If the xtd::forms::tool_bar::appearance property is set to xtd::forms::tool_bar_appearance::normal, the buttons appear raised and three-dimensional, and the separators appear as a gap between the buttons.
    /// @remarks You can assign a xtd::forms::context_menu to a button if the xtd::forms::tool_bar_button::style property is set to xtd::forms::tool_bar_button_style::drop_down. When the button is clicked, the assigned menu is displayed.
    /// @remarks To create a collection of xtd::forms::tool_bar_button controls to display on a xtd::forms::tool_bar, add the buttons individually by using the xtd::forms::tool_bar::tool_bar_button_collection::push_back method of the xtd::forms::tool_bar::buttons property. Alternatively, you can add several toolbar buttons using the xtd::forms::tool_bar::tool_bar_button_collection.push_back_range method.
    class tool_bar_button : public xtd::forms::component, public xtd::iequatable<tool_bar_button> {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of xtd::forms::tool_bar_button class.
      /// @remarks A newly created xtd::forms::tool_bar_button has no default xtd::forms::tool_bar_button::text or xtd::drawing::image assigned to it. The button's default style is xtd::tool_bar_button_style::push_button.
      tool_bar_button();
      /// @brief Initializes a new instance of the xtd::forms::tool_bar_button class and displays the assigned text on the button.
      /// @param text The text to display on the new xtd::forms::tool_bar_button.
      /// @remarks The newly created xtd::forms::tool_bar_button has no xtd::drawing::image assigned assigned to it. The button's default style is xtd::tool_bar_button_style::push_button. The text parameter is assigned to the xtd::forms::tool_bar_button::text property and is displayed on the new toolbar button control.
      explicit tool_bar_button(const xtd::ustring& text);
      /// @}
      
      /// @cond
      tool_bar_button(const tool_bar_button&) noexcept = default;
      tool_bar_button(tool_bar_button&&) noexcept = default;
      tool_bar_button& operator =(const tool_bar_button&) noexcept = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the control to be displayed in the control toolbar button.
      /// @return A xtd::forms::control to be displayed in the control toolbar button. The default is std::nullopt.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::control.
      std::optional<xtd::forms::control_ref> control() const noexcept;
      /// @brief Sets the control to be displayed in the control toolbar button.
      /// @param value A xtd::forms::control to be displayed in the control toolbar button. The default is std::nullopt.
      /// @return This current instance.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::control.
      tool_bar_button& control(const xtd::forms::control& value);
      /// @brief Resets the control to be displayed in the control toolbar button.
      /// @param value nullptr.
      /// @return This current instance.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::control.
      tool_bar_button& control(std::nullptr_t value);
      
      /// @brief Gets the menu to be displayed in the drop-down toolbar button.
      /// @return A xtd::forms::context_menu to be displayed in the drop-down toolbar button. The default is std::nullopt.
      /// @remarks You can specify a xtd::forms::context_menu to be displayed when the drop-down button is clicked. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::drop_down_button.
      std::optional<std::reference_wrapper<xtd::forms::context_menu>> drop_down_menu() const noexcept;
      /// @brief Sets the menu to be displayed in the drop-down toolbar button.
      /// @param value A xtd::forms::context_menu to be displayed in the drop-down toolbar button. The default is std::nullopt.
      /// @return This current instance.
      /// @remarks You can specify a xtd::forms::context_menu to be displayed when the drop-down button is clicked. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::drop_down_button.
      tool_bar_button& drop_down_menu(const xtd::forms::context_menu& value);
      /// @brief Resets the menu to be displayed in the drop-down toolbar button.
      /// @param value nullptr.
      /// @return This current instance.
      /// @remarks You can specify a xtd::forms::context_menu to be displayed when the drop-down button is clicked. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::drop_down_button.
      tool_bar_button& drop_down_menu(std::nullptr_t value);
      
      /// @brief Gets a value indicating whether the button is enabled.
      /// @return true if the button is enabled; otherwise, false. The default is true.
      /// @remarks When the xtd::forms::tool_bar_button::enabled property is set to false, the toolbar button cannot be clicked, and the button's appearance changes. The xtd::drawing::image and xtd::forms::tool_bar_button::text assigned to the button appear grayed out. If the image or text has multiple colors, they display in a monochromatic gray.
      bool enabled() const noexcept;
      /// @brief Sets a value indicating whether the button is enabled.
      /// @param value true if the button is enabled; otherwise, false. The default is true.
      /// @return This current instance.
      /// @remarks When the xtd::forms::tool_bar_button::enabled property is set to false, the toolbar button cannot be clicked, and the button's appearance changes. The xtd::drawing::image and xtd::forms::tool_bar_button::text assigned to the button appear grayed out. If the image or text has multiple colors, they display in a monochromatic gray.
      tool_bar_button& enabled(bool value);
      
      /// @brief Gets the index value of the image assigned to the button.
      /// @return The index value of the xtd::drawing::image assigned to the toolbar button. The default is xtd::forms::image_list::image_collection::npos.
      /// @remarks The xtd::forms::tool_bar_button::image_index value references the indexed value of the images in an xtd::forms::tool_bar::image_list assigned to the parent xtd::forms::tool_bar control.
      size_t image_index() const noexcept;
      /// @brief Sets the index value of the image assigned to the button.
      /// @param value The index value of the xtd::drawing::image assigned to the toolbar button. The default is xtd::forms::image_list::image_collection::npos.
      /// @return This current instance.
      /// @remarks The xtd::forms::tool_bar_button::image_index value references the indexed value of the images in an xtd::forms::tool_bar::image_list assigned to the parent xtd::forms::tool_bar control.
      tool_bar_button& image_index(size_t value);
      
      /// @brief Gets the name of the button.
      /// @return The name of the button.
      /// @remarks You can use the button name as a key to retrieve the xtd::forms::tool_bar_button from the xtd::forms::tool_bar::buttons collection of a xtd::forms::tool_bar control.
      const xtd::ustring& name() const noexcept;
      /// @brief Sets the name of the button.
      /// @param value The name of the button.
      /// @return This current instance.
      /// @remarks You can use the button name as a key to retrieve the xtd::forms::tool_bar_button from the xtd::forms::tool_bar::buttons collection of a xtd::forms::tool_bar control.
      tool_bar_button& name(const xtd::ustring& value);
      
      /// @brief Gets the toolbar control that the toolbar button is assigned to.
      /// @return The xtd::forms::tool_bar control that the xtd::forms::tool_bar_button is assigned to.
      std::optional<std::reference_wrapper<xtd::forms::tool_bar>> parent() const noexcept;
      
      /// @brief Gets a value indicating whether a toggle-style toolbar button is currently in the pushed state.
      /// @return rue if a toggle-style toolbar button is currently in the pushed state; otherwise, false. The default is false.
      /// @remarks When xtd::forms::tool_bar_button::pushed is set to true, the toolbar button appears sunken or inset relative to the other buttons. This property has no effect unless the xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button_style::toggle_button.
      bool pushed() const noexcept;
      /// @brief Sets a value indicating whether a toggle-style toolbar button is currently in the pushed state.
      /// @param value rue if a toggle-style toolbar button is currently in the pushed state; otherwise, false. The default is false.
      /// @return This current instance.
      /// @remarks When xtd::forms::tool_bar_button::pushed is set to true, the toolbar button appears sunken or inset relative to the other buttons. This property has no effect unless the xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button_style::toggle_button.
      tool_bar_button& pushed(bool value);
      
      /// @brief Gets the bounding rectangle for a toolbar button.
      /// @return The bounding xtd::drawing::rectangle for a toolbar button.
      /// @remarks If the xtd::forms::tool_bar and the current button are both xtd::forms::tool_bar_button::visible, then this property retrieves the bounding rectangle the button is currently contained in.
      const xtd::drawing::rectangle& rectangle() const noexcept;
      
      /// @brief Gets the style of the toolbar button.
      /// @return One of the xtd::forms::tool_bar_button_style values. The default is xtd::forms::tool_bar_button_style::push_button.
      /// @remarks If the button xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button::drop_down_button you can specify a xtd::forms::menu_contex to be displayed when the drop-down button is pressed. If the style is set to xtd::forms::tool_bar_button_style::separator, the toolbar button appears as a button separator and not as a button. The xtd::forms::tool_bar_button_style::toggle_button style causes the toolbar button to act like a toggle button; it can be in an on or off state. If the style is set to xtd::forms::tool_bar_button_style::stretchable_separator, the toolbar button appears as a stretchable button separator and not as a button. If the button xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button::control you can specify a xtd::forms::control to be displayed when the button.
      xtd::forms::tool_bar_button_style style() const noexcept;
      /// @brief Sets the style of the toolbar button.
      /// @param value One of the xtd::forms::tool_bar_button_style values. The default is xtd::forms::tool_bar_button_style::push_button.
      /// @return This current instance.
      /// @remarks If the button xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button::drop_down_button you can specify a xtd::forms::menu_contex to be displayed when the drop-down button is pressed. If the style is set to xtd::forms::tool_bar_button_style::separator, the toolbar button appears as a button separator and not as a button. The xtd::forms::tool_bar_button_style::toggle_button style causes the toolbar button to act like a toggle button; it can be in an on or off state. If the style is set to xtd::forms::tool_bar_button_style::stretchable_separator, the toolbar button appears as a stretchable button separator and not as a button. If the button xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button::control you can specify a xtd::forms::control to be displayed when the button.
      tool_bar_button& style(xtd::forms::tool_bar_button_style value);
      
      /// @brief Gets the object that contains data about the toolbar button.
      /// @return An std::any that contains data about the toolbar button. The default is empty.
      /// @remarks Retrieves or assigns the data currently associated with the toolbar button. Any std::any type can be assigned to this property.
      std::any tag() const noexcept;
      /// @brief Sets the object that contains data about the toolbar button.
      /// @param value An std::any that contains data about the toolbar button. The default is empty.
      /// @return This current instance.
      /// @remarks Retrieves or assigns the data currently associated with the toolbar button. Any std::any type can be assigned to this property.
      tool_bar_button& tag(std::any value);
      
      /// @brief Gets the text displayed on the toolbar button.
      /// @return The text displayed on the toolbar button. The default is an empty string ("").
      /// @remarks The default the xtd::forms::tool_bar_button::text property value is an empty string ("") unless you created the control with the xtd::forms::tool_bar constructor that accepts the text string as a parameter. The orientation of the text on the toolbar button is determined by the xtd::forms::tool_bar::text_align property of the button's parentxtd::forms::tool_bar, which can be set to one of the xtd::forms::tool_bar_text_align enumeration values. The orientation is in relation to the image assigned to the button. If no image is assigned to the button, there will be space left for one on the surface of the toolbar button.
      const xtd::ustring& text() const noexcept;
      /// @brief Sets the text displayed on the toolbar button.
      /// @param value The text displayed on the toolbar button. The default is an empty string ("").
      /// @return This current instance.
      /// @remarks The default the xtd::forms::tool_bar_button::text property value is an empty string ("") unless you created the control with the xtd::forms::tool_bar constructor that accepts the text string as a parameter. The orientation of the text on the toolbar button is determined by the xtd::forms::tool_bar::text_align property of the button's parentxtd::forms::tool_bar, which can be set to one of the xtd::forms::tool_bar_text_align enumeration values. The orientation is in relation to the image assigned to the button. If no image is assigned to the button, there will be space left for one on the surface of the toolbar button.
      tool_bar_button& text(const xtd::ustring& value);
      
      /// @brief Gets the text that appears as a xtd::forms::tool_tip for the button.
      /// @return The text that is displayed when the mouse pointer moves over the toolbar button. The default is an empty string ("").
      /// @remarks To enable the display of the xtd::forms::tool_tip text when the mouse pointer is moved over the button, set the xtd::forms::tool_bar::show_tool_tips property of the button's parent xtd::forms::tool_bar to true.
      const xtd::ustring& tool_tip_text() const noexcept;
      /// @brief Sets the text that appears as a xtd::forms::tool_tip for the button.
      /// @param value The text that is displayed when the mouse pointer moves over the toolbar button. The default is an empty string ("").
      /// @return This current instance.
      /// @remarks To enable the display of the xtd::forms::tool_tip text when the mouse pointer is moved over the button, set the xtd::forms::tool_bar::show_tool_tips property of the button's parent xtd::forms::tool_bar to true.
      tool_bar_button& tool_tip_text(const xtd::ustring& value);
      
      /// @brief Gets a value indicating whether the toolbar button is visible.
      /// @return true if the toolbar button is visible; otherwise, false. The default is true.
      /// @remarks If the toolbar button is not visible, it will not be displayed on the toolbar, and therefore cannot receive user input.
      bool visible() const noexcept;
      /// @brief Sets a value indicating whether the toolbar button is visible.
      /// @param value true if the toolbar button is visible; otherwise, false. The default is true.
      /// @return This current instance.
      /// @remarks If the toolbar button is not visible, it will not be displayed on the toolbar, and therefore cannot receive user input.
      tool_bar_button& visible(bool value);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create a control toolbar button with specified text and control.
      /// @param text The text displayed on the toolbar button.
      /// @param control A xtd::forms::control to be displayed in the control toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_control(const xtd::ustring& text, const xtd::forms::control& control);
      /// @brief A factory to create a control toolbar button with specified control.
      /// @param control A xtd::forms::control to be displayed in the control toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_control(const xtd::forms::control& control);
      
      /// @brief A factory to create a drop-down toolbar button with specified text and context menu.
      /// @param text The text displayed on the toolbar button.
      /// @param drop_down_menu A xtd::forms::context_menu to be displayed in the drop-down toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_drop_down_button(const xtd::ustring& text, const xtd::forms::context_menu& drop_down_menu);
      /// @brief A factory to create a drop-down toolbar button with specified image index and context menu.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @param drop_down_menu A xtd::forms::context_menu to be displayed in the drop-down toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_drop_down_button(size_t image_index, const xtd::forms::context_menu& drop_down_menu);
      /// @brief A factory to create a drop-down toolbar button with specified text, image index and context menu.
      /// @param text The text displayed on the toolbar button.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @param drop_down_menu A xtd::forms::context_menu to be displayed in the drop-down toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_drop_down_button(const xtd::ustring& text, size_t image_index, const xtd::forms::context_menu& drop_down_menu);
      
      /// @brief A factory to create a toolbar button with specified text.
      /// @param text The text displayed on the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_push_button(const xtd::ustring& text);
      /// @brief A factory to create a toolbar button with specified image index.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_push_button(size_t image_index);
      /// @brief A factory to create a toolbar button with specified text and image index.
      /// @param text The text displayed on the toolbar button.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_push_button(const xtd::ustring& text, size_t image_index);
      
      /// @brief A factory to create a toolbar separator
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_separator();
      
      /// @brief A factory to create a toolbar stretchable separator
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_stretchable_separator();
      
      /// @brief A factory to create a toolbar toggle button with specified text.
      /// @param text The text displayed on the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_toggle_button(const xtd::ustring& text);
      /// @brief A factory to create a toolbar toggle button with specified image index.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_toggle_button(size_t image_index);
      /// @brief A factory to create a toolbar toggle button with specified text and image index.
      /// @param text The text displayed on the toolbar button.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      static tool_bar_button create_toggle_button(const xtd::ustring& text, size_t image_index);
      
      bool equals(const tool_bar_button& other) const noexcept override;
      
      /// @brief Returns a string that represents the xtd::forms::tool_bar_button control.
      /// @return A xtd::ustring that represents the current xtd::forms::tool_bar_button.
      /// @remarks The xtd::forms::tool_bar_button::to_string method returns a string that includes the type and the value of the xtd::forms::tool_bar_button::style and xtd::forms::tool_bar_button::text properties.
      xtd::ustring to_string() const noexcept override;
      
    private:
      friend xtd::forms::tool_bar;
      std::shared_ptr<data> data_;
    };
  }
}
