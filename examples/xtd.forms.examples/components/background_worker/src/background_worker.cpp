#include <chrono>
#include <thread>
#include <xtd/xtd>

using namespace std::literals;
using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Background worker example");
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      auto_size(true);
      controls().push_back_range({panel_command, progress});
      form_closed += [&] {
        if (worker.is_busy())
          worker.cancel_async();
      };
      
      panel_command.parent(*this);
      panel_command.size({300, 80});
      panel_command.controls().push_back_range({button_run, button_cancel, status});
      
      panel_progress.parent(*this);
      panel_progress.top(80);
      panel_progress.size({300, 155});
      panel_progress.controls().push_back_range({progress, list_progress});
      panel_progress.visible(false);

      button_run.location({10, 10});
      button_run.text("Run");
      button_run.click += [&] {
        panel_progress.visible(true);
        button_cancel.enabled(true);
        button_run.enabled(false);
        worker.run_worker_async();
        if (worker.is_busy())
          status.text("Status : running");
      };
      
      button_cancel.location({215, 10});
      button_cancel.text("Cancel");
      button_cancel.enabled(false);
      button_cancel.click += [&] {
        button_cancel.enabled(false);
        worker.cancel_async();
      };
      
      status.location({10, 50});
      status.auto_size(true);
      status.text("Status : not started");

      progress.location({10, 10});
      progress.width(280);
      
      list_progress.location({10, 45});
      list_progress.size({280, 100});
      list_progress.multiline(true);
      list_progress.read_only(true);
      list_progress.word_wrap(false);

      worker.worker_supports_cancellation(true);
      worker.worker_reports_progress(true);
      worker.do_work += [&] {
        for (auto step = 1; step <= progress.maximum(); step++) {
          if (worker.cancellation_pending()) break; // stop work...
          std::this_thread::sleep_for(100ms); // simulate work...
          worker.report_progress(step, strings::format("step {} / {}", step, progress.maximum()));
        }
      };
      
      worker.progress_changed += [&](object& sender, const progress_changed_event_args& e) {
        progress.value(e.progress_percentage());
        list_progress.append_text(strings::format("{}{}", std::any_cast<std::string>(e.user_state()), environment::new_line()));
      };
      
      worker.run_worker_completed += [&](object& sender, const run_worker_completed_event_args& e){
        panel_progress.visible(false);
        button_run.enabled(true);
        button_cancel.enabled(false);
        progress.value(0);
        list_progress.text("");
        status.text(strings::format("Status : {}", e.cancel() ? "canceled" : "completed"));
      };
    }
    
  private:
    panel panel_command;
    panel panel_progress;
    button button_run;
    button button_cancel;
    label status;
    progress_bar progress;
    text_box list_progress;
    background_worker worker;
  };
}

int main() {
  application::run(examples::form1());
}
