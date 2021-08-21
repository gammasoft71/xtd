/// @file
/// @brief Contains xtd::object class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <string>
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class ustring;
  /// @endcond
  
  /// @brief Supports all classes in the xtd class hierarchy and provides low-level services to derived classes.
  /// This is the ultimate base class of all classes in the xtd.
  /// It is the root of the type hierarchy.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// The following example defines a point type derived from the Oobject class and virtuals many of the virtual methods of the object class. In addition, the example shows how to call many of the static and instance methods of the object class.
  /// @include object.cpp
  class object {
  public:
    /// @brief Create a new instance of the ultimate base class object
    /// @remarks This constructor is called by constructors in derived classes, but it can also be used to directly create an instance of the object class.
    object() = default;

    /// @cond
    object(const object&) = default;
    object& operator=(const object&) = default;
    virtual ~object() = default;
    //friend std::ostream& operator <<(std::ostream& os, const object& obj) noexcept {return os << obj.to_string();}
    /// @endcond

    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return true if the specified object is equal to the current object. otherwise, false.
    /// @par Examples
    /// The following code example compares the current instance with another object.
    /// @include object_equals.cpp
    virtual bool equals(const object& obj) const noexcept;
    
    /// @brief Determines whether the specified object instances are considered equal.
    /// @param object_a The first object to compare.
    /// @param object_b The second object to compare.
    /// @return true if object_a is the same instance as object_b or if both are null references or if object_a(object_b) returns true. otherwise, false.
    /// @par Examples
    /// The following code example compares different objects.
    /// @include object_equals2.cpp
    static bool equals(const object& object_a, const object& object_b) noexcept;
    
    /// @brief Serves as a hash function for a particular type.
    /// @return size_t A hash code for the current object.
    virtual size_t get_hash_code() const noexcept;

    /// @brief Gets the type of the current instance.
    /// @return The type instance that represents the exact runtime type of the current instance.
    /// @par Examples
    /// The following code example demonstrates that GetType returns the runtime type of the current instance.
    /// @include object_get_type.cpp
    //virtual type get_type() const;
    
    /// @brief Creates a shallow copy of the current object.
    /// @return A shallow copy of the current object.
    /// @par Examples
    /// The following code example shows how to copy an instance of a class using memberwise_clone.
    /// @include object_memberwise_clone.cpp
    template<typename object_t>
    std::unique_ptr<object_t> memberwise_clone() const {return std::make_unique<object_t>(dynamic_cast<const object_t&>(*this));}
    
    /// @brief Determines whether the specified object instances are the same instance.
    /// @param object_a The first object to compare.
    /// @param object_b The second object to compare.
    /// @return true if object_a is the same instance as object_b or if both are null references; otherwise, false.
    /// @par Examples
    /// The following code example uses reference_equals to determine if two objects are the same instance.
    /// @include object_reference_equals.cpp
    static bool reference_equals(const object& object_a, const object& object_b) noexcept;
    
    /// @brief Returns a std::string that represents the current object.
    /// @return A string that represents the current object.
    /// @par Examples
    /// The following code example demonstrates what to_string returns.
    /// @include object_to_string.cpp
    virtual xtd::ustring to_string() const noexcept;
  };
}
