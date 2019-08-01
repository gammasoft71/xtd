#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

// The main entry point for the application.
int main() {
  form form;
  form.back_color(color::dodger_blue);
  form.fore_color(color::yellow);
  cdebug << format("form.back_color = {}", form.back_color()) << endl;
  cdebug << format("form.fore_color = {}", form.fore_color()) << endl;
  cdebug << format("form.size = {}", form.size()) << endl;

  radio_button radio_button1;
  radio_button1.parent(form);
  radio_button1.checked(true);
  radio_button1.location({30, 30});
  radio_button1.text("radio 1");
  cdebug << format("radio_button1.back_color = {}", radio_button1.back_color()) << endl;
  cdebug << format("radio_button1.fore_color = {}", radio_button1.fore_color()) << endl;
  cdebug << format("radio_button1.size = {}", radio_button1.size()) << endl;

  radio_button radio_button2;
  radio_button2.parent(form);
  radio_button2.location({30, 60});
  radio_button2.text("radio 2");
  cdebug << format("radio_button2.back_color = {}", radio_button2.back_color()) << endl;
  cdebug << format("radio_button2.fore_color = {}", radio_button2.fore_color()) << endl;
  cdebug << format("radio_button2.size = {}", radio_button2.size()) << endl;

  radio_button radio_button3;
  radio_button3.parent(form);
  radio_button3.location({30, 90});
  radio_button3.text("radio 3");
  radio_button3.checked_changed += [&](const control& sender, const event_args& e) {
    cdebug << format("radio_button3.checked() = {}", radio_button3.checked()) << endl;
  };
  cdebug << format("radio_button3.back_color = {}", radio_button3.back_color()) << endl;
  cdebug << format("radio_button3.fore_color = {}", radio_button3.fore_color()) << endl;
  cdebug << format("radio_button3.size = {}", radio_button3.size()) << endl;

  application::run(form);
}
