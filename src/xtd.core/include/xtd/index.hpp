/// @file
/// @brief Contains xtd::index struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "collections/generic/extensions/list_common.hpp"
#include "collections/generic/helpers/equator.hpp"
#include "collections/generic/helpers/raw_array.hpp"
#include "iequatable.hpp"
#include "integer.hpp"
#include "is.hpp"
#include "logical.hpp"
#include "object.hpp"
#include "usize.hpp"
#include "npos.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a type that can be used to index a collection either from the beginning or the end.
  /// ```cpp
  /// class index : public xtd::object;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/range>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  struct index : public xtd::object, xtd::iequatable<index> {
    ///@name Public Aliases
    
    /// @{
    /// @brief Represents the xtd::index index type.
    using value_type = xtd::usize;
    /// @}
    
    ///@name Public Constructors
    
    /// @{
    /// @brief Instantiates a new xtd::index instance.
    constexpr index() noexcept = default;
    /// @brief Initializes a new xtd::index with a specified index position and a value that indicates if the index is from the beginning or the end of a collection.
    /// @param value The index value. It has to be greater then or equal to zero.
    /// @param from_end `true` to index from the end of the collection, or `false` to index from the beginning of the collection.
    /// @remarks If the xtd::index is constructed from the end, an index value of 1 points to the last element, and an index value of 0 points beyond the last element.
    constexpr index(xtd::integer auto value, xtd::logical auto from_end) noexcept : __v__{static_cast<value_type>(from_end ? ~value : value)} {}
    /// @brief Initializes a new xtd::index with a specified index position and a value that indicates if the index is from the beginning or the end of a collection.
    /// @param value The index value. It has to be greater then or equal to zero.
    /// @remarks If the xtd::index is constructed from the end, an index value of 1 points to the last element, and an index value of 0 points beyond the last element.
    constexpr explicit index(xtd::integer auto value) noexcept : index {value, false} {}
    /// @}
    
    ///@name Public Properties
    
    /// @{
    ///@brief Gets an xtd::index that represents the exclusive end index of the range.
    ///@return The end index of the range.
    [[nodiscard]] constexpr auto value() const noexcept -> value_type {return is_from_end() ? ~__v__ : __v__;}
    
    /// @brief Gets a value that indicates whether the index is from the start or the end.
    /// @return `true` if the xtd::index is from the end; otherwise, `false`.
    [[nodiscard]] constexpr auto is_from_end() const noexcept -> bool {return __v__ > std::numeric_limits<value_type>::max() / 2;}
    /// @}
    
    /// @name Public Methods
    ///
    /// @{
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    [[nodiscard]] auto equals(const object& obj) const noexcept -> bool override {return is<index>(obj) && equals(static_cast<const index&>(obj));}
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    [[nodiscard]] auto equals(const index& value) const noexcept -> bool override {return xtd::collections::generic::helpers::equator<value_type> {}(__v__, value.__v__);}
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override {return hash_code::combine(__v__);}
    
    /// @brief Calculates the offset from the start of the collection using the specified collection length.
    /// @param length The length of the collection that the xtd::index will be used with. Must be a positive value.
    /// @return The offset.
    [[nodiscard]] auto get_offset(value_type length) const noexcept -> xtd::usize {return is_from_end() ? length - value() : value();}
    
    /// @brief Returns the string representation of the current Range object.
    /// @return The string representation of the range.
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
    
    /// @brief Returns the xtd::usize representation of the current Range object.
    /// @return The xtd::usize representation of the range.
    [[nodiscard]] auto to_usize() const noexcept -> value_type {return __v__;}
    /// @}
    
    /// @cond
    auto operator ++() noexcept -> xtd::index& {++__v__; return *this;}
    auto operator --() noexcept -> xtd::index& {--__v__; return *this;}
    auto operator ++(int) noexcept -> xtd::index {return xtd::index {__v__++};}
    auto operator --(int) noexcept -> xtd::index {return xtd::index {__v__--};}
    constexpr auto operator ~() const noexcept -> xtd::index {return xtd::index {~__v__};}
    constexpr auto operator +() const noexcept -> xtd::index {return xtd::index {+__v__};}
    constexpr auto operator +(xtd::integer auto v) const noexcept -> xtd::index {return xtd::index {__v__ + static_cast<value_type>(v)};}
    constexpr auto operator -(xtd::integer auto v) const noexcept -> xtd::index {return xtd::index {__v__ - static_cast<value_type>(v)};}
    constexpr auto operator *(xtd::integer auto v) const noexcept -> xtd::index {return xtd::index {__v__ * static_cast<value_type>(v)};}
    constexpr auto operator /(xtd::integer auto v) const noexcept -> xtd::index {return xtd::index {__v__ / static_cast<value_type>(v)};}
    constexpr auto operator %(xtd::integer auto v) const noexcept -> xtd::index {return xtd::index {__v__ % static_cast<value_type>(v)};}
    /// @endcond
    
    /// @name Public Static Properties
    ///
    /// @{
    /// @brief Represents a value that is not a valid position in a collection.
    /// @remarks This constant is typically used to indicate the absence of an index or a failed search operation. It is equivalent to the maximum value of xtd::usize.
    /// @remarks The xtd::index::end is equivalent to `~0_i`. With bitwise operator the code is more concise.
    /// @par Examples
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// if (items.index_of(50) == index::end)
    ///   console::write_line("Value not found");
    /// ```
    /// The wollowing exemple shows the same example with bitwise operator as index.
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// if (items.index_of(50) == ~0_i)
    ///   console::write_line("Value not found");
    /// ```
    static const index end;

    /// @brief Represents the index of the last valid element in a collection.
    /// @remarks Unlike xtd::index::end (which means "no position"), xtd::index::last points to the last accessible element of a collection. It is equivalent to `items.count() - 1`.
    /// @note This constant is provided for readability and convenience. For example, `items[xtd::index::last]` directly accesses the last element without manually subtracting one from the collection count.
    /// @remarks The xtd::index::last is equivalent to `~1_i`. With bitwise operator the code is more concise.
    /// @par Examples
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// console::write_line(items[index::last]); // Prints 40
    /// console::write_line(items[index::last - 1]); // Prints 30
    /// ```
    /// The wollowing exemple shows the same example with bitwise operator as index.
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// console::write_line(items[~1_i]); // Prints 40
    /// console::write_line(items[~2_i]); // Prints 30
    /// ```
    static const index last;

    /// @brief Represents the index of the first valid element in a collection.
    /// @remarks Unlike xtd::index::end (which means "no position"), xtd::index::start points to the first accessible element of a collection. It is equivalent to `0`.
    /// @note This constant is provided for readability and convenience. For example, `items[xtd::index::start]` directly accesses the fist element.
    /// @remarks The xtd::index::start is equivalent to `0`. With `0` the code is more concise.
    /// @par Examples
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// println(items[index::start]); // Prints 10
    /// println(items[index::start + 1]); // Prints 20
    /// ```
    /// The wollowing exemple shows the same example without index.
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// console::write_line(items[0]); // Prints 10
    /// console::write_line(items[1]); // Prints 20
    /// ```
    static const index start;
    /// @}
    
    /// @name Public Static Methods
    ///
    /// @{
    /// @brief Creates an xtd::ndex from the end of a collection at a specified index position.
    /// @param value The index value from the end of a collection.
    /// @return The index value.
    inline static constexpr auto from_end(xtd::integer auto value) {return index {value, true};}

    /// @brief Creates an xtd::ndex from the start of a collection at a specified index position.
    /// @param value The index value from the start of a collection.
    /// @return The index value.
    inline static constexpr auto from_start(xtd::integer auto value) {return index {value};}
    /// @}

    /// @cond
    value_type __v__ = value_type {0};
    /// @endcond
  };
}

/// @cond
inline constexpr const xtd::index xtd::index::end {0, true};
inline constexpr const xtd::index xtd::index::last {1, true};
inline constexpr const xtd::index xtd::index::start {0};
/// @endcond

#include "literals/index.hpp"

/// @cond
template<typename type_t, typename allocator_t>
auto xtd::collections::generic::helpers::raw_array<type_t, allocator_t>::operator [](const xtd::index& index) const -> const_reference {return operator [](index.get_offset(size()));}

template<typename type_t, typename allocator_t>
auto xtd::collections::generic::helpers::raw_array<type_t, allocator_t>::operator [](const xtd::index& index) -> reference {return operator [](index.get_offset(size()));}

template<typename type_t, typename allocator_t>
auto xtd::collections::generic::helpers::raw_array<type_t, allocator_t>::operator ()(const xtd::index& index) const -> const_reference {return operator [](index.get_offset(size()));}

template<typename type_t, typename allocator_t>
auto xtd::collections::generic::helpers::raw_array<type_t, allocator_t>::operator ()(const xtd::index& index) -> reference {return operator [](index.get_offset(size()));}

template<typename type_t, typename list_t>
auto xtd::collections::generic::extensions::list_common<type_t, list_t>::operator [](const xtd::index& index) const -> const type_t& {return self().operator [](index.get_offset(self().count()));}

template<typename type_t, typename list_t>
auto xtd::collections::generic::extensions::list_common<type_t, list_t>::operator [](const xtd::index& index) -> type_t& {return self().operator [](index.get_offset(self().count()));}

template<typename type_t, typename list_t>
auto xtd::collections::generic::extensions::list_common<type_t, list_t>::operator ()(const xtd::index& index) const -> const type_t& {return self().operator [](index);}

template<typename type_t, typename list_t>
auto xtd::collections::generic::extensions::list_common<type_t, list_t>::operator ()(const xtd::index& index) -> type_t& {
  return self().operator [](index);
}
/// @endcond
