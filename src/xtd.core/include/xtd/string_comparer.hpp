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
  /// @ingroup xtd_core system
  class string_comparer : public xtd::object, public xtd::collections::generic::icomparer<xtd::string>, public xtd::collections::generic::iequality_comparer<xtd::string> {
  public:
    /// @name Public Static Properties
    
    /// @{
    /// @brief Gets a xtd::string_comparer object that performs a case-sensitive string comparison using the word comparison rules of the current culture.
    /// @return A xtd::string_comparer object.
    /// @remarks The xtd::string_comparer returned by the xtd::string_comparer::current_culture property can be used when strings are linguistically relevant. For example, if strings are displayed to the user, or if strings are the result of user interaction, culture-sensitive string comparison should be used to order the string data.
    /// @remarks The current culture is the xtd::globalization::culture_info object associated with the current thread.
    /// @remarks The xtd::::string_comparer::current_culture property actually returns an instance of an anonymous class derived from the ::string_comparer class.
    /// @remarks Each call to the ::string_comparer::current_culture property get accessor returns a new ::string_comparer object, as the following code shows.
    /// ```
    /// void compare_current_culture_string_comparer() {
    ///   string_comparer string_comparer1 = string_comparer::current_culture;
    ///   string_comparer string_comparer2 = string_comparer::current_culture;
    ///   // Displays false
    ///   console::write_line(string_comparer::reference_equals(string_comparer1, string_comparer2));
    /// }
    /// ```
    /// @remarks To improve performance, you can store the xtd::string_comparer object in a local variable rather than retrieve the value of the xtd::string_comparer::current_culture property multiple times.
    static string_comparer current_culture();

    /// @brief Gets a xtd::string_comparer object that performs case-insensitive string comparisons using the word comparison rules of the current culture.
    /// @return A xtd::string_comparer object.
    /// @remarks The current culture is the xtd::globalization::culture_info object associated with the current thread; it is returned by the xtd::globalization::culture_info::current_culture property.
    /// @remarks The xtd::string_comparer returned by the xtd::string_comparer::current_culture_ignore_case property can be used when strings are linguistically relevant but their case is not. For example, if strings are displayed to the user but case is unimportant, culture-sensitive, case-insensitive string comparison should be used to order the string data.
    /// @note xtd running on Linux and macOS systems only: The collation behavior for the C and Posix cultures is always case-sensitive because these cultures do not use the expected Unicode collation order. We recommend that you use a culture other than C or Posix for performing culture-sensitive, case-insensitive sorting operations.
    /// @remarks The xtd::string_comparer::current_culture_ignore_case property actually returns an instance of an anonymous class derived from the xtd::string_comparer class.
    /// @remarks Each call to the xtd::string_comparer::current_culture_ignore_case property get accessor returns a new xtd::string_comparer object, as the following code shows.
    /// ```
    /// void compare_current_culture_string_comparer() {
    ///   string_comparer string_comparer1 = string_comparer::current_culture_ignore_case;
    ///   string_comparer string_comparer2 = string_comparer::current_culture_ignore_case;
    ///   // Displays false
    ///   console::write_line(string_comparer::reference_equals(string_comparer1, string_comparer2));
    /// }
    /// ```
    /// @remarks To improve performance, you can store the xtd::string_comparer object in a local variable rather than retrieve the value of the xtd::string_comparer::current_culture_ignore_case property multiple times.
    static string_comparer current_culture_ignore_case();

    static string_comparer invariant_culture();
    
    static string_comparer invariant_culture_ignore_case();
    
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

    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return true if the specified object is equal to the current object. otherwise, false.
    /// @par Examples
    /// The following code example compares the current instance with another object.
    /// @include object_equals.cpp
    bool equals(const object& obj) const noexcept override;

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

    /// @name Public Static Methods
    
    /// @{
    /// @brief Converts the specified xtd::string_comparison instance to a StringComparer instance.
    /// @param comparison A string comparer instance to convert.
    /// @return A xtd::string_comparer instance representing the equivalent value of the specified xtd::string_comparison instance.
    /// @exception xtd::argument_exception The specified string comparison is not supported.
    static string_comparer from_comparison(xtd::string_comparison comparison);
    /// @}

  protected:
    /// @name Protected Constructors
    
    /// @{
    /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
    /*
    /// @brief Creates a xtd::string_comparer object that compares strings according to the rules of a specified culture.
    /// @param culture A culture whose linguistic rules are used to perform a string comparison.
    /// @param ignore_case `true` to specify that comparison operations be case-insensitive; `false` to specify that comparison operations be case-sensitive.
    /// @return A new xtd::string_comparer object that performs string comparisons according to the comparison rules used by the `culture` parameter and the case rule specified by the `ignore_case` parameter.
    string_comparer create(const xtd::globalization::culture_info& culture, bool ignore_case);
    
    /// @brief Creates a xtd::string_comparer object that compares strings according to the rules of a specified culture and string options.
    /// @param culture A culture whose linguistic rules are used to perform a string comparison.
    /// @param options A bitwise combination of the xtd::globalization::compare_options values.
    /// @exception xtd::argument_exception `options` has invalid flags.
    string_comparer create(const xtd::globalization::culture_info& culture, xtd::globalization::compare_options options);
     */

    /// @brief Initializes a new instance of the xtd::string_comparer class.
    string_comparer() = default;
    /// @}
    

  private:
    explicit string_comparer(xtd::string_comparison comparison);
    /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
    /*
    string_comparer(const xtd::globalization::culture_info& culture, xtd::globalization::compare_options options);
    xtd::globalization::culture_info culture_ = xtd::globalization::culture_info::empty;
    xtd::globalization::compare_options options_ = xtd::globalization::compare_options::none;
     */
    xtd::string_comparison comparison_ = xtd::string_comparison::ordinal;
  };
}
