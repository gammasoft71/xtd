#include "../../include/xtd/version.hpp"
#include "../../include/xtd/as.hpp"
#include "../../include/xtd/is.hpp"
#include "../../include/xtd/collections/specialized/string_collection.hpp"
#include "../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../include/xtd/format_exception.hpp"
#include <regex>

using namespace xtd;
using namespace xtd::helpers;

version::version(const string& version) {
  *this = parse(version);
}

version::version(int32 major, int32 minor) : major_(major), minor_(minor) {
  if (major < 0 || minor < 0) throw_helper::throws(exception_case::argument_out_of_range);
}

version::version(int32 major, int32 minor, int32 build) : major_(major), minor_(minor), build_(build) {
  if (major < 0 || minor < 0 || build < 0) throw_helper::throws(exception_case::argument_out_of_range);
}

version::version(int32 major, int32 minor, int32 build, int32 revision) : major_(major), minor_(minor), build_(build), revision_(revision) {
  if (major < 0 || minor < 0 || build < 0 || revision < 0) throw_helper::throws(exception_case::argument_out_of_range);
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

bool version::equals(const object& obj) const noexcept {
  return is<version>(obj) && equals(static_cast<const version&>(obj));
}

bool version::equals(const version& v) const noexcept {
  return major_ == v.major_ && minor_ == v.minor_ && build_ == v.build_ && revision_ == v.revision_;
}

size version::get_hash_code() const noexcept {
  return hash_code::combine(major_, minor_, build_, revision_);
}

version version::parse(const xtd::string& input) {
  auto rgx = std::regex {"\\."};
  auto versions = xtd::collections::specialized::string_collection {};
  for (auto it = std::sregex_token_iterator {input.chars().begin(), input.chars().end(), rgx, -1}, end = std::sregex_token_iterator {}; it != end; ++it)
    versions.push_back(it->str());
    
  switch (versions.size()) {
    case 2: return version {string::parse<int32>(versions[0]), string::parse<int32>(versions[1])};
    case 3: return version {string::parse<int32>(versions[0]), string::parse<int32>(versions[1]), string::parse<int32>(versions[2])};
    case 4: return version {string::parse<int32>(versions[0]), string::parse<int32>(versions[1]), string::parse<int32>(versions[2]), string::parse<int32>(versions[3])};
  }
  
  throw_helper::throws(exception_case::argument);;
}

bool version::try_parse(const xtd::string& input, version& result) noexcept {
  try {
    result = parse(input);
    return true;
  } catch (...) {
    return false;
  }
}

xtd::string version::to_string() const noexcept {
  try {
    return to_string(2 + (build_ != -1 ? 1 : 0) + (revision_ != -1 ? 1 : 0));
  } catch (...) {
    return "";
  }
}

xtd::string version::to_string(size_t field_count) const {
  if (field_count > 4 || (field_count >= 3 && build_ == -1) || (field_count == 4 && revision_ == -1)) throw_helper::throws(exception_case::argument, "Field count invalid"_t);
  auto result = string::empty_string;
  if (field_count >= 1) result += string::format("{}", major_);
  if (field_count >= 2) result += string::format(".{}", minor_);
  if (field_count >= 3) result += string::format(".{}", build_);
  if (field_count == 4) result += string::format(".{}", revision_);
  return result;
}
