#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal used only"
#endif
/// @endcond

#include <cstdint>
#include <string>
#include <xtd/static.h>
#include <xtd/drawing_native_export.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class drawing_native_export_ system_images final static_ {
      public:
        static intptr_t from_name(const std::string& name, int32_t width, int32_t height);
      };
    }
  }
}
/// @endcond
