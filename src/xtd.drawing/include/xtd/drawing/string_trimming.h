/// @file
/// @brief Contains xtd::drawing::string_trimming enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies how to trim characters from a string that does not completely fit into a layout shape.
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    enum class string_trimming {
      /// @brief Specifies no trimming.
      none = 0,
      /// @brief Specifies that the text is trimmed to the nearest character.
      character = 1,
      /// @brief Specifies that text is trimmed to the nearest word.
      word = 2,
      /// @brief Specifies that the text is trimmed to the nearest character, and an ellipsis is inserted at the end of a trimmed line.
      ellipsis_character = 3,
      /// @brief Specifies that text is trimmed to the nearest word, and an ellipsis is inserted at the end of a trimmed line.
      ellipsis_word = 4,
      /// @brief The center is removed from trimmed lines and replaced by an ellipsis. The algorithm keeps as much of the last slash-delimited segment of the line as possible.
      ellipsis_path = 5,
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, string_trimming value) {return os << xtd::to_string(value, {{string_trimming::none, "none"}, {string_trimming::character, "character"}, {string_trimming::word, "word"}, {string_trimming::ellipsis_character, "ellipsis_character"}, {string_trimming::ellipsis_word, "ellipsis_word"}, {string_trimming::ellipsis_path, "ellipsis_path"}});}
    inline std::wostream& operator<<(std::wostream& os, string_trimming value) {return os << xtd::to_string(value, {{string_trimming::none, L"none"}, {string_trimming::character, L"character"}, {string_trimming::word, L"word"}, {string_trimming::ellipsis_character, L"ellipsis_character"}, {string_trimming::ellipsis_word, L"ellipsis_word"}, {string_trimming::ellipsis_path, L"ellipsis_path"}});}
    /// @endcond
  }
}
