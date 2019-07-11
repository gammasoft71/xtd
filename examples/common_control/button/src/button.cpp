#include <xtd/strings>
#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->button1.parent(*this);
      this->button1.text("button1");
      this->button1.location({50, 50});
      this->button1.click += [&] (const control& sender, const event_args& e) {
        this->label1.text(strings::format("button1 clicked {} times", ++this->button1_clicked));
      };
      
      this->button2.parent(*this);
      this->button2.text("button2");
      this->button2.location({50, 100});
      this->button2.size({200, 75});
      this->button2.click += [&] (const control& sender, const event_args& e) {
        this->label2.text(strings::format("button2 clicked {} times", ++this->button2_clicked));
      };
      
      this->label1.parent(*this);
      this->label1.text("button1 clicked 0 times");
      this->label1.location({50, 200});
      this->label1.width(200);
      
      this->label2.parent(*this);
      this->label2.text("button2 clicked 0 times");
      this->label2.location({50, 230});
      this->label2.width(200);
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

// The main entry point for the application.
int main() {
  application::enable_visual_styles();
  application::run(examples::form1());
}

