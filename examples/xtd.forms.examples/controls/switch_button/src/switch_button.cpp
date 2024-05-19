#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/switch_button>

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
      label1.text(ustring::format("rounded switch: {}", switch_button2.checked() ? "On" : "Off"));
    };
    switch_button2.checked(true);
    
    label1.parent(*this);
    label1.location({110, 72});
    label1.auto_size(true);
    
    switch_button3.parent(*this);
    switch_button3.location({50, 110});
    switch_button3.rounded(false);
    switch_button3.checked_changed += [&] {
      label2.text(ustring::format("square switch: {}", switch_button3.checked() ? "On" : "Off"));
    };
    switch_button3.checked(true);
    
    label2.parent(*this);
    label2.location({110, 112});
    label2.auto_size(true);
  }
  
private:
  switch_button switch_button1;
  switch_button switch_button2;
  switch_button switch_button3;
  label label1;
  label label2;
};

auto main() -> int {
  application::run(form1 {});
}
