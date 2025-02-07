#include "../../../include/xtd/reflection/assembly_name_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_name_attribute::assembly_name_attribute(const string& name) : name_(name) {
}

assembly_name_attribute::assembly_name_attribute(const string& name, const object& executing_assembly) : name_(name) {
  __assembly_name_attribute__() = xtd::new_sptr<xtd::reflection::assembly_name_attribute>(name);
}

const string& assembly_name_attribute::name() const noexcept {
  return name_;
}

bool assembly_name_attribute::equals(const object& obj) const noexcept {
  return is<assembly_name_attribute>(obj) && equals(static_cast<const assembly_name_attribute&>(obj));
}

bool assembly_name_attribute::equals(const assembly_name_attribute& other) const noexcept {
  return name_ == other.name_;
}

size assembly_name_attribute::get_hash_code() const noexcept {
  return hash_code::combine(name_);
}

xtd::sptr<object> assembly_name_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_name_attribute>& __assembly_name_attribute__() {
  static auto title = xtd::sptr<xtd::reflection::assembly_name_attribute> {};
  return title;
}
