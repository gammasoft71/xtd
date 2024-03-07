/// @file
/// @brief Contains xtd::forms::native::month_calendar API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.h"
#include <xtd/static.h>
#include <xtd/date_time.h>
#include <xtd/forms_native_export.h>
#include <xtd/drawing/color.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class month_calendar;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains month calendar native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ month_calendar final static_ {
        friend xtd::forms::month_calendar;
      protected:
        /// @name Protected static methods
        /// @{
        /// @brief Sets the array of xtd::date_time objects that determines which annual days are displayed in bold.
        /// @param control month calendar handle.
        /// @param dates An array of xtd::date_time objects.
        /// @remarks Using this property, you can assign an array of annual bold dates. When you assign an array of dates, the existing dates are first cleared.
        /// @warning Internal use only
        static void annually_bolded_dates(intptr control, const std::vector<xtd::date_time>& dates);
        
        /// @brief Sets the array of xtd::date_time bjects that determines which nonrecurring dates are displayed in bold.
        /// @param control month calendar handle.
        /// @param dates An array of xtd::date_time objects.
        /// @remarks Using this property, you can assign an array of bold dates. When you assign an array of dates, the existing dates are first cleared.
        /// @warning Internal use only
        static void bolded_dates(intptr control, const std::vector<xtd::date_time>& dates);
        
        /// @brief Sets the number of columns and rows of months displayed.
        /// @param control month calendar handle.
        /// @param calendar_dimensions A xtd::drawing::size with the number of columns and rows to use to display the calendar.
        /// @warning Internal use only
        static void calendar_dimensions(intptr control, const xtd::drawing::size& calendar_dimensions);
        
        /// @brief Sets allowable date range to the calendar.
        /// @param control month calendar handle.
        /// @param min_date The minimum date allowable to the calendar.
        /// @param max_date The maximum date allowable to the calendar.
        /// @warning Internal use only
        static void allowable_dates(intptr control, date_time min_date, date_time max_date);
        
        /// @brief Sets the first day of the week as displayed in the month calendar.
        /// @param day One of following day values :
        /// | value | day         |
        /// | ----- | ----------- |
        /// | 0     | monday      |
        /// | 1     | tuesday     |
        /// | 2     | wednesday   |
        /// | 3     | thursday    |
        /// | 4     | friday      |
        /// | 5     | saturday    |
        /// | 6     | sunday      |
        /// | 7     | default_day |
        /// @warning Internal use only
        static void first_day_of_week(intptr control, uint32 day);
        
        /// @brief Returns informations on which portion of a month calendar control is at a location specified by a xtd::drawing::point.
        /// @param point A xtd::drawing::point containing the xtd::drawing::point::x and xtd::drawing::point::y coordinates of the point to be hit tested.
        /// @return A std:tuple<uint32, xtd::date_time> that contains information about the specified point on the month calendar.
        /// @remarks The value uint32 represents the strike zone, see the following table for the correspondence:
        /// | Value | hit area            |
        /// | ----- | ------------------- |
        /// | 0     | nowhere             |
        /// | 1     | title_background    |
        /// | 2     | title_month         |
        /// | 3     | title_year          |
        /// | 4     | next_month_button   |
        /// | 5     | prev_month_button   |
        /// | 6     | calendar_background |
        /// | 7     | date                |
        /// | 8     | next_month_date     |
        /// | 9     | prev_month_date     |
        /// | 10    | day_of_week         |
        /// | 11    | week_numbers        |
        /// | 12    | today_link          |
        static std::tuple<uint32, xtd::date_time> hit_test(intptr control, const xtd::drawing::point& point);
        
        /// @brief Sets the maximum number of days that can be selected in a month calendar control.
        /// @param control month calendar handle.
        /// @param value The maximum number of days that you can select. The default is 7.
        static void max_selection_count(intptr control, uint32 value);
        
        /// @brief Sets the array of xtd::date_time objects that determine which monthly days to bold.
        /// @param control month calendar handle.
        /// @param dates An array of xtd::date_time objects.
        /// @remarks Using this property, you can assign an array of annual bold dates. When you assign an array of dates, the existing dates are first cleared.
        /// @warning Internal use only
        static void monthly_bolded_dates(intptr control, const std::vector<xtd::date_time>& dates);
        
        /// @brief Sets selection range to the calendar.
        /// @param control month_calendar handle.
        /// @param date_start The range date start.
        /// @warning Internal use only
        static void selection_range(intptr control, date_time date_start, date_time date_end);
        
        /// @brief Gets selection range from the calendar.
        /// @param control month_calendar handle.
        /// @return selection range.
        /// @warning Internal use only
        static std::pair<date_time, date_time> selection_range(intptr control);
        
        /// @brief Gets the minimum size to display one month of the calendar.
        /// @param control month_calendar handle.
        /// @return The size, in pixels, necessary to fully display one month in the calendar.
        /// @warning Internal use only
        static xtd::drawing::size single_month_size(intptr control);
        
        /// @brief Sets a value indicating the background color of the title area of the calendar.
        /// @param control month_calendar handle.
        /// @param color A xtd::drawing::color.
        /// @warning Internal use only
        static void title_back_color(intptr control, const xtd::drawing::color& color);
        
        /// @brief Sets a value indicating the foreground color of the title area of the calendar.
        /// @param control month_calendar handle.
        /// @param color A xtd::drawing::color.
        /// @warning Internal use only
        static void title_fore_color(intptr control, const xtd::drawing::color& color);
        
        /// @brief Sets the value that is used by month_calendar as today's date.
        /// @param control month_calendar handle.
        /// @param value A xtd::date_time representing today's date.
        /// @warning Internal use only
        static void today_date(intptr control, const xtd::date_time& value);
        
        /// @brief Sets a value indicating the color of days in months that are not fully displayed in the control.
        /// @param control month_calendar handle.
        /// @param color A xtd::drawing::color.
        /// @warning Internal use only
        static void trailing_fore_color(intptr control, const xtd::drawing::color& color);
        /// @}
      };
    }
  }
}
