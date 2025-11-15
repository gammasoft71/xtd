/// @file
/// @brief Contains xtd::shared_ptr_object class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "hash_code.hpp"
#include "icomparable.hpp"
#include "iequatable.hpp"
#include "null_ptr.hpp"
#include "object.hpp"
#include "unique_ptr_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief The xtd::shared_ptr_object is a shared pointer as [std::shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr).
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @par Examples
  /// This example shows to use xtd::shared_ptr_object with xtd::version class
  /// @code
  /// shared_ptr_object<xtd::version> version = new_shared_ptr_object<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_shared_ptr_object(version); // Not mandatory.
  /// @endcode
  template<class type_t>
  class shared_ptr_object : public xtd::object, public xtd::icomparable<shared_ptr_object<type_t>>, public xtd::iequatable<shared_ptr_object<type_t >> {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the base type ([std::shared_ptr<type_t>](https://en.cppreference.com/w/cpp/memory/shared_ptr))
    using base_type = std::shared_ptr<type_t>;
    /// @brief Represent the element type.
    using element_type = typename base_type::element_type;
    /// @brief Represent the weak type.
    using weak_type = typename base_type::weak_type;
    /// @}
    
    /// @name Public Static Fields
    
    /// @{
    /// @brief Represents the empty xtd::shared_ptr_object. This field is constant.
    static const shared_ptr_object empty;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class.
    shared_ptr_object() noexcept = default;
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified null pointer.
    /// @param null The null pointer.
    shared_ptr_object(xtd::null_ptr null) noexcept : ptr_ {null} {} // Can't be explicit by design.
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified shared pointer object.
    /// @param value The shared pointer object.
    shared_ptr_object(shared_ptr_object&& value) noexcept : ptr_ {std::move(value.ptr_)} {}
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified shared pointer object.
    /// @param value The shared pointer object.
    shared_ptr_object(const shared_ptr_object& value) noexcept : ptr_ {value.ptr_} {}
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified pointer.
    /// @param value The pointer.
    template<class pointer_t>
    explicit shared_ptr_object(pointer_t* ptr) noexcept : ptr_ {ptr} {}
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified shared pointer object.
    /// @param value The shared pointer object.
    template<class value_t>
    shared_ptr_object(shared_ptr_object<value_t>&& value) noexcept : ptr_ {std::move(value.ptr_)} {}
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified shared pointer object.
    /// @param value The shared pointer object.
    template<class value_t>
    shared_ptr_object(const shared_ptr_object<value_t>& value) noexcept : ptr_ {value.ptr_} {}
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified shared pointer object.
    /// @param value The shared pointer object.
    shared_ptr_object(const base_type& value) noexcept : ptr_ {value} {}
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified shared pointer object.
    /// @param value The shared pointer object.
    shared_ptr_object(base_type&& value) noexcept : ptr_ {std::move(value)} {}
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified shared pointer object.
    /// @param value The shared pointer object.
    template<class value_t>
    shared_ptr_object(const std::shared_ptr<value_t>& value) noexcept : ptr_ {value} {}
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified weak pointer object.
    /// @param value The weak pointer object.
    template<class value_t>
    explicit shared_ptr_object(const std::weak_ptr<value_t>& value) noexcept : ptr_ {value} {}
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified unique pointer object.
    /// @param value The unique pointer object.
    template<class value_t, class deleter_t>
    shared_ptr_object(xtd::unique_ptr_object<value_t, deleter_t>&& value) : ptr_ {std::move(value.pointer())} {}
    /// @brief Initializes a new instance of the xtd::shared_ptr_object class with specified unique pointer object.
    /// @param value The unique pointer object.
    template<class value_t, class deleter_t>
    shared_ptr_object(std::unique_ptr<value_t, deleter_t>&& value) : ptr_ {std::move(value)} {}
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief Checks whether the managed object is managed only by the current xtd::shared_ptr_object object.
    /// @return `true` if the managed object is managed only by the current xtd::shared_ptr_object object; otherwise `false`.
    bool is_unique() const noexcept {return use_count() == xtd::size {1};}
    
    /// @brief Provides owner-based ordering of shared pointers.
    /// @param other The xtd::shared_ptr_object to be compared.
    /// @return `true` if thid current instance precedes `other`; otherwise `false`.
    template<class value_t>
    bool owner_before(const shared_ptr_object<value_t>& other) const noexcept {return ptr_.owner_before(other.ptr_);}
    /// @brief Provides owner-based ordering of shared pointers.
    /// @param other The xtd::shared_ptr_object::base_type to be compared.
    /// @return `true` if thid current instance precedes `other`; otherwise `false`.
    template<class value_t>
    bool owner_before(const std::shared_ptr<value_t>& other) const noexcept {return ptr_.owner_before(other);}
    /// @brief Provides owner-based ordering of shared pointers.
    /// @param other The std::weak_ptr to be compared.
    /// @return `true` if thid current instance precedes `other`; otherwise `false`.
    template<class value_t>
    bool owner_before(const std::weak_ptr<value_t>& other) const noexcept {return ptr_.owner_before(other);}
    
    /// @brief Returns the underlying base type pointer.
    /// @return The underlying base type pointer.
    const base_type& pointer() const noexcept {return ptr_;}
    
    /// @brief Returns the underlying base type pointer.
    /// @return The underlying base type pointer.
    base_type& pointer() noexcept {return ptr_;}
    
    /// @brief Gets the number of xtd::shared_ptr_object objects referring to the same managed object.
    /// @return The number of xtd::shared_ptr_object objects referring to the same managed object.
    xtd::size use_count() const noexcept {return static_cast<xtd::size>(ptr_.use_count());}
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
    int32 compare_to(const shared_ptr_object& obj) const noexcept override {return to_pointer() < obj.to_pointer() ? -1 : to_pointer() > obj.to_pointer() ? 1 : 0;}
    
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const xtd::object& value) const noexcept override {return dynamic_cast<const shared_ptr_object*>(&value) && equals(static_cast<const shared_ptr_object&>(value));}
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    bool equals(const shared_ptr_object& value) const noexcept override {return ptr_ == value.ptr_;}
    
    /// @brief Gets the stored pointer.
    /// @return The stored pointer.
    element_type* get() const noexcept {return ptr_.get();}
    
    /// @brief Serves as a hash function for a particular type.
    /// @return size_t A hash code for the current object.
    xtd::size get_hash_code() const noexcept override {return (ptr_ ? xtd::hash_code::combine(to_pointer()) : 0);}
    
    /// @brief Resets the current object. Set the current object to null.
    /// @remarks xtd::shared_ptr_object::usecount property is decremented. If alias count equal 0 the object T is deleted.
    void reset() noexcept {ptr_.reset();}
    /// @brief Resets the current object. Set the current object with specified pointer.
    /// @param ptr The pointer to assign the current object. It can be null.
    /// @remarks xtd::shared_ptr_object::usecount property is decremented. If alias count equal 0 the object T is deleted.
    template<class pointer_t>
    void reset(pointer_t* ptr) noexcept {ptr_.reset(ptr);}
    /// @brief Resets the current object. Set the current object with specified pointer.
    /// @param null The null pointer.
    void reset(xtd::null_ptr null) noexcept {ptr_.reset();}
    
    /// @brief Swaps this current instance with specified shared pointer object.
    /// @param ptr The shared pointer object to swap with this current instance.
    void swap(shared_ptr_object& ptr) noexcept {ptr_.swap(ptr.ptr_);}
    
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
    /// @brief Assignment operator with specified xtd::shared_ptr_object value.
    /// @param value The value to assign.
    shared_ptr_object& operator =(shared_ptr_object&& value) noexcept {
      ptr_ = std::move(value.ptr_);
      return *this;
    }
    
    /// @brief Assignment operator with specified xtd::shared_ptr_object value.
    /// @param value The value to assign.
    shared_ptr_object& operator =(const shared_ptr_object& value) noexcept {
      ptr_ = value.ptr_;
      return *this;
    }
    
    /// @brief Assignment operator with specified xtd::shared_ptr_object value.
    /// @param value The value to assign.
    template<class value_t>
    shared_ptr_object& operator =(shared_ptr_object<value_t>&& value) noexcept {
      ptr_ = std::move(value.ptr_);
      return *this;
    }
    
    /// @brief Assignment operator with specified xtd::shared_ptr_object value.
    /// @param value The value to assign.
    template<class value_t>
    shared_ptr_object& operator =(const shared_ptr_object<value_t>& value) noexcept {
      ptr_ = value.ptr_;
      return *this;
    }
    
    /// @brief Assignment operator with specified std::shared_ptr value.
    /// @param value The value to assign.
    template<class value_t>
    shared_ptr_object& operator =(std::shared_ptr<value_t>&& value) noexcept {
      ptr_ = std::move(value);
      return *this;
    }
    
    /// @brief Assignment operator with specified std::shared_ptr value.
    /// @param value The value to assign.
    template<class value_t>
    shared_ptr_object& operator =(const std::shared_ptr<value_t>& value) noexcept {
      ptr_ = value;
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
    
    /// @brief Returns the underlying base type pointer.
    /// @return The underlying base type pointer.
    operator base_type() const noexcept {return ptr_;}
    
    /// @brief Returns a weak type pointer.
    /// @return A weak type pointer.
    operator weak_type() const noexcept {return weak_type {ptr_};}
    /// @}
    
  private:
    template<class other_t>
    friend class shared_ptr_object;
    base_type ptr_;
  };
  
  template<class type_t>
  inline const shared_ptr_object<type_t>  shared_ptr_object<type_t>::empty;
  /// @}
  
  /// @cond
  // Deduction guides for xtd::reference_wrapper_object
  // {
  template<class type_t>
  shared_ptr_object(type_t*) -> shared_ptr_object<type_t>;
  template<class type_t>
  shared_ptr_object(std::weak_ptr<type_t>()) -> shared_ptr_object<type_t>;
  template<class type_t, class deleter_t>
  shared_ptr_object(xtd::unique_ptr_object<type_t, deleter_t>()) -> shared_ptr_object<type_t>;
  template<class type_t, class deleter_t>
  shared_ptr_object(std::unique_ptr<type_t, deleter_t>()) -> shared_ptr_object<type_t>;
  // }
}
