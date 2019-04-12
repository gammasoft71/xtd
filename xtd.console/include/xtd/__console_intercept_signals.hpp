/// @file
/// @brief Contains xtd::__console_intercept_signals class.
#pragma once
#include "console.hpp"

/// @cond
struct __console_intercept_signals {
  __console_intercept_signals() {
    auto signal_keys = __opaque_console::signal_keys();
    for (auto signal : signal_keys)
      ::signal(signal.first, __console_intercept_signals::signal_handler);
  }
  
  ~__console_intercept_signals() {
    auto signal_keys = __opaque_console::signal_keys();
    for (auto signal : signal_keys)
      ::signal(signal.first, SIG_DFL);
  }
  
private:
  static void signal_handler(int signal) {
    static auto signalKeys = __opaque_console::signal_keys();
    ::signal(signal, __console_intercept_signals::signal_handler);
    if (xtd::console::treat_control_c_as_input()) {
      __opaque_console::has_ctrl_c_key(true);
    } else {
      xtd::console_cancel_event_args console_cancel(false, signalKeys[signal]);
      xtd::console::cancel_key_press(console_cancel);
      if (console_cancel.cancel() == false)
        exit(EXIT_FAILURE);
    }
  }
  static __console_intercept_signals console_intercept_signals_;
};
/// @endcond
