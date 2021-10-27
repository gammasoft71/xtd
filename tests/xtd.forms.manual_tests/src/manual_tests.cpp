#include <xtd/xtd.forms>

using namespace xtd::forms;
using namespace std::chrono_literals;

class manual_test_form : public form {
public:
  static void main() {
    application::run(manual_test_form());
  }

  manual_test_form() {
    text("Manual tests");
    client_size({250, 150});
     
    download_button.parent(*this)
      .text("Download")
      .location({ 10, 10 })
      .size({ 150, 50 })
      .click += [this] {
        progress_box::show(*this, "Downloading", "Please wait...", 0, 0, 100, progress_box_options::show_cancel_button | progress_box_options::show_skip_button);
        for(int32_t i = progress_box::minimum(); i <= progress_box::maximum(); ++i) {
          std::this_thread::sleep_for(100ms); // Do some work...
          progress_box::update(i, "Downloading", xtd::ustring::format("{}/{}", i, progress_box::maximum()));
          if (progress_box::skipped()) i++;
          if (progress_box::cancelled()) break;
        }
        progress_box::hide();
      };
  }

private:
  button download_button;
};

startup_(manual_test_form);
