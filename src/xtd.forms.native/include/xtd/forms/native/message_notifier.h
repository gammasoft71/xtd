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
        /// @name Protected Static Methods

        /// @{
        /// @brief Shows message notifier
        /// @param hwnd Parent window handle.
        /// @param title The title text.
        /// @param message The message text.
        /// @param icon The icon associate to the notifier.
        /// @param style The Style (see ... for more informations).
        /// @param close_timeout_enabled true to enable close timeout; otherwhise false.
        /// @param close_timeout_interval Interval for close time out in milliseconds.
        /// @param on_notifier_closed The delagate called when message notifier is closed.
        /// @warning Internal use only
        static void show(intptr hwnd, const xtd::ustring& title, const xtd::ustring& message, const xtd::drawing::icon& icon, uint32 style, bool close_timeout_enabled, std::chrono::system_clock::duration close_timeout_interval, xtd::delegate<void()> on_notifier_closed);
        /// @}
      };
    }
  }
}
