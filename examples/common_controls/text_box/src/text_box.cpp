#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Text box example");

      text_box1.parent(*this);
      text_box1.location({10, 10});
      text_box1.text_changed += [&] {
        text_box2.text(text_box1.text());
      };
      text_box1.text("text box");

      text_box2.parent(*this);
      text_box2.location({10, 50});
      text_box2.cursor(cursors::ibeam());
      text_box2.text_changed += [&] {
        text_box1.text(text_box2.text());
      };
      
      active_control(text_box2);
    }
    
  private:
    text_box text_box1;
    text_box text_box2;
  };
}

int main() {
  application::enable_light_mode();
  application::run(examples::form1());
}
