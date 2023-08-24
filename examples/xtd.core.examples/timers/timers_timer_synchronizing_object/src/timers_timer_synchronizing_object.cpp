#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/message_box>
#include <xtd/forms/save_file_dialog>
#include <xtd/forms/text_box>
#include <xtd/io/stream_writer>
#include <xtd/timers/timer>
#include <xtd/date_time>
#include <xtd/startup>
#include <memory>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::io;
using namespace xtd::timers;

namespace timer_example {
  class form1 : public form {
  public:
    static void main() {
      application::run(form1 {});
    }
    
    form1() {
      initialize_component();
      
      text("Quick Text Editor");
      button1.text("Save");
      text_box1.multiline(true);

      // Configure the SaveFile dialog
      save_file_dialog1.filter("txt files (*.txt)|*.txt|All files (*.*)|*.*");
      save_file_dialog1.restore_directory(true);
      
      // Define the event handler
      timer.elapsed += {*this, &form1::prompt_for_save};
      // Synchronize the timer with the text box
      timer.synchronizing_object(*this);
      // Start the timer
      timer.auto_reset(true);

    }
    
  private:
    void initialize_component() {
      form_closing += {*this, &form1::form1_form_closing};
      controls().push_back_range({text_box1, button1});

      button1.dock(dock_style::bottom);
      button1.click += {*this, &form1::button1_click};

      text_box1.dock(dock_style::fill);
      text_box1.text_changed += {*this, &form1::text_box1__text_changed};
    }

    void prompt_for_save(object& source, const elapsed_event_args& e) {
      if (has_changed && !dialog_is_open) {
        elapsed_minutes++;
        dialog_is_open = true;
        
        if (message_box::show(ustring::format("{0} minutes have elapsed since the text was saved. Save it now? ",
                                              elapsed_minutes), "Save Text",
                              message_box_buttons::yes_no_cancel, message_box_icon::question) == dialog_result::yes)
          button1_click(*this, event_args::empty);
      }
      dialog_is_open = false;
    }
    
    void button1_click(object& sender, const event_args& e) {
      if (ustring::is_empty(save_file_dialog1.file_name())) {
        if (save_file_dialog1.show_dialog() == dialog_result::ok)
          sw = std::make_shared<stream_writer>(save_file_dialog1.file_name(), false);
      }
      txt = text_box1.text();
      has_changed = false;
      timer.stop();
    }
    
    void form1_form_closing(object& sender, form_closing_event_args& e) {
      timer.close();
      if (sw != null) {
        sw->write(txt);
        sw->close();
      }
    }
    
    void text_box1__text_changed(object& sender, const event_args& e) {
      has_changed = true;
      timer.start();
    }
    
    button button1;
    save_file_dialog save_file_dialog1;
    text_box text_box1;

    bool dialog_is_open = false;
    int elapsed_minutes = 0;
    bool has_changed = false;
    std::shared_ptr<stream_writer> sw;
    ustring txt;

    // Create a timer with a 1-minute interval
    timers::timer timer {60'000};
  };
}

startup_(timer_example::form1);
