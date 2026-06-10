/// @file
/// @brief Contains xtd::forms::tool_bar container.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "border_style.hpp"
#include "button.hpp"
#include "context_menu.hpp"
#include "image_list.hpp"
#include "panel.hpp"
#include "tool_bar_appearance.hpp"
#include "tool_bar_button.hpp"
#include "tool_bar_button_click_event_handler.hpp"
#include "tool_bar_text_align.hpp"
#include <memory>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class form;
    /// @endcond
    
    /// @brief Represents a Windows toolbar.
    /// ```cpp
    /// class forms_export_ tool_bar : public xtd::forms::control
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::tool_bar
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/tool_bar>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    /// @par Appearance
    /// |       | Windows                                          | macOS                                            | Gnome                                            |
    /// | ----- | ------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------ |
    /// | Light |  @image html menus_and_toolbars_tool_bar_w.png   |  @image html menus_and_toolbars_tool_bar_m.png   |  @image html menus_and_toolbars_tool_bar_g.png   |
    /// | Dark  |  @image html menus_and_toolbars_tool_bar_wd.png  |  @image html menus_and_toolbars_tool_bar_md.png  |  @image html menus_and_toolbars_tool_bar_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::tool_bar control.
    /// @include tool_bar.cpp
    /// @remarks xtd::forms::tool_bar controls are used to display xtd::forms::tool_bar_button controls that can appear as a standard button, a toggle-style button, or a drop-down style button. You can assign images to the buttons by creating an xtd::forms::image_list, assigning it to the xtd::forms::tool_bar::image_list property of the toolbar, and assigning the image index value to the xtd::forms::tool_bar_button::image_index property each xtd::forms::tool_bar_button. You can then assign text to be displayed underneath or to the right of the image by setting the xtd::forms::tool_bar_button::text property of the xtd::forms::tool_bar_button.
    /// @remarks Set the xtd::forms::tool_bar::appearance property of the toolbar to xtd::forms::tool_bar_appearance::flat to give the toolbar and its buttons a flat appearance. As the mouse pointer moves over the buttons, their appearance changes to three-dimensional. Toolbar buttons can be divided into logical groups by using separators. A separator is a toolbar button with the xtd::forms::tool_bar_button::style property set to xtd::forms::tool_bar_button_style::separator. Button separators appear as lines rather than spaces between the buttons when the toolbar has a flat appearance. If the xtd::forms::tool_bar::appearance property is set to xtd::forms::tool_bar_appearance::normal, the toolbar buttons appear raised and three-dimensional.
    /// @remarks If you specify a value for the xtd::forms::tool_bar::button_size property, all buttons in the tool bar are restricted to the specified size. Otherwise, the buttons adjust their size depending on their content, and the xtd::forms::tool_bar::button_size property returns the initial size of the largest button.
    /// @remarks To create a collection of xtd::forms::tool_bar_button controls to display on the xtd::forms::tool_bar, add the buttons individually by using the xtd::forms::tool_bar::tool_bar_button_collection::push_back or xtd::forms::tool_bar::tool_bar_button_collection::insert methods of the xtd::forms::tool_bar::buttons property.
    class forms_export_ tool_bar : public control {
      struct data;
      class tool_bar_button_control;
      
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the base type of the xtd::forms::tool_bar::buttons collection.
      using tool_bar_button_collection = xtd::forms::layout::arranged_element_collection<tool_bar_button_ref>;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::tool_bar class.
      /// @remarks A newly created toolbar control is empty; add xtd::forms::tool_bar_button controls by setting the xtd::forms::tool_bar::buttons property.
      tool_bar();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the value that determines the appearance of a toolbar control and its buttons.
      /// @return One of the xtd::forms::tool_bar_appearance values. The default is xtd::forms::tool_bar::appearance::normal.
      /// @remarks The xtd::forms::tool_bar::appearance property affects the appearance of the buttons assigned to the toolbar. When the appearance is set to xtd::forms::tool_bar_appearance::normal, the toolbar's buttons appear three-dimensional and raised. Set the xtd::forms::tool_bar::appearance property of the toolbar to xtd::forms::tool_bar_ppearance::flat to give the toolbar's buttons a flat appearance. As the mouse pointer moves over the flat buttons, they appear raised and three-dimensional. Separators on a xtd::forms::tool_bar with the xtd::forms::tool_bar::appearance property set to xtd::forms::tool_bar_appearance::flat appear as etched lines rather than spaces between the raised buttons. The flat style buttons give your application a more Web-like look.
      [[nodiscard]] virtual auto appearance() const noexcept -> xtd::forms::tool_bar_appearance;
      /// @brief Sets the value that determines the appearance of a toolbar control and its buttons.
      /// @param value One of the xtd::forms::tool_bar_appearance values. The default is xtd::forms::tool_bar::appearance::normal.
      /// @return Current tool_bar instance.
      /// @remarks The xtd::forms::tool_bar::appearance property affects the appearance of the buttons assigned to the toolbar. When the appearance is set to xtd::forms::tool_bar_appearance::normal, the toolbar's buttons appear three-dimensional and raised. Set the xtd::forms::tool_bar::appearance property of the toolbar to xtd::forms::tool_bar_ppearance::flat to give the toolbar's buttons a flat appearance. As the mouse pointer moves over the flat buttons, they appear raised and three-dimensional. Separators on a xtd::forms::tool_bar with the xtd::forms::tool_bar::appearance property set to xtd::forms::tool_bar_appearance::flat appear as etched lines rather than spaces between the raised buttons. The flat style buttons give your application a more Web-like look.
      virtual auto appearance(xtd::forms::tool_bar_appearance value) -> tool_bar&;
      
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      [[nodiscard]] virtual auto border_sides() const noexcept -> xtd::forms::border_sides;
      /// @brief Sets the border sides for the control.
      /// @param value A bitwise combination of the border_sides values. The default is border_style::all.
      /// @return Current tool_bar instance.
      virtual auto border_sides(xtd::forms::border_sides value) -> tool_bar&;
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks The xtd::forms::tool_bar can take on a sunken, three-dimensional appearance when the xtd::forms::tool_bar::border_style property is set to xtd::forms::border_style::fixed_3d. To display a flat thin border around the toolbar control, set the xtd::forms::tool_bar::border_style property to xtd::forms::border_style.fixed_single.
      [[nodiscard]] virtual auto border_style() const noexcept -> xtd::forms::border_style;
      /// @brief Sets the border style for the control.
      /// @param value One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current tool_bar instance.
      /// @remarks The xtd::forms::tool_bar can take on a sunken, three-dimensional appearance when the xtd::forms::tool_bar::border_style property is set to xtd::forms::border_style::fixed_3d. To display a flat thin border around the toolbar control, set the xtd::forms::tool_bar::border_style property to xtd::forms::border_style.fixed_single.
      virtual auto border_style(xtd::forms::border_style value) -> tool_bar&;
      /// @brief Resets the border style for the control.
      /// @param xtd::null.
      /// @return Current tool_bar instance.
      /// @remarks The xtd::forms::tool_bar can take on a sunken, three-dimensional appearance when the xtd::forms::tool_bar::border_style property is set to xtd::forms::border_style::fixed_3d. To display a flat thin border around the toolbar control, set the xtd::forms::tool_bar::border_style property to xtd::forms::border_style.fixed_single.
      virtual auto border_style(xtd::null_ptr) -> tool_bar&;
      
      /// @brief Gets the collection of xtd::forms::tool_bar_button controls assigned to the toolbar control.
      /// @return A xtd::forms::tool_bar::tool_bar_button_collection that contains a collection of xtd::forms::tool_bar_button controls.
      /// @remarks The xtd::forms::tool_bar::item property is a zero-based indexed collection used to hold all the xtd::forms::tool_bar_button controls assigned to the toolbar. Because the property is read-only, it can not be assigned a collection of toolbar buttons directly. Toolbar item can be added or removed by using the methods inherited from the xtd::forms::tool_bar::tool_bar_button_collection class. Use the xtd::forms::tool_bar::tool_bar_button_collection::push_back method to add individual buttons and the xtd::forms::tool_bar::tool_bar_button_collection::erase method to delete a item. Call the xtd::forms::tool_bar::tool_bar_button_collection::clear method to remove all the buttons from the collection.
      [[nodiscard]] virtual auto buttons() const noexcept -> const tool_bar_button_collection&;
      /// @brief Gets the collection of xtd::forms::tool_bar_button controls assigned to the toolbar control.
      /// @return A xtd::forms::tool_bar::tool_bar_button_collection that contains a collection of xtd::forms::tool_bar_button controls.
      /// @remarks The xtd::forms::tool_bar::item property is a zero-based indexed collection used to hold all the xtd::forms::tool_bar_button controls assigned to the toolbar. Because the property is read-only, it can not be assigned a collection of toolbar buttons directly. Toolbar item can be added or removed by using the methods inherited from the xtd::forms::tool_bar::tool_bar_button_collection class. Use the xtd::forms::tool_bar::tool_bar_button_collection::push_back method to add individual buttons and the xtd::forms::tool_bar::tool_bar_button_collection::erase method to delete a item. Call the xtd::forms::tool_bar::tool_bar_button_collection::clear method to remove all the buttons from the collection.
      [[nodiscard]] virtual auto buttons() -> tool_bar_button_collection&;
      
      /// @brief Gets the size of the buttons on the toolbar control.
      /// @return A xtd::drawing::size object that represents the size of the xtd::forms::tool_bar_button controls on the toolbar. The default size has a width of 24 pixels and a height of 22 pixels, or large enough to accommodate the xtd::drawing::image and text, whichever is greater.
      /// @remarks If the xtd::forms::tool_bar::button_size is not set, it is set to its default. Alternatively, a xtd::forms::tool_bar::size is computed to accommodate the largest xtd::drawing::image and text assigned to the xtd::forms::tool_bar_button controls.
      [[nodiscard]] virtual auto button_size() const noexcept -> xtd::drawing::size;
      /// @brief Sets the size of the buttons on the toolbar control.
      /// @param value A xtd::drawing::size object that represents the size of the xtd::forms::tool_bar_button controls on the toolbar. The default size has a width of 24 pixels and a height of 22 pixels, or large enough to accommodate the xtd::drawing::image and text, whichever is greater.
      /// @return Current tool_bar instance.
      /// @remarks If the xtd::forms::tool_bar::button_size is not set, it is set to its default. Alternatively, a xtd::forms::tool_bar::size is computed to accommodate the largest xtd::drawing::image and text assigned to the xtd::forms::tool_bar_button controls.
      virtual auto button_size(const xtd::drawing::size& value) -> tool_bar&;
      /// @brief Resets the size of the buttons on the toolbar control.
      /// @param xtd::null.
      /// @return Current tool_bar instance.
      /// @remarks If the xtd::forms::tool_bar::button_size is not set, it is set to its default. Alternatively, a xtd::forms::tool_bar::size is computed to accommodate the largest xtd::drawing::image and text assigned to the xtd::forms::tool_bar_button controls.
      virtual auto button_size(xtd::null_ptr) -> tool_bar&;
      
      /// @brief Gets a value indicating whether the toolbar displays a divider.
      /// @return `true` if the toolbar displays a divider; otherwise, `false`. The default is `true`.
      /// @remarks Dividers are displayed to help distinguish the toolbar from adjacent controls, such as menus. A divider is displayed as a raised edge along the top of the xtd::forms::tool_bar control.
      /// @note Only on Windows and if xtd::forms::tool_bar::appearance is set to xtd::forms::tool_bar_appearance::system.
      [[nodiscard]] virtual auto divider() const noexcept -> bool;
      /// @brief Sets a value indicating whether the toolbar displays a divider.
      /// @param value `true` if the toolbar displays a divider; otherwise, `false`. The default is `true`.
      /// @return Current tool_bar instance.
      /// @remarks Dividers are displayed to help distinguish the toolbar from adjacent controls, such as menus. A divider is displayed as a raised edge along the top of the xtd::forms::tool_bar control.
      /// @note Only on Windows and if xtd::forms::tool_bar::appearance is set to xtd::forms::tool_bar_appearance::system.
      virtual auto divider(bool value) -> tool_bar&;
      
      /// @brief Gets which control borders are docked to its parent control and determines how a control is resized with its parent.
      /// @return One of the xtd::forms::dock_style values. The default is xtd::forms::dock_style::none.
      /// @remarks Use the xtd::forms::control::dock property to define how a control is automatically resized as its parent control is resized. For example, setting xtd::forms::control::dock to xtd::forms::dock_style::left causes the control to align itself with the left edges of its parent control and to resize as the parent control is resized. Controls are docked in their Z-order, which is the visual layering of controls on a form along the form's Z-axis (depth).
      /// @remarks A control can be docked to one edge of its parent container or can be docked to all edges and fill the parent container.
      /// @remarks Setting the xtd::forms::control::margin property on a docked control has no effect on the distance of the control from the edges of its container.
      /// @note The xtd::forms::control::anchor and xtd::forms::control::dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Inheritors
      /// When overriding the xtd::forms::control::dock property in a derived class, use the base class's xtd::forms::control::dock property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set methods of the xtd::forms::control::dock property; you can override only one if needed.
      [[nodiscard]] auto dock() const noexcept -> xtd::forms::dock_style override;
      /// @brief Sets which control borders are docked to its parent control and determines how a control is resized with its parent.
      /// @param value One of the xtd::forms::dock_style values. The default is xtd::forms::dock_style::none.
      /// @return Current control.
      /// @remarks Use the xtd::forms::control::dock property to define how a control is automatically resized as its parent control is resized. For example, setting xtd::forms::control::dock to xtd::forms::dock_style::left causes the control to align itself with the left edges of its parent control and to resize as the parent control is resized. Controls are docked in their Z-order, which is the visual layering of controls on a form along the form's Z-axis (depth).
      /// @remarks A control can be docked to one edge of its parent container or can be docked to all edges and fill the parent container.
      /// @remarks Setting the xtd::forms::control::margin property on a docked control has no effect on the distance of the control from the edges of its container.
      /// @note The xtd::forms::control::anchor and xtd::forms::control::dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Inheritors
      /// When overriding the xtd::forms::control::dock property in a derived class, use the base class's xtd::forms::control::dock property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set methods of the xtd::forms::control::dock property; you can override only one if needed.
      auto dock(xtd::forms::dock_style value) -> xtd::forms::control& override;
      
      /// @brief Gets a value indicating whether drop-down buttons on a toolbar display down arrows.
      /// @return `true` if drop-down toolbar buttons display down arrows; otherwise, `false`. The default is `true`.
      /// @remarks When xtd::forms::tool_bar::drop_down_arrows is set to `false`, no down arrows display on drop-down style toolbar buttons. When the user clicks the drop-down button on the toolbar, the menu drops down for selection. When the drop-down arrow is displayed, the user must press the down arrow to display the menu.
      [[nodiscard]] virtual auto drop_down_arrows() const noexcept -> bool;
      /// @brief Sets a value indicating whether drop-down buttons on a toolbar display down arrows.
      /// @param value `true` if drop-down toolbar buttons display down arrows; otherwise, `false`. The default is `true`.
      /// @return Current tool_bar instance.
      /// @remarks When xtd::forms::tool_bar::drop_down_arrows is set to `false`, no down arrows display on drop-down style toolbar buttons. When the user clicks the drop-down button on the toolbar, the menu drops down for selection. When the drop-down arrow is displayed, the user must press the down arrow to display the menu.
      virtual auto drop_down_arrows(bool value) -> tool_bar&;
      
      /// @brief Gets the collection of images available to the toolbar button controls.
      /// @return An xtd::forms::image_list that contains images available to the xtd::forms::tool_bar_button controls. The default is empty.
      /// @remarks If you create an xtd::drawing::image_list and assign it to the xtd::forms::toll_bar::image_list property, you can assign an image from the collection to the xtd:forms::tool_bar_button controls by assigning the image's index value to the xtd:forms::tool_bar_button::image_index property of the toolbar button.
      [[nodiscard]] virtual auto image_list() const noexcept -> const xtd::forms::image_list&;
      /// @brief Gets the collection of images available to the toolbar button controls.
      /// @return An xtd::forms::image_list that contains images available to the xtd::forms::tool_bar_button controls. The default is empty.
      /// @remarks If you create an xtd::drawing::image_list and assign it to the xtd::forms::toll_bar::image_list property, you can assign an image from the collection to the xtd:forms::tool_bar_button controls by assigning the image's index value to the xtd:forms::tool_bar_button::image_index property of the toolbar button.
      [[nodiscard]] virtual auto image_list() -> xtd::forms::image_list&;
      /// @brief Sets the collection of images available to the toolbar button controls.
      /// @param value An xtd::forms::image_list that contains images available to the xtd::forms::tool_bar_button controls. The default is empty.
      /// @return Current tool_bar instance.
      /// @remarks If you create an xtd::drawing::image_list and assign it to the xtd::forms::toll_bar::image_list property, you can assign an image from the collection to the xtd:forms::tool_bar_button controls by assigning the image's index value to the xtd:forms::tool_bar_button::image_index property of the toolbar button.
      virtual auto image_list(const xtd::forms::image_list& value) -> tool_bar&;
      
      /// @brief Gets the size of the images in the image list assigned to the toolbar.
      /// @return A xtd::drawing::size that represents the size of the images (in the xtd::forms::image_list) assigned to the xtd::forms::tool_bar.
      [[nodiscard]] virtual auto image_size() const noexcept -> xtd::drawing::size;
      
      /// @brief Gets a value indicating whether the toolbar displays the image for each button.
      /// @return `true` if the toolbar display the image for each button; otherwise, `false`. The default is `true`.
      [[nodiscard]] virtual auto show_icon() const noexcept -> bool;
      /// @brief Sets a value indicating whether the toolbar displays the image for each button.
      /// @param value `true` if the toolbar display the image for each button; otherwise, `false`. The default is `true`.
      /// @return Current tool_bar instance.
      virtual auto show_icon(bool value) -> tool_bar&;
      
      /// @brief Gets a value indicating whether the toolbar displays the text for each button.
      /// @return `true` if the toolbar display the text for each button; otherwise, `false`. The default is `false`.
      [[nodiscard]] virtual auto show_text() const noexcept -> bool;
      /// @brief Sets a value indicating whether the toolbar displays the text for each button.
      /// @param value `true` if the toolbar display the text for each button; otherwise, `false`. The default is `false`.
      /// @return Current tool_bar instance.
      virtual auto show_text(bool value) -> tool_bar&;
      
      /// @brief Gets a value indicating whether the toolbar displays a xtd::forms::tool_tip for each button.
      /// @return `true` if the toolbar display a xtd::forms::tool_tip for each button; otherwise, `false`. The default is `false`.
      /// @remarks To set the text displayed by the xtd::forms::tool_tip, set the xtd::forms::tool_bar_button::tool_tip_text property of each xtd::forms::tool_bar_button on the xtd::forms::tool_bar. To cause the xtd::forms::tool_tip to display as the user moves the mouse pointer over the toolbar button, set the xtd::forms::tool_bar::show_tool_tips property to `true`.
      [[nodiscard]] virtual auto show_tool_tips() const noexcept -> bool;
      /// @brief Sets a value indicating whether the toolbar displays a xtd::forms::tool_tip for each button.
      /// @param value `true` if the toolbar display a xtd::forms::tool_tip for each button; otherwise, `false`. The default is `false`.
      /// @return Current tool_bar instance.
      /// @remarks To set the text displayed by the xtd::forms::tool_tip, set the xtd::forms::tool_bar_button::tool_tip_text property of each xtd::forms::tool_bar_button on the xtd::forms::tool_bar. To cause the xtd::forms::tool_tip to display as the user moves the mouse pointer over the toolbar button, set the xtd::forms::tool_bar::show_tool_tips property to `true`.
      virtual auto show_tool_tips(bool value) -> tool_bar&;
      
      /// @brief Gets the alignment of text in relation to each image displayed on the toolbar button controls.
      /// @return One of the xtd::forms::tool_bar_text_align values. The default is xtd::forms::tool_bar_text_align::underneath.
      /// @remarks The xtd::forms::tool_bar::text can be aligned underneath or to the right of the image displayed on the xtd::forms::tool_bar_button controls.
      [[nodiscard]] virtual auto text_align() const noexcept -> xtd::forms::tool_bar_text_align;
      /// @brief Sets the alignment of text in relation to each image displayed on the toolbar button controls.
      /// @param value One of the xtd::forms::tool_bar_text_align values. The default is xtd::forms::tool_bar_text_align::underneath.
      /// @return Current tool_bar instance.
      /// @remarks The xtd::forms::tool_bar::text can be aligned underneath or to the right of the image displayed on the xtd::forms::tool_bar_button controls.
      virtual auto text_align(xtd::forms::tool_bar_text_align value) -> tool_bar&;
      
      /// @brief Gets a value indicating whether the toolbar buttons wrap to the next line if the toolbar becomes too small to display all the buttons on the same line.
      /// @return `true` if the toolbar buttons wrap to another line if the toolbar becomes too small to display all the buttons on the same line; otherwise, `false`. The default value is `true`.
      /// @note Not yet implemented.
      [[nodiscard]] virtual auto wrappable() const noexcept -> bool;
      /// @brief Gets a value indicating whether the toolbar buttons wrap to the next line if the toolbar becomes too small to display all the buttons on the same line.
      /// @param value `true` if the toolbar buttons wrap to another line if the toolbar becomes too small to display all the buttons on the same line; otherwise, `false`. The default value is `true`.
      /// @return Current tool_bar instance.
      /// @remarks Toolbar buttons can be divided into logical groups by using separators. A separator is a toolbar button with the xtd::forms::tool_bar::style property set to xtd::forms::tool_bar_button_style::separator. If the xtd::forms::tool_bar::wrappable property is set to `true` and the toolbar becomes too small to display all the buttons on the same line, the toolbar is broken into additional lines, with the breaks occurring at the separators. This ensures that button groups stay together. Toolbar buttons that are not in a group can be separated when the toolbar wraps. The toolbar can become too small to display all its buttons on the same line if its parent xtd::forms:form is resized.
      /// @note Not yet implemented.
      virtual auto wrappable(bool value) -> tool_bar&;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when a xtd::forms::tool_bar_button on the xtd::forms::tool_bar is clicked.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<tool_bar, xtd::forms::tool_bar_button_click_event_handler> button_click;
      
      /// @brief Occurs when a drop-down style xtd::forms::tool_bar_button or its down arrow is clicked.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<tool_bar, xtd::forms::tool_bar_button_click_event_handler> button_drop_down;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::tool_bar.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create() -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified image collection.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::image_list::image_collection& image_collection) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified image collection, and name.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @param name The name of the xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::image_list::image_collection& image_collection, const xtd::string& name) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified style.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(xtd::forms::dock_style style) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified style, and image collection.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(xtd::forms::dock_style style, const xtd::forms::image_list::image_collection& image_collection) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified style, image collection, and name.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @param name The name of the xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(xtd::forms::dock_style style, const xtd::forms::image_list::image_collection& image_collection, const xtd::string& name) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const tool_bar_button_collection& buttons) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified image collection.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::image_list::image_collection& image_collection, const tool_bar_button_collection& buttons) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified image collection, and name.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @param name The name of the xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::image_list::image_collection& image_collection, const tool_bar_button_collection& buttons, const xtd::string& name) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified style.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(xtd::forms::dock_style style, const tool_bar_button_collection& buttons) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified style, and image collection.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(xtd::forms::dock_style style, const xtd::forms::image_list::image_collection& image_collection, const tool_bar_button_collection& buttons) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified style, image collection, and name.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @param name The name of the xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(xtd::forms::dock_style style, const xtd::forms::image_list::image_collection& image_collection, const tool_bar_button_collection& buttons, const xtd::string& name) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent, and image collection.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::forms::image_list::image_collection& image_collection) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent, image collection, and name.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @param name The name of the xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::forms::image_list::image_collection& image_collection, const xtd::string& name) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent, and style.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::forms::dock_style style) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent, style, and image collection.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::forms::dock_style style, const xtd::forms::image_list::image_collection& image_collection) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent, style, image collection, and name.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @param name The name of the xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::forms::dock_style style, const xtd::forms::image_list::image_collection& image_collection, const xtd::string& name) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const tool_bar_button_collection& buttons) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent, and image collection.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::forms::image_list::image_collection& image_collection, const tool_bar_button_collection& buttons) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent, image collection, and name.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @param name The name of the xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::forms::image_list::image_collection& image_collection, const tool_bar_button_collection& buttons, const xtd::string& name) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent, and style.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::forms::dock_style style, const tool_bar_button_collection& buttons) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent, style, and image collection.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::forms::dock_style style, const xtd::forms::image_list::image_collection& image_collection, const tool_bar_button_collection& buttons) -> tool_bar;
      /// @brief A factory to create an xtd::forms::tool_bar with specified parent, style, image collection, and name.
      /// @param parent The parent that contains the new created xtd::forms::tool_bar.
      /// @param style One of the xtd::forms::dock_style values.
      /// @param image_collection An xtd::forms::image_list::image_collection that contains images available to the xtd::forms::tool_bar_button controls.
      /// @param name The name of the xtd::forms::tool_bar.
      /// @return New xtd::forms::tool_bar created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::forms::dock_style style, const xtd::forms::image_list::image_collection& image_collection, const tool_bar_button_collection& buttons, const xtd::string& name) -> tool_bar;
      /// @}
      
    protected:
      friend tool_bar_button;
      friend form;
      
      /// @name Protetced properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      [[nodiscard]] auto default_font() const noexcept -> xtd::drawing::font override;
      [[nodiscard]] auto default_size() const noexcept -> xtd::drawing::size override;
      /// @}
      
      /// @name Protetced methods
      
      /// @{
      /// @brief Raises the xtd::forms::tool_bar::button_click event.
      /// @param e A xtd::forms::tool_bar_button_click_event_args that contains the event data.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      /// @remarks The xtd::forms::tool_bar::on_button_click method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::tool_bar::on_button_click in a derived class, be sure to call the base class's xtd::forms::tool_bar::on_button_click method so that registered delegates receive the event.
      auto on_button_click(const xtd::forms::tool_bar_button_click_event_args& e) -> void;
      
      /// @brief Raises the xtd::forms::tool_bar::button_drop_down event.
      /// @param e A xtd::forms::tool_bar_button_click_event_args that contains the event data.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      /// @remarks The xtd::forms::tool_bar::on_button_click method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::tool_bar::on_button_drop_down in a derived class, be sure to call the base class's xtd::forms::tool_bar::on_button_drop_down method so that registered delegates receive the event.
      auto on_button_drop_down(const xtd::forms::tool_bar_button_click_event_args& e) -> void;
      
      auto on_handle_created(const xtd::event_args& e) -> void override;
      auto on_handle_destroyed(const xtd::event_args& e) -> void override;
      auto on_paint(xtd::forms::paint_event_args& e) -> void override;
      auto on_resize(const xtd::event_args& e) -> void override;
      auto wnd_proc(xtd::forms::message& message) -> void override;
      /// @}
      
    private:
      auto fill() -> void;
      
      [[nodiscard]] auto horizontal() const noexcept -> bool;
      [[nodiscard]] auto system_tool_bar() const noexcept -> bool;
      auto system_tool_bar(bool value) -> tool_bar&;
      
      auto resize_stretchable_separtors() -> void;
      auto update_toolbar_button_control(xtd::intptr handle, const xtd::string& text, const xtd::string& tool_tip_text, const xtd::drawing::image& image, bool pushed, bool enabled, bool visible) -> void;
      
      auto wm_click(const xtd::forms::message& message) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
