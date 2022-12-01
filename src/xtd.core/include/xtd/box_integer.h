/// @file
/// @brief Contains xtd::box_integer class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "box.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
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
  /// @par Examples
  /// The following example shows how to create and use xtd::box_integer<int32_t>.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// int32_t unboxed_object = 42;
  /// box_integer<int32_t> boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  template<typename type_t>
  class box_integer : public xtd::box<type_t> {
  public:
    /// @cond
    box_integer() = default;
    box_integer(const type_t& value) : box<type_t>(value) {}
    box_integer(const box_integer&) = default;
    box_integer(box_integer&&) = default;
    box_integer& operator =(const box_integer&) = default;
    /// @endcond
    
    /// @brief Represents the largest possible value of type_t. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::max().
    static constexpr type_t max_value = std::numeric_limits<type_t>::max();
    /// @brief Represents the smallest possible value of type_t. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::lowest().
    static constexpr type_t min_value = std::numeric_limits<type_t>::lowest();
  };
  
  /// @brief Represent a boxed byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example shows how to create and use xtd::byte_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// byte_t unboxed_object = 42;
  /// byte_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using byte_object = box_integer<byte_t>;

  /// @brief Represent a boxed int16.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
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
  /// @par Examples
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
  /// @par Examples
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
  /// @par Examples
  /// The following example shows how to create and use xtd::intptr_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// intptr_t unboxed_object = 42;
  /// intptr_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using intptr_object = box_integer<intptr_t>;

  /// @brief Represent a boxed sbyte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example shows how to create and use xtd::sbyte_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// sbyte_t unboxed_object = 42;
  /// sbyte_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using sbyte_object = box_integer<sbyte_t>;

  /// @brief Represent a boxed uint16.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
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
  /// @par Examples
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
  /// @par Examples
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
  /// @par Examples
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
  /// @par Examples
  /// The following example shows how to create and use xtd::size_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// size_t unboxed_object = 42;
  /// size_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using size_object = box_integer<size_t>;
  
  /// @cond
  inline byte_object boxing(const byte_t& value) {return byte_object(value);}
  inline int16_object boxing(const int16_t& value) {return int16_object(value);}
  inline int32_object boxing(const int32_t& value) {return int32_object(value);}
  inline int64_object boxing(const int64_t& value) {return int64_object(value);}
  //inline intptr_object boxing(const intptr_t& value) {return intptr_object(value);}
  inline sbyte_object boxing(const sbyte_t& value) {return sbyte_object(value);}
  inline uint16_object boxing(const uint16_t& value) {return uint16_object(value);}
  inline uint32_object boxing(const uint32_t& value) {return uint32_object(value);}
  inline uint64_object boxing(const uint64_t& value) {return uint64_object(value);}
  //inline uintptr_object boxing(const uintptr_t& value) {return uintptr_object(value);}

  template<typename type_t>
  inline std::string to_string(const xtd::box_integer<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  /// @endcond
}
