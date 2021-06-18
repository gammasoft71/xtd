#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Exception box example");
    controls().push_back(button1);

    button1.location({10, 10});
    button1.auto_size(true);
    button1.text("Exception...");
    button1.click += [&] {
      try{
        throw invalid_operation_exception("Throws an invalid operation exception to show an exception dialog.", current_stack_frame_);
      } catch(const xtd::system_exception& e) {
        if (exception_box::show(*this, e) == dialog_result::cancel)
          application::exit();
      }
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(form1());
}
