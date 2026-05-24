/// @file
/// @brief Contains xtd::drawing::font_family class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "font_style.hpp"
#include "text/generic_font_families.hpp"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/string>

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
    /// ```cpp
    /// class drawing_export_ font_family final : public xtd::object
    /// ```
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
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new xtd::drawing::font_family with the specified name.
      /// @param name The name of the new xtd::drawing::font_family.
      /// @exception std::invalid_argument name is an empty string ("") - or - name specifies a font that is not installed on the computer running the application.
      explicit font_family(const xtd::string& name);
      
      /// @brief Initializes a new xtd::drawing::font_family from the specified generic font family.
      /// @param generic_font_families The xtd::drawing::text::generic_font_families from which to create the new font_family.
      explicit font_family(text::generic_font_families generic_font_families);
      
      /// @brief Initializes a new xtd::drawing::font_family in the specified font_collection with the specified name.
      /// @param name The name of the new xtd::drawing::font_family.
      /// @param font_collection The FontCollection that contains this FontFamily.
      /// @exception std::invalid_argument name is an empty string ("") - or - name specifies a font that is not installed on the computer running the application - or - name specifies a font that is not a part of specified font_collection..
      font_family(const xtd::string& name, const text::font_collection& font_collection);
      /// @}
      
      /// @cond
      ~font_family();
      font_family(const font_family& value);
      font_family();
      font_family& operator =(const font_family& value);
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the name of this font_family.
      /// @return A String that represents the name of this font_family.
      [[nodiscard]] auto name() const noexcept -> const xtd::string&;
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      /// @brief Returns an array that contains all the font_family objects associated with the current graphics context.
      /// @return An array of font_family objects associated with the current graphics context.
      [[nodiscard]] static auto families() noexcept -> xtd::array<font_family>;
      
      /// @brief Gets a generic monospace font_family.
      /// @return A font_family that represents a generic monospace font.
      [[nodiscard]] static auto generic_monospace() noexcept -> font_family;
      
      /// @brief Gets a generic sans serif font_family.
      /// @return A font_family that represents a generic sans serif font.
      [[nodiscard]] static auto generic_sans_serif() noexcept -> font_family;
      
      /// @brief Gets a generic serif font_family.
      /// @return A font_family that represents a generic serif font.
      [[nodiscard]] static auto generic_serif() noexcept -> font_family;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const font_family& other) const noexcept -> bool override;
      
      /// @brief Returns the cell ascent, in design units, of the font_family of the specified style.
      /// @param style A font_style that contains style information for the font.
      /// @return The cell ascent for this font_family that uses the specified font_style.
      [[nodiscard]] auto get_cell_ascent(font_style style) const -> xtd::int32;
      
      /// @brief Returns the cell descent, in design units, of the font_family of the specified style.
      /// @param style A font_style that contains style information for the font.
      /// @return The cell ascent for this font_family that uses the specified font_style.
      [[nodiscard]] auto get_cell_descent(font_style style) const -> xtd::int32;
      
      /// @brief Gets the height, in font design units, of the em square for the specified style.
      /// @param style A font_style that contains style information for the font.
      /// @return The height of the em square.
      [[nodiscard]] auto get_em_height(font_style style) const noexcept -> xtd::int32;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      
      /// @brief Returns the line spacing, in design units, of the font_family of the specified style. The line spacing is the vertical distance between the base lines of two consecutive lines of text.
      /// @param style A font_style that contains style information for the font.
      /// @return The distance between two consecutive lines of text.
      [[nodiscard]] auto get_line_spacing(font_style style) const -> xtd::int32;
      
      /// @brief Returns the name, in the specified language, of this font_family.
      /// @param language The language in which the name is returned.
      /// @return A String that represents the name, in the specified language, of this font_family.
      /// @remarks To indicate language neutral, you should specify 0 for the language parameter. For a listing of the available languages and sublanguages, see the Winnt.h header file. If you have Visual Studio installed, this header file can typically be found relative to the Visual Studio installation directory at \\VC\PlatformSDK\Include.
      [[nodiscard]] auto get_name(int32 language) const -> xtd::string;
      
      /// @brief Indicates whether the specified font_style enumeration is available.
      /// @param style The font_style to test.
      /// @return `true` if the specified font_style is available; otherwise, `false`.
      [[nodiscard]] auto is_style_available(font_style style) const -> bool;
      
      /// @brief Converts this font_family to a human-readable string representation.
      /// @return The string that represents this font_family.
      [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
