/// @file
/// @brief Contains xtd::forms::tool_bar_button container.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "component.hpp"
#include "const_control_ref.hpp"
#include "context_menu.hpp"
#include "control_ref.hpp"
#include "image_list.hpp"
#include "tool_bar_button_ref.hpp"
#include "tool_bar_button_style.hpp"
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
    /// ```cpp
    /// #include <xtd/forms/tool_bar_button>
    /// ```
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
    class tool_bar_button final : public xtd::forms::component, public xtd::iequatable<tool_bar_button> {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialises a new instance of xtd::forms::tool_bar_button class.
      /// @remarks A newly created xtd::forms::tool_bar_button has no default xtd::forms::tool_bar_button::text or xtd::drawing::image assigned to it. The button's default style is xtd::tool_bar_button_style::push_button.
      tool_bar_button();
      /// @brief Initializes a new instance of the xtd::forms::tool_bar_button class and displays the assigned text on the button.
      /// @param text The text to display on the new xtd::forms::tool_bar_button.
      /// @remarks The newly created xtd::forms::tool_bar_button has no xtd::drawing::image assigned assigned to it. The button's default style is xtd::tool_bar_button_style::push_button. The text parameter is assigned to the xtd::forms::tool_bar_button::text property and is displayed on the new toolbar button control.
      explicit tool_bar_button(const xtd::string& text);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the control to be displayed in the control toolbar button.
      /// @return A xtd::forms::control to be displayed in the control toolbar button. The default is std::nullopt.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::control.
      [[nodiscard]] auto control() const noexcept -> std::optional<xtd::forms::control_ref>;
      /// @brief Sets the control to be displayed in the control toolbar button.
      /// @param value A xtd::forms::control to be displayed in the control toolbar button. The default is std::nullopt.
      /// @return This current instance.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::control.
      auto control(const xtd::forms::control& value) -> tool_bar_button&;
      /// @brief Resets the control to be displayed in the control toolbar button.
      /// @param xtd::null.
      /// @return This current instance.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::control.
      auto control(xtd::null_ptr) -> tool_bar_button&;
      
      /// @brief Gets the menu to be displayed in the drop-down toolbar button.
      /// @return A xtd::forms::context_menu to be displayed in the drop-down toolbar button. The default is std::nullopt.
      /// @remarks You can specify a xtd::forms::context_menu to be displayed when the drop-down button is clicked. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::drop_down_button.
      [[nodiscard]] auto drop_down_menu() const noexcept -> std::optional<xtd::ref<xtd::forms::context_menu>>;
      /// @brief Sets the menu to be displayed in the drop-down toolbar button.
      /// @param value A xtd::forms::context_menu to be displayed in the drop-down toolbar button. The default is std::nullopt.
      /// @return This current instance.
      /// @remarks You can specify a xtd::forms::context_menu to be displayed when the drop-down button is clicked. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::drop_down_button.
      auto drop_down_menu(const xtd::forms::context_menu& value) -> tool_bar_button&;
      /// @brief Resets the menu to be displayed in the drop-down toolbar button.
      /// @param xtd::null.
      /// @return This current instance.
      /// @remarks You can specify a xtd::forms::context_menu to be displayed when the drop-down button is clicked. This property is not used unless the xtd::forms::tool_bar_button::style property value is set to xtd::forms::tool_bar_button_style::drop_down_button.
      auto drop_down_menu(xtd::null_ptr) -> tool_bar_button&;
      
      /// @brief Gets a value indicating whether the button is enabled.
      /// @return `true` if the button is enabled; otherwise, `false`. The default is `true`.
      /// @remarks When the xtd::forms::tool_bar_button::enabled property is set to `false`, the toolbar button cannot be clicked, and the button's appearance changes. The xtd::drawing::image and xtd::forms::tool_bar_button::text assigned to the button appear grayed out. If the image or text has multiple colors, they display in a monochromatic gray.
      [[nodiscard]] auto enabled() const noexcept -> bool;
      /// @brief Sets a value indicating whether the button is enabled.
      /// @param value `true` if the button is enabled; otherwise, `false`. The default is `true`.
      /// @return This current instance.
      /// @remarks When the xtd::forms::tool_bar_button::enabled property is set to `false`, the toolbar button cannot be clicked, and the button's appearance changes. The xtd::drawing::image and xtd::forms::tool_bar_button::text assigned to the button appear grayed out. If the image or text has multiple colors, they display in a monochromatic gray.
      auto enabled(bool value) -> tool_bar_button&;
      
      /// @brief Gets the index value of the image assigned to the button.
      /// @return The index value of the xtd::drawing::image assigned to the toolbar button. The default is xtd::forms::image_list::image_collection::npos.
      /// @remarks The xtd::forms::tool_bar_button::image_index value references the indexed value of the images in an xtd::forms::tool_bar::image_list assigned to the parent xtd::forms::tool_bar control.
      [[nodiscard]] auto image_index() const noexcept -> xtd::usize;
      /// @brief Sets the index value of the image assigned to the button.
      /// @param value The index value of the xtd::drawing::image assigned to the toolbar button. The default is xtd::forms::image_list::image_collection::npos.
      /// @return This current instance.
      /// @remarks The xtd::forms::tool_bar_button::image_index value references the indexed value of the images in an xtd::forms::tool_bar::image_list assigned to the parent xtd::forms::tool_bar control.
      auto image_index(xtd::usize value) -> tool_bar_button&;
      
      /// @brief Gets the name of the button.
      /// @return The name of the button.
      /// @remarks You can use the button name as a key to retrieve the xtd::forms::tool_bar_button from the xtd::forms::tool_bar::buttons collection of a xtd::forms::tool_bar control.
      [[nodiscard]] auto name() const noexcept -> const xtd::string&;
      /// @brief Sets the name of the button.
      /// @param value The name of the button.
      /// @return This current instance.
      /// @remarks You can use the button name as a key to retrieve the xtd::forms::tool_bar_button from the xtd::forms::tool_bar::buttons collection of a xtd::forms::tool_bar control.
      auto name(const xtd::string& value) -> tool_bar_button&;
      
      /// @brief Gets the toolbar control that the toolbar button is assigned to.
      /// @return The xtd::forms::tool_bar control that the xtd::forms::tool_bar_button is assigned to.
      [[nodiscard]] auto parent() const noexcept -> std::optional<xtd::ref<xtd::forms::tool_bar>>;
      
      /// @brief Gets a value indicating whether a toggle-style toolbar button is currently in the pushed state.
      /// @return rue if a toggle-style toolbar button is currently in the pushed state; otherwise, `false`. The default is `false`.
      /// @remarks When xtd::forms::tool_bar_button::pushed is set to `true`, the toolbar button appears sunken or inset relative to the other buttons. This property has no effect unless the xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button_style::toggle_button.
      [[nodiscard]] auto pushed() const noexcept -> bool;
      /// @brief Sets a value indicating whether a toggle-style toolbar button is currently in the pushed state.
      /// @param value rue if a toggle-style toolbar button is currently in the pushed state; otherwise, `false`. The default is `false`.
      /// @return This current instance.
      /// @remarks When xtd::forms::tool_bar_button::pushed is set to `true`, the toolbar button appears sunken or inset relative to the other buttons. This property has no effect unless the xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button_style::toggle_button.
      auto pushed(bool value) -> tool_bar_button&;
      
      /// @brief Gets the bounding rectangle for a toolbar button.
      /// @return The bounding xtd::drawing::rectangle for a toolbar button.
      /// @remarks If the xtd::forms::tool_bar and the current button are both xtd::forms::tool_bar_button::visible, then this property retrieves the bounding rectangle the button is currently contained in.
      [[nodiscard]] auto rectangle() const noexcept -> const xtd::drawing::rectangle&;
      
      /// @brief Gets the style of the toolbar button.
      /// @return One of the xtd::forms::tool_bar_button_style values. The default is xtd::forms::tool_bar_button_style::push_button.
      /// @remarks If the button xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button::drop_down_button you can specify a xtd::forms::menu_contex to be displayed when the drop-down button is pressed. If the style is set to xtd::forms::tool_bar_button_style::separator, the toolbar button appears as a button separator and not as a button. The xtd::forms::tool_bar_button_style::toggle_button style causes the toolbar button to act like a toggle button; it can be in an on or off state. If the style is set to xtd::forms::tool_bar_button_style::stretchable_separator, the toolbar button appears as a stretchable button separator and not as a button. If the button xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button::control you can specify a xtd::forms::control to be displayed when the button.
      [[nodiscard]] auto style() const noexcept -> xtd::forms::tool_bar_button_style;
      /// @brief Sets the style of the toolbar button.
      /// @param value One of the xtd::forms::tool_bar_button_style values. The default is xtd::forms::tool_bar_button_style::push_button.
      /// @return This current instance.
      /// @remarks If the button xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button::drop_down_button you can specify a xtd::forms::menu_contex to be displayed when the drop-down button is pressed. If the style is set to xtd::forms::tool_bar_button_style::separator, the toolbar button appears as a button separator and not as a button. The xtd::forms::tool_bar_button_style::toggle_button style causes the toolbar button to act like a toggle button; it can be in an on or off state. If the style is set to xtd::forms::tool_bar_button_style::stretchable_separator, the toolbar button appears as a stretchable button separator and not as a button. If the button xtd::forms::tool_bar_button::style is set to xtd::forms::tool_bar_button::control you can specify a xtd::forms::control to be displayed when the button.
      auto style(xtd::forms::tool_bar_button_style value) -> tool_bar_button&;
      
      /// @brief Gets the object that contains data about the toolbar button.
      /// @return An xtd::any_object that contains data about the toolbar button. The default is empty.
      /// @remarks Retrieves or assigns the data currently associated with the toolbar button. Any xtd::any_object type can be assigned to this property.
      [[nodiscard]] auto tag() const noexcept -> const xtd::any_object&;
      /// @brief Sets the object that contains data about the toolbar button.
      /// @param value An xtd::any_object that contains data about the toolbar button. The default is empty.
      /// @return This current instance.
      /// @remarks Retrieves or assigns the data currently associated with the toolbar button. Any xtd::any_object type can be assigned to this property.
      auto tag(const xtd::any_object& value) -> tool_bar_button&;
      
      /// @brief Gets the text displayed on the toolbar button.
      /// @return The text displayed on the toolbar button. The default is an empty string ("").
      /// @remarks The default the xtd::forms::tool_bar_button::text property value is an empty string ("") unless you created the control with the xtd::forms::tool_bar constructor that accepts the text string as a parameter. The orientation of the text on the toolbar button is determined by the xtd::forms::tool_bar::text_align property of the button's parentxtd::forms::tool_bar, which can be set to one of the xtd::forms::tool_bar_text_align enumeration values. The orientation is in relation to the image assigned to the button. If no image is assigned to the button, there will be space left for one on the surface of the toolbar button.
      [[nodiscard]] auto text() const noexcept -> const xtd::string&;
      /// @brief Sets the text displayed on the toolbar button.
      /// @param value The text displayed on the toolbar button. The default is an empty string ("").
      /// @return This current instance.
      /// @remarks The default the xtd::forms::tool_bar_button::text property value is an empty string ("") unless you created the control with the xtd::forms::tool_bar constructor that accepts the text string as a parameter. The orientation of the text on the toolbar button is determined by the xtd::forms::tool_bar::text_align property of the button's parentxtd::forms::tool_bar, which can be set to one of the xtd::forms::tool_bar_text_align enumeration values. The orientation is in relation to the image assigned to the button. If no image is assigned to the button, there will be space left for one on the surface of the toolbar button.
      auto text(const xtd::string& value) -> tool_bar_button&;
      
      /// @brief Gets the text that appears as a xtd::forms::tool_tip for the button.
      /// @return The text that is displayed when the mouse pointer moves over the toolbar button. The default is an empty string ("").
      /// @remarks To enable the display of the xtd::forms::tool_tip text when the mouse pointer is moved over the button, set the xtd::forms::tool_bar::show_tool_tips property of the button's parent xtd::forms::tool_bar to `true`.
      [[nodiscard]] auto tool_tip_text() const noexcept -> const xtd::string&;
      /// @brief Sets the text that appears as a xtd::forms::tool_tip for the button.
      /// @param value The text that is displayed when the mouse pointer moves over the toolbar button. The default is an empty string ("").
      /// @return This current instance.
      /// @remarks To enable the display of the xtd::forms::tool_tip text when the mouse pointer is moved over the button, set the xtd::forms::tool_bar::show_tool_tips property of the button's parent xtd::forms::tool_bar to `true`.
      auto tool_tip_text(const xtd::string& value) -> tool_bar_button&;
      
      /// @brief Gets a value indicating whether the toolbar button is visible.
      /// @return `true` if the toolbar button is visible; otherwise, `false`. The default is `true`.
      /// @remarks If the toolbar button is not visible, it will not be displayed on the toolbar, and therefore cannot receive user input.
      [[nodiscard]] auto visible() const noexcept -> bool;
      /// @brief Sets a value indicating whether the toolbar button is visible.
      /// @param value `true` if the toolbar button is visible; otherwise, `false`. The default is `true`.
      /// @return This current instance.
      /// @remarks If the toolbar button is not visible, it will not be displayed on the toolbar, and therefore cannot receive user input.
      auto visible(bool value) -> tool_bar_button&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const tool_bar_button& other) const noexcept -> bool override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      
      /// @brief Returns a string that represents the xtd::forms::tool_bar_button control.
      /// @return A xtd::string that represents the current xtd::forms::tool_bar_button.
      /// @remarks The xtd::forms::tool_bar_button::to_string method returns a string that includes the type and the value of the xtd::forms::tool_bar_button::style and xtd::forms::tool_bar_button::text properties.
      [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create a control toolbar button with specified text and control.
      /// @param text The text displayed on the toolbar button.
      /// @param control A xtd::forms::control to be displayed in the control toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_control(const xtd::string& text, const xtd::forms::control& control) -> tool_bar_button;
      /// @brief A factory to create a control toolbar button with specified control.
      /// @param control A xtd::forms::control to be displayed in the control toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_control(const xtd::forms::control& control) -> tool_bar_button;
      
      /// @brief A factory to create a drop-down toolbar button with specified text and context menu.
      /// @param text The text displayed on the toolbar button.
      /// @param drop_down_menu A xtd::forms::context_menu to be displayed in the drop-down toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_drop_down_button(const xtd::string& text, const xtd::forms::context_menu& drop_down_menu) -> tool_bar_button;
      /// @brief A factory to create a drop-down toolbar button with specified image index and context menu.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @param drop_down_menu A xtd::forms::context_menu to be displayed in the drop-down toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_drop_down_button(xtd::usize image_index, const xtd::forms::context_menu& drop_down_menu) -> tool_bar_button;
      /// @brief A factory to create a drop-down toolbar button with specified text, image index and context menu.
      /// @param text The text displayed on the toolbar button.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @param drop_down_menu A xtd::forms::context_menu to be displayed in the drop-down toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_drop_down_button(const xtd::string& text, xtd::usize image_index, const xtd::forms::context_menu& drop_down_menu) -> tool_bar_button;
      
      /// @brief A factory to create a toolbar button with specified text.
      /// @param text The text displayed on the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_push_button(const xtd::string& text) -> tool_bar_button;
      /// @brief A factory to create a toolbar button with specified image index.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_push_button(xtd::usize image_index) -> tool_bar_button;
      /// @brief A factory to create a toolbar button with specified text and image index.
      /// @param text The text displayed on the toolbar button.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_push_button(const xtd::string& text, xtd::usize image_index) -> tool_bar_button;
      
      /// @brief A factory to create a toolbar separator
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_separator() -> tool_bar_button;
      
      /// @brief A factory to create a toolbar stretchable separator
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_stretchable_separator() -> tool_bar_button;
      
      /// @brief A factory to create a toolbar toggle button with specified text.
      /// @param text The text displayed on the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_toggle_button(const xtd::string& text) -> tool_bar_button;
      /// @brief A factory to create a toolbar toggle button with specified image index.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_toggle_button(xtd::usize image_index) -> tool_bar_button;
      /// @brief A factory to create a toolbar toggle button with specified text and image index.
      /// @param text The text displayed on the toolbar button.
      /// @param image_index The index value of the xtd::drawing::image assigned to the toolbar button.
      /// @return New xtd::forms::tool_bar_button created.
      [[nodiscard]] static auto create_toggle_button(const xtd::string& text, xtd::usize image_index) -> tool_bar_button;
      /// @}
      
    private:
      friend xtd::forms::tool_bar;
      xtd::sptr<data> data_;
    };
  }
}
