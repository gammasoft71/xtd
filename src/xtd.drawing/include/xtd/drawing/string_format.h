/// @file
/// @brief Contains xtd::drawing::string_format class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "text/hotkey_prefix.h"
#include "string_alignment.h"
#include "string_format_flags.h"
#include "string_trimming.h"
#include <xtd/object>
#include <cstdint>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Encapsulates text layout information (such as alignment, orientation and tab stops) display manipulations (such as ellipsis insertion and national digit substitution) and OpenType features. This class cannot be inherited.
    /// @code
    /// class drawing_export_ string_format final : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::string_dormat
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing texts
    /// @remarks Many common formats are provided through the string_format_flags enumeration. string_format objects can be changed.
    class drawing_export_ string_format final : public xtd::object {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new string_format object.
      /// @remarks The following table shows initial property values for an instance of string_format class.
      /// | property       | initial value |
      /// | -------------- | ------------- |
      /// | format_flag    | 0             |
      /// | hotkey_prefix  | none          |
      string_format() = default;
      /// @brief Initializes a new string_format object from the specified existing string_format object.
      /// @param format The string_format object from which to initialize the new string_format object.
      string_format(const xtd::drawing::string_format& format) = default;
      /// @brief Initializes a new string_format object with the specified string_format_flags enumeration.
      /// @param options The StringFormatFlags enumeration for the new StringFormat object.
      explicit string_format(xtd::drawing::string_format_flags options);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets horizontal alignment of the string.
      /// @return A string_alignment enumeration that specifies the horizontal alignment of the string.
      /// @remarks Use line_alignment to specify the vertical alignment of the string.
      xtd::drawing::string_alignment alignment() const noexcept;
      /// @brief Sets horizontal alignment of the string.
      /// @param alignment A string_alignment enumeration that specifies the horizontal alignment of the string.
      /// @remarks Use line_alignment to specify the vertical alignment of the string.
      xtd::drawing::string_format& alignment(xtd::drawing::string_alignment alignment) noexcept;
      
      /// @brief Gets a string_formatFlags enumeration that contains formatting information.
      /// @return A string_formatFlags enumeration that contains formatting information.
      xtd::drawing::string_format_flags format_flags() const noexcept;
      /// @brief Sets a string_formatFlags enumeration that contains formatting information.
      /// @param format_flag A string_formatFlags enumeration that contains formatting information.
      xtd::drawing::string_format& format_flags(xtd::drawing::string_format_flags format_flag) noexcept;
      
      /// @brief Gets the HotkeyPrefix object for this string_format object.
      /// @return The hotkey_prefix object for this string_format object, the default is hotkey_prefix::none.
      /// @remarks In a graphical user interface, a hot key is the underlined letter in a word (usually combined with another key, such as the Alt key) that you can press on the keyboard to activate the functionality that the word represents.
      xtd::drawing::text::hotkey_prefix hotkey_prefix() const noexcept;
      /// @brief Sets the HotkeyPrefix object for this string_format object.
      /// @param hotkey_prefix The hotkey_prefix object for this string_format object, the default is hotkey_prefix::none.
      /// @remarks In a graphical user interface, a hot key is the underlined letter in a word (usually combined with another key, such as the Alt key) that you can press on the keyboard to activate the functionality that the word represents.
      xtd::drawing::string_format& hotkey_prefix(xtd::drawing::text::hotkey_prefix hotkey_prefix) noexcept;
      
      /// @brief Gets vertical alignment of the string.
      /// @return A string_alignment enumeration that specifies the vertical alignment of the string.
      /// @remarks Use alignment to specify the horizontal alignment of the string.
      xtd::drawing::string_alignment line_alignment() const noexcept;
      /// @brief Sets vertical alignment of the string.
      /// @param alignment A string_alignment enumeration that specifies the vertical alignment of the string.
      /// @remarks Use alignment to specify the horizontal alignment of the string.
      xtd::drawing::string_format& line_alignment(xtd::drawing::string_alignment line_alignment) noexcept;
      
      /// @brief Gets the string_trimming enumeration for this string_format object.
      /// @return A string_trimming enumeration that indicates how text drawn with this string_format object is trimmed when it exceeds the edges of the layout rectangle.
      xtd::drawing::string_trimming trimming() const noexcept;
      /// @brief Sets the string_trimming enumeration for this string_format object.
      /// @param trimming A string_trimming enumeration that indicates how text drawn with this string_format object is trimmed when it exceeds the edges of the layout rectangle.
      xtd::drawing::string_format& trimming(xtd::drawing::string_trimming trimming) noexcept;
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets a generic default string_format object.
      /// @return The generic default string_format object.
      /// @remarks The following table shows initial property values for a generic default instance of the string_format class.
      /// | property       | initial value |
      /// | -------------- | ------------- |
      /// | format_flag    | 0             |
      /// | alignment      | near          |
      /// | line_alignment | near          |
      /// | hotkey_prefix  | none          |
      /// | trimming       | character     |
      static xtd::drawing::string_format generic_default() noexcept;
      
      /// @brief Gets a generic typographic string_format object.
      /// @return A generic typographic string_format object.
      /// @remarks The following table shows initial property values for a generic default instance of the string_format class.
      /// | property       | initial value                                          |
      /// | -------------- | ------------------------------------------------------ |
      /// | format_flag    | 0b110000000000100 (no_clip\|fit_black_box\|line_limit) |
      /// | alignment      | near                                                   |
      /// | line_alignment | near                                                   |
      /// | hotkey_prefix  | none                                                   |
      /// | trimming       | none                                                   |
      static xtd::drawing::string_format generic_typographic() noexcept;
      /// @}

    private:
      xtd::drawing::text::hotkey_prefix hotkey_prefix_ = xtd::drawing::text::hotkey_prefix::none;
      xtd::drawing::string_format_flags format_flags_ = static_cast<xtd::drawing::string_format_flags>(0);
      xtd::drawing::string_alignment alignment_ = xtd::drawing::string_alignment::near;
      xtd::drawing::string_alignment line_alignment_ = xtd::drawing::string_alignment::near;
      xtd::drawing::string_trimming trimming_ = xtd::drawing::string_trimming::none;
    };
  }
}
