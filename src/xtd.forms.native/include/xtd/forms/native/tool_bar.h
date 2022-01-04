/// @file
/// @brief Contains xtd::forms::native::tool_bar API.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
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
      /// @brief Contains light button native API.
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
        static intptr_t add_tool_bar_button(intptr_t control, const xtd::ustring& text, intptr_t image);
        static intptr_t add_tool_bar_separator(intptr_t control);
        /// @brief Sets the tool_bar that is displayed in the form.
        /// @param control Control window handle.
        /// @param tool_bar A tool bar handle that represents the tool bar to display in the form.
        /// @warning Internal use only
        static bool set_system_tool_bar(intptr_t control, intptr_t tool_bar);
        /// @}
      };
    }
  }
}
