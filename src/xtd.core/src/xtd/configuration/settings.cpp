#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/configuration/file_settings.h"
#include "../../../include/xtd/configuration/settings.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/reflection/assembly.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/settings>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::configuration;
using namespace xtd::io;
using namespace xtd::reflection;

struct settings::data {
  configuration::file_settings file_settings;
};

settings::settings() : data_(std::make_shared<data>()) {
  auto product_name = [] {
    if (assembly::get_executing_assembly().product() != ustring::empty_string) return assembly::get_executing_assembly().product();
    if (environment::get_command_line_args().size() != 0) return path::get_file_name_without_extension(environment::get_command_line_args()[0]);
    return "noname"_s;
  };
  
  auto company_name = [&] {
    if (assembly::get_executing_assembly().company() != ustring::empty_string) return assembly::get_executing_assembly().company();
    return product_name();
  };

  data_->file_settings = file_settings {native::settings::get_path(company_name(), product_name())};
}

const ustring& settings::file_path() const noexcept {
  return data_->file_settings.file_path();
}

ustring settings::read(const ustring& key, const ustring& default_value) {
  return read_string(key, default_value);
}

void settings::reset() {
  data_->file_settings.reset();
}

void settings::save() {
  data_->file_settings.save();
}

void settings::write(const ustring& key, const ustring& value) {
  write_string(key, value);
}

ustring settings::read_string(const ustring& key, const ustring& default_value) {
  return data_->file_settings.read(key, default_value);
}

void settings::write_string(const ustring& key, const ustring& value) {
  data_->file_settings.write(key, value);
}
