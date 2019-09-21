#pragma once
#include <cstdint>
#include <vector>
#include <xtd/xtd.delegates>

namespace xtd {
  namespace forms {
    namespace native {
      class application {
      public:
        application() = delete;
        static bool allow_quit();
        static void cleanup();
        static void do_events();
        static void do_idle();
        static void enable_visual_style();
        static void exit();
        static void initialize();
        static void restart();
        static intptr_t main_form();
        static void register_message_filter(const delegate<bool(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& message_filter);
        static void register_wnd_proc(const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc);
        static void run();
      };
    }
  }
}
