#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/text_box>

using namespace xtd::forms;

namespace text_box_example {
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

auto main() -> int {
  application::run(text_box_example::form1 {});
}
