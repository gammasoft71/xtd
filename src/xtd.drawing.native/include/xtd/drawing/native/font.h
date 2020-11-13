#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <xtd/static.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class font static_ {
      public:
        static intptr_t create(const std::string& name, float em_size, bool bold, bool italic, bool underline, bool strikeout, uint8_t gdi_char_set, bool gdi_vertical_font);
        static intptr_t create_from_hdc(intptr_t hdc);
        static intptr_t create_from_hfont(intptr_t hfont);
        static void destroy(intptr_t font);
        static int32_t dpi();
        static void get_information(intptr_t font, std::string& name, float& em_size, bool& bold, bool& italic, bool& underline, bool& strikeout, uint8_t& gdi_char_set, bool& gdi_vertical_font);
        static float height(intptr_t font);
        static float height(intptr_t font, intptr_t hdc);
      };
    }
  }
}
/// @endcond
