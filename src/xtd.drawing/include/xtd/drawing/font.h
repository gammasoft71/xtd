/// @file
/// @brief Contains xtd::drawing::font class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "font_family.h"
#include "graphics_unit.h"
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
  /// @cond
  namespace forms {
    namespace native {
      class font_dialog;
    }
  }
  /// @endcond
  
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class graphics;
    class system_fonts;
    /// @endcond
    
    /// @brief Defines a particular format for text, including font face, size, and style attributes. This class cannot be inherited.
    /// @code
    /// class drawing_export_ font final : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::font
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing fonts
    class drawing_export_ font final : public xtd::object, public xtd::iequatable<font> {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief IInitializes a new Font that uses the specified existing xtd::drawing::font and size.
      /// @param prototype The existing xtd::drawing::font from which to create the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      font(const font& prototype, float em_size);
      
      /// @brief IInitializes a new Font that uses the specified existing xtd::drawing::font, size and  font_style enumeration.
      /// @param prototype The existing xtd::drawing::font from which to create the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style to apply to the new xtd::drawing::font. Multiple values of the font_style enumeration can be combined with the OR operator.
      font(const font& prototype, float em_size, font_style style);
      
      /// @brief IInitializes a new Font that uses the specified existing xtd::drawing::font and font_style enumeration.
      /// @param prototype The existing xtd::drawing::font from which to create the new xtd::drawing::font.
      /// @param style The font_style to apply to the new xtd::drawing::font. Multiple values of the font_style enumeration can be combined with the OR operator.
      font(const font& prototype, font_style style);
      
      /// @brief IInitializes a new xtd::drawing::font using the specified size, style, unit, and character set.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @param gdi_char_set A byte that specifies a GDI character set to use for this font.
      /// @param gdi_vertical_font A boolean value indicating whether the new xtd::drawing::font is derived from a GDI vertical font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h. If the familyName parameter specifies a font that is not installed on the machine running the application or is not supported, Microsoft Sans Serif will be substituted.
      font(xtd::ustring family_name, float em_size, font_style style, graphics_unit unit, xtd::byte gdi_char_set, bool gdi_vertical_font);
      
      /// @brief Initializes a new xtd::drawing::font using the specified size, style, unit, and character set.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @param gdi_char_set A byte that specifies a GDI character set to use for this font.
      /// @param gdi_vertical_font A boolean value indicating whether the new xtd::drawing::font is derived from a GDI vertical font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h. If the familyName parameter specifies a font that is not installed on the machine running the application or is not supported, Microsoft Sans Serif will be substituted.
      font(const drawing::font_family& font_family, float em_size, font_style style, graphics_unit unit, xtd::byte gdi_char_set, bool gdi_vertical_font);
      
      /// @brief Initializes a new xtd::drawing::font using the specified size, style, unit, and character set.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @param gdi_char_set A byte that specifies a GDI character set to use for this font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h. If the familyName parameter specifies a font that is not installed on the machine running the application or is not supported, Microsoft Sans Serif will be substituted.
      font(xtd::ustring family_name, float em_size, font_style style, graphics_unit unit, xtd::byte gdi_char_set);
      
      /// @brief Initializes a new xtd::drawing::font using the specified size, style, unit, and character set.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @param gdi_char_set A byte that specifies a GDI character set to use for this font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h. If the familyName parameter specifies a font that is not installed on the machine running the application or is not supported, Microsoft Sans Serif will be substituted.
      font(const drawing::font_family& font_family, float em_size, font_style style, graphics_unit unit, xtd::byte gdi_char_set);
      
      /// @brief Initializes a new xtd::drawing::font using the specified size, style and unit.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(xtd::ustring family_name, float em_size, font_style style, graphics_unit unit);
      
      /// @brief Initializes a new xtd::drawing::font using the specified size, style and unit.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(const drawing::font_family& font_family, float em_size, font_style style, graphics_unit unit);
      
      /// @brief Initializes a new xtd::drawing::font using the specified size and style.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(xtd::ustring family_name, float em_size, font_style style);
      
      /// @brief Initializes a new xtd::drawing::font using the specified size and style.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(const drawing::font_family& font_family, float em_size, font_style style);
      
      /// @brief Initializes a new xtd::drawing::font using the specified size and unit.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(xtd::ustring family_name, float em_size, graphics_unit unit);
      
      /// @brief Initializes a new xtd::drawing::font using the specified size and unit.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(const drawing::font_family& font_family, float em_size, graphics_unit unit);
      
      /// @brief Initializes a new xtd::drawing::font using the specified size and unit.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(xtd::ustring family_name, float em_size);
      
      /// @brief Initializes a new xtd::drawing::font using the specified size.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(const drawing::font_family& font_family, float em_size);
      /// @}
      
      /// @cond
      font(const font& value);
      font& operator =(const font& value);
      ~font();
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value that indicates whether this xtd::drawing::font is bold.
      /// @return true if this xtd::drawing::font is bold; otherwise, false.
      bool bold() const noexcept;
      
      /// @brief Gets the xtd::drawing::font_family associated with this xtd::drawing::font.
      /// @return The font_family associated with this Font.
      /// @remarks A font_family represents a group of fonts that have a similar font face, but may have different sizes and styles (for example, Arial, Times New Roman, and Verdana).
      drawing::font_family font_family() const noexcept;
      
      /// @brief Gets a byte value that specifies the GDI character set that this xtd::drawing::font uses.
      /// @return A byte value that specifies the GDI character set that this xtd::drawing::font uses. The default is 1.
      /// @remarks This property returns 1, unless a different character set is specified in the font(string, float, font_style, graphics_unit, xtd::byte) constructor. This property takes a value from the list defined in the Windows SDK header file WinGDI.h. The character sets and byte values are listed in the following table.
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
      xtd::byte gdi_char_set() const noexcept;
      
      /// @brief Gets a Boolean value that indicates whether this xtd::drawing::font is derived from a GDI vertical font.
      /// @return true if this xtd::drawing::font is derived from a GDI vertical font; otherwise, false.
      /// @remarks Use this property to determine if a font is compatible with native Win32 controls on non-Unicode platforms.
      /// @remarks gdi_vertical_font only returns true if this font was created from a classic GDI font definition, like a LOGFONT or HFONT.
      bool gdi_vertical_font() const noexcept;
      
      /// @brief Gets the window handle that the font is bound to.
      /// @return An intptr that contains the window handle (hfont) of the font.
      intptr handle() const noexcept;
      
      /// @brief Gets the line spacing of this font.
      /// @return The line spacing, in pixels, of this font.
      /// @remarks The line spacing is the vertical distance between the base lines of two consecutive lines of text. Thus, the line spacing includes the blank space between lines along with the height of the character itself.
      /// @remarks If the unit property of the font is set to anything other than graphics_unit::pixel, the height (in pixels) is calculated using the vertical resolution of the screen display. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em-height is 2048 and the line spacing is 2355. For a screen display that has a vertical resolution of 96 dots per inch, you can calculate the height as follows:
      /// @remarks 2355*(0.3/2048)*96 = 33.11719
      /// @remarks The value returned by the get_height method would be 33.11719, and the value returned by the height property would be 34. The height property is the value returned by get_height, rounded up to the nearest integer.
      int32 height() const noexcept;
      
      /// @brief Gets a value indicating whether the font is a member of xtd::drawing::system_fonts.
      /// @return true if the font is a member of xtd::drawing::system_fonts; otherwise, false. The default is false.
      /// @remarks When the user changes the system font, the is_system_font property could return true, even if the font is not actually a system font.
      bool is_system_font() const noexcept;
      
      /// @brief Gets a value that indicates whether this xtd::drawing::font is italic.
      /// @return true if this xtd::drawing::font is italic; otherwise, false.
      bool italic() const noexcept;
      
      /// @brief Gets the face name of this xtd::drawing::font.
      /// @return A string representation of the face name of this xtd::drawing::font.
      const xtd::ustring& name() const noexcept;
      
      /// @brief Gets the face name of this Font.
      /// @return A string representation of the face name of this Font.
      const xtd::ustring& original_font_name() const noexcept;
      
      /// @brief Gets the em-size of this xtd::drawing::font measured in the units specified by the unit property.
      /// @return The em-size of this xtd::drawing::font.
      float size() const noexcept;
      
      /// @brizef Gets the em-size, in points, of this xtd::drawing::font.
      /// @return The em-size, in points, of this xtd::drawing::font.
      float size_in_points() const noexcept;
      
      /// @brief Gets a value that indicates whether this xtd::drawing::font is strikeout.
      /// @return true if this xtd::drawing::font is strikeout; otherwise, false.
      bool strikeout() const noexcept;
      
      /// @brief Gets style information for this xtd::drawing::font.
      /// @return A font_style enumeration that contains style information for this xtd::drawing::font.
      font_style style() const noexcept;
      
      /// @brief Gets a value that indicates whether this xtd::drawing::font is underline.
      /// @return true if this xtd::drawing::font is underline; otherwise, false.
      bool underline() const noexcept;
      
      /// @brief Gets the unit of measure for this xtd::drawing::font.
      /// @return A graphics_unit that represents the unit of measure for this xtd::drawing::font.
      graphics_unit unit() const noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      bool equals(const font& value) const noexcept override;
      
      /// @brief Creates a font from the specified Windows handle to a device context.
      /// @param hdc A handle to a device context.
      /// @return The font this method creates.
      static font from_hdc(const intptr hdc);
      
      /// @brief Creates a font from the specified Windows handle.
      /// @param hfont A Windows handle to a GDI font.
      /// @return The font this method creates.
      static font from_hfont(const intptr hfont);
      
      /// @brief Returns the line spacing, in pixels, of this font.
      /// @return The line spacing, in pixels, of this font.
      /// @remarks The line spacing of a xtd::drawing::font is the vertical distance between the base lines of two consecutive lines of text. Thus, the line spacing includes the blank space between lines along with the height of the character itself.
      /// @remarks If the unit property of the font is set to anything other than graphics_unit::pixel, the height (in pixels) is calculated using the vertical resolution of the screen display. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em-height is 2048 and the line spacing is 2355. For a screen display that has a vertical resolution of 96 dots per inch, you can calculate the height as follows: <br> 2355*(0.3/2048)*96 = 33.11719
      float get_height() const;
      
      /// @brief Returns the line spacing, in the current unit of a specified xtd::drawing::graphics, of this font.
      /// @param graphics A xtd::drawing::graphics that holds the vertical resolution, in dots per inch, of the display device as well as settings for page unit and page scale.
      /// @return The line spacing, in pixels, of this font.
      /// @remarks The line spacing of a xtd::drawing::font is the vertical distance between the base lines of two consecutive lines of text. Thus, the line spacing includes the blank space between lines along with the height of the character itself.
      /// @remarks If the unit property of the font is set to anything other than graphics_unit::pixel, the height (in pixels) is calculated using the vertical resolution of the screen display. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em-height is 2048 and the line spacing is 2355. For a screen display that has a vertical resolution of 96 dots per inch, you can calculate the height as follows: <br> 2355*(0.3/2048)*96 = 33.11719
      float get_height(const graphics& graphics) const;
      
      /// @brief Returns the height, in pixels, of this Font when drawn to a device with the specified vertical resolution.
      /// @param dpi The vertical resolution, in dots per inch, used to calculate the height of the font.
      /// @return The height, in pixels, of this xtd::drawing::font.
      /// @remarks If the unit property of the font is set to anything other than graphics_unit::pixel, the height (in pixels) is calculated using the vertical resolution of the screen display. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em-height is 2048 and the line spacing is 2355. If the specified vertical resolution is 96 dots per inch, the height is calculated as follows: <br> 2355*(0.3/2048)*96 = 33.1171875
      float get_height(float dpi) const;
      
      /// @return Returns a handle to this xtd::drawing::font.
      /// @return A Windows handle to this xtd::drawing::font.
      /// @remarks When using this method, you must dispose of the resulting Hfont using the GDI DeleteObject method to ensure the resources are released.
      intptr to_hfont() const;
      
      /// @brief Converts this font_family to a human-readable string representation.
      /// @return The string that represents this font_family.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      friend class graphics;
      friend class system_fonts;
      friend class xtd::forms::native::font_dialog;
      font();
      explicit font(intptr hfont);
      
      std::shared_ptr<data> data_;
    };
  }
}
