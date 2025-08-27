#include <xtd/xtd>

auto main() -> int {
  auto button1_clicked = 0, button2_clicked = 0;
  auto form1 = form::create("Emplace example");
  form1.controls().emplace<button>(form1.controls().begin(), "Button 1", point{50, 50}).click += delegate_ {
    form1.controls()["label1"].value().get().text(string::format("Button 1 clicked {} times", ++button1_clicked));
  };
  form1.controls().emplace_at<button>(1, "Button 2", point {50, 100}, drawing::size {200, 75}).auto_repeat(true).click += delegate_ {
    form1.controls()["label2"].value().get().text(string::format("Button 2 clicked {} times", ++button2_clicked));
  };
  form1.controls().emplace<label>(form1.controls().end(), "Button 1 clicked 0 times", point {50, 200}, drawing::size {200, 23}, "label1");
  form1.controls().emplace_back<label>("Button 2 clicked 0 times", point {50, 230}, drawing::size {200, 23}, "label2");
  application::run(form1);
}
