#include <xtd/xtd>

auto main() -> int {
  auto button1_clicked = 0, button2_clicked = 0;
  auto form1 = form::create("Button 4 example");
  auto button1 = button::create(form1, "Button 1", {50, 50});
  auto button2 = button::create(form1, "Button 2", {50, 100}, {200, 75});
  auto label1 = label::create(form1, "Button 1 clicked 0 times", {50, 200}, {200, 23});
  auto label2 = label::create(form1, "Button 2 clicked 0 times", {50, 230}, {200, 23});
  button1.click += delegate_ {label1.text(string::format("Button 1 clicked {} times", ++button1_clicked));};
  button2.auto_repeat(true).click += delegate_ {label2.text(string::format("Button 2 clicked {} times", ++button2_clicked));};
  application::run(form1);
}
