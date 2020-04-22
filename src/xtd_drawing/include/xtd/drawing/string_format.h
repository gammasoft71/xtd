#pragma once
#include <cstdint>
#include <ostream>
#include <xtd/xtd.strings>
#include "hotkey_prefix.h"
#include "string_alignment.h"
#include "string_format_flags.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Encapsulates text layout information (such as alignment, orientation and tab stops) display manipulations (such as ellipsis insertion and national digit substitution) and OpenType features. This class cannot be inherited.
    /// @remarks Many common formats are provided through the string_format_flags enumeration. string_format objects can be changed.
    class string_format final {
    public:
      string_format() = default;
      
      string_format(const xtd::drawing::string_format&) = default;
      
      /// @brief Gets a generic default StringFormat object.
      /// @return The generic default StringFormat object.
      /// @remarks The following table shows initial property values for a generic default instance of the StringFormat class.
      /// | property       | initial value |
      /// |----------------|---------------|
      /// | format_flag    | 0             |
      /// | alignment      | near          |
      /// | line_alignment | near          |
      static xtd::drawing::string_format generic_default() {return xtd::drawing::string_format();}
      
      /// @brief Gets horizontal alignment of the string.
      /// @return A string_alignment enumeration that specifies the horizontal alignment of the string.
      /// @remarks Use line_alignment to specify the vertical alignment of the string.
      xtd::drawing::string_alignment alignment() const {return this->alignment_;}
      /// @brief Sets horizontal alignment of the string.
      /// @param alignment A string_alignment enumeration that specifies the horizontal alignment of the string.
      /// @remarks Use line_alignment to specify the vertical alignment of the string.
      xtd::drawing::string_format& alignment(xtd::drawing::string_alignment alignment) {
        this->alignment_ = alignment;
        return *this;
      }

      /// @brief Gets a StringFormatFlags enumeration that contains formatting information.
      /// @return A StringFormatFlags enumeration that contains formatting information.
      xtd::drawing::string_format_flags format_flags() const {return format_flags_;}
      /// @brief Sets a StringFormatFlags enumeration that contains formatting information.
      /// @param format_flag A StringFormatFlags enumeration that contains formatting information.
      xtd::drawing::string_format& format_flags(xtd::drawing::string_format_flags format_flag) {
        format_flags_ = format_flag;
        return *this;
      }
      
      /// @brief Gets the HotkeyPrefix object for this StringFormat object.
      /// @return The hotkey_prefix object for this string_format object, the default is hotkey_prefix::none.
      /// @remarks In a graphical user interface, a hot key is the underlined letter in a word (usually combined with another key, such as the Alt key) that you can press on the keyboard to activate the functionality that the word represents.
      xtd::drawing::hotkey_prefix hotkey_prefix() const {return hotkey_prefix_;}
      /// @brief Sets the HotkeyPrefix object for this StringFormat object.
      /// @param hotkey_prefix The hotkey_prefix object for this string_format object, the default is hotkey_prefix::none.
      /// @remarks In a graphical user interface, a hot key is the underlined letter in a word (usually combined with another key, such as the Alt key) that you can press on the keyboard to activate the functionality that the word represents.
      xtd::drawing::string_format&  hotkey_prefix(xtd::drawing::hotkey_prefix hotkey_prefix) {
        hotkey_prefix_ = hotkey_prefix;
        return *this;
      }

      /// @brief Gets vertical alignment of the string.
      /// @return A string_alignment enumeration that specifies the vertical alignment of the string.
      /// @remarks Use alignment to specify the horizontal alignment of the string.
      xtd::drawing::string_alignment line_alignment() const {return this->line_alignment_;}
      /// @brief Sets vertical alignment of the string.
      /// @param alignment A string_alignment enumeration that specifies the vertical alignment of the string.
      /// @remarks Use alignment to specify the horizontal alignment of the string.
      xtd::drawing::string_format& line_alignment(xtd::drawing::string_alignment line_alignment) {
        this->line_alignment_ = line_alignment;
        return *this;
      }

    private:
      xtd::drawing::hotkey_prefix hotkey_prefix_ = xtd::drawing::hotkey_prefix::none;
      xtd::drawing::string_format_flags format_flags_ = static_cast<xtd::drawing::string_format_flags>(0);
      xtd::drawing::string_alignment alignment_ = xtd::drawing::string_alignment::near;
      xtd::drawing::string_alignment line_alignment_ = xtd::drawing::string_alignment::near;
    };
  }
}
