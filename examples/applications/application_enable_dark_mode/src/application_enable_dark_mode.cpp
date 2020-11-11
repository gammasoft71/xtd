#include <xtd/xtd.forms>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    label1.parent(*this);
    label1.auto_size(true);
    label1.location({10, 13});
    label1.text("Dark mode");

    button1.parent(*this);
    button1.auto_size(true);
    button1.location({110, 10});
    button1.text("Click me");

    list_box1.parent(*this);
    list_box1.location({10, 50});
    list_box1.items().push_back_range({"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"});
    list_box1.selected_item("Item 1");

    radio_button1.parent(*this);
    radio_button1.auto_size(true);
    radio_button1.checked(true);
    radio_button1.location({10, 170});
    radio_button1.text("Radio 1");
    
    radio_button2.parent(*this);
    radio_button2.auto_size(true);
    radio_button2.location({110, 170});
    radio_button2.text("Radio 2");

    check_box1.parent(*this);
    check_box1.auto_size(true);
    check_box1.checked(true);
    check_box1.location({10, 200});
    check_box1.text("Check 1");
    
    check_box2.parent(*this);
    check_box2.auto_size(true);
    check_box2.location({110, 200});
    check_box2.text("Check 2");
  }
  
private:
  label label1;
  button button1;
  list_box list_box1;
  radio_button radio_button1;
  radio_button radio_button2;
  check_box check_box1;
  check_box check_box2;
};

int main() {
  application::enable_dark_mode();
  xtd::forms::application::run(form1());
}
