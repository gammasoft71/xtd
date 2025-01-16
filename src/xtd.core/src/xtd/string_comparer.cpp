#include "../../include/xtd/argument_exception.hpp"
#include "../../include/xtd/is.hpp"
#include "../../include/xtd/string_comparer.hpp"

using namespace xtd;

const string_comparer& string_comparer::ordinal() {
  static auto result = string_comparer(string_comparison::ordinal);
  return result;
}

const string_comparer& string_comparer::ordinal_ignore_case() {
  static auto result = string_comparer(string_comparison::ordinal_ignore_case);
  return result;
}

int32 string_comparer::compare(const xtd::string& x, const xtd::string& y) const noexcept {
  switch (comparison_) {
    case string_comparison::ordinal: return x.compare_to(y);
    case string_comparison::ordinal_ignore_case: return x.to_lower().compare_to(y.to_lower());
  }
}

bool string_comparer::equals(const string& x, const string& y) const noexcept {
  if (&x == &y) return true;
  switch (comparison_) {
    case string_comparison::ordinal: return x.equals(y);
    case string_comparison::ordinal_ignore_case: return x.to_lower().equals(y.to_lower());
  }
}

xtd::size string_comparer::get_hash_code(const string& obj) const noexcept {
  switch (comparison_) {
    case string_comparison::ordinal: return obj.get_hash_code();
    case string_comparison::ordinal_ignore_case: return obj.to_lower().get_hash_code();
  }
}
