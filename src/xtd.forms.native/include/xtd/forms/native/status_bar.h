/// @file
/// @brief Contains xtd::forms::native::status_bar API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/image.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class status_bar;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains status bar native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ status_bar final static_ {
        friend xtd::forms::status_bar;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Adds status bar panel.
        /// @param status_bar The status bar that contains the panel.
        /// @param text The panel text.
        /// @param tool_tip_text The tool tip text.
        /// @param image The panel image.
        /// @param visible true if panel is visible; otherwise false.
        /// @param width The panel width.
        /// @param stretchable true if panel is stretchable; otherwise false.
        /// @warning Internal use only
        //static intptr add_status_bar_panel(intptr status_bar, int border_style, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool visible, int width, bool stretchable);
        static intptr add_status_bar_panel(intptr status_bar, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, int32 alignment, int32 auto_size, int32 border_style, int32 min_width, int32 width);
        /// @brief Adds status bar control.
        /// @param status_bar The tool bar that contains the control.
        /// @param control The control handle.
        /// @param text The control text.
        /// @warning Internal use only
        static intptr add_status_bar_control(intptr status_bar, intptr control, const xtd::ustring& text);
        /// @brief Sets the status_bar that is displayed in the form.
        /// @param control Control window handle.
        /// @param status_bar A tool bar handle that represents the status bar to display in the form.
        /// @warning Internal use only
        static bool set_system_status_bar(intptr control, intptr status_bar);
        /// @brief Gets a value indicating whether OS displays a sizing grip.
        /// @return true if OS displays a sizing grip; otherwise, false.
        /// @warning Internal use only
        static bool sizing_grip();
        /// @brief Gets the cursor name used by sizing grip.
        /// @return The cursor name used by sizing grip.
        /// @warning Internal use only
        static xtd::ustring sizing_grip_cursor_name();
        /// @brief Updates status bar item.
        /// @param tool_bar The status bar that contains the item.
        /// @param handle The status bar item handle.
        /// @param text The panel text.
        /// @param tool_tip_text The tool tip text.
        /// @param image The panel image.
        /// @param visible true if panel is visible; otherwise false.
        /// @param width The panel width.
        /// @param visible true if panel is stretchable; otherwise false.
        /// @warning Internal use only
        static void update_status_bar_item(intptr status_bar, intptr handle, int32 border_style, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool visible, int32 width, bool stretchable);
        /// @}
      };
    }
  }
}
