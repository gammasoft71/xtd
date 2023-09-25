#include "../../../include/xtd/reflection/assembly_product_attribute"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_product_attribute::assembly_product_attribute(const ustring& product) : product_(product) {
}

assembly_product_attribute::assembly_product_attribute(const ustring& product, const object& executing_assembly) : product_(product) {
  __assembly_product_attribute__() = make_shared<xtd::reflection::assembly_product_attribute>(product);
}

const ustring& assembly_product_attribute::product() const noexcept {
  return product_;
}

shared_ptr<object> assembly_product_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

shared_ptr<xtd::reflection::assembly_product_attribute>& __assembly_product_attribute__() {
  static auto product = shared_ptr<xtd::reflection::assembly_product_attribute> {};
  return product;
}
