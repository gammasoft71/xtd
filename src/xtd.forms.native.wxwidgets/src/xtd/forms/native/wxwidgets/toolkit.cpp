#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/toolkit.hpp>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/toolkit.hpp>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/environment>

using namespace xtd;

string xtd::forms::native::toolkit::name() {
  return xtd::drawing::native::toolkit::name();
}

string xtd::forms::native::toolkit::description() {
  //return string::format("The underlying graphical toolkit is {} {}. See https://www.wxwidgets.org for more information.", name(), version());
  return "The underlying graphical toolkit is wxWidgets. See https://www.wxwidgets.org for more information.";
}

xtd::version xtd::forms::native::toolkit::version() {
  return xtd::drawing::native::toolkit::version();
}
