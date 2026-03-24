/// @file
/// @brief Contains xtd::any_object class.
#pragma once
#include "collections/generic/helpers/comparer.hpp"
#include "boxing.hpp"
#include "enum_object.hpp"
#include "icomparable.hpp"
#include "iequatable.hpp"
#include "invalid_operation_exception.hpp"
#include "is.hpp"
#include "object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a polymorphic wrapper capable of holding any type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/any_object>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following code example illustrates the use of xtd::any_object class.
  /// @include any.cpp
  /// @remarks TTo add a class, structure or any other type unknown to xtd, you need to implement the xtd::iequatable and xtd::icompoabale interfaces or overrride the == and < operetors.
  class any_object : public object, public icomparable<any_object>, public iequatable<any_object> {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::any_object class.
    any_object() noexcept = default;
    /// @brief Initializes a new instance of the xtd::any_object class with specified value.
    /// @param value The value to initialize the contained value with.
    template<typename type_t> // Can't be explicit by design.
    any_object(type_t&& value) noexcept : value_(boxing_ptr(std::forward<type_t>(value))) {}
    /// @brief Initializes a new instance of the xtd::any_object class with specified value.
    /// @param value The value to initialize the contained value with.
    template<typename type_t> // Can't be explicit by design.
    any_object(type_t& value) noexcept : value_(boxing_ptr(value)) {}
    /// @brief Initializes a new instance of the xtd::any_object class with specified value.
    /// @param value The value to initialize the contained value with.
    template<typename type_t> // Can't be explicit by design.
    any_object(const type_t& value) noexcept : value_(boxing_ptr(value)) {}
    /// @}
    
    /// @cond
    any_object(any_object&&) noexcept = default;
    any_object(any_object&) noexcept = default;
    any_object(const any_object&) noexcept = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets a value indicating whether the current xtd::any_object object has a valid value of its underlying type.
    /// @return `true` if the current xtd::any_object object has a value; `false` if the current xtd::any_object object has no value.
    /// @remarks If the xtd::any_object::has_value property is `true`, the value of the current xtd::any_object object can be accessed with the xtd::any_object::value property. Otherwise, attempting to access its value throws an xtd::invalid_operation_exception exception.
    [[nodiscard]] auto has_value() const noexcept -> bool;
    
    /// @brief Gets the value of the current xtd::any_object object if it has been assigned a valid underlying value.
    /// @return The value of the current xtd::any_object object if the xtd::any_object::has_value property is `true`. An exception is thrown if the xtd::any_object::has_value property is `false`.
    /// @exception xtd::invalid_operation_exception The xtd::any_object::has_value property is `false`.
    [[nodiscard]] auto value() const -> const object&;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Compares the current instance with another object of the same type.
    /// @param obj An object to compare with this instance.
    /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    ///
    /// | Value             | Condition                          |
    /// | ----------------- | ---------------------------------- |
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    [[nodiscard]] auto compare_to(const any_object& other) const noexcept -> int32 override;
    
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    [[nodiscard]] auto equals(const object& other) const noexcept -> bool override;
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    [[nodiscard]] auto equals(const any_object& other) const noexcept -> bool override;
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    [[nodiscard]] auto get_hash_code() const noexcept -> xtd::size override;
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
    
    /// @brief Reset the current object. Set the current object to null.
    /// @remarks If xtd::any_object::has_values is `true`, destroys the contained object; otherwise does nothing.
    auto reset() noexcept -> void;
    /// @}
    
    /// @name Public Operators
    
    /// @{
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
    /// @param other Another polymorphic wrapper.
    /// @return This current instance.
    auto operator =(const any_object& other) noexcept -> any_object& = default;
    /// @brief Move assignment operator. Replaces the contents with a copy of the contents of other.
    /// @param other Another polymorphic wrapper.
    /// @return This current instance.
    auto operator =(any_object&& other) noexcept -> any_object&;
    /// @}
    
  private:
    template<typename type_t>
    [[nodiscard]] auto boxing_ptr(const type_t& value) noexcept -> ptr<object> {return new_ptr<typename __box_enum_or_object__<type_t, typename std::is_enum<type_t>::type>::type>(value);}
    template<typename type_t, typename ...args_t>
    [[nodiscard]] auto boxing_ptr(args_t&& ...args) noexcept -> ptr<object> {return new box<type_t>(args...);}
    //[[nodiscard]] auto boxing_ptr(const object& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const char* value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const char8* value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const char16* value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const char32* value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const wchar* value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const char& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const char8& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const char16& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const char32& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const wchar& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(char& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(char8& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(char16& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(char32& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(wchar& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const xtd::byte& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const int16& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const int32& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const int64& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const slong& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const sbyte& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const uint16& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const uint32& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const uint64& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const xtd::ulong& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(xtd::byte& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(int16& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(int32& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(int64& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(slong& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(sbyte& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(uint16& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(uint32& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(uint64& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(xtd::ulong& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const float& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const double& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(const decimal& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(float& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(double& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(decimal& value) noexcept -> ptr<object>;
    [[nodiscard]] auto boxing_ptr(std::nullptr_t value) noexcept -> ptr<object>;
    
    ptr<object> value_;
  };
  
  /// @cond
  template<typename type_t, typename bool_t>
  struct __is_enum_any_object__ {};
  
  template<typename type_t>
  struct __is_enum_any_object__<type_t, std::true_type> {
    [[nodiscard]] auto operator()(const any_object& o) const -> bool {return is<enum_object<type_t>>(o.value());}
  };
  
  template<typename type_t>
  struct __is_enum_any_object__<type_t, std::false_type> {
    [[nodiscard]] auto operator()(const any_object& o) const -> bool {return false;}
  };
  
  template<typename type_t, typename bool_t>
  struct __is_polymorphic_any_object__ {};
  
  template<typename type_t>
  struct __is_polymorphic_any_object__<type_t, std::true_type> {
    [[nodiscard]] auto operator()(const any_object& o) const -> bool {return is<type_t>(o.value());}
  };
  
  template<typename type_t>
  struct __is_polymorphic_any_object__<type_t, std::false_type> {
    [[nodiscard]] auto operator()(const any_object& o) const -> bool {return __is_enum_any_object__<type_t, typename std::is_enum<type_t>::type> {}(o);}
  };
  
  template<typename type_t>
  requires (!std::is_null_pointer_v<type_t> && (!std::integral<type_t> || std::same_as<type_t, bool>))
  [[nodiscard]] auto is(any_object& o) -> bool {
    if (!o.has_value()) return false;
    if (is<box<type_t>>(o.value())) return true;
    return __is_polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type > {}(o);
  }
  
  template<typename type_t>
  requires (!std::is_null_pointer_v<type_t> && (!std::integral<type_t> || std::same_as<type_t, bool>))
  [[nodiscard]] auto is(const any_object& o) -> bool {
    if (!o.has_value()) return false;
    if (is<box<type_t>>(o.value())) return true;
    return __is_polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type > {}(o);
  }
  
  template<typename type_t>
  requires (!std::is_null_pointer_v<type_t> && std::integral<type_t> && !std::same_as<type_t, bool>)
  [[nodiscard]] auto is(any_object& o) -> bool {
    if (!o.has_value()) return false;
    if (xtd::is<xtd::box_integer<xtd::byte>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::byte>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int16>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::int16>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int32>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::int32>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int64>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::int64>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::sbyte>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::sbyte>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::slong>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::slong>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint16>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::uint16>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint32>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::uint32>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint64>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::uint64>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::ulong>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::ulong>&>(o.value()).value);
    return false;
  }
  
  template<typename type_t>
  requires (!std::is_null_pointer_v<type_t> && std::integral<type_t> && !std::same_as<type_t, bool>)
  [[nodiscard]] auto is(const any_object& o) -> bool {
    if (!o.has_value()) return false;
    if (xtd::is<xtd::box_integer<xtd::byte>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::byte>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int16>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::int16>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int32>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::int32>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int64>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::int64>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::sbyte>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::sbyte>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::slong>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::slong>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint16>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::uint16>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint32>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::uint32>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint64>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::uint64>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::ulong>>(o.value())) return xtd::box_integer<type_t>::is_valid(static_cast<const xtd::box_integer<xtd::ulong>&>(o.value()).value);
    return false;
  }

  template<typename type_t>
  requires std::is_null_pointer_v<type_t>
  [[nodiscard]] auto is(any_object& o) -> bool {
    return !o.has_value();
  }
  
  template<typename type_t>
  requires std::is_null_pointer_v<type_t>
  [[nodiscard]] auto is(const any_object& o) -> bool {
    return !o.has_value();
  }

  template<typename type_t>
  [[nodiscard]] auto is(any_object* o) -> bool {
    if (is<box<type_t>>(o->value())) return true;
    return __is_polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type > {}(*o);
  }
  
  template<typename type_t>
  [[nodiscard]] auto is(const any_object* o) -> bool {
    if (is<box<type_t>>(o->value())) return true;
    return __is_polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type > {}(*o);
  }
  /// @endcond
}
