#define TRACE 1 // Force to trace even if example is builded with -DNTRACE.
#include <xtd/xtd>

auto main() -> int {
  auto df = debug_form {};
  
  form form1;
  button button1;
  button1.auto_size(true);
  button1.location({10, 10});
  button1.text("show dialog");
  button1.parent(form1);
  button1.click += delegate_ {
    form dialog;
    dialog.text("dialog");
    dialog.client_size({200, 100});
    dialog.show_dialog();
  };
  
  application::application_exit += delegate_ {
    diagnostics::trace::write_line("Application exit");
  };
  
  application::enter_thread_modal += delegate_ {
    diagnostics::trace::write_line("Enter thread modal");
  };
  
  application::idle += delegate_ {
    static auto cpt = 0;
    diagnostics::trace::write_line(string::format("Idle [{}]...", ++cpt));
  };
  
  application::leave_thread_modal += delegate_ {
    diagnostics::trace::write_line("Leave thread modal");
  };
  
  application::thread_exit += delegate_ {
    diagnostics::trace::write_line("Thread exit");
  };
  
  application::run(form1);
}
