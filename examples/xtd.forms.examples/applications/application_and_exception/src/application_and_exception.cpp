#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/message_box>
#include <xtd/operation_canceled_exception>
#include <xtd/startup>
#include <stdexcept>

using namespace xtd;
using namespace xtd::forms;

class main_form : public form {
public:
  static auto main() {
    application::run(main_form());
  }
  
  main_form() {
    text("application and exception example");
    
    // Uncomment the following line to raise the exception in main entry point :
    //throw system_exception {};
    
    generate_handled_exception_button.auto_size(true);
    generate_handled_exception_button.location({10, 10});
    generate_handled_exception_button.parent(*this);
    generate_handled_exception_button.text("Generate handled exception");
    generate_handled_exception_button.click += event_handler(*this, &main_form::generate_handled_exception);
    
    generate_std_exception_button.auto_size(true);
    generate_std_exception_button.location({10, 50});
    generate_std_exception_button.parent(*this);
    generate_std_exception_button.text("Generate std exception");
    generate_std_exception_button.click += event_handler(*this, &main_form::generate_std_exception);
    
    generate_xtd_exception_button.auto_size(true);
    generate_xtd_exception_button.location({10, 90});
    generate_xtd_exception_button.parent(*this);
    generate_xtd_exception_button.text("Generate xtd exception");
    generate_xtd_exception_button.click += event_handler(*this, &main_form::generate_xtd_exception);
    
    generate_unknown_exception_button.auto_size(true);
    generate_unknown_exception_button.location({10, 130});
    generate_unknown_exception_button.parent(*this);
    generate_unknown_exception_button.text("Generate unknown exception");
    generate_unknown_exception_button.click += event_handler(*this, &main_form::generate_unknown_exception);
  }
  
private:
  void generate_handled_exception() {
    try {
      throw operation_canceled_exception {};
    } catch (const system_exception& e) {
      message_box::show(*this, e.message(), string::format("Exception {} handled", e.get_type().full_name()));
    }
  }
  void generate_std_exception() {throw std::invalid_argument("Invalid argument");}
  void generate_xtd_exception() {throw argument_out_of_range_exception {};}
  void generate_unknown_exception() {throw "Unknown exception occured";}

  button generate_handled_exception_button;
  button generate_std_exception_button;
  button generate_xtd_exception_button;
  button generate_unknown_exception_button;
};

startup_(main_form::main);
