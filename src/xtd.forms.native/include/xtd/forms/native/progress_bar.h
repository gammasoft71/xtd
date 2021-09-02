/// @file
/// @brief Contains xtd::forms::native::progress_bar API.
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
    class progress_bar;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains progress bar native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ progress_bar final static_ {
        friend xtd::forms::progress_bar;
      protected:
        /// @brief Sets value indicates progress by continuously scrolling a block across a progress_bar in a marquee fashion.
        /// @param control Control window handle.
        /// @param marquee true if progress_bar is marquee; otherwise false.
        /// @param animation_speed The time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
        /// @warning Internal use only
        static void marquee(intptr_t control, bool marquee, size_t animation_speed);
        /// @brief Sets the maximum value of the range of the control.
        /// @param control Control window handle.
        /// @param maximum The maximum value of the range.
        /// @warning Internal use only
        static void maximum(intptr_t control, int32_t maximum);
        /// @brief Sets the minimum value of the range of the control.
        /// @param control Control window handle.
        /// @param minimum The minimum value of the range.
        /// @warning Internal use only
        static void minimum(intptr_t control, int32_t minimum);
        /// @brief Sets the current position of the progress bar.
        /// @param control Control window handle.
        /// @param value The position within the range of the progress bar.
        /// @warning Internal use only
        static void value(intptr_t control, int32_t value);
      };
    }
  }
}
