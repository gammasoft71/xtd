/// @file
/// @brief Contains xtd::forms::native::tool_bar API.
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
    class tool_bar;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains tool bar native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ tool_bar final static_ {
        friend xtd::forms::tool_bar;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Adds tool bar push button.
        /// @param tool_bar The tool bar that contains the button.
        /// @param text The button text
        /// @param tool_tip_text The tool tip text.
        /// @param image The button image.
        /// @param enabled true if button is enabled; otherwise false.
        /// @param visible true if button is visible; otherwise false.
        /// @warning Internal use only
        static intptr add_tool_bar_button(intptr tool_bar, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool enabled, bool visible);
        /// @brief Adds tool bar drop down button.
        /// @param tool_bar The tool bar that contains the button.
        /// @param text The button text
        /// @param tool_tip_text The tool tip text.
        /// @param image The button image.
        /// @param enabled true if button is enabled; otherwise false.
        /// @param visible true if button is visible; otherwise false.
        /// @param drop_down_menu The context menu handle.
        /// @warning Internal use only
        static intptr add_tool_bar_drop_down_button(intptr tool_bar, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool enabled, bool visible, intptr drop_down_menu);
        /// @brief Adds tool bar toggle button.
        /// @param tool_bar The tool bar that contains the button.
        /// @param text The button text
        /// @param tool_tip_text The tool tip text.
        /// @param image The button image.
        /// @param pushed true if button is pushed; otherwise false.
        /// @param enabled true if button is enabled; otherwise false.
        /// @param visible true if button is visible; otherwise false.
        /// @warning Internal use only
        static intptr add_tool_bar_toggle_button(intptr tool_bar, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool pushed, bool enabled, bool visible);
        /// @brief Adds tool bar separator.
        /// @param tool_bar The tool bar that contains the separator.
        /// @warning Internal use only
        static intptr add_tool_bar_separator(intptr tool_bar);
        /// @brief Adds tool bar stretchable separator.
        /// @param tool_bar The tool bar that contains the stretchable separator.
        /// @warning Internal use only
        static intptr add_tool_bar_stretchable_separator(intptr tool_bar);
        /// @brief Adds tool bar control.
        /// @param tool_bar The tool bar that contains the control.
        /// @param control The control handle.
        /// @param text The control text
        /// @param tool_tip_text The tool tip text.
        /// @warning Internal use only
        static intptr add_tool_bar_control(intptr tool_bar, intptr control, const xtd::ustring& text, const xtd::ustring& tool_tip_text);
        /// @brief Sets the tool_bar that is displayed in the form.
        /// @param control Control window handle.
        /// @param tool_bar A tool bar handle that represents the tool bar to display in the form.
        /// @warning Internal use only
        static bool set_system_tool_bar(intptr control, intptr tool_bar);
        /// @brief Updates tool bar item.
        /// @param tool_bar The tool bar that contains the button.
        /// @param handle The tool bar item handle.
        /// @param text The button text
        /// @param tool_tip_text The tool tip text.
        /// @param image The button image.
        /// @param pushed true if button is pushed; otherwise false.
        /// @param enabled true if button is enabled; otherwise false.
        /// @param visible true if button is visible; otherwise false.
        /// @warning Internal use only
        static void update_tool_bar_item(intptr tool_bar, intptr handle, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool pushed, bool enabled, bool visible);
        /// @brief Gets the tool bar item rectangle
        /// @param tool_bar The tool bar that contains the button.
        /// @param handle The tool bar item handle.
        /// @return A xtd::drawing::rectangle that contains the tool bar item rectangle.
        /// @warning Internal use only
        static xtd::drawing::rectangle tool_bar_item_rectangle(intptr tool_bar, intptr handle);
        /// @}
      };
    }
  }
}
