/// @file
/// @brief Contains xtd::forms::scroll_bar control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows scroll bar.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ scroll_bar : public control {
    public:
      /// @brief Gets a value to be added to or subtracted from the xtd::forms::scroll_bar::value property when the scroll box is moved a large distance.
      /// @return A numeric value. The default value is 10.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than 0.
      /// @remarks When the user clicks in the scroll bar track on either side of the scroll box, the xtd::forms::scroll_bar::value property changes according to the value set in the xtd::forms::scroll_bar::large_change property.
      /// @note You can handle key press events so that when the user presses the PAGE UP or PAGE DOWN key the scroll box moves.
      /// @remarks User interface guidelines suggest that the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties are set relative to the size of the view that the user sees, not to the total size including the unseen part. For example, if you have a picture box with scroll bars displaying a large image, the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties should be set relative to the size of the picture box, not to the size of the image.
      virtual int32_t large_change() const;
      /// @brief Sets a value to be added to or subtracted from the xtd::forms::scroll_bar::value property when the scroll box is moved a large distance.
      /// @param large_change A numeric value. The default value is 10.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than 0.
      /// @remarks When the user clicks in the scroll bar track on either side of the scroll box, the xtd::forms::scroll_bar::value property changes according to the value set in the xtd::forms::scroll_bar::large_change property.
      /// @note You can handle key press events so that when the user presses the PAGE UP or PAGE DOWN key the scroll box moves.
      /// @remarks User interface guidelines suggest that the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties are set relative to the size of the view that the user sees, not to the total size including the unseen part. For example, if you have a picture box with scroll bars displaying a large image, the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties should be set relative to the size of the picture box, not to the size of the image.
      virtual scroll_bar& large_change(int32_t large_change);
      
      /// @brief Gets the upper limit of values of the scrollable range.
      /// @return A numeric value. The default value is 100.
      /// @remarks You might consider adjusting the xtd::forms::scroll_bar::maximum property dynamically to match the size of the scroll bar's parent in proportion to pixel size or to the number of rows or lines displayed.
      /// @remarks The maximum value can only be reached programmatically. The value of a scroll bar cannot reach its maximum value through user interaction at run time. The maximum value that can be reached through user interaction is equal to 1 plus the xtd::forms::scroll_bar::maximum property value minus the xtd::forms::scroll_bar::large_change property value. If necessary, you can set the xtd::forms::scroll_bar::maximum property to the size of the object -1 to account for the term of 1.
      virtual int32_t maximum() const;
      /// @brief Sets the upper limit of values of the scrollable range.
      /// @param maximum A numeric value. The default value is 100.
      /// @remarks You might consider adjusting the xtd::forms::scroll_bar::maximum property dynamically to match the size of the scroll bar's parent in proportion to pixel size or to the number of rows or lines displayed.
      /// @remarks The maximum value can only be reached programmatically. The value of a scroll bar cannot reach its maximum value through user interaction at run time. The maximum value that can be reached through user interaction is equal to 1 plus the xtd::forms::scroll_bar::maximum property value minus the xtd::forms::scroll_bar::large_change property value. If necessary, you can set the xtd::forms::scroll_bar::maximum property to the size of the object -1 to account for the term of 1.
      virtual scroll_bar& maximum(int32_t maximum);
      
      /// @brief Gets the lower limit of values of the scrollable range.
      /// @return A numeric value. The default value is 0.
      virtual int32_t minimum() const;
      /// @brief Sets the lower limit of values of the scrollable range.
      /// @param minimum A numeric value. The default value is 0.
      virtual scroll_bar& minimum(int32_t minimum);
      
      /// @brief Gets the value to be added to or subtracted from the xtd::forms::scroll_bar::value property when the scroll box is moved a small distance.
      /// @return A numeric value. The default value is 1.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than 0.
      /// @remarks When the user presses one of the arrow keys or clicks one of the scroll bar buttons, the xtd::forms::scroll_bar::value property changes according to the value set in the xtd::forms::scroll_bar::small_change property.
      /// @remarks User interface guidelines suggest that the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties are set relative to the size of the view that the user sees, not to the total size including the unseen part. For example, if you have a picture box with scroll bars displaying a large image, the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties should be set relative to the size of the picture box, not to the size of the image.
      virtual int32_t small_change() const;
      /// @brief Sets the value to be added to or subtracted from the xtd::forms::scroll_bar::value property when the scroll box is moved a small distance.
      /// @param small_change A numeric value. The default value is 1.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than 0.
      /// @remarks When the user presses one of the arrow keys or clicks one of the scroll bar buttons, the xtd::forms::scroll_bar::value property changes according to the value set in the xtd::forms::scroll_bar::small_change property.
      /// @remarks User interface guidelines suggest that the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties are set relative to the size of the view that the user sees, not to the total size including the unseen part. For example, if you have a picture box with scroll bars displaying a large image, the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties should be set relative to the size of the picture box, not to the size of the image.
      virtual scroll_bar& small_change(int32_t small_change);

      /// @brief Gets or sets a numeric value that represents the current position of the scroll box on the scroll bar control.
      /// @return A numeric value that is within the Minimum and Maximum range. The default value is 0.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than the xtd::forms::scroll_bar::minimum property value. -or- The assigned value is greater than the xtd::forms::scroll_bar::maximum property value.
      virtual int32_t value() const;
      /// @brief Sets or sets a numeric value that represents the current position of the scroll box on the scroll bar control.
      /// @param value A numeric value that is within the Minimum and Maximum range. The default value is 0.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than the xtd::forms::scroll_bar::minimum property value. -or- The assigned value is greater than the xtd::forms::scroll_bar::maximum property value.
      virtual scroll_bar& value(int32_t value);

      /// @brief Occurs when the scroll box has been moved by either a mouse or keyboard action.
      /// @ingroup events
      event<scroll_bar, event_handler> scroll;
      
      /// @brief Occurs when the xtd::forms::scroll_bar::value property is changed, either by a xtd::forms::scroll_bar::scroll event or programmatically.
      /// @ingroup events
      event<scroll_bar, event_handler> value_changed;

    protected:
      /// @brief Initializes a new instance of scroll_bar class.
      scroll_bar() = default;
 
      xtd::forms::create_params create_params() const override;
      
      void on_handle_created(const event_args& e) override;

      /// @brief Raises the xtd::forms::scroll_bar::scroll event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The td::forms::scroll_bar::on_scroll method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::scroll_bar::on_scroll in a derived class, be sure to call the base class' xtd::forms::scroll_bar::on_scroll method so that registered delegates receive the event.
      virtual void on_scroll(const event_args& e);
      
      /// @brief Raises the scroll_bar::value_changed event.
      /// @param e The event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The td::forms::scroll_bar::on_value_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::scroll_bar::on_value_changed in a derived class, be sure to call the base class' xtd::forms::scroll_bar::on_value_changed method so that registered delegates receive the event.
      virtual void on_value_changed(const event_args& e);

      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      
      /// @cond
      int32_t large_change_ = 10;
      int32_t maximum_ = 100;
      int32_t minimum_ = 0;
      int32_t small_change_ = 1;
      int32_t value_ = 0;
      bool v_scroll_ = true;
      /// @endcond
      
    private:
      void wm_scroll(message& message);
    };
  }
}
