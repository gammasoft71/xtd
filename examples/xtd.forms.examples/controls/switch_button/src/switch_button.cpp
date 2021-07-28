#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Switch button example");
    
    switch_button1.auto_check(false);
    switch_button1.parent(*this);
    switch_button1.location({50, 30});
    switch_button1.click += [&] {
      //switch_button1.checked(!switch_button1.checked());
    };

    switch_button2.parent(*this);
    switch_button2.location({50, 70});
    switch_button2.checked_changed += [&] {
      label1.text(ustring::format("switch: {}", switch_button2.checked() ? "On" : "Off"));
    };
    switch_button2.checked(true);

    label1.parent(*this);
    label1.location({50, 110});
    label1.auto_size(true);
  }
  
private:
  switch_button switch_button1;
  switch_button switch_button2;
  label label1;
};

int main() {
  application::run(form1());
}
