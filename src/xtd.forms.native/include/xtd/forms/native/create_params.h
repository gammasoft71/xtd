/// @file
/// @brief Contains xtd::forms::create_params class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <iostream>
#include <string>
#include <xtd/drawing/point.h>
#include <xtd/drawing/size.h>
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    namespace native {
      /// @brief Encapsulates the information needed when creating a control.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native
      /// @remarks The information in a create_params can be used to pass information about the initial state and appearance of a control. Most control derived controls override the create_params property to pass in the appropriate values or include additional information in the create_params.
      /// @note The constants used to set the style, ex_style, and class_style properties are defined in the xtd.forms.native library as constants.
      /// @warning Internal use only
      struct create_params {
        /// @name Public Properties
        
        /// @{
        /// @brief Gets or sets the control's initial text.
        /// @return The control's initial text.
        /// @warning Internal use only
        xtd::ustring caption;
        
        /// @brief Gets or sets the name of the Windows class to derive the control from.
        /// @return The name of the Windows class to derive the control from.
        /// @remarks The default value for this property is empty (""), indicating that the control is not derived from an existing control class. To derive from an existing control class, store the system class name in this property. For example, to derive from the standard Button control, set this property to "button".
        /// @warning Internal use only
        xtd::ustring class_name;
        
        /// @brief Gets or sets a bitwise combination of class style values.
        /// @return A bitwise combination of the class style values.
        /// @remarks see class_styles.h file
        /// @warning Internal use only
        size_t class_style = 0;
        
        /// @brief Gets or sets a bitwise combination of extended window style values.
        /// @return A bitwise combination of the extended window style values.
        /// @remarks The ex_style property supports extended appearance and initial state values to apply to the control.
        /// @remarks see window_styles.h file
        /// @warning Internal use only
        size_t ex_style = 0;
        
        /// @brief Gets or sets the initial location of the control.
        /// @return The xtd::drawing::point that represents the initial location of the control.
        /// @warning Internal use only
        drawing::point location;
        
        /// @brief Gets or sets additional parameter information needed to create the control.
        /// @return An intptr that holds additional parameter information needed to create the control.
        /// @warning Internal use only
        intptr param = 0;
        
        /// @brief Gets or sets the control's parent.
        /// @return An intptr that contains the window handle of the control's parent.
        /// @warning Internal use only
        intptr parent = 0;
        
        /// @brief Gets or sets a bitwise combination of window style values.
        /// @return A bitwise combination of the window style values.
        /// @remarks The Style property controls the appearance of the control and its initial state.
        /// @warning Internal use only
        size_t style = 0;
        
        /// @brief Gets or sets the initial size of the control.
        /// @return The xtd::drawing::size that represents the initial size of the control.
        /// @warning Internal use only
        drawing::size size;
        /// @}
      };
    }
  }
}
