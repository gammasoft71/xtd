/// @file
/// @brief Contains xtd::drawing::font_family class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "font_style.h"
#include "text/generic_font_families.h"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>
#include <cstdint>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    namespace text {
      class font_collection;
    }
    /// @endcond
    
    /// @brief Defines a group of type faces having a similar basic design and certain variations in styles. This class cannot be inherited.
    /// @code
    /// class drawing_export_ font_family final : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::font_family
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing fonts
    class drawing_export_ font_family final : public xtd::object, public xtd::iequatable<font_family> {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new xtd::drawing::font_family with the specified name.
      /// @param name The name of the new xtd::drawing::font_family.
      /// @exception std::invalid_argument name is an empty string ("") - or - name specifies a font that is not installed on the computer running the application.
      explicit font_family(const xtd::ustring& name);
      
      /// @brief Initializes a new xtd::drawing::font_family from the specified generic font family.
      /// @param generic_font_families The xtd::drawing::text::generic_font_families from which to create the new font_family.
      explicit font_family(text::generic_font_families generic_font_families);
      
      /// @brief Initializes a new xtd::drawing::font_family in the specified font_collection with the specified name.
      /// @param name The name of the new xtd::drawing::font_family.
      /// @param font_collection The FontCollection that contains this FontFamily.
      /// @exception std::invalid_argument name is an empty string ("") - or - name specifies a font that is not installed on the computer running the application - or - name specifies a font that is not a part of specified font_collection..
      font_family(const xtd::ustring& name, const text::font_collection& font_collection);
      /// @}
      
      /// @cond
      ~font_family();
      font_family(const font_family& value);
      font_family();
      font_family& operator =(const font_family& value);
      /// @endcond

      /// @name Properties
      
      /// @{
      /// @brief Gets the name of this font_family.
      /// @return A String that represents the name of this font_family.
      const xtd::ustring& name() const noexcept;
      /// @}

      /// @name Static properties
      
      /// @{
      /// @brief Returns an array that contains all the font_family objects associated with the current graphics context.
      /// @return An array of font_family objects associated with the current graphics context.
      static std::vector<font_family> families() noexcept;
      
      /// @brief Gets a generic monospace font_family.
      /// @return A font_family that represents a generic monospace font.
      static font_family generic_monospace() noexcept;
      
      /// @brief Gets a generic sans serif font_family.
      /// @return A font_family that represents a generic sans serif font.
      static font_family generic_sans_serif() noexcept;
      
      /// @brief Gets a generic serif font_family.
      /// @return A font_family that represents a generic serif font.
      static font_family generic_serif() noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      bool equals(const font_family& value) const noexcept override;
      
      /// @brief Returns the cell ascent, in design units, of the font_family of the specified style.
      /// @param style A font_style that contains style information for the font.
      /// @return The cell ascent for this font_family that uses the specified font_style.
      int32 get_cell_ascent(font_style style) const;
      
      /// @brief Returns the cell descent, in design units, of the font_family of the specified style.
      /// @param style A font_style that contains style information for the font.
      /// @return The cell ascent for this font_family that uses the specified font_style.
      int32 get_cell_descent(font_style style) const;
      
      /// @brief Gets the height, in font design units, of the em square for the specified style.
      /// @param style A font_style that contains style information for the font.
      /// @return The height of the em square.
      int32 get_em_height(font_style style) const noexcept;
      
      /// @brief Returns the line spacing, in design units, of the font_family of the specified style. The line spacing is the vertical distance between the base lines of two consecutive lines of text.
      /// @param style A font_style that contains style information for the font.
      /// @return The distance between two consecutive lines of text.
      int32 get_line_spacing(font_style style) const;
      
      /// @brief Returns the name, in the specified language, of this font_family.
      /// @param language The language in which the name is returned.
      /// @return A String that represents the name, in the specified language, of this font_family.
      /// @remarks To indicate language neutral, you should specify 0 for the language parameter. For a listing of the available languages and sublanguages, see the Winnt.h header file. If you have Visual Studio installed, this header file can typically be found relative to the Visual Studio installation directory at \\VC\PlatformSDK\Include.
      xtd::ustring get_name(int32 language) const;
      
      /// @brief Indicates whether the specified font_style enumeration is available.
      /// @param style The font_style to test.
      /// @return true if the specified font_style is available; otherwise, false.
      bool is_style_available(font_style style) const;
      
      /// @brief Converts this font_family to a human-readable string representation.
      /// @return The string that represents this font_family.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
