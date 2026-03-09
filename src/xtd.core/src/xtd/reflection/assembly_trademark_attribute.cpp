#include "../../../include/xtd/reflection/assembly_trademark_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_trademark_attribute::assembly_trademark_attribute(const string& trademark) : trademark_(trademark) {
}

auto assembly_trademark_attribute::trademark() const noexcept -> const string& {
  return trademark_;
}

auto assembly_trademark_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_trademark_attribute>(obj) && equals(static_cast<const assembly_trademark_attribute&>(obj));
}

auto assembly_trademark_attribute::equals(const assembly_trademark_attribute& other) const noexcept -> bool {
  return trademark_ == other.trademark_;
}

auto assembly_trademark_attribute::get_hash_code() const noexcept -> size {
  return hash_code::combine(trademark_);
}

auto assembly_trademark_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto assembly_trademark_attribute::create(const string& trademark) -> assembly_trademark_attribute {
  __assembly_trademark_attribute__() = xtd::new_sptr<xtd::reflection::assembly_trademark_attribute>(trademark);
  return assembly_trademark_attribute {trademark};
}

auto __assembly_trademark_attribute__() -> sptr<assembly_trademark_attribute>& {
  static auto trademark = xtd::sptr<xtd::reflection::assembly_trademark_attribute> {};
  return trademark;
}
