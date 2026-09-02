/// @file
/// @brief Contains xtd::range class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "helpers/throw_helper.hpp"
#include "basic_string_view.hpp"
#include "index.hpp"
#include "index.hpp"
#include "object.hpp"
#include "usize.hpp"
#include "usize_object.hpp"
#include "npos.hpp"
#include "linq/enumerable.hpp"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a range that has start and end indexes.
  /// ```cpp
  /// class range : public xtd::object, xtd::iequatable<range;
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
  /// @par Examples
  /// The following example shows how to use xtd::range with a xtd::collections::generic::list.
  /// @include range.cpp
  /// The following example shows how to use range literal operator.
  /// @include range_literal.cpp
  /// The following example shows how to create your own collection with xtd::range operator.
  /// @include range_operator.cpp
  class range : public xtd::object, xtd::iequatable<range> {
  public:
    ///@name Public Aliases
    
    /// @{
    /// @brief Represents the xtd::range index type.
    using index_type = xtd::index;
    
    /// @brief Represents the size type.
    using size_type = xtd::usize;
    /// @}
    
    ///@name Public Types
    
    /// @{
    /// @brief Represents a offset and length.
    /// @remarks Used by xtd::range::get_offset_and_length method.
    /// @par Examples
    /// ```cpp
    /// auto [start, length] = items_range.get_offset_and_length(items.size());
    /// ```
    struct offset_and_length {
      /// @brief Represents a offset.
      size_type start = 0;
      /// @brief Represents a length.
      size_type length = 0;
    };
    /// @}

    ///@name Public Constructors
    
    /// @{
    /// @brief Instantiates a new xtd::range instance.
    range() noexcept = default;
    /// @brief Instantiates a new xtd::range instance with the specified starting and ending indexes.
    /// @param start The inclusive start index of the range.
    /// @param end The exclusive end index of the range.
    range(const index_type& start, const index_type& end) noexcept : start_{start}, end_{end} {}
    /// @brief Instantiates a new xtd::range instance with the specified starting and ending indexes.
    /// @param start The inclusive start index of the range.
    /// @param end The exclusive end index of the range.
    range(xtd::integer auto start, const xtd::integer auto end) noexcept : start_{start}, end_{end} {}
    /// @}
    
    ///@name Public Properties
    
    /// @{
    ///@brief Gets an Index that represents the exclusive end index of the range.
    ///@return The end index of the range.
    [[nodiscard]] constexpr auto end() const noexcept -> const index_type& {return end_;}
    /// @brief Gets the inclusive start index of the Range.
    /// @return The inclusive start index of the range.
    [[nodiscard]] constexpr auto start() const noexcept -> const index_type& {return start_;}
    /// @}
    
    /// @name Public Methods

    /// @{
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    [[nodiscard]] auto equals(const object& obj) const noexcept -> bool override {return is<range>(obj) && equals(static_cast<const range& > (obj));}
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    [[nodiscard]] auto equals(const range& value) const noexcept -> bool override {return xtd::collections::generic::helpers::equator<index_type> {}(start_, value.start_) && xtd::collections::generic::helpers::equator<index_type> {}(end_, value.end_);}

    /// @brief Calculates the start offset and length of the range object using a collection length.
    /// @param lengh A positive integer that represents the length of the collection that the range will be used with.
    /// @return The start offset and length of the range.
    /// @par Examples
    /// ```cpp
    /// auto [start, length] = items_range.get_offset_and_length(items.size());
    /// ```
    [[nodiscard]] auto get_offset_and_length(size_type length) const -> offset_and_length {
      auto start = start_.get_offset(length);
      auto end = end_.get_offset(length);
      if (end > length || start > end) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return {.start = start, .length = end - start};
    }

    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    [[nodiscard]] auto get_hash_code() const noexcept -> size_type override {return hash_code::combine(start_, end_);}
    
    /// @brief Returns the string representation of the current Range object.
    /// @return The string representation of the range.
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override {return xtd::string::format("{}..{}", start_, end_);}
    /// @}
    
    /// @name Public Static Properties

    /// @{
    /// @brief Gets a xtd::range object that starts from the first element to the end.
    /// @return A range from the start to the end.
    [[nodiscard]] static auto all() noexcept -> xtd::range {return range {xtd::index::start, xtd::index::end};}
    /// @}
    
    /// @name Public Static Methods

    /// @{
    /// @brief Creates a xtd::range object starting from the first element in the collection to a specified end index.
    /// @param end The position of the last element up to which the Range object will be created.
    /// @return A range that starts from the first element to end.
    [[nodiscard]] static auto end_at(index_type end) noexcept -> xtd::range {return range {xtd::index::start, end};}
    /// @brief Creates a xtd::range object starting from the first element in the collection to a specified end index.
    /// @param end The position of the last element up to which the Range object will be created.
    /// @return A range that starts from the first element to end.
    [[nodiscard]] static auto end_at(xtd::integer auto end) noexcept -> xtd::range {return range {xtd::index::start, xtd::index {end}};}

    /// @brief Converts the string to xtd::range equivalent.
    /// @param value A string containing a xtd::index to convert.
    /// @return A xtd::range equivalent to the native value contained in value.
    [[nodiscard]] static auto parse(const xtd::string& value) -> xtd::range {
      auto result = range {};
      if (!try_parse(value, result)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format);
      return result;
    }

    /// @brief Creates a new xtd::range object starting from a specified start index to the end of the collection.
    /// @param start The position of the first element from which the Range will be created.
    /// @return A range from start to the end of the collection.
    [[nodiscard]] static auto start_at(index_type start) noexcept -> xtd::range {return range {start, xtd::index::end};}
    /// @brief Creates a new xtd::range object starting from a specified start index to the end of the collection.
    /// @param start The position of the first element from which the Range will be created.
    /// @return A range from start to the end of the collection.
    [[nodiscard]] static auto start_at(xtd::integer auto start) noexcept -> xtd::range {return range {xtd::index {start}, xtd::index::end};}
    
    /// @brief Converts the string to xtd::range equivalent. A return value indicates whether the conversion succeeded or failed.
    /// @param value A string containing a xtd::range to convert.
    /// @param result A xtd::range equivalent to the native value contained in value.
    /// @return `true` if s was converted successfully; otherwise, `false`.
    [[nodiscard]] static auto try_parse(const xtd::string& value, xtd::range& result) noexcept -> bool {
      auto indexes = value.split('.');
      if (indexes.length() != 3 && !xtd::string::is_empty(indexes[1])) return false;
      if (!xtd::index::try_parse(indexes[0], result.start_)) return false;
      if (!xtd::index::try_parse(indexes[2], result.end_)) return false;
      return true;
    }
    /// @}
  
  private:
    index_type start_ = index_type {0};
    index_type end_ = index_type {0};
  };
}

#include "literals/range.hpp"

/// @cond
template<typename char_t, typename traits_t, typename allocator_t>
auto xtd::basic_string<char_t, traits_t, allocator_t>::operator [](const xtd::range& range) const -> xtd::basic_read_only_string_view<char_t> {
  //return xtd::basic_read_only_string_view<type_t>(self(), range);
  auto [start, length] = range.get_offset_and_length(size());
  return xtd::basic_read_only_string_view<char_t> {chars_.begin() + start, chars_.begin() + start + length};
}

template<typename char_t, typename traits_t, typename allocator_t>
auto xtd::basic_string<char_t, traits_t, allocator_t>::operator ()(const xtd::range& range) const -> xtd::basic_read_only_string_view<char_t> {
  return operator [](range);
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::take(source_t&& source, const xtd::range& range) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  if (range.start().is_from_end() || range.end().is_from_end()) {
    auto safe_source = std::vector<xtd::iterable_value_type<source_t>> {source.begin(), source.end()};
    for (const auto& item : xtd::span<xtd::iterable_value_type<source_t>>{safe_source, range})
      co_yield item;
  } else {
    auto index = xtd::usize {0};
    auto skip = range.start().value();
    auto end = range.end().value();
    //auto source_holder = enumerable_holder<xtd::raw_type<source_t>> {std::forward<source_t>(source)};
    //for (const auto& item : source_holder.get())
    for (const auto& item : source) {
      if (index++ < skip) continue;
      if (index - 1 == end) break;
      co_yield item;
    }
  }
}
/// @endcond
