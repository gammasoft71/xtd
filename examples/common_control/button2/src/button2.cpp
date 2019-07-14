#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

// The main entry point for the application.
int main() {
  int button1_clicked = 0;
  int button2_clicked = 0;
  auto form1 = control::create<form>("form1");
  auto button1 = control::create<button>(*form1, "button1", {50, 50});
  auto button2 = control::create<button>(*form1, "button2", {50, 100}, {200, 75});
  auto label1 = control::create<label>(*form1, "button1 clicked 0 times", {50, 200});
  auto label2 = control::create<label>(*form1, "button2 clicked 0 times", {50, 230});
  
  button1->click += [&] (const control& sender, const event_args& e) {
    label1->text(strings::format("button1 clicked {} times", ++button1_clicked));
  };
  
  button2->click += [&] (const control& sender, const event_args& e) {
    label2->text(strings::format("button2 clicked {} times", ++button2_clicked));
  };
  
  application::run(*form1);
}
