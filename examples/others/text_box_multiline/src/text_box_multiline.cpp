#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Text box multiline example");
      client_size({300, 300});
      *this << text_box1 << text_box2;

      text_box1.location({10, 10});
      text_box1.multiline(true);
      text_box1.size({280, 130});
      text_box1.text_changed += [&] {
        text_box2.text(text_box1.text());
      };
      text_box1.text("Line 1\nLine 2\nLine 3\n...");

      text_box2.location({10, 150});
      text_box2.word_wrap(true);
      text_box2.multiline(true);
      text_box2.size({280, 130});
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
  application::run(examples::form1());
}
