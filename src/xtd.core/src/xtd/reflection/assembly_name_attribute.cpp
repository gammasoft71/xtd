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

xtd::sptr<object> assembly_name_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_name_attribute>& __assembly_name_attribute__() {
  static auto title = xtd::sptr<xtd::reflection::assembly_name_attribute> {};
  return title;
}
