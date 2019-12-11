#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace std::literals;

int main() {
  main_menu menu;
  
  menu.menu_items().push_back("File");
  menu.menu_items().push_back("Edit");
  menu.menu_items().push_back("View");
  
  background_worker worker;
  worker.worker_supports_cancellation(true);
  worker.worker_reports_progress(true);
  worker.do_work += [&](component& sender, do_work_event_args& e){
    for (int progress = 1; progress <= 100; progress++) {
      if (worker.cancellation_pending()) break;
      std::this_thread::sleep_for(100ms);
      worker.report_progress(progress);
      cdebug << format("progress {} / 100", progress) << std::endl;
    }
  };

  button button_run;
  button_run.location({10, 10});
  button_run.text("Run");
  
  button button_cancel;
  button_cancel.location({215, 10});
  button_cancel.text("Cancel");
  button_cancel.enabled(false);

  progress_bar progress;
  progress.location({10, 50});
  progress.width(280);
  progress.set_range(0, 100);

  button_run.click += [&] {
    progress.value(0);
    button_cancel.enabled(true);
    button_run.enabled(false);
    worker.run_worker_async();
  };
  
  button_cancel.click += [&] {
    button_run.enabled(true);
    button_cancel.enabled(false);
    if (worker.is_busy())
      worker.cancel_async();
  };
  
  worker.progress_changed += [&](component& sender, const progress_changed_event_args& e) {
    progress.value(e.progress_percentage());
  };
  
  form form_main;
  form_main.controls().push_back_range({button_run, button_cancel, progress});
  form_main.text("Manual tests");
  //form_main.menu(menu);
  form_main.client_size({300, 95});
  form_main.form_closed += [&] {
    if (worker.is_busy())
      worker.cancel_async();
  };

  application::run(form_main);
}
