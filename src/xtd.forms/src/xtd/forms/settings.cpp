#include "../../../include/xtd/forms/settings.h"
#include "../../../include/xtd/forms/application.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/settings.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd::forms;

settings::settings() {
  data_->settings_ = native::settings::create(application::product_name(), application::company_name());
}

settings::~settings() {
  if (data_.use_count() == 1)
    native::settings::destroy(data_->settings_);
}

xtd::ustring settings::read_string(const xtd::ustring &key, const xtd::ustring &default_value) {
  return native::settings::read(data_->settings_, key, default_value);
}

void settings::reset() {
  native::settings::reset(data_->settings_);
}

void settings::save() {
  native::settings::save(data_->settings_);
}

void settings::write_string(const xtd::ustring &key, const xtd::ustring &value) {
  native::settings::write(data_->settings_, key, value);
}
