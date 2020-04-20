#pragma once
#include <cstdint>
#include <vector>
#include <xtd/static.h>
#include <xtd/xtd.delegates>

namespace xtd {
  namespace forms {
    namespace native {
      class application static_ {
      public:
        static bool allow_quit();
        static void cleanup();
        static void do_events();
        static void do_idle();
        static bool dark_mode_enabled();
        static void enable_button_images();
        static void enable_dark_mode();
        static void enable_light_mode();
        static void enable_visual_style();
        static void exit();
        static void initialize();
        static void restart();
        static void register_message_filter(const delegate<bool(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& message_filter);
        static void register_wnd_proc(const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc);
        static void run();
        static void use_wait_cursor(bool use_wait_cursor);
      };
    }
  }
}
