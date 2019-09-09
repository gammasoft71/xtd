//#include <xtd/xtd.forms>
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
    cp.caption("form");
    this->handle_ = control::create(cp);
  }
  
  virtual ~win() {
    control::destroy(this->handle_);
  }
  
  bool visible() const {return control::visible(this->handle_);}
  win& visible(bool visible) {
    control::visible(this->handle_, visible);
    return *this;
  }
  
private:
  intptr_t handle_;
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
  
  auto w = std::make_shared<win>();
  w->visible(true);
  application::run();
}
