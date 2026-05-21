/// @file
/// @brief Contains xtd::forms::native::text_box API.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.#pragma once
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/drawing/color>
#include "create_params"
#include <xtd/static>
#include <xtd/string>
#include <xtd/forms_native_export.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class text_box;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains text box native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ text_box final static_ {
        friend xtd::forms::text_box;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Gets the number of characters selected in the text box.
        /// @param control Text box window handle.
        /// @return The number of characters selected in the text box.
        /// @warning Internal use only
        [[nodiscard]] static auto selection_length(xtd::intptr control) -> xtd::usize;
        /// @brief Gets o the starting point of text selected in the text box.
        /// @param control Text box window handle.
        /// @return The starting position of text selected in the text box.
        /// @warning Internal use only
        [[nodiscard]] static auto selection_start(xtd::intptr control) -> xtd::usize;
        /// @brief Appends text to the current text of a text box.
        /// @param control Text box window handle.
        /// @param value The text to append to the current contents of the text box.
        /// @warning Internal use only
        static auto append(xtd::intptr control, const xtd::string& text) -> void;
        /// @brief Selects a range of text in the text box.
        /// @param control Text box window handle.
        /// @param start The position of the first character in the current text selection within the text box.
        /// @param length The number of characters to select.
        /// @warning Internal use only
        static auto select(xtd::intptr control, xtd::usize start, xtd::usize length) -> void;
        /// @brief Gets text associate to the text box.
        /// @param control Text box window handle.
        /// @return The text string.
        /// @warning Internal use only
        [[nodiscard]] static auto text(xtd::intptr control) -> xtd::string;
        /// @brief Sets text associate to the text box.
        /// @param control Text box window handle.
        /// @param text The text string.
        /// @warning Internal use only
        static auto text(xtd::intptr control, const xtd::string& text) -> void;
        /// @brief Sets the placeholder text (aka hint) associate to the text box.
        /// @return The text string.
        /// @warning Internal use only
        static auto placeholder_text(xtd::intptr control, const xtd::string& text) -> void;
        /// @}
      };
    }
  }
}
