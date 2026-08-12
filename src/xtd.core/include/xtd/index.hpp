/// @file
/// @brief Contains xtd::index class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "collections/generic/extensions/list_common.hpp"
#include "iequatable.hpp"
#include "object.hpp"
#include "usize.hpp"
#include "usize_object.hpp"
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
  class index : public xtd::object, xtd::iequatable<index> {
  public:
    ///@name Public Aliases
    
    /// @{
    /// @brief Represents the xtd::index index type.
    using value_type = xtd::usize;
    /// @}
    
    ///@name Public Constructors
    
    /// @{
    /// @brief Instantiates a new xtd::index instance.
    index() noexcept = default;
    /// @brief Initializes a new xtd::index with a specified index position and a value that indicates if the index is from the beginning or the end of a collection.
    /// @param value The index value. It has to be greater then or equal to zero.
    /// @param from_end `true` to index from the end of the collection, or `false` to index from the beginning of the collection.
    /// @remarks If the Index is constructed from the end, an index value of 1 points to the last element, and an index value of 0 points beyond the last element.
    explicit index(value_type value, bool from_end = false) noexcept : value_{value} {
      //value_ = from_end ? ~(value - 1) : value > xtd::usize_object::max_value / 2 ? value - 1 : value;
      value_ = from_end ? ~value : value;
    }
    /// @}
    
    ///@name Public Properties
    
    /// @{
    ///@brief Gets an Index that represents the exclusive end index of the range.
    ///@return The end index of the range.
    [[nodiscard]] auto value() const noexcept -> value_type {return is_from_end() ? ~value_ : value_;}
    
    [[nodiscard]] auto is_from_end() const noexcept -> bool {return value_ > xtd::usize_object::max_value / 2;}
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
    [[nodiscard]] auto equals(const index& value) const noexcept -> bool override {return xtd::collections::generic::helpers::equator<value_type> {}(value_, value.value_);}
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override {return hash_code::combine(value_);}
    
    /// @brief Returns the string representation of the current Range object.
    /// @return The string representation of the range.
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override {return is_from_end() ? xtd::string::format("~{}", ~value_) : xtd::string::format("{}", value_);}
    /// @}
    
    /// @name Public Operators
    ///
    /// @{
    operator value_type() {return value_;}
    operator value_type() const {return value_;}
    /// @}
    
    /// @name Public Static Properties
    ///
    /// @{
    /// @brief Represents the index of the firsy valid element in a collection.
    /// @remarks Unlike xtd::npos (which means "no position"), xtd::bpos points to the first accessible element of a collection. It is equivalent to `0`.
    /// @note This constant is provided for readability and convenience. For example, `items[xtd::bpos]` directly accesses the fist element.
    /// @remarks The xtd::index::epos is equivalent to `0`. With `0` the code is more concise.
    /// @par Examples
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// println(items[index::bpos]); // Prints 10
    /// println(items[index::bpos + 1]); // Prints 20
    /// ```
    /// The wollowing exemple shows the same example without index.
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// console::write_line(items[0]); // Prints 10
    /// console::write_line(items[1]); // Prints 20
    /// ```
    static const index bpos;
    /// @brief Represents the index of the last valid element in a collection.
    /// @remarks Unlike xtd::npos (which means "no position"), xtd::epos points to the last accessible element of a collection. It is equivalent to `items.count() - 1`.
    /// @note This constant is provided for readability and convenience. For example, `items[xtd::epos]` directly accesses the last element without manually subtracting one from the collection count.
    /// @remarks The xtd::index::epos is equivalent to `~1_z`. With bitwise operator the code is more concise.
    /// @par Examples
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// console::write_line(items[index::epos]); // Prints 40
    /// console::write_line(items[index::epos - 1]); // Prints 30
    /// ```
    /// The wollowing exemple shows the same example with bitwise operator as index.
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// console::write_line(items[index::~1_z]); // Prints 40
    /// console::write_line(items[index::~2_z]); // Prints 30
    /// ```
    static const index epos;
    /// @brief Represents a value that is not a valid position in a collection.
    /// @remarks This constant is typically used to indicate the absence of an index or a failed search operation. It is equivalent to the maximum value of xtd::usize.
    /// @remarks The xtd::index::epos is equivalent to `~0_z`. With bitwise operator the code is more concise.
    /// @par Examples
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// if (items.index_of(50) == index::npos)
    ///   console::write_line("Value not found");
    /// ```
    /// The wollowing exemple shows the same example with bitwise operator as index.
    /// ```cpp
    /// auto items = array {10, 20, 30, 40};
    /// if (items.index_of(50) == ~0_z)
    ///   console::write_line("Value not found");
    /// ```
    static const index npos;
    /// @}
    
    /// @name Public Static Methods
    ///
    /// @{
    /// @}
  private:
    value_type value_ = value_type {0};
  };
}

/// @cond
inline const xtd::index xtd::index::bpos {0};
inline const xtd::index xtd::index::epos {~1_z};
inline const xtd::index xtd::index::npos {~0_z};

template<typename type_t, typename list_t>
auto xtd::collections::generic::extensions::list_common<type_t, list_t>::operator [](const xtd::index& index) const -> const type_t& {
  return self().operator [](static_cast<xtd::usize>(index));
}

template<typename type_t, typename list_t>
auto xtd::collections::generic::extensions::list_common<type_t, list_t>::operator [](const xtd::index& index) -> type_t& {
  return self().operator [](static_cast<xtd::usize>(index));
}

template<typename type_t, typename list_t>
auto xtd::collections::generic::extensions::list_common<type_t, list_t>::operator ()(const xtd::index& index) const -> const type_t& {
  return self().operator [](static_cast<xtd::usize>(index));
}

template<typename type_t, typename list_t>
auto xtd::collections::generic::extensions::list_common<type_t, list_t>::operator ()(const xtd::index& index) -> type_t& {
  return self().operator [](static_cast<xtd::usize>(index));
}
/// @endcond
