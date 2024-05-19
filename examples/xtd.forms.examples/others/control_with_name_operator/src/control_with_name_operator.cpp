#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>

using namespace xtd;
using namespace xtd::forms;

namespace control_with_name_operator_example {
  class main_form : public form {
  public:
    main_form() {
      controls().push_back_range({button1, label1});
      button1.name("button1");
      label1.name("label1");
      
      controls()["button1"].value().get().location({10, 10});
      controls()["button1"].value().get().text("Click me");
      as<button>(controls()["button1"].value().get()).auto_repeat(true);
      controls()["button1"].value().get().click += [&] {
        static int count = 0;
        controls()["label1"].value().get().text(ustring::format("button clicked {} times", ++count));
      };

      controls()["label1"].value().get().auto_size(true);
      controls()["label1"].value().get().location({10, 50});
      controls()["label1"].value().get().text("button clicked 0 times");
    }
    
  private:
    button button1;
    label label1;
  };
}

auto main() -> int {
  xtd::forms::application::run(control_with_name_operator_example::main_form {});
}
