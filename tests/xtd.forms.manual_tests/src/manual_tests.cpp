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
    this->handle_ = control::create(cp);
  }
  
  win(const win&) = default;
  //win& operator=(const win&) = default;
  
  virtual ~win() {
    control::destroy(this->handle_);
  }
  
  intptr_t handle() const { return this->handle_; }
  
  std::string text() const { return control::text(this->handle_); }
  win& text(const std::string& text) {
    control::text(this->handle_, text);
    return *this;
  }
  
  bool visible() const { return control::visible(this->handle_); }
  win& visible(bool visible) {
    control::visible(this->handle_, visible);
    return *this;
  }
  
private:
  intptr_t handle_;
};

template <typename control_t>
control_t create(const std::string& text) {
  control_t ctrl;
  
  ctrl.text(text);
  
  return ctrl;
}

class app {
public:
  app() {application::start_application();}
  ~app() {application::end_application();}
  
  void run() {application::run();}
};

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
  
  app app;
  auto w = std::make_shared<win>();
  w.reset();
  
  win w2;
  //w2.text("form2");
  xtd::cdebug << xtd::format("w = 0x{:X}", (intptr_t)&w2) << std::endl;
  xtd::cdebug << xtd::format("w.handle = 0x{:X}", (intptr_t)w2.handle()) << std::endl;
  w2.visible(true);
  application::main_form(w2.handle());
  //app.run();
}
