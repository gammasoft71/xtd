#pragma once
#include <xtd/delegate.hpp>
#include <xtd/event_args.hpp>
#include <cstdint>

namespace native {
  class timer_api {
  public:
    static intptr_t create(int interval, const xtd::delegate<void(const xtd::event_args&)>& tick);
    static void destroy(intptr_t handle);
  };
}
