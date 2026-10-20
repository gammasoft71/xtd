#include <xtd/xtd>

namespace task_example {
  class form1 : public form {
  public:
    static void main() {
      application::run(form1 {});
    }
    
    form1() {
      text("thread example");
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      auto_size(true);
      form_closing += delegate_(auto& sender, auto& e) {
        e.cancel(worker.is_alive());
        if (e.cancel()) message_box::show(self_, "Cancel worker before cloe form", text(), message_box_buttons::ok, message_box_icon::error);
      };
      
      command_panel.parent(self_);
      command_panel.size({300, 80});
      command_panel.controls().add_range({run_button, cancel_button, status});
      
      progress_panel.parent(self_);
      progress_panel.top(80);
      progress_panel.size({300, 155});
      progress_panel.controls().add_range({progress, progress_text});
      progress_panel.visible(false);
      
      run_button.location({10, 10});
      run_button.text("Run");
      run_button.click += delegate_ {
        progress_panel.visible(true);
        cancel_button.enabled(true);
        run_button.enabled(false);
        worker = thread::start_new({self_, &form1::do_work});
        status.text("Status : running");
      };
      
      cancel_button.location({215, 10});
      cancel_button.text("Cancel");
      cancel_button.enabled(false);
      cancel_button.click += delegate_ {
        cancel_button.enabled(false);
        worker_cancellation = true;
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
    }
    
  private:
    auto do_work() -> void {
      for (auto step = 1; step <= progress.maximum(); ++step) {
        if (worker_cancellation) break; // stop work...
        thread::sleep(100_ms); // simulate work...
        progress_changed(step);
      }
      work_completed();
    }
    
    auto progress_changed(auto step) -> void {
      invoke(delegate_ {
        progress.value(step);
        progress_text.append_text(string::format("step {} / {}{}", step, progress.maximum(), environment::new_line()));
      });
    }
    
    auto work_completed() -> void {
      invoke(delegate_ {
        progress_panel.visible(false);
        run_button.enabled(true);
        cancel_button.enabled(false);
        progress.value(0);
        progress_text.text("");
        status.text(string::format("Status : {}", worker_cancellation ? "canceled" : "completed"));
        worker_cancellation = false;
      });
    }
    
    bool worker_cancellation = false;
    thread worker;
    panel command_panel;
    panel progress_panel;
    button run_button;
    button cancel_button;
    label status;
    progress_bar progress;
    text_box progress_text;
  };
}

startup_(task_example::form1::main);
