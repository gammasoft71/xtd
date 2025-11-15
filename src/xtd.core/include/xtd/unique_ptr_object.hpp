/// @file
/// @brief Contains xtd::unique_ptr_object class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/throw_helper.hpp"
#define __XTD_CORE_INTERNAL__
#include "internal/__array_definition.hpp"
#include "internal/__list_definition.hpp"
#include "internal/__unique_ptr_object_definition.hpp"
#undef __XTD_CORE_INTERNAL__
#include "hash_code.hpp"
#include "icomparable.hpp"
#include "iequatable.hpp"
#include "null_ptr.hpp"
#include "object.hpp"
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace linq {
    class enumerable;
  }
  /// @endcond
  
  /// @name Native types
  
  /// @{
  /// @brief The xtd::unique_ptr_object is a unique pointer as [std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr).
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @par Examples
  /// This example shows to use xtd::unique_ptr_object with xtd::version class
  /// @code
  /// unique_ptr_object<xtd::version> version = new_unique_ptr_object<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_unique_ptr_object(version); // Not mandatory.
  /// @endcode
  template<class type_t, class deleter_t>
  class unique_ptr_object : public xtd::object, public xtd::icomparable<unique_ptr_object<type_t, deleter_t>>, public xtd::iequatable<unique_ptr_object<type_t, deleter_t >> {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the base type ([std::unique_ptr<type_t, deleter_t>](https://en.cppreference.com/w/cpp/memory/unique_ptr))
    using base_type = std::unique_ptr<type_t, deleter_t>;
    /// @brief Represent the deleter type.
    using deleter_type = typename base_type::deleter_type;
    /// @brief Represent the element type.
    using element_type = typename base_type::element_type;
    /// @brief Represent the pointer type.
    using pointer_type = typename base_type::pointer;
    /// @}
    
    /// @name Public Static Fields
    
    /// @{
    /// @brief Represents the empty xtd::unique_ptr_object. This field is constant.
    static const unique_ptr_object empty;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class.
    unique_ptr_object() noexcept = default;
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified null pointer.
    /// @param null The null pointer.
    unique_ptr_object(xtd::null_ptr null) noexcept : ptr_ {null} {} // Can't be explicit by design.
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified pointer.
    /// @param value The pointer.
    explicit unique_ptr_object(pointer_type ptr) noexcept : ptr_ {ptr} {}
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified pointer and deleter.
    /// @param ptr The pointer.
    /// @param deleter The tdeleter method.
    unique_ptr_object(pointer_type ptr, const deleter_t& deleter) noexcept : ptr_ {ptr, deleter} {}
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified pointer and deleter.
    /// @param ptr The pointer.
    /// @param deleter The tdeleter method.
    unique_ptr_object(pointer_type ptr, deleter_t&& deleter) noexcept : ptr_ {ptr, deleter} {}
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified unique pointer object.
    /// @param value The unique pointer object.
    unique_ptr_object(unique_ptr_object&& value) noexcept : ptr_ {std::move(value.ptr_)} {}
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified unique pointer object.
    /// @param value The unique pointer object.
    template<class value_t, class other_deleter_t>
    unique_ptr_object(unique_ptr_object<value_t, other_deleter_t>&& value) : ptr_ {std::move(value)} {}
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified unique pointer object.
    /// @param value The unique pointer object.
    template<class value_t, class other_deleter_t>
    unique_ptr_object(std::unique_ptr<value_t, other_deleter_t>&& value) : ptr_ {std::move(value)} {}
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified unique pointer object.
    /// @param value The unique pointer object.
    unique_ptr_object(const unique_ptr_object& value) = delete;
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified unique pointer object.
    /// @param value The unique pointer object.
    unique_ptr_object(const base_type& value) = delete;
    
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified pointer.
    /// @param ptr The pointer.
    template<class pointer_t>
    explicit unique_ptr_object(pointer_t* ptr) noexcept : ptr_ {ptr} {}
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified pointer and dleter.
    /// @param ptr The pointer.
    /// @param deleter The tdeleter method.
    template<class pointer_t, class other_deleter_t>
    unique_ptr_object(pointer_t* ptr, other_deleter_t deleter) noexcept : ptr_ {ptr, deleter} {}
    
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified unique pointer object.
    /// @param value The unique pointer object.
    template<class value_t>
    unique_ptr_object(unique_ptr_object<value_t>&& value) noexcept : ptr_ {std::move(value.ptr_)} {}
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified unique pointer object.
    /// @param value The unique pointer object.
    unique_ptr_object(base_type&& value) noexcept : ptr_ {std::move(value)} {}
    /// @brief Initializes a new instance of the xtd::unique_ptr_object class with specified unique pointer object.
    /// @param value The unique pointer object.
    template<class value_t>
    unique_ptr_object(std::unique_ptr<value_t>&& value) noexcept : ptr_ {std::move(value)} {}
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief Returns the underlying base type pointer.
    /// @return The underlying base type pointer.
    const base_type& pointer() const noexcept {return ptr_;}
    /// @brief Returns the underlying base type pointer.
    /// @return The underlying base type pointer.
    base_type& pointer() noexcept {return ptr_;}
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
    int32 compare_to(const unique_ptr_object& obj) const noexcept override {return to_pointer() < obj.to_pointer() ? -1 : to_pointer() > obj.to_pointer() ? 1 : 0;}
    
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const xtd::object& value) const noexcept override {return dynamic_cast<const unique_ptr_object*>(&value) && equals(static_cast<const unique_ptr_object&>(value));}
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    bool equals(const unique_ptr_object& value) const noexcept override {return ptr_ == value.ptr_;}
    
    /// @brief Gets the stored pointer.
    /// @return The stored pointer.
    element_type* get() const noexcept {return ptr_.get();}
    
    /// @brief Serves as a hash function for a particular type.
    /// @return size_t A hash code for the current object.
    xtd::size get_hash_code() const noexcept override {return (ptr_ ? xtd::hash_code::combine(to_pointer()) : 0);}
    
    /// @brief Releases the stored pointer.
    /// @return The stored pointer.
    pointer_type release() noexcept {return ptr_.release();}
    
    /// @brief Resets the current object. Set the current object to null.
    /// @remarks xtd::unique_ptr_object::usecount property is decremented. If alias count equal 0 the object T is deleted.
    void reset() noexcept {ptr_.reset();}
    /// @brief Resets the current object. Set the current object with specified pointer.
    /// @param ptr The pointer to assign the current object. It can be null.
    /// @remarks xtd::unique_ptr_object::usecount property is decremented. If alias count equal 0 the object T is deleted.
    void reset(pointer_type ptr) noexcept {ptr_.reset(ptr);}
    /// @brief Resets the current object. Set the current object with specified pointer.
    /// @param ptr The pointer to assign the current object. It can be null.
    /// @remarks xtd::unique_ptr_object::usecount property is decremented. If alias count equal 0 the object T is deleted.
    template<class pointer_t>
    void reset(pointer_t* ptr) noexcept {ptr_.reset(ptr);}
    /// @brief Resets the current object. Set the current object with specified pointer.
    /// @param null The null pointer.
    void reset(xtd::null_ptr null) noexcept {ptr_.reset(null);}
    
    
    /// @brief Swaps this current instance with specified unique pointer object.
    /// @param ptr The unique pointer object to swap with this current instance.
    void swap(unique_ptr_object& ptr) noexcept {ptr_.swap(ptr.ptr_);}
    
    /// @brief Gets the stored object.
    /// @return The stored object.
    type_t& to_object() const noexcept {return *to_pointer();}
    
    /// @brief Gets the stored object with specified `target_t` type.
    /// @return The stored object.
    /// @exception xtd::cast_exception If the current object can't be casted in target_t.
    template<typename target_t>
    target_t to_object() const;
    
    /// @brief Gets the stored pointer.
    /// @return The stored pointer.
    element_type* to_pointer() const noexcept {return get();}
    
    /// @brief Gets the stored pointer with specified `target_t` type.
    /// @return The stored pointer.
    /// @exception xtd::cast_exception If the current object can't be casted in target_t.
    template<typename target_t>
    target_t* to_pointer() const;
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    xtd::string to_string() const noexcept override;
    /// @}
    
    /// @name Public Operators
    
    /// @{
    /// @brief Assignment operator with specified xtd::unique_ptr_object value.
    /// @param value The value to assign.
    unique_ptr_object& operator =(unique_ptr_object&& value) noexcept {
      ptr_ = std::move(value.ptr_);
      return *this;
    }
    
    /// @brief Assignment operator with specified xtd::unique_ptr_object value.
    /// @param value The value to assign.
    template<class value_t>
    unique_ptr_object& operator =(unique_ptr_object<value_t>&& value) noexcept {
      ptr_ = std::move(value.ptr_);
      return *this;
    }
    
    /// @brief Assignment operator with specified std::unique_ptr value.
    /// @param value The value to assign.
    template<class value_t>
    unique_ptr_object& operator =(std::unique_ptr<value_t>&& value) noexcept {
      ptr_ = std::move(value);
      return *this;
    }
    
    /// @brief Gets the stored object.
    /// @return The stored object.
    type_t& operator *() const noexcept {return ptr_.operator * ();}
    
    /// @brief Gets the stored pointer.
    /// @return The stored pointer.
    type_t* operator ->() const noexcept {return ptr_.operator ->();}
    
    /// @brief Provides indexed access to the stored array.
    /// @param index The array index.
    /// @return A reference to the index-th element of the array, i.e., `get()[index]`.
    element_type& operator[](std::ptrdiff_t index) const {return ptr_.operator [](index);}
    
    /// @brief Checks if the stored pointer is not null.
    /// @return `true`if stored pointer is non null; otherwise `false`.
    explicit operator bool() const noexcept {return ptr_.operator bool();}
    /// @}
    
  private:
    template<class value_t, class other_deleter_t>
    friend class xtd::unique_ptr_object;
    
    template<class value_t, class allocator_t>
    friend class xtd::basic_array;
    
    template<class value_t, class allocator_t>
    friend class xtd::collections::generic::list;
    
    friend class xtd::linq::enumerable;
    
    unique_ptr_object& operator =(const unique_ptr_object& value) noexcept {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);}
    
    base_type ptr_;
  };
  
  template<class type_t, class deleter_t>
  inline const unique_ptr_object<type_t, deleter_t>  unique_ptr_object<type_t, deleter_t>::empty;
  /// @}
  
  /// @cond
  // Deduction guides for xtd::reference_wrapper_object
  // {
  template<class type_t>
  unique_ptr_object(type_t*) -> unique_ptr_object<type_t, std::default_delete<type_t>>;
  template<class type_t, class deleter_t>
  unique_ptr_object(type_t*, const deleter_t&) -> unique_ptr_object<type_t, deleter_t>;
  template<class type_t, class deleter_t>
  unique_ptr_object(xtd::unique_ptr_object<type_t, deleter_t>()) -> unique_ptr_object<type_t, deleter_t>;
  template<class type_t, class deleter_t>
  unique_ptr_object(std::unique_ptr<type_t, deleter_t>()) -> unique_ptr_object<type_t, deleter_t>;
  // }
}

template<class object_t>
xtd::unique_ptr_object<object_t> xtd::object::memberwise_clone() const {
  auto object_ptr = dynamic_cast<const object_t*>(this);
  if (object_ptr == nullptr) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  return xtd::unique_ptr_object<object_t>(new object_t(*object_ptr));
}
