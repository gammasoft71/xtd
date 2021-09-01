/// @file
/// @brief Contains xtd::drawing::drawing2d::hatch_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Specifies the different patterns available for xtd::drawing::drawing2d::hatch_brush objects.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class hatch_style {
        /// @brief A pattern of horizontal lines.
        horizontal = 0,
        /// @brief A pattern of vertical lines.
        vertical = 1,
        /// @brief A pattern of lines on a diagonal from upper left to lower right.
        forward_diagonal = 2,
        /// @brief A pattern of lines on a diagonal from upper right to lower left.
        backward_diagonal = 3,
        /// @brief Specifies horizontal and vertical lines that cross.
        cross = 4,
        /// @brief A pattern of crisscross diagonal lines.
        diagonal_cross = 5,
        /// @brief Specifies a 5-percent hatch. The ratio of foreground color to background color is 5:95.
        percent_05 = 6,
        /// @brief Specifies a 10-percent hatch. The ratio of foreground color to background color is 10:90.
        percent_10 = 7,
        /// @brief Specifies a 20-percent hatch. The ratio of foreground color to background color is 20:80.
        percent_20 = 8,
        /// @brief Specifies a 25-percent hatch. The ratio of foreground color to background color is 25:75.
        percent_25 = 9,
        /// @brief Specifies a 30-percent hatch. The ratio of foreground color to background color is 30:70.
        percent_30 = 10,
        /// @brief Specifies a 40-percent hatch. The ratio of foreground color to background color is 40:60.
        percent_40 = 11,
        /// @brief Specifies a 50-percent hatch. The ratio of foreground color to background color is 50:50.
        percent_50 = 12,
        /// @brief Specifies a 60-percent hatch. The ratio of foreground color to background color is 60:40.
        percent_60 = 13,
        /// @brief Specifies a 70-percent hatch. The ratio of foreground color to background color is 70:30.
        percent_70 = 14,
        /// @brief Specifies a 75-percent hatch. The ratio of foreground color to background color is 75:25.
        percent_75 = 15,
        /// @brief Specifies a 80-percent hatch. The ratio of foreground color to background color is 80:20.
        percent_80 = 16,
        /// @brief Specifies a 90-percent hatch. The ratio of foreground color to background color is 90:10.
        percent_90 = 17,
        /// @brief Specifies diagonal lines that slant to the right from top points to bottom points and are spaced 50 percent closer together than forward_diagonal, but are not antialiased.
        light_downward_diagonal = 18,
        /// @brief Specifies diagonal lines that slant to the left from top points to bottom points and are spaced 50 percent closer together than backward_diagonal, but they are not antialiased.
        light_upward_diagonal = 19,
        /// @brief Specifies diagonal lines that slant to the right from top points to bottom points, are spaced 50 percent closer together than, and are twice the width of forward_diagonal. This hatch pattern is not antialiased.
        dark_downward_diagonal = 20,
        /// @brief Specifies diagonal lines that slant to the left from top points to bottom points, are spaced 50 percent closer together than backward_diagonal, and are twice its width, but the lines are not antialiased.
        dark_upward_diagonal = 21,
        /// @brief Specifies diagonal lines that slant to the right from top points to bottom points, have the same spacing as hatch style forward_diagonal, and are triple its width, but are not antialiased.
        wide_downward_diagonal = 22,
        /// @brief Specifies diagonal lines that slant to the left from top points to bottom points, have the same spacing as hatch style backward_diagonal, and are triple its width, but are not antialiased.
        wide_upward_diagonal = 23,
        /// @brief Specifies vertical lines that are spaced 50 percent closer together than vertical.
        light_vertical = 24,
        /// @brief Specifies horizontal lines that are spaced 50 percent closer together than horizontal.
        light_horizontal = 25,
        /// @brief Specifies vertical lines that are spaced 75 percent closer together than hatch style vertical (or 25 percent closer together than light_vertical).
        narrow_vertical = 26,
        /// @brief Specifies horizontal lines that are spaced 75 percent closer together than hatch style horizontal (or 25 percent closer together than light_horizontal).
        narrow_horizontal = 27,
        /// @brief Specifies vertical lines that are spaced 50 percent closer together than vertical and are twice its width.
        dark_vertical = 28,
        /// @brief Specifies horizontal lines that are spaced 50 percent closer together than horizontal and are twice the width of horizontal.
        dark_horizontal = 29,
        /// @brief Specifies dashed diagonal lines, that slant to the right from top points to bottom points.
        dashed_downward_diagonal = 30,
        /// @brief Specifies dashed diagonal lines, that slant to the left from top points to bottom points.
        dashed_upward_diagonal = 31,
        /// @brief Specifies dashed horizontal lines.
        dashed_horizontal = 32,
        /// @brief Specifies dashed vertical lines.
        dashed_vertical = 33,
        /// @brief Specifies a hatch that has the appearance of confetti.
        small_confetti = 34,
        /// @brief Specifies a hatch that has the appearance of confetti, and is composed of larger pieces than small_confetti.
        large_confetti = 35,
        /// @brief Specifies horizontal lines that are composed of zigzags.
        zig_zag = 36,
        /// @brief Specifies horizontal lines that are composed of tildes.
        wave = 37,
        /// @brief Specifies a hatch that has the appearance of layered bricks that slant to the left from top points to bottom points.
        diagonal_brick = 38,
        /// @brief Specifies a hatch that has the appearance of horizontally layered bricks.
        horizontal_brick = 39,
        /// @brief Specifies a hatch that has the appearance of a woven material.
        weave = 40,
        /// @brief Specifies a hatch that has the appearance of a plaid material.
        plaid = 41,
        /// @brief Specifies a hatch that has the appearance of divots.
        divot = 42,
        /// @brief Specifies horizontal and vertical lines, each of which is composed of dots, that cross.
        dotted_grid = 43,
        /// @brief Specifies forward diagonal and backward diagonal lines, each of which is composed of dots, that cross.
        dotted_diamond = 44,
        /// @brief Specifies a hatch that has the appearance of diagonally layered shingles that slant to the right from top points to bottom points.
        shingle = 45,
        /// @brief Specifies a hatch that has the appearance of a trellis.
        trellis = 46,
        /// @brief Specifies a hatch that has the appearance of spheres laid adjacent to one another.
        sphere = 47,
        /// @brief Specifies horizontal and vertical lines that cross and are spaced 50 percent closer together than hatch style cross.
        small_grid = 48,
        /// @brief Specifies a hatch that has the appearance of a checkerboard.
        small_checker_board = 49,
        /// @brief Specifies a hatch that has the appearance of a checkerboard with squares that are twice the size of small_checker_board.
        large_checker_board = 50,
        /// @brief Specifies forward diagonal and backward diagonal lines that cross but are not antialiased.
        outlined_diamond = 51,
        /// @brief Specifies a hatch that has the appearance of a checkerboard placed diagonally.
        solid_diamond = 52,
      };

      /// @cond
      inline std::ostream& operator<<(std::ostream& os, hatch_style value) {return os << to_string(value, {{hatch_style::horizontal, "horizontal"}, {hatch_style::vertical, "vertical"}, {hatch_style::forward_diagonal, "forward_diagonal"}, {hatch_style::backward_diagonal, "backward_diagonal"}, {hatch_style::cross, "cross"}, {hatch_style::diagonal_cross, "diagonal_cross"}, {hatch_style::percent_05, "percent_05"}, {hatch_style::percent_10, "percent_10"}, {hatch_style::percent_20, "percent_20"}, {hatch_style::percent_25, "percent_25"}, {hatch_style::percent_30, "percent_30"}, {hatch_style::percent_40, "percent_40"}, {hatch_style::percent_50, "percent_50"}, {hatch_style::percent_60, "percent_60"}, {hatch_style::percent_70, "percent_70"}, {hatch_style::percent_75, "percent_75"}, {hatch_style::percent_80, "percent_80"}, {hatch_style::percent_90, "percent_90"}, {hatch_style::light_downward_diagonal, "light_downward_diagonal"}, {hatch_style::light_upward_diagonal, "light_upward_diagonal"}, {hatch_style::dark_downward_diagonal, "dark_downward_diagonal"}, {hatch_style::dark_upward_diagonal, "dark_upward_diagonal"}, {hatch_style::wide_downward_diagonal, "wide_downward_diagonal"}, {hatch_style::wide_upward_diagonal, "wide_upward_diagonal"}, {hatch_style::light_vertical, "light_vertical"}, {hatch_style::light_horizontal, "light_horizontal"}, {hatch_style::narrow_vertical, "narrow_vertical"}, {hatch_style::narrow_horizontal, "narrow_horizontal"}, {hatch_style::dark_vertical, "dark_vertical"}, {hatch_style::dark_horizontal, "dark_horizontal"}, {hatch_style::dashed_downward_diagonal, "dashed_downward_diagonal"}, {hatch_style::dashed_upward_diagonal, "dashed_upward_diagonal"}, {hatch_style::dashed_horizontal, "dashed_horizontal"}, {hatch_style::dashed_vertical, "dashed_vertical"}, {hatch_style::small_confetti, "small_confetti"}, {hatch_style::large_confetti, "large_confetti"}, {hatch_style::zig_zag, "zig_zag"}, {hatch_style::wave, "wave"}, {hatch_style::diagonal_brick, "diagonal_brick"}, {hatch_style::horizontal_brick, "horizontal_brick"}, {hatch_style::weave, "weave"}, {hatch_style::plaid, "plaid"}, {hatch_style::divot, "divot"}, {hatch_style::dotted_grid, "dotted_grid"}, {hatch_style::dotted_diamond, "dotted_diamond"}, {hatch_style::shingle, "shingle"}, {hatch_style::trellis, "trellis"}, {hatch_style::sphere, "sphere"}, {hatch_style::small_grid, "small_grid"}, {hatch_style::small_checker_board, "small_checker_board"}, {hatch_style::large_checker_board, "large_checker_board"}, {hatch_style::outlined_diamond, "outlined_diamond"}, {hatch_style::solid_diamond, "solid_diamond"}});}
      inline std::wostream& operator<<(std::wostream& os, hatch_style value) {return os << to_string(value, {{hatch_style::horizontal, L"horizontal"}, {hatch_style::vertical, L"vertical"}, {hatch_style::forward_diagonal, L"forward_diagonal"}, {hatch_style::backward_diagonal, L"backward_diagonal"}, {hatch_style::cross, L"cross"}, {hatch_style::diagonal_cross, L"diagonal_cross"}, {hatch_style::percent_05, L"percent_05"}, {hatch_style::percent_10, L"percent_10"}, {hatch_style::percent_20, L"percent_20"}, {hatch_style::percent_25, L"percent_25"}, {hatch_style::percent_30, L"percent_30"}, {hatch_style::percent_40, L"percent_40"}, {hatch_style::percent_50, L"percent_50"}, {hatch_style::percent_60, L"percent_60"}, {hatch_style::percent_70, L"percent_70"}, {hatch_style::percent_75, L"percent_75"}, {hatch_style::percent_80, L"percent_80"}, {hatch_style::percent_90, L"percent_90"}, {hatch_style::light_downward_diagonal, L"light_downward_diagonal"}, {hatch_style::light_upward_diagonal, L"light_upward_diagonal"}, {hatch_style::dark_downward_diagonal, L"dark_downward_diagonal"}, {hatch_style::dark_upward_diagonal, L"dark_upward_diagonal"}, {hatch_style::wide_downward_diagonal, L"wide_downward_diagonal"}, {hatch_style::wide_upward_diagonal, L"wide_upward_diagonal"}, {hatch_style::light_vertical, L"light_vertical"}, {hatch_style::light_horizontal, L"light_horizontal"}, {hatch_style::narrow_vertical, L"narrow_vertical"}, {hatch_style::narrow_horizontal, L"narrow_horizontal"}, {hatch_style::dark_vertical, L"dark_vertical"}, {hatch_style::dark_horizontal, L"dark_horizontal"}, {hatch_style::dashed_downward_diagonal, L"dashed_downward_diagonal"}, {hatch_style::dashed_upward_diagonal, L"dashed_upward_diagonal"}, {hatch_style::dashed_horizontal, L"dashed_horizontal"}, {hatch_style::dashed_vertical, L"dashed_vertical"}, {hatch_style::small_confetti, L"small_confetti"}, {hatch_style::large_confetti, L"large_confetti"}, {hatch_style::zig_zag, L"zig_zag"}, {hatch_style::wave, L"wave"}, {hatch_style::diagonal_brick, L"diagonal_brick"}, {hatch_style::horizontal_brick, L"horizontal_brick"}, {hatch_style::weave, L"weave"}, {hatch_style::plaid, L"plaid"}, {hatch_style::divot, L"divot"}, {hatch_style::dotted_grid, L"dotted_grid"}, {hatch_style::dotted_diamond, L"dotted_diamond"}, {hatch_style::shingle, L"shingle"}, {hatch_style::trellis, L"trellis"}, {hatch_style::sphere, L"sphere"}, {hatch_style::small_grid, L"small_grid"}, {hatch_style::small_checker_board, L"small_checker_board"}, {hatch_style::large_checker_board, L"large_checker_board"}, {hatch_style::outlined_diamond, L"outlined_diamond"}, {hatch_style::solid_diamond, L"solid_diamond"}});}
      /// @endcond
    }
  }
}
