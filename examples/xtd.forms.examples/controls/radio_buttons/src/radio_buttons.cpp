#include <xtd/drawing/texts>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/group_box>
#include <xtd/forms/radio_buttons>

using namespace xtd::forms;

auto main()->int {
  auto form_main = form::create("Radio buttons example");
  auto group_box_alignment = group_box::create(form_main, xtd::drawing::texts::alignment(), {10, 10}, {150, 180});
  auto radio_button_align_left = radio_buttons::align_left(group_box_alignment, true, {20, 20});
  auto radio_button_align_right = radio_buttons::align_right(group_box_alignment, false, {20, 50});
  auto radio_button_centered = radio_buttons::centered(group_box_alignment, false, {20, 80});
  auto radio_button_justified = radio_buttons::justified(group_box_alignment, false, {20, 110});
  application::run(form_main);
}
