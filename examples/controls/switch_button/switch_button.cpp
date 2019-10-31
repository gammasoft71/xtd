#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Switch button example");

    switch_button1.parent(*this);
    switch_button1.location({10, 10});
    switch_button1.checked_changed += [this](control& sender, const event_args& e) {
      label1.text(strings::format("switch: {}", static_cast<switch_button&>(sender).checked() ? "ON" : "OFF"));
    };

    switch_button2.parent(*this);
    switch_button2.auto_check(false);
    switch_button2.checked(true);
    switch_button2.location({10, 50});
    switch_button2.click += [](control& sender, const event_args& e) {
      //static_cast<switch_button&>(sender).checked(!static_cast<switch_button&>(sender).checked());
    };

    label1.parent(*this);
    label1.location({10, 90});
    label1.auto_size(true);
    label1.text("switch: OFF");
  }
  
private:
  switch_button switch_button1;
  switch_button switch_button2;
  label label1;

};

int main() {
  application::run(form1());
}
