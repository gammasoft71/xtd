#include "../../include/xtd/cpp_language"

using namespace xtd;

cpp_language::cpp_language(uint32 cpp) noexcept : cpp_(cpp) {
}

bool cpp_language::is_experimental_language() const noexcept {
  return language() != experimental_language();
}

bool cpp_language::is_supported() const noexcept {
  return cpp_ >= 201703L;
}

language_id cpp_language::language() const noexcept {
  /// @todo Remove comment when c++23 is defined...
  //if (cpp_ >= ??????L) return language_id::cpp23; //TBD
  if (cpp_ >= 202002L) return language_id::cpp20;
  if (cpp_ >= 201703L) return language_id::cpp17;
  if (cpp_ >= 201402L) return language_id::cpp14;
  if (cpp_ >= 201103L) return language_id::cpp11;
  if (cpp_ >= 199711L) return language_id::cpp98;
  if (cpp_ >= 1L) return language_id::cpp_pre98;
  return language_id::unknown;
}

language_id cpp_language::experimental_language() const noexcept {
  /// @todo Remove comment when c++23 is defined...
  //if (cpp_ >= ??????L) return language_id::cpp23;
  if (cpp_ >= 201707L) return language_id::cpp20;
  if (cpp_ >= 201411L) return language_id::cpp17;
  if (cpp_ >= 201210L) return language_id::cpp14;
  if (cpp_ >= 200410L) return language_id::cpp11;
  if (cpp_ >= 199711L) return language_id::cpp98;
  if (cpp_ >= 1L) return language_id::cpp_pre98;
  return language_id::unknown;
}

int32 cpp_language::month() const noexcept {
  return cpp_ % 100;
}

xtd::ustring cpp_language::name() const noexcept {
  static auto names = std::map<language_id, xtd::ustring> {{language_id::cpp_pre98, "C++ Pre 98"}, {language_id::cpp98, "C++ 98"}, {language_id::cpp11, "C++ 11"}, {language_id::cpp14, "C++ 14"}, {language_id::cpp17, "C++ 17"}, {language_id::cpp20, "C++ 20"}, {language_id::cpp23, "C++ 23"}, {language_id::unknown, "<unknown>"}};
  if (is_experimental_language()) return ustring::format("Experimental {}", names[experimental_language()]);
  return names[language()];
}

uint32 cpp_language::value() const noexcept {
  return cpp_;
}

xtd::ustring cpp_language::version_string() const noexcept {
  return ustring::format("{} {}", name(), version());
}

xtd::version cpp_language::version() const noexcept {
  return xtd::version(cpp_ / 100, cpp_ % 100);
}

int32 cpp_language::year() const noexcept {return cpp_ / 100;}

xtd::ustring cpp_language::to_string() const noexcept {
  return version_string();
}
