/// @file
/// @brief Contains xtd::drawing::string_trimming enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies how to trim characters from a string that does not completely fit into a layout shape.
    /// @par Namespace
    /// xtd::drawing
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
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::string_trimming> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::string_trimming> {{xtd::drawing::string_trimming::none, "none"}, {xtd::drawing::string_trimming::character, "character"}, {xtd::drawing::string_trimming::word, "word"}, {xtd::drawing::string_trimming::ellipsis_character, "ellipsis_character"}, {xtd::drawing::string_trimming::ellipsis_word, "ellipsis_word"}, {xtd::drawing::string_trimming::ellipsis_path, "ellipsis_path"}};}
};
/// @endcond
