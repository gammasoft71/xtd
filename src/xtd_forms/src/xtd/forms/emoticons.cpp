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

const std::vector<xtd::forms::emoticon>& xtd::forms::emoticons::get_emoticons() {
  static std::vector<xtd::forms::emoticon> emoticons {
    copyright_sign, registered_sign,
    double_exclamation_mark, exclamation_question_mark,
    trade_mark_sign, information_source,
    left_right_arrow, up_down_arrow, north_west_arrow, north_east_arrow, south_east_arrow, south_west_arrow, leftwards_arrow_with_hook, rightwards_arrow_with_hook,
  };
  return emoticons;
}
