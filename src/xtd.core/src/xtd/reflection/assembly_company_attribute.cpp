#include "../../../include/xtd/reflection/assembly_company_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_company_attribute::assembly_company_attribute(const string& company) : company_(company) {}

assembly_company_attribute::assembly_company_attribute(const string& company, const object& executing_assembly) : company_(company) {
  __assembly_company_attribute__() = xtd::new_sptr<xtd::reflection::assembly_company_attribute>(company);
}

const string& assembly_company_attribute::company() const noexcept {
  return company_;
}

bool assembly_company_attribute::equals(const object& obj) const noexcept {
  return is<assembly_company_attribute>(obj) && equals(static_cast<const assembly_company_attribute&>(obj));
}

bool assembly_company_attribute::equals(const assembly_company_attribute& other) const noexcept {
  return company_ == other.company_;
}

size assembly_company_attribute::get_hash_code() const noexcept {
  return hash_code::combine(company_);
}

xtd::sptr<object> assembly_company_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_company_attribute>& __assembly_company_attribute__() {
  static auto company = xtd::sptr<xtd::reflection::assembly_company_attribute> {};
  return company;
}
