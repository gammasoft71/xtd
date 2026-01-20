#include "../../../include/xtd/reflection/assembly_description_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_description_attribute::assembly_description_attribute(const string& description) : description_(description) {
}

assembly_description_attribute::assembly_description_attribute(const string& description, const object& executing_assembly) : description_(description) {
  __assembly_description_attribute__() = xtd::new_sptr<xtd::reflection::assembly_description_attribute>(description);
}

auto assembly_description_attribute::description() const noexcept -> const string& {
  return description_;
}

auto assembly_description_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_description_attribute>(obj) && equals(static_cast<const assembly_description_attribute&>(obj));
}

auto assembly_description_attribute::equals(const assembly_description_attribute& other) const noexcept -> bool {
  return description_ == other.description_;
}

auto assembly_description_attribute::get_hash_code() const noexcept -> size {
  return hash_code::combine(description_);
}

auto assembly_description_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto __assembly_description_attribute__() -> sptr<assembly_description_attribute>& {
  static auto description = xtd::sptr<xtd::reflection::assembly_description_attribute> {};
  return description;
}
