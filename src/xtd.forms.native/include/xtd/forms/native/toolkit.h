/// @file
/// @brief Contains xtd::forms::native::toolkit API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/ustring.h>
#include <xtd/version.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class label;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains toolkit native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @remarks No member for the moment.
      /// @warning Internal use only
      class toolkit final static_ {
      public:
        /// @brief Get the name of the toolkit
        /// @return The name of the toolkit
        static xtd::ustring name();
        /// @brief Get the description of the toolkit
        /// @return The description of the toolkit
        static xtd::ustring description();
        /// @brief Get the version of the toolkit
        /// @return The version of the toolkit
        static xtd::version version();
      };
    }
  }
}
