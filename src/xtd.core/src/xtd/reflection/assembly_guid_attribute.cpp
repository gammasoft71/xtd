#include "../../../include/xtd/reflection/assembly_guid_attribute.h"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_guid_attribute::assembly_guid_attribute(const ustring& guid) : guid_(guid) {
}

assembly_guid_attribute::assembly_guid_attribute(const ustring& guid, const object& executing_assembly) : guid_(guid) {
  __assembly_guid_attribute__() = make_shared<xtd::reflection::assembly_guid_attribute>(guid);
}

const ustring& assembly_guid_attribute::guid() const noexcept {
  return guid_;
}

xtd::sptr<object> assembly_guid_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_guid_attribute>& __assembly_guid_attribute__() {
  static auto guid = xtd::sptr<xtd::reflection::assembly_guid_attribute> {};
  return guid;
}
