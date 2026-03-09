#include "../../../include/xtd/reflection/assembly_company_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_company_attribute::assembly_company_attribute(const string& company) : company_(company) {
}

auto assembly_company_attribute::company() const noexcept -> const string& {
  return company_;
}

auto assembly_company_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_company_attribute>(obj) && equals(static_cast<const assembly_company_attribute&>(obj));
}

auto assembly_company_attribute::equals(const assembly_company_attribute& other) const noexcept -> bool {
  return company_ == other.company_;
}

auto assembly_company_attribute::get_hash_code() const noexcept -> size {
  return hash_code::combine(company_);
}

auto assembly_company_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto assembly_company_attribute::create(const xtd::string& company) -> assembly_company_attribute {
  __assembly_company_attribute__() = xtd::new_sptr<xtd::reflection::assembly_company_attribute>(company);
  return assembly_company_attribute {company};
}

auto __assembly_company_attribute__() -> sptr<assembly_company_attribute>& {
  static auto company = xtd::sptr<xtd::reflection::assembly_company_attribute> {};
  return company;
}
