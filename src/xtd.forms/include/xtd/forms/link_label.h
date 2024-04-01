/// @file
/// @brief Contains xtd::forms::link_label class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
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
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents a link within a link_label control.
      /// @remarks The xtd::forms::link_label::link class defines the properties of a link within a xtd::forms::link_label control. You can use these properties to provide data to the xtd::forms::link_label::link_clicked event of the xtd::forms::link_label control to perform tasks when the link is clicked in the control. The xtd::forms::link_label::link_data property enables you to define information that the xtd::forms::link_label::link_clicked event can use to display a URL within your web browser or to open a file.
      /// @remarks In addition to information related to the link, the properties of the xtd::forms::link_label::link class also help define the text of the xtd::forms::link_label::lLink and its display state. The xtd::forms::link_label::start and xtd::forms::link_label::length properties define the location and length of text from the text of the xtd::forms::link_label control to display as a link. The xtd::forms::link_label::enabled property allows you to display the link as a disabled link, and the xtd::forms::link_label::visited property can alert the user that they already visited the specified link in the current instance of the xtd::forms::link_label.
      /// @remarks You can display multiple links in a single xtd::forms::link_label control. Each xtd::forms::link_label::link is added into the xtd::forms::link_label::link_collection associated with the xtd::forms::link_label control. To obtain the collection of links defined in a xtd::forms::link_label control, use the xtd::forms::link_label::links property.
      using link = xtd::forms::link;
      /// @}
      
      /// @brief Represents a collection of controls.
      class link_collection : public xtd::forms::layout::arranged_element_collection<xtd::forms::link_label::link> {
      public:
        /// @name Aliases
        
        /// @{
        /// @brief Represents the base type of the collection.
        using base = xtd::forms::layout::arranged_element_collection<xtd::forms::link_label::link>;
        /// @}
        
        /// @name Public Constructors
        
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
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new default instance of the xtd::forms::link_label class.
      link_label();
      /// @}
      
      /// @cond
      link_label(link_label&& rhs);
      link_label(const link_label&) = default;
      link_label& operator =(const link_label&) = default;
      /// @endcond

      /// @name Public Properties
      
      /// @{
      /// @brief Gets the color used to display an active link.
      /// @return A xtd::drawing::color that represents the color to display an active link. The default color is specified by the system, typically this color is xtd::drawing::color::red in light mode and xtd::drawing::color::from_argb(0xFFD03E3D) in dark mode.
      /// @remarks An active link is a link that is in the process of being clicked. This is similar to the depressed state of a xtd::forms::button control. You can use this property to specify the color that the link is displayed in when the link is in the process of being clicked.
      /// @remarks There are a number of colors associated with a link. The xtd::forms::link_label::link_color specifies the color of all links displayed in the xtd::forms::link_label control. The xtd::forms::link_label::visited_link_color property enables you to specify the color of a link after it has been visited by the user. When a link is disabled, the xtd::forms::link_label::disabled_link_color is used to display the link in a disabled state.
      /// @note When setting this property, ensure that the color you are setting the property to does not conflict with the color of the control's background or the text does not display properly. For example, if the background color of the control is xtd::drawing::color::red and this property is set to xtd::drawing::color::red, the text is not shown properly when the link is in the process of being clicked.
      /// @remarks The default color of the xtd::forms::link_label::active_link_color, xtd::forms::link_label::disabled_link_color, xtd::forms::link_label::link_color and xtd::forms::link_label::visited_link_color properties may be different on operating systems other than Windows with ligh theme.
      xtd::drawing::color active_link_color() const noexcept;
      /// @brief Sets the color used to display an active link.
      /// @param color A xtd::drawing::color that represents the color to display an active link. The default color is specified by the system, typically this color is xtd::drawing::color::red in light mode and xtd::drawing::color::from_argb(0xFFD03E3D) in dark mode.
      /// @return Current control.
      /// @remarks An active link is a link that is in the process of being clicked. This is similar to the depressed state of a xtd::forms::button control. You can use this property to specify the color that the link is displayed in when the link is in the process of being clicked.
      /// @remarks There are a number of colors associated with a link. The xtd::forms::link_label::link_color specifies the color of all links displayed in the xtd::forms::link_label control. The xtd::forms::link_label::visited_link_color property enables you to specify the color of a link after it has been visited by the user. When a link is disabled, the xtd::forms::link_label::disabled_link_color is used to display the link in a disabled state.
      /// @note When setting this property, ensure that the color you are setting the property to does not conflict with the color of the control's background or the text does not display properly. For example, if the background color of the control is xtd::drawing::color::red and this property is set to xtd::drawing::color::red, the text is not shown properly when the link is in the process of being clicked.
      /// @remarks The default color of the xtd::forms::link_label::active_link_color, xtd::forms::link_label::disabled_link_color, xtd::forms::link_label::link_color and xtd::forms::link_label::visited_link_color properties may be different on operating systems other than Windows with ligh theme.
      link_label& active_link_color(const xtd::drawing::color& color);
      
      /// @brief Gets the color used when displaying a disabled link.
      /// @return A xtd::drawing::color that represents the color when displaying a disabled link. The default is Empty.
      /// @remarks his property enables you to specify the color for links that are disabled in the xtd::forms::link_label. Disabled links do not cause the xtd::forms::link_label::link_clicked event to be raised.
      /// @remarks There are a number of colors associated with a link. All links in the xtd::forms::link_label are initially displayed with the color defined in the xtd::forms::link_label::link_color property. The xtd::forms::link_label::active_link_color property enables you to specify the color of the link when it is in the process of being clicked. The xtd::forms::link_label::visited_link_color property enables you to specify the color of a link after it has been visited by the user.
      /// @remarks The default color of the xtd::forms::link_label::active_link_color, xtd::forms::link_label::disabled_link_color, xtd::forms::link_label::link_color and xtd::forms::link_label::visited_link_color properties may be different on operating systems other than Windows with ligh theme.
      xtd::drawing::color disabled_link_color() const noexcept;
      /// @brief Sets the color used when displaying a disabled link.
      /// @param color A xtd::drawing::color that represents the color when displaying a disabled link. The default is Empty.
      /// @return Current control.
      /// @remarks his property enables you to specify the color for links that are disabled in the xtd::forms::link_label. Disabled links do not cause the xtd::forms::link_label::link_clicked event to be raised.
      /// @remarks There are a number of colors associated with a link. All links in the xtd::forms::link_label are initially displayed with the color defined in the xtd::forms::link_label::link_color property. The xtd::forms::link_label::active_link_color property enables you to specify the color of the link when it is in the process of being clicked. The xtd::forms::link_label::visited_link_color property enables you to specify the color of a link after it has been visited by the user.
      /// @remarks The default color of the xtd::forms::link_label::active_link_color, xtd::forms::link_label::disabled_link_color, xtd::forms::link_label::link_color and xtd::forms::link_label::visited_link_color properties may be different on operating systems other than Windows with ligh theme.
      link_label& disabled_link_color(const xtd::drawing::color& color);
      
      /// @brief Gets the range in the text to treat as a link.
      /// @return A xtd::forms::link_area that represents the area treated as a link.
      /// @remarks The xtd::forms::link_label::link_area property provides a quick way to specify a single hyperlink to display in the text of the xtd::forms::link_label: control. The xtd::forms::link_area object provides properties that specify the starting position of the link within the text of the control and the length of text for the hyperlink. When a hyperlink is specified using the xtd::forms::link_label:link_rea property, the hyperlink is added to the xtd::forms::link_label::link_collection of the control. The xtd::forms::link_label:link_area property converts the xtd::forms::link_area object assigned to it to a xtd::forms::link_label::link object that is stored within the collection.
      /// @remarks To add multiple hyperlinks to the text of the control, you can use the xtd::forms::link_label::links property. The xtd::forms::link_label::links property enables you to access the properties and methods of the xtd::forms::link_label::link_collection, which stores the links specified for the control. This method of adding links to the xtd::forms::link_label also enables you to specify data in the xtd::forms::link_label::link::link_data property that is associated with the link being created. The value of the xtd::forms::link_label::link_data property can be used to store the location of a file to display or the address of a Web site.
      /// @remarks When a xtd::forms::link_label control is created, a default hyperlink that contains all the text within the xtd::forms::link_label control is added to the xtd::forms::link_label::link_collection. You can override this default link by specifying a new link area with the xtd::forms::link_label::link_area property, or specify a link using the xtd::forms::link_label::link_collection::push_back method of the xtd::forms::link_label::link_collection. You can also remove the default hyperlink by using the xtd::forms::link_label::link_collection::erase method of the xtd::forms::link_label::link_collection class.
      /// @note The xtd::forms::link_label::link_area property always returns the first item in the xtd::forms::link_label::link_collection, regardless of how the hyperlink was added to the collection.
      xtd::forms::link_area link_area() const noexcept;
      /// @brief Sets the range in the text to treat as a link.
      /// @param value A xtd::forms::link_area that represents the area treated as a link.
      /// @return Current control.
      /// @remarks The xtd::forms::link_label::link_area property provides a quick way to specify a single hyperlink to display in the text of the xtd::forms::link_label: control. The xtd::forms::link_area object provides properties that specify the starting position of the link within the text of the control and the length of text for the hyperlink. When a hyperlink is specified using the xtd::forms::link_label:link_rea property, the hyperlink is added to the xtd::forms::link_label::link_collection of the control. The xtd::forms::link_label:link_area property converts the xtd::forms::link_area object assigned to it to a xtd::forms::link_label::link object that is stored within the collection.
      /// @remarks To add multiple hyperlinks to the text of the control, you can use the xtd::forms::link_label::links property. The xtd::forms::link_label::links property enables you to access the properties and methods of the xtd::forms::link_label::link_collection, which stores the links specified for the control. This method of adding links to the xtd::forms::link_label also enables you to specify data in the xtd::forms::link_label::link::link_data property that is associated with the link being created. The value of the xtd::forms::link_label::link_data property can be used to store the location of a file to display or the address of a Web site.
      /// @remarks When a xtd::forms::link_label control is created, a default hyperlink that contains all the text within the xtd::forms::link_label control is added to the xtd::forms::link_label::link_collection. You can override this default link by specifying a new link area with the xtd::forms::link_label::link_area property, or specify a link using the xtd::forms::link_label::link_collection::push_back method of the xtd::forms::link_label::link_collection. You can also remove the default hyperlink by using the xtd::forms::link_label::link_collection::erase method of the xtd::forms::link_label::link_collection class.
      /// @note The xtd::forms::link_label::link_area property always returns the first item in the xtd::forms::link_label::link_collection, regardless of how the hyperlink was added to the collection.
      link_label& link_area(xtd::forms::link_area value);
      
      /// @brief Gets a value that represents the behavior of a link.
      /// @return One of the xtd::forms::link_behavior values. The default is xtd::forms::link_behavior::system_default.
      /// @remarks This property enables you to specify the behavior of links when they are displayed in the control. For example, if you want links to be displayed with an underline only when the mouse pointer is over a link, you can set this property to LinkBehavior.HoverUnderline. For more information on the types of behaviors that can be associated with a link, see xtd::forms::link_behavior.
      xtd::forms::link_behavior link_behavior() const noexcept;
      /// @brief Sets a value that represents the behavior of a link.
      /// @param value One of the xtd::forms::link_behavior values. The default is xtd::forms::link_behavior::system_default.
      /// @return Current control.
      /// @remarks This property enables you to specify the behavior of links when they are displayed in the control. For example, if you want links to be displayed with an underline only when the mouse pointer is over a link, you can set this property to LinkBehavior.HoverUnderline. For more information on the types of behaviors that can be associated with a link, see xtd::forms::link_behavior.
      link_label& link_behavior(xtd::forms::link_behavior value);
      
      /// @brief Gets the color used when displaying a normal link.
      /// @return A xtd::drawing::color that represents the color used to displaying a normal link. The default color is specified by the system, typically this color is xtd::drawing::color::blue.
      /// @remarks This property enables you to specify the color that is initially displayed for all links in the xtd::forms::link_label.
      /// @remarks There are a number of colors associated with a link. The xtd::forms::link_labelactive_link_color property enables you to specify the color of the link when it is in the process of being clicked. The xtd::forms::link_label::visited_link_color property enables you to specify the color of a link after it has been visited by the user. When a link is disabled, the xtd::forms::link_label::disabled_link_color is used to display the link in a disabled state.
      /// @note When setting this property, ensure that the color you are setting the property to does not conflict with the color of the control's background or the text does not display properly. For example, if the background color of the control is xtd::drawing::color::red and this property is set to xtd::drawing::color::red, the text of the link is not shown properly.
      /// @remarks The default color of the xtd::forms::link_label::active_link_color, xtd::forms::link_label::disabled_link_color, xtd::forms::link_label::link_color and xtd::forms::link_label::visited_link_color properties may be different on operating systems other than Windows with ligh theme.
      xtd::drawing::color link_color() const noexcept;
      /// @brief Sets the color used when displaying a normal link.
      /// @param value A xtd::drawing::color that represents the color used to displaying a normal link. The default color is specified by the system, typically this color is xtd::drawing::color::blue.
      /// @return Current control.
      /// @remarks This property enables you to specify the color that is initially displayed for all links in the xtd::forms::link_label.
      /// @remarks There are a number of colors associated with a link. The xtd::forms::link_label::active_link_color property enables you to specify the color of the link when it is in the process of being clicked. The xtd::forms::link_label::visited_link_color property enables you to specify the color of a link after it has been visited by the user. When a link is disabled, the xtd::forms::link_label::disabled_link_color is used to display the link in a disabled state.
      /// @note When setting this property, ensure that the color you are setting the property to does not conflict with the color of the control's background or the text does not display properly. For example, if the background color of the control is xtd::drawing::color::red and this property is set to xtd::drawing::color::red, the text of the link is not shown properly.
      /// @remarks The default color of the xtd::forms::link_label::active_link_color, xtd::forms::link_label::disabled_link_color, xtd::forms::link_label::link_color and xtd::forms::link_label::visited_link_color properties may be different on operating systems other than Windows with ligh theme.
      link_label& link_color(const xtd::drawing::color& color);
      
      /// @brief Gets the collection of links contained within the xtd::forms::link_label.
      /// @return A xtd::forms::link_label::link_collection that represents the links contained within the xtd::forms::link_label control.
      /// @remarks A xtd::forms::link_label control can display any number of links within the text of the control. This property enables you to access the xtd::forms::link_label::link_collection instance associated with the xtd::forms::link_label that represents the collection of links displayed in the control. You can then use the members of the xtd::forms::link_label::link_collection class to add, remove, and find links in the collection. For more information on the types of tasks you can perform with the link collection, see xtd::forms::link_label::link_collection.
      /// @remarks When a xtd::forms::link_label control is created, a default hyperlink that contains all the text within the xtd::forms::link_label control is added to the xtd::forms::link_label::link_collection. You can override this default link by specifying a new link area with the xtd::forms::link_label::link_area property, or specify a link using the xtd::forms::link_label::link_collection::push_back method of the xtd::forms::link_label::link_collection. You can also remove the default hyperlink by using the xtd::forms::link_label::link_collection::erase method of the xtd::forms::link_label::link_collection class.
      /// @remarks If you do not need to specify more than one link to display within the xtd::forms::link_label, you can use the xtd::forms::link_label::link_area property.
      const link_collection& links() const noexcept;
      /// @brief Gets the collection of links contained within the xtd::forms::link_label.
      /// @return A xtd::forms::link_label::link_collection that represents the links contained within the xtd::forms::link_label control.
      /// @remarks A xtd::forms::link_label control can display any number of links within the text of the control. This property enables you to access the xtd::forms::link_label::link_collection instance associated with the xtd::forms::link_label that represents the collection of links displayed in the control. You can then use the members of the xtd::forms::link_label::link_collection class to add, remove, and find links in the collection. For more information on the types of tasks you can perform with the link collection, see xtd::forms::link_label::link_collection.
      /// @remarks When a xtd::forms::link_label control is created, a default hyperlink that contains all the text within the xtd::forms::link_label control is added to the xtd::forms::link_label::link_collection. You can override this default link by specifying a new link area with the xtd::forms::link_label::link_area property, or specify a link using the xtd::forms::link_label::link_collection::push_back method of the xtd::forms::link_label::link_collection. You can also remove the default hyperlink by using the xtd::forms::link_label::link_collection::erase method of the xtd::forms::link_label::link_collection class.
      /// @remarks If you do not need to specify more than one link to display within the xtd::forms::link_label, you can use the xtd::forms::link_label::link_area property.
      link_collection& links();
      /// @brief Sets the collection of links contained within the xtd::forms::link_label.
      /// @param value A xtd::forms::link_label::link_collection that represents the links contained within the xtd::forms::link_label control.
      /// @return Current control.
      /// @remarks A xtd::forms::link_label control can display any number of links within the text of the control. This property enables you to access the xtd::forms::link_label::link_collection instance associated with the xtd::forms::link_label that represents the collection of links displayed in the control. You can then use the members of the xtd::forms::link_label::link_collection class to add, remove, and find links in the collection. For more information on the types of tasks you can perform with the link collection, see xtd::forms::link_label::link_collection.
      /// @remarks When a xtd::forms::link_label control is created, a default hyperlink that contains all the text within the xtd::forms::link_label control is added to the xtd::forms::link_label::link_collection. You can override this default link by specifying a new link area with the xtd::forms::link_label::link_area property, or specify a link using the xtd::forms::link_label::link_collection::push_back method of the xtd::forms::link_label::link_collection. You can also remove the default hyperlink by using the xtd::forms::link_label::link_collection::erase method of the xtd::forms::link_label::link_collection class.
      /// @remarks If you do not need to specify more than one link to display within the xtd::forms::link_label, you can use the xtd::forms::link_label::link_area property.
      link_label& links(const link_collection& value);

      /// @brief Gets the mouse pointer to use when the mouse pointer is within the bounds of the xtd::forms::link_label.
      /// @return The xtd::forms::cursor to use when the mouse pointer is within the xtd::forms::link_label bounds.
      xtd::forms::cursor override_cursor() const noexcept;
      /// @brief Sets the mouse pointer to use when the mouse pointer is within the bounds of the xtd::forms::link_label.
      /// @param value The xtd::forms::cursor to use when the mouse pointer is within the xtd::forms::link_label bounds.
      /// @return Current control.
      link_label& override_cursor(const xtd::forms::cursor& cursor);
      
      /// @brief Gets the color used when displaying a link that has been previously visited.
      /// @return A xtd::drawing::color that represents the color used to display links that have been visited. The default color is specified by the system, typically this color is xtd::drawing::color::purple.
      /// @remarks This property enables you to specify the color that is displayed for all links in the xtd::forms::link_label xtd::.forms that have been visited by the user.
      /// @remarks There are a number of colors associated with a link. All links in the xtd::forms::link_label are initially displayed with the color defined in the xtd::forms::link_label::link_color property. The xtd::forms::link_label::active_link_color property enables you to specify the color of the link when it is in the process of being clicked. When a link is disabled, the xtd::forms::link_label::disabled_link_color is used to display the link in a disabled state.
      /// @note When setting this property, ensure that the color you are setting the property to does not conflict with the color of the control's background or the text does not display properly. For example, if the background color of the control is xtd::drawing::color::red and this property is set to xtd::drawing::color::rRed, the text is not shown properly when the link is displayed as a visited link.
      /// @remarks The default color of the xtd::forms::link_label::active_link_color, xtd::forms::link_label::disabled_link_color, xtd::forms::link_label::link_color and xtd::forms::link_label::visited_link_color properties may be different on operating systems other than Windows with ligh theme.
      xtd::drawing::color visited_link_color() const noexcept;
      /// @brief Sets the color used when displaying a link that has been previously visited.
      /// @param value A xtd::drawing::color that represents the color used to display links that have been visited. The default color is specified by the system, typically this color is xtd::drawing::color::purple.
      /// @return Current control.
      /// @remarks This property enables you to specify the color that is displayed for all links in the xtd::forms::link_label xtd::.forms that have been visited by the user.
      /// @remarks There are a number of colors associated with a link. All links in the xtd::forms::link_label are initially displayed with the color defined in the xtd::forms::link_label::link_color property. The xtd::forms::link_label::active_link_color property enables you to specify the color of the link when it is in the process of being clicked. When a link is disabled, the xtd::forms::link_label::disabled_link_color is used to display the link in a disabled state.
      /// @note When setting this property, ensure that the color you are setting the property to does not conflict with the color of the control's background or the text does not display properly. For example, if the background color of the control is xtd::drawing::color::red and this property is set to xtd::drawing::color::rRed, the text is not shown properly when the link is displayed as a visited link.
      /// @remarks The default color of the xtd::forms::link_label::active_link_color, xtd::forms::link_label::disabled_link_color, xtd::forms::link_label::link_color and xtd::forms::link_label::visited_link_color properties may be different on operating systems other than Windows with ligh theme.
      link_label& visited_link_color(const xtd::drawing::color& color);
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create();
      /// @brief A factory to create an xtd::forms::link_label with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::link_label with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::link_label with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @param name The name of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::link_label with specified text.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const xtd::ustring& text);
      /// @brief A factory to create an xtd::forms::link_label with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const xtd::ustring& text, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::link_label with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::link_label with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @param name The name of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::link_label with specified text.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param links A xtd::forms::link_label::link_collection that represents the links contained within the xtd::forms::link_label control.
      /// @return New xtd::forms::link_label created.
      static link_label create(const xtd::ustring& text, const link_collection& links);
      /// @brief A factory to create an xtd::forms::link_label with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param links A xtd::forms::link_label::link_collection that represents the links contained within the xtd::forms::link_label control.
     /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const xtd::ustring& text, const link_collection& links, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::link_label with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param links A xtd::forms::link_label::link_collection that represents the links contained within the xtd::forms::link_label control.
     /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const xtd::ustring& text, const link_collection& links, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::link_label with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param links A xtd::forms::link_label::link_collection that represents the links contained within the xtd::forms::link_label control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @param name The name of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const xtd::ustring& text, const link_collection& links, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::link_label with specified parent,.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, location.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @param name The name of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, and text.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const xtd::ustring& text);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, text, and location.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const xtd::ustring& text, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @param name The name of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, and text.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const xtd::ustring& text, const link_collection& links);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, text, and location.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param links A xtd::forms::link_label::link_collection that represents the links contained within the xtd::forms::link_label control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const xtd::ustring& text, const link_collection& links, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param links A xtd::forms::link_label::link_collection that represents the links contained within the xtd::forms::link_label control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const xtd::ustring& text, const link_collection& links, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::link_label with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::link_label.
      /// @param text A string that represent text of the xtd::forms::link_label.
      /// @param links A xtd::forms::link_label::link_collection that represents the links contained within the xtd::forms::link_label control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::link_label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::link_label.
      /// @param name The name of the xtd::forms::link_label.
      /// @return New xtd::forms::link_label created.
      static link_label create(const control& parent, const xtd::ustring& text, const link_collection& links, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when a link is clicked within the control.
      /// @remarks Typically, the xtd::forms::link_label::link_clicked event is handled to perform tasks when the user clicks on a link in the control. The event handler for the xtd::forms::link_label::link_clicked event is passed an instance of the xtd::forms::link_label_clicked_event_args class that contains a xtd::forms::link object that is associated with the link that was clicked. You can use information specified in the xtd::forms::link::link_data property of xtd::forms::link class to determine which link was clicked or what type of task to perform when the link is clicked. For example, if a xtd::forms::link_label control has a xtd::forms::link object defined with its xtd::forms::link::link_data property set to the string www.microsoft.com, you can use this information in an event handler for the xtd::forms::link_label::link_clicked event to display the Web site.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
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
      /// @return xtd::forms::link_label::link corresponding to the point.
      link_label::link& point_in_link(const xtd::drawing::point& point);
      /// @}
      
    private:
      xtd::drawing::point get_text_location(size_t line) const noexcept;
      std::vector<std::tuple<xtd::drawing::rectangle, bool>> generate_text_rects() const noexcept;
      xtd::drawing::font link_font() const noexcept;
      void on_links_link_added(size_t pos, const link& link);
      void on_links_link_removed(size_t pos, const link& link);
      void on_links_link_updated(size_t pos, const link& link);

      std::shared_ptr<data> data_;
    };
  }
}

