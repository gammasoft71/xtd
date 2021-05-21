/// @file
/// @brief Contains xtd::forms::native::up_down_button API.
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
    /// @cond
    class up_down_button;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains up down button native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ up_down_button final static_ {
        friend xtd::forms::up_down_button;
      protected:
        /// @brief Sets the maximum allowed value for the up_down_button control.
        /// @param control Up down button window handle.
        /// @param maximum The maximum allowed value for the up down button.
        /// @warning Internal use only
        static void maximum(intptr_t control, int32_t maximum);
        /// @brief Sets the minimum allowed value for the up_down_button control.
        /// @param control Up down button window handle.
        /// @param value The minimum allowed value for the up down button.
        /// @warning Internal use only
        static void minimum(intptr_t control, int32_t minimum);
        /// @brief Gets the value assigned to the up_down_button control.
        /// @param control Up down button window handle.
        /// @return The numeric value of the up down button control.
        /// @warning Internal use only
        static int32_t value(intptr_t control);
        /// @brief Sets the value assigned to the up_down_button control.
        /// @param control Up down button window handle.
        /// @param value The numeric value of the up down button control.
        /// @warning Internal use only
        static void value(intptr_t control, int32_t value);
      };
    }
  }
}
