#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/toolkit.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms::native;

ustring toolkit::name() {
  return "wxwidgets";
}

ustring toolkit::description() {
  return "This library is based on wxWidgets 3.1.5 (https://www.wxwidgets.org) toolkit.";
}

xtd::version toolkit::version() {
  return {0, 1, 0};
}
