#include <xtd/diagnostics/debugger>
#include <xtd/forms/application>
#include <xtd/forms/assert_dialog>
#include <xtd/forms/button>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Assert dialog example");
    controls().push_back(button1);
    
    button1.location({10, 10});
    button1.auto_size(true);
    button1.text("assert...");
    button1.click += [&] {
      auto dialog = assert_dialog {};
      dialog.message("Index must be > 0");
      switch(dialog.show_sheet_dialog(*this)) {
        case forms::dialog_result::abort: application::exit(); break;
        case forms::dialog_result::retry: debugger::debug_break(); break;
        default: break;
      }
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  application::run(form1 {});
}
