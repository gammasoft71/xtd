#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/toolkit.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/toolkit.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/environment>

using namespace xtd;

ustring xtd::forms::native::toolkit::name() {
  return xtd::drawing::native::toolkit::name();
}

ustring xtd::forms::native::toolkit::description() {
  return ustring::format("The underlying graphical toolkit is {} {}. See https://www.wxwidgets.org for more information.", xtd::drawing::native::toolkit::name(), xtd::drawing::native::toolkit::version());
}

xtd::version xtd::forms::native::toolkit::version() {
  return xtd::drawing::native::toolkit::version();
}
