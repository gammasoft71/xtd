/// @file
/// @brief Contains xtd::basic_string_comparer class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "collections/generic/icomparer.hpp"
#include "collections/generic/iequality_comparer.hpp"
#include "argument_exception.hpp"
#include "as.hpp"
#include "is.hpp"
#include "not_implemented_exception.hpp"
#include "string_comparison.hpp"
#include "basic_string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a string comparison operation that uses specific case and culture-based or ordinal comparison rules.
  /// @par Definition
  /// ```cpp
  /// template<class char_t>
  /// class basic_string_comparer : public xtd::object, public xtd::collections::generic::icomparer<xtd::basic_string<char_t>>, public xtd::collections::generic::iequality_comparer<xtd::basic_string<char_t>>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/basic_string_comparer
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<class char_t>
  class basic_string_comparer : public xtd::object, public xtd::collections::generic::icomparer<xtd::basic_string<char_t>>, public xtd::collections::generic::iequality_comparer<xtd::basic_string<char_t>> {
  public:
    /// @name Public Static Properties
    
    /// @{
    /// @brief Gets a xtd::basic_string_comparer object that performs a case-sensitive string comparison using the word comparison rules of the current culture.
    /// @return A xtd::basic_string_comparer object.
    /// @remarks The xtd::basic_string_comparer returned by the xtd::basic_string_comparer::current_culture property can be used when strings are linguistically relevant. For example, if strings are displayed to the user, or if strings are the result of user interaction, culture-sensitive string comparison should be used to order the string data.
    /// @remarks The current culture is the xtd::globalization::culture_info object associated with the current thread.
    /// @remarks The xtd::basic_string_comparer::current_culture property actually returns an instance of an anonymous class derived from the ::basic_string_comparer class.
    /// @remarks Each call to the ::basic_string_comparer::current_culture property get accessor returns a new ::basic_string_comparer object, as the following code shows.
    /// ```
    /// void compare_current_culture_basic_string_comparer() {
    ///   basic_string_comparer basic_string_comparer1 = basic_string_comparer::current_culture;
    ///   basic_string_comparer basic_string_comparer2 = basic_string_comparer::current_culture;
    ///   // Displays false
    ///   console::write_line(basic_string_comparer::reference_equals(basic_string_comparer1, basic_string_comparer2));
    /// }
    /// ```
    /// @remarks To improve performance, you can store the xtd::basic_string_comparer object in a local variable rather than retrieve the value of the xtd::basic_string_comparer::current_culture property multiple times.
    static basic_string_comparer current_culture() {
      throw not_implemented_exception {};
      //return create(culture_info::current_culture);
    }

    /// @brief Gets a xtd::basic_string_comparer object that performs case-insensitive string comparisons using the word comparison rules of the current culture.
    /// @return A xtd::basic_string_comparer object.
    /// @remarks The current culture is the xtd::globalization::culture_info object associated with the current thread; it is returned by the xtd::globalization::culture_info::current_culture property.
    /// @remarks The xtd::basic_string_comparer returned by the xtd::basic_string_comparer::current_culture_ignore_case property can be used when strings are linguistically relevant but their case is not. For example, if strings are displayed to the user but case is unimportant, culture-sensitive, case-insensitive string comparison should be used to order the string data.
    /// @note xtd running on Linux and macOS systems only: The collation behavior for the C and Posix cultures is always case-sensitive because these cultures do not use the expected Unicode collation order. We recommend that you use a culture other than C or Posix for performing culture-sensitive, case-insensitive sorting operations.
    /// @remarks The xtd::basic_string_comparer::current_culture_ignore_case property actually returns an instance of an anonymous class derived from the xtd::basic_string_comparer class.
    /// @remarks Each call to the xtd::basic_string_comparer::current_culture_ignore_case property get accessor returns a new xtd::basic_string_comparer object, as the following code shows.
    /// ```
    /// void compare_current_culture_basic_string_comparer() {
    ///   basic_string_comparer basic_string_comparer1 = basic_string_comparer::current_culture_ignore_case;
    ///   basic_string_comparer basic_string_comparer2 = basic_string_comparer::current_culture_ignore_case;
    ///   // Displays false
    ///   console::write_line(basic_string_comparer::reference_equals(basic_string_comparer1, basic_string_comparer2));
    /// }
    /// ```
    /// @remarks To improve performance, you can store the xtd::basic_string_comparer object in a local variable rather than retrieve the value of the xtd::basic_string_comparer::current_culture_ignore_case property multiple times.
    static basic_string_comparer current_culture_ignore_case() {
      /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
      throw not_implemented_exception {};
      //return create(culture_info::current_culture, true);
    }

    static basic_string_comparer invariant_culture() {
      /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
      throw not_implemented_exception {};
      //return create(culture_info::invariant_culture);
    }
    
    static basic_string_comparer invariant_culture_ignore_case() {
      /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
      throw not_implemented_exception {};
      //return create(culture_info::invariant_culture, true);
    }
    
    /// @brief Gets a xtd::basic_string_comparer object that performs a case-sensitive ordinal string comparison.
    /// @return A xtd::basic_string_comparer object.
    /// @remarks The xtd::basic_string_comparer returned by the xtd::basic_string_comparer::ordinal property performs a simple byte comparison that is independent of language. This is most appropriate when comparing strings that are generated programmatically or when comparing case-sensitive resources such as passwords.
    /// @remarks The xtd::basic_string_comparer::ordinal property actually returns an instance of an anonymous class derived from the xtd::basic_string_comparer class.
    static const basic_string_comparer& ordinal() {
      static auto result = from_comparison(string_comparison::ordinal);
      return result;
    }

    /// @brief Gets a xtd::basic_string_comparer object that performs a case-insensitive ordinal string comparison.
    /// @return A xtd::basic_string_comparer object.
    /// @remarks The xtd::basic_string_comparer returned by the xtd::basic_string_comparer::ordinal_ignore_case property treats the characters in the strings to compare as if they were converted to uppercase using the conventions of the invariant culture, and then performs a simple byte comparison that is independent of language. This is most appropriate when comparing strings that are generated programmatically or when comparing case-insensitive resources such as paths and filenames.
    /// @remarks The xtd::basic_string_comparer::ordinal_ignore_case property actually returns an instance of an anonymous class derived from the xtd::basic_string_comparer class.
    static const basic_string_comparer& ordinal_ignore_case() {
      static auto result = from_comparison(string_comparison::ordinal_ignore_case);
      return result;
    }
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
    /// @remarks The xtd::basic_string_comparer::compare(const string&, const string&) method is slightly more efficient than the xtd::basic_string_comparer::compare(const object_t&, consy object_t&) method because no conversion of the `x` and `y` arguments is needed to perform the comparison.
    template <class object_t>
    int32 compare(const object_t& x, const object_t& y) const  {
      if (is<basic_string<char_t>>(x) && is<basic_string<char_t>>(y)) return compare(as<basic_string<char_t>>(x), as<basic_string<char_t>>(y));
      if (is<icomparable<object_t>>(x) && is<icomparable<object_t>>(y)) return as<icomparable<object_t>>(x).compare_to(y);
      if (is<object>(x) && is<object>(y) && as<object>(x) == as<object>(y)) return 0;
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);;
    }
    /// @cond
    int32 compare(const char_t* x, const char_t* y) const {
      if (x == y) return 0;
      return compare(basic_string<char_t> {x}, basic_string<char_t> {y});
    }
    int32 compare(const basic_string<char_t>& x, const char_t* y) const {return compare(x, basic_string<char_t> {y});}
    int32 compare(const char_t* x, const basic_string<char_t>& y) const {return compare(basic_string<char_t> {x}, y);}
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
    /// @remarks The xtd::basic_string_comparer::compare(const string&, const string&) method is slightly more efficient than the xtd::basic_string_comparer::compare(const object_t&, consy object_t&) method because no conversion of the `x` and `y` arguments is needed to perform the comparison.
    int32 compare(const xtd::basic_string<char_t>& x, const xtd::basic_string<char_t>& y) const noexcept override {
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

    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    /// @par Examples
    /// The following code example compares the current instance with another object.
    /// @include object_equals.cpp
    bool equals(const object& obj) const noexcept override {
      return is<basic_string_comparer>(obj) && reinterpret_cast<const basic_string_comparer&>(obj).comparison_ == comparison_;
    }

    /// @brief When overridden in a derived class, indicates whether two objects are equal.
    /// @param x An object to compare to `y`.
    /// @param y An object to compare to `x`.
    /// @return `true` if `x` and `y`  refer to the same object, or `x` and `y` are both the same type of object and those objects are equal; otherwise, `false`.
    /// @remarks The xtd::basic_string_comparer::equals(const string&, const string&) method is slightly more efficient than the xtd::basic_string_comparer::equals(const object_t&, consy object_t&) method because no conversion of the `x` and `y` arguments is needed to perform the comparison.
    template <class object_t>
    bool equals(const object_t& x, const object_t& y) const  {
      if (&x == &y) return true;
      if (is<basic_string<char_t>>(x) && is<basic_string<char_t>>(y)) return equals(as<basic_string<char_t>>(x), as<basic_string<char_t>>(y));
      if (is<iequatable<object_t>>(x) && is<iequatable<object_t>>(y)) return as<iequatable<object_t>>(x).equals(y);
      if (is<object>(x) && is<object>(y) && as<object>(x) == as<object>(y)) return 0;
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);;
    }
    /// @cond
    bool equals(const char_t* x, const char_t* y) const {
      if (x == y) return true;
      return equals(basic_string<char_t> {x}, basic_string<char_t> {y});}
    bool equals(const basic_string<char_t>& x, const char_t* y) const {return equals(x, basic_string<char_t> {y});}
    bool equals(const char_t* x, const basic_string<char_t>& y) const {return equals(basic_string<char_t> {x}, y);}
    /// @endcond
    /// @brief When overridden in a derived class, indicates whether two strings are equal.
    /// @param x An object to compare to `y`.
    /// @param y An object to compare to `x`.
    /// @return `true` if `x` and `y`  refer to the same object, or `x` and `y` are both the same type of object and those objects are equal; otherwise, `false`.
    /// @remarks The xtd::basic_string_comparer::equals(const string&, const string&) method is slightly more efficient than the xtd::basic_string_comparer::equals(const object_t&, consy object_t&) method because no conversion of the `x` and `y` arguments is needed to perform the comparison.
    bool equals(const xtd::basic_string<char_t>& x, const xtd::basic_string<char_t>& y) const noexcept override {
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
        
    using xtd::object::get_hash_code;
    /// @brief When overridden in a derived class, gets the hash code for the specified object.
    /// @param obj An object.
    /// @return A xtd::size hash code calculated from the value of the obj parameter.
    /// @remarks The xtd::basic_string_comparer::get_hash_code(const string&) method is more efficient than the xtd::basic_string_comparer::get_hash_code(const object&) method because the obj parameter does not have to be converted to perform the operation.
    template <class object_t>
    xtd::size get_hash_code(const object_t& obj) const  {
      if (is<basic_string<char_t>>(obj)) return get_hash_code(as<basic_string<char_t>>(obj));
      if (is<object>(obj)) return as<object>(obj).get_hash_code();
      throw xtd::hash_code::combine(obj);
    }
    /// @cond
    xtd::size get_hash_code(const char_t* obj) const {return get_hash_code(basic_string<char_t> {obj});}
    /// @endcond
    /// @brief When overridden in a derived class, gets the hash code for the specified string.
    /// @param obj A string.
    /// @return A xtd::size hash code calculated from the value of the obj parameter.
    /// @remarks The xtd::basic_string_comparer::get_hash_code(const string&) method is more efficient than the xtd::basic_string_comparer::get_hash_code(const object&) method because the obj parameter does not have to be converted to perform the operation.
    xtd::size get_hash_code(const xtd::basic_string<char_t>& obj) const noexcept override {
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
    /// @}

    /// @name Public Static Methods
    
    /// @{
    /// @brief Converts the specified xtd::string_comparison instance to a StringComparer instance.
    /// @param comparison A string comparer instance to convert.
    /// @return A xtd::basic_string_comparer instance representing the equivalent value of the specified xtd::string_comparison instance.
    /// @exception xtd::argument_exception The specified string comparison is not supported.
    static basic_string_comparer from_comparison(xtd::string_comparison comparison) {
      return basic_string_comparer {comparison};
    }
    
    /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
    /*
    /// @brief Determines whether the specified xtd::collections::generic::iequality_comparer <type_t> is a well-known culture-aware string comparer.
    /// @param comparer The comparer to query.
    /// @param comapre_info When this method returns, contains a value indicating which xtd::globalization::compare_info was used to create `comparer`. Set to default value if this method returns `false`.
    /// @param compare_options When this method returns, contains a value indicating which xtd::globalization::compare_options was used to create `comparer`. Set to td::globalization::compare_options::none if this method returns `false`.
    /// @return `true` if comparer is a well-known culture-aware string comparer; otherwise, `false`.
    /// @remarks A "well-known culture-aware comparer" describes a comparer that's tied to a specific xtd::globalization::compare_info using some defined xtd::globalization::compare_options. To create a xtd::basic_string_comparer instance wrapped around a xtd::globalization::compare_info and xtd::globalization::compare_options, use xtd::globalization::globalization_extensions::get_string_comparer. This method returns `false` when given xtd::basic_string_comparer::ordinal and other non-linguistic comparers as input.
    bool is_well_known_culture_aware_comparer(const xtd::collections::generic::iequality_comparer<xtd::basic_string<char_t>>& comparer, xtd::globalization::compare_info& compare_info, xtd::globalization::compare_options& compare_options) {
      if (xtd::is<>(comparer)) {
        compare_info = get_compare_info();
        compare_options = get_compare_options();
        return true;
      }
      
      compare_info = xtd::globalization::compare_info {};
      compare_options = xtd::globalization::compare_options::none;
      return false;
    } */
    
    /// @brief Determines whether the specified xtd::collections::generic::iequality_comparer <type_t> is a well-known ordinal string comparer.
    /// @param comparer The comparer to query.
    /// @param ignore_case When this method returns, contains a value stating whether `comparer` is case-insensitive. Set to `false` if this method returns `false`.
    /// @return `true` if comparer is a well-known ordinal string comparer; otherwise, `false`.
    /// @remarks A "well-known ordinal comparer" describes a comparer that behaves identically to xtd::basic_string_comparer::ordinal when passed to xtd::collections::generic::dictionary <key_t, value_t> or xtd::collections::generic::hash_set <type_t>. For example, xtd::collections::generic::equality_comparer::default_equality_comparer is a well-known ordinal comparer because a xtd::collections::generic::dictionary <key_t, value_t> given xtd::collections::generic::equality_comparer::default_equality_comparer as a constructor argument will behave identically to a xtd::collections::generic::dictionary <key_t, value_t> given xtd::string_comparer::ordinal as a constructor argument. If `ignore_case` is `true` on method exit, then `comparer` behaves identically to xtd::basic_string_comparer::ordinal_ignore_case when passed to the constructor of such a collection.
    static bool is_well_known_ordinal_comparer(const xtd::collections::generic::iequality_comparer<xtd::basic_string<char_t>>& comparer, bool& ignore_case) {
      if (xtd::is<xtd::basic_string_comparer<char_t>>(comparer) && (xtd::as<xtd::basic_string_comparer<char_t>>(comparer).comparison_ == xtd::string_comparison::ordinal || xtd::as<xtd::basic_string_comparer<char_t>>(comparer).comparison_ == xtd::string_comparison::ordinal_ignore_case)) {
        ignore_case = xtd::is<xtd::basic_string_comparer<char_t>>(comparer) && xtd::as<xtd::basic_string_comparer<char_t>>(comparer).comparison_ == xtd::string_comparison::ordinal_ignore_case;
        return true;
      }
      
      ignore_case = false;
      return false;
    }
    /// @}

  protected:
    /// @name Protected Constructors
    
    /// @{
    /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
    /*
    /// @brief Creates a xtd::basic_string_comparer object that compares strings according to the rules of a specified culture.
    /// @param culture A culture whose linguistic rules are used to perform a string comparison.
    /// @param ignore_case `true` to specify that comparison operations be case-insensitive; `false` to specify that comparison operations be case-sensitive.
    /// @return A new xtd::basic_string_comparer object that performs string comparisons according to the comparison rules used by the `culture` parameter and the case rule specified by the `ignore_case` parameter.
    basic_string_comparer create(const xtd::globalization::culture_info& culture, bool ignore_case)  {
      return create {culture, ignore_case ? compare_options::ignore_case : compare_options::none};
    } */
    
    /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
    /*
    /// @brief Creates a xtd::basic_string_comparer object that compares strings according to the rules of a specified culture and string options.
    /// @param culture A culture whose linguistic rules are used to perform a string comparison.
    /// @param options A bitwise combination of the xtd::globalization::compare_options values.
    /// @exception xtd::argument_exception `options` has invalid flags.
    basic_string_comparer create(const xtd::globalization::culture_info& culture, xtd::globalization::compare_options options) {
      return basic_string_comparer {culture, options};
    } */

    /// @brief Initializes a new instance of the xtd::basic_string_comparer class.
    basic_string_comparer() = default;
    /// @}
    

  private:
    explicit basic_string_comparer(xtd::string_comparison comparison) : comparison_ {comparison} {
      /// @todo Remove following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
      if (comparison == string_comparison::current_culture) throw not_implemented_exception {};
      if (comparison == string_comparison::current_culture_ignore_case) throw not_implemented_exception {};
      if (comparison == string_comparison::invariant_culture) throw not_implemented_exception {};
      if (comparison == string_comparison::invariant_culture_ignore_case) throw not_implemented_exception {};
      
      if (!enum_object<>::is_defined(comparison)) throw argument_exception {};
    }
    /// @todo Uncomment following lines when xtd::globalization::culture_info and xtd::globalization::compare_options are developped.
    /*
    basic_string_comparer(const xtd::globalization::culture_info& culture, xtd::globalization::compare_options options) : culture_ {culture}, options_ {options} {
    }
    xtd::globalization::culture_info culture_ = xtd::globalization::culture_info::empty;
    xtd::globalization::compare_options options_ = xtd::globalization::compare_options::none;
     */
    xtd::string_comparison comparison_ = xtd::string_comparison::ordinal;
  };
}
