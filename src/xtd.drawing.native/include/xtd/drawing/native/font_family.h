#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <vector>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    namespace text {
      class installed_font_collection;
    }
    class font_family;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains font family native API.
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ font_family final static_ {
        friend xtd::drawing::text::installed_font_collection;
        friend xtd::drawing::font_family;
      protected:
        static intptr_t create(const xtd::ustring& name);
        static void destroy(intptr_t font_family);
        static xtd::ustring generic_serif_name();
        static xtd::ustring generic_sans_serif_name();
        static xtd::ustring generic_monospace_name();
        static std::vector<xtd::ustring> installed_font_families();
        static int32_t get_cell_ascent(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout);
        static int32_t get_cell_descent(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout);
        static int32_t get_line_spacing(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout);
        static xtd::ustring get_name(intptr_t font_family, int32_t language);
        static bool is_style_avaible(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout);
      };
    }
  }
}
