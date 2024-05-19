#include <xtd/drawing/system_icons>
#include <xtd/forms/application>
#include <xtd/forms/busy_dialog>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/threading/thread>

using namespace xtd::forms;
using namespace xtd::threading;

class form1 : public form {
public:
  form1() {
    text("Busy dialog example");
    
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Do something...");
    button1.click += [&] {
      auto dialog = busy_dialog {};
      dialog.icon(xtd::drawing::system_icons::exclamation({64, 64}));
      dialog.text("Application busy");
      dialog.description("Please wait while do something...");
      dialog.back_color(xtd::drawing::color::red);
      dialog.fore_color(xtd::drawing::color::white);
      dialog.opacity(0.75);
      dialog.show(*this);
      for (auto count = 0; count < 500; ++count) {
        application::do_events();
        thread::sleep(10);
      }
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  xtd::forms::application::run(form1 {});
}
