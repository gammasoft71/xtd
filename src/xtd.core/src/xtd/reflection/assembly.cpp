#include "../../../include/xtd/reflection/assembly.h"
#include "../../../include/xtd/reflection/assembly_info.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/environment.h"

using namespace xtd;
using namespace xtd::io;
using namespace xtd::reflection;

const string& assembly::company() const noexcept {
  return company_;
}

const string& assembly::configuration() const noexcept {
  return configuration_;
}

const string& assembly::copyright() const noexcept {
  return copyright_;
}

const string& assembly::culture() const noexcept {
  return culture_;
}

const string& assembly::description() const noexcept {
  return description_;
}

const string& assembly::file_version() const noexcept {
  return file_version_;
}

const string& assembly::guid() const noexcept {
  return guid_;
}

const string& assembly::identifier() const noexcept {
  return identifier_;
}

string assembly::location() const noexcept {
  return environment::get_command_line_args()[0];
}

const string& assembly::name() const noexcept {
  return name_;
}

const string& assembly::product() const noexcept {
  return product_;
}

string assembly::location_path() const noexcept {
  return path::get_directory_name(location());
}

const string& assembly::title() const noexcept {
  return title_;
}

const string& assembly::trademarks() const noexcept {
  return trademarks_;
}

const string& assembly::version() const noexcept {
  return version_;
}

const assembly& assembly::get_executing_assembly() noexcept {
  static auto current_assembly = assembly {};
  if (__assembly_company_attribute__() && current_assembly.company_ != __assembly_company_attribute__()->company()) current_assembly.company_ = __assembly_company_attribute__()->company();
  if (__assembly_configuration_attribute__() && current_assembly.configuration_ != __assembly_configuration_attribute__()->configuration()) current_assembly.configuration_ = __assembly_configuration_attribute__()->configuration();
  if (__assembly_copyright_attribute__() && current_assembly.copyright_ != __assembly_copyright_attribute__()->copyright()) current_assembly.copyright_ = __assembly_copyright_attribute__()->copyright();
  if (__assembly_culture_attribute__() && current_assembly.culture_ != __assembly_culture_attribute__()->culture()) current_assembly.culture_ = __assembly_culture_attribute__()->culture();
  if (__assembly_description_attribute__() && current_assembly.description_ != __assembly_description_attribute__()->description()) current_assembly.description_ = __assembly_description_attribute__()->description();
  if (__assembly_file_version_attribute__() && current_assembly.file_version_ != __assembly_file_version_attribute__()->version()) current_assembly.file_version_ = __assembly_file_version_attribute__()->version();
  if (__assembly_guid_attribute__() && current_assembly.guid_ != __assembly_guid_attribute__()->guid()) current_assembly.guid_ = __assembly_guid_attribute__()->guid();
  if (__assembly_identifier_attribute__() && current_assembly.identifier_ != __assembly_identifier_attribute__()->identifier()) current_assembly.identifier_ = __assembly_identifier_attribute__()->identifier();
  if (__assembly_name_attribute__() && current_assembly.name_ != __assembly_name_attribute__()->name()) current_assembly.name_ = __assembly_name_attribute__()->name();
  if (__assembly_product_attribute__() && current_assembly.product_ != __assembly_product_attribute__()->product()) current_assembly.product_ = __assembly_product_attribute__()->product();
  if (__assembly_title_attribute__() && current_assembly.title_ != __assembly_title_attribute__()->title()) current_assembly.title_ = __assembly_title_attribute__()->title();
  if (__assembly_trademark_attribute__() && current_assembly.trademarks_ != __assembly_trademark_attribute__()->trademark()) current_assembly.trademarks_ = __assembly_trademark_attribute__()->trademark();
  if (__assembly_version_attribute__() && current_assembly.version_ != __assembly_version_attribute__()->version()) current_assembly.version_ = __assembly_version_attribute__()->version();
  return current_assembly;
}
