#include <xtd/xtd.forms>

auto main()->int {
  auto form1 = xtd::forms::control::create<xtd::forms::form>("Button 2 example");
  auto button1 = xtd::forms::control::create<xtd::forms::button>(*form1, "Button 1", {50, 50});
  auto button2 = xtd::forms::control::create<xtd::forms::button>(*form1, "Button 2", {50, 100}, {200, 75});
  auto label1 = xtd::forms::control::create<xtd::forms::label>(*form1, "Button 1 clicked 0 times", {50, 200}, {200, 23});
  auto label2 = xtd::forms::control::create<xtd::forms::label>(*form1, "Button 2 clicked 0 times", {50, 230}, {200, 23});

  button1->click += [&](const auto& sender, const auto& e) {
    static auto clicks = 0;
    label1->text(xtd::strings::format("Button 1 clicked {} times", ++clicks));
  };
  
  button2->click += [&](const auto& sender, const auto& e) {
    static auto clicks = 0;
    label2->text(xtd::strings::format("Button 2 clicked {} times", ++clicks));
  };
  
  xtd::forms::application::run(*form1);
}
