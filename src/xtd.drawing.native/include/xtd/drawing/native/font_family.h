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
    namespace text {
      class installed_font_collection;
    }
    class font_family;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains font family native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ font_family final static_ {
        friend xtd::drawing::text::installed_font_collection;
        friend xtd::drawing::font_family;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Creates fontt family from name.
        /// @param name The name of the fontt family.
        /// @return The created font family handle.
        /// @warning Internal use only
        static intptr create(const xtd::ustring& name);
        
        /// @brief Destroys the font family.
        /// @param font_family The font family handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr font_family);
        
        /// @brief Gets the generic serif name.
        /// @return The generic serif name.
        /// @warning Internal use only
        static xtd::ustring generic_serif_name();
        
        /// @brief Gets the generic sans serif name.
        /// @return The generic sans serif name.
        /// @warning Internal use only
        static xtd::ustring generic_sans_serif_name();
        
        /// @brief Gets the generic monospace name.
        /// @return The generic monospace name.
        /// @warning Internal use only
        static xtd::ustring generic_monospace_name();
        
        /// @brief Gets the installed font families.
        /// @return The installed font families.
        /// @warning Internal use only
        static std::vector<xtd::ustring> installed_font_families();
        
        /// @brief Gets the cell ascent.
        /// @param font_family The fontt family handle.
        /// @param em_height The em-height of the font family in pixels.
        /// @param bold true if font family is bold; otherwise false.
        /// @param italic true if font family is italic; otherwise false.
        /// @param underline true if font family is underline; otherwise false.
        /// @param strikeout true if font family is strikeout; otherwise false.
        /// @return The cell ascent.
        /// @warning Internal use only
        static int32 get_cell_ascent(intptr font_family, int32 em_height, bool bold, bool italic, bool underline, bool strikeout);
        
        /// @brief Gets the cell descent.
        /// @param font_family The fontt family handle.
        /// @param em_height The em-height of the font family in pixels.
        /// @param bold true if font family is bold; otherwise false.
        /// @param italic true if font family is italic; otherwise false.
        /// @param underline true if font family is underline; otherwise false.
        /// @param strikeout true if font family is strikeout; otherwise false.
        /// @return The cell descent.
        /// @warning Internal use only
        static int32 get_cell_descent(intptr font_family, int32 em_height, bool bold, bool italic, bool underline, bool strikeout);
        
        /// @brief Gets the line spacing.
        /// @param font_family The fontt family handle.
        /// @param em_height The em-height of the font family in pixels.
        /// @param bold true if font family is bold; otherwise false.
        /// @param italic true if font family is italic; otherwise false.
        /// @param underline true if font family is underline; otherwise false.
        /// @param strikeout true if font family is strikeout; otherwise false.
        /// @return The line spacing.
        /// @warning Internal use only
        static int32 get_line_spacing(intptr font_family, int32 em_height, bool bold, bool italic, bool underline, bool strikeout);
        
        /// @brief Gets the font name for specifiedd language.
        /// @param font_family The fontt family handle.
        /// @param language The language id for retreive the font family name.
        /// @return The font tfamily name.
        /// @remarks To indicate language neutral, you should specify 0 for the language parameter. For a listing of the available languages and sublanguages, see the Winnt.h header file. If you have Visual Studio installed, this header file can typically be found relative to the Visual Studio installation directory at \\VC\PlatformSDK\Include.
        /// @warning Internal use only
        static xtd::ustring get_name(intptr font_family, int32 language);
        
        /// @brief Gets the style availability.
        /// @param font_family The fontt family handle.
        /// @param em_height The em-height of the font family in pixels.
        /// @param bold true if font family is bold; otherwise false.
        /// @param italic true if font family is italic; otherwise false.
        /// @param underline true if font family is underline; otherwise false.
        /// @param strikeout true if font family is strikeout; otherwise false.
        /// @return True if font family is availlable; otherwise false.
        /// @warning Internal use only
        static bool is_style_available(intptr font_family, bool bold, bool italic, bool underline, bool strikeout);
        /// @}
      };
    }
  }
}
