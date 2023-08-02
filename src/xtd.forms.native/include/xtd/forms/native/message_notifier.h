#pragma once
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif

#include <cstdint>
#include <string>
#include <xtd/delegate.h>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/forms_native_export.h>
#include <xtd/drawing/icon.h>
#include <xtd/guid.h>
#include <xtd/chrono>
// TODO: Documentation


namespace xtd {
  namespace forms {
    class message_notifier;
    namespace native {
      class forms_native_export_ message_notifier final static_ {
        friend xtd::forms::message_notifier;
      protected:
        /// @param hwnd Parent window handle.
        static void show(intptr hwnd,
          const xtd::ustring& title,
          const xtd::ustring& message,
          const xtd::drawing::icon& icon,
          uint32 style,
          bool close_timeout_enabled_,
          std::chrono::system_clock::duration close_timeout_interval,
          xtd::delegate<void()> on_notifier_closed);
          
          
          
          
      };
    }
  }
}
