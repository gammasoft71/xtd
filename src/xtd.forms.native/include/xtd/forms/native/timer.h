/// @file
/// @brief Contains xtd::forms::native::tab_control API.
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
    class timer;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains timer native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ timer final static_ {
        friend xtd::forms::timer;
      protected:
        /// @brief Create and start timer.
        /// @param interval An int32_t specifying the number of milliseconds before the tick event is raised relative to the last occurrence of the tick event. The value cannot be less than one.
        /// @param tick The delegate called at each elapsed interval until the destroy call.
        /// @return New created timer handle.
        /// @warning Internal use only
        static intptr_t create(int32_t interval, const delegate<void(const event_args&)>& tick);
        /// @brief Stop and destroy timer.
        /// @param timer timer handle.
        /// @warning Internal use only
        static void destroy(intptr_t timer);
      };
    }
  }
}
