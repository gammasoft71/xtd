#include "../../include/xtd/version.h"
#include "../../include/xtd/as.h"
#include "../../include/xtd/is.h"
#include "../../include/xtd/collections/specialized/string_vector.h"
#include "../../include/xtd/argument_out_of_range_exception.h"
#include "../../include/xtd/format_exception.h"
#include <regex>

using namespace std;
using namespace xtd;

version::version(const ustring& version) {
  *this = parse(version);
}

version::version(int32 major, int32 minor) : major_(major), minor_(minor) {
  if (major < 0 || minor < 0) throw argument_out_of_range_exception {csf_};
}

version::version(int32 major, int32 minor, int32 build) : major_(major), minor_(minor), build_(build) {
  if (major < 0 || minor < 0 || build < 0) throw argument_out_of_range_exception {csf_};
}

version::version(int32 major, int32 minor, int32 build, int32 revision) : major_(major), minor_(minor), build_(build), revision_(revision) {
  if (major < 0 || minor < 0 || build < 0 || revision < 0) throw argument_out_of_range_exception {csf_};
}

int32 version::build() const noexcept {
  return build_;
}

int32 version::major() const noexcept {
  return major_;
}

int16 version::major_revision() const noexcept {
  return as<int16>((revision_ & 0xFFFF0000) >> 16);
}

int32 version::minor() const noexcept {
  return minor_;
}

int16 version::minor_revision() const noexcept {
  return as<int16>(revision_ & 0x0000FFFF);
}

int32 version::revision() const noexcept {
  return revision_;
}

int32 version::compare_to(const version& value) const noexcept {
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

bool version::equals(const version& v) const noexcept {
  return major_ == v.major_ && minor_ == v.minor_ && build_ == v.build_ && revision_ == v.revision_;
}

version version::parse(const xtd::ustring& input) {
  auto rgx = regex {"\\."};
  auto versions = xtd::collections::specialized::string_vector {};
  for (auto it = sregex_token_iterator {input.begin(), input.end(), rgx, -1}, end = sregex_token_iterator {}; it != end; ++it)
    versions.push_back(it->str());
    
  switch (versions.size()) {
    case 2: return version {ustring::parse<int32>(versions[0]), ustring::parse<int32>(versions[1])};
    case 3: return version {ustring::parse<int32>(versions[0]), ustring::parse<int32>(versions[1]), ustring::parse<int32>(versions[2])};
    case 4: return version {ustring::parse<int32>(versions[0]), ustring::parse<int32>(versions[1]), ustring::parse<int32>(versions[2]), ustring::parse<int32>(versions[3])};
  }
  
  throw xtd::argument_exception {csf_};
}

bool version::try_parse(const xtd::ustring& input, version& result) noexcept {
  try {
    result = parse(input);
    return true;
  } catch (...) {
    return false;
  }
}

xtd::ustring version::to_string() const noexcept {
  try {
    return to_string(2 + (build_ != -1 ? 1 : 0) + (revision_ != -1 ? 1 : 0));
  } catch (...) {
    return "";
  }
}

xtd::ustring version::to_string(size_t field_count) const {
  if (field_count > 4 || (field_count >= 3 && build_ == -1) || (field_count == 4 && revision_ == -1)) throw xtd::argument_exception {"Field count invalid"_t, csf_};
  auto result = ustring::empty_string;
  if (field_count >= 1) result += ustring::format("{}", major_);
  if (field_count >= 2) result += ustring::format(".{}", minor_);
  if (field_count >= 3) result += ustring::format(".{}", build_);
  if (field_count == 4) result += ustring::format(".{}", revision_);
  return result;
}
