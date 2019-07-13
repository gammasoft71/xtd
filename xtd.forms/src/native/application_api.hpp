#pragma once
#include <cstdint>
#include <vector>
#include <xtd/xtd.delegates>
#include "../../include/xtd/forms/message.hpp"

namespace native {
  class application_api {
  public:
    static bool allow_quit();
    static void do_events();
    static void do_idle();
    static void enable_visual_style();
    static void exit();
    static void initialize_application();
    static intptr_t main_form();
    static void main_form(intptr_t handle);
    static std::vector<intptr_t> open_forms();
    static void register_wnd_proc(xtd::delegate<void(xtd::forms::message&)> wnd_proc);
    static void run();
    static void unregister_wnd_proc();
  };
}
