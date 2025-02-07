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

bool assembly_product_attribute::equals(const object& obj) const noexcept {
  return is<assembly_product_attribute>(obj) && equals(static_cast<const assembly_product_attribute&>(obj));
}

bool assembly_product_attribute::equals(const assembly_product_attribute& other) const noexcept {
  return product_ == other.product_;
}

size assembly_product_attribute::get_hash_code() const noexcept {
  return hash_code::combine(product_);
}

xtd::sptr<object> assembly_product_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_product_attribute>& __assembly_product_attribute__() {
  static auto product = xtd::sptr<xtd::reflection::assembly_product_attribute> {};
  return product;
}
