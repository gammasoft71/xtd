#pragma once
#include <cstdint>
#include <xtd/delegate.h>
#include <xtd/event_args.h>
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class timer static_ {
      public:
        static intptr_t create(int32_t interval, const delegate<void(const event_args&)>& tick);
        static void destroy(intptr_t handle);
      };
    }
  }
}
