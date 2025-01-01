/// @file
/// @brief Contains xtd::forms::native::replace_dialog API.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/optional>
#include <xtd/static>
#include <xtd/delegate>
#include <xtd/string>
#include <xtd/drawing/point>
#include <xtd/forms_native_export.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class replace_dialog;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains replace dialog native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ replace_dialog final static_ {
        friend xtd::forms::replace_dialog;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Creates replace dialog.
        /// @param hwnd Window handle.
        /// @param location The xtd::drawing::point class that define the location of the replace dialog. If no value, the default system location is used.
        /// @param title A string that specifies the title bar caption to display.
        /// @param find_string A string that specifies the text to find.
        /// @param replace_string A string that specifies the replaced text.
        /// @param show_whole_word A boolean that specifies the visibility of whole word option.
        /// @param show_match_case A boolean that specifies the visibility of watch case option.
        /// @param whole_word A boolean that specifies the whole word option is checked.
        /// @param show_match_case A boolean that specifies the match case option is checked.
        /// @param find_next A delegate that will be invoked when find button is clicked.
        /// @param replace A delegate that will be invoked when replace and replace all buttons are clicked.
        /// @param dialog_closed A delegate that will be invoked when the dialog is closed.
        /// @param return The replace dialog handle.
        /// @warning Internal use only
        static intptr create(intptr hwnd, const std::optional<xtd::drawing::point>& location, const xtd::string& title, const xtd::string& find_string, const xtd::string& replace_string, bool show_whole_word, bool show_match_case, bool whole_word, bool match_case, xtd::delegate<void(const xtd::drawing::point&, const xtd::string&, const xtd::string&, bool, bool)> find_next, xtd::delegate<void(const xtd::drawing::point&, const xtd::string&, const xtd::string&, bool, bool, bool)> replace, xtd::delegate<void()> dialog_closed);
        /// @brief Hides replace dialog.
        /// @param dialog Find dialog handle.
        /// @warning Internal use only
        static void close(intptr dialog);
        /// @brief Destroy replace dialog.
        /// @param dialog Find dialog handle.
        /// @warning Internal use only
        static void destroy(intptr dialog);
        /// @brief Shows replace dialog.
        /// @param dialog Find dialog handle.
        /// @warning Internal use only
        static void show(intptr& dialog);
        /// @}
      };
    }
  }
}
