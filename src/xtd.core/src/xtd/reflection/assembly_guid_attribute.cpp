#include "../../../include/xtd/reflection/assembly_guid_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_guid_attribute::assembly_guid_attribute(const string& guid) : guid_(guid) {
}

assembly_guid_attribute::assembly_guid_attribute(const string& guid, const object& executing_assembly) : guid_(guid) {
  __assembly_guid_attribute__() = xtd::new_sptr<xtd::reflection::assembly_guid_attribute>(guid);
}

auto assembly_guid_attribute::guid() const noexcept -> const string& {
  return guid_;
}

auto assembly_guid_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_guid_attribute>(obj) && equals(static_cast<const assembly_guid_attribute&>(obj));
}

auto assembly_guid_attribute::equals(const assembly_guid_attribute& other) const noexcept -> bool {
  return guid_ == other.guid_;
}

auto assembly_guid_attribute::get_hash_code() const noexcept -> size {
  return hash_code::combine(guid_);
}

auto assembly_guid_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto __assembly_guid_attribute__() -> sptr<assembly_guid_attribute>& {
  static auto guid = xtd::sptr<xtd::reflection::assembly_guid_attribute> {};
  return guid;
}
