/// @file
/// @brief Contains xtd::forms::native::track_bar API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.#pragma once
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains track bar native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ track_bar final static_ {
      public:
        /// @brief Sets a value to be added to or subtracted from the value property when the scroll box is moved a large distance.
        /// @param control track bar window handle.
        /// @param large_change A numeric value. The default is 5.
        /// @warning Internal use only
        static void large_change(intptr_t control, int32_t large_change);
        /// @brief sets the upper limit of the range this track_bar is working with.
        /// @param control track bar window handle.
        /// @param maximum The maximum value for the track_bar. The default is 10.
        /// @warning Internal use only
        static void maximum(intptr_t control, int32_t maximum);
        /// @brief Sets the lower limit of the range this track_bar is working with.
        /// @param control track bar window handle.
        /// @param minimum The minimum value for the track_bar. The default is 0.
        /// @warning Internal use only
        static void minimum(intptr_t control, int32_t minimum);
        /// @brief Sets the value added to or subtracted from the Value property when the scroll box is moved a small distance.
        /// @param control track bar window handle.
        /// @param small_change A numeric value. The default value is 1.
        /// @warning Internal use only
        static void small_change(intptr_t control, int32_t small_change);
        /// @brief Sets a value that specifies the delta between ticks drawn on the control.
        /// @param control track bar window handle.
        /// @param tick_frequency The numeric value representing the delta between ticks. The default is 1.
        /// @warning Internal use only
        static void tick_frequency(intptr_t control, int32_t tick_frequency);
        /// @brief Gets a numeric value that represents the current position of the scroll box on the track bar.
        /// @param control track bar window handle.
        /// @return A numeric value that is within the minimum and maximum range. The default value is 0.
        /// @warning Internal use only
        static int32_t value(intptr_t control);
        /// @brief Sets a numeric value that represents the current position of the scroll box on the track bar.
        /// @param control track bar window handle.
        /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
        /// @warning Internal use only
        static void value(intptr_t control, int32_t value);
      };
    }
  }
}
