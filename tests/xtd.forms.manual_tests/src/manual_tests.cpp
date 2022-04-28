#include <xtd/xtd.forms.h>
#include <xtd/forms/style_sheets/style_sheet.h>
#include <xtd/forms/button_renderer.h>
#include <xtd/forms/text_renderer.h>

using namespace std::chrono;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    close_button.parent(*this);
    close_button.location({10, 10});
    close_button.text("Close");
    close_button.click += [&] {
      close();
    };

    show_button.parent(*this);
    show_button.location({10, 40});
    show_button.text("Show");
    show_button.click += [&] {
      dialog->show();
    };

    hide_button.parent(*this);
    hide_button.location({10, 70});
    hide_button.text("Hide");
    hide_button.click += [&] {
      dialog->hide();
    };
  }

private:
  button close_button;
  button show_button;
  button hide_button;
  std::unique_ptr<form> dialog = control::create<form>("dialog show normal", {}, {250, 100});

};

int main() {
  application::run(form1());
}

