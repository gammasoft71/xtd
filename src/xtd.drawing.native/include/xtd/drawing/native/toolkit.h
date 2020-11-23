#pragma once
#include <cstdint>
#include <xtd/static.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class toolkit final static_ {
      public:
        static intptr_t initialize();
        static void shutdown(intptr_t handle);
      };
    }
  }
}
/// @endcond
