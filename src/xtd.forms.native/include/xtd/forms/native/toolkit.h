/// @file
/// @brief Contains xtd::forms::native::toolkit API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/ustring.h>
#include <xtd/static.h>
#include <xtd/version.h>
#include <xtd/forms_native_export.h>

/// @cond
struct __init_toolkit__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class system_information;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains toolkit native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @remarks No member for the moment.
      /// @warning Internal use only
      class forms_native_export_ toolkit final static_ {
        friend struct ::__init_toolkit__;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Gets the name of the toolkit.
        /// @return The name of the toolkit.
        /// @warning Internal use only
        static xtd::ustring name();
        
        /// @brief Gets the description of the toolkit.
        /// @return The description of the toolkit.
        /// @warning Internal use only
        static xtd::ustring description();
        
        /// @brief Gets the version of the toolkit.
        /// @return The version of the toolkit.
        /// @warning Internal use only
        static xtd::version version();
        /// @}
      };
    }
  }
}
