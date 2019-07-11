#pragma once
#include <cstdint>
#include <xtd/xtd.delegates>

namespace native {
  class application_api {
  public:
    static bool allow_quit();
    static void do_events();
    static void enable_visual_style();
    static void exit();
    static void initialize_application();
    static intptr_t main_form();
    static void main_form(intptr_t handle);
    static void register_idle(xtd::delegate<void()> idle);
    static void run();
    static void unregister_idle();
  };
}
