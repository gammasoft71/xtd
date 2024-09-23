/// @file
/// @brief Contains xtd::collections::generic::params class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../object.h"
#include "../../string.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief An object of type xtd::collections::generic::params <type_t> is a lightweight proxy object that provides access to an array of objects of type const `type_t` (that may be allocated in read-only memory).
      /// ```cpp
      /// template<typename type_t>
      /// class params : public xtd::object
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/params
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks This class cannot be inherited.
      /// @remarks A xtd::collections::generic::params object is automatically constructed when:
      /// * A brace-enclosed params is used to initialize an object, where the corresponding constructor accepts an xtd::collections::generic::params or [std::initializer_list](https://en.cppreference.com/w/cpp/utility/initializer_list) parameter,
      /// * A brace-enclosed params is used as the right operand of assignment or as a function call argument, and the corresponding assignment operator/function accepts an xtd::collections::generic::params or [std::initializer_list](https://en.cppreference.com/w/cpp/utility/initializer_list) parameter.
      /// * A brace-enclosed params is bound to auto, including in a [ranged for loop](https://en.cppreference.com/w/cpp/language/range-for).
      /// @remarks xtd::collections::generic::params may be implemented as a pair of pointers or pointer and length. Copying a xtd::collections::generic::params does not copy the backing array of the corresponding params.
      /// @remarks xtd::collections::generic::params is exactly The same as [std::initializer_list](https://en.cppreference.com/w/cpp/utility/initializer_list) object.
      /// @warning When creating your own container, use the [std::initializer_list](https://en.cppreference.com/w/cpp/utility/initializer_list) object instead of the xtd::collections::generic::params object for the constructor, because C++ compilers use a magic trick (such as a private constructor) to initialize elements correctly. Use xtd::collections::generic::params when initializing elements yourself.
      /// @par Examples
      /// The following example demonstrates how to usea xtd::collections::generic::params <type_t> class.
      /// @include generic_params.cpp
      template<typename type_t>
      class params final : public xtd::object {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the params base type.
        using base_type = std::initializer_list<type_t>;
        /// @brief Represents the params value type.
        using value_type = typename base_type::value_type;
        /// @brief Represents the reference of params value type.
        using reference = typename base_type::reference;
        /// @brief Represents the const reference of params value type.
        using const_reference = typename base_type::const_reference;
        /// @brief Represents the const pointer of params value type.
        using const_pointer = const value_type*;
        /// @brief Represents the params size type (usually xtd::size).
        using size_type = typename base_type::size_type;
        /// @brief Represents the iterator of params value type.
        using iterator = typename base_type::iterator;
        /// @brief Represents the const iterator of params value type.
        using const_iterator = typename base_type::const_iterator;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Create a new instance of the class xtd::collections::generic::params.
        constexpr params() noexcept = default;
        /// @}
        
        /// @cond
        params(base_type items) noexcept : items_(items) {}
        params& operator =(base_type items) noexcept {items_ = items; return *this;}
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Returns a pointer to the first element in the params.
        /// @return A pointer to the first element in the params.
        /// @remarks If the params is empty, the values of begin() and end() are unspecified, but will be identical.
        constexpr iterator begin() const noexcept {return items_.begin();}
        
        /// @brief Returns pointer to the underlying array serving as element storage.
        /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
        /// @remarks The pointer is such that range [xtd::collections::generic::list::data(), xtd::collections::generic::list::data() + xtd::collections::generic::list::size()) is always a valid range, even if the container is empty (xtd::collections::generic::list::data() is not dereferenceable in that case).
        const_pointer data() const noexcept {return reinterpret_cast<const_pointer>(begin());}
        
        /// @brief Returns a pointer to one past the last element in the params, i.e. begin() + size().
        /// @return A pointer to one past the last element in the params.
        /// @remarks If the params is empty, the values of begin() and end() are unspecified, but will be identical.
        constexpr iterator end() const noexcept {return items_.end();}
        
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        const base_type& items() const noexcept {return items_;}
        
        /// @brief Returns the number of elements in the params, i.e. `std::distance(begin(), end())`.
        /// @return The number of elements in the params.
        constexpr size_type size() const noexcept {return items_.size();}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        xtd::string to_string() const noexcept override {return xtd::string::format("{}", items_);}
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator const base_type&() const noexcept {return items_;}
        /// @}
        
      private:
        base_type items_;
      };
      
      /// @cond
      // C++17 deduction
      // {
      template<typename type_t>
      params(std::initializer_list<type_t>) -> params<type_t>;
      // }
      /// @endcond
    }
  }
}

/// @cond
namespace std {
  template<typename type_t>
  inline const type_t* begin(xtd::collections::generic::params<type_t> items) noexcept {
    return items.begin();
  }
  
  template<typename type_t>
  inline const type_t* end(xtd::collections::generic::params<type_t> items) noexcept {
    return items.end();
  }
}
/// @endcond
