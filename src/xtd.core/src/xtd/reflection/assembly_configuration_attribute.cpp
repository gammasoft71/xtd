#include "../../../include/xtd/reflection/assembly_configuration_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_configuration_attribute::assembly_configuration_attribute(const string& configuration) : configuration_(configuration) {
}

assembly_configuration_attribute::assembly_configuration_attribute(const string& configuration, const object& executing_assembly) : configuration_(configuration) {
  __assembly_configuration_attribute__() = xtd::new_sptr<xtd::reflection::assembly_configuration_attribute>(configuration);
}

auto assembly_configuration_attribute::configuration() const noexcept -> const string& {
  return configuration_;
}

auto assembly_configuration_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_configuration_attribute>(obj) && equals(static_cast<const assembly_configuration_attribute&>(obj));
}

auto assembly_configuration_attribute::equals(const assembly_configuration_attribute& other) const noexcept -> bool {
  return configuration_ == other.configuration_;
}

auto assembly_configuration_attribute::get_hash_code() const noexcept -> size {
  return hash_code::combine(configuration_);
}

auto assembly_configuration_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto __assembly_configuration_attribute__() -> sptr<assembly_configuration_attribute>& {
  static auto configuration = xtd::sptr<xtd::reflection::assembly_configuration_attribute> {};
  return configuration;
}
