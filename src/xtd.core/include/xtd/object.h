/// @file
/// @brief Contains xtd::object class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once

#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.h"
#undef __XTD_STD_INTERNAL__
#define __XTD_CORE_INTERNAL__
#include "internal/__string_definitions.h"
#undef __XTD_CORE_INTERNAL__
#include "core_export.h"
#include "iequatable.h"
#include "types.h"
#if defined(__xtd__cpp_lib_format)
#include <cassert>
#include <format>
#endif
#include <string>
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class type_object;
  /// @endcond
  
  /// @brief Supports all classes in the xtd class hierarchy and provides low-level services to derived classes.
  /// This is the ultimate base class of all classes in the xtd.
  /// It is the root of the type hierarchy.
  /// ```cpp
  /// class core_export_ object
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example defines a `point` type derived from the xtd::object class and overrides many of the virtual methods of the xtd::object class. In addition, the example shows how to call many of the static and instance methods of the xtd::object class.
  /// @include object.cpp
  class core_export_ object {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of the ultimate base class object.
    /// @remarks This constructor is called by constructors in derived classes, but it can also be used to directly create an instance of the object class.
    object() = default;
    /// @}
    
    /// @cond
    object(const object&) = default;
    object& operator =(const object&) = default;
    virtual ~object() = default;
    bool operator ==(const object& obj) const noexcept;
    bool operator !=(const object& obj) const noexcept;
    /// @endcond
    
    /// @name Public Methods
    
    /// @{
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return true if the specified object is equal to the current object. otherwise, false.
    /// @par Examples
    /// The following code example compares the current instance with another object.
    /// @include object_equals.cpp
    virtual bool equals(const object& obj) const noexcept;
    
    /// @brief Serves as a hash function for a particular type.
    /// @return size_t A hash code for the current object.
    virtual size_t get_hash_code() const noexcept;
    
    /// @brief Gets the type of the current instance.
    /// @return The type instance that represents the exact runtime type of the current instance.
    /// @par Examples
    /// The following code example demonstrates that xtd::object::get_type returns the runtime type of the current instance.
    /// @include object_get_type.cpp
    virtual type_object get_type() const noexcept;
    
    /// @brief Creates a shallow copy of the current object.
    /// @return A shallow copy of the current object.
    /// @par Examples
    /// The following example illustrates the xtd::object::memberwise_clone method. It defines a `shallow_copy` method that calls the xtd::object::memberwise_clone method to perform a shallow copy operation on a `person` object. It also defines a `deep_copy` method that performs a deep copy operation on a `person` object.
    /// @include object_memberwise_clone.cpp
    /// In this example, the `person::id_info` property returns an `id_info` object.
    /// As the output from the example shows, when a `person` object is cloned by calling the xtd::object::memberwise_clone method, the cloned `person` object is an independent copy of the original object, except that they share the same `person::id_info` object reference.
    /// As a result, modifying the clone's `person::id_info` property changes the original object's `person::id_info` property.
    /// On the other hand, when a deep copy operation is performed, the cloned `person` object, including its `person::id_info` property, can be modified without affecting the original object.
    /// @remarks The xtd::object::memberwise_clone method creates a shallow copy by creating a new object, and then copying the nonstatic fields of the current object to the new object. If a field is a value type, a bit-by-bit copy of the field is performed. If a field is a reference type, the reference is copied but the referred object is not; therefore, the original object and its clone refer to the same object.
    /// @remarks For example, consider an object called X that references objects A and B. Object B, in turn, references object C. A shallow copy of X creates new object X2 that also references objects A and B. In contrast, a deep copy of X creates a new object X2 that references the new objects A2 and B2, which are copies of A and B. B2, in turn, references the new object C2, which is a copy of C. The example illustrates the difference between a shallow and a deep copy operation.
    /// @remarks There are numerous ways to implement a deep copy operation if the shallow copy operation performed by the xtd::object::memberwise_clone method does not meet your needs. These include the following:
    /// * Call a class constructor of the object to be copied to create a second object with property values taken from the first object. This assumes that the values of an object are entirely defined by its class constructor.
    /// * Call the xtd::object::memberwise_clone method to create a shallow copy of an object, and then assign new objects whose values are the same as the original object to any properties or fields whose values are reference types. The `deep_copy` method in the example illustrates this approach.
    /// * Serialize the object to be deep copied, and then restore the serialized data to a different object variable.
    /// * Use reflection with recursion to perform the deep copy operation.
    template<typename object_t>
    xtd::uptr<object_t> memberwise_clone() const {
      auto object_ptr = dynamic_cast<const object_t*>(this);
      if (object_ptr == nullptr) __throw_invalid_cast_exception(__FILE__, __LINE__, __func__);
      return xtd::new_uptr<object_t>(*object_ptr);
    }
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    /// @par Examples
    /// The following code example demonstrates what to_string returns.
    /// @include object_to_string.cpp
    virtual xtd::string to_string() const noexcept;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Determines whether the specified object instances are considered equal.
    /// @param object_a The first object to compare.
    /// @param object_b The second object to compare.
    /// @return true if object_a is the same instance as object_b or if both are null references or if object_a(object_b) returns true. otherwise, false.
    /// @par Examples
    /// The following code example compares different objects.
    /// @include object_equals2.cpp
    template<typename object_a_t, typename object_b_t>
    static bool equals(const object_a_t& object_a, const object_b_t& object_b) noexcept {
      static_assert(std::is_base_of<xtd::object, object_a_t>::value, "object_a does not inherit from xtd::object");
      static_assert(std::is_base_of<xtd::object, object_b_t>::value, "object_b does not inherit from xtd::object");
      return object_a == object_b;
    }

    /// @brief Determines whether the specified object instances are the same instance.
    /// @param object_a The first object to compare.
    /// @param object_b The second object to compare.
    /// @return true if object_a is the same instance as object_b or if both are null references; otherwise, false.
    /// @par Examples
    /// The following code example uses xtd::object::reference_equals to determine if two objects are the same instance.
    /// @include object_reference_equals.cpp
    template<typename object_a_t, typename object_b_t>
    static bool reference_equals(const object_a_t& object_a, const object_b_t& object_b) noexcept {
      static_assert(std::is_base_of<xtd::object, object_a_t>::value, "object_a does not inherit from xtd::object");
      static_assert(std::is_base_of<xtd::object, object_b_t>::value, "object_b does not inherit from xtd::object");
      return &object_a == &object_b;
    }
    /// @}
    
  private:
    void __throw_invalid_cast_exception(const string& file, uint32 line, const string& method) const;
  };
}

/// @cond
std::ostream& operator <<(std::ostream& os, const xtd::object& obj) noexcept;
/// @endcond

#include "type.h"

/*
/// @cond
/// Needed for std::format
#if defined(__xtd__cpp_lib_format)
template <>
struct std::formatter<xtd::object> : std::formatter<std::string> {
  template <typename object_t, typename format_context_t>
  auto format(const object_t& obj, format_context_t& ctx) const {return std::format_to(ctx.out(), "{}", std::string {obj.to_string()});}
};
#endif
/// @endcond
*/
