/// @file
/// @brief Contains xtd::range class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "object.hpp"
#include "usize.hpp"
#include "usize_object.hpp"
#include "epos.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a range that has start and end indexes.
  /// ```cpp
  /// class range : public xtd::object;
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
  class range : public xtd::object, xtd::iequatable<range> {
  public:
    ///@name Public Aliases
    
    /// @{
    /// @brief Represents the xtd::range index type.
    using index_type = xtd::usize; /// @todo Replace xtd::usize with xtd::index
    /// @}
    
    ///@name Public Constructors
    
    /// @{
    /// @brief Instantiates a new xtd::range instance.
    range() noexcept = default;
    /// @brief Instantiates a new xtd::range instance with the specified starting and ending indexes.
    /// @param start The inclusive start index of the range.
    /// @param end The exclusive end index of the range.
    range(index_type start, index_type end) noexcept : start_{start}, end_{end} {}
    /// @}
    
    ///@name Public Properties
    
    /// @{
    ///@brief Gets an Index that represents the exclusive end index of the range.
    ///@return The end index of the range.
    [[nodiscard]] auto end() const noexcept -> index_type {return end_;}
    /// @brief Gets the inclusive start index of the Range.
    /// @return The inclusive start index of the range.
    [[nodiscard]] auto start() const noexcept -> index_type {return start_;}
    /// @}
    
    /// @name Public Methods
    ///
    /// @{
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    [[nodiscard]] auto equals(const object& obj) const noexcept -> bool override {return is<range>(obj) && equals(static_cast<const range& > (obj));}
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    [[nodiscard]] auto equals(const range& value) const noexcept -> bool override {return xtd::collections::generic::helpers::equator<index_type> {}(start_, value.start_) && xtd::collections::generic::helpers::equator<index_type> {}(end_, value.end_);}
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override {return hash_code::combine(start_, end_);}
    
    /// @brief Returns the string representation of the current Range object.
    /// @return The string representation of the range.
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override {return xtd::string::format("{}..{}", index_to_string(start_), index_to_string(end_));}
    /// @}
    
    /// @name Public Static Properties
    ///
    /// @{
    /// @brief Gets a xtd::range object that starts from the first element to the end.
    /// @return A range from the start to the end.
    [[nodiscard]] static auto all() noexcept -> xtd::range {return range {index_type {0}, xtd::epos};}
    /// @}
    
    /// @name Public Static Methods
    ///
    /// @{
    /// @brief Creates a xtd::range object starting from the first element in the collection to a specified end index.
    /// @param end The position of the last element up to which the Range object will be created.
    /// @return A range that starts from the first element to end.
    [[nodiscard]] static auto end_at(index_type end) noexcept -> xtd::range {return range {index_type {0}, end};}
    
    /// @brief Creates a new xtd::range object starting from a specified start index to the end of the collection.
    /// @param start The position of the first element from which the Range will be created.
    /// @return A range from start to the end of the collection.
    [[nodiscard]] static auto start_at(index_type start) noexcept -> xtd::range {return range {start, xtd::epos};}
    /// @}
  private:
    /// @todo replcae by xtd::index::to_string()...
    static auto index_to_string(index_type index) noexcept -> xtd::string {return index > xtd::usize_object::max_value / 2 ? xtd::string::format("~{}", ~index) : xtd::string::format("{}", index);}
    index_type start_ = index_type {0};
    index_type end_ = index_type {0};
  };
}
