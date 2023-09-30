/// @file
/// @brief Contains xtd::forms::selection_range control.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include <xtd/date_time>
#include <xtd/object>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a date selection range in a month calendar control.
    /// @par Header
    /// @code #include <xtd/forms/selection_range> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @par Examples
    /// The following example sets the xtd::forms::month_calendar::selection_range property of a xtd::forms::month_calendar control based on two dates entered into two xtd::forms::text_box controls when a xtd::forms::button is clicked.
    /// This code assumes new instances of a xtd::forms::month_calendar control, two xtd::forms::text_box controls, and a xtd::forms::button have been created on a xtd::forms::form.
    /// You might consider adding code to validate the xtd::forms::control::text assigned to the text boxes to verify that they contain valid dates.
    /// @code
    /// void button1_click(const object& sender, const event_args& e) {
    ///   // Set the selection_range with start and end dates from text boxes.
    ///   try {
    ///     month_calendar1.selection_range(selection_range(date_time::parse(text_box1.text(), date_time::parse(text_box2.text()));
    ///   } catch(const system_exception& ex) {
    ///     message_box::show(ex.message());
    ///   }
    /// }
    /// @endcode
    /// @remarks The xtd::forms::selection_range is the date or dates selected and highlighted on the xtd::forms::month_calendar control. If only one date is selected, the xtd::forms::selection_range::start and xtd::forms::selection_range::end property values will be equal. The xtd::forms::selection_range can be changed by the user clicking a date while dragging the mouse pointer across the desired dates, or you can set the range in code. For example, you might want to have the user enter a date range into two xtd::forms::text_box controls or two xtd::forms::date_time_picker controls and set the xtd::forms::selection_range based on those dates.
    class forms_export_ selection_range : public object {
    public:
      /// @Name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::selection_range class.
      /// @remarks The xtd::forms::selection_range::start and xtd::forms::selection_range::end values are set to xtd::date_time::min_value when this constructor is used.
      selection_range() = default;
      /// @brief Initializes a new instance of the xtd::forms::selection_range class with the specified beginning and ending dates.
      /// @param start The starting date in the xtd::forms::selection_range.
      /// @param end The ending date in the xtd::forms::selection_range.
      /// @remarks If the lower xtd::dateTime value is greater than the upper xtd::date_time value, the lower value will be assigned to the xtd::forms::selection_range::end property instead of the xtd::forms::selection_range::start property.
      selection_range(date_time start, date_time end);
      /// @}
      
      /// @cond
      selection_range(const selection_range&) = default;
      selection_range(selection_range&&) = default;
      selection_range& operator =(const selection_range&) = default;
      /// @endcond
      
      
      /// @Name Properties
      
      /// @{
      /// @brief Gets the ending date and time of the selection range.
      /// @return The ending xtd::date_time value of the range.
      virtual date_time end() const noexcept;
      /// @brief Sets the ending date and time of the selection range.
      /// @param value The ending xtd::date_time value of the range.
      /// @return This current instance.
      virtual selection_range& end(date_time value);
      
      /// @brief Gets the starting date and time of the selection range.
      /// @return The starting xtd::date_time value of the range.
      virtual date_time start() const noexcept;
      /// @brief Sets the starting date and time of the selection range.
      /// @param value The starting xtd::date_time value of the range.
      /// @return This current instance.
      virtual selection_range& start(date_time value);
      /// @}
      
      /// @Name Methods
      /// @{
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      date_time start_;
      date_time end_;
    };
  }
}
