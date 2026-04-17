#include "../../../include/xtd/reflection/assembly.hpp"
#include "../../../include/xtd/reflection/assembly_info.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/environment.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/environment>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::io;
using namespace xtd::reflection;

auto assembly::company() const noexcept -> const string& {
  return company_;
}

auto assembly::configuration() const noexcept -> const string& {
  return configuration_;
}

auto assembly::copyright() const noexcept -> const string& {
  return copyright_;
}

auto assembly::culture() const noexcept -> const string& {
  return culture_;
}

auto assembly::description() const noexcept -> const string& {
  return description_;
}

auto assembly::file_name() const noexcept -> string {
  return path::get_file_name(location());
}

auto assembly::file_version() const noexcept -> const string& {
  return file_version_;
}

auto assembly::guid() const noexcept -> const string& {
  return guid_;
}

auto assembly::identifier() const noexcept -> const string& {
  return identifier_;
}

auto assembly::location() const noexcept -> string {
  return native::environment::get_executable_path();
}

auto assembly::name() const noexcept -> const string& {
  return name_;
}

auto assembly::name_or_file_name() const noexcept -> string {
  return string::is_empty(name_) ? file_name() : name_;
}

auto assembly::product() const noexcept -> const string& {
  return product_;
}

auto assembly::location_path() const noexcept -> string {
  return path::get_directory_name(location());
}

auto assembly::title() const noexcept -> const string& {
  return title_;
}

auto assembly::trademark() const noexcept -> const string& {
  return trademarks_;
}

auto assembly::version() const noexcept -> const string& {
  return version_;
}

auto assembly::equals(const object& obj) const noexcept -> bool {
  return is<assembly>(obj) && equals(static_cast<const assembly&>(obj));
}

auto assembly::equals(const assembly& other) const noexcept -> bool {
  return company_ == other.company_ && configuration_ == other.configuration_ && copyright_ == other.copyright_ && culture_ == other.culture_ && description_ == other.description_ && file_version_ == other.file_version_ && guid_ == other.guid_ && identifier_ == other.identifier_ && name_ == other.name_ && product_ == other.product_ && title_ == other.title_ && trademarks_ == other.trademarks_ && version_ == other.version_;
}

auto assembly::get_hash_code() const noexcept -> usize {
  return hash_code::combine(company_, configuration_, copyright_, culture_, description_, file_version_, guid_, identifier_, name_, product_, title_, trademarks_, version_);
}

auto assembly::get_executing_assembly() noexcept -> const assembly& {
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
