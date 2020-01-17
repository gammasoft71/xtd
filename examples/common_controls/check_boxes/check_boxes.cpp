#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  auto form_main = control::create<form>("Check boxes example");
  auto group_box_font = control::create<group_box>(*form_main, texts::font, {10, 10}, {150, 180});
  auto check_box_bold = check_boxes::bold(*group_box_font, {20, 20});
  auto check_box_italic = check_boxes::italic(*group_box_font, {20, 50});
  auto check_box_underline = check_boxes::underline(*group_box_font, {20, 80});
  auto check_box_strikeout = check_boxes::strikeout(*group_box_font, {20, 110});
  auto panel_test = control::create<panel>(*form_main, "", {10, 200}, {250, 50});

  *form_main << *group_box_font;
  *group_box_font << *check_box_bold << *check_box_italic << *check_box_underline << *check_box_strikeout;
  application::run(*form_main);
}
