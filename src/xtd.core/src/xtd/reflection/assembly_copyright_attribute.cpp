#include "../../../include/xtd/reflection/assembly_copyright_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_copyright_attribute::assembly_copyright_attribute(const string& copyright) : copyright_(copyright) {
}

auto assembly_copyright_attribute::copyright() const noexcept -> const string& {
  return copyright_;
}

auto assembly_copyright_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_copyright_attribute>(obj) && equals(static_cast<const assembly_copyright_attribute&>(obj));
}

auto assembly_copyright_attribute::equals(const assembly_copyright_attribute& other) const noexcept -> bool {
  return copyright_ == other.copyright_;
}

auto assembly_copyright_attribute::get_hash_code() const noexcept -> size {
  return hash_code::combine(copyright_);
}

auto assembly_copyright_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto assembly_copyright_attribute::create(const string& copyright) -> assembly_copyright_attribute {
  __assembly_copyright_attribute__() = xtd::new_sptr<xtd::reflection::assembly_copyright_attribute>(copyright);
  return assembly_copyright_attribute {copyright};
}

auto __assembly_copyright_attribute__() -> sptr<assembly_copyright_attribute>& {
  static auto copyright = xtd::sptr<xtd::reflection::assembly_copyright_attribute> {};
  return copyright;
}
