#include "../../include/xtd/compiler"
#include "../../include/xtd/argument_exception"
#include <algorithm>

using namespace xtd;

compiler::compiler(xtd::compiler_id compiler_id, const xtd::version& version, xtd::build_type build_type, bool is_64_bit) : compiler_id_(compiler_id), version_(version), build_type_(build_type), is_64_bit_(is_64_bit) {
  if (!enum_object<>::is_defined(compiler_id)) throw argument_exception {csf_};
}

xtd::build_type compiler::build_type() const noexcept {
  return build_type_;
}

xtd::compiler_id compiler::compiler_id() const noexcept {
  return compiler_id_;
}

bool compiler::is_build_type_debug() const noexcept {
  return build_type_ == xtd::build_type::debug;
}

bool compiler::is_64_bit() noexcept {
  return is_64_bit_;
}

xtd::ustring compiler::name() const noexcept {
  static std::map<xtd::compiler_id, xtd::ustring> names {{compiler_id::unknown, "<unknown>"}, {compiler_id::microsoft_visual_studio, "Microsoft Visual Studio"}, {compiler_id::clang, "clang"}, {compiler_id::gcc, "gcc"}};
  return names[compiler_id()];
}

xtd::ustring compiler::version_string() const noexcept {
  return ustring::format("{} {}", name(), version());
}

const xtd::version& compiler::version() const noexcept {
  return version_;
}

xtd::ustring compiler::to_string() const noexcept {
  return version_string();
}

