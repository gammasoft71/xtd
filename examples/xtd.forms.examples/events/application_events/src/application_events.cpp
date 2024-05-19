#define TRACE
#include <xtd/diagnostics/trace>
#include <xtd/forms/application>
#include <xtd/forms/debug_form>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

auto main() -> int {
  auto df = debug_form {};
  
  form form1;
  button button1;
  button1.auto_size(true);
  button1.location({10, 10});
  button1.text("show dialog");
  button1.parent(form1);
  button1.click += [] {
    form dialog;
    dialog.text("dialog");
    dialog.client_size({200, 100});
    dialog.show_dialog();
  };
  
  application::application_exit += [] {
    trace::write_line("Application exit");
  };
  
  application::enter_thread_modal += [] {
    trace::write_line("Enter thread modal");
  };
  
  application::idle += [] {
    static auto cpt = 0;
    trace::write_line(ustring::format("Idle [{}]...", ++cpt));
  };
  
  application::leave_thread_modal += [] {
    trace::write_line("Leave thread modal");
  };
  
  application::thread_exit += [] {
    trace::write_line("Thread exit");
  };
  
  application::run(form1);
}
