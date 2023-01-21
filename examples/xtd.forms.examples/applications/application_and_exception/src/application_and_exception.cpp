#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class main_form : public form {
public:
  static auto main() {
    application::run(main_form());
  }
  
  main_form() {
    text("application and exception example");
    
    // uncomment next line to throw error and catch it in main entry point
    //throw system_exception(current_stack_frame_);
    
    generate_handled_exception_button.auto_size(true);
    generate_handled_exception_button.location({10, 10});
    generate_handled_exception_button.parent(*this);
    generate_handled_exception_button.text("Generate handled exception");
    generate_handled_exception_button.click += event_handler(*this, &main_form::generate_handled_exception);
    
    generate_exception_button.auto_size(true);
    generate_exception_button.location({10, 50});
    generate_exception_button.parent(*this);
    generate_exception_button.text("Generate exception");
    generate_exception_button.click += event_handler(*this, &main_form::generate_exception);
    
    generate_system_exception_button.auto_size(true);
    generate_system_exception_button.location({10, 90});
    generate_system_exception_button.parent(*this);
    generate_system_exception_button.text("Generate system exception");
    generate_system_exception_button.click += event_handler(*this, &main_form::generate_system_exception);
    
    generate_unknown_exception_button.auto_size(true);
    generate_unknown_exception_button.location({10, 130});
    generate_unknown_exception_button.parent(*this);
    generate_unknown_exception_button.text("Generate unknown exception");
    generate_unknown_exception_button.click += event_handler(*this, &main_form::generate_unknown_exception);
  }
  
private:
  auto generate_handled_exception()->void {
    try {
      throw operation_canceled_exception(current_stack_frame_);
    } catch (const xtd::system_exception& e) {
      message_box::show(*this, e.message(), ustring::format("Exception {} handled", e.name()));
    }
  }
  auto generate_exception()->void {throw invalid_argument("Invalid argument");}
  auto generate_system_exception()->void {throw argument_out_of_range_exception(current_stack_frame_);}
  auto generate_unknown_exception()->void {throw "Unknown exception occured";}
  
  button generate_handled_exception_button;
  button generate_exception_button;
  button generate_system_exception_button;
  button generate_unknown_exception_button;
};

startup_(main_form);
