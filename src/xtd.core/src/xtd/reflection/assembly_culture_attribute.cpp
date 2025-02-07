#include "../../../include/xtd/reflection/assembly_culture_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_culture_attribute::assembly_culture_attribute(const string& culture) : culture_(culture) {
}

assembly_culture_attribute::assembly_culture_attribute(const string& culture, const object& executing_assembly) : culture_(culture) {
  __assembly_culture_attribute__() = xtd::new_sptr<xtd::reflection::assembly_culture_attribute>(culture);
}

const string& assembly_culture_attribute::culture() const noexcept {
  return culture_;
}

bool assembly_culture_attribute::equals(const object& obj) const noexcept {
  return is<assembly_culture_attribute>(obj) && equals(static_cast<const assembly_culture_attribute&>(obj));
}

bool assembly_culture_attribute::equals(const assembly_culture_attribute& other) const noexcept {
  return culture_ == other.culture_;
}

size assembly_culture_attribute::get_hash_code() const noexcept {
  return hash_code::combine(culture_);
}

xtd::sptr<object> assembly_culture_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_culture_attribute>& __assembly_culture_attribute__() {
  static auto culture = xtd::sptr<xtd::reflection::assembly_culture_attribute> {};
  return culture;
}
