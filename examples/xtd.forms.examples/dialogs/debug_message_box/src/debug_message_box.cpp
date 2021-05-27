#include <xtd/xtd>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms;

class form_main : public form {
public:
  form_main() {
    button_.parent(*this);
    button_.location({10, 10});
    button_.text("Error...");
    button_.click += [&] {
      debug_message_box::show(*this, "An unknown process error occured.");
    };
  }
  
  static void main() {
    debug_form debug_form;
    xtd::forms::application::run(form_main());
  }
private:
  button button_;
};

startup_(form_main);
