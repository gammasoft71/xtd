/// @file
/// @brief Contains xtd::forms::native::form API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.hpp"
#include <xtd/static>
#include <xtd/drawing/icon>
#include <xtd/forms_native_export.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class form;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains form native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ form final static_ {
        friend xtd::forms::form;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Activates the form and gives it focus.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void activate(intptr control);
        /// @brief Closes the form.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void close(intptr control);
        /// @brief Force end dialog with specified result
        /// @param control Control window handle.
        /// @param result A dialog box id.
        /// @warning Internal use only
        static void end_dialog(intptr control, int32 result);
        /// @brief Gets a value indicates whether full screen window.
        /// @param control Control window handle.
        /// @return true if form is full screen; otherwise false.
        /// @warning Internal use only
        static bool full_screen(intptr control);
        /// @brief Sets a value indicates whether full screen window.
        /// @param control Control window handle.
        /// @param full_screen true if form is full screen; otherwise false.
        /// @warning Internal use only
        static void full_screen(intptr control, bool full_screen);
        /// @brief Sets the icon for the form.
        /// @param control Control window handle.
        /// @param icon An icon that represents the icon for the form.
        /// @warning Internal use only
        static void icon(intptr control, const xtd::drawing::icon& icon);
        /// @brief Gets a value indicate whether maximized windows.
        /// @param control Control window handle.
        /// @return true if form is full screen; otherwise false.
        /// @warning Internal use only
        static bool maximize(intptr control);
        /// @brief Sets a value indicate whether maximized windows.
        /// @param control Control window handle.
        /// @param maximize true if form is maximized; otherwise false.
        /// @warning Internal use only
        static void maximize(intptr control, bool maximize);
        /// @brief Gets a value indicate whether minimized windows.
        /// @param control Control window handle.
        /// @return true if form is full screen; otherwise false.
        /// @warning Internal use only
        static bool minimize(intptr control);
        /// @brief Sets a value indicate whether minimized windows.
        /// @param control Control window handle.
        /// @param minimize true if form is full screen; otherwise false.
        /// @warning Internal use only
        static void minimize(intptr control, bool minimize);
        /// @brief Sets the main_menu that is displayed in the form.
        /// @param control Control window handle.
        /// @param menu A menu handle that represents the menu to display in the form.
        /// @warning Internal use only
        static void menu(intptr control, intptr menu);
        /// @brief Sets form opacity.
        /// @param control Control window handle.
        /// @param opacity A double-precision value between 0.0 and 1.0 that represent the form opacity.
        /// @warning Internal use only
        static void opacity(intptr control, double opacity);
        /// @brief Restore form in normal state (not minimized, not maximized and not full screen).
        /// @param control Control window handle.
        /// @warning Internal use only
        static void restore(intptr control);
        
        /// @brief Sets the shape of the window to that depicted by region.
        /// @param control Control window handle.
        /// @param region The region to set shape;
        /// @warning Internal use only
        static void set_region(intptr control, intptr region);
        
        /// @brief Show dialog.
        /// @param control Control window handle.
        /// @warning Internal use only
        static int32 show_dialog(intptr control);
        /// @brief Show async dialog as sheet.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void show_sheet(intptr control);
        /// @brief Show dialog as sheet.
        /// @param control Control window handle.
        /// @warning Internal use only
        static int32 show_sheet_dialog(intptr control);
        /// @brief Sets virtual size
        /// @param control Control window handle.
        /// @param size A virtual xtd::drawing::size.
        /// @warning Internal use only
        static void virtual_size(intptr control, const drawing::size& size);
        /// @}
      };
    }
  }
}
