#include "../../../include/xtd/reflection/assembly_copyright_attribute.h"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_copyright_attribute::assembly_copyright_attribute(const ustring& copyright) : copyright_(copyright) {
}

assembly_copyright_attribute::assembly_copyright_attribute(const ustring& copyright, const object& executing_assembly) : copyright_(copyright) {
  __assembly_copyright_attribute__() = make_shared<xtd::reflection::assembly_copyright_attribute>(copyright);
}

shared_ptr<object> assembly_copyright_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

shared_ptr<xtd::reflection::assembly_copyright_attribute>& __assembly_copyright_attribute__() {
  static shared_ptr<xtd::reflection::assembly_copyright_attribute> copyright;
  return copyright;
}
