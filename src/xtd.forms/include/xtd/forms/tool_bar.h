/// @file
/// @brief Contains xtd::forms::tool_bar container.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "border_style"
#include "button"
#include "context_menu"
#include "image_list"
#include "panel"
#include "tool_bar_appearance"
#include "tool_bar_button"
#include "tool_bar_button_click_event_handler"
#include "tool_bar_text_align"
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
    /// @code
    /// class forms_export_ tool_bar : public xtd::forms::control
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::tool_bar
    /// @par Header
    /// @code #include <xtd/forms/tool_bar> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    /// @par Appearance
    /// |       | Windows                                          | macOS                                            | Gnome                                            |
    /// | ----- | ------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------ |
    /// | Light |  @image html menus_and_toolbars_tool_bar_w.png   |  @image html menus_and_toolbars_tool_bar_m.png   |  @image html menus_and_toolbars_tool_bar_g.png   |
    /// | Dark  |  @image html menus_and_toolbars_tool_bar_wd.png  |  @image html menus_and_toolbars_tool_bar_md.png  |  @image html menus_and_toolbars_tool_bar_gd.png  |
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
      /// @name Alias
      
      /// @{
      /// @brief Represents the base type of the xtd::forms::tool_bar::buttons collection.
      using tool_bar_button_collection = xtd::forms::layout::arranged_element_collection<tool_bar_button_ref>;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::tool_bar class.
      /// @remarks A newly created toolbar control is empty; add xtd::forms::tool_bar_button controls by setting the xtd::forms::tool_bar::buttons property.
      tool_bar();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the value that determines the appearance of a toolbar control and its buttons.
      /// @return One of the xtd::forms::tool_bar_appearance values. The default is xtd::forms::tool_bar::appearance::normal.
      /// @remarks The xtd::forms::tool_bar::appearance property affects the appearance of the buttons assigned to the toolbar. When the appearance is set to xtd::forms::tool_bar_appearance::normal, the toolbar's buttons appear three-dimensional and raised. Set the xtd::forms::tool_bar::appearance property of the toolbar to xtd::forms::tool_bar_ppearance::flat to give the toolbar's buttons a flat appearance. As the mouse pointer moves over the flat buttons, they appear raised and three-dimensional. Separators on a xtd::forms::tool_bar with the xtd::forms::tool_bar::appearance property set to xtd::forms::tool_bar_appearance::flat appear as etched lines rather than spaces between the raised buttons. The flat style buttons give your application a more Web-like look.
      virtual xtd::forms::tool_bar_appearance appearance() const noexcept;
      /// @brief Sets the value that determines the appearance of a toolbar control and its buttons.
      /// @param value One of the xtd::forms::tool_bar_appearance values. The default is xtd::forms::tool_bar::appearance::normal.
      /// @return Current tool_bar instance.
      /// @remarks The xtd::forms::tool_bar::appearance property affects the appearance of the buttons assigned to the toolbar. When the appearance is set to xtd::forms::tool_bar_appearance::normal, the toolbar's buttons appear three-dimensional and raised. Set the xtd::forms::tool_bar::appearance property of the toolbar to xtd::forms::tool_bar_ppearance::flat to give the toolbar's buttons a flat appearance. As the mouse pointer moves over the flat buttons, they appear raised and three-dimensional. Separators on a xtd::forms::tool_bar with the xtd::forms::tool_bar::appearance property set to xtd::forms::tool_bar_appearance::flat appear as etched lines rather than spaces between the raised buttons. The flat style buttons give your application a more Web-like look.
      virtual tool_bar& appearance(xtd::forms::tool_bar_appearance value);
      
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      virtual forms::border_sides border_sides() const noexcept;
      /// @brief Sets the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      /// @return Current tool_bar instance.
      virtual tool_bar& border_sides(forms::border_sides border_sides);
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks The xtd::forms::tool_bar can take on a sunken, three-dimensional appearance when the xtd::forms::tool_bar::border_style property is set to xtd::forms::border_style::fixed_3d. To display a flat thin border around the toolbar control, set the xtd::forms::tool_bar::border_style property to xtd::forms::border_style.fixed_single.
      virtual forms::border_style border_style() const noexcept;
      /// @brief Sets the border style for the control.
      /// @param value One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current tool_bar instance.
      /// @remarks The xtd::forms::tool_bar can take on a sunken, three-dimensional appearance when the xtd::forms::tool_bar::border_style property is set to xtd::forms::border_style::fixed_3d. To display a flat thin border around the toolbar control, set the xtd::forms::tool_bar::border_style property to xtd::forms::border_style.fixed_single.
      virtual tool_bar& border_style(forms::border_style value);
      /// @brief Reets the border style for the control.
      /// @param value nullptr.
      /// @return Current tool_bar instance.
      /// @remarks The xtd::forms::tool_bar can take on a sunken, three-dimensional appearance when the xtd::forms::tool_bar::border_style property is set to xtd::forms::border_style::fixed_3d. To display a flat thin border around the toolbar control, set the xtd::forms::tool_bar::border_style property to xtd::forms::border_style.fixed_single.
      virtual xtd::forms::tool_bar& border_style(std::nullptr_t value);
      
      /// @brief Gets the collection of xtd::forms::tool_bar_button controls assigned to the toolbar control.
      /// @return A xtd::forms::tool_bar::tool_bar_button_collection that contains a collection of xtd::forms::tool_bar_button controls.
      /// @remarks The xtd::forms::tool_bar::item property is a zero-based indexed collection used to hold all the xtd::forms::tool_bar_button controls assigned to the toolbar. Because the property is read-only, it can not be assigned a collection of toolbar buttons directly. Toolbar item can be added or removed by using the methods inherited from the xtd::forms::tool_bar::tool_bar_button_collection class. Use the xtd::forms::tool_bar::tool_bar_button_collection::push_back method to add individual buttons and the xtd::forms::tool_bar::tool_bar_button_collection::erase method to delete a item. Call the xtd::forms::tool_bar::tool_bar_button_collection::clear method to remove all the buttons from the collection.
      const tool_bar_button_collection& buttons() const noexcept;
      /// @brief Gets the collection of xtd::forms::tool_bar_button controls assigned to the toolbar control.
      /// @return A xtd::forms::tool_bar::tool_bar_button_collection that contains a collection of xtd::forms::tool_bar_button controls.
      /// @remarks The xtd::forms::tool_bar::item property is a zero-based indexed collection used to hold all the xtd::forms::tool_bar_button controls assigned to the toolbar. Because the property is read-only, it can not be assigned a collection of toolbar buttons directly. Toolbar item can be added or removed by using the methods inherited from the xtd::forms::tool_bar::tool_bar_button_collection class. Use the xtd::forms::tool_bar::tool_bar_button_collection::push_back method to add individual buttons and the xtd::forms::tool_bar::tool_bar_button_collection::erase method to delete a item. Call the xtd::forms::tool_bar::tool_bar_button_collection::clear method to remove all the buttons from the collection.
      tool_bar_button_collection& buttons();
      
      /// @brief Gets the size of the buttons on the toolbar control.
      /// @return A xtd::drawing::size object that represents the size of the xtd::forms::tool_bar_button controls on the toolbar. The default size has a width of 24 pixels and a height of 22 pixels, or large enough to accommodate the xtd::drawing::image and text, whichever is greater.
      /// @remarks If the xtd::forms::tool_bar::button_size is not set, it is set to its default. Alternatively, a xtd::forms::tool_bar::size is computed to accommodate the largest xtd::drawing::image and text assigned to the xtd::forms::tool_bar_button controls.
      virtual xtd::drawing::size button_size() const noexcept;
      /// @brief Sets the size of the buttons on the toolbar control.
      /// @param value A xtd::drawing::size object that represents the size of the xtd::forms::tool_bar_button controls on the toolbar. The default size has a width of 24 pixels and a height of 22 pixels, or large enough to accommodate the xtd::drawing::image and text, whichever is greater.
      /// @return Current tool_bar instance.
      /// @remarks If the xtd::forms::tool_bar::button_size is not set, it is set to its default. Alternatively, a xtd::forms::tool_bar::size is computed to accommodate the largest xtd::drawing::image and text assigned to the xtd::forms::tool_bar_button controls.
      virtual tool_bar& button_size(const xtd::drawing::size& value);
      /// @brief Resets the size of the buttons on the toolbar control.
      /// @param value nullptr.
      /// @return Current tool_bar instance.
      /// @remarks If the xtd::forms::tool_bar::button_size is not set, it is set to its default. Alternatively, a xtd::forms::tool_bar::size is computed to accommodate the largest xtd::drawing::image and text assigned to the xtd::forms::tool_bar_button controls.
      virtual tool_bar& button_size(std::nullptr_t value);
      
      /// @brief Gets a value indicating whether the toolbar displays a divider.
      /// @return true if the toolbar displays a divider; otherwise, false. The default is true.
      /// @remarks Dividers are displayed to help distinguish the toolbar from adjacent controls, such as menus. A divider is displayed as a raised edge along the top of the xtd::forms::tool_bar control.
      /// @note Only on Windows and if xtd::forms::tool_bar::appearance is set to xtd::forms::tool_bar_appearance::system.
      virtual bool divider() const noexcept;
      /// @brief Sets a value indicating whether the toolbar displays a divider.
      /// @param value true if the toolbar displays a divider; otherwise, false. The default is true.
      /// @return Current tool_bar instance.
      /// @remarks Dividers are displayed to help distinguish the toolbar from adjacent controls, such as menus. A divider is displayed as a raised edge along the top of the xtd::forms::tool_bar control.
      /// @note Only on Windows and if xtd::forms::tool_bar::appearance is set to xtd::forms::tool_bar_appearance::system.
      virtual tool_bar& divider(bool value);
      
      dock_style dock() const noexcept override;
      control& dock(dock_style dock) override;
      
      /// @brief Gets a value indicating whether drop-down buttons on a toolbar display down arrows.
      /// @return true if drop-down toolbar buttons display down arrows; otherwise, false. The default is true.
      /// @remarks When xtd::forms::tool_bar::drop_down_arrows is set to false, no down arrows display on drop-down style toolbar buttons. When the user clicks the drop-down button on the toolbar, the menu drops down for selection. When the drop-down arrow is displayed, the user must press the down arrow to display the menu.
      virtual bool drop_down_arrows() const noexcept;
      /// @brief Sets a value indicating whether drop-down buttons on a toolbar display down arrows.
      /// @param value true if drop-down toolbar buttons display down arrows; otherwise, false. The default is true.
      /// @return Current tool_bar instance.
      /// @remarks When xtd::forms::tool_bar::drop_down_arrows is set to false, no down arrows display on drop-down style toolbar buttons. When the user clicks the drop-down button on the toolbar, the menu drops down for selection. When the drop-down arrow is displayed, the user must press the down arrow to display the menu.
      virtual tool_bar& drop_down_arrows(bool value);
      
      /// @brief Gets the collection of images available to the toolbar button controls.
      /// @return An xtd::forms::image_list that contains images available to the xtd::forms::tool_bar_button controls. The default is empty.
      /// @remarks If you create an xtd::drawing::image_list and assign it to the xtd::forms::toll_bar::image_list property, you can assign an image from the collection to the xtd:forms::tool_bar_button controls by assigning the image's index value to the xtd:forms::tool_bar_button::image_index property of the toolbar button.
      const xtd::forms::image_list& image_list() const noexcept;
      /// @brief Gets the collection of images available to the toolbar button controls.
      /// @return An xtd::forms::image_list that contains images available to the xtd::forms::tool_bar_button controls. The default is empty.
      /// @remarks If you create an xtd::drawing::image_list and assign it to the xtd::forms::toll_bar::image_list property, you can assign an image from the collection to the xtd:forms::tool_bar_button controls by assigning the image's index value to the xtd:forms::tool_bar_button::image_index property of the toolbar button.
      xtd::forms::image_list& image_list();
      /// @brief Sets the collection of images available to the toolbar button controls.
      /// @param value An xtd::forms::image_list that contains images available to the xtd::forms::tool_bar_button controls. The default is empty.
      /// @return Current tool_bar instance.
      /// @remarks If you create an xtd::drawing::image_list and assign it to the xtd::forms::toll_bar::image_list property, you can assign an image from the collection to the xtd:forms::tool_bar_button controls by assigning the image's index value to the xtd:forms::tool_bar_button::image_index property of the toolbar button.
      tool_bar& image_list(const xtd::forms::image_list& value);
      
      /// @brief Gets the size of the images in the image list assigned to the toolbar.
      /// @return A xtd::drawing::size that represents the size of the images (in the xtd::forms::image_list) assigned to the xtd::forms::tool_bar.
      virtual xtd::drawing::size image_size() const noexcept;
      
      /// @brief Gets a value indicating whether the toolbar displays the image for each button.
      /// @return true if the toolbar display the image for each button; otherwise, false. The default is true.
      virtual bool show_icon() const noexcept;
      /// @brief Sets a value indicating whether the toolbar displays the image for each button.
      /// @param value true if the toolbar display the image for each button; otherwise, false. The default is true.
      /// @return Current tool_bar instance.
      virtual tool_bar& show_icon(bool value);
      
      /// @brief Gets a value indicating whether the toolbar displays the text for each button.
      /// @return true if the toolbar display the text for each button; otherwise, false. The default is false.
      virtual bool show_text() const noexcept;
      /// @brief Sets a value indicating whether the toolbar displays the text for each button.
      /// @param value true if the toolbar display the text for each button; otherwise, false. The default is false.
      /// @return Current tool_bar instance.
      virtual tool_bar& show_text(bool value);
      
      /// @brief Gets a value indicating whether the toolbar displays a xtd::forms::tool_tip for each button.
      /// @return true if the toolbar display a xtd::forms::tool_tip for each button; otherwise, false. The default is false.
      /// @remarks To set the text displayed by the xtd::forms::tool_tip, set the xtd::forms::tool_bar_button::tool_tip_text property of each xtd::forms::tool_bar_button on the xtd::forms::tool_bar. To cause the xtd::forms::tool_tip to display as the user moves the mouse pointer over the toolbar button, set the xtd::forms::tool_bar::show_tool_tips property to true.
      virtual bool show_tool_tips() const noexcept;
      /// @brief Sets a value indicating whether the toolbar displays a xtd::forms::tool_tip for each button.
      /// @param value true if the toolbar display a xtd::forms::tool_tip for each button; otherwise, false. The default is false.
      /// @return Current tool_bar instance.
      /// @remarks To set the text displayed by the xtd::forms::tool_tip, set the xtd::forms::tool_bar_button::tool_tip_text property of each xtd::forms::tool_bar_button on the xtd::forms::tool_bar. To cause the xtd::forms::tool_tip to display as the user moves the mouse pointer over the toolbar button, set the xtd::forms::tool_bar::show_tool_tips property to true.
      virtual tool_bar& show_tool_tips(bool value);
      
      /// @brief Gets the alignment of text in relation to each image displayed on the toolbar button controls.
      /// @return One of the xtd::forms::tool_bar_text_align values. The default is xtd::forms::tool_bar_text_align::underneath.
      /// @remarks The xtd::forms::tool_bar::text can be aligned underneath or to the right of the image displayed on the xtd::forms::tool_bar_button controls.
      virtual xtd::forms::tool_bar_text_align text_align() const noexcept;
      /// @brief Sets the alignment of text in relation to each image displayed on the toolbar button controls.
      /// @param value One of the xtd::forms::tool_bar_text_align values. The default is xtd::forms::tool_bar_text_align::underneath.
      /// @return Current tool_bar instance.
      /// @remarks The xtd::forms::tool_bar::text can be aligned underneath or to the right of the image displayed on the xtd::forms::tool_bar_button controls.
      virtual tool_bar& text_align(xtd::forms::tool_bar_text_align value);
      
      /// @brief Gets a value indicating whether the toolbar buttons wrap to the next line if the toolbar becomes too small to display all the buttons on the same line.
      /// @return true if the toolbar buttons wrap to another line if the toolbar becomes too small to display all the buttons on the same line; otherwise, false. The default value is true.
      /// @note Not yet implemented.
      virtual bool wrappable() const noexcept;
      /// @brief Gets a value indicating whether the toolbar buttons wrap to the next line if the toolbar becomes too small to display all the buttons on the same line.
      /// @param value true if the toolbar buttons wrap to another line if the toolbar becomes too small to display all the buttons on the same line; otherwise, false. The default value is true.
      /// @return Current tool_bar instance.
      /// @remarks Toolbar buttons can be divided into logical groups by using separators. A separator is a toolbar button with the xtd::forms::tool_bar::style property set to xtd::forms::tool_bar_button_style::separator. If the xtd::forms::tool_bar::wrappable property is set to true and the toolbar becomes too small to display all the buttons on the same line, the toolbar is broken into additional lines, with the breaks occurring at the separators. This ensures that button groups stay together. Toolbar buttons that are not in a group can be separated when the toolbar wraps. The toolbar can become too small to display all its buttons on the same line if its parent xtd::forms:form is resized.
      /// @note Not yet implemented.
      virtual tool_bar& wrappable(bool value);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when a xtd::forms::tool_bar_button on the xtd::forms::tool_bar is clicked.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      xtd::event<tool_bar, xtd::forms::tool_bar_button_click_event_handler> button_click;
      
      /// @brief Occurs when a drop-down style xtd::forms::tool_bar_button or its down arrow is clicked.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      xtd::event<tool_bar, xtd::forms::tool_bar_button_click_event_handler> button_drop_down;
      /// @}
      
    protected:
      friend tool_bar_button;
      friend form;
      
      /// @name Protetced properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      xtd::drawing::font default_font() const noexcept override;
      drawing::size default_size() const noexcept override;
      /// @}
      
      /// @name Protetced methods
      
      /// @{
      /// @brief Raises the xtd::forms::tool_bar::button_click event.
      /// @param e A xtd::forms::tool_bar_button_click_event_args that contains the event data.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      /// @remarks The xtd::forms::tool_bar::on_button_click method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::tool_bar::on_button_click in a derived class, be sure to call the base class's xtd::forms::tool_bar::on_button_click method so that registered delegates receive the event.
      void on_button_click(const xtd::forms::tool_bar_button_click_event_args& e);
      
      /// @brief Raises the xtd::forms::tool_bar::button_drop_down event.
      /// @param e A xtd::forms::tool_bar_button_click_event_args that contains the event data.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      /// @remarks The xtd::forms::tool_bar::on_button_click method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::tool_bar::on_button_drop_down in a derived class, be sure to call the base class's xtd::forms::tool_bar::on_button_drop_down method so that registered delegates receive the event.
      void on_button_drop_down(const xtd::forms::tool_bar_button_click_event_args& e);
      
      void on_handle_created(const event_args& e) override;
      void on_handle_destroyed(const event_args& e) override;
      void on_paint(xtd::forms::paint_event_args& e) override;
      void on_resize(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void fill();
      
      bool is_horizontal() const noexcept;
      bool is_system_tool_bar() const noexcept;
      tool_bar& is_system_tool_bar(bool value);
      
      void on_item_added(size_t pos, tool_bar_button_ref item);
      void on_item_updated(size_t pos, tool_bar_button_ref item);
      void on_item_removed(size_t pos, tool_bar_button_ref item);
      
      void resize_stretchable_separtors();
      void update_toolbar_button_control(intptr handle, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool pushed, bool enabled, bool visible);
      
      void wm_click(const message& message);
      
      std::shared_ptr<data> data_;
    };
  }
}
