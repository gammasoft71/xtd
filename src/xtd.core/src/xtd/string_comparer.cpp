#include "../../include/xtd/argument_exception.hpp"
#include "../../include/xtd/is.hpp"
#include "../../include/xtd/string_comparer.hpp"
#include "../../include/xtd/not_implemented_exception.hpp"

using namespace xtd;
/// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
//using namespace xtd::globalization;

string_comparer string_comparer::current_culture() {
  throw not_implemented_exception {};
  //return create(culture_info::current_culture);
}

string_comparer string_comparer::current_culture_ignore_case() {
  /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
  throw not_implemented_exception {};
  //return create(culture_info::current_culture, true);
}

string_comparer string_comparer::invariant_culture() {
  /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
  throw not_implemented_exception {};
  //return create(culture_info::invariant_culture);
}

string_comparer string_comparer::invariant_culture_ignore_case() {
  /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
  throw not_implemented_exception {};
  //return create(culture_info::invariant_culture, true);
}

const string_comparer& string_comparer::ordinal() {
  static auto result = from_comparison(string_comparison::ordinal);
  return result;
}

const string_comparer& string_comparer::ordinal_ignore_case() {
  static auto result =  from_comparison(string_comparison::ordinal_ignore_case);
  return result;
}

int32 string_comparer::compare(const xtd::string& x, const xtd::string& y) const noexcept {
  /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
  switch (comparison_) {
    case string_comparison::current_culture:
    case string_comparison::invariant_culture:
    case string_comparison::ordinal: return x.compare_to(y);
    case string_comparison::current_culture_ignore_case:
    case string_comparison::invariant_culture_ignore_case:
    case string_comparison::ordinal_ignore_case: return x.to_lower().compare_to(y.to_lower());
  }
}

bool string_comparer::equals(const string& x, const string& y) const noexcept {
  if (&x == &y) return true;
  /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
  switch (comparison_) {
    case string_comparison::current_culture:
    case string_comparison::invariant_culture:
    case string_comparison::ordinal: return x.equals(y);
    case string_comparison::current_culture_ignore_case:
    case string_comparison::invariant_culture_ignore_case:
    case string_comparison::ordinal_ignore_case: return x.to_lower().equals(y.to_lower());
  }
}

bool string_comparer::equals(const object& obj) const noexcept {
  return is<string_comparer>(obj) && reinterpret_cast<const string_comparer&>(obj).comparison_ == comparison_;
}

xtd::size string_comparer::get_hash_code(const string& obj) const noexcept {
  /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
  switch (comparison_) {
    case string_comparison::current_culture:
    case string_comparison::invariant_culture:
    case string_comparison::ordinal: return obj.get_hash_code();
    case string_comparison::current_culture_ignore_case:
    case string_comparison::invariant_culture_ignore_case:
    case string_comparison::ordinal_ignore_case: return obj.to_lower().get_hash_code();
  }
}

/// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
/*
string_comparer string_comparer::create(const culture_info& culture, bool ignore_case) {
  return create {culture, compare_options::ignore_case};
}

string_comparer string_comparer::create(const culture_info& culture, compare_options options) {
  return string_comparer {culture, options};
}*/

string_comparer string_comparer::from_comparison(xtd::string_comparison comparison) {
  return string_comparer {comparison};
}

string_comparer::string_comparer(string_comparison comparison) : comparison_ {comparison} {
  /// @todo Remove following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
  if (comparison == string_comparison::current_culture) throw not_implemented_exception {};
  if (comparison == string_comparison::current_culture_ignore_case) throw not_implemented_exception {};
  if (comparison == string_comparison::invariant_culture) throw not_implemented_exception {};
  if (comparison == string_comparison::invariant_culture_ignore_case) throw not_implemented_exception {};

  if (!enum_object<>::is_defined(comparison)) throw argument_exception {};
}

/// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
/*
string_comparer::string_comparer(const culture_info& culture, compare_options options) {
  culture_ = culture;
  options_ = options;
}
*/
