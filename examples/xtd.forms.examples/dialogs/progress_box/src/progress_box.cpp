#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/progress_box>
#include <xtd/threading/thread>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Progress box example");
    client_size({ 400, 200 });
    
    download_button.parent(*this)
    .text("Download")
    .location({ 10, 10 })
    .size({ 150, 35 })
    .click += [this] {
      progress_box::show(*this, "Downloading", "Please wait...", 0, 0, 100, progress_box_options::show_cancel_button | progress_box_options::show_skip_button);
      for (auto index = progress_box::minimum(); index <= progress_box::maximum(); ++index) {
        threading::thread::sleep(100_ms); // Do some work...
        progress_box::update(index, "Downloading", xtd::ustring::format("{}/{}", index, progress_box::maximum()));
        if (progress_box::skipped()) index++;
        if (progress_box::cancelled()) break;
      }
      progress_box::hide();
    };
  }
  
private:
  button download_button;
};

auto main() -> int {
  application::run(form1 {});
}
