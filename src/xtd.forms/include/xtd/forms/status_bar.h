/// @file
/// @brief Contains xtd::forms::status_bar container.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "panel"
#include "status_bar_panel"
#include "status_bar_draw_item_event_handler"
#include "status_bar_panel_click_event_handler"
#include <memory>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class form;
    /// @endcond
    
    /// @brief Represents a Windows status bar control.
    /// @code
    /// class forms_export_ status_bar : public xtd::forms::control
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::status_bar
    /// @par Header
    /// @code #include <xtd/forms/status_bar> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    /// @par Appearance
    /// |       | Windows                                            | macOS                                              | Gnome                                              |
    /// | ----- | -------------------------------------------------- | -------------------------------------------------- | -------------------------------------------------- |
    /// | Light |  @image html menus_and_toolbars_status_bar_w.png   |  @image html menus_and_toolbars_status_bar_m.png   |  @image html menus_and_toolbars_status_bar_g.png   |
    /// | Dark  |  @image html menus_and_toolbars_status_bar_wd.png  |  @image html menus_and_toolbars_status_bar_md.png  |  @image html menus_and_toolbars_status_bar_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::status_bar control.
    /// @include status_bar.cpp
    /// @remarks Typically, a xtd::forms::status_bar control consists of xtd::forms::status_bar_panel objects, each of which displays text and/or an image. You can also provide owner-drawn panels to provide custom panels such as a progress bar or a series of images that displays the state of your application. A xtd::forms::status_bar control typically displays information about an object being viewed on a xtd::forms::form, the object's components, or contextual information that relates to that object's operation within your application.
    /// @remarks The xtd::forms::status_bar control provides properties that enable you to customize the appearance of the control. If the xtd::forms::status_bar is displayed on a form that can be resized, you can use the xtd::forms::status_bar::sizing_grip property to display a sizing grip in the lower-right corner of the form to indicate to users that the form can be resized. The xtd::forms::status_bar::show_panels property enables you to display panels within your xtd::forms::status_bar or to display only the value of the xtd::forms::status_bar::text property of the control.
    /// @remarks The default xtd::forms::status_bar has no panels. To add panels to a xtd::forms::status_bar you can use the xtd::forms::status_bar::status_bar_panel_collection::push_back method of the xtd::forms::status_bar::status_bar_ppanel_collection class that is accessible through the xtd::forms::status_bar::panels property of the control. You can also use the xtd::forms::status_bar::status_bar_panel_collection object provided through the xtd::forms::status_bar::panels property to remove panels from the control and access a specific xtd::forms::status_bar_panel to manipulate the panel.
    /// @remarks If you want to determine when a xtd::forms::status_bar_panel object within a xtd::forms::status_bar control is clicked, you can create an event handler for the xtd::forms::status_bar::panel_click event. To perform owner-draw operations on a panel, you can create an event handler for the xtd::forms::status_bar::draw_item event. The event data passed to the event handler provides information on the panel to draw and a xtd::drawing::graphics object to use to perform drawing tasks.
    /// @remarks When you create an instance of xtd::forms::status_bar, the read/write properties are set to initial values. For a list of these values, see the xtd::forms::status_bar constructor.
    class forms_export_ status_bar : public control {
      struct data;
      class status_bar_panel_control;
      class sizing_grip_control;
      
    public:
      /// @name Alias
      
      /// @{
      /// @brief Represents the collection of panels in a xtd::forms::status_bar control.
      using status_bar_panel_collection = xtd::forms::layout::arranged_element_collection<status_bar_panel_ref>;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::status_bar class.
      /// @remarks The default xtd::forms::status_bar has no panels.
      /// @remarks When you create an instance of xtd::forms::status_bar, the following read/write properties are set to initial values.
      /// | Property                            | Initial value                  |
      /// | ----------------------------------- | ------------------------------ |
      /// | xtd::forms::status_bar::dock        | xtd::forms::dock_style::bottom |
      /// | xtd::forms::status_bar::show_panels | false                          |
      /// | xtd::forms::status_bar::sizing_grip | true                           |
      status_bar();
      /// @}
      
      /// @name Properties
      
      /// @{
      dock_style dock() const noexcept override;
      control& dock(dock_style dock) override;
      
      /// @brief Gets the collection of xtd::forms::status_bar panels contained within the control.
      /// @return A xtd::forms::status_bar::status_bar_panel_collection containing the xtd::forms::status_bar_panel objects of the xtd::forms::status_bar control.
      /// @remarks The xtd::forms::status_bar control can display a number of panels to provide information to the user of your application. For example, a panel could display the current time or the progress of a file download. Each panel displayed by the xtd::forms::status_bar control is an instance of the xtd::forms::status_bar_panel class. The xtd::forms::status_bar::panels property enables you to obtain a reference to the collection of xtd::forms::status_bar_panel objects that are currently stored in the xtd::forms::status_bar control. With this reference, you can add panels, remove panels, access a specific panel within the collection, and obtain a count of the panels in the xtd::forms::status_bar control. For more information on the tasks that can be performed with the panel collection, see the xtd::forms::status_bar::status_bar_panel_collection class reference topics.
      const status_bar_panel_collection& panels() const noexcept;
      /// @brief Gets the collection of xtd::forms::status_bar panels contained within the control.
      /// @return A xtd::forms::status_bar::status_bar_panel_collection containing the xtd::forms::status_bar_panel objects of the xtd::forms::status_bar control.
      /// @remarks The xtd::forms::status_bar control can display a number of panels to provide information to the user of your application. For example, a panel could display the current time or the progress of a file download. Each panel displayed by the xtd::forms::status_bar control is an instance of the xtd::forms::status_bar_panel class. The xtd::forms::status_bar::panels property enables you to obtain a reference to the collection of xtd::forms::status_bar_panel objects that are currently stored in the xtd::forms::status_bar control. With this reference, you can add panels, remove panels, access a specific panel within the collection, and obtain a count of the panels in the xtd::forms::status_bar control. For more information on the tasks that can be performed with the panel collection, see the xtd::forms::status_bar::status_bar_panel_collection class reference topics.
      status_bar_panel_collection& panels();
      
      /// @brief Gets a value indicating whether any panels that have been added to the control are displayed.
      /// @return true if panels are displayed; otherwise, false. The default is false.
      /// @remarks By default, the xtd::forms::status_bar control displays the value of its xtd::forms::status_bar::text property without any panels. When xtd::forms::status_bar::show_panels is set to true, any xtd::forms::status_bar objects specified in the StatusBar control are displayed. No panels are initially created when you create an instance of the xtd::forms::status_bar class. You can add panels to a xtd::forms::status_bar control by using the xtd::forms::status_bar::status_bar_panel_collection::push_back method of the xtd::forms::status_bar::status_bar_panel_collection class. This collection class can be accessed through the xtd::forms::status_bar::panels property of xtd::forms::status_bar.
      virtual bool show_panels() const noexcept;
      /// @brief Sets a value indicating whether any panels that have been added to the control are displayed.
      /// @param value true if panels are displayed; otherwise, false. The default is false.
      /// @return Current status_bar instance.
      /// @remarks By default, the xtd::forms::status_bar control displays the value of its xtd::forms::status_bar::text property without any panels. When xtd::forms::status_bar::show_panels is set to true, any xtd::forms::status_bar objects specified in the StatusBar control are displayed. No panels are initially created when you create an instance of the xtd::forms::status_bar class. You can add panels to a xtd::forms::status_bar control by using the xtd::forms::status_bar::status_bar_panel_collection::push_back method of the xtd::forms::status_bar::status_bar_panel_collection class. This collection class can be accessed through the xtd::forms::status_bar::panels property of xtd::forms::status_bar.
      virtual status_bar& show_panels(bool value);
      
      /// @brief Gets a value indicating whether the status bar displays a xtd::forms::tool_tip for each button.
      /// @return true if the status bar display a xtd::forms::tool_tip for each button; otherwise, false. The default is false.
      /// @remarks To set the text displayed by the xtd::forms::tool_tip, set the xtd::forms::tool_bar_button::tool_tip_text property of each xtd::forms::tool_bar_button on the xtd::forms::tool_bar. To cause the xtd::forms::tool_tip to display as the user moves the mouse pointer over the status bar button, set the xtd::forms::tool_bar::show_tool_tips property to true.
      virtual bool show_tool_tips() const noexcept;
      /// @brief Sets a value indicating whether the status bar displays a xtd::forms::tool_tip for each button.
      /// @param value true if the status bar display a xtd::forms::tool_tip for each button; otherwise, false. The default is false.
      /// @return Current tool_bar instance.
      /// @remarks To set the text displayed by the xtd::forms::tool_tip, set the xtd::forms::tool_bar_button::tool_tip_text property of each xtd::forms::tool_bar_button on the xtd::forms::tool_bar. To cause the xtd::forms::tool_tip to display as the user moves the mouse pointer over the status bar panel, set the xtd::forms::tool_bar::show_tool_tips property to true.
      virtual status_bar& show_tool_tips(bool value);
      
      /// @brief Gets a value indicating whether a sizing grip is displayed in the lower-right corner of the control.
      /// @return true if a sizing grip is displayed; otherwise, false. The default is true.
      /// @remarks You can use this property to display a sizing grip to provide an indication to the user when a form is resizable. If the xtd::forms::form_border_style property of your xtd::forms::form is set to a border style that is not resizable, such as xtd::forms::form_border_style::fixed_3d or xtd::forms::form_border_style::fixed_dialog, you should set the xtd::forms::status_bar::sizing_grip property to false to prevent the user from thinking that the form can be resized.
      virtual bool sizing_grip() const noexcept;
      /// @brief Sets a value indicating whether a sizing grip is displayed in the lower-right corner of the control.
      /// @param value true if a sizing grip is displayed; otherwise, false. The default is true.
      /// @return Current status_bar instance.
      /// @remarks You can use this property to display a sizing grip to provide an indication to the user when a form is resizable. If the xtd::forms::form_border_style property of your xtd::forms::form is set to a border style that is not resizable, such as xtd::forms::form_border_style::fixed_3d or xtd::forms::form_border_style::fixed_dialog, you should set the xtd::forms::status_bar::sizing_grip property to false to prevent the user from thinking that the form can be resized.
      virtual status_bar& sizing_grip(bool value);
      /// @}
      
      /// @name Methods
      
      /// @{
      //using control::create;
      /// @brief A factory to create an xtd::forms::status_bar with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::status_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::status_bar.
      /// @param name The name of the xtd::forms::status_bar.
      /// @return New xtd::forms::status_bar created.
      static status_bar create(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::status_bar with specified parent, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::status_bar.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::status_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::status_bar.
      /// @param name The name of the xtd::forms::status_bar.
      /// @return New xtd::forms::status_bar created.
      static status_bar create(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when a visual aspect of an owner-drawn status bar control changes.
      /// @remarks You can use this event to perform drawing operations in an owner-drawn xtd::forms::status_bar control. For example, if you display an owner-drawn xtd::forms::status_bar_panel that displays a progress bar, you can use this event to perform the drawing of the progress bar on the panel. The data provided to the event through the xtd::forms::status_bar_draw_item_event_args object passed as a parameter to the event handler enables you to determine the panel that needs to be drawn and the xtd::drawing::graphics to use to draw to the panel. This event is only raised when the xtd::forms::status_bar_panel::style property of a xtd::forms::status_bar_panel in a xtd::forms::status_bar control is set to xtd::forms::status_bar_panel_style::owner_draw.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      xtd::event<status_bar, xtd::forms::status_bar_draw_item_event_handler> draw_item;
      
      /// @brief Occurs when a xtd::forms::status_bar_panel object on a xtd::forms::status_bar control is clicked.
      /// @remarks You can use this event to perform tasks when a panel within a xtd::forms::status_bar control is clicked. The data provided to the event through the xtd::forms::status_bar_panel_click_event_args passed as a parameter to the event handler enables you to determine the xtd::forms::status_bar_panel that was clicked by the user in order to perform tasks on the selected panel.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      xtd::event<status_bar, xtd::forms::status_bar_panel_click_event_handler> panel_click;
      /// @}
      
    protected:
      friend status_bar_panel;
      friend form;
      
      /// @name Protetced properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      xtd::drawing::font default_font() const noexcept override;
      drawing::size default_size() const noexcept override;
      /// @}
      
      /// @name Protetced methods
      
      /// @{
      /// @brief Raises the xtd::forms::status_bar::daw_item event.
      /// @param e A xtd::forms::status_bar_draw_item_event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      /// @remarks The xtd::forms::status_bar::on_draw_item method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::status_bar::on_draw_item in a derived class, be sure to call the base class's xtd::forms::status_bar::on_draw_item method so that registered delegates receive the event.
      virtual void on_draw_item(xtd::forms::status_bar_draw_item_event_args& e);
      
      /// @brief Raises the xtd::forms::status_bar::panel_click event.
      /// @param e A xtd::forms::status_bar_panel_click_event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      /// @remarks The xtd::forms::status_bar::on_panel_click method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::status_bar::on_panel_click in a derived class, be sure to call the base class's xtd::forms::status_bar::on_panel_click method so that registered delegates receive the event.
      virtual void on_panel_click(const xtd::forms::status_bar_panel_click_event_args& e);
      
      void on_handle_created(const event_args& e) override;
      void on_handle_destroyed(const event_args& e) override;
      
      void on_main_panel_paint(object& sender, xtd::forms::paint_event_args& e);
      
      void on_paint(xtd::forms::paint_event_args& e) override;
      void on_resize(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void fill();
      
      bool is_horizontal() const noexcept;
      bool is_system_status_bar() const noexcept;
      status_bar& is_system_status_bar(bool value);
      
      void on_control_appearance_changed(const xtd::event_args&) override;
      void on_item_added(size_t pos, status_bar_panel_ref item);
      void on_item_updated(size_t pos, status_bar_panel_ref item);
      void on_item_removed(size_t pos, status_bar_panel_ref item);
      
      void resize_spring_panels();
      void update_status_bar_panel_control(intptr handle, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, xtd::forms::horizontal_alignment alignment, xtd::forms::status_bar_panel_auto_size auto_size, xtd::forms::status_bar_panel_border_style border_style, xtd::forms::status_bar_panel_style panel_style, int32 min_width, int32 width);
      
      std::shared_ptr<data> data_;
    };
  }
}
