/// @file
/// @brief Contains xtd::forms::native::application API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <vector>
#include <xtd/static.h>
#include <xtd/delegate.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class application;
    class control;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @cond
      class control;
      class message_box;
      class screen;
      class settings;
      class timer;
      class wx_command_link_button;
      /// @endcond
      
      /// @brief Contains application native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ application final static_ {
        friend xtd::forms::application;
        friend xtd::forms::control;
        friend xtd::forms::native::control;
        friend xtd::forms::native::message_box;
         friend xtd::forms::native::screen;
        friend xtd::forms::native::settings;
        friend xtd::forms::native::timer;
        friend xtd::forms::native::wx_command_link_button;
      protected:
        /// @brief Gets a value indicating whether the caller can quit this application.
        /// @return true if the caller can quit this application; otherwise, false.
        /// @warning Internal use only
        static bool allow_quit();
        /// @brief Cleanup all datas, handles, references, ... initialized by initilize before quit.
        /// @remarks Some toolkits are nothing to clean. Leave this method empty.
        /// @warning Internal use only
        static void cleanup();
        /// @brief Processes all Windows messages currently in the message queue.
        /// @warning Internal use only
        static void do_events();
        /// @brief Processes do idle event.
        /// @warning Internal use only
        static void do_idle();
        /// @brief Return true if dark mode is enabled for the application; otherwise return false.
        /// @return true if dark mode is enabled; otherwise false.
        /// @warning Internal use only
        static bool dark_mode_enabled();
        /// @brief Enables button images for the application.
        /// @warning Internal use only
        static void enable_button_images();
        /// @brief Enables dark mode for the application.
        /// @warning Internal use only
        static void enable_dark_mode();
        /// @brief Enables light mode for the application.
        /// @warning Internal use only
        static void enable_light_mode();
        /// @brief Enables menu images for the application.
        /// @warning Internal use only
        static void enable_menu_images();
        /// @brief Enables visual styles for the application.
        /// @warning Internal use only
        static void enable_visual_style();
        /// @brief Exits application.
        /// @warning Internal use only
        static void exit();
        /// @brief Initialize all datas, handles, references, ... needed by tookits.
        /// @remarks Some toolkits are nothing to init. Leave this method empty.
        /// @warning Internal use only
        static void initialize();
        /// @brief Register a specified message filter from the message pump of the application.
        /// @param message_filter A message filter delegate to register.
        /// @warning Internal use only
        static void register_message_filter(const delegate<bool(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& message_filter);
        /// @brief Register a specified thread_exception from the message pump of the application.
        /// @param thread_exception A thread exception delegate to register.
        /// @remarks The thread exception delegate return true if the user want quit application after exception.
        /// @warning Internal use only
        static void register_thread_exception(const delegate<bool()>& thread_exception);
        /// @brief Register a specified wnd proc from the message pump of the application.
        /// @param wnd_proc A wnd proc delegate to register.
        /// @warning Internal use only
        static void register_wnd_proc(const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc);
        /// @brief Begins running a standard application message loop on the current thread.
        /// @warning Internal use only
        static void run();
        /// @brief Sets whether the wait cursor is used for all open forms of the application.
        /// @param use_wait_cursor true is the wait cursor is used for all open forms; otherwise, false.
        /// @warning Internal use only
        static void use_wait_cursor(bool use_wait_cursor);
      };
    }
  }
}
