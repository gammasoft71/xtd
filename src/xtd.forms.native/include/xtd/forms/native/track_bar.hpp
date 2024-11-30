/// @file
/// @brief Contains xtd::forms::native::track_bar API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.#pragma once
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.hpp"
#include <xtd/static>
#include <xtd/forms_native_export.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class track_bar;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains track bar native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ track_bar final static_ {
        friend xtd::forms::track_bar;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Sets a value to be added to or subtracted from the value property when the scroll box is moved a large distance.
        /// @param control track bar window handle.
        /// @param large_change A numeric value. The default is 5.
        /// @warning Internal use only
        static void large_change(intptr control, int32 large_change);
        /// @brief sets the upper limit of the range this track_bar is working with.
        /// @param control track bar window handle.
        /// @param maximum The maximum value for the track_bar. The default is 10.
        /// @warning Internal use only
        static void maximum(intptr control, int32 maximum);
        /// @brief Sets the lower limit of the range this track_bar is working with.
        /// @param control track bar window handle.
        /// @param minimum The minimum value for the track_bar. The default is 0.
        /// @warning Internal use only
        static void minimum(intptr control, int32 minimum);
        /// @brief Sets the value added to or subtracted from the Value property when the scroll box is moved a small distance.
        /// @param control track bar window handle.
        /// @param small_change A numeric value. The default value is 1.
        /// @warning Internal use only
        static void small_change(intptr control, int32 small_change);
        /// @brief Sets a value that specifies the delta between ticks drawn on the control.
        /// @param control track bar window handle.
        /// @param tick_frequency The numeric value representing the delta between ticks. The default is 1.
        /// @warning Internal use only
        static void tick_frequency(intptr control, int32 tick_frequency);
        /// @brief Gets a numeric value that represents the current position of the scroll box on the track bar.
        /// @param control track bar window handle.
        /// @return A numeric value that is within the minimum and maximum range. The default value is 0.
        /// @warning Internal use only
        static int32 value(intptr control);
        /// @brief Sets a numeric value that represents the current position of the scroll box on the track bar.
        /// @param control track bar window handle.
        /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
        /// @warning Internal use only
        static void value(intptr control, int32 value);
        /// @}
      };
    }
  }
}
