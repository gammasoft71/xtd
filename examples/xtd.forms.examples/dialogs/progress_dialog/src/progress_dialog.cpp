#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/progress_dialog>
#include <xtd/threading/thread>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::threading;

class form1 : public form {
public:
  form1() {
    text("Progress dialog example");
    
    button_process.auto_size(true);
    button_process.location({10, 10});
    button_process.parent(*this);
    button_process.text("Process...");
    button_process.click += [this] {
      auto dialog = progress_dialog {};
      dialog.text("Process running");
      dialog.show_skip_button(true);
      dialog.show_remaining_time(true);
      dialog.show_dialog(*this);
      for (auto step = 1; step <= dialog.maximum(); ++step) {
        dialog.value(step);
        dialog.message(ustring::format("Step {}/{} ==> {}", dialog.value(), dialog.maximum(), dialog.skipped() ? "skipped" : "done"));
        thread::sleep(100_ms);
      }
    };
    
    button_indeterminate_process.auto_size(true);
    button_indeterminate_process.location({100, 10});
    button_indeterminate_process.parent(*this);
    button_indeterminate_process.text("Indeterminate process...");
    button_indeterminate_process.click += [this] {
      auto dialog = progress_dialog {};
      dialog.text("Indeterminate process running");
      dialog.message("Click \"Cancel\" to abort");
      dialog.marquee(true);
      dialog.show_cancel_button(true);
      dialog.show_elapsed_time(true);
      dialog.show_dialog(*this);
      while (!dialog.cancelled()) {
        application::do_events();
        thread::sleep(100_ms);
      }
    };
  }
  
private:
  button button_process;
  button button_indeterminate_process;
};

auto main() -> int {
  application::run(form1 {});
}
