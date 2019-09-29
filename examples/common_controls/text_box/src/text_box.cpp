#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Text box example");

      text_box1.parent(*this);
      text_box1.location({10, 10});
      text_box1.text("text box");
      text_box1.text_changed += [this](const control& sender, const xtd::event_args& e) {
        text_box2.text(text_box1.text());
      };
      
      text_box2.parent(*this);
      text_box2.location({10, 50});
      text_box2.text("text box");
      text_box2.text_changed += [this](const control& sender, const xtd::event_args& e) {
        text_box1.text(text_box2.text());
      };
    }
    
  private:
    text_box text_box1;
    text_box text_box2;
  };
}

int main() {
  application::run(examples::form1());
}
