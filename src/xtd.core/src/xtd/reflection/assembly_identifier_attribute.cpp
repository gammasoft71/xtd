#include "../../../include/xtd/reflection/assembly_identifier_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_identifier_attribute::assembly_identifier_attribute(const string& identifier) : identifier_(identifier) {
}

assembly_identifier_attribute::assembly_identifier_attribute(const string& identifier, const object& executing_assembly) : identifier_(identifier) {
  __assembly_identifier_attribute__() = xtd::new_sptr<xtd::reflection::assembly_identifier_attribute>(identifier);
}

const string& assembly_identifier_attribute::identifier() const noexcept {
  return identifier_;
}

bool assembly_identifier_attribute::equals(const object& obj) const noexcept {
  return is<assembly_identifier_attribute>(obj) && equals(static_cast<const assembly_identifier_attribute&>(obj));
}

bool assembly_identifier_attribute::equals(const assembly_identifier_attribute& other) const noexcept {
  return identifier_ == other.identifier_;
}

size assembly_identifier_attribute::get_hash_code() const noexcept {
  return hash_code::combine(identifier_);
}

xtd::sptr<object> assembly_identifier_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_identifier_attribute>& __assembly_identifier_attribute__() {
  static auto identifier = xtd::sptr<xtd::reflection::assembly_identifier_attribute> {};
  return identifier;
}
