/// @file
/// @brief Contains xtd::box class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "icomparable.h"
#include "iequatable.h"
#include "object.h"
#include "ustring.h"
#include "types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a boxed object.
  /// @code
  /// class box : public xtd::icomparable<box<type_t>>, public xtd::iequatable<box<type_t>>, public xtd::object
  /// @endcode
  /// @par Inheritance
  /// xtd::object → xtd::box <type_t>
  /// @par Implements
  /// xtd::icomparable <>, xtd::iequatable <>
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks You can use xtd::box to represent a class or structure that does not inherit from xtd::object. Typically used for integral types.
  /// @remarks Use xtd::boxing to box an object.
  /// @remarks Use xtd::unboxing to unbox an object.
  template<typename type_t>
  class box : public xtd::icomparable<box<type_t>>, public xtd::iequatable<box<type_t>>, public xtd::object {
  public:
    /// @name Constructors
    
    /// @{
    /// @brief Initialize a new xtd::box object.
    box() = default;
    /// @brief Initialize a new xtd::box object with specified value.
    /// @param value Volue used to initialize object.
    box(const type_t& value) : value_(value) {}
    /// @}

    /// @cond
    box(const box&) = default;
    box(box&&) = default;
    box& operator=(const box&) = default;
    box& operator=(const type_t& value) {
      value_ = value;
      return *this;
    };
    /// @endcond

    /// @name Properties

    /// @{
    /// @brief Gets the underlying value.
    /// @return Return the underlying value.
    const type_t& value() const {return value_;}
    /// @brief Gets the underlying value.
    /// @return Return the underlying value.
    type_t& value() {return value_;}
    /// @brief Sets de underlying value.
    /// @param value The value to set to the underlying value.
    box& value(const type_t& value) {
      value_ = value;
      return *this;
    }
    /// @}

    /// @name Opertors
    
    /// @{
    operator type_t() const {return value_;}
    /// @}

    /// @name Methods
    
    /// @{
    bool equals(const object& value) const noexcept override {return dynamic_cast<const box<type_t>*>(&value) ? equals(static_cast<const box<type_t>&>(value)) : false;}
    bool equals(const box& value) const noexcept override {return value_ == value.value_;}
      
    int32_t compare_to(const object& value) const noexcept override {return dynamic_cast<const box<type_t>*>(&value) ? compare_to(static_cast<const box<type_t>&>(value)) : -1;}
    int32_t compare_to(const box& value) const noexcept override {
      if (value_ < value.value_) return -1;
      if (value_ > value.value_) return 1;
      return 0;
    }

    /// @brief Converts the string to its type_t equivalent.
    /// @param value A string containing a type_t to convert.
    /// @return A type_t equivalent to the number contained in value.
    static type_t parse(const xtd::ustring& value) {return xtd::parse<type_t>(value);}

    xtd::ustring to_string() const noexcept override {return xtd::ustring::format("{}", value_);}
    /// @brief Converts the value of this instance to its equivalent string representation, using the specified format.
    /// @param format A value type format string.
    /// @return The string representation of the value of this instance as specified by format.
    xtd::ustring to_string(const xtd::ustring& format) const noexcept {return xtd::ustring::format(xtd::ustring::format("{{:{}}}", format), value_);}

    /// @brief Converts the string to its type_t equivalent. A return value indicates whether the conversion succeeded or failed.
    /// @param value A string containing a type_t to convert.
    /// @param result A type_t equivalent to the number contained in value.
    /// @return true if s was converted successfully; otherwise, false.
    static bool try_parse(const xtd::ustring& value, type_t& result) {return xtd::try_parse<type_t>(value, result);}
    /// @}

  private:
      type_t value_ {};
  };
  
  /// @brief Represents a boxed integer object.
  /// @code
  /// class box_integer : public xtd::box<type_t>
  /// @endcode
  /// @par Inheritance
  /// xtd::object → xtd::box <type_t> → xtd::box_integer <type_t>  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks You can use xtd::box to represent a class or structure that does not inherit from xtd::object. Typically used for integral types.
  /// @remarks Use xtd::boxing to box an object.
  /// @remarks Use xtd::unboxing to unbox an object.
  template<typename type_t>
  class box_integer : public xtd::box<type_t> {
  public:
    /// @cond
    box_integer() = default;
    box_integer(const type_t& value) : box<type_t>(value) {}
    box_integer(const box_integer&) = default;
    box_integer(box_integer&&) = default;
    box_integer& operator=(const box_integer&) = default;
    /// @endcond

    /// @brief Represents the largest possible value of type_t. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::max().
    static constexpr type_t max_value = std::numeric_limits<type_t>::max();
    /// @brief Represents the smallest possible value of type_t. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::lowest().
    static constexpr type_t min_value = std::numeric_limits<type_t>::lowest();
  };
      
  /// @brief Represents a boxed floating point object.
  /// @code
  /// class box_floating_point : public xtd::box<type_t>
  /// @endcode
  /// @par Inheritance
  /// xtd::object → xtd::box <type_t> → xtd::box_integer <type_t> → box_floating_point <type_t>
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks You can use xtd::box to represent a class or structure that does not inherit from xtd::object. Typically used for integral types.
  /// @remarks Use xtd::boxing to box an object.
  /// @remarks Use xtd::unboxing to unbox an object.
  template<typename type_t>
  class box_floating_point : public box_integer<type_t> {
  public:
    /// @cond
    box_floating_point() = default;
    box_floating_point(const type_t& value) : box_integer<type_t>(value) {}
    box_floating_point(const box_floating_point&) = default;
    box_floating_point(box_floating_point&&) = default;
     box_floating_point& operator=(const box_floating_point&) = default;
    /// @endcond
    
    /// @brief Represents the smallest positive type_t value greater than zero. This field is constant.
    /// @remarks The value of this field is 4.94066e-324.
    static constexpr type_t epsilon = box_floating_point<type_t>::__get_epsilon(type_t{});
    /// @brief Represents infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::infinity().
    static constexpr type_t infinity = std::numeric_limits<type_t>::infinity();
    /// @brief Represents not a number (NaN). This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::quiet_NaN().
    static constexpr type_t NaN = std::numeric_limits<type_t>::quiet_NaN();
    /// @brief Represents negative infinity. This field is constant.
    /// @remarks The value of this field is -std::numeric_limits<type_t>::infinity().
    static constexpr type_t negative_infinity = -infinity;
    /// @brief Represents positive infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::infinity().
    static constexpr double positive_infinity = +infinity;
    
    
  private:
    static constexpr decimal_t __get_epsilon(decimal_t) noexcept {return 0;}
    static constexpr double __get_epsilon(double) noexcept {return 4.94066e-324;}
    static constexpr float __get_epsilon(float) noexcept {return 1.401298E-45f;}
  };
   
  /// @brief Represent a boxed bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::boolean_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// bool unboxed_object = true;
  /// boolean_object boxed_object = unboxed_bool;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = true;
  /// @endcode
  using boolean_object = box<bool>;
      
  /// @brief Represent a boxed single.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::single_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// float unboxed_object = 3.14f;
  /// single_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 3.14;
  /// @endcode
  using single_object = box_floating_point<float>;
  /// @brief Represent a boxed double.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::double_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// double unboxed_object = 3.14;
  /// double_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 3.14;
  /// @endcode
  using double_object = box_floating_point<double>;
  /// @brief Represent a boxed decimal.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::double_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// decimal unboxed_object = 3.14;
  /// decimal_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 3.14;
  /// @endcode
  using decimal_object = box_floating_point<decimal_t>;

  /// @brief Represent a boxed sbyte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::sbyte_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// sbyte_t unboxed_object = 42;
  /// sbyte_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using sbyte_object = box_integer<sbyte_t>;
  /// @brief Represent a boxed int16.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::int16_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// int16_t unboxed_object = 42;
  /// int16_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using int16_object = box_integer<int16_t>;
  /// @brief Represent a boxed int32.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::int32_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// int32_t unboxed_object = 42;
  /// int32_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using int32_object = box_integer<int32_t>;
  /// @brief Represent a boxed int64.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::int64_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// int64_t unboxed_object = 42;
  /// int64_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using int64_object = box_integer<int64_t>;
  /// @brief Represent a boxed intptr.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::intptr_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// intptr_t unboxed_object = 42;
  /// intptr_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using intptr_object = box_integer<intptr_t>;

  /// @brief Represent a boxed byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::byte_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// byte_t unboxed_object = 42;
  /// byte_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using byte_object = box_integer<byte_t>;
  /// @brief Represent a boxed uint16.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::uint16_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// uint16_t unboxed_object = 42;
  /// uint16_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using uint16_object = box_integer<uint16_t>;
  /// @brief Represent a boxed uint32.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::uint32_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// uint32_t unboxed_object = 42;
  /// uint32_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using uint32_object = box_integer<uint32_t>;
  /// @brief Represent a boxed uint64.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::uint64_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// uint64_t unboxed_object = 42;
  /// uint64_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using uint64_object = box_integer<uint64_t>;
  /// @brief Represent a boxed uintptr.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::uintptr_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// uintptr_t unboxed_object = 42;
  /// uintptr_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using uintptr_object = box_integer<uintptr_t>;

  /// @brief Represent a boxed size_t.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::size_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// size_t unboxed_object = 42;
  /// size_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using size_object = box_integer<size_t>;

  /// @brief Represent a boxed char.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::char_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// char unboxed_object = 'a';
  /// char_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = a;
  /// @endcode
  using char_object = box_integer<char>;
  /// @brief Represent a boxed char8.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::char8_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// char8_t unboxed_object = u8'a';
  /// char8_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = a;
  /// @endcode
  using char8_object = box_integer<char8_t>;
  /// @brief Represent a boxed char16.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::char16_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// char16_t unboxed_object = u'a';
  /// char16_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = a;
  /// @endcode
  using char16_object = box_integer<char16_t>;
  /// @brief Represent a boxed char32.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::char32_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// char32_t unboxed_object = U'a';
  /// char32_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = a;
  /// @endcode
  using char32_object = box_integer<char32_t>;
  /// @brief Represent a boxed wchar.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Example
  /// The following example shows how to create and use xtd::wchar_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// wchar_t unboxed_object = L'a';
  /// wchar_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", r
      /// esult); // Display: result = a;
  /// @endcode
  using wchar_object = box_integer<wchar_t>;

  /// @brief Allows to box an object
  /// @param value Object to box.
  /// @return Boxed object.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<typename type_t>
  inline box<type_t> boxing(const type_t& value) {return box<type_t>(value);}
  
  /// @cond
  inline int16_object boxing(const int16_t& value) {return int16_object(value);}
  inline int32_object boxing(const int32_t& value) {return int32_object(value);}
  inline const object& boxing(const object& value) {return value;}
  inline object& boxing(object& value) {return value;}
  /// @endcond
  
  /// @brief Allows to unbox an object
  /// @param value Object to box.
  /// @return Unboxed object.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<typename type_t>
  inline type_t unboxing(const xtd::box<type_t>& value) {return value.value();}
  
  /// @cond
  inline const object& unboxing(const object& value) {return value;}
  inline object& unboxing(object& value) {return value;}
  
  template<typename type_t>
  inline std::string to_string(const xtd::box<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  
  template<typename type_t>
  inline std::string to_string(const xtd::box_integer<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  
  template<typename type_t>
  inline std::string to_string(const xtd::box_floating_point<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  /// @endcond
}
