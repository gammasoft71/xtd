#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  auto form1 = control::create<form>("form1");
  form1->show();
  form1->form_closing += [&](const control& sender, form_closing_event_args& e) {
    e.cancel(message_box::show("form1", "Close ?", message_box_buttons::yes_no) == dialog_result::no);
  };
  auto form2 = control::create<form>("form2");
  form2->show();
  auto button1 = control::create<button>(*form1, "main", {10, 10});
  auto button2 = control::create<button>(*form2, "main", {10, 10});
  application_context context;
  button1->click += [&] {
    context.main_form(*form1);
    button1->enabled(&context.main_form() != form1.get());
    button2->enabled(&context.main_form() != form2.get());
  };
  button2->click += [&] {
    context.main_form(*form2);
    button1->enabled(&context.main_form() != form1.get());
    button2->enabled(&context.main_form() != form2.get());
  };
  application::run(context);
}
