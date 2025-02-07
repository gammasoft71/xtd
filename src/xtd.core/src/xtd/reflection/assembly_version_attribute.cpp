#include "../../../include/xtd/reflection/assembly_version_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_version_attribute::assembly_version_attribute(const string& version) : version_(version) {
}

assembly_version_attribute::assembly_version_attribute(const string& version, const object& executing_assembly) : version_(version) {
  __assembly_version_attribute__() = xtd::new_sptr<xtd::reflection::assembly_version_attribute>(version);
}

const string& assembly_version_attribute::version() const noexcept {
  return version_;
}

bool assembly_version_attribute::equals(const object& obj) const noexcept {
  return is<assembly_version_attribute>(obj) && equals(static_cast<const assembly_version_attribute&>(obj));
}

bool assembly_version_attribute::equals(const assembly_version_attribute& other) const noexcept {
  return version_ == other.version_;
}

size assembly_version_attribute::get_hash_code() const noexcept {
  return hash_code::combine(version_);
}

xtd::sptr<object> assembly_version_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

xtd::sptr<xtd::reflection::assembly_version_attribute>& __assembly_version_attribute__() {
  static auto version = xtd::sptr<xtd::reflection::assembly_version_attribute> {};
  return version;
}
