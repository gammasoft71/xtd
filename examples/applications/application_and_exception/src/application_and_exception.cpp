#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class main_form : public form {
public:
  main_form() {
    text("application and exception example");
    
    // uncomment to throw error
    // throw overflow_error("Creattion object error");
    
    generate_handled_exception_button.auto_size(true);
    generate_handled_exception_button.location({10, 10});
    generate_handled_exception_button.parent(*this);
    generate_handled_exception_button.text("Generate handled exception");
    generate_handled_exception_button.click += [] {
      try {
        throw invalid_argument("Not a valid argument");
      } catch(const exception& e) {
        // do something on exception...
      }
    };

    generate_exception_button.auto_size(true);
    generate_exception_button.location({10, 40});
    generate_exception_button.parent(*this);
    generate_exception_button.text("Generate exception");
    generate_exception_button.click += [] {
      throw invalid_argument("Not a valid argument");
    };
    
    generate_unknown_exception_button.auto_size(true);
    generate_unknown_exception_button.location({10, 70});
    generate_unknown_exception_button.parent(*this);
    generate_unknown_exception_button.text("Generate unknown exception");
    generate_unknown_exception_button.click += [] {
      throw "throw unknown type exception";
    };
  }
private:
  button generate_handled_exception_button;
  button generate_exception_button;
  button generate_unknown_exception_button;
};

int main() {
  try {
    application::run(main_form());
  } catch(const exception& e) {
    message_box::show(strings::format("Message : {}", e.what()), strings::format("Exception {} occured", strings::class_name(e)), message_box_buttons::ok, message_box_icon::error);
  } catch(...) {
    message_box::show("Message : (none)", "Unknown exception occured", message_box_buttons::ok, message_box_icon::error);
  }
}
