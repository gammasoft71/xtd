/// @file
/// @brief Contains xtd::hash_code class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "collections/generic/helpers/hasher.hpp"
#include "object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Combines the hash code for multiple values into a single hash code.
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
  /// @remarks You can use xtd::hash_code to combine multiple values (for example, fields on a structure or class) into a single hash code. This structure has static and instance methods that operate differently:
  /// @remarks * The static methods accept a set of several values to combine.
  /// @remarks * Two instance methods operate in a streaming fashion, accepting values one at a time.
  /// @warning It's best-practice to consider hash codes as an implementation detail, as the implementation may change across xtd versions. Do not store hash codes produced by xtd::hash_code in serialized structures, for example, on-disk. xtd::hash_code uses a statically initialized random seed to enforce this best practice, meaning that the hash codes are only deterministic within the scope of an operating system process.
  class hash_code : public xtd::object {
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
    template<class type_t>
    hash_code& add(const type_t& value) noexcept {
      hash_code_ = hash_combine(hash_code_, xtd::collections::generic::helpers::hasher<type_t> {}(value));
      return *this;
    }
    
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const xtd::object& other) const noexcept override;
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    xtd::size get_hash_code() const noexcept override;
    
    /// @brief Calculates the final hash code after consecutive xtd::hash_code::add invocations.
    /// @return The calculated hash code.
    /// @remarks This method must be called at most once per instance of xtd::hash_code.
    xtd::size to_hash_code() const noexcept;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Combines values into a hash code.
    /// @param values The values to combine into the hash code.
    /// @return The hash code that represents the values.
    template<class ...args_t>
    inline static xtd::size combine(args_t... values) noexcept {return combine_iterator(generate_uniqueness_seed(), values...);}
    /// @}
    
  private:
    template<class type_t, class ...args_t>
    inline static xtd::size combine_iterator(xtd::size seed, const type_t& value, args_t... values) noexcept {return combine_iterator(hash_combine(seed, xtd::collections::generic::helpers::hasher<type_t> {}(value)), values...);}
    static xtd::size combine_iterator(xtd::size seed) noexcept;
    static xtd::size hash_combine(xtd::size seed, xtd::size value) noexcept;
    static xtd::size generate_uniqueness_seed() noexcept;
    
    xtd::size hash_code_ = generate_uniqueness_seed();
  };
}
