#include "../../../include/xtd/forms/button.hpp"
#include <xtd/forms/native/window_button.hpp>

using namespace xtd;
using namespace xtd::forms;

button::button() {
  this->make_control(*this);
}

button& button::operator=(const button& value) {
  this->button_base::operator=(value);
  return *this;
}

forms::create_params button::create_params() const {
  forms::create_params create_params = this->button_base::create_params();
  
  create_params.style(create_params.style() | BS_PUSHBUTTON);
  
  return create_params;
}

button& button::auto_size_mode(forms::auto_size_mode value) {
  this->set_auto_size_mode(value);
  return *this;
}
