/// @file
/// @brief Contains xtd::hash_code class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "collections/generic/hasher"
#include "object.h"
#include "literals.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Combines the hash code for multiple values into a single hash code.
  /// This is the ultimate base class of all classes in the xtd.
  /// It is the root of the type hierarchy.
  /// ```cpp
  /// class hash_code : public xtd::object
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The static methods in this class combine the default hash codes of several values.
  /// @include hash_code.cpp
  class hash_code : public object {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of the class hash_code
    hash_code() = default;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Adds a single value to the hash code.
    /// @tparam type_t The type of the value to add to the hash code.
    /// @param value The value to add to the hash code.
    /// @return The current instance.
    template<typename type_t>
    hash_code& add(const type_t value) noexcept {
      hash_code_ = combine(hash_code_, value);
      return *this;
    }
    
    bool equals(const object& other) const noexcept override {return is<hash_code>(other) ? hash_code_ == as<hash_code>(other).hash_code_ : object::equals(other);}

    size_t get_hash_code() const noexcept override {return hash_code_;}

    /// @brief Calculates the final hash code after consecutive xtd::hash_code::add invocations.
    /// @return The calculated hash code.
    /// @remarks This method must be called at most once per instance of xtd::hash_code.
    size_t to_hash_code() const noexcept {return hash_code_;}
    /// @}

    /// @name Public Static Methods
    
    /// @{
    /// @brief Combines values into a hash code.
    /// @param value The first values to combine into the hash code.
    /// @param values The rest of values to combine into the hash code.
    /// @return The hash code that represents the values.
    template<typename type_t, typename ...args_t>
    static size_t combine(type_t value, args_t... values) noexcept {return xtd::collections::generic::hasher<type_t> {}(value) ^ (combine(values...) << 1);}
    /// @}

  private:
    static size_t combine() noexcept {return 0;}
    
    xtd::size hash_code_ = 0;
  };
}
