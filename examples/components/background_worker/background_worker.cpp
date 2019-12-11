#include <chrono>
#include <thread>
#include <xtd/xtd.forms>

using namespace std::literals;
using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Background worker example");
      client_size({300, 105});
      controls().push_back_range({button_run, button_cancel, progress, status});
      form_closed += [this] {
        button_cancel.enabled(true);
        if (worker.is_busy())
          worker.cancel_async();
      };

      button_run.location({10, 10});
      button_run.text("Run");
      button_run.click += [this] {
        button_cancel.enabled(true);
        button_run.enabled(false);
        worker.run_worker_async();
        if (worker.is_busy())
          status.text("Status : running");
      };
      
      button_cancel.location({215, 10});
      button_cancel.text("Cancel");
      button_cancel.enabled(false);
      button_cancel.click += [this] {
        button_cancel.enabled(false);
        worker.cancel_async();
      };
      
      progress.location({10, 50});
      progress.width(280);
      progress.set_range(0, 100);
      
      status.location({10, 80});
      status.auto_size(true);
      status.text("Status : ");

      worker.worker_supports_cancellation(true);
      worker.worker_reports_progress(true);
      worker.do_work += [this](component& sender, do_work_event_args& e){
        for (int progress = 1; progress <= 100; progress++) {
          if (worker.cancellation_pending()) break; // stop work...
          std::this_thread::sleep_for(100ms); // simulate work...
          worker.report_progress(progress);
          cdebug << format("progres s {} / 100", progress) << std::endl;
        }
      };
      
      worker.progress_changed += [this](component& sender, const progress_changed_event_args& e) {
        progress.value(e.progress_percentage());
      };
      
      worker.run_worker_completed += [this](component& sender, const run_worker_completed_event_args& e){
        button_run.enabled(true);
        button_cancel.enabled(false);
        progress.value(0);
        if (e.cancel())
          status.text("Status : canceled");
        else
          status.text("Status : completed");
      };
    }
    
  private:
    button button_run;
    button button_cancel;
    progress_bar progress;
    label status;
    background_worker worker;
  };
}

int main() {
  application::run(examples::form1());
}
