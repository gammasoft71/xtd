#define __XTD_FORMS_NATIVE_LIBRARY__
//#include <xtd/forms/native/message_notifier.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/message_notifier.h"
#include <xtd/diagnostics/debug.h>
using namespace xtd;
using namespace xtd::forms;

notifier_result message_notifier::show() {
  xtd::diagnostics::debug::write_line("message_notifier::show({}, {}, {}, ...);", title_, message_, icon_);
  //native::message_notifier::show(title_, message_, icon_, ...);
  return notifier_result::none;
}
