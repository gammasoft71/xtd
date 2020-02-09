#include "../../../include/xtd/forms/emoticons.hpp"

using namespace xtd::forms;

// 00080-00FF Latin 1 Supplement

const xtd::forms::emoticon xtd::forms::emoticons::copyright_sign = {"copyright sign", {0x000000A9 , 0x0000FE0F }};
const xtd::forms::emoticon xtd::forms::emoticons::registered_sign = {"registered sign", {0x000000AE , 0x0000FE0F }};

const std::vector<xtd::forms::emoticon>& xtd::forms::emoticons::get_emoticons() {
  static std::vector<xtd::forms::emoticon> emoticons {copyright_sign, registered_sign, };
  return emoticons;
}
