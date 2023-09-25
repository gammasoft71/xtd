#include "../../../include/xtd/reflection/assembly_file_version_attribute"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_file_version_attribute::assembly_file_version_attribute(const ustring& version) : version_(version) {
}

assembly_file_version_attribute::assembly_file_version_attribute(const ustring& version, const object& executing_assembly) : version_(version) {
  __assembly_file_version_attribute__() = make_shared<xtd::reflection::assembly_file_version_attribute>(version);
}

const ustring& assembly_file_version_attribute::version() const noexcept {
  return version_;
}

shared_ptr<object> assembly_file_version_attribute::get_type_id() const noexcept {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

shared_ptr<xtd::reflection::assembly_file_version_attribute>& __assembly_file_version_attribute__() {
  static auto version = shared_ptr<xtd::reflection::assembly_file_version_attribute> {};
  return version;
}
