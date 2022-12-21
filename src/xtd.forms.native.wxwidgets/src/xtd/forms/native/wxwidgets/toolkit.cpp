#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/toolkit.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/environment.h>

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

bool toolkit::is_operating_system_double_buffered() {
  static auto is_operating_system_double_buffered = !xtd::environment::os_version().is_windows_platform();
  return is_operating_system_double_buffered;
}
