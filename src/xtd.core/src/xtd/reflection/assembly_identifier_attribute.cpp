#include "../../../include/xtd/reflection/assembly_identifier_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_identifier_attribute::assembly_identifier_attribute(const string& identifier) : identifier_(identifier) {
}

auto assembly_identifier_attribute::identifier() const noexcept -> const string& {
  return identifier_;
}

auto assembly_identifier_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_identifier_attribute>(obj) && equals(static_cast<const assembly_identifier_attribute&>(obj));
}

auto assembly_identifier_attribute::equals(const assembly_identifier_attribute& other) const noexcept -> bool {
  return identifier_ == other.identifier_;
}

auto assembly_identifier_attribute::get_hash_code() const noexcept -> size {
  return hash_code::combine(identifier_);
}

auto assembly_identifier_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto assembly_identifier_attribute::create(const string& identifier) -> assembly_identifier_attribute {
  __assembly_identifier_attribute__() = xtd::new_sptr<xtd::reflection::assembly_identifier_attribute>(identifier);
  return assembly_identifier_attribute {identifier};
}

auto __assembly_identifier_attribute__() -> sptr<assembly_identifier_attribute>& {
  static auto identifier = xtd::sptr<xtd::reflection::assembly_identifier_attribute> {};
  return identifier;
}
