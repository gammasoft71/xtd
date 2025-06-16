/// @file
/// @brief Contains xtd::any_cast alias on [xtd::any_cast](https://www.cppreference.com/w/cpp/utility/any/any_cast.html) operators.
#pragma once
#include "any.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Performs type-safe access to the contained object.
  /// @par Header
  /// ```cpp
  /// #include <xtd/<any_cast>>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param operand The target any object.
  /// @return The type_t value contained in the `operand`.
  /// @exception std::bad_any_cast if the typeid of the requested `type_t` does not match that of the contents of `operand`.
  template<class type_t>
  type_t any_cast(const xtd::any& operand) {
    return std::any_cast<type_t>(operand);
  }
  /// @brief Performs type-safe access to the contained object.
  /// @par Header
  /// ```cpp
  /// #include <xtd/<any_cast>>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param operand The target any object.
  /// @return The type_t value contained in the `operand`.
  /// @exception std::bad_any_cast if the typeid of the requested `type_t` does not match that of the contents of `operand`.
  template<class type_t>
  type_t any_cast(xtd::any& operand) {
    return std::any_cast<type_t>(operand);
  }
  /// @brief Performs type-safe access to the contained object.
  /// @par Header
  /// ```cpp
  /// #include <xtd/<any_cast>>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param operand The target any object.
  /// @return The type_t value contained in the `operand`.
  /// @exception std::bad_any_cast if the typeid of the requested `type_t` does not match that of the contents of `operand`.
  template<class type_t>
  type_t any_cast(xtd::any&& operand) {
    return std::any_cast<type_t>(operand);
  }
  /// @brief Performs type-safe access to the contained object.
  /// @par Header
  /// ```cpp
  /// #include <xtd/<any_cast>>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param operand The target any object.
  /// @return The type_t pointer on the `operand` value.
  /// @exception std::bad_any_cast if the typeid of the requested `type_t` does not match that of the contents of `operand`.
  /// @remarks If the `operand` is null poinetr, the result is null pointer.
  template<class type_t>
  type_t* any_cast(xtd::any* operand) {
    return std::any_cast<type_t>(operand);
  }
  /// @brief Performs type-safe access to the contained object.
  /// @par Header
  /// ```cpp
  /// #include <xtd/<any_cast>>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param operand The target any object.
  /// @return The type_t pointer on the `operand` value.
  /// @exception std::bad_any_cast if the typeid of the requested `type_t` does not match that of the contents of `operand`.
  /// @remarks If the `operand` is null poinetr, the result is null pointer.
  template<class type_t>
  type_t* any_cast(const xtd::any* operand) {
    return std::any_cast<type_t>(operand);
  }
}
