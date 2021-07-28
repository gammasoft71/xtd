#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Button example");

      button1.parent(*this);
      button1.text("Button 1");
      button1.location({50, 50});
      button1.click += [&] {
        label1.text(ustring::format("Button 1 clicked {} times", ++button1_clicked));
      };
      
      button2.parent(*this);
      button2.text("Button 2");
      button2.location({50, 100});
      button2.auto_repeat(true);
      button2.size({200, 75});
      button2.click += [&] {
        label2.text(ustring::format("Button 2 clicked {} times", ++button2_clicked));
      };
      
      label1.parent(*this);
      label1.text("Button 1 clicked 0 times");
      label1.location({50, 200});
      label1.width(200);
      
      label2.parent(*this);
      label2.text("Button 2 clicked 0 times");
      label2.location({50, 230});
      label2.width(200);
    }
    
  private:
    button button1;
    button button2;
    label label1;
    label label2;
    int button1_clicked = 0;
    int button2_clicked = 0;
  };
}

int main() {
  application::run(examples::form1());
}
