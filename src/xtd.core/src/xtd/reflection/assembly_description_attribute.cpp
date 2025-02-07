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

bool assembly_description_attribute::equals(const object& obj) const noexcept {
  return is<assembly_description_attribute>(obj) && equals(static_cast<const assembly_description_attribute&>(obj));
}

bool assembly_description_attribute::equals(const assembly_description_attribute& other) const noexcept {
  return description_ == other.description_;
}

size assembly_description_attribute::get_hash_code() const noexcept {
  return hash_code::combine(description_);
}

xtd::sptr<object> assembly_description_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_description_attribute>& __assembly_description_attribute__() {
  static auto description = xtd::sptr<xtd::reflection::assembly_description_attribute> {};
  return description;
}
