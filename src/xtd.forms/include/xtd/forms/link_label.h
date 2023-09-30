/// @file
/// @brief Contains xtd::forms::link_label class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "cursors.h"
#include "label.h"
#include "link.h"
#include "link_area.h"
#include "link_behavior.h"
#include "link_label_clicked_event_handler.h"
#include <xtd/drawing/system_colors>
#include <xtd/any>
#include <tuple>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows label control that can display hyperlinks.
    /// @par Header
    /// @code #include <xtd/forms/link_label> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks The xtd::forms::link_label control is similar to a xtd::forms::label control with the exception that it can display a hyperlink. Multiple hyperlinks can be specified in the text of the control. Each hyperlink can perform a different task within an application. For example, you can use a hyperlink to display a Web site in your web browser or to load a log file associated with an application.
    /// @remarks Each hyperlink displayed in the xtd::forms::link_label control is an instance of the xtd::forms::link_label::link class. The xtd::forms::link_label::link class defines display information, state, and location of the hyperlink. In addition, the xtd::forms::link_label::link::link_data property of the xtd::forms::link_label::link class enables you to associate information, such as a URL to display, with the hyperlink. When a user clicks a hyperlink within the control, the xtd::forms::link_label::link_clicked event is raised, and the xtd::forms::link_label::link object representing the hyperlink that was clicked is passed as part of the xtd::forms::link_label_link_clicked_event_args object that is passed as a parameter to the event handler. You can use this object to obtain the xtd::forms::link_label::link object associated with the hyperlink that was clicked by the user. All hyperlinks contained within the xtd::forms::link_label control are stored in the xtd::forms::link_label::link_collection class instance for the control.
    /// @remarks There are two ways to add a hyperlink to the the xtd::forms::link_label control. The quickest way is to specify a the xtd::forms::link_label::link_area and assign it to the the xtd::forms::link_label::link_area property. This enables you to specify a single hyperlink within the text of the control. To add multiple hyperlinks, you can use the the xtd::forms::link_label::link_collection::push_back method of the the xtd::forms::link_label::link_collection class by accessing the collection through the the xtd::forms::link_label::links property.
    /// @remarks When a xtd::forms::link_label control is created, a default hyperlink that contains all the text within the xtd::forms::link_label control is added to the xtd::forms::link_label::link_collection. You can override this default link by specifying a new link area with the xtd::forms::link_label::link_area property, or specify a link using the xtd::forms::link_label::link_collection::push_back method of the xtd::forms::link_label::link_collection. You can also remove the default hyperlink by using the xtd::forms::link_label::link_collection::erase method of the xtd::forms::link_label::link_collection class.
    /// @remarks The xtd::forms::link_label::tab_stop property is true by default, as long as there is at least one link of greater than zero length in the Links collection. The xtd::forms::link_label control has a single xtd::forms::link_label::tab_index value. However, each link of greater than zero length gets its own tab stop, in left-to-right order. To prevent tab navigation to the xtd::forms::link_label control, set the xtd::forms::link_label::tab_stop property to false. However, be aware that adding new links to the xtd::forms::link_label::links collection will automatically set the xtd::forms::link_label::tab_stop property to true again.
    /// @remarks The xtd::forms::link_label provides a number of properties that enable you to define the display appearance of hyperlinks in the control. The xtd::forms::link_label::active_link_color, xtd::forms::link_label::disabled_link_color, xtd::forms::link_label::link_color, and xtd::forms::link_label::visited_link_color properties define the colors used when displaying a hyperlink in various states. The xtd::forms::link_label::link_behavior property defines the display of the underline that is associated with a hyperlink.
    /// @par Appearance
    /// |       | Windows                                 | macOS                                   | Gnome                                   |
    /// | ----- | --------------------------------------- | --------------------------------------- | --------------------------------------- |
    /// | Light |  @image html control_link_label_w.png   |  @image html control_link_label_m.png   |  @image html control_link_label_g.png   |
    /// | Dark  |  @image html control_link_label_wd.png  |  @image html control_link_label_md.png  |  @image html control_link_label_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of link_label control.
    /// @include link_label.cpp
    class link_label : public label {
      struct data;
      
    public:
      /// @name Alias
      
      /// @{
      /// @brief Represents a link within a link_label control.
      /// @remarks The xtd::forms::link_label::link class defines the properties of a link within a xtd::forms::link_label control. You can use these properties to provide data to the xtd::forms::link_label::link_clicked event of the xtd::forms::link_label control to perform tasks when the link is clicked in the control. The xtd::forms::link_label::link_data property enables you to define information that the xtd::forms::link_label::link_clicked event can use to display a URL within your web browser or to open a file.
      /// @remarks In addition to information related to the link, the properties of the xtd::forms::link_label::link class also help define the text of the xtd::forms::link_label::lLink and its display state. The xtd::forms::link_label::start and xtd::forms::link_label::length properties define the location and length of text from the text of the xtd::forms::link_label control to display as a link. The xtd::forms::link_label::enabled property allows you to display the link as a disabled link, and the xtd::forms::link_label::visited property can alert the user that they already visited the specified link in the current instance of the xtd::forms::link_label.
      /// @remarks You can display multiple links in a single xtd::forms::link_label control. Each xtd::forms::link_label::link is added into the xtd::forms::link_label::link_collection associated with the xtd::forms::link_label control. To obtain the collection of links defined in a xtd::forms::link_label control, use the xtd::forms::link_label::links property.
      using link = xtd::forms::link;
      
      /// @brief Represents a collection of controls.
      class link_collection : public xtd::forms::layout::arranged_element_collection<xtd::forms::link_label::link> {
      public:
        /// @name Link
        
        /// @{
        /// @brief Represents the base type of the collection.
        using base = xtd::forms::layout::arranged_element_collection<xtd::forms::link_label::link>;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Creates a new object xtd::forms::control::control_collection with specified allocator (optional).
        /// @param allocator The allocator associate to the collection (optional).
        /// @remarks If allocator not specified, the std::allocator<value_type> is used.
        explicit link_collection(const allocator_type& allocator = allocator_type());
        /// @}
        
        /// @cond
        explicit link_collection(const base& collection);
        link_collection(const link_collection& collection);
        link_collection& operator =(const link_collection& collection);
        link_collection(link_collection&&) = default;
        /// @endcond
        
        /// @name Operators
        
        /// @{
        using base::operator [];
        /// @brief Gets the first xtd::forms::control::control_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator [] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        const_reference operator [](const xtd::ustring& name) const noexcept;
        /// @brief Gets the first xtd::forms::control::control_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator [] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        reference operator [](const xtd::ustring& name) noexcept;
        /// @}
      };
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new default instance of the xtd::forms::link_label class.
      link_label();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the color used to display an active link.
      /// @return A xtd::drawing::color that represents the color to display an active link. The default color is specified by the system, typically this color is xtd::drawing::color::red in light mode and xtd::drawing::color::from_argb(0xFFD03E3D) in dark mode.
      /// @remarks An active link is a link that is in the process of being clicked. This is similar to the depressed state of a xtd::forms::button control. You can use this property to specify the color that the link is displayed in when the link is in the process of being clicked.
      /// @remarks There are a number of colors associated with a link. The xtd::forms::link_label::link_color specifies the color of all links displayed in the xtd::forms::link_label control. The xtd::forms::link_label::visited_link_color property enables you to specify the color of a link after it has been visited by the user. When a link is disabled, the xtd::forms::link_label::disabled_link_color is used to display the link in a disabled state.
      /// @note When setting this property, ensure that the color you are setting the property to does not conflict with the color of the control's background or the text does not display properly. For example, if the background color of the control is xtd::drawing::color::red and this property is set to xtd::drawing::color::red, the text is not shown properly when the link is in the process of being clicked.
      xtd::drawing::color active_link_color() const noexcept;
      /// @brief Sets the color used to display an active link.
      /// @param color A xtd::drawing::color that represents the color to display an active link. The default color is specified by the system, typically this color is xtd::drawing::color::red in light mode and xtd::drawing::color::from_argb(0xFFD03E3D) in dark mode.
      /// @return Current control.
      /// @remarks An active link is a link that is in the process of being clicked. This is similar to the depressed state of a xtd::forms::button control. You can use this property to specify the color that the link is displayed in when the link is in the process of being clicked.
      /// @remarks There are a number of colors associated with a link. The xtd::forms::link_label::link_color specifies the color of all links displayed in the xtd::forms::link_label control. The xtd::forms::link_label::visited_link_color property enables you to specify the color of a link after it has been visited by the user. When a link is disabled, the xtd::forms::link_label::disabled_link_color is used to display the link in a disabled state.
      /// @note When setting this property, ensure that the color you are setting the property to does not conflict with the color of the control's background or the text does not display properly. For example, if the background color of the control is xtd::drawing::color::red and this property is set to xtd::drawing::color::red, the text is not shown properly when the link is in the process of being clicked.
      link_label& active_link_color(const xtd::drawing::color& color);
      
      /// @brief Gets the color used when displaying a disabled link.
      /// @return A xtd::drawing::color that represents the color when displaying a disabled link. The default is Empty.
      /// @remarks his property enables you to specify the color for links that are disabled in the xtd::forms::link_label. Disabled links do not cause the xtd::forms::link_label::link_clicked event to be raised.
      /// @remarks There are a number of colors associated with a link. All links in the xtd::forms::link_label are initially displayed with the color defined in the xtd::forms::link_label::link_color property. The xtd::forms::link_label::active_link_color property enables you to specify the color of the link when it is in the process of being clicked. The xtd::forms::link_label::visited_link_color property enables you to specify the color of a link after it has been visited by the user.
      xtd::drawing::color disabled_link_color() const noexcept;
      /// @brief Sets the color used when displaying a disabled link.
      /// @param color A xtd::drawing::color that represents the color when displaying a disabled link. The default is Empty.
      /// @return Current control.
      /// @remarks his property enables you to specify the color for links that are disabled in the xtd::forms::link_label. Disabled links do not cause the xtd::forms::link_label::link_clicked event to be raised.
      /// @remarks There are a number of colors associated with a link. All links in the xtd::forms::link_label are initially displayed with the color defined in the xtd::forms::link_label::link_color property. The xtd::forms::link_label::active_link_color property enables you to specify the color of the link when it is in the process of being clicked. The xtd::forms::link_label::visited_link_color property enables you to specify the color of a link after it has been visited by the user.
      link_label& disabled_link_color(const xtd::drawing::color& color);
      
      xtd::forms::link_area link_area() const noexcept;
      link_label& link_area(xtd::forms::link_area value);
      
      xtd::forms::link_behavior link_behavior() const noexcept;
      link_label& link_behavior(xtd::forms::link_behavior value);
      
      xtd::drawing::color link_color() const noexcept;
      link_label& link_color(const xtd::drawing::color& color);
      
      const link_collection& links() const noexcept;
      link_collection& links();
      
      xtd::forms::cursor override_cursor() const noexcept;
      link_label& override_cursor(const xtd::forms::cursor& cursor);
      
      xtd::drawing::color visited_link_color() const noexcept;
      link_label& visited_link_color(const xtd::drawing::color& color);
      /// @}
      
      /// @name Methods
      
      /// @{
      using control::create;
      /// @brief A factory to create an xtd::forms::link_label with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @param name The name of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const xtd::ustring& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, text, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @param name The name of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const xtd::ustring& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when a link is clicked within the control.
      /// @remarks Typically, the xtd::forms::link_label::link_clicked event is handled to perform tasks when the user clicks on a link in the control. The event handler for the xtd::forms::link_label::link_clicked event is passed an instance of the xtd::forms::link_label_clicked_event_args class that contains a xtd::forms::link object that is associated with the link that was clicked. You can use information specified in the xtd::forms::link::link_data property of xtd::forms::link class to determine which link was clicked or what type of task to perform when the link is clicked. For example, if a xtd::forms::link_label control has a xtd::forms::link object defined with its xtd::forms::link::link_data property set to the string www.microsoft.com, you can use this information in an event handler for the xtd::forms::link_label::link_clicked event to display the Web site.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<link_label, link_label_clicked_event_handler> link_clicked;
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      xtd::drawing::size measure_control() const noexcept override;
      void on_cursor_changed(const xtd::event_args& e) override;
      void on_mouse_click(const xtd::forms::mouse_event_args& e) override;
      void on_mouse_down(const xtd::forms::mouse_event_args& e) override;
      void on_mouse_up(const xtd::forms::mouse_event_args& e) override;
      void on_mouse_move(const xtd::forms::mouse_event_args& e) override;
      void on_paint(xtd::forms::paint_event_args& e) override;
      void on_text_align_changed(const xtd::event_args& e) override;
      void on_text_changed(const xtd::event_args& e) override;
      
      /// @brief Gets link from point.
      /// @return xtd::forms::label::link corresponding to the point.
      link_label::link& point_in_link(const xtd::drawing::point& point);
      /// @}
      
    private:
      xtd::drawing::point get_text_location(size_t line) const noexcept;
      std::vector<std::tuple<xtd::drawing::rectangle, bool>> generate_text_rects() const noexcept;
      xtd::drawing::font link_font() const noexcept;
      
      std::shared_ptr<data> data_;
    };
  }
}

