#define TRACE
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/trace_form>
#include <xtd/forms/trace_message_box>
#include <xtd/startup>

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
      trace_message_box::show(*this, "An unknown process error occured.");
    };
  }
  
  static auto main() {
    auto tf = trace_form {};
    xtd::forms::application::run(form_main());
  }
private:
  button button_;
};

startup_(form_main);
