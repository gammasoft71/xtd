#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
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
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
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
        /// @name Protected static methods
        
        /// @{
        /// @brief Creates font.
        /// @param family_name A string representation of the font family for the new font.
        /// @param em_size The em-size of the new font in pixels.
        /// @param bold true if font is bold; otherwise false.
        /// @param italic true if font is italic; otherwise false.
        /// @param underline true if font is underline; otherwise false.
        /// @param strikeout true if font is strikeout; otherwise false.
        /// @param gdi_char_set A byte that specifies a GDI character set to use for this font.
        /// @param gdi_vertical_font A boolean value indicating whether the new xtd::drawing::font is derived from a GDI vertical font.
        /// @return The created font handle.
        /// @warning Internal use only
        static intptr create(const xtd::ustring& family_name, float em_size, bool bold, bool italic, bool underline, bool strikeout, xtd::byte gdi_char_set, bool gdi_vertical_font);
        
        /// @brief Creates font from hdc.
        /// @param hdc The handle of the device context font.
        /// @return The created font handle.
        /// @warning Internal use only
        static intptr create_from_hdc(intptr hdc);
        
        /// @brief Creates font from hfont.
        /// @param hfont The handle of the font.
        /// @return The created font handle.
        /// @warning Internal use only
        static intptr create_from_hfont(intptr hfont);
        
        /// @brief Destroys the font.
        /// @param font The font handle.
        /// @warning Internal use only
        static void destroy(intptr font);
        
        /// @brief Gets the screen dpi .
        /// @return The screen dpi.
        /// @warning Internal use only
        static int32 dpi();
        
        /// @brief Gets the font information from font hanfle.
        /// @param font The font handle to retrieve informations.
        /// @param name The font name.
        /// @param em_size The font em-size.
        /// @param bold True is the font is bold; otherwise false.
        /// @param italic True is the font is italic; otherwise false.
        /// @param underline True is the font is underline; otherwise false.
        /// @param strikeout True is the font is strikeout; otherwise false.
        /// @param gdi_char_set The GDI character set.
        /// @param gdi_vertical_font True is the font is GDI vertical font; otherwise false.
        /// | Character set | Value |
        /// | ------------- | ----- |
        /// | ANSI          | 0     |
        /// | DEFAULT       | 1     |
        /// | SYMBOL        | 2     |
        /// | SHIFTJIS      | 128   |
        /// | HANGEUL       | 129   |
        /// | HANGUL        | 129   |
        /// | GB2312        | 134   |
        /// | CHINESEBIG5   | 136   |
        /// | OEM           | 255   |
        /// | JOHAB         | 130   |
        /// | HEBREW        | 177   |
        /// | ARABIC        | 178   |
        /// | GREEK         | 161   |
        /// | TURKISH       | 162   |
        /// | VIETNAMESE    | 163   |
        /// | THAI          | 222   |
        /// | EASTEUROPE    | 238   |
        /// | RUSSIAN       | 204   |
        /// | MAC           | 77    |
        /// | BALTIC        | 186   |
        /// @warning Internal use only
        static void get_information(intptr font, xtd::ustring& name, float& em_size, bool& bold, bool& italic, bool& underline, bool& strikeout, xtd::byte& gdi_char_set, bool& gdi_vertical_font);
        
        /// @brief Gets the font height.
        /// @param font The font handle.
        /// @return The font height.
        /// @warning Internal use only
        static float height(intptr font);
        
        /// @brief Gets the font height for the specified hdc.
        /// @param font The font handle.
        /// @param hdc The device context handle.
        /// @return The font height.
        /// @warning Internal use only
        static float height(intptr font, intptr hdc);
        /// @}
      };
    }
  }
}
