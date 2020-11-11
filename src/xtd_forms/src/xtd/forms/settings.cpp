#include "../../../include/xtd/forms/settings.h"
#include "../../../include/xtd/forms/application.h"
#include <xtd/forms/native/settings.h>

using namespace xtd::forms;

settings::settings() {
  data_->settings_ = native::settings::create(application::product_name(), application::company_name());
}

settings::~settings() {
  if (data_.use_count() == 1)
    native::settings::destroy(data_->settings_);
}

std::string settings::read_string(const std::string &key, const std::string &default_value) {
  return native::settings::read(data_->settings_, key, default_value);
}

void settings::reset() {
  native::settings::reset(data_->settings_);
}

void settings::save() {
  native::settings::save(data_->settings_);
}

void settings::write_string(const std::string &key, const std::string &value) {
  native::settings::write(data_->settings_, key, value);
}
