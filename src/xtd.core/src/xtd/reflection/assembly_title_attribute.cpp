#include "../../../include/xtd/reflection/assembly_title_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_title_attribute::assembly_title_attribute(const string& title) : title_(title) {
}

assembly_title_attribute::assembly_title_attribute(const string& title, const object& executing_assembly) : title_(title) {
  __assembly_title_attribute__() = xtd::new_sptr<xtd::reflection::assembly_title_attribute>(title);
}

auto assembly_title_attribute::title() const noexcept -> const string& {
  return title_;
}

auto assembly_title_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_title_attribute>(obj) && equals(static_cast<const assembly_title_attribute&>(obj));
}

auto assembly_title_attribute::equals(const assembly_title_attribute& other) const noexcept -> bool {
  return title_ == other.title_;
}

auto assembly_title_attribute::get_hash_code() const noexcept -> size {
  return hash_code::combine(title_);
}

auto assembly_title_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto __assembly_title_attribute__() -> sptr<assembly_title_attribute>& {
  static auto title = xtd::sptr<xtd::reflection::assembly_title_attribute> {};
  return title;
}
