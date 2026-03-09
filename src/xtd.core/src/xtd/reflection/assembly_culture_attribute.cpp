#include "../../../include/xtd/reflection/assembly_culture_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_culture_attribute::assembly_culture_attribute(const string& culture) : culture_(culture) {
}

auto assembly_culture_attribute::culture() const noexcept -> const string& {
  return culture_;
}

auto assembly_culture_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_culture_attribute>(obj) && equals(static_cast<const assembly_culture_attribute&>(obj));
}

auto assembly_culture_attribute::equals(const assembly_culture_attribute& other) const noexcept -> bool {
  return culture_ == other.culture_;
}

auto assembly_culture_attribute::get_hash_code() const noexcept -> size {
  return hash_code::combine(culture_);
}

auto assembly_culture_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto assembly_culture_attribute::create(const string& culture) -> assembly_culture_attribute {
  __assembly_culture_attribute__() = xtd::new_sptr<xtd::reflection::assembly_culture_attribute>(culture);
  return assembly_culture_attribute {culture};
}

auto __assembly_culture_attribute__() -> sptr<assembly_culture_attribute>& {
  static auto culture = xtd::sptr<xtd::reflection::assembly_culture_attribute> {};
  return culture;
}
