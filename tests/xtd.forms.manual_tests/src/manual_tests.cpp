#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    close_button.parent(*this);
    close_button.location({10, 10});
    close_button.text("Close");
    close_button.click += [&] {
      child_form.close();
    };

    show_button.parent(*this);
    show_button.location({10, 40});
    show_button.text("Show");
    show_button.click += [&] {
      child_form.show();
    };

    hide_button.parent(*this);
    hide_button.location({10, 70});
    hide_button.text("Hide");
    hide_button.click += [&] {
      child_form.hide();
    };

    child_form.text(ustring::format("child form instance {}", instance));
    child_form.size({250, 100});
    child_form.form_closed += [&] {
      child_form.text(ustring::format("child form instance {}", ++instance));
    };
  }

private:
  button close_button;
  button show_button;
  button hide_button;
  form child_form;
  int instance = 1;
};

int main() {
  application::run(form1());
}

