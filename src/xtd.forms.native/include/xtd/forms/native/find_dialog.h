/// @file
/// @brief Contains xtd::forms::native::find_dialog API.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <optional>
#include <xtd/static.h>
#include <xtd/delegate.h>
#include <xtd/ustring.h>
#include <xtd/drawing/point.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class find_dialog;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains find dialog native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ find_dialog final static_ {
        friend xtd::forms::find_dialog;
      protected:
        /// @name Protected Alias
        
        /// @{
        /// @brief Represents the callback delegate for find_next and dialog_closed events.
        using callback_t = xtd::delegate<void(const xtd::drawing::point&, const xtd::ustring&, bool, bool, bool)>;
        /// @}

        /// @name Protected methods
        
        /// @{
        /// @brief Creates and shows find dialog.
        /// @param hwnd Window handle.
        /// @param location The xtd::drawing::point class that define the location of the find dialog. If no value, the default system location is used.
        /// @param title A string that specifies the title bar caption to display.
        /// @param find_string A string that specifies the text to find.
        /// @param show_up_down A boolean that specifies the visibility of up down box option.
        /// @param show_whole_word A boolean that specifies the visibility of whole word option.
        /// @param show_match_case A boolean that specifies the visibility of watch case option.
        /// @param downwards A boolean that specifies the down option is checked. Otherwise is up.
        /// @param whole_word A boolean that specifies the whole word option is checked.
        /// @param show_match_case A boolean that specifies the match case option is checked.
        /// @param find_next A delegate that will be invoked when find button is clicked.
        /// @param return The find dialog handle.
        /// @param dialog_closed A delegate that will be invoked when the dialog is closed.
        /// @warning Internal use only
        static intptr_t show(intptr_t hwnd, const std::optional<xtd::drawing::point>& location, const xtd::ustring& title, const xtd::ustring& find_string, bool show_up_down, bool show_whole_word, bool show_match_case, bool downwards, bool whole_word, bool match_case, callback_t find_next, callback_t dialog_closed);
        /// @brief Destroy and hides find dialog.
        /// @param hwnd Find dialog handle.
        /// @warning Internal use only
        static void close(intptr_t dialog);
        /// @}
      };
    }
  }
}
