/// @file
/// @brief Contains xtd::forms::native::progress_dialog API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <string>
#include <vector>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/icon.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class progress_dialog;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains progress dialog native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ progress_dialog final static_ {
        friend xtd::forms::progress_dialog;
      protected:
        /// @brief Gets whether user has clicked on cancel butttoon.
        /// @param dialog Progress dialog window handle.
        /// @return true if user has clicked on cancel button; otherwise false.
        /// @warning Internal use only
       static bool cancelled(intptr_t dialog);
        /// @brief Creates progress dialog.
        /// @param hwnd Parent window handle.
        /// @param text A string that specifies the title bar caption to display.
        /// @param message A string that specifies the text to display.
        /// @param informations The information texts.
        /// @param marquee_animation_speed The time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
        /// @param minimum The minimum value of the range.
        /// @param maximum The maximum value of the range.
        /// @param value The position within the range of the progress bar. The default is 0.
        /// @param options A bittwise progress dialog flags value.
       /// @return The created progress dialog window handle.
        /// @warning Internal use only
        static intptr_t create(intptr_t hwnd, const xtd::ustring& text, const xtd::ustring& message, const std::vector<xtd::ustring>& informations, size_t marquee_animation_speed, int32_t minimum, int32_t maximum, int32_t value, size_t options);
        /// @brief Destroys progress dialog.
        /// @param dialog Progress dialog window handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr_t dialog);
        /// @brief Sets the information texts.
        /// @param dialog Progress dialog window handle.
        /// @param informations The information texts.
        /// @warning Internal use only
        static void informations(intptr_t dialog, const std::vector<xtd::ustring>& informations);
        /// @brief Gets a value that Indicates progress by continuously scrolling a block across a progress_bar in a marquee fashion.
        /// @param dialog Progress dialog window handle.
        /// @param marquee truee is marquee; otherwise false. The default is false.
        /// @warning Internal use only
        static void marquee(intptr_t dialog, bool marquee, size_t animation_speed);
        /// @brief Sets the maximum value of the range of the control.
        /// @param dialog Progress dialog window handle.
        /// @param maximum The maximum value of the range.
        /// @warning Internal use only
        static void maximum(intptr_t dialog, int32_t maximum);
        /// @brief Sets the message text.
        /// @param dialog Progress dialog window handle.
        /// @param description The message text.
        /// @warning Internal use only
        static void message(intptr_t dialog, const xtd::ustring& message);
        /// @brief Sets the minimum value of the range of the control.
        /// @param dialog Progress dialog window handle.
        /// @param minimum The minimum value of the range.
        /// @warning Internal use only
        static void minimum(intptr_t dialog, int32_t minimum);
        /// @brief Resume progress dialog box after Abort button clicked.
        /// @param dialog Progress dialog window handle.
        /// @warning Internal use only
        static void resume(intptr_t dialog);
        /// @brief Runs progress dialog box.
        /// @param dialog Progress dialog window handle.
        /// @warning Internal use only
        static void show(intptr_t dialog);
        /// @brief Runs progress dialog box as sheet.
        /// @param dialog Progress dialog window handle.
        /// @warning Internal use only
        static void show_sheet(intptr_t dialog);
        /// @brief Gets whether user has clicked on skip butttoon.
        /// @param dialog Progress dialog window handle.
        /// @return true if user has clicked on skip button; otherwise false.
        /// @warning Internal use only
        static bool skipped(intptr_t dialog);
        /// @brief Sets the current position of the progress bar.
        /// @param dialog Progress dialog window handle.
        /// @param value The position within the range of the progress bar. The default is 0.
        /// @warning Internal use only
        static void value(intptr_t dialog, int32_t value);
      };
    }
  }
}
