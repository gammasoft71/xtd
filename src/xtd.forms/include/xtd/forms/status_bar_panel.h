/// @file
/// @brief Contains xtd::forms::status_bar_panel container.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "component.h"
#include "const_control_ref.h"
#include "context_menu.h"
#include "control_ref.h"
#include "horizontal_alignment.h"
#include "image_list.h"
#include "status_bar_panel_auto_size.h"
#include "status_bar_panel_border_style.h"
#include "status_bar_panel_style.h"
#include <xtd/event>
#include <xtd/event_handler>
#include <xtd/iequatable>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    class status_bar;
    /// @endcond
    
    /// @brief Represents a xtd::forms::status_bar panel.
    /// @par Header
    /// @code #include <xtd/forms/status_bar_panel> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::status_bar_panel control.
    /// @include status_bar.cpp
    /// @remarks A xtd::forms::status_bar_panel represents an individual panel in the xtd::forms::status_bar::status_bar_panel_collection of a xtd::forms::status_bar control. A xtd::forms::status_bar_panel can contain text and/or an image that can be used to reflect the status of an application. Use the xtd::forms::status_bar::status_bar_panel_collection, accessible through the xtd::forms::status_bar::panels property of a xtd::forms::status_bar control, to retrieve, add, or remove an individual xtd::forms::status_bar_panel.
    /// @remarks The xtd::forms::status_bar_panel provides properties that enable you to modify the display behavior of a panel within a xtd::forms::status_bar control. You can use the xtd::forms::status_bar_panel::image property to display an image within a panel. This property can be used to provide a graphical representation of state in an application. The xtd::forms::status_bar_panel::alignment property enables you to specify how text and/or an image is aligned within the panel. To ensure that your panel is sized properly to fit the text of the panel, you can use the xtd::forms::status_bar_panel::auto_size property to automatically resize the panel to fit the text of the panel or to fill the remaining space within the xtd::forms::status_bar control. The xtd::forms::status_bar_panel::min_width property enables you to specify a minimum width for the panel to ensure that it does not get smaller than the data it is intended to display.
    /// @remarks The xtd::forms::status_bar control is typically used to display Help information or state information about your application. Often, it is important to display additional information about data that is presented in a panel. You can use the xtd::forms::status_bar_panel::tool_tip_text property to display information whenever the mouse pointer rests on a panel.
    /// @remarks Although the xtd::forms::status_bar control is typically used to display textual information, you can also provide your own type of display to a xtd::forms::status_bar_panel. The xtd::forms::status_bar_panel::style property enables you to specify how the xtd::forms::status_bar_panel will be drawn. By default, the xtd::forms::status_bar_panel::style property is used to display the value of the xtd::forms::status_bar_panel_style::text property (and an image, if specified in the xtd::forms::status_bar_panel::image property). If the property is set to xtd::forms::status_bar_panel_style::owner_draw, you can draw your own information into the panel. You can use this feature to draw a progress bar or an animated image in the panel.
    /// @remarks When you create an instance of the xtd::forms::status_bar_panel class, the read/write properties are set to initial values. For a list of these values, see the xtd::forms::status_bar_panel::status_bar_panel constructor.
    class status_bar_panel : public xtd::forms::component, public xtd::iequatable<status_bar_panel> {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialises a new instance of xtd::forms::status_bar_panel class.
      /// @remarks When you create an instance of StatusBarPanel, the following read/write properties are set to initial values.
      /// | Property                                    | Initial value                                     |
      /// | ------------------------------------------- | ------------------------------------------------- |
      /// | xtd::forms::status_bar_panel::alignment     | xtd::forms::horizontal_alignment::left            |
      /// | xtd::forms::status_bar_panel::auto_size     | xtd::forms::status_bar_panel_auto_size::none      |
      /// | xtd::forms::status_bar_panel::border_style  | xtd::forms::status_bar_panel_border_style::sunken |
      /// | xtd::forms::status_bar_panel::image         | xtd::drawing::image::empty                        |
      /// | xtd::forms::status_bar_panel::min_width     | 10                                                |
      /// | xtd::forms::status_bar_panel::style         | xtd::forms::status_bar_panel_style::text          |
      /// | xtd::forms::status_bar_panel::text          | xtd::ustring::empty_string                        |
      /// | xtd::forms::status_bar_panel::tool_tip_text | xtd::ustring::empty_string                        |
      /// | xtd::forms::status_bar_panel::width         | 100                                               |
      status_bar_panel();
      /// @}
      
      /// @cond
      status_bar_panel(const status_bar_panel&) noexcept = default;
      status_bar_panel(status_bar_panel&&) noexcept = default;
      status_bar_panel& operator =(const status_bar_panel&) noexcept = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the alignment of text and icons within the status bar panel.
      /// @return One of the xtd::forms::horizontal_alignment values. The default is xtd::forms::horizontal_alignment::left.
      /// @remarks You can use this property to horizontally align the text and/or image assigned to the xtd::forms::status_bar_panel::image property within the borders of the panel. Text and im ge can be aligned to the left, right, or center of the xtd::forms::status_bar_panel. There is no way to independently position animage within the xtd::forms::status_bar_panel. For example, you cannot position an icon to the left side of the xtd::forms::status_bar_panel while aligning the text on the right side. The image is always positioned to the left side of the text regardless of how the text is aligned.
      xtd::forms::horizontal_alignment alignment() const noexcept;
      /// @brief Sets the alignment of text and icons within the status bar panel.
      /// @param value One of the xtd::forms::horizontal_alignment values. The default is xtd::forms::horizontal_alignment::left.
      /// @return This current instance.
      /// @remarks You can use this property to horizontally align the text and/or image assigned to the xtd::forms::status_bar_panel::image property within the borders of the panel. Text and im ge can be aligned to the left, right, or center of the xtd::forms::status_bar_panel. There is no way to independently position animage within the xtd::forms::status_bar_panel. For example, you cannot position an icon to the left side of the xtd::forms::status_bar_panel while aligning the text on the right side. The image is always positioned to the left side of the text regardless of how the text is aligned.
      status_bar_panel& alignment(xtd::forms::horizontal_alignment value);
      
      /// @brief Gets a value indicating whether the status bar panel is automatically resized.
      /// @return One of the xtd::forms::status_bar_panel_auto_size values. The default is xtd::forms::status_bar_panel_auto_size::none.
      /// @remarks xtd::forms::status_bar_panel objects set to xtd::forms::status_bar_panel_auto_size::contents have precedence over those panels set to the xtd::forms::status_bar_panel_auto_size::spring value. For example, a xtd::forms::status_bar_panel that has its xtd::forms::status_bar_panel::auto_size property set to xtd::forms::status_bar_panel_auto_size::spring is shortened if a xtd::forms::status_bar_panel with the xtd::forms::status_bar_panel::auto_size property set to xtd::forms::status_bar_panel_auto_size::contents requires that space.
      /// @remarks You can use xtd::forms::status_bar_panel::auto_size to ensure that the contents of a xtd::forms::status_bar_panel are properly displayed in a xtd::forms::status_bar control that contains more than one panel. For example, you might want a panel that contains text to adjust automatically to the amount of text it is displaying (xtd::forms::status_bar_panel_auto_size::contents), while another panel on the xtd::forms::status_bar that displays an owner-drawn progress bar would need to be a fixed size (xtd::forms::status_bar_panel_auto_size::none).
      xtd::forms::status_bar_panel_auto_size auto_size() const noexcept;
      /// @brief Sets a value indicating whether the status bar panel is automatically resized.
      /// @param value One of the xtd::forms::status_bar_panel_auto_size values. The default is xtd::forms::status_bar_panel_auto_size::none.
      /// @return This current instance.
      /// @remarks xtd::forms::status_bar_panel objects set to xtd::forms::status_bar_panel_auto_size::contents have precedence over those panels set to the xtd::forms::status_bar_panel_auto_size::spring value. For example, a xtd::forms::status_bar_panel that has its xtd::forms::status_bar_panel::auto_size property set to xtd::forms::status_bar_panel_auto_size::spring is shortened if a xtd::forms::status_bar_panel with the xtd::forms::status_bar_panel::auto_size property set to xtd::forms::status_bar_panel_auto_size::contents requires that space.
      /// @remarks You can use xtd::forms::status_bar_panel::auto_size to ensure that the contents of a xtd::forms::status_bar_panel are properly displayed in a xtd::forms::status_bar control that contains more than one panel. For example, you might want a panel that contains text to adjust automatically to the amount of text it is displaying (xtd::forms::status_bar_panel_auto_size::contents), while another panel on the xtd::forms::status_bar that displays an owner-drawn progress bar would need to be a fixed size (xtd::forms::status_bar_panel_auto_size::none).
      status_bar_panel& auto_size(xtd::forms::status_bar_panel_auto_size value);
      
      /// @brief Gets the border style of the status bar panel.
      /// @return One of the xtd::forms::status_bar_panel_border_style values. The default is xtd::forms::status_bar_panel_border_style::sunken.
      /// @remarks You can use this property to differentiate a panel from other panels in a xtd::forms::status_bar control.
      xtd::forms::status_bar_panel_border_style border_style() const noexcept;
      /// @brief Sets the border style of the status bar panel.
      /// @param value One of the xtd::forms::status_bar_panel_border_style values. The default is xtd::forms::status_bar_panel_border_style::sunken.
      /// @return This current instance.
      /// @remarks You can use this property to differentiate a panel from other panels in a xtd::forms::status_bar control.
      status_bar_panel& border_style(xtd::forms::status_bar_panel_border_style value);
      
      /// @brief Gets the control to be displayed in the control status bar panel.
      /// @return A xtd::forms::control to be displayed in the control status bar panel. The default is std::nullopt.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::status_bar_panel::style property value is set to xtd::forms::status_bar_panel_style::control.
      std::optional<control_ref> control() const noexcept;
      /// @brief Sets the control to be displayed in the control status bar panel.
      /// @param value A xtd::forms::control to be displayed in the control status bar panel. The default is std::nullopt.
      /// @return This current instance.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::status_bar_panel::style property value is set to xtd::forms::status_bar_panel_style::control.
      status_bar_panel& control(const xtd::forms::control& value);
      /// @brief Resets the control to be displayed in the control status bar panel.
      /// @param value nullptr.
      /// @return This current instance.
      /// @remarks You can specify a xtd::forms::control to be displayed. This property is not used unless the xtd::forms::status_bar_panel::style property value is set to xtd::forms::status_bar_panel_style::control.
      status_bar_panel& control(std::nullptr_t value);
      
      /// @brief Gets the image to display within the status bar panel.
      /// @return An xtd::drawing::image that represents the image to display in the panel.
      /// @remarks You can use this property to display an image that represents the state of your application or a process within your application. For example, you can display an image in a xtd::forms::status_bar_panel to indicate whether a file save operation is in progress or complete.
      /// @note There is no way to independently position an image within the xtd::forms::status_bar_panel. For example, you cannot position an image to the left side of the xtd::forms::status_bar_panel while aligning the text on the right side using the xtd::forms::status_bar_panel::alignment property. The image is always positioned to the left side of the panel's text regardless of how the text is aligned.
      const xtd::drawing::image& image() const noexcept;
      /// @brief Sets the image to display within the status bar panel.
      /// @param value An xtd::drawing::image that represents the image to display in the panel.
      /// @return This current instance.
      /// @remarks You can use this property to display an image that represents the state of your application or a process within your application. For example, you can display an image in a xtd::forms::status_bar_panel to indicate whether a file save operation is in progress or complete.
      /// @note There is no way to independently position an image within the xtd::forms::status_bar_panel. For example, you cannot position an image to the left side of the xtd::forms::status_bar_panel while aligning the text on the right side using the xtd::forms::status_bar_panel::alignment property. The image is always positioned to the left side of the panel's text regardless of how the text is aligned.
      status_bar_panel& image(const xtd::drawing::image& value);
      
      /// @brief Gets the minimum allowed width of the status bar panel within the xtd::forms::status_bar control.
      /// @return The minimum width, in pixels, of the xtd::forms::status_bar_panel
      /// @remarks The xtd::forms::status_bar_panel::min_width property is used when the xtd::forms::status_bar_panel::auto_size property is set to xtd::forms::status_bar_panel_auto_size::contents or xtd::forms::status_bar_panel_auto_size::spring to prevent the xtd::forms::status_bar_panel from automatically resizing to a width that is too small. When the xtd::forms::status_bar_panel::auto_size property is set to xtd::forms::status_bar_panel_auto_size::none, the xtd::forms::status_bar_panel::min_width property is automatically set to the same value as the xtd::forms::status_bar_panel::width property.
      int32 min_width() const noexcept;
      /// @brief Sets the minimum allowed width of the status bar panel within the xtd::forms::status_bar control.
      /// @param value The minimum width, in pixels, of the xtd::forms::status_bar_panel
      /// @exception xtd::argument_exception A value less than 0 is assigned to the property.
      /// @remarks The xtd::forms::status_bar_panel::min_width property is used when the xtd::forms::status_bar_panel::auto_size property is set to xtd::forms::status_bar_panel_auto_size::contents or xtd::forms::status_bar_panel_auto_size::spring to prevent the xtd::forms::status_bar_panel from automatically resizing to a width that is too small. When the xtd::forms::status_bar_panel::auto_size property is set to xtd::forms::status_bar_panel_auto_size::none, the xtd::forms::status_bar_panel::min_width property is automatically set to the same value as the xtd::forms::status_bar_panel::width property.
      status_bar_panel& min_width(int32 value);
      
      /// @brief Gets the name of the xtd::forms::status_bar_panel.
      /// @return The name of the xtd::forms::status_bar_panel.
      /// @remarks The xtd::forms::status_bar_panel::name property corresponds to the key for a xtd::forms::status_bar_panel in the xtd::forms::status_bar::status_bar_panel_collection.
      const xtd::ustring& name() const noexcept;
      /// @brief Sets the name of the xtd::forms::status_bar_panel.
      /// @param value The name of the xtd::forms::status_bar_panel.
      /// @return This current instance.
      /// @remarks The xtd::forms::status_bar_panel::name property corresponds to the key for a xtd::forms::status_bar_panel in the xtd::forms::status_bar::status_bar_panel_collection.
      status_bar_panel& name(const xtd::ustring& value);
      
      /// @brief Gets the xtd::forms::status_bar control that the status bar panel is assigned to.
      /// @return The xtd::forms::status_bar control that the xtd::forms::status_bar_panel is assigned to.
      std::optional<std::reference_wrapper<xtd::forms::status_bar>> parent() const noexcept;
      
      /// @brief Gets the style of the status bar panel.
      /// @return One of the xtd::forms::status_bar_panel_style values. The default is xtd::forms::status_bar_panel_style::text.
      /// @remarks You can use this property to indicate whether a xtd::forms::status_bar_panel displays text or whether the panel is managed as an owner-drawn xtd::forms::status_bar_panel. To determine when a xtd::forms::status_bar_panel needs to be drawn, create an event handler for the xtd::forms::status_bar::draw_item event of the xtd::forms::status_bar control. The xtd::forms::status_bar_draw_item_event_args passed as a parameter to an event handler of the xtd::forms::status_bar::draw_item event enables you to determine which panel needs to be drawn. The xtd::forms::status_bar_draw_item_event_args also provides a xtd::drawing::graphics object you can use to perform drawing tasks on the xtd::forms::status_bar_panel.
      xtd::forms::status_bar_panel_style style() const noexcept;
      /// @brief Sets the style of the status bar panel.
      /// @param value One of the xtd::forms::status_bar_panel_style values. The default is xtd::forms::status_bar_panel_style::text.
      /// @return This current instance.
      /// @remarks You can use this property to indicate whether a xtd::forms::status_bar_panel displays text or whether the panel is managed as an owner-drawn xtd::forms::status_bar_panel. To determine when a xtd::forms::status_bar_panel needs to be drawn, create an event handler for the xtd::forms::status_bar::draw_item event of the xtd::forms::status_bar control. The xtd::forms::status_bar_draw_item_event_args passed as a parameter to an event handler of the xtd::forms::status_bar::draw_item event enables you to determine which panel needs to be drawn. The xtd::forms::status_bar_draw_item_event_args also provides a xtd::drawing::graphics object you can use to perform drawing tasks on the xtd::forms::status_bar_panel.
      status_bar_panel& style(xtd::forms::status_bar_panel_style value);
      
      /// @brief Gets an object that contains data about the xtd::forms::status_bar_panel.
      /// @return An std::any that contains data about the xtd::forms::status_bar_panel. The default is empty.
      /// @remarks Retrieves or assigns the data currently associated with the xtd::forms::status_bar_panel. Any std::any type can be assigned to this property.
      std::any tag() const noexcept;
      /// @brief Sets an object that contains data about the xtd::forms::status_bar_panel.
      /// @param value An std::any that contains data about the xtd::forms::status_bar_panel. The default is empty.
      /// @return This current instance.
      /// @remarks Retrieves or assigns the data currently associated with the xtd::forms::status_bar_panel. Any std::any type can be assigned to this property.
      status_bar_panel& tag(std::any value);
      
      /// @brief Gets the text of the status bar panel.
      /// @return The text displayed in the panel. The default is an empty string ("").
      /// @remarks This property represents the text that is displayed when the xtd::forms::status_bar_panel::style property is set to xtd::forms::status_bar_panel::text. You can use this property to display information about your application in a xtd::forms::status_bar control. For example, you can use the xtd::forms::status_bar_panel::text property to display Help information when the user moves the mouse over a menu or to display the name and location of a file that is opened in an application. To align the text within a xtd::forms::status_bar_panel, use the xtd::forms::status_bar_panel::alignment property.
      const xtd::ustring& text() const noexcept;
      /// @brief Sets the text of the status bar panel.
      /// @param value The text displayed in the panel. The default is an empty string ("").
      /// @return This current instance.
      /// @remarks This property represents the text that is displayed when the xtd::forms::status_bar_panel::style property is set to xtd::forms::status_bar_panel::text. You can use this property to display information about your application in a xtd::forms::status_bar control. For example, you can use the xtd::forms::status_bar_panel::text property to display Help information when the user moves the mouse over a menu or to display the name and location of a file that is opened in an application. To align the text within a xtd::forms::status_bar_panel, use the xtd::forms::status_bar_panel::alignment property.
      status_bar_panel& text(const xtd::ustring& value);
      
      /// @brief Gets ToolTip text associated with the status bar panel.
      /// @return The ToolTip text for the panel.
      /// @remarks You can use this property to display additional information in a ToolTip when the mouse pointer rests on a xtd::forms::status_bar_panel. For example, you can display a ToolTip that provides data transfer speed for a xtd::forms::status_bar_panel that displays the status of a file transfer.
      /// @remarks To display ToolTips for other controls in your application, use the xtd::forms::tool_tip control.
      const xtd::ustring& tool_tip_text() const noexcept;
      /// @brief Sets ToolTip text associated with the status bar panel.
      /// @param value The ToolTip text for the panel.
      /// @return This current instance.
      /// @remarks You can use this property to display additional information in a ToolTip when the mouse pointer rests on a xtd::forms::status_bar_panel. For example, you can display a ToolTip that provides data transfer speed for a xtd::forms::status_bar_panel that displays the status of a file transfer.
      /// @remarks To display ToolTips for other controls in your application, use the xtd::forms::tool_tip control.
      status_bar_panel& tool_tip_text(const xtd::ustring& value);
      
      /// @brief Gets the width of the status bar panel within the xtd::forms::status_bar control.
      /// @return The width, in pixels, of the xtd::forms::status_bar_panel.
      /// @remarks The xtd::forms::status_bar_panel::width property always reflects the actual width of a xtd::forms::status_bar_panel and cannot be smaller than the xtd::forms::status_bar_panel::min_width property. To automatically resize the width of the xtd::forms::status_bar_panel to the contents of the xtd::forms::status_bar_panel, you can use the xtd::forms::status_bar_panel::auto_size property.
      int32 width() const noexcept;
      /// @brief Sets the width of the status bar panel within the xtd::forms::status_bar control.
      /// @param value The width, in pixels, of the xtd::forms::status_bar_panel.
      /// @return This current instance.
      /// @remarks The xtd::forms::status_bar_panel::width property always reflects the actual width of a xtd::forms::status_bar_panel and cannot be smaller than the xtd::forms::status_bar_panel::min_width property. To automatically resize the width of the xtd::forms::status_bar_panel to the contents of the xtd::forms::status_bar_panel, you can use the xtd::forms::status_bar_panel::auto_size property.
      status_bar_panel& width(int32 value);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Begins the initialization of a xtd::forms::status_bar_panel.
      /// @remarks This method is used to start the initialization of a component that is used on a form or used by another component. The xtd::forms::status_bar_panel::end_init method ends the initialization. Using the xtd::forms::status_bar_panel::begin_init and xtd::forms::status_bar_panel::end_init methods prevents the control from being used before it is fully initialized.
      void begin_init();
      
      bool equals(const status_bar_panel& other) const noexcept override;
      
      /// @brief Ends the initialization of a xtd::forms::status_bar_panel.
      /// @remarks This method is used to end the initialization of a component that is used on a form or used by another component. The xtd::forms::status_bar_panel::end_init method ends the initialization. Using the xtd::forms::status_bar_panel::begin_init and xtd::forms::status_bar_panel::end_init methods prevents the control from being used before it is fully initialized.
      void end_init();
      
      /// @brief Returns a string that represents the xtd::forms::status_bar_panel control.
      /// @return A xtd::ustring that represents the current xtd::forms::status_bar_panel.
      /// @remarks The xtd::forms::status_bar_panel::to_string method returns a string that includes the type and the value of the xtd::forms::status_bar_panel::style and xtd::forms::status_bar_panel::text properties.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create a control status bar panel with specified text and control.
      /// @param text The text displayed on the status bar panel.
      /// @param control A xtd::forms::control to be displayed in the control status bar panel.
      /// @return New xtd::forms::status_bar_panel created.
      static status_bar_panel create_control(const xtd::ustring& text, const xtd::forms::control& control);
      /// @brief A factory to create a control status bar panel with specified control.
      /// @param control A xtd::forms::control to be displayed in the control status bar panel.
      /// @return New xtd::forms::status_bar_panel created.
      static status_bar_panel create_control(const xtd::forms::control& control);
      
      /// @brief A factory to create a status bar panel with specified text.
      /// @param text The text displayed on the status bar panel.
      /// @return New xtd::forms::status_bar_panel created.
      static status_bar_panel create_panel(const xtd::ustring& text);
      /// @brief A factory to create a status bar panel with specified image index.
      /// @param image The xtd::drawing::image assigned to the status bar panel.
      /// @return New xtd::forms::status_bar_panel created.
      static status_bar_panel create_panel(const xtd::drawing::image& image);
      /// @brief A factory to create a status bar panel with specified text and image index.
      /// @param text The text displayed on the status bar panel.
      /// @param image The xtd::drawing::image assigned to the status bar panel.
      /// @return New xtd::forms::status_bar_panel created.
      static status_bar_panel create_panel(const xtd::ustring& text, const xtd::drawing::image& image);
      /// @}
      
    private:
      friend xtd::forms::status_bar;
      std::shared_ptr<data> data_;
    };
    
    /// @brief Represents a xtd::forms::status_bar_item reference.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using status_bar_panel_ref = std::reference_wrapper<status_bar_panel>;
  }
}
