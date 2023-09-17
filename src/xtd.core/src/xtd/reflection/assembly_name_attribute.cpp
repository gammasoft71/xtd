#include "../../../include/xtd/reflection/assembly_name_attribute.h"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_name_attribute::assembly_name_attribute(const ustring& name) : name_(name) {
}

assembly_name_attribute::assembly_name_attribute(const ustring& name, const object& executing_assembly) : name_(name) {
  __assembly_name_attribute__() = make_shared<xtd::reflection::assembly_name_attribute>(name);
}

const ustring& assembly_name_attribute::name() const noexcept {
  return name_;
}

shared_ptr<object> assembly_name_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

shared_ptr<xtd::reflection::assembly_name_attribute>& __assembly_name_attribute__() {
  static auto title = shared_ptr<xtd::reflection::assembly_name_attribute> {};
  return title;
}
