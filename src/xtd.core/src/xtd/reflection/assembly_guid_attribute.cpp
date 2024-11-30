#include "../../../include/xtd/reflection/assembly_guid_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_guid_attribute::assembly_guid_attribute(const string& guid) : guid_(guid) {
}

assembly_guid_attribute::assembly_guid_attribute(const string& guid, const object& executing_assembly) : guid_(guid) {
  __assembly_guid_attribute__() = xtd::new_sptr<xtd::reflection::assembly_guid_attribute>(guid);
}

const string& assembly_guid_attribute::guid() const noexcept {
  return guid_;
}

xtd::sptr<object> assembly_guid_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_guid_attribute>& __assembly_guid_attribute__() {
  static auto guid = xtd::sptr<xtd::reflection::assembly_guid_attribute> {};
  return guid;
}
