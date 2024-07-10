#include "../../../include/xtd/reflection/assembly_description_attribute.h"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_description_attribute::assembly_description_attribute(const ustring& description) : description_(description) {
}

assembly_description_attribute::assembly_description_attribute(const ustring& description, const object& executing_assembly) : description_(description) {
  __assembly_description_attribute__() = make_shared<xtd::reflection::assembly_description_attribute>(description);
}

const ustring& assembly_description_attribute::description() const noexcept {
  return description_;
}

xtd::sptr<object> assembly_description_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_description_attribute>& __assembly_description_attribute__() {
  static auto description = xtd::sptr<xtd::reflection::assembly_description_attribute> {};
  return description;
}
