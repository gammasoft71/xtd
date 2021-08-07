#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class user_input_dialog : public form {
public:
  user_input_dialog() {
    accept_button(button_ok);
    cancel_button(button_cancel);
    client_size({200, 80});
    form_border_style(forms::form_border_style::fixed_dialog);
    control_box(false);
    minimize_box(false);
    maximize_box(false);
    show_icon(false);
    start_position(form_start_position::center_parent);
    text("User input dialog");
    controls().push_back_range({input, button_ok, button_cancel});

    input.location({10, 10});
    input.width(180);

    button_cancel.dialog_result(forms::dialog_result::cancel);
    button_cancel.location({10, 50});
    button_cancel.text("Cancel");
    button_cancel.width(85);

    button_ok.dialog_result(forms::dialog_result::ok);
    button_ok.location({105, 50});
    button_ok.text("OK");
    button_ok.width(85);

    active_control(input);
  }
  
  virtual ustring input_text() const {return input.text();}
  virtual user_input_dialog& input_text(const ustring& input_text) {
    input.text(input_text);
    return *this;
  }

private:
  text_box input;
  button button_cancel;
  button button_ok;
};

class form1 : public form {
public:
  form1() {
    controls().push_back_range({button_dialog, input_text});
    size({800, 450});
    text("User dialog exemple");
    
    input_text.auto_size(true);
    input_text.location({10, 50});
    input_text.text("User input text");
    
    button_dialog.location({10, 10});
    button_dialog.text("Dialog...");
    button_dialog.click += [&] {
      dialog.input_text(input_text.text());
      if (dialog.show_dialog(*this) == forms::dialog_result::ok)
        input_text.text(dialog.input_text());
    };
  }
  
private:
  user_input_dialog dialog;
  button button_dialog;
  label input_text;
};

int main() {
  application::run(form1());
}
