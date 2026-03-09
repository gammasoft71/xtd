#include "../../../include/xtd/reflection/assembly_name_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_name_attribute::assembly_name_attribute(const string& name) : name_(name) {
}

auto assembly_name_attribute::name() const noexcept -> const string& {
  return name_;
}

auto assembly_name_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_name_attribute>(obj) && equals(static_cast<const assembly_name_attribute&>(obj));
}

auto assembly_name_attribute::equals(const assembly_name_attribute& other) const noexcept -> bool {
  return name_ == other.name_;
}

auto assembly_name_attribute::get_hash_code() const noexcept -> size {
  return hash_code::combine(name_);
}

auto assembly_name_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto assembly_name_attribute::create(const string& name) -> assembly_name_attribute {
  __assembly_name_attribute__() = xtd::new_sptr<xtd::reflection::assembly_name_attribute>(name);
  return assembly_name_attribute {name};
}

auto __assembly_name_attribute__() -> sptr<assembly_name_attribute>& {
  static auto title = xtd::sptr<xtd::reflection::assembly_name_attribute> {};
  return title;
}
