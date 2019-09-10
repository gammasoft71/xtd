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
  /*
   form f;
   {
   form g;
   g.text("Hello, World!");
   f = g;
   }
   application::run(f);
   */
  
  //auto w1 = create<win>("form1");
  //xtd::cdebug << xtd::format("w = 0x{:X}", (intptr_t)&w1) << std::endl;
  //xtd::cdebug << xtd::format("w.handle = 0x{:X}", (intptr_t)w1.handle()) << std::endl;
  
  application::start_application();
  //auto w1 = std::make_shared<win>();
  //w1.reset();
  
  win w2 = create<win>("form2");
  w2.visible(true);
  application::main_form(w2.handle());
  application::run();
  application::end_application();
}
