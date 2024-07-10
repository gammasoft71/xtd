#include "../../../include/xtd/reflection/assembly_culture_attribute.h"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_culture_attribute::assembly_culture_attribute(const ustring& culture) : culture_(culture) {
}

assembly_culture_attribute::assembly_culture_attribute(const ustring& culture, const object& executing_assembly) : culture_(culture) {
  __assembly_culture_attribute__() = xtd::new_sptr<xtd::reflection::assembly_culture_attribute>(culture);
}

const ustring& assembly_culture_attribute::culture() const noexcept {
  return culture_;
}

xtd::sptr<object> assembly_culture_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_culture_attribute>& __assembly_culture_attribute__() {
  static auto culture = xtd::sptr<xtd::reflection::assembly_culture_attribute> {};
  return culture;
}
