/// @file
/// @brief Contains xtd::forms::label control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "border_style.h"
#include "content_alignment.h"
#include "flat_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows label.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of label control.
    /// @include label.cpp
    /// @par Windows
    /// @image html label_w.png
    /// <br>
    /// @image html label_wd.png
    /// @par macOS
    /// @image html label_m.png
    /// <br>
    /// @image html label_md.png
    /// @par Gnome
    /// @image html label_g.png
    /// <br>
    /// @image html label_gd.png
    /// @par Examples
    /// The following code example demonstrate the use of label control.
    /// @include hello_world_label.cpp
    /// @par Windows
    /// @image html hello_world_label_w.png
    /// <br>
    /// @image html hello_world_label_wd.png
    /// @par macOS
    /// @image html hello_world_label_m.png
    /// <br>
    /// @image html hello_world_label_md.png
    /// @par Gnome
    /// @image html hello_world_label_g.png
    /// <br>
    /// @image html hello_world_label_gd.png
    class forms_export_ label : public control {
    public:
      /// @brief Initializee a new instance of label class.
      label();

      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual xtd::forms::border_style border_style() const {return border_style_;}
      /// @brief Sets the border style for the control.
      /// @param border_style One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current label instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual xtd::forms::label& border_style(xtd::forms::border_style border_style);
      
      /// @brief Gets the flat style appearance of the label control.
      /// @return One of the xtd::forms::flat_style values. The default value is xtd::forms::flat_style::standard.
      /// @remarks When the flat_style property is set to xtd::forms::flat_style::system, any values assigned to the image_list, image, image_index, and image_align properties are ignored. In addition, the text_align property ignores any property values that are not vertical property settings. Horizontally aligned settings of the text_align property are aligned to the top of the control. For example, if you set the text_align property to content_alignment::top_center, content_alignment::middle_center, or content_alignment::bottom_center, when the flat_style property is set to xtd::forms::flat_style::system, the text in the label control will be aligned to the top and center locations within the bounds of the control.
      virtual xtd::forms::flat_style flat_style() const {return flat_style_;}
      /// @brief Sets the flat style appearance of the label control.
      /// @param flat_style One of the xtd::forms::flat_style values. The default value is xtd::forms::flat_style::standard.
      /// @return Current label instance.
      /// @remarks When the flat_style property is set to xtd::forms::flat_style::system, any values assigned to the image_list, image, image_index, and image_align properties are ignored. In addition, the text_align property ignores any property values that are not vertical property settings. Horizontally aligned settings of the text_align property are aligned to the top of the control. For example, if you set the text_align property to content_alignment::top_center, content_alignment::middle_center, or content_alignment::bottom_center, when the flat_style property is set to xtd::forms::flat_style::system, the text in the label control will be aligned to the top and center locations within the bounds of the control.
      virtual xtd::forms::label& flat_style(xtd::forms::flat_style flat_style);

      xtd::drawing::size default_size() const override {return {100, 23};}
      
      /// @brief Gets the alignment of the text on the button control.
      /// @return One of the content_alignment values. The default is middle_center.
      /// @remarks You can use this property to align the text within a label to match the layout of controls on your form. For example, if your controls are located to the right edge of the labels, you can set the text_align property to one of the right-aligned horizontal alignments (top_right, middle_right, bottom_right) and the text will be aligned with the right edge of the labels to align with your controls.
      virtual xtd::forms::content_alignment text_align() const {return text_align_;}
      /// @brief Gets the alignment of the text on the button control.
      /// @param text_align One of the content_alignment values. The default is middle_center.
      /// @return Current label instance.
      /// @remarks You can use this property to align the text within a label to match the layout of controls on your form. For example, if your controls are located to the right edge of the labels, you can set the text_align property to one of the right-aligned horizontal alignments (top_right, middle_right, bottom_right) and the text will be aligned with the right edge of the labels to align with your controls.
      virtual xtd::forms::label& text_align(xtd::forms::content_alignment text_align);
      
      /// @brief Occurs when the value of the xtd::forms::label::text_align property has changed.
      event<label, event_handler> text_align_changed;

    protected:
      xtd::forms::create_params create_params() const override;
      
      xtd::drawing::size measure_control() const override;
      
      void on_font_changed(const xtd::event_args& e) override;
      void on_handle_created(const event_args& e) override;
      void on_paint(xtd::forms::paint_event_args& e) override;      
      void on_resize(const xtd::event_args& e) override;
      
      /// @brief Raises the xtd::forms::label::text_align_changed event.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::label::on_text_align_changed in a derived class, be sure to call the base class's xtd::forms::label::on_text_align_changed method.
      virtual void on_text_align_changed(const xtd::event_args& e);
      
      void on_text_changed(const xtd::event_args& e) override;

      /// @cond
      xtd::forms::border_style border_style_ = xtd::forms::border_style::none;
      xtd::forms::flat_style flat_style_ = xtd::forms::flat_style::standard;
      xtd::forms::content_alignment text_align_ = xtd::forms::content_alignment::top_left;
      /// @endcond
    };
  }
}
