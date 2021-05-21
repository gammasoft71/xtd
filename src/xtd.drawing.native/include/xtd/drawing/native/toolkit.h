#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal used only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/drawing_native_export.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class drawing_native_export_ toolkit final static_ {
      public:
        static intptr_t initialize();
        static void shutdown(intptr_t handle);
      };
    }
  }
}
/// @endcond
