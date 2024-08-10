#include "../../../include/xtd/reflection/assembly_copyright_attribute.h"

using namespace xtd;
using namespace xtd::reflection;

assembly_copyright_attribute::assembly_copyright_attribute(const ustring& copyright) : copyright_(copyright) {
}

assembly_copyright_attribute::assembly_copyright_attribute(const ustring& copyright, const object& executing_assembly) : copyright_(copyright) {
  __assembly_copyright_attribute__() = xtd::new_sptr<xtd::reflection::assembly_copyright_attribute>(copyright);
}

const ustring& assembly_copyright_attribute::copyright() const noexcept {
  return copyright_;
}

xtd::sptr<object> assembly_copyright_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_copyright_attribute>& __assembly_copyright_attribute__() {
  static auto copyright = xtd::sptr<xtd::reflection::assembly_copyright_attribute> {};
  return copyright;
}
