#include "../../../include/xtd/reflection/assembly_product_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_product_attribute::assembly_product_attribute(const string& product) : product_(product) {
}

assembly_product_attribute::assembly_product_attribute(const string& product, const object& executing_assembly) : product_(product) {
  __assembly_product_attribute__() = xtd::new_sptr<xtd::reflection::assembly_product_attribute>(product);
}

const string& assembly_product_attribute::product() const noexcept {
  return product_;
}

xtd::sptr<object> assembly_product_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_product_attribute>& __assembly_product_attribute__() {
  static auto product = xtd::sptr<xtd::reflection::assembly_product_attribute> {};
  return product;
}
