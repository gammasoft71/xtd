#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal used only"
#endif
/// @endcond

#include <cstdint>
#include <string>
#include <vector>
#include <xtd/static.h>
#include <xtd/drawing_native_export.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class drawing_native_export_ font_family final static_ {
      public:
        static intptr_t create(const std::string& name);
        static void destroy(intptr_t font_family);
        static std::string generic_serif_name();
        static std::string generic_sans_serif_name();
        static std::string generic_monospace_name();
        static std::vector<std::string> installed_font_families();
        static int32_t get_cell_ascent(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout);
        static int32_t get_cell_descent(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout);
        static int32_t get_line_spacing(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout);
        static std::string get_name(intptr_t font_family, int32_t language);
        static bool is_style_avaible(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout);
      };
    }
  }
}
/// @endcond
