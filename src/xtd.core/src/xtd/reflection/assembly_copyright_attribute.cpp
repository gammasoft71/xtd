#include "../../../include/xtd/reflection/assembly_copyright_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_copyright_attribute::assembly_copyright_attribute(const string& copyright) : copyright_(copyright) {
}

assembly_copyright_attribute::assembly_copyright_attribute(const string& copyright, const object& executing_assembly) : copyright_(copyright) {
  __assembly_copyright_attribute__() = xtd::new_sptr<xtd::reflection::assembly_copyright_attribute>(copyright);
}

const string& assembly_copyright_attribute::copyright() const noexcept {
  return copyright_;
}

bool assembly_copyright_attribute::equals(const object& obj) const noexcept {
  return is<assembly_copyright_attribute>(obj) && equals(static_cast<const assembly_copyright_attribute&>(obj));
}

bool assembly_copyright_attribute::equals(const assembly_copyright_attribute& other) const noexcept {
  return copyright_ == other.copyright_;
}

size assembly_copyright_attribute::get_hash_code() const noexcept {
  return hash_code::combine(copyright_);
}

xtd::sptr<object> assembly_copyright_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_copyright_attribute>& __assembly_copyright_attribute__() {
  static auto copyright = xtd::sptr<xtd::reflection::assembly_copyright_attribute> {};
  return copyright;
}
