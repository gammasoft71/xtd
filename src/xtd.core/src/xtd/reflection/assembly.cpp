#include "../../../include/xtd/reflection/assembly.h"
#include "../../../include/xtd/reflection/assembly_info.h"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

const ustring& assembly::company() const noexcept {
  return company_;
}

const ustring& assembly::configuration() const noexcept {
  return configuration_;
}

const ustring& assembly::copyright() const noexcept {
  return copyright_;
}

const ustring& assembly::culture() const noexcept {
  return culture_;
}

const ustring& assembly::description() const noexcept {
  return description_;
}

const ustring& assembly::file_version() const noexcept {
  return file_version_;
}

const ustring& assembly::guid() const noexcept {
  return guid_;
}

const ustring& assembly::identifier() const noexcept {
  return identifier_;
}

const ustring& assembly::name() const noexcept {
  return name_;
}

const ustring& assembly::product() const noexcept {
  return product_;
}

const ustring& assembly::title() const noexcept {
  return title_;
}

const ustring& assembly::trademarks() const noexcept {
  return trademarks_;
}

const ustring& assembly::version() const noexcept {
  return version_;
}

const assembly& assembly::get_executing_assembly() noexcept {
  static auto current_assembly = unique_ptr<assembly> {};
  if (!current_assembly) {
    current_assembly = unique_ptr<assembly> {new assembly {}};
    if (__assembly_company_attribute__()) current_assembly->company_ = __assembly_company_attribute__()->company();
    if (__assembly_configuration_attribute__()) current_assembly->configuration_ = __assembly_configuration_attribute__()->configuration();
    if (__assembly_copyright_attribute__()) current_assembly->copyright_ = __assembly_copyright_attribute__()->copyright();
    if (__assembly_culture_attribute__()) current_assembly->culture_ = __assembly_culture_attribute__()->culture();
    if (__assembly_description_attribute__()) current_assembly->description_ = __assembly_description_attribute__()->description();
    if (__assembly_file_version_attribute__()) current_assembly->file_version_ = __assembly_file_version_attribute__()->version();
    if (__assembly_guid_attribute__()) current_assembly->guid_ = __assembly_guid_attribute__()->guid();
    if (__assembly_identifier_attribute__()) current_assembly->identifier_ = __assembly_identifier_attribute__()->identifier();
    if (__assembly_name_attribute__()) current_assembly->name_ = __assembly_name_attribute__()->name();
    if (__assembly_product_attribute__()) current_assembly->product_ = __assembly_product_attribute__()->product();
    if (__assembly_title_attribute__()) current_assembly->title_ = __assembly_title_attribute__()->title();
    if (__assembly_trademark_attribute__()) current_assembly->trademarks_ = __assembly_trademark_attribute__()->trademark();
    if (__assembly_version_attribute__()) current_assembly->version_ = __assembly_version_attribute__()->version();
  }
  return *current_assembly;
}
