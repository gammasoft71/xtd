#include "../../../include/xtd/reflection/assembly_product_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_product_attribute::assembly_product_attribute(const string& product) : product_(product) {
}

auto assembly_product_attribute::product() const noexcept -> const string& {
  return product_;
}

auto assembly_product_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_product_attribute>(obj) && equals(static_cast<const assembly_product_attribute&>(obj));
}

auto assembly_product_attribute::equals(const assembly_product_attribute& other) const noexcept -> bool {
  return product_ == other.product_;
}

auto assembly_product_attribute::get_hash_code() const noexcept -> usize {
  return hash_code::combine(product_);
}

auto assembly_product_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto assembly_product_attribute::create(const string& product) -> assembly_product_attribute {
  __assembly_product_attribute__() = xtd::new_sptr<xtd::reflection::assembly_product_attribute>(product);
  return assembly_product_attribute {product};
}

auto __assembly_product_attribute__() -> sptr<assembly_product_attribute>& {
  static auto product = xtd::sptr<xtd::reflection::assembly_product_attribute> {};
  return product;
}
