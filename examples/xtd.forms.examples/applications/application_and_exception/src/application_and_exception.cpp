#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class main_form : public form {
public:
  static void main() {
    application::run(main_form());
  }
  
  main_form() {
    text("application and exception example");
    
    // uncomment next line to throw error and catch it in main entry point
    //throw system_exception(caller_info_);

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
      throw operation_canceled_exception(caller_info_);
    } catch(const xtd::system_exception& e) {
      message_box::show(*this, e.message(), strings::format("Exception {} handled", e.name()));
    }
  }
  void generate_exception() {throw invalid_argument("Invalid argument");}
  void generate_system_exception() {throw argument_out_of_range_exception(caller_info_);}
  void generate_unknown_exception() {throw "Unknown exception occured";}
  
  button generate_handled_exception_button;
  button generate_exception_button;
  button generate_system_exception_button;
  button generate_unknown_exception_button;
};

startup_(main_form);
