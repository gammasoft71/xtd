#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

class main_form : public form {
public:
  main_form() {
    text("application and exception example");
    
    // uncomment to throw error
    //throw overflow_error("Creattion object error");
    
    generate_handled_exception_button.auto_size(true);
    generate_handled_exception_button.location({10, 10});
    generate_handled_exception_button.parent(*this);
    generate_handled_exception_button.text("Generate handled exception");
    generate_handled_exception_button.click += {*this, &main_form::generate_handled_exception};

    generate_exception_button.auto_size(true);
    generate_exception_button.location({10, 40});
    generate_exception_button.parent(*this);
    generate_exception_button.text("Generate exception");
    generate_exception_button.click += {*this, &main_form::generate_exception};

    generate_system_exception_button.auto_size(true);
    generate_system_exception_button.location({10, 70});
    generate_system_exception_button.parent(*this);
    generate_system_exception_button.text("Generate system exception");
    generate_system_exception_button.click += {*this, &main_form::generate_system_exception};

    generate_unknown_exception_button.auto_size(true);
    generate_unknown_exception_button.location({10, 100});
    generate_unknown_exception_button.parent(*this);
    generate_unknown_exception_button.text("Generate unknown exception");
    generate_unknown_exception_button.click += {*this, &main_form::generate_unknown_exception};
  }
  
private:
  void generate_handled_exception() {
    try {
      throw system_exception("Exception handled generated", caller_info_);
    } catch(const xtd::system_exception& e) {
      message_box::show(*this, e.message(), strings::format("Exception {} handled", e.name()));
    }
  }
  void generate_exception() {throw invalid_argument("Exception generated");}
  void generate_system_exception() {throw argument_out_of_range_exception("System exception generated", caller_info_);}
  void generate_unknown_exception() {throw "Unknown exception generated";}
  
  button generate_handled_exception_button;
  button generate_exception_button;
  button generate_system_exception_button;
  button generate_unknown_exception_button;
};

int main() {
  try {
    application::run(main_form());
  } catch(const system_exception& e) {
    debug::write_line(e);
    message_box::show(e.to_string(), strings::format("Exception {} occured", strings::class_name(e)), message_box_buttons::ok, message_box_icon::error);
  } catch(const exception& e) {
    debug::write_line(e);
    message_box::show(strings::format("Message : {}", e.what()), strings::format("Exception {} occured", strings::class_name(e)), message_box_buttons::ok, message_box_icon::error);
  } catch(...) {
    debug::write_line("Unknown exception occured");
    message_box::show("(Unknown exception)", "Unknown exception occured", message_box_buttons::ok, message_box_icon::error);
  }
}
