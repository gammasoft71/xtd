#include <xtd/xtd>

class main_form : public form {
public:
  static auto main() {
    application::run(main_form());
  }
  
  main_form() {
    text("application and exception example");
    width(350);
    
    // Uncomment the following line to raise the exception in main entry point :
    //throw system_exception {};

    generate_handled_exception_button.auto_size(true);
    generate_handled_exception_button.location({10, 10});
    generate_handled_exception_button.parent(*this);
    generate_handled_exception_button.text("Generate handled exception");
    generate_handled_exception_button.click += event_handler {*this, &main_form::generate_handled_exception};
    
    generate_std_exception_button.auto_size(true);
    generate_std_exception_button.location({10, 50});
    generate_std_exception_button.parent(*this);
    generate_std_exception_button.text("Generate std exception");
    generate_std_exception_button.click += event_handler {*this, &main_form::generate_std_exception};
    
    generate_xtd_exception_button.auto_size(true);
    generate_xtd_exception_button.location({10, 90});
    generate_xtd_exception_button.parent(*this);
    generate_xtd_exception_button.text("Generate xtd exception");
    generate_xtd_exception_button.click += event_handler {*this, &main_form::generate_xtd_exception};
    
    generate_unknown_exception_button.auto_size(true);
    generate_unknown_exception_button.location({10, 130});
    generate_unknown_exception_button.parent(*this);
    generate_unknown_exception_button.text("Generate unknown exception");
    generate_unknown_exception_button.click += event_handler {*this, &main_form::generate_unknown_exception};
    
    consume_thread_exception_event_check_box.auto_size(true);
    consume_thread_exception_event_check_box.location({10, 170});
    consume_thread_exception_event_check_box.parent(*this);
    consume_thread_exception_event_check_box.text("Consume xtd::application::thread_exception event");
    consume_thread_exception_event_check_box.checked_changed += event_handler {*this, &main_form::consume_thread_exception_event};
  }
  
private:
  void consume_thread_exception_event() {
    if (consume_thread_exception_event_check_box.checked()) application::thread_exception += thread_exception_event_handler {*this, &main_form::on_thread_exception};
    else application::thread_exception -= thread_exception_event_handler {*this, &main_form::on_thread_exception};
  }
  
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
  
  void on_thread_exception(object& sender, const thread_exception_event_args& e) {
    diagnostics::debug::write_line(e.exception());
    application::exit();
  };

  button generate_handled_exception_button;
  button generate_std_exception_button;
  button generate_xtd_exception_button;
  button generate_unknown_exception_button;
  check_box consume_thread_exception_event_check_box;
};

startup_(main_form::main);
