#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Group box and radio button example");
    client_size({300, 160});
    
    group_box1.parent(*this);
    group_box1.bounds({10, 10, 135, 140});
    group_box1.text("Group 1");
    
    group_box2.parent(*this);
    group_box2.bounds({155, 10, 135, 140});
    group_box2.text("Group 2");
    
    radio_button1.checked(true);
    radio_button1.location({20, 10});
    radio_button1.parent(group_box1);
    radio_button1.text("radio 1");
    
    radio_button2.location({20, 40});
    radio_button2.parent(group_box1);
    radio_button2.text("radio 2");

    radio_button3.location({20, 70});
    radio_button3.parent(group_box1);
    radio_button3.text("radio 3");

    radio_button4.location({20, 10});
    radio_button4.parent(group_box2);
    radio_button4.text("radio 4");

    radio_button5.checked(true);
    radio_button5.location({20, 40});
    radio_button5.parent(group_box2);
    radio_button5.text("radio 5");

    radio_button6.location({20, 70});
    radio_button6.parent(group_box2);
    radio_button6.text("radio 6");
  }
  
private:
  group_box group_box1;
  group_box group_box2;
  
  radio_button radio_button1;
  radio_button radio_button2;
  radio_button radio_button3;
  radio_button radio_button4;
  radio_button radio_button5;
  radio_button radio_button6;
};

int main() {
  application::run(form1());
}
