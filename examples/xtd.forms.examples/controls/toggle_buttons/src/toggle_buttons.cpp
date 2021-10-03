#include <xtd/xtd>

using namespace xtd::forms;

int main() {
  auto form_main = control::create<form>("toggle buttons example");
  auto group_box_alignment = control::create<group_box>(*form_main, system_texts::alignment(), {10, 10}, {150, 180});
  auto toggle_button_align_left = toggle_buttons::align_left(*group_box_alignment, {20, 20});
  auto toggle_button_align_right = toggle_buttons::align_right(*group_box_alignment, {20, 50});
  auto toggle_button_centered = toggle_buttons::centered(*group_box_alignment, {20, 80});
  auto toggle_button_justified = toggle_buttons::justified(*group_box_alignment, {20, 110});
  toggle_button_align_left->checked(true);
  application::run(*form_main);
}
