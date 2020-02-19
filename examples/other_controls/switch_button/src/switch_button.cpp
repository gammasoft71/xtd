#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Switch button example");
    
    switch_button1.parent(*this);
    switch_button1.location({50, 30});
    switch_button1.checked_changed += [&] {
      label1.text(strings::format("switch: {}", switch_button1.checked() ? "ON" : "OFF"));
    };

    switch_button2.parent(*this);
    switch_button2.auto_check(false);
    switch_button2.checked(true);
    switch_button2.location({50, 70});
    switch_button2.click += [&] {
      //switch_button2.checked(!switch_button2.checked());
    };
    
    switch_button3.parent(*this);
    switch_button3.location({170, 30});
    switch_button3.rounded(true);
    switch_button3.checked_changed += [&] {
      label2.text(strings::format("switch: {}", switch_button3.checked() ? "ON" : "OFF"));
    };

    switch_button4.parent(*this);
    switch_button4.auto_check(false);
    switch_button4.checked(true);
    switch_button4.location({170, 70});
    switch_button4.rounded(true);
    switch_button4.click += [&] {
      //switch_button4.checked(!switch_button4.checked());
    };

    label1.parent(*this);
    label1.location({50, 110});
    label1.auto_size(true);
    label1.text("switch: OFF");

    label2.parent(*this);
    label2.location({170, 110});
    label2.auto_size(true);
    label2.text("switch: OFF");
  }
  
private:
  switch_button switch_button1;
  switch_button switch_button2;
  switch_button switch_button3;
  switch_button switch_button4;
  label label1;
  label label2;
};

int main() {
  application::run(form1());
}
