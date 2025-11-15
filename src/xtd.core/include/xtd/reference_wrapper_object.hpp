/// @file
/// @brief Contains xtd::reference_wrapper_object class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/throw_helper.hpp"
#include "hash_code.hpp"
#include "icomparable.hpp"
#include "iequatable.hpp"
#include "null_ptr.hpp"
#include "object.hpp"
#include <optional>
#include <functional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace linq {
    class enumerable;
  }
  /// @endcond
  
  /// @name Native types
  
  /// @{
  /// @brief The xtd::reference_wrapper_object is a reference wrapper as [std::reference_wrapper](https://en.cppreference.com/w/cpp/utility/functional/reference_wrapper).
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @par Examples
  /// This example shows to use xtd::reference_wrapper_object with xtd::version class
  /// @code
  /// version ver = version {1, 2, 3};
  /// reference_wrapper_object<version> ver_ref = create_reference_wrapper_object(ver);
  ///
  /// console::write_line("version = {}", ver_ref.to_string());
  /// @endcode
  template<class type_t>
  class reference_wrapper_object : public xtd::object, public xtd::icomparable<reference_wrapper_object<type_t>>, public xtd::iequatable<reference_wrapper_object<type_t >> {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the base type ([std::reference_wrapper<type_t>](https://en.cppreference.com/w/cpp/utility/functional/reference_wrapper))
    using base_type = std::reference_wrapper<type_t>;
    /// @brief Represent the referenced type.
    using type = typename base_type::type;
    /// @brief Represent the referenced type.
    using reference_type = typename base_type::type;
    /// @}
    
    /// @name Public Static Fields
    
    /// @{
    /// @brief Represents the empty xtd::reference_wrapper_object. This field is constant.
    static const reference_wrapper_object empty;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object class.
    reference_wrapper_object() noexcept = default;
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object class with specified null pointer.
    /// @param null The null pointer.
    reference_wrapper_object(xtd::null_ptr null) noexcept {} // Can't be explicit by design.
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object class with specified reference.
    /// @param value The reference.
    template<class value_t>
    reference_wrapper_object(value_t&& value) noexcept : ref_ {value} {} // Can't be explicit by design.
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object class with specified reference object.
    /// @param value The reference object.
    reference_wrapper_object(reference_wrapper_object& value) noexcept : ref_ {value.ref_} {}
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object class with specified reference object.
    /// @param value The reference object.
    reference_wrapper_object(const reference_wrapper_object& value) noexcept : ref_ {value.ref_} {}
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object class with specified reference object.
    /// @param value The reference object.
    reference_wrapper_object(reference_wrapper_object&& value) noexcept : ref_ {std::move(value.ref_)} {}
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object class with specified reference object.
    /// @param value The reference object.
    template<class value_t>
    reference_wrapper_object(reference_wrapper_object<value_t>& value) noexcept : ref_ {value.ref_} {}
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object class with specified reference object.
    /// @param value The reference object.
    template<class value_t>
    reference_wrapper_object(const reference_wrapper_object<value_t>& value) noexcept : ref_ {value.ref_} {}
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object class with specified reference object.
    /// @param value The reference object.
    template<class value_t>
    reference_wrapper_object(reference_wrapper_object<value_t>&& value) noexcept : ref_ {std::move(value.ref_)} {}
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object::base_type class with specified reference object.
    /// @param value The reference object.
    reference_wrapper_object(base_type& value) noexcept : ref_ {value} {}
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object::base_type class with specified reference object.
    /// @param value The reference object.
    reference_wrapper_object(const base_type& value) noexcept : ref_ {value} {}
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object::base_type class with specified reference object.
    /// @param value The reference object.
    reference_wrapper_object(base_type&& value) noexcept : ref_ {std::move(value)} {}
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object::base_type class with specified reference object.
    /// @param value The reference object.
    template<class value_t>
    reference_wrapper_object(std::reference_wrapper<value_t>& value) noexcept : ref_ {value} {}
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object::base_type class with specified reference object.
    /// @param value The reference object.
    template<class value_t>
    reference_wrapper_object(const std::reference_wrapper<value_t>& value) noexcept : ref_ {value} {}
    /// @brief Initializes a new instance of the xtd::reference_wrapper_object::base_type class with specified reference object.
    /// @param value The reference object.
    template<class value_t>
    reference_wrapper_object(std::reference_wrapper<value_t>&& value) noexcept : ref_ {std::move(value)} {}
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief Checks if the stored reference is empty.
    /// @return `true`if stored reference is empty; otherwise `false`.
    /// @par Examples
    /// The following code shows how to use xtd::reference_wrapper_object::get and xtd::reference_wrapper_object::is_empty
    /// @code
    /// template<class value_t>
    /// void print_value(const reference_wrapper_object<value_t>& value) {
    ///   if (value.is_empty()) println("value is empty");
    ///   else println("value = {}", value.get());
    /// }
    /// @endcode
    bool is_empty() const noexcept {return !ref_.has_value();}
    
    /// @brief Returns the underlying base type reference.
    /// @return The underlying base type reference.
    const base_type& reference() const {
      if (!ref_.has_value()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      return ref_.value();
    }
    /// @brief Returns the underlying base type reference.
    /// @return The underlying base type reference.
    base_type& reference() {
      if (!ref_.has_value()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      return ref_.value();
    }
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
    int32 compare_to(const reference_wrapper_object& obj) const noexcept override {
      if (!ref_.has_value() && !obj.ref_.has_value()) return 0;
      if (ref_.has_value() && !obj.ref_.has_value()) return 1;
      if (!ref_.has_value() && obj.ref_.has_value()) return -1;
      return &ref_.value().get() < &obj.ref_.value().get() ? -1 : &ref_.value().get() > &obj.ref_.value().get() ? 1 : 0;
    }
    
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const xtd::object& value) const noexcept override {return dynamic_cast<const reference_wrapper_object*>(&value) && equals(static_cast<const reference_wrapper_object&>(value));}
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    bool equals(const reference_wrapper_object& value) const noexcept override {
      if (!ref_.has_value() && !value.ref_.has_value()) return true;
      if (ref_.has_value() && !value.ref_.has_value()) return false;
      if (!ref_.has_value() && value.ref_.has_value()) return false;
      return &ref_.value().get() == &value.ref_.value().get();
    }
    
    /// @brief Gets the stored reference.
    /// @return The stored reference.
    /// @exception xtd::null_pointer_exception If xtd::reference_wrapper_object is empty.
    /// @par Examples
    /// The following code shows how to use xtd::reference_wrapper_object::get and xtd::reference_wrapper_object::is_empty
    /// @code
    /// template<class value_t>
    /// void print_value(const reference_wrapper_object<value_t>& value) {
    ///   if (value.is_empty()) println("value is empty");
    ///   else println("value = {}", value.get());
    /// }
    /// @endcode
    type& get() const {
      if (!ref_.has_value()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      return ref_.value();
    }
    
    /// @brief Serves as a hash function for a particular type.
    /// @return size_t A hash code for the current object.
    xtd::size get_hash_code() const noexcept override {return (ref_.has_value() ? xtd::hash_code::combine(&reference()) : 0);}
    
    /// @brief Resets the current object. Set the current object to null.
    /// @remarks xtd::reference_wrapper_object::usecount property is decremented. If alias count equal 0 the object T is deleted.
    void reset() noexcept {ref_.reset();}
    /// @brief Resets the current object. Set the current object with specified reference.
    /// @param value The reference to assign the current object. It can be null.
    /// @remarks xtd::reference_wrapper_object::usecount property is decremented. If alias count equal 0 the object T is deleted.
    template<class value_t>
    void reset(value_t&& value) noexcept {ref_ = value;}
    /// @brief Resets the current object. Set the current object with specified null value.
    /// @param null The null value.
    void reset(xtd::null_ptr null) noexcept {ref_.reset();}
    
    
    /// @brief Swaps this current instance with specified reference object.
    /// @param value The reference object to swap with this current instance.
    void swap(reference_wrapper_object& value) noexcept {std::swap(ref_, value.ref_);}
    
    /// @brief Gets the stored object.
    /// @return The stored object.
    /// @exception xtd::null_pointer_exception If xtd::reference_wrapper_object is empty.
    /// @par Examples
    /// The following code shows how to use xtd::reference_wrapper_object::to_object and xtd::reference_wrapper_object::is_empty
    /// @code
    /// template<class value_t>
    /// void print_value(const reference_wrapper_object<value_t>& value) {
    ///   if (value.is_empty()) println("value is empty");
    ///   else println("value = {}", value.get());
    /// }
    /// @endcode
    type_t& to_object() const {return get();}
    
    /// @brief Gets the stored object with specified `target_t` type.
    /// @return The stored object.
    /// @exception xtd::cast_exception If the current object can't be casted in target_t.
    template<typename target_t>
    target_t to_object() const;
    
    /// @brief Gets the stored reference.
    /// @return The stored reference.
    type& to_reference() const {return get();}
    
    /// @brief Gets the stored reference with specified `target_t` type.
    /// @return The stored reference.
    /// @exception xtd::cast_exception If the current object can't be casted in target_t.
    template<typename target_t>
    target_t to_reference() const;
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    xtd::string to_string() const noexcept override;
    /// @}
    
    /// @name Public Operators
    
    /// @{
    /// @brief Assignment operator with specified xtd::reference_wrapper_object value.
    /// @param value The value to assign.
    reference_wrapper_object& operator =(const reference_wrapper_object& value) noexcept {
      ref_ = value.ref_;
      return *this;
    }
    /// @brief Assignment operator with specified xtd::reference_wrapper_object value.
    /// @param value The value to assign.
    reference_wrapper_object& operator =(reference_wrapper_object& value) noexcept {
      ref_ = value.ref_;
      return *this;
    }
    /// @brief Assignment operator with specified xtd::reference_wrapper_object value.
    /// @param value The value to assign.
    reference_wrapper_object& operator =(reference_wrapper_object&& value) noexcept {
      ref_ = std::move(value.ref_);
      return *this;
    }
    /// @brief Assignment operator with specified xtd::reference_wrapper_object value.
    /// @param value The value to assign.
    template<class value_t>
    reference_wrapper_object& operator =(const reference_wrapper_object<value_t>& value) noexcept {
      ref_ = value.ref_;
      return *this;
    }
    /// @brief Assignment operator with specified xtd::reference_wrapper_object value.
    /// @param value The value to assign.
    template<class value_t>
    reference_wrapper_object& operator =(reference_wrapper_object<value_t>& value) noexcept {
      ref_ = value.ref_;
      return *this;
    }
    /// @brief Assignment operator with specified xtd::reference_wrapper_object value.
    /// @param value The value to assign.
    template<class value_t>
    reference_wrapper_object& operator =(reference_wrapper_object<value_t>&& value) noexcept {
      ref_ = std::move(value.ref_);
      return *this;
    }
    /// @brief Assignment operator with specified xtd::reference_wrapper_object::base_type value.
    /// @param value The value to assign.
    template<class value_t>
    reference_wrapper_object& operator =(const std::reference_wrapper<value_t>& value) noexcept {
      ref_ = value;
      return *this;
    }
    /// @brief Assignment operator with specified xtd::reference_wrapper_object::base_type value.
    /// @param value The value to assign.
    template<class value_t>
    reference_wrapper_object& operator =(std::reference_wrapper<value_t>& value) noexcept {
      ref_ = value;
      return *this;
    }
    /// @brief Assignment operator with specified xtd::reference_wrapper_object::base_type value.
    /// @param value The value to assign.
    reference_wrapper_object& operator =(const base_type& value) noexcept {
      ref_ = value;
      return *this;
    }
    /// @brief Assignment operator with specified xtd::reference_wrapper_object::base_type value.
    /// @param value The value to assign.
    reference_wrapper_object& operator =(base_type& value) noexcept {
      ref_ = value;
      return *this;
    }
    /// @brief Assignment operator with specified xtd::reference_wrapper_object::base_type value.
    /// @param value The value to assign.
    template<class value_t>
    reference_wrapper_object& operator =(value_t&& value) noexcept {
      ref_ = value;
      return *this;
    }
    
    /// @brief Gets the stored object.
    /// @return The stored object.
    /// @exception xtd::null_pointer_exception If xtd::reference_wrapper_object is empty.
    /// @par Examples
    /// The following code shows how to use xtd::reference_wrapper_object::operator type& and xtd::reference_wrapper_object::is_empty
    /// @code
    /// template<class value_t>
    /// void print_value(const reference_wrapper_object<value_t>& value) {
    ///   if (value.is_empty()) println("value is empty");
    ///   else println("value = {}", value.get());
    /// }
    /// @endcode
    operator type& () const {return get();}
    
    /// @brief Checks if the stored reference is not empty.
    /// @return `true`if stored reference is not empty; otherwise `false`.
    explicit operator bool() const noexcept {return ref_.has_value();}
    
    /// @brief Equal to operator with specidied lhs ans rhs values.
    /// @param lhs The left hand side value to compare.
    /// @param rhs The right hand side value to compare.
    /// @return `true` if lhs is equal to rhs; otherwise `false`.
    friend bool operator ==(const reference_wrapper_object& lhs, const type_t& rhs) noexcept {
      if (!lhs.ref_.has_value()) return false;
      return &lhs.ref_.value().get() == &rhs;
    }
    /// @brief Not equal to operator with specidied lhs ans rhs values.
    /// @param lhs The left hand side value to compare.
    /// @param rhs The right hand side value to compare.
    /// @return `true` if lhs is not equal to rhs; otherwise `false`.
    friend bool operator !=(const reference_wrapper_object& lhs, const type_t& rhs) noexcept {return !(lhs == rhs);}
    
    /// @brief Three-way comparison operator with specidied lhs ans rhs values.
    /// @param lhs The left hand side value to compare.
    /// @param rhs The right hand side value to compare.
    /// @return A strong ordering result:
    /// * std::strong_ordering::less : if lhs less than rhs;
    /// * std::strong_ordering::greater : if lhs greater than rhs;
    /// * std::strong_ordering::equivalent : if lhs is equal to rhs.
    friend std::strong_ordering operator <=>(const reference_wrapper_object& lhs, const type_t& rhs) noexcept {
      if (!lhs.ref_.has_value()) return std::strong_ordering::less;
      if (&lhs.ref_.value().get() < &rhs) return std::strong_ordering::less;
      if (&lhs.ref_.value().get() > &rhs) return std::strong_ordering::greater;
      return std::strong_ordering::equivalent;
    }
    /// @}
    
  private:
    template<class other_t>
    friend class reference_wrapper_object;
    std::optional<base_type> ref_;
  };
  
  template<class type_t>
  inline const reference_wrapper_object<type_t>  reference_wrapper_object<type_t>::empty;
  /// @}
  
  /// @cond
  // Deduction guides for xtd::reference_wrapper_object
  // {
  template<class type_t>
  reference_wrapper_object(type_t&) -> reference_wrapper_object<type_t>;
  // }
  /// @endcond
}
