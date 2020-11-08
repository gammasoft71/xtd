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
        throw system_exception("Generate handled exception");
      } catch(const exception& e) {
        // do something on exception...
      }
    };

    generate_exception_button.auto_size(true);
    generate_exception_button.location({10, 40});
    generate_exception_button.parent(*this);
    generate_exception_button.text("Generate exception");
    generate_exception_button.click += [] {
      throw invalid_argument("Generate exception");
    };

    generate_system_exception_button.auto_size(true);
    generate_system_exception_button.location({10, 70});
    generate_system_exception_button.parent(*this);
    generate_system_exception_button.text("Generate system exception");
    generate_system_exception_button.click += [] {
      throw system_exception("Generate system exception", caller_info_);
    };

    generate_unknown_exception_button.auto_size(true);
    generate_unknown_exception_button.location({10, 100});
    generate_unknown_exception_button.parent(*this);
    generate_unknown_exception_button.text("Generate unknown exception");
    generate_unknown_exception_button.click += [] {
      throw "Generate unknown exception";
    };
  }
private:
  button generate_handled_exception_button;
  button generate_exception_button;
  button generate_system_exception_button;
  button generate_unknown_exception_button;
};

int main() {
  try {
    application::run(main_form());
  } catch(const system_exception& e) {
    message_box::show(e.to_string(), strings::format("Exception {} occured", strings::class_name(e)), message_box_buttons::ok, message_box_icon::error);
  } catch(const exception& e) {
    message_box::show(strings::format("Message : {}", e.what()), strings::format("Exception {} occured", strings::class_name(e)), message_box_buttons::ok, message_box_icon::error);
  } catch(...) {
    message_box::show("Message : (none)", "Unknown exception occured", message_box_buttons::ok, message_box_icon::error);
  }
}
