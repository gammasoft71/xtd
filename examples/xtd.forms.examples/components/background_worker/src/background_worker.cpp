#include <xtd/forms/application>
#include <xtd/forms/background_worker>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/panel>
#include <xtd/forms/progress_bar>
#include <xtd/forms/text_box>
#include <xtd/threading/thread>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::threading;

namespace background_worker_example {
  class form1 : public form {
  public:
    static void main() {
      application::run(background_worker_example::form1 {});
    }

    form1() {
      text("Background worker example");
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      auto_size(true);
      form_closed += [&] {
        cancel_button.perform_click();
      };
      
      command_panel.parent(*this);
      command_panel.size({300, 80});
      command_panel.controls().push_back_range({run_button, cancel_button, status});
      
      progress_panel.parent(*this);
      progress_panel.top(80);
      progress_panel.size({300, 155});
      progress_panel.controls().push_back_range({progress, progress_text});
      progress_panel.visible(false);
      
      run_button.location({10, 10});
      run_button.text("Run");
      run_button.click += [&] {
        progress_panel.visible(true);
        cancel_button.enabled(true);
        run_button.enabled(false);
        worker.run_worker_async();
        if (worker.is_busy())
          status.text("Status : running");
      };
      
      cancel_button.location({215, 10});
      cancel_button.text("Cancel");
      cancel_button.enabled(false);
      cancel_button.click += [&] {
        cancel_button.enabled(false);
        worker.cancel_async();
      };
      
      status.location({10, 50});
      status.auto_size(true);
      status.text("Status : not started");
      
      progress.location({10, 10});
      progress.width(280);
      
      progress_text.location({10, 45});
      progress_text.size({280, 100});
      progress_text.multiline(true);
      progress_text.read_only(true);
      progress_text.word_wrap(false);
      
      worker.worker_supports_cancellation(true);
      worker.worker_reports_progress(true);
      worker.do_work += [&] {
        for (auto step = 1; step <= progress.maximum(); ++step) {
          if (worker.cancellation_pending()) break; // stop work...
          thread::sleep(100_ms); // simulate work...
          worker.report_progress(step, ustring::format("step {} / {}", step, progress.maximum()));
        }
      };
      
      worker.progress_changed += [&](object & sender, const progress_changed_event_args & e) {
        progress.value(e.progress_percentage());
        progress_text.append_text(ustring::format("{}{}", std::any_cast<ustring>(e.user_state()), environment::new_line()));
      };
      
      worker.run_worker_completed += [&](object & sender, const run_worker_completed_event_args & e) {
        progress_panel.visible(false);
        run_button.enabled(true);
        cancel_button.enabled(false);
        progress.value(0);
        progress_text.text("");
        status.text(ustring::format("Status : {}", e.cancel() ? "canceled" : "completed"));
      };
    }
    
  private:
    panel command_panel;
    panel progress_panel;
    button run_button;
    button cancel_button;
    label status;
    progress_bar progress;
    text_box progress_text;
    background_worker worker;
  };
}

startup_(background_worker_example::form1::main);
