#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

// The main entry point for the application.
int main() {
  form form;
  form.back_color(color::dodger_blue);
  form.fore_color(color::yellow);
  cdebug << format("form.back_color = {}", form.back_color()) << endl;
  cdebug << format("form.fore_color = {}", form.fore_color()) << endl;
  cdebug << format("form.size = {}", form.size()) << endl;

  label label1;
  //label1.auto_size(true);
  label1.border_styles(forms::border_styles::fixed_single);
  label1.text("Hello");
  label1.parent(form);
  label1.location({10, 10});
  cdebug << format("label1.back_color = {}", label1.back_color()) << endl;
  cdebug << format("label1.fore_color = {}", label1.fore_color()) << endl;
  cdebug << format("label1.size = {}", label1.size()) << endl;

  text_box text_box;
  text_box.parent(form);
  text_box.location({10, 70});
  cdebug << format("text_box.back_color = {}", text_box.back_color()) << endl;
  cdebug << format("text_box.fore_color = {}", text_box.fore_color()) << endl;
  cdebug << format("text_box.size = {}", text_box.size()) << endl;

  button button1;
  button1.parent(form);
  button1.location({10, 200});
  button1.width(110);
  button1.text(strings::format("auto size {}", label1.auto_size() ? "OFF" : "ON"));
  button1.click += [&](const control& sender, const event_args& e) {
    label1.auto_size(!label1.auto_size());
    label1.size({100, 23});
    button1.text(strings::format("auto size {}", label1.auto_size() ? "OFF" : "ON"));
  };
  cdebug << format("button1.back_color = {}", button1.back_color()) << endl;
  cdebug << format("button1.fore_color = {}", button1.fore_color()) << endl;
  cdebug << format("button1.size = {}", button1.size()) << endl;

  forms::button button2;
  button2.parent(form);
  button2.location({150, 200});
  button2.text("text...");
  button2.click += [&](const control& sender, const event_args& e) {
    label1.text(label1.text() == "Hello" ? "This is a very long long text" : "Hello");
  };
  cdebug << format("button2.back_color = {}", button2.back_color()) << endl;
  cdebug << format("button2.fore_color = {}", button2.fore_color()) << endl;
  cdebug << format("button2.size = {}", button2.size()) << endl;

  application::run(form);
}
