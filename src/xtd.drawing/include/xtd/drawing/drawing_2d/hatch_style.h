/// @file
/// @brief Contains xtd::drawing::drawing_2d::hatch_style enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "drawing2d.h"
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d/ namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Specifies the different patterns available for xtd::drawing::drawing_2d::hatch_brush objects.
      /// @par Namespace
      /// xtd::drawing::drawing_2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class hatch_style {
        /// @brief A pattern of horizontal lines.
        /// @image html hatch_brush_horizontal.png
        horizontal = 0,
        /// @brief A pattern of vertical lines.
        /// @image html hatch_brush_vertical.png
        vertical = 1,
        /// @brief A pattern of lines on a diagonal from upper left to lower right.
        /// @image html hatch_brush_forward_diagonal.png
        forward_diagonal = 2,
        /// @brief A pattern of lines on a diagonal from upper right to lower left.
        /// @image html hatch_brush_backward_diagonal.png
        backward_diagonal = 3,
        /// @brief Specifies horizontal and vertical lines that cross.
        /// @image html hatch_brush_cross.png
        cross = 4,
        /// @brief A pattern of crisscross diagonal lines.
        /// @image html hatch_brush_diagonal_cross.png
        diagonal_cross = 5,
        /// @brief Specifies a 5-percent hatch. The ratio of foreground color to background color is 5:95.
        /// @image html hatch_brush_percent_05.png
        percent_05 = 6,
        /// @brief Specifies a 10-percent hatch. The ratio of foreground color to background color is 10:90.
        /// @image html hatch_brush_percent_10.png
        percent_10 = 7,
        /// @brief Specifies a 20-percent hatch. The ratio of foreground color to background color is 20:80.
        /// @image html hatch_brush_percent_20.png
        percent_20 = 8,
        /// @brief Specifies a 25-percent hatch. The ratio of foreground color to background color is 25:75.
        /// @image html hatch_brush_percent_25.png
        percent_25 = 9,
        /// @brief Specifies a 30-percent hatch. The ratio of foreground color to background color is 30:70.
        /// @image html hatch_brush_percent_30.png
        percent_30 = 10,
        /// @brief Specifies a 40-percent hatch. The ratio of foreground color to background color is 40:60.
        /// @image html hatch_brush_percent_40.png
        percent_40 = 11,
        /// @brief Specifies a 50-percent hatch. The ratio of foreground color to background color is 50:50.
        /// @image html hatch_brush_percent_50.png
        percent_50 = 12,
        /// @brief Specifies a 60-percent hatch. The ratio of foreground color to background color is 60:40.
        /// @image html hatch_brush_percent_60.png
        percent_60 = 13,
        /// @brief Specifies a 70-percent hatch. The ratio of foreground color to background color is 70:30.
        /// @image html hatch_brush_percent_70.png
        percent_70 = 14,
        /// @brief Specifies a 75-percent hatch. The ratio of foreground color to background color is 75:25.
        /// @image html hatch_brush_percent_75.png
        percent_75 = 15,
        /// @brief Specifies a 80-percent hatch. The ratio of foreground color to background color is 80:20.
        /// @image html hatch_brush_percent_80.png
        percent_80 = 16,
        /// @brief Specifies a 90-percent hatch. The ratio of foreground color to background color is 90:10.
        /// @image html hatch_brush_percent_90.png
        percent_90 = 17,
        /// @brief Specifies diagonal lines that slant to the right from top points to bottom points and are spaced 50 percent closer together than xtd::drawing::drawing_2d::hatch_style::forward_diagonal, but are not antialiased.
        /// @image html hatch_brush_light_downward_diagonal.png
        light_downward_diagonal = 18,
        /// @brief Specifies diagonal lines that slant to the left from top points to bottom points and are spaced 50 percent closer together than xtd::drawing::drawing_2d::hatch_style::backward_diagonal, but they are not antialiased.
        /// @image html hatch_brush_light_upward_diagonal.png
        light_upward_diagonal = 19,
        /// @brief Specifies diagonal lines that slant to the right from top points to bottom points, are spaced 50 percent closer together than, and are twice the width of xtd::drawing::drawing_2d::hatch_style::forward_diagonal. This hatch pattern is not antialiased.
        /// @image html hatch_brush_dark_downward_diagonal.png
        dark_downward_diagonal = 20,
        /// @brief Specifies diagonal lines that slant to the left from top points to bottom points, are spaced 50 percent closer together than xtd::drawing::drawing_2d::hatch_style::backward_diagonal, and are twice its width, but the lines are not antialiased.
        /// @image html hatch_brush_dark_upward_diagonal.png
        dark_upward_diagonal = 21,
        /// @brief Specifies diagonal lines that slant to the right from top points to bottom points, have the same spacing as hatch style xtd::drawing::drawing_2d::hatch_style::forward_diagonal, and are triple its width, but are not antialiased.
        /// @image html hatch_brush_wide_downward_diagonal.png
        wide_downward_diagonal = 22,
        /// @brief Specifies diagonal lines that slant to the left from top points to bottom points, have the same spacing as hatch style xtd::drawing::drawing_2d::hatch_style::backward_diagonal, and are triple its width, but are not antialiased.
        /// @image html hatch_brush_wide_upward_diagonal.png
        wide_upward_diagonal = 23,
        /// @brief Specifies vertical lines that are spaced 50 percent closer together than xtd::drawing::drawing_2d::hatch_style::vertical.
        /// @image html hatch_brush_light_vertical.png
        light_vertical = 24,
        /// @brief Specifies horizontal lines that are spaced 50 percent closer together than xtd::drawing::drawing_2d::hatch_style::horizontal.
        /// @image html hatch_brush_light_horizontal.png
        light_horizontal = 25,
        /// @brief Specifies vertical lines that are spaced 75 percent closer together than hatch style xtd::drawing::drawing_2d::hatch_style::vertical (or 25 percent closer together than xtd::drawing::drawing_2d::hatch_style::light_vertical).
        /// @image html hatch_brush_narrow_vertical.png
        narrow_vertical = 26,
        /// @brief Specifies horizontal lines that are spaced 75 percent closer together than hatch style xtd::drawing::drawing_2d::hatch_style::horizontal (or 25 percent closer together than xtd::drawing::drawing_2d::hatch_style::light_horizontal).
        /// @image html hatch_brush_narrow_horizontal.png
        narrow_horizontal = 27,
        /// @brief Specifies vertical lines that are spaced 50 percent closer together than xtd::drawing::drawing_2d::hatch_style::vertical and are twice its width.
        /// @image html hatch_brush_dark_vertical.png
        dark_vertical = 28,
        /// @brief Specifies horizontal lines that are spaced 50 percent closer together than xtd::drawing::drawing_2d::hatch_style::horizontal and are twice the width of horizontal.
        /// @image html hatch_brush_dark_horizontal.png
        dark_horizontal = 29,
        /// @brief Specifies dashed diagonal lines, that slant to the right from top points to bottom points.
        /// @image html hatch_brush_dashed_downward_diagonal.png
        dashed_downward_diagonal = 30,
        /// @brief Specifies dashed diagonal lines, that slant to the left from top points to bottom points.
        /// @image html hatch_brush_dashed_upward_diagonal.png
        dashed_upward_diagonal = 31,
        /// @brief Specifies dashed horizontal lines.
        /// @image html hatch_brush_dashed_horizontal.png
        dashed_horizontal = 32,
        /// @brief Specifies dashed vertical lines.
        /// @image html hatch_brush_dashed_vertical.png
        dashed_vertical = 33,
        /// @brief Specifies a hatch that has the appearance of confetti.
        /// @image html hatch_brush_small_confetti.png
        small_confetti = 34,
        /// @brief Specifies a hatch that has the appearance of confetti, and is composed of larger pieces than xtd::drawing::drawing_2d::hatch_style::small_confetti.
        /// @image html hatch_brush_large_confetti.png
        large_confetti = 35,
        /// @brief Specifies horizontal lines that are composed of zigzags.
        /// @image html hatch_brush_zig_zag.png
        zig_zag = 36,
        /// @brief Specifies horizontal lines that are composed of tildes.
        /// @image html hatch_brush_wave.png
        wave = 37,
        /// @brief Specifies a hatch that has the appearance of layered bricks that slant to the left from top points to bottom points.
        /// @image html hatch_brush_diagonal_brick.png
        diagonal_brick = 38,
        /// @brief Specifies a hatch that has the appearance of horizontally layered bricks.
        /// @image html hatch_brush_horizontal_brick.png
        horizontal_brick = 39,
        /// @brief Specifies a hatch that has the appearance of a woven material.
        /// @image html hatch_brush_weave.png
        weave = 40,
        /// @brief Specifies a hatch that has the appearance of a plaid material.
        /// @image html hatch_brush_plaid.png
        plaid = 41,
        /// @brief Specifies a hatch that has the appearance of divots.
        /// @image html hatch_brush_divot.png
        divot = 42,
        /// @brief Specifies horizontal and vertical lines, each of which is composed of dots, that cross.
        /// @image html hatch_brush_dotted_grid.png
        dotted_grid = 43,
        /// @brief Specifies forward diagonal and backward diagonal lines, each of which is composed of dots, that cross.
        /// @image html hatch_brush_dotted_diamond.png
        dotted_diamond = 44,
        /// @brief Specifies a hatch that has the appearance of diagonally layered shingles that slant to the right from top points to bottom points.
        /// @image html hatch_brush_shingle.png
        shingle = 45,
        /// @brief Specifies a hatch that has the appearance of a trellis.
        /// @image html hatch_brush_trellis.png
        trellis = 46,
        /// @brief Specifies a hatch that has the appearance of spheres laid adjacent to one another.
        /// @image html hatch_brush_sphere.png
        sphere = 47,
        /// @brief Specifies horizontal and vertical lines that cross and are spaced 50 percent closer together than hatch style xtd::drawing::drawing_2d::hatch_style::cross.
        /// @image html hatch_brush_small_grid.png
        small_grid = 48,
        /// @brief Specifies a hatch that has the appearance of a checkerboard.
        /// @image html hatch_brush_small_checker_board.png
        small_checker_board = 49,
        /// @brief Specifies a hatch that has the appearance of a checkerboard with squares that are twice the size of xtd::drawing::drawing_2d::hatch_style::small_checker_board.
        /// @image html hatch_brush_large_checker_board.png
        large_checker_board = 50,
        /// @brief Specifies forward diagonal and backward diagonal lines that cross but are not antialiased.
        /// @image html hatch_brush_outlined_diamond.png
        outlined_diamond = 51,
        /// @brief Specifies a hatch that has the appearance of a checkerboard placed diagonally.
        /// @image html hatch_brush_solid_diamond.png
        solid_diamond = 52,
        /// @brief Specifies a hatch that has the appearance of a checkerboard with squares that are twice the size of xtd::drawing::drawing_2d::hatch_style::large_checker_board and Four times the size of xtd::drawing::drawing_2d::hatch_style::small_checker_board.
        /// @image html hatch_brush_wide_checker_board.png
        wide_checker_board = 53,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing_2d::hatch_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::drawing_2d::hatch_style> {{xtd::drawing::drawing_2d::hatch_style::horizontal, "horizontal"}, {xtd::drawing::drawing_2d::hatch_style::vertical, "vertical"}, {xtd::drawing::drawing_2d::hatch_style::forward_diagonal, "forward_diagonal"}, {xtd::drawing::drawing_2d::hatch_style::backward_diagonal, "backward_diagonal"}, {xtd::drawing::drawing_2d::hatch_style::cross, "cross"}, {xtd::drawing::drawing_2d::hatch_style::diagonal_cross, "diagonal_cross"}, {xtd::drawing::drawing_2d::hatch_style::percent_05, "percent_05"}, {xtd::drawing::drawing_2d::hatch_style::percent_10, "percent_10"}, {xtd::drawing::drawing_2d::hatch_style::percent_20, "percent_20"}, {xtd::drawing::drawing_2d::hatch_style::percent_25, "percent_25"}, {xtd::drawing::drawing_2d::hatch_style::percent_30, "percent_30"}, {xtd::drawing::drawing_2d::hatch_style::percent_40, "percent_40"}, {xtd::drawing::drawing_2d::hatch_style::percent_50, "percent_50"}, {xtd::drawing::drawing_2d::hatch_style::percent_60, "percent_60"}, {xtd::drawing::drawing_2d::hatch_style::percent_70, "percent_70"}, {xtd::drawing::drawing_2d::hatch_style::percent_75, "percent_75"}, {xtd::drawing::drawing_2d::hatch_style::percent_80, "percent_80"}, {xtd::drawing::drawing_2d::hatch_style::percent_90, "percent_90"}, {xtd::drawing::drawing_2d::hatch_style::light_downward_diagonal, "light_downward_diagonal"}, {xtd::drawing::drawing_2d::hatch_style::light_upward_diagonal, "light_upward_diagonal"}, {xtd::drawing::drawing_2d::hatch_style::dark_downward_diagonal, "dark_downward_diagonal"}, {xtd::drawing::drawing_2d::hatch_style::dark_upward_diagonal, "dark_upward_diagonal"}, {xtd::drawing::drawing_2d::hatch_style::wide_downward_diagonal, "wide_downward_diagonal"}, {xtd::drawing::drawing_2d::hatch_style::wide_upward_diagonal, "wide_upward_diagonal"}, {xtd::drawing::drawing_2d::hatch_style::light_vertical, "light_vertical"}, {xtd::drawing::drawing_2d::hatch_style::light_horizontal, "light_horizontal"}, {xtd::drawing::drawing_2d::hatch_style::narrow_vertical, "narrow_vertical"}, {xtd::drawing::drawing_2d::hatch_style::narrow_horizontal, "narrow_horizontal"}, {xtd::drawing::drawing_2d::hatch_style::dark_vertical, "dark_vertical"}, {xtd::drawing::drawing_2d::hatch_style::dark_horizontal, "dark_horizontal"}, {xtd::drawing::drawing_2d::hatch_style::dashed_downward_diagonal, "dashed_downward_diagonal"}, {xtd::drawing::drawing_2d::hatch_style::dashed_upward_diagonal, "dashed_upward_diagonal"}, {xtd::drawing::drawing_2d::hatch_style::dashed_horizontal, "dashed_horizontal"}, {xtd::drawing::drawing_2d::hatch_style::dashed_vertical, "dashed_vertical"}, {xtd::drawing::drawing_2d::hatch_style::small_confetti, "small_confetti"}, {xtd::drawing::drawing_2d::hatch_style::large_confetti, "large_confetti"}, {xtd::drawing::drawing_2d::hatch_style::zig_zag, "zig_zag"}, {xtd::drawing::drawing_2d::hatch_style::wave, "wave"}, {xtd::drawing::drawing_2d::hatch_style::diagonal_brick, "diagonal_brick"}, {xtd::drawing::drawing_2d::hatch_style::horizontal_brick, "horizontal_brick"}, {xtd::drawing::drawing_2d::hatch_style::weave, "weave"}, {xtd::drawing::drawing_2d::hatch_style::plaid, "plaid"}, {xtd::drawing::drawing_2d::hatch_style::divot, "divot"}, {xtd::drawing::drawing_2d::hatch_style::dotted_grid, "dotted_grid"}, {xtd::drawing::drawing_2d::hatch_style::dotted_diamond, "dotted_diamond"}, {xtd::drawing::drawing_2d::hatch_style::shingle, "shingle"}, {xtd::drawing::drawing_2d::hatch_style::trellis, "trellis"}, {xtd::drawing::drawing_2d::hatch_style::sphere, "sphere"}, {xtd::drawing::drawing_2d::hatch_style::small_grid, "small_grid"}, {xtd::drawing::drawing_2d::hatch_style::small_checker_board, "small_checker_board"}, {xtd::drawing::drawing_2d::hatch_style::large_checker_board, "large_checker_board"}, {xtd::drawing::drawing_2d::hatch_style::outlined_diamond, "outlined_diamond"}, {xtd::drawing::drawing_2d::hatch_style::solid_diamond, "solid_diamond"}, {xtd::drawing::drawing_2d::hatch_style::wide_checker_board, "wide_checker_board"}};}
};
/// @endcond
