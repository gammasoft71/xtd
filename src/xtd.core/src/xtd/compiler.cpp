#include "../../include/xtd/diagnostics/process.h"
#include "../../include/xtd/io/stream_reader.h"
#include "../../include/xtd/compiler.h"
#include "../../include/xtd/argument_exception.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

compiler::compiler(xtd::compiler_id compiler_id, const xtd::version& version, xtd::build_type build_type, bool is_64_bit) : compiler_id_(compiler_id), version_(version), build_type_(build_type), is_64_bit_(is_64_bit) {
  if (!enum_object<>::is_defined(compiler_id)) throw argument_exception {csf_};
}

xtd::ustring compiler::additional_information() const noexcept {
  if (compiler_id() == xtd::compiler_id::msvc) return get_msvc_additional_information();
  if (compiler_id() == xtd::compiler_id::apple_clang) return get_apple_clang_additional_information();
  return ustring::empty_string;
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
  static std::map<xtd::compiler_id, xtd::ustring> names {{compiler_id::unknown, "<unknown>"}, {compiler_id::msvc, "MSVC"}, {compiler_id::clang, "Clang"}, {compiler_id::gcc, "GCC"}, {compiler_id::apple_clang, "Apple Clang"}};
  return names[compiler_id()];
}

xtd::ustring compiler::version_string() const noexcept {
  if (compiler_id() == xtd::compiler_id::apple_clang || compiler_id() == xtd::compiler_id::clang) return get_compiler_version_string("clang");
  if (compiler_id() == xtd::compiler_id::gcc) return get_compiler_version_string("gcc");
  return ustring::format("{} {}", name(), version());
}

const xtd::version& compiler::version() const noexcept {
  return version_;
}

xtd::ustring compiler::to_string() const noexcept {
  return version_string();
}

xtd::ustring compiler::get_apple_clang_additional_information() const noexcept {
  // https://en.wikipedia.org/wiki/Xcode#:~:text=Starting%20with%20Xcode%204.2%2C%20the,end%20for%20the%20IDE%27s%20debugger.
  auto version_string = get_compiler_version_string("clang");
  if (version_string.contains("15.0.0 (clang-1500.3.9.4)")) return "Xcode 15.3";
  if (version_string.contains("15.0.0 (clang-1500.1.0.2.5)")) return "Xcode 15.2";
  if (version_string.contains("15.0.0 (clang-1500.1.0.2.5)")) return "Xcode 15.1";
  if (version_string.contains("15.0.0 (clang-1500.0.40.1)")) return "Xcode 15.0, 15.0.1";
  if (version_string.contains("14.0.3 (clang-1403.0.22.14.1)")) return "Xcode 14.3, 14.3.1";
  if (version_string.contains("14.0.0 (clang-1400.0.29.202)")) return "Xcode 14.1, 14.2";
  if (version_string.contains("14.0.0 (clang-1400.0.29.102)")) return "Xcode 14.0, 14.0.1";
  if (version_string.contains("13.1.6 (clang-1316.0.21.2.5)")) return "Xcode 13.4, 13.4.1";
  if (version_string.contains("13.1.6 (clang-1316.0.21.2.3)")) return "Xcode 13.3.1";
  if (version_string.contains("13.1.6 (clang-1316.0.21.2)")) return "Xcode 13.3";
  if (version_string.contains("13.0.0 (clang-1300.0.29.30)")) return "Xcode 13.2, 13.2.1";
  if (version_string.contains("13.0.0 (clang-1300.0.29.3)")) return "Xcode 13.0, 13.1";
  if (version_string.contains("12.0.5 (clang-1205.0.22.11)")) return "Xcode 12.5.1";
  if (version_string.contains("12.0.5 (clang-1205.0.22.9)")) return "Xcode 12.5";
  if (version_string.contains("12.0.0 (clang-1200.0.32.29)")) return "Xcode 12.4";
  if (version_string.contains("12.0.0 (clang-1200.0.32.28)")) return "Xcode 12.3";
  if (version_string.contains("12.0.0 (clang-1200.0.32.27)")) return "Xcode 12.2";
  if (version_string.contains("12.0.0 (clang-1200.0.32.21)")) return "Xcode 12.1, 12.1.1 RC";
  if (version_string.contains("12.0.0 (clang-1200.0.32.2)")) return "Xcode 12.0, 12.0.1";
  if (version_string.contains("11.0.3 (clang-1103.0.32.62)")) return "Xcode 11.5, 11.6, 11.7";
  if (version_string.contains("11.0.3 (clang-1103.0.32.59)")) return "Xcode 11.4.1";
  if (version_string.contains("11.0.3 (clang-1103.0.32.29)")) return "Xcode 11.4";
  if (version_string.contains("11.0.0 (clang-1100.0.33.17)")) return "Xcode 11.3.1";
  if (version_string.contains("11.0.0 (clang-1100.0.33.16)")) return "Xcode 11.3";
  if (version_string.contains("11.0.0 (clang-1100.0.33.12)")) return "Xcode 11.2, 11.2.1";
  if (version_string.contains("11.0.0 (clang-1100.0.33.8)")) return "Xcode 11.0, 11.1";
  if (version_string.contains("10.0.1 (clang-1001.0.46.4)")) return "Xcode 10.2.1, 10.3";
  if (version_string.contains("10.0.1 (clang-1001.0.46.3)")) return "Xcode 10.2";
  if (version_string.contains("10.0.0 (clang-1000.11.45.5)")) return "Xcode 10.1";
  if (version_string.contains("10.0.0 (clang-1000.11.45.2)")) return "Xcode 10.0";
  if (version_string.contains("9.1.0 (clang-902.0.39.2)")) return "Xcode 9.4, 9.4.1";
  if (version_string.contains("9.1.0 (clang-902.0.39.1)")) return "Xcode 9.3, 9.3.1";
  if (version_string.contains("9.0.0 (clang-900.0.39.2)")) return "Xcode 9.2";
  if (version_string.contains("9.0.0 (clang-900.0.38)")) return "Xcode 9.1";
  if (version_string.contains("9.0.0 (clang-900.0.37)")) return "Xcode 9.0";
  if (version_string.contains("8.1.0 (clang-802.0.42)")) return "Xcode 8.3.2, 8.3.3";
  if (version_string.contains("8.1.0 (clang-802.0.41)")) return "Xcode 8.3.1";
  if (version_string.contains("8.1.0 (clang-802.0.38)")) return "Xcode 8.3";
  if (version_string.contains("8.0.0 (clang-800.0.42.1)")) return "Xcode 8.1, 8.2, 8.2.1";
  if (version_string.contains("8.0.0 (clang-800.0.38)")) return "Xcode 8.0";
  if (version_string.contains("7.3.0 (clang-703.0.31)")) return "Xcode 7.3.1";
  if (version_string.contains("7.3.0 (clang-703.0.29)")) return "Xcode 7.3";
  if (version_string.contains("7.0.2 (clang-700.1.81)")) return "Xcode 7.2, 7.2.1";
  if (version_string.contains("7.0.0 (clang-700.1.76)")) return "Xcode 7.1";
  if (version_string.contains("7.0.0 (clang-700.0.72)")) return "Xcode 7.0, 7.0.1";
  if (version_string.contains("6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)")) return "Xcode 6.3.2, 6.4";
  if (version_string.contains("6.1.0 (clang-602.0.49) (based on LLVM 3.6.0svn)")) return "Xcode 6.3, 6.3.1";
  if (version_string.contains("6.0 (clang-600.0.57) (based on LLVM 3.5svn)")) return "Xcode 6.2";
  if (version_string.contains("6.0 (clang-600.0.56) (based on LLVM 3.5svn)")) return "Xcode 6.1.1";
  if (version_string.contains("6.0 (clang-600.0.54) (based on LLVM 3.5svn)")) return "Xcode 6.1";
  if (version_string.contains("6.0 (clang-600.0.51) (based on LLVM 3.5svn)")) return "Xcode 6.0.1";
  if (version_string.contains("5.1 (clang-503.0.40) (based on LLVM 3.4svn)")) return "Xcode 5.1.1";
  if (version_string.contains("5.1 (clang-503.0.38) (based on LLVM 3.4svn)")) return "Xcode 5.1";
  if (version_string.contains("5.0 (clang-500.2.79) (based on LLVM 3.3svn)")) return "Xcode 5.0.1, 5.0.2";
  if (version_string.contains("5.0 (clang-500.2.75) (based on LLVM 3.3svn)")) return "Xcode 5.0";
  if (version_string.contains("4.2 (clang-425.0.28) (based on LLVM 3.2svn)")) return "Xcode 4.6.2, 4.6.3";
  if (version_string.contains("4.2 (clang-425.0.27) (based on LLVM 3.2svn)")) return "Xcode 4.6.1";
  if (version_string.contains("4.2 (clang-425.0.24) (based on LLVM 3.2svn)")) return "Xcode 4.6";
  if (version_string.contains("4.1 (tags/Apple/clang-421.11.66) (based on LLVM 3.1svn)")) return "Xcode 4.5.1, 4.5.2";
  if (version_string.contains("4.1 (tags/Apple/clang-421.11.65) (based on LLVM 3.1svn)")) return "Xcode 4.5";
  if (version_string.contains("4.0 (tags/Apple/clang-421.0.60) (based on LLVM 3.1svn)")) return "Xcode 4.4.1";
  if (version_string.contains("4.0 (tags/Apple/clang-421.0.57) (based on LLVM 3.1svn)")) return "Xcode 4.4";
  if (version_string.contains("3.1 (tags/Apple/clang-318.0.61) (based on LLVM 3.1svn)")) return "Xcode 4.3.3";
  if (version_string.contains("3.1 (tags/Apple/clang-318.0.58) (based on LLVM 3.1svn)")) return "Xcode 4.3.2";
  if (version_string.contains("3.1 (tags/Apple/clang-318.0.54) (based on LLVM 3.1svn)")) return "Xcode 4.3.1";
  if (version_string.contains("3.1 (tags/Apple/clang-318.0.45) (based on LLVM 3.1svn)")) return "Xcode 4.3";
  if (version_string.contains("3.0 (211.10.1) (based on LLVM 3.0svn)")) return "Xcode 4.2";
  if (version_string.contains("2.1 (163.7.1) (based on LLVM 3.0svn)")) return "Xcode 4.1";
  if (version_string.contains("2.0 (137) (based on LLVM 2.9svn)")) return "Xcode 4.0, 4.0.2";
  if (version_string.contains("1.7 (77) (based on LLVM 2.9svn)")) return "Xcode 3.2.6";
  if (version_string.contains("1.6 (70)")) return "Xcode 3.2.5";
  if (version_string.contains("1.5 (60)")) return "Xcode 3.2.3, 3.2.4";
  if (version_string.contains("1.0.2")) return "Xcode 3.2";

  if (version().major() == 15) return "Xcode 15.0, 15.0.1, 15.1, 15.2, 15.3";
  if (version().major() == 14) return "Xcode 14.0, 14.0.1, 14.1, 14.2, 14.3, 14.3.1";
  if (version().major() == 13 && version().minor() == 1) return "Xcode 13.3, 13.3.1, 13.4, 13.4.1";
  if (version().major() == 13 && version().minor() == 0) return "Xcode 13.0, 13.0.1, 13.2, 13.2.1";
  if (version().major() == 12) return "Xcode 12.0, 12.0.1, 12.1, 12.1.1 RC, 12.2, 12.3, 12.4, 12.5, 12.5.1";
  if (version().major() == 11 && version().minor() == 3) return "Xcode 11.4, 11.4.1, 11.5, 11.6, 11.7";
  if (version().major() == 11 && version().minor() == 0) return "Xcode 11.0, 11.1, 11.2, 11.2.1, 11.3, 11.3.1";
  if (version().major() == 10 && version().minor() == 1) return "Xcode 10.2, 10.2.1, 10.3";
  if (version().major() == 10 && version().minor() == 0) return "Xcode 10.0, 10.1";
  if (version().major() == 9 && version().minor() == 1) return "Xcode 9.3, 9.3.1, 9.4, 9.4.1";
  if (version().major() == 9 && version().minor() == 0) return "Xcode 9.0, 9.1, 9.2";
  if (version().major() == 8 && version().minor() == 1) return "Xcode 8.3, 8.3.2, 8.3.2, 8.3.3";
  if (version().major() == 8 && version().minor() == 0) return "Xcode 8.0, 8.1, 8.2, 8.2.1";
  if (version().major() == 7 && version().minor() == 3) return "Xcode 7.3, 7.3.1";
  if (version().major() == 7 && version().minor() == 0) return "Xcode 7.0, 7.0.1, 7.1, 7.2, 7.2.1";
  if (version().major() == 6 && version().minor() == 1) return "Xcode 6.3, 6.3.1, 6.3.2, 6.4";
  if (version().major() == 6 && version().minor() == 0) return "Xcode 6.0.1, 6.1, 6.1.1, 6.2";
  if (version().major() == 5 && version().minor() == 1) return "Xcode 5.1, 5.1.1";
  if (version().major() == 5 && version().minor() == 0) return "Xcode 5.0, 5.0.1, 5.0.2";
  if (version().major() == 4 && version().minor() == 2) return "Xcode 4.6, 4.6.1, 4.6.2, 4.6.3";
  if (version().major() == 4 && version().minor() == 1) return "Xcode 5.1, 4.5, 4.5.1, 4.5.2";
  if (version().major() == 4 && version().minor() == 0) return "Xcode 4.4, 4.4.1";
  if (version().major() == 3 && version().minor() == 1) return "Xcode 4.3, 4.3.1, 4.3.2, 4.3.3";
  if (version().major() == 3 && version().minor() == 0) return "Xcode 4.2";
  if (version().major() == 2 && version().minor() == 1) return "Xcode 4.1";
  if (version().major() == 2 && version().minor() == 0) return "Xcode 4.0, 4.0.2";
  if (version().major() == 1 && version().minor() == 7) return "Xcode 3.2.6";
  if (version().major() == 1 && version().minor() == 6) return "Xcode 3.2.5";
  if (version().major() == 1 && version().minor() == 5) return "Xcode 3.2.3, 3.2.4";
  if (version().major() == 1 && version().minor() == 0 && version().build() == 2) return "Xcode 3.2";
  return "Xcode";
}

xtd::ustring compiler::get_compiler_version_string(const xtd::ustring& compiler_name) const noexcept {
  static auto version_string = ustring::empty_string;
  if (!ustring::is_empty(version_string)) return version_string;
  try {
    auto psi = process_start_info {compiler_name, "--version"};
    auto p = process::start(psi.use_shell_execute(false).redirect_standard_output(true)).wait_for_exit();
    version_string = stream_reader(p.standard_output()).read_line();
  } catch(...) {
    version_string = ustring::format("{} {}", name(), version());
  }
  return version_string;
}

xtd::ustring compiler::get_msvc_additional_information() const noexcept {
  // https://learn.microsoft.com/fr-fr/cpp/overview/compiler-versions?view=msvc-170
  if (version().major() == 19 && version().minor() == 40) return "Visual Studio 20222 version 17.10";
  if (version().major() == 19 && version().minor() == 39) return "Visual Studio 2022 version 17.9";
  if (version().major() == 19 && version().minor() == 38) return "Visual Studio 2022 version 17.8";
  if (version().major() == 19 && version().minor() == 37) return "Visual Studio 2022 version 17.7";
  if (version().major() == 19 && version().minor() == 36) return "Visual Studio 2022 version 17.6";
  if (version().major() == 19 && version().minor() == 35) return "Visual Studio 2022 version 17.5";
  if (version().major() == 19 && version().minor() == 34) return "Visual Studio 2022 version 17.4";
  if (version().major() == 19 && version().minor() == 33) return "Visual Studio 2022 version 17.3";
  if (version().major() == 19 && version().minor() == 32) return "Visual Studio 2022 version 17.2";
  if (version().major() == 19 && version().minor() == 31) return "Visual Studio 2022 version 17.1";
  if (version().major() == 19 && version().minor() == 30) return "Visual Studio 2022 RTW 17.0";
  if (version().major() == 19 && version().minor() == 29 && version().build() == 30129) return "Visual Studio 2019 version 16.11";
  if (version().major() == 19 && version().minor() == 29 && version().build() == 29917) return "Visual Studio 2019 version 16.10";
  if (version().major() == 19 && version().minor() == 28 && version().build() == 29910) return "Visual Studio 2019 version 16.9";
  if (version().major() == 19 && version().minor() == 28 && version().build() == 29333) return "Visual Studio 2019 version 16.8";
  if (version().major() == 19 && version().minor() == 27) return "Visual Studio 2019 version 16.7";
  if (version().major() == 19 && version().minor() == 26) return "Visual Studio 2019 version 16.6";
  if (version().major() == 19 && version().minor() == 25) return "Visual Studio 2019 version 16.5";
  if (version().major() == 19 && version().minor() == 24) return "Visual Studio 2019 version 16.4";
  if (version().major() == 19 && version().minor() == 23) return "Visual Studio 2019 version 16.3";
  if (version().major() == 19 && version().minor() == 22) return "Visual Studio 2019 version 16.2";
  if (version().major() == 19 && version().minor() == 21) return "Visual Studio 2019 version 16.1";
  if (version().major() == 19 && version().minor() == 20) return "Visual Studio 2019 RTW 16.0";
  if (version().major() == 19 && version().minor() == 16) return "Visual Studio 2017 version 15.9";
  if (version().major() == 19 && version().minor() == 15) return "Visual Studio 2017 version 15.8";
  if (version().major() == 19 && version().minor() == 14) return "Visual Studio 2017 version 15.7";
  if (version().major() == 19 && version().minor() == 13) return "Visual Studio 2017 version 15.6";
  if (version().major() == 19 && version().minor() == 12) return "Visual Studio 2017 version 15.5";
  if (version().major() == 19 && version().minor() == 11) return "Visual Studio 2017 version 15.3";
  if (version().major() == 19 && version().minor() == 10) return "Visual Studio 2017 RTW (15.0)";
  if (version().major() == 19 && version().minor() == 0) return "Visual Studio 2015 (14.0)";
  if (version().major() == 18 && version().minor() == 0) return "Visual Studio 2013 (12.0)";
  if (version().major() == 17 && version().minor() == 0) return "Visual Studio 2012 (11.0)";
  if (version().major() == 16 && version().minor() == 0) return "Visual Studio 2010 (10.0)";
  if (version().major() == 15 && version().minor() == 0) return "Visual Studio 2008 (9.0)";
  if (version().major() == 14 && version().minor() == 0) return "Visual Studio 2005 (8.0)";
  if (version().major() == 13 && version().minor() == 10) return "Visual Studio .NET 2003 (7.1)";
  if (version().major() == 13 && version().minor() == 0) return "Visual Studio .NET 2002 (7.0)";
  if (version().major() == 12 && version().minor() == 0) return "Visual Studio 6.0";
  return "Visual Studio";
}
