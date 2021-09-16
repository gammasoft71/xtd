#include "../../include/xtd/version.h"
#include "../../include/xtd/as.h"
#include "../../include/xtd/is.h"
#include "../../include/xtd/collections/specialized/string_vector.h"
#include "../../include/xtd/argument_out_of_range_exception.h"
#include "../../include/xtd/format_exception.h"
#include <sstream>
#include <regex>

using namespace std;
using namespace xtd;

version::version(const ustring& ver) {
  *this = parse(ver);
}

version::version(int32_t major, int32_t minor) : major_(major), minor_(minor) {
  if (major < 0 || minor < 0) throw argument_out_of_range_exception(csf_);
}

version::version(int32_t major, int32_t minor, int32_t build) : major_(major), minor_(minor), build_(build) {
  if (major < 0 || minor < 0 || build < 0) throw argument_out_of_range_exception(csf_);
}

version::version(int32_t major, int32_t minor, int32_t build, int32_t revision) : major_(major), minor_(minor), build_(build), revision_(revision) {
  if (major < 0 || minor < 0 || build < 0 || revision < 0) throw argument_out_of_range_exception(csf_);
}

bool version::operator==(const version& v) const noexcept {
  return major_ == v.major_ && minor_ == v.minor_ && build_ == v.build_ && revision_ == v.revision_;
}

bool version::operator!=(const version& v) const noexcept {
  return !operator==(v);
}

std::ostream& xtd::operator<<(std::ostream& os, const version& ver) noexcept {
  return os << ver.to_string();
}

int32_t version::build() const noexcept {
  return build_;
}

int32_t version::major() const noexcept {
  return major_;
}

int16_t version::major_revision() const noexcept {
  return as<int16_t>((revision_ & 0xFFFF0000) >> 16);
}

int32_t version::minor() const noexcept {
  return minor_;
}

int16_t version::mainor_revision() const noexcept {
  return as<int16_t>(revision_ & 0x0000FFFF);
}

int32_t version::revision() const noexcept {
  return revision_;
}

int32_t version::compare_to(const object& obj) const noexcept {
  if (!is<version>(&obj)) return 1;
  return compare_to(static_cast<const version&>(obj));
}

int32_t version::compare_to(const version& value) const noexcept {
  if (major_ < value.major_) return -1;
  if (major_ > value.major_) return 1;
  if (minor_ < value.minor_) return -1;
  if (minor_ > value.minor_) return 1;
  if (build_ < value.build_) return -1;
  if (build_ > value.build_) return 1;
  if (revision_ < value.revision_) return -1;
  if (revision_ > value.revision_) return 1;
  return 0;
}

version version::parse(const xtd::ustring& ver) {
  std::regex rgx("\\.");
  xtd::collections::specialized::string_vector versions;
  for (std::sregex_token_iterator it(ver.begin(), ver.end(), rgx, -1), end; it != end; ++it)
    versions.push_back(it->str());
  
  switch (versions.size()) {
    case 2: return version(ustring::parse<int32_t>(versions[0]), ustring::parse<int32_t>(versions[1]));
    case 3: return version(ustring::parse<int32_t>(versions[0]), ustring::parse<int32_t>(versions[1]), ustring::parse<int32_t>(versions[2]));
    case 4: return version(ustring::parse<int32_t>(versions[0]), ustring::parse<int32_t>(versions[1]), ustring::parse<int32_t>(versions[2]), ustring::parse<int32_t>(versions[3]));
  }
  
  throw xtd::argument_exception(csf_);
}

bool version::try_parse(const xtd::ustring& ver, version& result) noexcept {
  try {
    result = parse(ver);
    return true;
  } catch (...) {
    return false;
  }
}

xtd::ustring version::to_string() const noexcept {
  return to_string(2 + (build_ != -1 ? 1 : 0) + (revision_ != -1 ? 1 : 0));
}

xtd::ustring version::to_string(size_t field_count) const {
  if (field_count > 4 || (field_count >= 3 && build_ == -1) || (field_count == 4 && revision_ == -1))
    throw xtd::argument_exception("Field count invalid"_t, current_stack_frame_);
  std::stringstream result;
  if (field_count >= 1)
    result << std::to_string(major_);
  if (field_count >= 2)
    result << "." << std::to_string(minor_);
  if (field_count >= 3)
    result << "." << std::to_string(build_);
  if (field_count == 4)
    result << "." << std::to_string(revision_);
  return result.str();
}
