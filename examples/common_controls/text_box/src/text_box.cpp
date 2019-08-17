#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Text box example");

      this->text_box1.parent(*this);
      this->text_box1.location({10, 10});
      this->text_box1.text_changed += [&](const control& sender, const xtd::event_args& e) {
        this->text_box2.text(text_box1.text());
      };

      this->text_box2.parent(*this);
      this->text_box2.border_style(border_style::none);
      this->text_box2.location({10, 50});
      this->text_box2.text_changed += [&](const control& sender, const xtd::event_args& e) {
        this->text_box1.text(text_box2.text());
      };
      this->text_box2.text("text box");
    }
    
  private:
    text_box text_box1;
    text_box text_box2;
  };
}

int main() {
  application::run(examples::form1());
}
