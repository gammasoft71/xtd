#include <xtd/forms/native/about_dialog.h>
#include "../../../include/xtd/forms/about_dialog.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

void about_dialog::reset() {
  name_ = "";
  description_ = "";
  version_ = "";
  long_version_ = "";
  copyright_ = "";
}

bool about_dialog::run_dialog(intptr_t owner) {
  return native::about_dialog::run_dialog(owner, name_, description_, version_, long_version_, copyright_);
}
