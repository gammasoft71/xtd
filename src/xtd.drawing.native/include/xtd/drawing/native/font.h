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
    class font;
    /// @endcond

    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains font native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ font final static_ {
        friend xtd::drawing::font;
      protected:
        /// @brief Creates font.
        /// @param family_name A string representation of the font family for the new font.
        /// @param em_size The em-size of the new font in the units specified by the unit parameter.
        /// @param bold true if font is bold; otherwise false.
        /// @param italic true if font is italic; otherwise false.
        /// @param underline true if font is underline; otherwise false.
        /// @param strikeout true if font is strikeout; otherwise false.
        /// @param gdi_char_set A byte that specifies a GDI character set to use for this font.
        /// @param gdi_vertical_font A boolean value indicating whether the new xtd::drawing::font is derived from a GDI vertical font.
        /// @return The created brush handle.
        /// @warning Internal use only
        static intptr_t create(const xtd::ustring& family_name, float em_size, bool bold, bool italic, bool underline, bool strikeout, uint8_t gdi_char_set, bool gdi_vertical_font);
        static intptr_t create_from_hdc(intptr_t hdc);
        static intptr_t create_from_hfont(intptr_t hfont);
        static void destroy(intptr_t font);
        static int32_t dpi();
        static void get_information(intptr_t font, xtd::ustring& name, float& em_size, bool& bold, bool& italic, bool& underline, bool& strikeout, uint8_t& gdi_char_set, bool& gdi_vertical_font);
        static float height(intptr_t font);
        static float height(intptr_t font, intptr_t hdc);
      };
    }
  }
}
