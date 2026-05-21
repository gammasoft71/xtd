#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/array>
#include <xtd/static>
#include <xtd/string>
#include <xtd/drawing_native_export.hpp>

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
        [[nodiscard]] static auto create(const xtd::string& name) -> xtd::intptr;
        
        /// @brief Destroys the font family.
        /// @param font_family The font family handle to destroy.
        /// @warning Internal use only
        static auto destroy(intptr font_family) -> void;
        
        /// @brief Gets the generic serif name.
        /// @return The generic serif name.
        /// @warning Internal use only
        [[nodiscard]] static auto generic_serif_name() -> xtd::string;
        
        /// @brief Gets the generic sans serif name.
        /// @return The generic sans serif name.
        /// @warning Internal use only
        [[nodiscard]] static auto generic_sans_serif_name() -> xtd::string;
        
        /// @brief Gets the generic monospace name.
        /// @return The generic monospace name.
        /// @warning Internal use only
        [[nodiscard]] static auto generic_monospace_name() -> xtd::string;
        
        /// @brief Gets the installed font families.
        /// @return The installed font families.
        /// @warning Internal use only
        [[nodiscard]] static auto installed_font_families() -> xtd::array<xtd::string>;
        
        /// @brief Gets the cell ascent.
        /// @param font_family The fontt family handle.
        /// @param em_height The em-height of the font family in pixels.
        /// @param bold `true` if font family is bold; otherwise `false`.
        /// @param italic `true` if font family is italic; otherwise `false`.
        /// @param underline `true` if font family is underline; otherwise `false`.
        /// @param strikeout `true` if font family is strikeout; otherwise `false`.
        /// @return The cell ascent.
        /// @warning Internal use only
        [[nodiscard]] static auto get_cell_ascent(xtd::intptr font_family, xtd::int32 em_height, bool bold, bool italic, bool underline, bool strikeout) -> xtd::int32;
        
        /// @brief Gets the cell descent.
        /// @param font_family The fontt family handle.
        /// @param em_height The em-height of the font family in pixels.
        /// @param bold `true` if font family is bold; otherwise `false`.
        /// @param italic `true` if font family is italic; otherwise `false`.
        /// @param underline `true` if font family is underline; otherwise `false`.
        /// @param strikeout `true` if font family is strikeout; otherwise `false`.
        /// @return The cell descent.
        /// @warning Internal use only
        [[nodiscard]] static auto get_cell_descent(xtd::intptr font_family, xtd::int32 em_height, bool bold, bool italic, bool underline, bool strikeout) -> xtd::int32;
        
        /// @brief Gets the line spacing.
        /// @param font_family The fontt family handle.
        /// @param em_height The em-height of the font family in pixels.
        /// @param bold `true` if font family is bold; otherwise `false`.
        /// @param italic `true` if font family is italic; otherwise `false`.
        /// @param underline `true` if font family is underline; otherwise `false`.
        /// @param strikeout `true` if font family is strikeout; otherwise `false`.
        /// @return The line spacing.
        /// @warning Internal use only
        [[nodiscard]] static auto get_line_spacing(xtd::intptr font_family, xtd::int32 em_height, bool bold, bool italic, bool underline, bool strikeout) -> xtd::int32;
        
        /// @brief Gets the font name for specifiedd language.
        /// @param font_family The fontt family handle.
        /// @param language The language id for retreive the font family name.
        /// @return The font tfamily name.
        /// @remarks To indicate language neutral, you should specify 0 for the language parameter. For a listing of the available languages and sublanguages, see the Winnt.h header file. If you have Visual Studio installed, this header file can typically be found relative to the Visual Studio installation directory at \\VC\PlatformSDK\Include.
        /// @warning Internal use only
        [[nodiscard]] static auto get_name(xtd::intptr font_family, xtd::int32 language) -> xtd::string;
        
        /// @brief Gets the style availability.
        /// @param font_family The fontt family handle.
        /// @param em_height The em-height of the font family in pixels.
        /// @param bold `true` if font family is bold; otherwise `false`.
        /// @param italic `true` if font family is italic; otherwise `false`.
        /// @param underline `true` if font family is underline; otherwise `false`.
        /// @param strikeout `true` if font family is strikeout; otherwise `false`.
        /// @return `true` if font family is availlable; otherwise `false`.
        /// @warning Internal use only
        [[nodiscard]] static auto is_style_available(xtd::intptr font_family, bool bold, bool italic, bool underline, bool strikeout) -> bool;
        /// @}
      };
    }
  }
}
