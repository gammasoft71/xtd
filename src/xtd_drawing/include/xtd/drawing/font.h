#pragma once
#include <cstdint>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <vector>
#include <xtd/xtd.strings>
#include "font_family.h"
#include "graphics_unit.h"

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
    class font final {
    public:
      /// @brief Initializes a new Font that uses the specified existing xtd::drawing::font and size.
      /// @param prototype The existing xtd::drawing::font from which to create the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      font (const font& prototype, float em_size);
      
      /// @brief Initializes a new Font that uses the specified existing xtd::drawing::font, size and  font_style enumeration.
      /// @param prototype The existing xtd::drawing::font from which to create the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style to apply to the new xtd::drawing::font. Multiple values of the font_style enumeration can be combined with the OR operator.
      font (const font& prototype, float em_size, font_style style);
      
      /// @brief Initializes a new Font that uses the specified existing xtd::drawing::font and font_style enumeration.
      /// @param prototype The existing xtd::drawing::font from which to create the new xtd::drawing::font.
      /// @param style The font_style to apply to the new xtd::drawing::font. Multiple values of the font_style enumeration can be combined with the OR operator.
      font (const font& prototype, font_style style);
      
      /// @brief nitializes a new xtd::drawing::font using the specified size, style, unit, and character set.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @param gdi_char_set A byte that specifies a GDI character set to use for this font.
      /// @param gdi_vertical_font A boolean value indicating whether the new xtd::drawing::font is derived from a GDI vertical font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h. If the familyName parameter specifies a font that is not installed on the machine running the application or is not supported, Microsoft Sans Serif will be substituted.
      font(std::string family_name, float em_size, font_style style, graphics_unit unit, uint8_t gdi_char_set, bool gdi_vertical_font);
      
      /// @brief nitializes a new xtd::drawing::font using the specified size, style, unit, and character set.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @param gdi_char_set A byte that specifies a GDI character set to use for this font.
      /// @param gdi_vertical_font A boolean value indicating whether the new xtd::drawing::font is derived from a GDI vertical font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h. If the familyName parameter specifies a font that is not installed on the machine running the application or is not supported, Microsoft Sans Serif will be substituted.
      font(const drawing::font_family& font_family, float em_size, font_style style, graphics_unit unit, uint8_t gdi_char_set, bool gdi_vertical_font) : font(font_family.name(), em_size, style, unit, gdi_char_set, gdi_vertical_font) {}
      
      /// @brief nitializes a new xtd::drawing::font using the specified size, style, unit, and character set.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @param gdi_char_set A byte that specifies a GDI character set to use for this font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h. If the familyName parameter specifies a font that is not installed on the machine running the application or is not supported, Microsoft Sans Serif will be substituted.
      font(std::string family_name, float em_size, font_style style, graphics_unit unit, uint8_t gdi_char_set) : font(family_name, em_size, style, unit, gdi_char_set, false) {}
      
      /// @brief nitializes a new xtd::drawing::font using the specified size, style, unit, and character set.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @param gdi_char_set A byte that specifies a GDI character set to use for this font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      /// @remarks The gdiCharSet parameter takes a value from the list defined in the Windows SDK header file WinGDI.h. If the familyName parameter specifies a font that is not installed on the machine running the application or is not supported, Microsoft Sans Serif will be substituted.
      font(const drawing::font_family& font_family, float em_size, font_style style, graphics_unit unit, uint8_t gdi_char_set) : font(font_family, em_size, style, unit, gdi_char_set, false) {}
      
      /// @brief nitializes a new xtd::drawing::font using the specified size, style and unit.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(std::string family_name, float em_size, font_style style, graphics_unit unit) : font(family_name, em_size, style, unit, 0, false) {}
      
      /// @brief nitializes a new xtd::drawing::font using the specified size, style and unit.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(const drawing::font_family& font_family, float em_size, font_style style, graphics_unit unit) : font(font_family, em_size, style, unit, 0, false) {}
      
      /// @brief nitializes a new xtd::drawing::font using the specified size and style.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(std::string family_name, float em_size, font_style style) : font(family_name, em_size, style, graphics_unit::point, 0, false) {}
      
      /// @brief nitializes a new xtd::drawing::font using the specified size and style.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param style The font_style of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(const drawing::font_family& font_family, float em_size, font_style style) : font(font_family, em_size, style, graphics_unit::point, 0, false) {}
      
      /// @brief nitializes a new xtd::drawing::font using the specified size and unit.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(std::string family_name, float em_size, graphics_unit unit) : font(family_name, em_size, font_style::regular, unit, 0, false) {}
      
      /// @brief nitializes a new xtd::drawing::font using the specified size and unit.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @param unit The graphics_unit of the new xtd::drawing::font.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(const drawing::font_family& font_family, float em_size, graphics_unit unit) : font(font_family, em_size, font_style::regular, unit, 0, false) {}

      /// @brief nitializes a new xtd::drawing::font using the specified size and unit.
      /// @param family_name A string representation of the font_family for the new xtd::drawing::font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(std::string family_name, float em_size) : font(family_name, em_size, font_style::regular, graphics_unit::point, 0, false) {}
      
      /// @brief nitializes a new xtd::drawing::font using the specified size.
      /// @param font_family The font_family of the new Font.
      /// @param em_size The em-size of the new font in the units specified by the unit parameter.
      /// @exception std::invalid_param emSize is less than or equal to 0, evaluates to infinity, or is not a valid number.
      font(const drawing::font_family& font_family, float em_size) : font(font_family, em_size, font_style::regular, graphics_unit::point, 0, false) {}

      /// @cond
      font(const font& value);
      font& operator=(const font& value);
      bool operator==(const font& value) const {return this->data_->font_family_ == value.data_->font_family_ && this->data_->gdi_char_set_ == value.data_->gdi_char_set_ && this->data_->gdi_vertical_font_ == value.data_->gdi_vertical_font_ && this->data_->style_ == value.data_->style_ && this->data_->size_ == value.data_->size_ && this->data_->unit_ == value.data_->unit_;}
      bool operator!=(const font& value) const {return !this->operator==(value);}
      ~font();
      /// @endcond
      
      /// @brief Converts this font_family to a human-readable string representation.
      /// @return The string that represents this font_family.
      std::string to_string() const {
        //return strings::format("[{}: ]", strings::class_name(*this));
        return strings::format("[{}: name={}, size={}, units={}, gdi_char_set={}, gdi_vertical_font={}]", strings::class_name(*this), this->data_->font_family_.name(), this->data_->size_, (int32_t)this->data_->unit_, this->data_->gdi_char_set_, this->data_->gdi_vertical_font_);
      }
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::font& font) noexcept {return os << font.to_string();}
      /// @endcond

      /// @brief Gets a value that indicates whether this xtd::drawing::font is bold.
      /// @return true if this xtd::drawing::font is bold; otherwise, false.
      bool bold() const {return (this->data_->style_ & font_style::bold) == font_style::bold;}

      /// @brief Gets the xtd::draing::font_family associated with this xtd::drawing::font.
      /// @return The font_family associated with this Font.
      /// @remarks A font_family represents a group of fonts that have a similar font face, but may have different sizes and styles (for example, Arial, Times New Roman, and Verdana).
      drawing::font_family font_family() const {return this->data_->font_family_;}
      
      /// @brief Gets a byte value that specifies the GDI character set that this xtd::drawing::font uses.
      /// @return A byte value that specifies the GDI character set that this xtd::drawing::font uses. The default is 1.
      /// @remarks This property returns 1, unless a different character set is specified in the font(string, float, font_style, graphics_unit, uint8_t) constructor. This property takes a value from the list defined in the Windows SDK header file WinGDI.h. The character sets and byte values are listed in the following table.
      /// | Character set | alue |
      /// |---------------|------|
      /// | ANSI          | 0    |
      /// | DEFAULT       | 1    |
      /// | SYMBOL        | 2    |
      /// | SHIFTJIS      | 128  |
      /// | HANGEUL       | 129  |
      /// | HANGUL        | 129  |
      /// | GB2312        | 134  |
      /// | CHINESEBIG5   | 136  |
      /// | OEM           | 255  |
      /// | JOHAB         | 130  |
      /// | HEBREW        | 177  |
      /// | ARABIC        | 178  |
      /// | GREEK         | 161  |
      /// | TURKISH       | 162  |
      /// | VIETNAMESE    | 163  |
      /// | THAI          | 222  |
      /// | EASTEUROPE    | 238  |
      /// | RUSSIAN       | 204  |
      /// | MAC           | 77   |
      /// | BALTIC        | 186  |
      uint8_t gdi_char_set() const {return this->data_->gdi_char_set_;}
      
      /// @brief Gets a Boolean value that indicates whether this xtd::drawing::font is derived from a GDI vertical font.
      /// @return true if this xtd::drawing::font is derived from a GDI vertical font; otherwise, false.
      /// @remarks Use this property to determine if a font is compatible with native Win32 controls on non-Unicode platforms.
      /// @remarks gdi_vertical_font only returns true if this font was created from a classic GDI font definition, like a LOGFONT or HFONT.
      bool gdi_vertical_font() const {return this->data_->gdi_vertical_font_;}
      
      /// @brief Gets the window handle that the font is bound to.
      /// @return An intptr_t that contains the window handle (hfont) of the font.
      intptr_t handle() const {return this->data_->handle_;}
      
      /// @brief Gets the line spacing of this font.
      /// @return The line spacing, in pixels, of this font.
      /// @remarks The line spacing is the vertical distance between the base lines of two consecutive lines of text. Thus, the line spacing includes the blank space between lines along with the height of the character itself.
      /// @remarks If the unit property of the font is set to anything other than graphics_unit::pixel, the height (in pixels) is calculated using the vertical resolution of the screen display. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em-height is 2048 and the line spacing is 2355. For a screen display that has a vertical resolution of 96 dots per inch, you can calculate the height as follows:
      /// @remarks 2355*(0.3/2048)*96 = 33.11719
      /// @remarks The value returned by the get_height method would be 33.11719, and the value returned by the height property would be 34. The height property is the value returned by get_height, rounded up to the nearest integer.
      int32_t height() const;
      
      /// @brief Gets a value indicating whether the font is a member of xtd::drawing::system_fonts.
      /// @return true if the font is a member of xtd::drawing::system_fonts; otherwise, false. The default is false.
      /// @remarks When the user changes the system font, the is_system_font property could return true, even if the font is not actually a system font.
      bool is_system_font() const {return this->data_->is_system_font_;}
      
      /// @brief Gets a value that indicates whether this xtd::drawing::font is italic.
      /// @return true if this xtd::drawing::font is italic; otherwise, false.
      bool italic() const {return (this->data_->style_ & font_style::italic) == font_style::italic;}

      /// @brief Gets the face name of this xtd::drawing::font.
      /// @return A string representation of the face name of this xtd::drawing::font.
      const std::string& name() const {return this->data_->font_family_.name();}

      /// @brief Gets the face name of this Font.
      /// @return A string representation of the face name of this Font.
      const std::string& original_font_name() const {return this->data_->original_font_name_;}
      
      /// @brief Gets the em-size of this xtd::drawing::font measured in the units specified by the unit property.
      /// @return The em-size of this xtd::drawing::font.
      float size() const {return this->data_->size_;}
      
      /// @brizef Gets the em-size, in points, of this xtd::drawing::font.
      /// @return The em-size, in points, of this xtd::drawing::font.
      float size_in_points() const;
      
      /// @brief Gets a value that indicates whether this xtd::drawing::font is strikeout.
      /// @return true if this xtd::drawing::font is strikeout; otherwise, false.
      bool strikeout() const {return (this->data_->style_ & font_style::strikeout) == font_style::strikeout;}

      /// @brief Gets style information for this xtd::drawing::font.
      /// @return A font_style enumeration that contains style information for this xtd::drawing::font.
      font_style style() const {return this->data_->style_;}
      
      /// @brief Gets a value that indicates whether this xtd::drawing::font is underline.
      /// @return true if this xtd::drawing::font is underline; otherwise, false.
      bool underline() const {return (this->data_->style_ & font_style::underline) == font_style::underline;}
      
      /// @brief Gets the unit of measure for this xtd::drawing::font.
      /// @return A graphics_unit that represents the unit of measure for this xtd::drawing::font.
      graphics_unit unit() const {return this->data_->unit_;}
      
      static font from_hdc(const intptr_t hdc);
      
      static font from_hfont(const intptr_t hfont);
      
      /// @brief Returns the line spacing, in pixels, of this font.
      /// @return The line spacing, in pixels, of this font.
      /// @remarks The line spacing of a xtd::drawing::font is the vertical distance between the base lines of two consecutive lines of text. Thus, the line spacing includes the blank space between lines along with the height of the character itself.
      /// @remarks If the unit property of the font is set to anything other than graphics_unit::pixel, the height (in pixels) is calculated using the vertical resolution of the screen display. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em-height is 2048 and the line spacing is 2355. For a screen display that has a vertical resolution of 96 dots per inch, you can calculate the height as follows: <br> 2355*(0.3/2048)*96 = 33.11719
      float get_height() const;
      
      /// @brief Returns the line spacing, in the current unit of a specified xtd::drawing::raphics, of this font.
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
      intptr_t to_hfont() const;
      
    private:
      friend class graphics;
      friend class system_fonts;
      friend class xtd::forms::native::font_dialog;
      font() = default;
      font(intptr_t hfont);
      struct data {
        intptr_t handle_ = 0;
        drawing::font_family font_family_;
        uint8_t gdi_char_set_ = 1;
        bool gdi_vertical_font_ = false;
        bool is_system_font_ = false;
        std::string original_font_name_;
        float size_ = 8.25f;
        std::string system_font_name_;
        font_style style_ = font_style::regular;
        graphics_unit unit_ = graphics_unit::point;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
