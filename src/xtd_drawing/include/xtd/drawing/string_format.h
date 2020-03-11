#pragma once
#include <cstdint>
#include <ostream>
#include <xtd/xtd.strings>
#include "string_alignment.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Encapsulates text layout information (such as alignment, orientation and tab stops) display manipulations (such as ellipsis insertion and national digit substitution) and OpenType features. This class cannot be inherited.
    /// @remarks Many common formats are provided through the string_format_flags enumeration. string_format objects can be changed.
    class string_format final {
      
      /// @brief Gets horizontal alignment of the string.
      /// @return A string_alignment enumeration that specifies the horizontal alignment of the string.
      /// @remarks Use line_alignment to specify the vertical alignment of the string.
      string_alignment alignment() const {return this->alignment_;}
      
      /// @brief Sets horizontal alignment of the string.
      /// @param alignment A string_alignment enumeration that specifies the horizontal alignment of the string.
      /// @remarks Use line_alignment to specify the vertical alignment of the string.
      void alignment(string_alignment alignment) {this->alignment_ = alignment;}
      
      /// @brief Gets vertical alignment of the string.
      /// @return A string_alignment enumeration that specifies the vertical alignment of the string.
      /// @remarks Use alignment to specify the horizontal alignment of the string.
      string_alignment line_alignment() const {return this->line_alignment_;}
      
      /// @brief Sets vertical alignment of the string.
      /// @param alignment A string_alignment enumeration that specifies the vertical alignment of the string.
      /// @remarks Use alignment to specify the horizontal alignment of the string.
      void line_alignment(string_alignment line_alignment) {this->line_alignment_ = line_alignment;}

    private:
      string_alignment alignment_ = string_alignment::near;
      string_alignment line_alignment_ = string_alignment::near;
    };
  }
}
