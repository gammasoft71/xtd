#include <xtd/drawing/texts>
#include <xtd/forms/application>
#include <xtd/forms/check_boxes>
#include <xtd/forms/group_box>
#include <xtd/forms/form>

using namespace xtd::forms;

auto main()->int {
  auto main_form = form::create("Check boxes example");
  auto font_group_box = group_box::create(main_form, xtd::drawing::texts::font(), {10, 10}, {150, 180});
  auto bold_check_box = check_boxes::bold(font_group_box, {20, 20});
  auto italic_check_box = check_boxes::italic(font_group_box, {20, 50});
  auto underline_check_box = check_boxes::underline(font_group_box, check_state::unchecked, {20, 80});
  auto strikeout_check_box = check_boxes::strikeout(font_group_box, false, check_state::unchecked, {20, 110});
  application::run(main_form);
}
