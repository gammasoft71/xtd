#include <xtd/xtd>

using namespace xtd::forms;

int main() {
  auto form_main = control::create<form>("Radio buttons example");
  auto group_box_alignment = control::create<group_box>(*form_main, system_texts::alignment(), {10, 10}, {150, 180});
  auto radio_button_align_left = radio_buttons::align_left(*group_box_alignment, {20, 20});
  auto radio_button_align_right = radio_buttons::align_right(*group_box_alignment, {20, 50});
  auto radio_button_centered = radio_buttons::centered(*group_box_alignment, {20, 80});
  auto radio_button_justified = radio_buttons::justified(*group_box_alignment, {20, 110});
  radio_button_align_left->checked(true);
  application::run(*form_main);
}
