#include <xtd/xtd>

using namespace xtd::forms;

class dialog : public form {
public:
  dialog() {
    accept_button(ok_button);
    client_size({195, 75});
    minimize_box(false);
    text("Dialog");

    ok_button.dialog_result(dialog_result::ok);
    ok_button.location({60, 40});
    ok_button.parent(*this);
    ok_button.text(texts::ok());
  }
  
public:
  button ok_button;
};

int main() {
  form form;
  form.text("Dialog example");
  
  button button;
  button.location({10, 10});
  button.parent(form);
  button.text("Dialog...");
  button.click += [&] {
    dialog().show_dialog(form);
  };

  application::run(form);
}
