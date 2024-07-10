#include "../../../include/xtd/reflection/assembly_trademark_attribute.h"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_trademark_attribute::assembly_trademark_attribute(const ustring& trademark) : trademark_(trademark) {
}

assembly_trademark_attribute::assembly_trademark_attribute(const ustring& trademark, const object& executing_assembly) : trademark_(trademark) {
  __assembly_trademark_attribute__() = xtd::new_sptr<xtd::reflection::assembly_trademark_attribute>(trademark);
}

const ustring& assembly_trademark_attribute::trademark() const noexcept {
  return trademark_;
}

xtd::sptr<object> assembly_trademark_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_trademark_attribute>& __assembly_trademark_attribute__() {
  static auto trademark = xtd::sptr<xtd::reflection::assembly_trademark_attribute> {};
  return trademark;
}
