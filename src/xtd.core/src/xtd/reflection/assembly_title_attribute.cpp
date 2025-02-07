#include "../../../include/xtd/reflection/assembly_title_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_title_attribute::assembly_title_attribute(const string& title) : title_(title) {
}

assembly_title_attribute::assembly_title_attribute(const string& title, const object& executing_assembly) : title_(title) {
  __assembly_title_attribute__() = xtd::new_sptr<xtd::reflection::assembly_title_attribute>(title);
}

const string& assembly_title_attribute::title() const noexcept {
  return title_;
}

bool assembly_title_attribute::equals(const object& obj) const noexcept {
  return is<assembly_title_attribute>(obj) && equals(static_cast<const assembly_title_attribute&>(obj));
}

bool assembly_title_attribute::equals(const assembly_title_attribute& other) const noexcept {
  return title_ == other.title_;
}

size assembly_title_attribute::get_hash_code() const noexcept {
  return hash_code::combine(title_);
}

xtd::sptr<object> assembly_title_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_title_attribute>& __assembly_title_attribute__() {
  static auto title = xtd::sptr<xtd::reflection::assembly_title_attribute> {};
  return title;
}
