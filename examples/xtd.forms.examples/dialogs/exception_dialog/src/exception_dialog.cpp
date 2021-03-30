#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Exception dialog example");
    controls().push_back(button1);

    button1.location({10, 10});
    button1.auto_size(true);
    button1.text("Exception...");
    button1.click += [&] {
      exception_dialog dialog;
      dialog.exception(exception);
      if (dialog.show_dialog() == dialog_result::cancel)
        application::exit();
    };
  }
  
private:
  button button1;
  invalid_operation_exception exception {"Dialog exception example"};
};

int main() {
  application::run(form1());
}
