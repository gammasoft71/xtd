#include <xtd/xtd>

auto main()->int {
  auto button1_clicked = 0, button2_clicked = 0;
  auto form1 = xtd::forms::control::create<xtd::forms::form>("Button 4 example");
  auto button1 = xtd::forms::control::create<xtd::forms::button>(*form1, "Button 1", {50, 50});
  auto button2 = xtd::forms::control::create<xtd::forms::button>(*form1, "Button 2", {50, 100}, {200, 75});
  auto label1 = xtd::forms::control::create<xtd::forms::label>(*form1, "Button 1 clicked 0 times", {50, 200}, {200, 23});
  auto label2 = xtd::forms::control::create<xtd::forms::label>(*form1, "Button 2 clicked 0 times", {50, 230}, {200, 23});
  button1->click += [&] {label1->text(xtd::ustring::format("Button 1 clicked {} times", ++button1_clicked));};
  button2->click += [&] {label2->text(xtd::ustring::format("Button 2 clicked {} times", ++button2_clicked));};
  xtd::forms::application::run(*form1);
}
