#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

// The main entry point for the application.
int main() {
  form form;
  //form.back_color(color::dodger_blue);
  //form.fore_color(color::yellow);
  cdebug << format("form.back_color = {}", form.back_color()) << endl;
  cdebug << format("form.fore_color = {}", form.fore_color()) << endl;
  cdebug << format("form.size = {}", form.size()) << endl;

  group_box group_box1;
  group_box1.parent(form);
  group_box1.location({10, 10});
  group_box1.text("group_box 1");

  radio_button radio_button1;
  radio_button1.parent(group_box1);
  radio_button1.checked(true);
  radio_button1.location({30, 20});
  radio_button1.text("radio 1");
  cdebug << format("radio_button1.back_color = {}", radio_button1.back_color()) << endl;
  cdebug << format("radio_button1.fore_color = {}", radio_button1.fore_color()) << endl;
  cdebug << format("radio_button1.size = {}", radio_button1.size()) << endl;
  
  radio_button radio_button2;
  radio_button2.parent(group_box1);
  radio_button2.location({30, 50});
  radio_button2.text("radio 2");
  radio_button2.checked_changed += [&](const control& sender, const event_args& e) {
    cdebug << format("radio_button2.checked() = {}", radio_button2.checked()) << endl;
  };
  cdebug << format("radio_button2.back_color = {}", radio_button2.back_color()) << endl;
  cdebug << format("radio_button2.fore_color = {}", radio_button2.fore_color()) << endl;
  cdebug << format("radio_button2.size = {}", radio_button2.size()) << endl;

  group_box group_box2;
  group_box2.parent(form);
  group_box2.location({10, 150});
  
  radio_button radio_button3;
  radio_button3.parent(group_box2);
  radio_button3.checked(true);
  radio_button3.location({30, 20});
  radio_button3.text("radio 3");
  
  radio_button radio_button4;
  radio_button4.parent(group_box2);
  radio_button4.location({30, 50});
  radio_button4.text("radio 4");
  radio_button4.checked_changed += [&](const control& sender, const event_args& e) {
    cdebug << format("radio_button4.checked() = {}", radio_button4.checked()) << endl;
  };
  
  button button;
  button.parent(form);
  button.location({30, 120});
  button.text("Color...");
  button.click += [&](const control& sender, const event_args& e) {
    if (form.back_color() == color::dodger_blue) {
      form.back_color(system_colors::control);
      form.fore_color(system_colors::control_text);
    } else {
      form.back_color(color::dodger_blue);
      form.fore_color(color::yellow);
    }
  };

  application::run(form);
}
