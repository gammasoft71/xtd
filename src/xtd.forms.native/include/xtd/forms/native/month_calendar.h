/// @file
/// @brief Contains xtd::forms::native::month_calendar API.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/date_time.h>
#include <xtd/forms_native_export.h>

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
        /// @name Protected methods
        /// @{
        /// @brief Sets the array of xtd::date_time objects that determines which annual days are displayed in bold.
        /// @param control: month calendar handle.
        /// @param value An array of xtd::date_time objects.
        /// @remarks Using this property, you can assign an array of annual bold dates. When you assign an array of dates, the existing dates are first cleared.
        /// @warning Internal use only
        static void annually_bolded_dates(const intptr_t control, const std::vector<xtd::date_time>& dates);
        /// @brief Sets the array of xtd::date_time bjects that determines which nonrecurring dates are displayed in bold.
        /// @param control: month calendar handle.
        /// @param value An array of xtd::date_time objects.
        /// @remarks Using this property, you can assign an array of bold dates. When you assign an array of dates, the existing dates are first cleared.
        /// @warning Internal use only
        static void bolded_dates(const intptr_t control, const std::vector<xtd::date_time>& dates);
        /// @brief Sets allowable date range to the calendar.
        /// @param control: month calendar handle.
        /// @param min_date: The minimum date allowable to the calendar.
        /// @param max_date: The maximum date allowable to the calendar.
        /// @warning Internal use only
        static void allowable_dates(const intptr_t control, date_time min_date, date_time max_date);
        /// @brief Sets selection range to the calendar.
        /// @param control: month_calendar handle.
        /// @param date_start: The range date start.
        /// @param date_end: The range date end.
        /// @warning Internal use only
        static void selection_range(const intptr_t control, date_time date_start, date_time date_end);
        /// @brief Gets selection range from the calendar.
        /// @param control: month_calendar handle.
        /// @return selection range.
        /// @warning Internal use only
        static std::pair<date_time, date_time> selection_range(const intptr_t control);
        /// @}
      };
    }
  }
}
