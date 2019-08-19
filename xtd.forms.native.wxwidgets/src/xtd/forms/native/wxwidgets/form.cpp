#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/form.hpp>
#include "wx_form.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void form::close(intptr_t form) {
  reinterpret_cast<wx_form*>(form)->control()->Close();
}
