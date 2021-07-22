/// @file
/// @brief Contains xtd::forms::native::scroll_bar API.
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

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class scroll_bar;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains scroll_bar native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @remarks No member for the moment.
      /// @warning Internal use only
      class scroll_bar final static_ {
        // class forms_native_export_ hscroll_bar final static_ {
        friend xtd::forms::scroll_bar;
      protected:
        /// @brief Sets a value to be added to or subtracted from the value property when the scroll box is moved a large distance.
        /// @param control scroll bar window handle.
        /// @param large_change A numeric value. The default is 5.
        /// @warning Internal use only
        static void large_change(intptr_t control, int32_t large_change);
        /// @brief sets the upper limit of the range this scroll_bar is working with.
        /// @param control scroll bar window handle.
        /// @param maximum The maximum value for the scroll_bar. The default is 10.
        /// @warning Internal use only
        static void maximum(intptr_t control, int32_t maximum);
        /// @brief Sets the lower limit of the range this scroll_bar is working with.
        /// @param control scroll bar window handle.
        /// @param minimum The minimum value for the scroll_bar. The default is 0.
        /// @warning Internal use only
        static void minimum(intptr_t control, int32_t minimum);
        /// @brief Sets the value added to or subtracted from the Value property when the scroll box is moved a small distance.
        /// @param control scroll bar window handle.
        /// @param small_change A numeric value. The default value is 1.
        /// @warning Internal use only
        static void small_change(intptr_t control, int32_t small_change);
        /// @brief Gets a numeric value that represents the current position of the scroll box on the scroll bar.
        /// @param control scroll bar window handle.
        /// @return A numeric value that is within the minimum and maximum range. The default value is 0.
        /// @warning Internal use only
        static int32_t value(intptr_t control);
        /// @brief Sets a numeric value that represents the current position of the scroll box on the scroll bar.
        /// @param control scroll bar window handle.
        /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
        /// @warning Internal use only
        static void value(intptr_t control, int32_t value);
      };
    }
  }
}
