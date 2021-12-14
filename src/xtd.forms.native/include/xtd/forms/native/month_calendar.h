/// @file
/// @brief Contains xtd::forms::native::month_calendar API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>
#include <chrono>  // std::chrono
#include <utility> // std::pair

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
      class forms_native_export_ month_calendar final static_{
        friend xtd::forms::month_calendar;
      protected:
        /// @name Protected methods
        /// @{
        /// @brief Sets date to the calendar.
        /// @param control: month_calendar handle.
        /// @param date: date to set to the calendar.
        /// @warning Internal use only
        static void value(const intptr_t control, const std::chrono::system_clock::time_point date);
        /// @brief Gets selected date from the calendar.
        /// @param control: month_calendar handle.
        /// @return selected date.
        /// @warning Internal use only
        static std::chrono::system_clock::time_point value(const intptr_t control);
        /// @brief Sets date range to the control.
        /// @param control: month_calendar handle.
        /// @param from_date: lower date of the calendar.
        /// @param to_date: upper date of the calendar.
        /// @warning Internal use only
        static void set_date_range(const intptr_t control, const std::chrono::system_clock::time_point from_date, const std::chrono::system_clock::time_point to_date);
        /// @name Protected methods
        /// @brief Gets date range from the control.
        /// @param control: month_calendar handle.
        /// @param from_date: output lower date from the calendar.
        /// @param to_date: output upper date from the calendar.
        /// @warning Internal use only
        static void get_date_range(const intptr_t control, std::chrono::system_clock::time_point& from_date, std::chrono::system_clock::time_point& to_date);
        /// @}
      };
    }
  }
}
