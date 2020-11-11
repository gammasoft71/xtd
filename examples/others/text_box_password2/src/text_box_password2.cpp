#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Text box password example");
      *this << text_box1 << label1;
      active_control(text_box1);

      text_box1.location({10, 10});
      text_box1.password_char('@');
      text_box1.text_changed += [&] {
        label1.text(text_box1.text());
      };
      text_box1.text("123456");

      label1.location({10, 50});
      label1.auto_size(true);
    }
    
  private:
    text_box text_box1;
    label label1;
  };
}

int main() {
  application::run(examples::form1());
}
