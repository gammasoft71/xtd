#define DEBUG
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/debug_form>
#include <xtd/forms/debug_message_box>
#include <xtd/forms/form>
#include <xtd/startup>

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
  
  static auto main() {
    debug_form debug_form;
    application::run(form_main {});
  }
  
private:
  button button_;
};

startup_(form_main);
