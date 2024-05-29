#include "../../include/xtd/settings.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/settings>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/environment>
#include <xtd/io/path>
#include <xtd/reflection/assembly>

using namespace xtd;
using namespace xtd::reflection;

namespace {
  xtd::ustring executable_path() noexcept {
    if (environment::get_command_line_args().size() == 0) return "";
    return environment::get_command_line_args()[0];
  }

  xtd::ustring product_name() noexcept {
    if (assembly::get_executing_assembly().product() == "") return xtd::io::path::get_file_name_without_extension(executable_path());
    return assembly::get_executing_assembly().product();
  }

  xtd::ustring company_name() noexcept {
    try {
      if (assembly::get_executing_assembly().company() == "") return xtd::io::path::get_file_name_without_extension(executable_path());
      return assembly::get_executing_assembly().company();
    } catch (...) {
      return assembly::get_executing_assembly().company();
    }
  }
}

struct settings::data {
  intptr settings_;
};

settings::settings() : data_(std::make_shared<data>()) {
  data_->settings_ = native::settings::create(product_name(), company_name());
}

settings::~settings() {
  if (data_.use_count() == 1)
    native::settings::destroy(data_->settings_);
}

xtd::ustring settings::read(const xtd::ustring& key, const xtd::ustring& default_value) {
  return read_string(key, default_value);
}

void settings::reset() {
  native::settings::reset(data_->settings_);
}

void settings::save() {
  native::settings::save(data_->settings_);
}

void settings::write(const xtd::ustring& key, const xtd::ustring& value) {
  write_string(key, value);
}

xtd::ustring settings::read_string(const xtd::ustring& key, const xtd::ustring& default_value) {
  return native::settings::read(data_->settings_, key, default_value);
}

void settings::write_string(const xtd::ustring& key, const xtd::ustring& value) {
  native::settings::write(data_->settings_, key, value);
}
