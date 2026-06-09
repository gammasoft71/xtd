/// @file
/// @brief Contains xtd::forms::scroll_bar control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows scroll bar.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/scroll_bar>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ scroll_bar : public xtd::forms::control {
      struct data;
      
    public:
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value to be added to or subtracted from the xtd::forms::scroll_bar::value property when the scroll box is moved a large distance.
      /// @return A numeric value. The default value is 10.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than 0.
      /// @remarks When the user clicks in the scroll bar track on either side of the scroll box, the xtd::forms::scroll_bar::value property changes according to the value set in the xtd::forms::scroll_bar::large_change property.
      /// @note You can handle key press events so that when the user presses the PAGE UP or PAGE DOWN key the scroll box moves.
      /// @remarks User interface guidelines suggest that the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties are set relative to the size of the view that the user sees, not to the total size including the unseen part. For example, if you have a picture box with scroll bars displaying a large image, the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties should be set relative to the size of the picture box, not to the size of the image.
      [[nodiscard]] virtual auto large_change() const noexcept -> xtd::int32;
      /// @brief Sets a value to be added to or subtracted from the xtd::forms::scroll_bar::value property when the scroll box is moved a large distance.
      /// @param value A numeric value. The default value is 10.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than 0.
      /// @remarks When the user clicks in the scroll bar track on either side of the scroll box, the xtd::forms::scroll_bar::value property changes according to the value set in the xtd::forms::scroll_bar::large_change property.
      /// @note You can handle key press events so that when the user presses the PAGE UP or PAGE DOWN key the scroll box moves.
      /// @remarks User interface guidelines suggest that the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties are set relative to the size of the view that the user sees, not to the total size including the unseen part. For example, if you have a picture box with scroll bars displaying a large image, the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties should be set relative to the size of the picture box, not to the size of the image.
      virtual auto large_change(xtd::int32 value) -> scroll_bar&;
      
      /// @brief Gets the upper limit of values of the scrollable range.
      /// @return A numeric value. The default value is 100.
      /// @remarks You might consider adjusting the xtd::forms::scroll_bar::maximum property dynamically to match the size of the scroll bar's parent in proportion to pixel size or to the number of rows or lines displayed.
      /// @remarks The maximum value can only be reached programmatically. The value of a scroll bar cannot reach its maximum value through user interaction at run time. The maximum value that can be reached through user interaction is equal to 1 plus the xtd::forms::scroll_bar::maximum property value minus the xtd::forms::scroll_bar::large_change property value. If necessary, you can set the xtd::forms::scroll_bar::maximum property to the size of the object -1 to account for the term of 1.
      [[nodiscard]] virtual auto maximum() const noexcept -> xtd::int32;
      /// @brief Sets the upper limit of values of the scrollable range.
      /// @param value A numeric value. The default value is 100.
      /// @remarks You might consider adjusting the xtd::forms::scroll_bar::maximum property dynamically to match the size of the scroll bar's parent in proportion to pixel size or to the number of rows or lines displayed.
      /// @remarks The maximum value can only be reached programmatically. The value of a scroll bar cannot reach its maximum value through user interaction at run time. The maximum value that can be reached through user interaction is equal to 1 plus the xtd::forms::scroll_bar::maximum property value minus the xtd::forms::scroll_bar::large_change property value. If necessary, you can set the xtd::forms::scroll_bar::maximum property to the size of the object -1 to account for the term of 1.
      virtual auto maximum(xtd::int32 value) -> scroll_bar&;
      
      /// @brief Gets the lower limit of values of the scrollable range.
      /// @return A numeric value. The default value is 0.
      [[nodiscard]] virtual auto minimum() const noexcept -> xtd::int32;
      /// @brief Sets the lower limit of values of the scrollable range.
      /// @param value A numeric value. The default value is 0.
      virtual auto minimum(xtd::int32 value) -> scroll_bar&;
      
      /// @brief Gets the value to be added to or subtracted from the xtd::forms::scroll_bar::value property when the scroll box is moved a small distance.
      /// @return A numeric value. The default value is 1.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than 0.
      /// @remarks When the user presses one of the arrow keys or clicks one of the scroll bar buttons, the xtd::forms::scroll_bar::value property changes according to the value set in the xtd::forms::scroll_bar::small_change property.
      /// @remarks User interface guidelines suggest that the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties are set relative to the size of the view that the user sees, not to the total size including the unseen part. For example, if you have a picture box with scroll bars displaying a large image, the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties should be set relative to the size of the picture box, not to the size of the image.
      [[nodiscard]] virtual auto small_change() const noexcept -> xtd::int32;
      /// @brief Sets the value to be added to or subtracted from the xtd::forms::scroll_bar::value property when the scroll box is moved a small distance.
      /// @param value A numeric value. The default value is 1.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than 0.
      /// @remarks When the user presses one of the arrow keys or clicks one of the scroll bar buttons, the xtd::forms::scroll_bar::value property changes according to the value set in the xtd::forms::scroll_bar::small_change property.
      /// @remarks User interface guidelines suggest that the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties are set relative to the size of the view that the user sees, not to the total size including the unseen part. For example, if you have a picture box with scroll bars displaying a large image, the xtd::forms::scroll_bar::small_change and xtd::forms::scroll_bar::large_change properties should be set relative to the size of the picture box, not to the size of the image.
      virtual auto small_change(xtd::int32 value) -> scroll_bar&;
      
      /// @brief Gets or sets a numeric value that represents the current position of the scroll box on the scroll bar control.
      /// @return A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than the xtd::forms::scroll_bar::minimum property value.<br>-or-<br>The assigned value is greater than the xtd::forms::scroll_bar::maximum property value.
      [[nodiscard]] virtual auto value() const noexcept -> xtd::int32;
      /// @brief Sets or sets a numeric value that represents the current position of the scroll box on the scroll bar control.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @exception xtd::argument_out_of_range_exception The assigned value is less than the xtd::forms::scroll_bar::minimum property value.<br>-or-<br>The assigned value is greater than the xtd::forms::scroll_bar::maximum property value.
      virtual auto value(xtd::int32 value) -> scroll_bar&;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the scroll box has been moved by either a mouse or keyboard action.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<scroll_bar, xtd::event_handler> scroll;
      
      /// @brief Occurs when the xtd::forms::scroll_bar::value property is changed, either by a xtd::forms::scroll_bar::scroll event or programmatically.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<scroll_bar, xtd::event_handler> value_changed;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of scroll_bar class.
      /// @param vertical `true` if scroll_bar vertical; otherwise `false`.
      explicit scroll_bar(bool vertical);
      /// @}
      
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      auto on_handle_created(const event_args& e) -> void override;
      
      /// @brief Raises the xtd::forms::scroll_bar::scroll event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The xtd::forms::scroll_bar::on_scroll method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::scroll_bar::on_scroll in a derived class, be sure to call the base class' xtd::forms::scroll_bar::on_scroll method so that registered delegates receive the event.
      virtual auto on_scroll(const event_args& e) -> void;
      
      /// @brief Raises the scroll_bar::value_changed event.
      /// @param e The event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The xtd::forms::scroll_bar::on_value_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// When overriding xtd::forms::scroll_bar::on_value_changed in a derived class, be sure to call the base class' xtd::forms::scroll_bar::on_value_changed method so that registered delegates receive the event.
      virtual auto on_value_changed(const event_args& e) -> void;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      auto wnd_proc(message& message) -> void override;
      /// @}
      
    private:
      auto wm_scroll_control(message& message) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
