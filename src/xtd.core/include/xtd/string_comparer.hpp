/// @file
/// @brief Contains xtd::string_comparer class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "collections/generic/icomparer.hpp"
#include "collections/generic/iequality_comparer.hpp"
#include "argument_exception.hpp"
#include "as.hpp"
#include "string_comparison.hpp"
#include "string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a string comparison operation that uses specific case and culture-based or ordinal comparison rules.
  /// @par Definition
  /// ```cpp
  /// class string_comparer : public xtd::object, public xtd::collections::generic::icomparer<xtd::string>, public xtd::collections::generic::iequality_comparer<xtd::string>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/string_comparer
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  class string_comparer : public xtd::object, public xtd::collections::generic::icomparer<xtd::string>, public xtd::collections::generic::iequality_comparer<xtd::string> {
  public:
    /// @name Public Static Properties
    
    /// @{
    /// @brief Gets a xtd::string_comparer object that performs a case-sensitive ordinal string comparison.
    /// @return A xtd::string_comparer object.
    /// @remarks The xtd::string_comparer returned by the xtd::string_comparer::ordinal property performs a simple byte comparison that is independent of language. This is most appropriate when comparing strings that are generated programmatically or when comparing case-sensitive resources such as passwords.
    /// @remarks The xtd::string_comparer::ordinal property actually returns an instance of an anonymous class derived from the xtd::string_comparer class.
    static const string_comparer& ordinal();

    /// @brief Gets a xtd::string_comparer object that performs a case-insensitive ordinal string comparison.
    /// @return A xtd::string_comparer object.
    /// @remarks The xtd::string_comparer returned by the xtd::string_comparer::ordinal_ignore_case property treats the characters in the strings to compare as if they were converted to uppercase using the conventions of the invariant culture, and then performs a simple byte comparison that is independent of language. This is most appropriate when comparing strings that are generated programmatically or when comparing case-insensitive resources such as paths and filenames.
    /// @remarks The xtd::string_comparer::ordinal_ignore_case property actually returns an instance of an anonymous class derived from the xtd::string_comparer class.
    static const string_comparer& ordinal_ignore_case();
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief When overridden in a derived class, compares two objects and returns an indication of their relative sort order.
    /// @param x An object to compare to `y`.
    /// @param y An object to compare to `x`.
    /// @return A signed integer that indicates the relative values of `x` and `y`, as shown in the following table.
    /// | Value             | Meaning                             |
    /// | ----------------- | ----------------------------------- |
    /// | Less than zero    | `x` precedes `y` in the sort order. |
    /// | Zero              | `x` is equal to `y`.                |
    /// | Greater than zero | `x` follows `y` in the sort order.  |
    /// @exception xtd::argument_exception Neither `x` nor `y` is a xtd::string object, and neither `x` nor `y` implements the `xtd::icomparable` interface.
    /// @remarks The xtd::string_comparer::compare(const string&, const string&) method is slightly more efficient than the xtd::string_comparer::compare(const object_t&, consy object_t&) method because no conversion of the `x` and `y` arguments is needed to perform the comparison.
    template <class object_t>
    int32 compare(const object_t& x, const object_t& y) const  {
      if (is<string>(x) && is<string>(y)) return compare(as<string>(x), as<string>(y));
      if (is<icomparable<object_t>>(x) && is<icomparable<object_t>>(y)) return as<icomparable<object_t>>(x).compare_to(y);
      if (is<object>(x) && is<object>(y) && as<object>(x) == as<object>(y)) return 0;
      throw xtd::argument_exception {};
    }
    /// @cond
    int32 compare(const char* x, const char* y) const {
      if (x == y) return 0;
      return compare(string {x}, string {y});
    }
    int32 compare(const string& x, const char* y) const {return compare(x, string {y});}
    int32 compare(const char* x, const string& y) const {return compare(string {x}, y);}
    /// @endcond
    /// @brief When overridden in a derived class, compares two strings and returns an indication of their relative sort order.
    /// @param x An object to compare to `y`.
    /// @param y An object to compare to `x`.
    /// @return A signed integer that indicates the relative values of `x` and `y`, as shown in the following table.
    /// | Value             | Meaning                             |
    /// | ----------------- | ----------------------------------- |
    /// | Less than zero    | `x` precedes `y` in the sort order. |
    /// | Zero              | `x` is equal to `y`.                |
    /// | Greater than zero | `x` follows `y` in the sort order.  |
    /// @remarks The xtd::string_comparer::compare(const string&, const string&) method is slightly more efficient than the xtd::string_comparer::compare(const object_t&, consy object_t&) method because no conversion of the `x` and `y` arguments is needed to perform the comparison.
    int32 compare(const xtd::string& x, const xtd::string& y) const noexcept override;

    using xtd::object::equals;
    /// @brief When overridden in a derived class, indicates whether two objects are equal.
    /// @param x An object to compare to `y`.
    /// @param y An object to compare to `x`.
    /// @return `true` if `x` and `y`  refer to the same object, or `x` and `y` are both the same type of object and those objects are equal; otherwise, `false`.
    /// @remarks The xtd::string_comparer::equals(const string&, const string&) method is slightly more efficient than the xtd::string_comparer::equals(const object_t&, consy object_t&) method because no conversion of the `x` and `y` arguments is needed to perform the comparison.
    template <class object_t>
    bool equals(const object_t& x, const object_t& y) const  {
      if (&x == &y) return true;
      if (is<string>(x) && is<string>(y)) return equals(as<string>(x), as<string>(y));
      if (is<iequatable<object_t>>(x) && is<iequatable<object_t>>(y)) return as<iequatable<object_t>>(x).equals(y);
      if (is<object>(x) && is<object>(y) && as<object>(x) == as<object>(y)) return 0;
      throw xtd::argument_exception {};
    }
    /// @cond
    bool equals(const char* x, const char* y) const {
      if (x == y) return true;
      return equals(string {x}, string {y});}
    bool equals(const string& x, const char* y) const {return equals(x, string {y});}
    bool equals(const char* x, const string& y) const {return equals(string {x}, y);}
    /// @endcond
    /// @brief When overridden in a derived class, indicates whether two strings are equal.
    /// @param x An object to compare to `y`.
    /// @param y An object to compare to `x`.
    /// @return `true` if `x` and `y`  refer to the same object, or `x` and `y` are both the same type of object and those objects are equal; otherwise, `false`.
    /// @remarks The xtd::string_comparer::equals(const string&, const string&) method is slightly more efficient than the xtd::string_comparer::equals(const object_t&, consy object_t&) method because no conversion of the `x` and `y` arguments is needed to perform the comparison.
    bool equals(const xtd::string& x, const xtd::string& y) const noexcept override;
    
    using xtd::object::get_hash_code;
    /// @brief When overridden in a derived class, gets the hash code for the specified object.
    /// @param obj An object.
    /// @return A xtd::size hash code calculated from the value of the obj parameter.
    /// @remarks The xtd::string_comparer::get_hash_code(const string&) method is more efficient than the xtd::string_comparer::get_hash_code(const object&) method because the obj parameter does not have to be converted to perform the operation.
    template <class object_t>
    xtd::size get_hash_code(const object_t& obj) const  {
      if (is<string>(obj)) return get_hash_code(as<string>(obj));
      if (is<object>(obj)) return as<object>(obj).get_hash_code();
      throw xtd::hash_code::combine(obj);
    }
    /// @cond
    xtd::size get_hash_code(const char* obj) const {return get_hash_code(string {obj});}
    /// @endcond
    /// @brief When overridden in a derived class, gets the hash code for the specified string.
    /// @param obj A string.
    /// @return A xtd::size hash code calculated from the value of the obj parameter.
    /// @remarks The xtd::string_comparer::get_hash_code(const string&) method is more efficient than the xtd::string_comparer::get_hash_code(const object&) method because the obj parameter does not have to be converted to perform the operation.
    xtd::size get_hash_code(const xtd::string& obj) const noexcept override;
    /// @}

  protected:
    /// @name Protected Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::string_comparer class.
    string_comparer() = default;
    /// @}
    

  private:
    explicit string_comparer(xtd::string_comparison comparison) : comparison_ {comparison} {}
    xtd::string_comparison comparison_ = xtd::string_comparison::ordinal;
  };
}
