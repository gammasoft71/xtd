#include "../../../include/xtd/environment.hpp"
#include "../../../include/xtd/configuration/file_settings.hpp"
#include "../../../include/xtd/configuration/settings.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/reflection/assembly.hpp"
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

settings::settings() : data_(xtd::new_sptr<data>()) {
  auto product_name = assembly::get_executing_assembly().product() != string::empty_string ? assembly::get_executing_assembly().product() : path::get_file_name_without_extension(assembly::get_executing_assembly().location());
  auto company_name = assembly::get_executing_assembly().company() != string::empty_string ? assembly::get_executing_assembly().company() : product_name;
  data_->file_settings = file_settings {io::path::combine(environment::get_folder_path(environment::special_folder::application_data), company_name, product_name + native::settings::get_file_extension().c_str())};
}

const string& settings::file_path() const noexcept {
  return data_->file_settings.file_path();
}

string settings::read(const string& key, const string& default_value) {
  return read_string(key, default_value);
}

void settings::reset() {
  data_->file_settings.reset();
}

void settings::save() {
  data_->file_settings.save();
}

void settings::write(const string& key, const string& value) {
  write_string(key, value);
}

string settings::read_string(const string& key, const string& default_value) {
  return data_->file_settings.read(key, default_value);
}

void settings::write_string(const string& key, const string& value) {
  data_->file_settings.write(key, value);
}
