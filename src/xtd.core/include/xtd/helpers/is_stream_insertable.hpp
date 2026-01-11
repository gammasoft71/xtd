/// @file
/// @brief Contains xtd::helpers::is_stream_insertable struct and is_stream_insertable_v struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <type_traits>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::helpers namespace contains helpers for xtd objects, sush as exception static class.
  namespace helpers {
    /// @brief Type trait that determines whether a type can be inserted into an std::ostream using the stream insertion operator (`operator<<`).
    /// @par Definition
    /// ```cpp
    /// template<class value_t>
    /// struct is_stream_insertable<value_t, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<const value_t&>())>> : std::true_type {};
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/helpers/is_stream_insertable>
    /// ```
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core helpers
    /// This trait evaluates to `std::true_type` if the following expression is valid:
    /// ```cpp
    /// std::declval<std::ostream&>() << std::declval<const value_t&>()
    /// ```
    /// Otherwise, it evaluates to `std::false_type`.
    /// @tparam value_t The type to test for stream insertability.
    /// @note This trait only checks syntactic validity of the insertion expression. It does not guarantee any particular semantic meaning or formatting quality of the output.
    /// @see is_stream_insertable_v
    template<class value_t, class = void>
    struct is_stream_insertable : std::false_type {};
    /// @brief Specialization of is_stream_insertable for types that support stream insertion into std::ostream.
    /// @par Definition
    /// ```cpp
    /// template<class value_t>
    /// struct is_stream_insertable<value_t, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<const std::remove_cvref_t<value_t>&>())>> : std::true_type {};
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/helpers/is_stream_insertable>
    /// ```
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core helpers
    /// This specialization is selected when `value_t` provides a valid `operator<<` overload compatible with `std::ostream`.
    /// @tparam value_t The type to test for stream insertability.
    /// @see is_stream_insertable_v
    template<class value_t>
    struct is_stream_insertable<value_t,
    std::void_t<decltype(std::declval<std::ostream&>() << std::declval<const std::remove_cvref_t<value_t>&>())>> : std::true_type {};
    /// @brief Specialization of is_stream_insertable for types that support stream insertion into std::ostream.
    /// @par Definition
    /// ```cpp
    /// template<class value_t>
    /// struct is_stream_insertable<value_t, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<const std::remove_cvref_t<value_t>&>())>> : std::true_type {};
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/helpers/is_stream_insertable>
    /// ```
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core helpers
    /// This specialization is selected when `value_t` provides a valid `operator<<` overload compatible with `std::ostream`.
    /// @tparam value_t The type to test for stream insertability.
    /// @see is_stream_insertable_v
    template<class value_t>
    requires std::is_enum_v<std::remove_cvref_t<value_t>>
    struct is_stream_insertable<value_t> : std::false_type {};

    /// @brief Convenience variable template equivalent to `is_stream_insertable<value_t>::value`.
    /// This helper allows simpler and more readable usage, especially in `if constexpr` expressions and static assertions.
    /// @tparam value_t The type to test for stream insertability.
    /// ```cpp
    /// static_assert(xtd::helpers::is_stream_insertable_v<int>);
    /// static_assert(!xtd::helpers::is_stream_insertable_v<std::vector<int>>);
    /// ```
    /// @see is_stream_insertable
    template<class value_t>
    inline constexpr bool is_stream_insertable_v = is_stream_insertable<std::remove_cvref_t<value_t>>::value;
  }
}
