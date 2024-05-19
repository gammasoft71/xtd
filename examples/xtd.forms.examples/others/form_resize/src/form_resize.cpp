#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/button_images>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({220, 115});
    maximum_client_size(client_size() + drawing::size {300, 300});
    minimum_client_size(client_size());
    controls().push_back_range({up_button, left_button, right_button, down_button, shrink_button, grow_button});
    text("Form resize example");
    
    key_down += [&](auto sender, auto e) {
      if (e.key_code() == keys::right) left(left() + 10);
      else if (e.key_code() == keys::left) left(left() - 10);
      else if (e.key_code() == keys::down) top(top() + 10);
      else if (e.key_code() == keys::up) top(top() - 10);
    };
    
    key_press += [&](auto sender, auto e) {
      if (e.key_char() == '+') size(size() + drawing::size {10, 10});
      else if (e.key_char() == '-') size(size() - drawing::size {10, 10});
    };
        
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
    
    shrink_button.auto_repeat(true);
    shrink_button.bounds({150, 45, 25, 25});
    shrink_button.image(button_images::from_name("zoom-out"));
    shrink_button.click += [&] {
      size(size() - drawing::size {10, 10});
    };
    
    grow_button.auto_repeat(true);
    grow_button.bounds({185, 45, 25, 25});
    grow_button.image(button_images::from_name("zoom-in"));
    grow_button.click += [&] {
      size(size() + drawing::size {10, 10});
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

auto main() -> int {
  application::run(form1 {});
}
