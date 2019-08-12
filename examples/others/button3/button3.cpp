#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->button1.text("Button 1").location({50, 50});
      this->button2.text("Button 2").location({50, 100}).size({200, 75});
      this->label1.text("Button 1 clicked 0 times").location({50, 200}).width(200);      
      this->label2.text("Button 2 clicked 0 times").location({50, 230}).width(200);      
      this->button1.click += [&](const control& sender, const event_args& e) {this->label1.text(strings::format("Button 1 clicked {} times", ++this->button1_clicked));};
      this->button2.click += [&](const control& sender, const event_args& e) {this->label2.text(strings::format("Button 2 clicked {} times", ++this->button2_clicked));};
      this->text("Button example");     
      *this << this->button1 << this->button2 << this->label1 << this->label2;
    }
    
  private:
    button button1, button button2;
    label label1, label2;
    int button1_clicked = 0, button2_clicked = 0;
  };
}

// The main entry point for the application.
int main() {
  application::enable_visual_styles();
  application::run(examples::form1());
}
