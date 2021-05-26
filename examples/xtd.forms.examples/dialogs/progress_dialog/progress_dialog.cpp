#include <thread>
#include <xtd/xtd>

using namespace std::literals;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Progress dialog example");
    
    button_process.auto_size(true);
    button_process.location({10, 10});
    button_process.parent(*this);
    button_process.text("Process...");
    button_process.click += [this] {
      progress_dialog dialog;
      dialog.text("Process running");
      dialog.show_skip_button(true);
      dialog.show_remaining_time(true);
      dialog.show_sheet_dialog(*this);
      for (auto step = 1; step <= dialog.maximum(); ++step) {
        dialog.value(step);
        dialog.message(strings::format("Step {}/{} ==> {}", dialog.value(), dialog.maximum(), dialog.skipped() ? "skipped" : "done"));
        std::this_thread::sleep_for(100ms);
      }
    };
    
    button_indeterminate_process.auto_size(true);
    button_indeterminate_process.location({100, 10});
    button_indeterminate_process.parent(*this);
    button_indeterminate_process.text("Indeterminate process...");
    button_indeterminate_process.click += [this] {
      progress_dialog dialog;
      dialog.text("Indeterminate process running");
      dialog.message("Click \"Cancel\" to abort");
      dialog.marquee(true);
      dialog.show_cancel_button(true);
      dialog.show_elapsed_time(true);
      dialog.show_sheet_dialog(*this);
      while (!dialog.cancelled()) {
        application::do_events();
        std::this_thread::sleep_for(100ms);
      }
    };
  }
  
private:
  button button_process;
  button button_indeterminate_process;
};

int main() {
  application::run(form1());
}
