#include "../../../include/xtd/reflection/assembly_company_attribute.h"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_company_attribute::assembly_company_attribute(const ustring& company) : company_(company) {}

assembly_company_attribute::assembly_company_attribute(const ustring& company, const object& executing_assembly) : company_(company) {
  __assembly_company_attribute__() = xtd::new_sptr<xtd::reflection::assembly_company_attribute>(company);
}

const ustring& assembly_company_attribute::company() const noexcept {
  return company_;
}

xtd::sptr<object> assembly_company_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_company_attribute>& __assembly_company_attribute__() {
  static auto company = xtd::sptr<xtd::reflection::assembly_company_attribute> {};
  return company;
}
