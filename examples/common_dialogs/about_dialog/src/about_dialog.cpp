#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("About dialog example");
    controls().push_back(button1);

    button1.location({10, 10});
    button1.text("About...");
    button1.click += [&] {
      about_dialog about_dialog;
      about_dialog.name("About dialog");
      about_dialog.version("1.0");
      about_dialog.long_version("1.0.0");
      about_dialog.description("About dialog description.");
      about_dialog.copyright("Copyright (c) 2019 Gammasoft.\nAll rights reserved.");
      about_dialog.show();
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(form1());
}
