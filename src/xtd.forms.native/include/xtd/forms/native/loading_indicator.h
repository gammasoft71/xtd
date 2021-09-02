/// @file
/// @brief Contains xtd::forms::native::loading_indicator API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.#pragma once
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/delegate.h>
#include <xtd/event_args.h>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class loading_indicator;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains loading_indicator native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ loading_indicator final static_ {
        friend xtd::forms::loading_indicator;
      protected:
        /// @brief Start loading indicator.
        /// @param control loading indicator handle.
        /// @warning Internal use only
        static void start(intptr_t control);
        /// @brief Stop loading indicator.
        /// @param control loading indicator handle.
        /// @warning Internal use only
        static void stop(intptr_t control);
      };
    }
  }
}
