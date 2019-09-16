#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class user_input_dialog : public form {
public:
  user_input_dialog() {
    this->client_size({200, 80});
    this->start_position(form_start_position::center_parent);
    this->text("Input dialog");
    this->controls().push_back_range({this->input, this->button_ok, this->button_cancel});

    this->input.location({10, 10});
    this->input.width(180);

    this->button_ok.dialog_result(forms::dialog_result::ok);
    this->button_ok.location({10, 50});
    this->button_ok.text("OK");

    this->button_cancel.dialog_result(forms::dialog_result::cancel);
    this->button_cancel.location({110, 50});
    this->button_cancel.text("Cancel");
  }
  
  virtual std::string input_text() const {return this->input.text();}
  virtual user_input_dialog& input_text(const std::string& input_text) {
    this->input.text(input_text);
    return *this;
  }

private:
  text_box input;
  button button_ok;
  button button_cancel;
};

class form1 : public form {
public:
  form1() {
    this->controls().push_back_range({this->button_dialog, this->input_text});
    this->start_position(form_start_position::center_screen);
    this->size({800, 450});
    this->text("User dialog exemple");
    
    this->input_text.auto_size(true);
    this->input_text.location({10, 50});
    this->input_text.text("User input text");
    
    this->button_dialog.text("Dialog...");
    this->button_dialog.location({10, 10});
    this->button_dialog.click += [&] {
      user_input_dialog dialog;
      dialog.input_text(this->input_text.text());
      if (dialog.show_dialog() == forms::dialog_result::ok)
        this->input_text.text(dialog.input_text());
    };
  }
  
private:
  button button_dialog;
  label input_text;
};

int main() {
  application::run(form1());
}
