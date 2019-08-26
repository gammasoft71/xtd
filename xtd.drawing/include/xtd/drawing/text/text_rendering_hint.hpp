#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::text namespace provides advanced GDI+ typography functionality.
    namespace text {
      /// @brief Specifies the quality of text rendering.
      /// @remarks The quality ranges from text (fastest performance, but lowest quality) to antialiased text (better quality, but slower performance) to ClearType text (best quality on an LCD display).
      enum class text_rendering_hint {
        /// @brief Each character is drawn using its glyph bitmap, with the system default rendering hint. The text will be drawn using whatever font-smoothing settings the user has selected for the system.
        system_default = 0,
        /// @brief Each character is drawn using its glyph bitmap. Hinting is used to improve character appearance on stems and curvature.
        single_bit_per_pixel_grid_fit = 1,
        /// @brief Each character is drawn using its glyph bitmap. Hinting is not used.
        single_bit_per_pixel = 2,
        /// @brief Each character is drawn using its antialiased glyph bitmap with hinting. Much better quality due to antialiasing, but at a higher performance cost.
        anti_alias_grid_fit = 3,
        /// @brief Each character is drawn using its antialiased glyph bitmap without hinting. Better quality due to antialiasing. Stem width differences may be noticeable because hinting is turned off.
        anti_alias = 4,
        /// @brief Each character is drawn using its glyph ClearType bitmap with hinting. The highest quality setting. Used to take advantage of ClearType font features.
        clear_type_grid_fit = 5
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, text_rendering_hint value) {return os << xtd::to_string(value, {{text_rendering_hint::system_default, "system_default"}, {text_rendering_hint::single_bit_per_pixel_grid_fit, "single_bit_per_pixel_grid_fit"}, {text_rendering_hint::single_bit_per_pixel, "single_bit_per_pixel"}, {text_rendering_hint::anti_alias_grid_fit, "anti_alias_grid_fit"}, {text_rendering_hint::anti_alias, "anti_alias"}, {text_rendering_hint::clear_type_grid_fit, "clear_type_grid_fit"}});}
      inline std::wostream& operator<<(std::wostream& os, text_rendering_hint value) {return os << xtd::to_string(value, {{text_rendering_hint::system_default, L"system_default"}, {text_rendering_hint::single_bit_per_pixel_grid_fit, L"single_bit_per_pixel_grid_fit"}, {text_rendering_hint::single_bit_per_pixel, L"single_bit_per_pixel"}, {text_rendering_hint::anti_alias_grid_fit, L"anti_alias_grid_fit"}, {text_rendering_hint::anti_alias, L"anti_alias"}, {text_rendering_hint::clear_type_grid_fit, L"clear_type_grid_fit"}});}
      /// @endcond
    }
  }
}
