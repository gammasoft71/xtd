/// @file
/// @brief Contains xtd::box_integer class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
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
  /// The following example shows how to create and use xtd::box_integer<int32>.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// int32 unboxed_object = 42;
  /// box_integer<int32> boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  template<typename type_t>
  class box_integer : public xtd::box<type_t> {
  public:
    /// @cond
    box_integer() = default;
    box_integer(const type_t& value) : xtd::box<type_t>(value) {}
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
  /// xtd::byte unboxed_object = 42;
  /// byte_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using byte_object = box_integer<xtd::byte>;
  
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
  /// int16 unboxed_object = 42;
  /// int16_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using int16_object = box_integer<int16>;
  
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
  /// int32 unboxed_object = 42;
  /// int32_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  
  using int32_object = box_integer<int32>;
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
  /// int64 unboxed_object = 42;
  /// int64_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  
  using int64_object = box_integer<int64>;
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
  /// intptr unboxed_object = 42;
  /// intptr_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using intptr_object = box_integer<intptr>;
  
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
  /// sbyte unboxed_object = 42;
  /// sbyte_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using sbyte_object = box_integer<sbyte>;
  
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
  /// uint16 unboxed_object = 42;
  /// uint16_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using uint16_object = box_integer<uint16>;
  
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
  /// uint32 unboxed_object = 42;
  /// uint32_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using uint32_object = box_integer<uint32>;
  
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
  /// uint64 unboxed_object = 42;
  /// uint64_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using uint64_object = box_integer<uint64>;
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
  /// uintptr unboxed_object = 42;
  /// uintptr_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  using uintptr_object = box_integer<uintptr>;
  
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
  using llong_object = box_integer<slong>;
  using ullong_object = box_integer<xtd::ulong>;
  
  inline byte_object boxing(const xtd::byte& value) noexcept {return byte_object(value);}
  inline int16_object boxing(const int16& value) noexcept {return int16_object(value);}
  inline int32_object boxing(const int32& value) noexcept {return int32_object(value);}
  inline int64_object boxing(const int64& value) noexcept {return int64_object(value);}
  inline llong_object boxing(const slong& value) noexcept {return llong_object(value);}
  inline sbyte_object boxing(const sbyte& value) noexcept {return sbyte_object(value);}
  inline uint16_object boxing(const uint16& value) noexcept {return uint16_object(value);}
  inline uint32_object boxing(const uint32& value) noexcept {return uint32_object(value);}
  inline uint64_object boxing(const uint64& value) noexcept {return uint64_object(value);}
  inline ullong_object boxing(const xtd::ulong& value) noexcept {return ullong_object(value);}
  inline byte_object boxing(xtd::byte& value) noexcept {return byte_object(value);}
  inline int16_object boxing(int16& value) noexcept {return int16_object(value);}
  inline int32_object boxing(int32& value) noexcept {return int32_object(value);}
  inline int64_object boxing(int64& value) noexcept {return int64_object(value);}
  inline llong_object boxing(slong& value) noexcept {return llong_object(value);}
  inline sbyte_object boxing(sbyte& value) noexcept {return sbyte_object(value);}
  inline uint16_object boxing(uint16& value) noexcept {return uint16_object(value);}
  inline uint32_object boxing(uint32& value) noexcept {return uint32_object(value);}
  inline uint64_object boxing(uint64& value) noexcept {return uint64_object(value);}
  inline ullong_object boxing(xtd::ulong& value) noexcept {return ullong_object(value);}
  
  inline xtd::byte unboxing(const xtd::byte& value) noexcept {return value;}
  inline int16 unboxing(const int16& value) noexcept {return value;}
  inline int32 unboxing(const int32& value) noexcept {return value;}
  inline int64 unboxing(const int64& value) noexcept {return value;}
  inline slong unboxing(const slong& value) noexcept {return value;}
  inline sbyte unboxing(const sbyte& value) noexcept {return value;}
  inline uint16 unboxing(const uint16& value) noexcept {return value;}
  inline uint32 unboxing(const uint32& value) noexcept {return value;}
  inline uint64 unboxing(const uint64& value) noexcept {return value;}
  inline xtd::ulong unboxing(const xtd::ulong& value) noexcept {return value;}
  inline xtd::byte unboxing(xtd::byte& value) noexcept {return value;}
  inline int16 unboxing(int16& value) noexcept {return value;}
  inline int32 unboxing(int32& value) noexcept {return value;}
  inline int64 unboxing(int64& value) noexcept {return value;}
  inline slong unboxing(slong& value) noexcept {return value;}
  inline sbyte unboxing(sbyte& value) noexcept {return value;}
  inline uint16 unboxing(uint16& value) noexcept {return value;}
  inline uint32 unboxing(uint32& value) noexcept {return value;}
  inline uint64 unboxing(uint64& value) noexcept {return value;}
  inline xtd::ulong unboxing(xtd::ulong& value) noexcept {return value;}
  
  template<typename type_t>
  inline std::string to_string(const xtd::box_integer<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  /// @endcond
}
