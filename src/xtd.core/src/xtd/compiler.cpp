#include "../../include/xtd/compiler.h"
#include "../../include/xtd/argument_exception.h"
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
  if (compiler_id() == xtd::compiler_id::visual_studio) {
    // https://learn.microsoft.com/fr-fr/cpp/overview/compiler-versions?view=msvc-170
    if (version().major() == 19 && version().minor() >= 30 && version().minor() <= 40) return "Visual Studio 2022";
    else if (version().major() == 19 && version().minor() >= 20 && version().minor() <= 29) return "Visual Studio 2019";
    else if (version().major() == 19 && version().minor() >= 10 && version().minor() <= 16) return "Visual Studio 2017";
    else if (version().major() == 19 && version().minor() == 0) return "Visual Studio 2015";
    else if (version().major() == 18 && version().minor() == 0) return "Visual Studio 2013";
    else if (version().major() == 17 && version().minor() == 0) return "Visual Studio 2012";
    else if (version().major() == 16 && version().minor() == 0) return "Visual Studio 2010";
    else if (version().major() == 15 && version().minor() == 0) return "Visual Studio 2008";
    else if (version().major() == 14 && version().minor() == 0) return "Visual Studio 2005";
    else if (version().major() == 13 && version().minor() == 10) return "Visual Studio .NET 2003";
    else if (version().major() == 13 && version().minor() == 0) return "Visual Studio .NET 2002";
    else if (version().major() == 12 && version().minor() == 0) return "Visual Studio";
    else return ustring::format("Visual Studio");
  }
  
  static std::map<xtd::compiler_id, xtd::ustring> names {{compiler_id::unknown, "<unknown>"}, {compiler_id::visual_studio, "Visual Studio"}, {compiler_id::clang, "clang"}, {compiler_id::gcc, "gcc"}};
  return names[compiler_id()];
}

xtd::ustring compiler::version_string() const noexcept {
  if (compiler_id() == xtd::compiler_id::visual_studio) {
    // https://learn.microsoft.com/fr-fr/cpp/overview/compiler-versions?view=msvc-170
    if (version().major() == 19 && version().minor() == 40) return ustring::format("{} 2022 version 17.10", name());
    else if (version().major() == 19 && version().minor() == 39) return ustring::format("{} version 17.9", name());
    else if (version().major() == 19 && version().minor() == 38) return ustring::format("{} version 17.8", name());
    else if (version().major() == 19 && version().minor() == 37) return ustring::format("{} version 17.7", name());
    else if (version().major() == 19 && version().minor() == 36) return ustring::format("{} version 17.6", name());
    else if (version().major() == 19 && version().minor() == 35) return ustring::format("{} version 17.5", name());
    else if (version().major() == 19 && version().minor() == 34) return ustring::format("{} version 17.4", name());
    else if (version().major() == 19 && version().minor() == 33) return ustring::format("{} version 17.3", name());
    else if (version().major() == 19 && version().minor() == 32) return ustring::format("{} version 17.2", name());
    else if (version().major() == 19 && version().minor() == 31) return ustring::format("{} version 17.1", name());
    else if (version().major() == 19 && version().minor() == 30) return ustring::format("{} RTW 17.0", name());
    else if (version().major() == 19 && version().minor() == 29 && version().build() == 30129) return ustring::format("{} version 16.11", name());
    else if (version().major() == 19 && version().minor() == 29 && version().build() == 29917) return ustring::format("{} version 16.10", name());
    else if (version().major() == 19 && version().minor() == 28 && version().build() == 29910) return ustring::format("{} version 16.9", name());
    else if (version().major() == 19 && version().minor() == 28 && version().build() == 29333) return ustring::format("{} version 16.8", name());
    else if (version().major() == 19 && version().minor() == 27) return ustring::format("{} version 16.7", name());
    else if (version().major() == 19 && version().minor() == 26) return ustring::format("{} version 16.6", name());
    else if (version().major() == 19 && version().minor() == 25) return ustring::format("{} version 16.5", name());
    else if (version().major() == 19 && version().minor() == 24) return ustring::format("{} version 16.4", name());
    else if (version().major() == 19 && version().minor() == 23) return ustring::format("{} version 16.3", name());
    else if (version().major() == 19 && version().minor() == 22) return ustring::format("{} version 16.2", name());
    else if (version().major() == 19 && version().minor() == 21) return ustring::format("{} version 16.1", name());
    else if (version().major() == 19 && version().minor() == 20) return ustring::format("{} RTW 16.0", name());
    else if (version().major() == 19 && version().minor() == 16) return ustring::format("{} version 15.9", name());
    else if (version().major() == 19 && version().minor() == 15) return ustring::format("{} version 15.8", name());
    else if (version().major() == 19 && version().minor() == 14) return ustring::format("{} version 15.7", name());
    else if (version().major() == 19 && version().minor() == 13) return ustring::format("{} version 15.6", name());
    else if (version().major() == 19 && version().minor() == 12) return ustring::format("{} version 15.5", name());
    else if (version().major() == 19 && version().minor() == 11) return ustring::format("{} version 15.3", name());
    else if (version().major() == 19 && version().minor() == 10) return ustring::format("{} RTW (15.0)", name());
    else if (version().major() == 19 && version().minor() == 0) return ustring::format("{} (14.0)", name());
    else if (version().major() == 18 && version().minor() == 0) return ustring::format("{} (12.0)", name());
    else if (version().major() == 17 && version().minor() == 0) return ustring::format("{} (11.0)", name());
    else if (version().major() == 16 && version().minor() == 0) return ustring::format("{} (10.0)", name());
    else if (version().major() == 15 && version().minor() == 0) return ustring::format("{} (9.0)", name());
    else if (version().major() == 14 && version().minor() == 0) return ustring::format("{} (8.0)", name());
    else if (version().major() == 13 && version().minor() == 10) return ustring::format("{} (7.1)", name());
    else if (version().major() == 13 && version().minor() == 0) return ustring::format("{} (7.0)", name());
    else if (version().major() == 12 && version().minor() == 0) return ustring::format("{} 6.0", name());
    else return ustring::format("{} (MSVC {})", name(), version());
  }
  
  return ustring::format("{} {}", name(), version());
}

const xtd::version& compiler::version() const noexcept {
  return version_;
}

xtd::ustring compiler::to_string() const noexcept {
  return version_string();
}

