#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({220, 115});
    maximum_size(size() + drawing::size {300, 300});
    minimum_size(size());
    controls().push_back_range({up_button, left_button, right_button, down_button, grow_button, shrink_button});
    text("Form resize example");
    
    up_button.auto_repeat(true);
    up_button.bounds({45, 10, 25, 25});
    up_button.image(button_images::from_name("go-up"));
    up_button.click += [&] {
      top(top() - 10);
    };
    
    left_button.auto_repeat(true);
    left_button.bounds({10, 45, 25, 25});
    left_button.image(button_images::from_name("go-previous"));
    left_button.click += [&] {
      left(left() - 10);
    };
    
    right_button.auto_repeat(true);
    right_button.bounds({80, 45, 25, 25});
    right_button.image(button_images::from_name("go-next"));
    right_button.click += [&] {
      left(left() + 10);
    };
    
    down_button.auto_repeat(true);
    down_button.bounds({45, 80, 25, 25});
    down_button.image(button_images::from_name("go-down"));
    down_button.click += [&] {
      top(top() + 10);
    };
    
    grow_button.auto_repeat(true);
    grow_button.bounds({150, 45, 25, 25});
    grow_button.image(button_images::from_name("zoom-in"));
    grow_button.click += [&] {
      size(size() + drawing::size {10, 10});
    };
    
    shrink_button.auto_repeat(true);
    shrink_button.bounds({185, 45, 25, 25});
    shrink_button.image(button_images::from_name("zoom-out"));
    shrink_button.click += [&] {
      size(size() - drawing::size {10, 10});
    };
  }
  
private:
  button up_button;
  button left_button;
  button right_button;
  button down_button;
  button grow_button;
  button shrink_button;
};

int main() {
  application::run(form1());
}
