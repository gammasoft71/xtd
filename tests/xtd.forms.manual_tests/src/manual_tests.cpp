#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  form form1;
  button button1;
  button1.parent(form1);
  button1.location({10, 10});
  button1.text("dialog");
  button1.click += [&] {
    form dialog;
    dialog.form_closed += [&] {
      dialog.dialog_result(dialog_result::yes);
    };
    cdebug << format("result = {}", dialog.show_dialog()) << endl;
  };
  //application::run(form1);
  form1.show_dialog();
}

/*
#include <xtd/diagnostics/cdebug.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/form.hpp>

using namespace xtd::forms;
using namespace xtd::forms::native;

int main() {
  application::start_application();
  
  create_params cp;
  cp.class_name("form");
  cp.caption("Form");
  intptr_t f = control::create(cp);
  control::visible(f, true);
  application::main_form(f);
  application::run();

  application::end_application();
}
*/
