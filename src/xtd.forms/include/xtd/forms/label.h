/// @file
/// @brief Contains xtd::forms::label control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "border_sides.h"
#include "border_style.h"
#include "content_alignment.h"
#include "flat_style.h"
#include "image_list.h"
#include "shadows.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows label.
    /// @par Header
    /// @code #include <xtd/forms/label> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                            | macOS                              | Gnome                              |
    /// | ----- | ---------------------------------- | ---------------------------------- | ---------------------------------- |
    /// | Light |  @image html control_label_w.png   |  @image html control_label_m.png   |  @image html control_label_g.png   |
    /// | Dark  |  @image html control_label_wd.png  |  @image html control_label_md.png  |  @image html control_label_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of label control.
    /// @include label.cpp
    /// @par Examples
    /// The following code example demonstrates the use of label control.
    /// @include hello_world_label.cpp
    class forms_export_ label : public control {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of label class.
      label();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value indicating whether the ellipsis character (...) appears at the right edge of the xtd::forms::label, denoting that the xtd::forms::label text extends beyond the specified length of the xtd::forms::label.
      /// @return true if the additional label text is to be indicated by an ellipsis; otherwise, false. The default is false.
      /// @remarks Set xtd::forms::label::auto_ellipsis to true to display text that extends beyond the width of the xtd::forms::label in a tooltip when the user passes over the control with the mouse. If xtd::forms::label::auto_size is true, the label will grow to fit the text and an ellipsis will not appear.
      /// @note If the font is taller than the height of the xtd::forms::label and xtd::forms::label::auto_ellipsis is true, you must set xtd::forms::label::auto_size to false for text to be drawn.
      virtual bool auto_ellipsis() const noexcept;
      /// @brief Sets a value indicating whether the ellipsis character (...) appears at the right edge of the xtd::forms::label, denoting that the xtd::forms::label text extends beyond the specified length of the xtd::forms::label.
      /// @param value true if the additional label text is to be indicated by an ellipsis; otherwise, false. The default is false.
      /// @return Current label instance.
      /// @remarks Set xtd::forms::label::auto_ellipsis to true to display text that extends beyond the width of the xtd::forms::label in a tooltip when the user passes over the control with the mouse. If xtd::forms::label::auto_size is true, the label will grow to fit the text and an ellipsis will not appear.
      /// @note If the font is taller than the height of the xtd::forms::label and xtd::forms::label::auto_ellipsis is true, you must set xtd::forms::label::auto_size to false for text to be drawn.
      virtual label& auto_ellipsis(bool value);
      
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      virtual forms::border_sides border_sides() const noexcept;
      /// @brief Sets the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      /// @return Current label instance.
      virtual label& border_sides(forms::border_sides border_sides);
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual xtd::forms::border_style border_style() const noexcept;
      /// @brief Sets the border style for the control.
      /// @param border_style One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current label instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual xtd::forms::label& border_style(xtd::forms::border_style border_style);
      /// @brief Resets the border style for the control.
      /// @param border_style nullptr.
      /// @return Current label instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual xtd::forms::label& border_style(std::nullptr_t border_style);
      
      using control::control_appearance;
      control& control_appearance(forms::control_appearance value) override;
      
      /// @brief Gets the flat style appearance of the label control.
      /// @return One of the xtd::forms::flat_style values. The default value is xtd::forms::flat_style::standard.
      /// @remarks When the flat_style property is set to xtd::forms::flat_style::system, any values assigned to the image_list, image, image_index, and image_align properties are ignored. In addition, the text_align property ignores any property values that are not vertical property settings. Horizontally aligned settings of the text_align property are aligned to the top of the control. For example, if you set the text_align property to content_alignment::top_center, content_alignment::middle_center, or content_alignment::bottom_center, when the flat_style property is set to xtd::forms::flat_style::system, the text in the label control will be aligned to the top and center locations within the bounds of the control.
      virtual xtd::forms::flat_style flat_style() const noexcept;
      /// @brief Sets the flat style appearance of the label control.
      /// @param flat_style One of the xtd::forms::flat_style values. The default value is xtd::forms::flat_style::standard.
      /// @return Current label instance.
      /// @remarks When the flat_style property is set to xtd::forms::flat_style::system, any values assigned to the image_list, image, image_index, and image_align properties are ignored. In addition, the text_align property ignores any property values that are not vertical property settings. Horizontally aligned settings of the text_align property are aligned to the top of the control. For example, if you set the text_align property to content_alignment::top_center, content_alignment::middle_center, or content_alignment::bottom_center, when the flat_style property is set to xtd::forms::flat_style::system, the text in the label control will be aligned to the top and center locations within the bounds of the control.
      virtual xtd::forms::label& flat_style(xtd::forms::flat_style flat_style);
      
      /// @brief Gets the image that is displayed on a label control.
      /// @return The Image displayed on the label control. The default value is xtd::drawing::image::empty.
      /// @remarks When the image property is set, the image_list property will be set to xtd::forms::image_list::empty, and the image_index property will be set to its default, -1.
      /// @note If the flat_style property is set to xtd::forms::flat_style::system, any images assigned to the image property are not displayed.
      virtual const drawing::image& image() const noexcept;
      /// @brief Sets the image that is displayed on a label control.
      /// @param value The Image displayed on the label control. The default value is xtd::drawing::image::empty.
      /// @return Current label instance.
      /// @remarks When the image property is set, the image_list property will be set to xtd::forms::image_list::empty, and the image_index property will be set to its default, -1.
      /// @note If the flat_style property is set to xtd::forms::flat_style::system, any images assigned to the image property are not displayed.
      virtual xtd::forms::label& image(const drawing::image& value);
      
      /// @brief Gets the alignment of the image on the label control.
      /// @return One of the content_alignment values. The default is middle_center.
      virtual xtd::forms::content_alignment image_align() const noexcept;
      /// @brief Gets the alignment of the image on the label control.
      /// @param value One of the content_alignment values. The default is xtd::forms::content_alignment::middle_center.
      /// @return Current label instance.
      virtual xtd::forms::label& image_align(content_alignment value);
      
      /// @brief Gets the image list index value of the image displayed on the label control.
      /// @return A zero-based index, which represents the image position in an image_list. The default is -1.
      /// @remarks When the image_index or image_list properties are set, the Image property is set to its default value, xtd::drawing::image::empty.
      /// @remarks image_key and image_index are mutually exclusive, meaning if one is set, the other is set to an invalid value and ignored. If you set the image_key property, the image_index property is automatically set to -1. Alternatively, if you set the image_index property, the image_key is automatically set to an empty string ("").
      /// @remarks If the image_list property value is changed to xtd::forms::image_list::empty, the image_index property returns its default value, -1. However, the assigned image_index value is retained internally and used when another image_list object is assigned to the image_list property. If the new image_list assigned to the image_list property has an imageList::_image_collection::size property value that is less than or equal to the value assigned to the image_index property minus one (to account for the collection being a zero-based index), the image_index property value is adjusted to one less than the size property value. For example, consider a button control whose image_list has three images and whose image_index property is set to 2. If a new image_list that has only two images is assigned to the button, the image_index value changes to 1.
      virtual int32 image_index() const noexcept;
      /// @brief Sets the image list index value of the image displayed on the label control.
      /// @param value A zero-based index, which represents the image position in an image_list. The default is -1.
      /// @return Current label instance.
      /// @remarks When the image_index or image_list properties are set, the Image property is set to its default value, xtd::drawing::image::empty.
      /// @remarks image_key and image_index are mutually exclusive, meaning if one is set, the other is set to an invalid value and ignored. If you set the image_key property, the image_index property is automatically set to -1. Alternatively, if you set the image_index property, the image_key is automatically set to an empty string ("").
      /// @remarks If the image_list property value is changed to xtd::forms::image_list::empty, the image_index property returns its default value, -1. However, the assigned image_index value is retained internally and used when another image_list object is assigned to the image_list property. If the new image_list assigned to the image_list property has an imageList::_image_collection::size property value that is less than or equal to the value assigned to the image_index property minus one (to account for the collection being a zero-based index), the image_index property value is adjusted to one less than the size property value. For example, consider a button control whose image_list has three images and whose image_index property is set to 2. If a new image_list that has only two images is assigned to the button, the image_index value changes to 1.
      virtual xtd::forms::label& image_index(int32 value);
      
      /// @brief Gets the image_list that contains the image displayed on a label control.
      /// @return An xtd::drawing::image_list. The default value is xtd::drawing::image_list::empty.
      virtual const forms::image_list& image_list() const noexcept;
      /// @brief Gets the image_list that contains the image displayed on a label control.
      /// @return An xtd::drawing::image_list. The default value is xtd::drawing::image_list::empty.
      virtual forms::image_list& image_list() noexcept;
      /// @brief Sets the image_list that contains the image displayed on a label control.
      /// @param value An xtd::drawing::image_list. The default value is xtd::drawing::image_list::empty.
      /// @return Current label instance.
      virtual xtd::forms::label& image_list(const forms::image_list& value);
      
      /// @brief Gets a value that allows to draw a drop shadow under the text.
      /// @return true allows to draw a drop shadow under the text; otherwise false. The default is false.
      virtual bool shadow() const noexcept;
      /// @brief Sets a value that allows to draw a drop shadow under the text.
      /// @param value true allows to draw a drop shadow under the text; otherwise false. The default is false.
      /// @return Current label instance.
      virtual xtd::forms::label& shadow(bool value);
      
      /// @brief Gets an xtd::forms::shadow array used to draw shadows under the text.
      /// @return An xtd::forms::shadow array used to draw shadows under the text.
      virtual const xtd::forms::shadows& shadows() const noexcept;
      /// @brief Sets an xtd::forms::shadow array used to draw shadows under the text.
      /// @param value An xtd::forms::shadow array used to draw shadows under the text.
      /// @return Current label instance.
      virtual xtd::forms::label& shadows(const xtd::forms::shadows& value);
      
      /// @brief Gets the alignment of the text on the button control.
      /// @return One of the content_alignment values. The default is middle_center.
      /// @remarks You can use this property to align the text within a label to match the layout of controls on your form. For example, if your controls are located to the right edge of the labels, you can set the text_align property to one of the right-aligned horizontal alignments (top_right, middle_right, bottom_right) and the text will be aligned with the right edge of the labels to align with your controls.
      virtual xtd::forms::content_alignment text_align() const noexcept;
      /// @brief Gets the alignment of the text on the button control.
      /// @param text_align One of the content_alignment values. The default is middle_center.
      /// @return Current label instance.
      /// @remarks You can use this property to align the text within a label to match the layout of controls on your form. For example, if your controls are located to the right edge of the labels, you can set the text_align property to one of the right-aligned horizontal alignments (top_right, middle_right, bottom_right) and the text will be aligned with the right edge of the labels to align with your controls.
      virtual xtd::forms::label& text_align(xtd::forms::content_alignment text_align);
      /// @}
      
      /// @name Methods
      
      /// @{
      using control::create;
      /// @brief A factory to create an xtd::forms::label with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::label.
      /// @param name The name of the xtd::forms::label.
      /// @return New xtd::forms::label created.
      static label create(const xtd::ustring& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::label with specified parent, text, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::label.
      /// @param text A string that represent text of the xtd::forms::label.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::label.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::label.
      /// @param name The name of the xtd::forms::label.
      /// @return New xtd::forms::label created.
      static label create(const control& parent, const xtd::ustring& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the value of the image property changes.
      /// @remarks This event is raised if the image property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<label, event_handler> image_changed;
      /// @brief Occurs when the value of the xtd::forms::label::text_align property has changed.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<label, event_handler> text_align_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      xtd::forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      xtd::drawing::size measure_control() const noexcept override;
      void on_font_changed(const xtd::event_args& e) override;
      
      /// @brief Raises the button_base::image_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_image_changed(const xtd::event_args& e);
      
      void on_paint(xtd::forms::paint_event_args& e) override;
      void on_resize(const xtd::event_args& e) override;
      
      /// @brief Raises the xtd::forms::label::text_align_changed event.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::label::on_text_align_changed in a derived class, be sure to call the base class's xtd::forms::label::on_text_align_changed method.
      virtual void on_text_align_changed(const xtd::event_args& e);
      
      void on_text_changed(const xtd::event_args& e) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
