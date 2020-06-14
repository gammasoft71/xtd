#pragma once
#include <cstdint>
#include <string>
#include <xtd/static.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class system_images static_ {
      public:
        static std::string default_theme();
        static intptr_t from_name(const std::string& name, int32_t width, int32_t height);
      };
    }
  }
}
/// @endcond
