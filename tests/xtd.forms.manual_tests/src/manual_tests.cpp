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

/*
 //#include <xtd/xtd.forms>
 #include <xtd/diagnostics/cdebug.hpp>
 #include <xtd/forms/native/application.hpp>
 #include <xtd/forms/native/control.hpp>
 #include <xtd/forms/native/form.hpp>
 
 using namespace xtd::forms;
 using namespace xtd::forms::native;
 
 class win {
 public:
 win() {
 create_params cp;
 cp.class_name("form");
 cp.location({100, 100});
 cp.size({300, 300});
 cp.caption("win");
 this->data_->handle_ = control::create(cp);
 }
 
 win(const win&) = default;
 //win& operator=(const win&) = default;
 
 virtual ~win() {
 if (this->data_.use_count() == 1)
 control::destroy(this->data_->handle_);
 }
 
 intptr_t handle() const { return this->data_->handle_; }
 
 std::string text() const { return control::text(this->data_->handle_); }
 win& text(const std::string& text) {
 control::text(this->data_->handle_, text);
 return *this;
 }
 
 bool visible() const { return control::visible(this->data_->handle_); }
 win& visible(bool visible) {
 control::visible(this->data_->handle_, visible);
 return *this;
 }
 
 private:
 struct data {
 intptr_t handle_;
 };
 std::shared_ptr<data> data_ = std::make_shared<data>();
 };
 
 template <typename control_t>
 control_t create() {
 control_t ctrl;
 return ctrl;
 }
 
 template <typename control_t>
 control_t create(const std::string& text) {
 control_t ctrl;
 ctrl.text(text);
 return ctrl;
 }
 
 int main() {
 application::start_application();
 auto w1 = std::make_shared<win>();
 w1.reset();
 
 win w2 = create<win>("form2");
 w2.visible(true);
 application::main_form(w2.handle());
 application::run();
 application::end_application();
 }
 */

