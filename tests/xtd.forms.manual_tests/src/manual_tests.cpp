#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  auto form1 = control::create<form>("form1");
  auto button1 = control::create<button>(form1, "Dialog", {10, 10});
  button1.click += [&] {
    auto dialog = control::create<form>("dialog", {200, 400});
    auto button_ok = control::create<button>(dialog, "OK", {10, 10});
    button_ok.dialog_result(forms::dialog_result::ok);
    auto button_cancel = control::create<button>(dialog, "Cancel", {100, 10});
    button_cancel.dialog_result(forms::dialog_result::cancel);
    cdebug << format("dialog_result = {}", dialog.show_dialog()) << endl;
  };
  application::run(form1);
}
