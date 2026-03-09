#include "../../../include/xtd/reflection/assembly_file_version_attribute.hpp"

using namespace xtd;
using namespace xtd::reflection;

assembly_file_version_attribute::assembly_file_version_attribute(const string& version) : version_(version) {
}

auto assembly_file_version_attribute::version() const noexcept -> const string& {
  return version_;
}

auto assembly_file_version_attribute::equals(const object& obj) const noexcept -> bool {
  return is<assembly_file_version_attribute>(obj) && equals(static_cast<const assembly_file_version_attribute&>(obj));
}

auto assembly_file_version_attribute::equals(const assembly_file_version_attribute& other) const noexcept -> bool {
  return version_ == other.version_;
}

auto assembly_file_version_attribute::get_hash_code() const noexcept -> size {
  return hash_code::combine(version_);
}

auto assembly_file_version_attribute::get_type_id() const noexcept -> sptr<object> {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

auto assembly_file_version_attribute::create(const string& version) -> assembly_file_version_attribute {
  __assembly_file_version_attribute__() = xtd::new_sptr<xtd::reflection::assembly_file_version_attribute>(version);
  return assembly_file_version_attribute {version};
}

auto __assembly_file_version_attribute__() -> sptr<assembly_file_version_attribute>& {
  static auto version = xtd::sptr<xtd::reflection::assembly_file_version_attribute> {};
  return version;
}
