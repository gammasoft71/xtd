#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Manual test");
    
    button1.parent(*this);
    button1.text("Button 1");
    button1.location({50, 50});
    
    button2.parent(*this);
    button2.text("Button 2");
    button2.location({50, 100});
    button2.size({200, 100});
    
    rb1.parent(*this);
    rb1.text("Radio 1");
    rb1.location({10, 10});
    
    rb2.parent(*this);
    rb2.text("Radio 2");
    rb2.location({150, 10});
  }
  
private:
  button button1;
  button button2;
  radio_button rb1;
  radio_button rb2;
};

int main() {
  application::enable_visual_styles();
  application::run(form1());
}
