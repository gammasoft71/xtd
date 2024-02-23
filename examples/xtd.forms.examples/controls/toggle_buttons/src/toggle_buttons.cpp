#include <xtd/drawing/texts>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/group_box>
#include <xtd/forms/toggle_buttons>

using namespace xtd::forms;

auto main()->int {
  auto form_main = form::create("toggle buttons example");
  auto group_box_alignment = group_box::create(form_main, xtd::drawing::texts::alignment(), {10, 10}, {150, 240});
  auto toggle_button_align_left = toggle_buttons::align_left(group_box_alignment, false, check_state::unchecked, {20, 20});
  auto toggle_button_align_right = toggle_buttons::align_right(group_box_alignment, false, check_state::unchecked, {20, 70});
  auto toggle_button_centered = toggle_buttons::centered(group_box_alignment, false, check_state::unchecked, {20, 120});
  auto toggle_button_justified = toggle_buttons::justified(group_box_alignment, false, check_state::unchecked, {20, 170});
  toggle_button_align_left.checked(true);
  application::run(form_main);
}
