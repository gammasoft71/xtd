#include <xtd/forms/native/about_dialog.h>
#include "../../../include/xtd/forms/about_dialog.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

void about_dialog::reset() {
  about_dialog_style_ = xtd::forms::about_dialog_style::system;
  name_ = "";
  description_ = "";
  version_ = "";
  long_version_ = "";
  copyright_ = "";
  website_ = "";
  website_label_ = "";
  creators_.clear();
  designers_.clear();
  doc_writers_.clear();
  translators_.clear();
  license_ = "";
}

bool about_dialog::run_dialog(intptr_t owner) {
  if (about_dialog_style_ == xtd::forms::about_dialog_style::system)
    return native::about_dialog::run_dialog(owner, name_, description_, version_, long_version_, copyright_, website_, website_label_, creators_.to_array(), designers_.to_array(), doc_writers_.to_array(), translators_.to_array(), license_);
  return false;
}
