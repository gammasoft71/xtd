#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace manual_test {
  class form1 : public form {
  public:
    form1() {
      text("Manual test");
      controls().push_back(button1);

      button1.location({10, 10});
      button1.text("Color...");
      button1.click += [this] {
        color_dialog color_dialog;
        color_dialog.alpha_color(false);
        color_dialog.color(this->back_color());
        forms::dialog_result dialog_result = color_dialog.show_dialog();
        if (dialog_result == forms::dialog_result::ok)
          this->back_color(color_dialog.color());
      };
    }
    
  private:
    button button1;
  };
}

int main() {
  application::run(manual_test::form1());
}
