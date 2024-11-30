#include "../../../include/xtd/reflection/assembly_description_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_description_attribute::assembly_description_attribute(const string& description) : description_(description) {
}

assembly_description_attribute::assembly_description_attribute(const string& description, const object& executing_assembly) : description_(description) {
  __assembly_description_attribute__() = xtd::new_sptr<xtd::reflection::assembly_description_attribute>(description);
}

const string& assembly_description_attribute::description() const noexcept {
  return description_;
}

xtd::sptr<object> assembly_description_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_description_attribute>& __assembly_description_attribute__() {
  static auto description = xtd::sptr<xtd::reflection::assembly_description_attribute> {};
  return description;
}
