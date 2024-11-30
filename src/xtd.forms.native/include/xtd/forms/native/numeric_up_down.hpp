/// @file
/// @brief Contains xtd::forms::native::numeric_up_down API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.hpp"
#include <xtd/static>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class numeric_up_down;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains numeric up down native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ numeric_up_down final static_ {
        friend xtd::forms::numeric_up_down;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Sets the number of decimal places to display in the spin box (also known as an up-down control).
        /// @param control Numeric up down window handle.
        /// @param decimal_place The number of decimal places to display in the spin box.
        /// @warning Internal use only
        static void decimal_place(intptr control, int32 decimal_place);
        /// @brief Sets the value to increment or decrement the spin box (also known as an up-down control) when the up or down buttons are clicked.
        /// @param control Numeric up down window handle.
        /// @param increment The value to increment or decrement the Value property when the up or down buttons are clicked on the spin box.
        /// @warning Internal use only
        static void increment(intptr control, double increment);
        /// @brief Sets the maximum value for the spin box (also known as an up-down control).
        /// @param control Numeric up down window handle.
        /// @param maximum The maximum value for the spin box.
        /// @warning Internal use only
        static void maximum(intptr control, double maximum);
        /// @brief Sets the minimum value for the spin box (also known as an up-down control).
        /// @param control Numeric up down window handle.
        /// @param minimum The maximum value for the spin box.
        /// @warning Internal use only
        static void minimum(intptr control, double minimum);
        /// @brief Gets the value assigned to the spin box (also known as an up-down control).
        /// @param control Numeric up down window handle.
        /// @return The numeric value of the numeric_up_down control.
        /// @warning Internal use only
        static double value(intptr control);
        /// @brief Sets the value assigned to the spin box (also known as an up-down control).
        /// @param control Numeric up down window handle.
        /// @param value The numeric value of the numeric_up_down control.
        /// @warning Internal use only
        static void value(intptr control, double value);
        /// @}
      };
    }
  }
}
