#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Exception box example");
    controls().add(button1);
    
    button1.location({10, 10});
    button1.auto_size(true);
    button1.text("Exception...");
    button1.click += delegate_ {
      try {
        throw invalid_operation_exception("Throws an invalid operation exception to show an exception dialog.");
      } catch (const xtd::system_exception& e) {
        if (exception_box::show(*this, e) == dialog_result::cancel)
          application::exit();
      }
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  application::run(form1 {});
}
