#include <xtd/xtd>

class main_form : public form {
public:
  static auto main() {
    application::thread_exception += thread_exception_event_handler {&main_form::on_thread_exception};
    application::run(main_form());
  }
  
  main_form() {
    text("application::thread_exception event example");
    
    generate_exception_button.auto_size(true);
    generate_exception_button.click += delegate_ {throw argument_out_of_range_exception {};};
  }
  
private:
  static void on_thread_exception(object& sender, const thread_exception_event_args& e) {
    auto result = show_thread_exception_dialog("Fatal Windows Forms Error", e.exception());
    if (result == forms::dialog_result::abort) application::exit();
  };
  
  static forms::dialog_result show_thread_exception_dialog(const string& title, const std::exception& e) {
    auto error_msg = "An application error occurred. Please contact the adminstrator with the following information:\n\n"_s;
    if (is<exception>(e)) error_msg = error_msg + as<exception>(e).message() + (is<exception>(e) ? "\n\nStack Trace:\n" + as<exception>(e).stack_trace() : "");
    else error_msg = error_msg + e.what();
    return message_box::show(error_msg, title, message_box_buttons::abort_retry_ignore, message_box_icon::stop);
  }

  button generate_exception_button = button::create(self_, "Generate exception", {10, 10});
};

startup_(main_form::main);
