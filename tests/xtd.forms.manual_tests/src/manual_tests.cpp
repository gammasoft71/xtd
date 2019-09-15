#include <cstdlib>
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  form form1;
  form1.text("form1");
  //form1.enabled(false);

  button button1;
  button1.parent(form1);
  button1.location({10, 10});
  button1.text("dialog");
  button1.click += [&] {
    form dialog;
    dialog.text("dialog");
    dialog.location({200, 400});
    
    button button_ok;
    button_ok.parent(dialog);
    button_ok.text("OK");
    button_ok.location({10, 10});
    cdebug << format("button_ok[0x{:X}] = {}", button_ok.handle(), button_ok) << endl;
    cdebug << format("button_ok.parent[0x{:X} = {}", button_ok.parent().handle(), button_ok.parent()) << endl;
    cdebug << format("button_ok.top_level_control[0x{:X}] = {}", button_ok.top_level_control().handle(), button_ok.top_level_control()) << endl;
    button_ok.dialog_result(forms::dialog_result::oK);
    
    cdebug << format("dialog_result = {}", dialog.show_dialog()) << endl;
  };
  application::run(form1);
}

/*
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  auto f0 = control::create<form>("Form Main");
  cdebug << format("f0.data_ = 0x{:X}, handle = 0x{:X}, {}", (intptr_t)f0.control::data_.get(), f0.handle(), f0) << endl;
  
  auto f = control::create<form>("Form One");
  cdebug << format("f.data_ = 0x{:X}, handle = 0x{:X}, {}", (intptr_t)f.control::data_.get(), f.handle(), f) << endl;
  
  f = control::create<form>("Form Two");
  cdebug << format("f.data_ = 0x{:X}, handle = 0x{:X} {}", (intptr_t)f.control::data_.get(), f.handle(), f) << endl;
  
  auto b = control::create<button>(f, "Button One", {10, 10});;
  cdebug << format("b.data_ = 0x{:X}, handle = 0x{:X}, {}", (intptr_t)b.control::data_.get(), b.handle(), b) << endl;
  
  b = control::create<button>(f, "Button Two", {10, 10});
  cdebug << format("b.data_ = 0x{:X}, handle = 0x{:X}, {}", (intptr_t)b.control::data_.get(), b.handle(), b) << endl;
  
  cdebug << "------------------------------------------------" << endl;
  for(auto item : control::top_level_controls_) {
    cdebug << format("control::top_level_controls_ handle = [0x{:X}] = {}", item.get().data_->handle_, item.get()) << endl;
  }
  
  cdebug << "------------------------------------------------" << endl;
  for(auto item : control::controls_) {
    cdebug << format("control::controls[0x{:X}] = {}", (intptr_t)item.first, *item.second) << endl;
  }
  
  cdebug << "------------------------------------------------" << endl;
  for(auto item : control::handles_) {
    cdebug << format("control::handles[0x{:X}] = {}", item.first, *item.second) << endl;
  }
  
  cdebug << "------------------------------------------------" << endl;
  for(auto item : f.controls()) {
    cdebug << format("f.controls handle = [0x{:X}] = {}", item.get().data_->handle_, item.get()) << endl;
  }
  
  b.click += [&] {
    message_box::show(f, "Two");
  };
  
  f.visible(true);
  
  application::run(f0);
}
*/
 
/*
#include <xtd/diagnostics/cdebug.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/form.hpp>

using namespace xtd::forms;
using namespace xtd::forms::native;

int main() {
  application::start_application();
  
  create_params cp;
  cp.class_name("form");
  cp.caption("Form");
  intptr_t f = control::create(cp);
  control::visible(f, true);
  application::main_form(f);
  application::run();

  application::end_application();
}
*/
