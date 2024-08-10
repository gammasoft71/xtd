#include "../../../include/xtd/reflection/assembly_configuration_attribute.h"

using namespace xtd;
using namespace xtd::reflection;

assembly_configuration_attribute::assembly_configuration_attribute(const ustring& configuration) : configuration_(configuration) {
}

assembly_configuration_attribute::assembly_configuration_attribute(const ustring& configuration, const object& executing_assembly) : configuration_(configuration) {
  __assembly_configuration_attribute__() = xtd::new_sptr<xtd::reflection::assembly_configuration_attribute>(configuration);
}

const ustring& assembly_configuration_attribute::configuration() const noexcept {
  return configuration_;
}

xtd::sptr<object> assembly_configuration_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_configuration_attribute>& __assembly_configuration_attribute__() {
  static auto configuration = xtd::sptr<xtd::reflection::assembly_configuration_attribute> {};
  return configuration;
}
