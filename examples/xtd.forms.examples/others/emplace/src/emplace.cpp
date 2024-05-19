#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>

using namespace xtd::drawing;
using namespace xtd::forms;

auto main() -> int {
  auto button1_clicked = 0, button2_clicked = 0;
  auto form1 = xtd::forms::form::create("Emplace example");
  form1.controls().emplace<xtd::forms::button>(form1.controls().begin(), "Button 1", point{50, 50}).click += [&] {
    form1.controls()["label1"].value().get().text(xtd::ustring::format("Button 1 clicked {} times", ++button1_clicked));
  };
  form1.controls().emplace_at<xtd::forms::button>(1, "Button 2", point {50, 100}, size {200, 75}).auto_repeat(true).click += [&] {
    form1.controls()["label2"].value().get().text(xtd::ustring::format("Button 2 clicked {} times", ++button2_clicked));
  };
  form1.controls().emplace<xtd::forms::label>(form1.controls().end(), "Button 1 clicked 0 times", point {50, 200}, size {200, 23}, "label1");
  form1.controls().emplace_back<xtd::forms::label>("Button 2 clicked 0 times", point {50, 230}, size {200, 23}, "label2");
  xtd::forms::application::run(form1);
}
