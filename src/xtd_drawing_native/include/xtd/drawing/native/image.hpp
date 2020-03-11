#pragma once
#include <cstdint>
#include <istream>
#include <string>
#include <vector>
#include "argb.hpp"
#include <xtd/static.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class image static_ {
      public:
        struct property_item {
          int32_t id = 0;
          int32_t len = 0;
          int32_t type = 1;
          std::vector<uint8_t> value;
        };
        
        static void color_palette(intptr_t image, std::vector<argb>& entries, int32_t& flags);
        static intptr_t create(const std::string& filename);
        static intptr_t create(std::istream& stream);
        static intptr_t create(const char* const* bits);
        static intptr_t create(int32_t width, int32_t height);
        static intptr_t create(intptr_t image, int32_t width, int32_t height);
        static intptr_t create(intptr_t image, int32_t left, int32_t top, int32_t width, int32_t height);
        static void destroy(intptr_t image);
        static size_t flags(intptr_t image);
        static size_t frame_resolutions(intptr_t image);
        static float horizontal_resolution(intptr_t image);
        static void physical_dimension(intptr_t image, int32_t& width, int32_t& height);
        static std::vector<int32_t> property_id_list(intptr_t image);
        static std::vector<property_item> property_items(intptr_t image);
        static size_t pixel_format(intptr_t image);
        static size_t raw_format(intptr_t image);
        static void size(intptr_t image, int32_t& width, int32_t& height);
        static float vertical_resolution(intptr_t image);
        static void get_pixel(intptr_t image, int32_t x, int32_t y, argb& color);
        static void set_pixel(intptr_t image, int32_t x, int32_t y, const argb& color);
        static void save(intptr_t image, const std::string& filename);
        static void save(intptr_t image, const std::string& filename, size_t raw_format);
        static void save(intptr_t image, std::ostream& stream, size_t raw_format);
      };
    }
  }
}
/// @endcond
