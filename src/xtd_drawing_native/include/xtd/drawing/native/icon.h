#pragma once
#include <cstdint>
#include <istream>
#include <string>
#include <vector>
#include "argb.h"
#include <xtd/static.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class icon static_ {
      public:
        struct property_item {
          int32_t id = 0;
          int32_t len = 0;
          int32_t type = 1;
          std::vector<uint8_t> value;
        };
        
        static intptr_t create(const std::string& filename);
        static intptr_t create(std::istream& stream);
        static intptr_t create(const char* const* bits);
        static intptr_t create(intptr_t icon, int32_t width, int32_t height);
        static void destroy(intptr_t icon);
        static void save(intptr_t icon, const std::string& filename);
        static void save(intptr_t icon, std::ostream& stream);
        static intptr_t to_bitmap(intptr_t icon);
      };
    }
  }
}
/// @endcond
