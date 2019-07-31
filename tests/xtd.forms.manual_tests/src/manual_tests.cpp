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

  check_box check_box1;
  check_box1.parent(form);
  check_box1.check_state(forms::check_state::unchecked);
  check_box1.location({10, 10});
  check_box1.text("unchecked");
  cdebug << format("check_box1.back_color = {}", check_box1.back_color()) << endl;
  cdebug << format("check_box1.fore_color = {}", check_box1.fore_color()) << endl;
  cdebug << format("check_box1.size = {}", check_box1.size()) << endl;

  check_box check_box2;
  check_box2.parent(form);
  check_box2.check_state(forms::check_state::checked);
  check_box2.location({10, 40});
  check_box2.text("checked");
  cdebug << format("check_box2.back_color = {}", check_box2.back_color()) << endl;
  cdebug << format("check_box2.fore_color = {}", check_box2.fore_color()) << endl;
  cdebug << format("check_box2.size = {}", check_box2.size()) << endl;

  check_box check_box3;
  check_box3.parent(form);
  //check_box3.auto_check(false);
  check_box3.three_state(true);
  check_box3.check_state(forms::check_state::indeterminate);
  check_box3.location({10, 70});
  check_box3.text("indeterminate");
  check_box3.check_changed += [&](const control& sender, const event_args& e) {
    cdebug << format("check_box3.checked() = {}", check_box3.checked()) << endl;
  };
  check_box3.check_state_changed += [&](const control& sender, const event_args& e) {
    cdebug << format("check_box3.check_state() = {}", check_box3.check_state()) << endl;
  };
  cdebug << format("check_box3.back_color = {}", check_box3.back_color()) << endl;
  cdebug << format("check_box3.fore_color = {}", check_box3.fore_color()) << endl;
  cdebug << format("check_box3.size = {}", check_box3.size()) << endl;

  button b;
  b.parent(form);
  b.location({10, 200});
  b.click += [&](const control& sender, const event_args& e) {
    cdebug << "button click" << endl;
  };
  
  application::run(form);
}
