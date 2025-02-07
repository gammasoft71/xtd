#include "../../../include/xtd/reflection/assembly_configuration_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_configuration_attribute::assembly_configuration_attribute(const string& configuration) : configuration_(configuration) {
}

assembly_configuration_attribute::assembly_configuration_attribute(const string& configuration, const object& executing_assembly) : configuration_(configuration) {
  __assembly_configuration_attribute__() = xtd::new_sptr<xtd::reflection::assembly_configuration_attribute>(configuration);
}

const string& assembly_configuration_attribute::configuration() const noexcept {
  return configuration_;
}

bool assembly_configuration_attribute::equals(const object& obj) const noexcept {
  return is<assembly_configuration_attribute>(obj) && equals(static_cast<const assembly_configuration_attribute&>(obj));
}

bool assembly_configuration_attribute::equals(const assembly_configuration_attribute& other) const noexcept {
  return configuration_ == other.configuration_;
}

size assembly_configuration_attribute::get_hash_code() const noexcept {
  return hash_code::combine(configuration_);
}

xtd::sptr<object> assembly_configuration_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_configuration_attribute>& __assembly_configuration_attribute__() {
  static auto configuration = xtd::sptr<xtd::reflection::assembly_configuration_attribute> {};
  return configuration;
}
