/// @file
/// @brief Contains xtd::forms::native::date_time_picker API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
#include <xtd/static.h>
#include <ctime>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains date time picker native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ date_time_picker final static_ {
      public:
        /// @brief Gets the date/time value assigned to the control.
        /// @param control Date time picker handle.
        /// @return The date and time value assign to the control.
        /// @warning Internal use only
        static std::chrono::system_clock::time_point value(intptr_t control);
        /// @brief Sets the date/time value assigned to the control.
        /// @param control Date time picker handle.
        /// @param date_time The date and time value assign to the control.
        /// @warning Internal use only
        static void value(intptr_t control, std::chrono::system_clock::time_point date_time);
      };
    }
  }
}
