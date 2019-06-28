#pragma once
#include <functional>
#include <cstdint>

namespace native {
  class application_api {
  public:
    static void do_events();
    static void enable_visual_style();
    static intptr_t main_form();
    static void main_form(intptr_t handle);
    static void register_idle(std::function<void()> idle);
    static void run();
    static void unregister_idle();
  };
}
