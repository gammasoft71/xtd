#include "../../../include/xtd/forms/emoticons.hpp"

using namespace xtd::forms;

// 00080-00FF Latin 1 Supplement

const xtd::forms::emoticon xtd::forms::emoticons::copyright_sign = {"copyright sign", {0x000000A9, 0x0000FE0F}};
const xtd::forms::emoticon xtd::forms::emoticons::registered_sign = {"registered sign", {0x000000AE, 0x0000FE0F}};

/// 2000-206F - General Punctuation

const xtd::forms::emoticon xtd::forms::emoticons::zero_width_joiner = {"zero width joiner", 0x0000200D};
const xtd::forms::emoticon xtd::forms::emoticons::double_exclamation_mark = {"double exclamation mark", {0x0000203C, 0x0000FE0F}};
const xtd::forms::emoticon xtd::forms::emoticons::exclamation_question_mark = {"exclamation question mark", {0x00002049, 0x0000FE0F}};

/// 2100-214F Letterlike Symbols

const xtd::forms::emoticon xtd::forms::emoticons::trade_mark_sign = {"trade mark sign", {0x00002122, 0x0000FE0F}};
const xtd::forms::emoticon xtd::forms::emoticons::information_source = {"information source", {0x00002139, 0x0000FE0F}};

/// 2190-21FF Arrows

const xtd::forms::emoticon xtd::forms::emoticons::left_right_arrow = {"left right arrow", {0x00002194, 0x0000FE0F}};
const xtd::forms::emoticon xtd::forms::emoticons::up_down_arrow = {"up down arrow", {0x00002195, 0x0000FE0F}};
const xtd::forms::emoticon xtd::forms::emoticons::north_west_arrow = {"north west arrow", {0x00002196, 0x0000FE0F}};
const xtd::forms::emoticon xtd::forms::emoticons::north_east_arrow = {"north east arrow", {0x00002197, 0x0000FE0F}};
const xtd::forms::emoticon xtd::forms::emoticons::south_east_arrow = {"south east arrow", {0x00002198, 0x0000FE0F}};
const xtd::forms::emoticon xtd::forms::emoticons::south_west_arrow = {"south west arrow", {0x00002199, 0x0000FE0F}};
const xtd::forms::emoticon xtd::forms::emoticons::leftwards_arrow_with_hook = {"leftwards arrow with hook", {0x000021A9, 0x0000FE0F}};
const xtd::forms::emoticon xtd::forms::emoticons::rightwards_arrow_with_hook = {"rightwards arrow with hook", {0x000021AA, 0x0000FE0F}};

/// 2300-23FF Miscellaneous Technical

const xtd::forms::emoticon xtd::forms::emoticons::watch = {"watch", 0x0000231A};
const xtd::forms::emoticon xtd::forms::emoticons::hourglass = {"hourglass", 0x0000231B};
const xtd::forms::emoticon xtd::forms::emoticons::keyboard = {"keyboard", 0x00002328};
const xtd::forms::emoticon xtd::forms::emoticons::eject_symbol = {"eject symbol", {0x000023CF, 0x0000FE0F}};
const xtd::forms::emoticon xtd::forms::emoticons::black_right_pointing_double_triangle = {"black right-pointing double triangle", 0x000023E9};
const xtd::forms::emoticon xtd::forms::emoticons::black_left_pointing_double_triangle = {"black left-pointing double triangle", 0x000023EA};
const xtd::forms::emoticon xtd::forms::emoticons::black_up_pointing_double_triangle = {"black up-pointing double triangle", 0x000023EB};
const xtd::forms::emoticon xtd::forms::emoticons::black_down_pointing_double_triangle = {"black down-pointing double triangle", 0x000023EC};
const xtd::forms::emoticon xtd::forms::emoticons::black_right_pointing_double_triangle_with_vertical_bar = {"black right-pointing double triangle with vertical bar", 0x000023ED};
const xtd::forms::emoticon xtd::forms::emoticons::black_left_pointing_double_triangle_with_vertical_bar = {"black left-pointing double triangle with vertical bar", 0x000023EE};
const xtd::forms::emoticon xtd::forms::emoticons::black_right_pointing_triangle_with_double_vertical_bar = {"black right-pointing triangle with double vertical bar", 0x000023EF};
const xtd::forms::emoticon xtd::forms::emoticons::alarm_clock = {"alarm clock", 0x000023F0};
const xtd::forms::emoticon xtd::forms::emoticons::stopwatch = {"stopwatch", 0x000023F1};
const xtd::forms::emoticon xtd::forms::emoticons::timer_clock = {"timer clock", 0x000023F2};
const xtd::forms::emoticon xtd::forms::emoticons::hourglass_with_flowing_sand = {"hourglass with flowing sand", 0x000023F3};
const xtd::forms::emoticon xtd::forms::emoticons::double_vertical_bar = {"double vertical bar", 0x000023F8};
const xtd::forms::emoticon xtd::forms::emoticons::black_square_for_stop = {"black square for stop", 0x000023F9};
const xtd::forms::emoticon xtd::forms::emoticons::black_circle_for_record = {"black circle for record", 0x000023FA};

/// 2460-24FF Enclosed Alphanumerics

const xtd::forms::emoticon xtd::forms::emoticons::circled_latin_capital_letter_m = {"circled latin capital letter m", {0x000024C2, 0x0000FE0F}};

const std::vector<xtd::forms::emoticon>& xtd::forms::emoticons::get_emoticons() {
  static std::vector<xtd::forms::emoticon> emoticons {
    copyright_sign, registered_sign,
    double_exclamation_mark, exclamation_question_mark,
    trade_mark_sign, information_source,
    left_right_arrow, up_down_arrow, north_west_arrow, north_east_arrow, south_east_arrow, south_west_arrow, leftwards_arrow_with_hook, rightwards_arrow_with_hook,
    watch, hourglass, keyboard, eject_symbol, black_right_pointing_double_triangle, black_left_pointing_double_triangle, black_up_pointing_double_triangle, black_down_pointing_double_triangle, black_right_pointing_double_triangle_with_vertical_bar, black_left_pointing_double_triangle_with_vertical_bar, black_right_pointing_triangle_with_double_vertical_bar, alarm_clock, stopwatch, timer_clock, hourglass_with_flowing_sand, double_vertical_bar, black_square_for_stop, black_circle_for_record,
    circled_latin_capital_letter_m,
  };
  return emoticons;
}
