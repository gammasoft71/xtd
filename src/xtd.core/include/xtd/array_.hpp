/// @file
/// @brief Contains xtd::array class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#if !defined(__XTD_ARRAY_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/array> or <xtd/array.hpp> instead."
#endif

#include "string.hpp"
#include "collections/object_model/read_only_collection.hpp"
#include <numeric>

/// @cond
namespace xtd {
  // C++17 deduction guides for xtd::array
  // {
  template<class type_t, xtd::size rank = 1, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  array(type_t, type_t, allocator_t = allocator_t()) -> array<type_t, rank, allocator_t>;
  
  template<class type_t, xtd::size rank = 1, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  array(std::initializer_list<type_t>) -> array<type_t, rank, allocator_t>;
  
  template<class type_t, xtd::size length, xtd::size rank = 1, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  array(const type_t(&a)[length]) -> array<type_t, rank, allocator_t>;
  
  template<class type_t, xtd::size rank = 1, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  array(const xtd::collections::generic::ienumerable<type_t>&) -> array<type_t, rank, allocator_t>;
  
  template<class type_t, xtd::size rank = 1, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  array(const xtd::collections::generic::ilist<type_t>&) -> array<type_t, rank, allocator_t>;
  
  template<class type_t, xtd::size rank = 1, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  array(const std::vector<type_t>&) -> array<type_t, rank, allocator_t>;
  
  template<class type_t, xtd::size rank = 1, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  array(const array<type_t, rank, allocator_t>&) -> array<type_t, rank, allocator_t>;
  
  template<class type_t, xtd::size rank = 1, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  array(std::vector<type_t>&&) -> array<type_t, rank, allocator_t>;
  
  template<class type_t, xtd::size rank = 1, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  array(array<type_t, rank, allocator_t>&&) -> array<type_t, rank, allocator_t>;
  // }
}

template<class type_t, class allocator_t>
inline const type_t& xtd::basic_array<type_t, allocator_t>::get_value(const xtd::array<xtd::size>& indexes) const {
  return operator()(indexes);
}

template<class type_t, class allocator_t>
inline xtd::string xtd::basic_array<type_t, allocator_t>::to_string() const noexcept {
  return xtd::string::format("[{}]", xtd::string::join(", ", *this));
}

template<class type_t, class allocator_t>
inline type_t& xtd::basic_array<type_t, allocator_t>::operator()(const xtd::array<xtd::size>& indexes) {
  auto position = xtd::size {0};
  for (auto index1 = xtd::size {0}; index1 < indexes.size(); ++index1) {
    if (indexes[index1] >= get_length(index1)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
    auto multiplicand = xtd::size {1};
    for (auto index2 = index1 + 1; index2 < indexes.size(); ++index2)
      multiplicand *= get_length(index2);
    position += indexes[index1] * multiplicand;
  }
  if (position >= length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
  return data_->items[position];
}

template<class type_t, class allocator_t>
inline const type_t& xtd::basic_array<type_t, allocator_t>::operator()(const xtd::array<xtd::size>& indexes) const {
  auto position = xtd::size {0};
  for (auto index1 = xtd::size {0}; index1 < indexes.size(); ++index1) {
    if (indexes[index1] >= get_length(index1)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
    auto multiplicand = xtd::size {1};
    for (auto index2 = index1 + 1; index2 < indexes.size(); ++index2)
      multiplicand *= get_length(index2);
    position += indexes[index1] * multiplicand;
  }
  if (position >= length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
  return data_->items[position];
}

template<class type_t, class allocator_t>
inline xtd::basic_array<type_t, allocator_t>::basic_array(const array<size_type, 1>& lengths) : basic_array(lengths, value_type {}) {
}

template<class type_t, class allocator_t>
inline xtd::basic_array<type_t, allocator_t>::basic_array(const array<size_type, 1>& lengths, const value_type& value) {
  data_->items = base_type(lengths.aggregate([&](const size_type & accumulator, const size_type & value) {return accumulator * value;}), value);
  data_->lower_bound.clear();
  data_->upper_bound.clear();
  for (auto length : lengths) {
    data_->lower_bound.push_back(0);
    data_->upper_bound.push_back(length - 1);
  }
}

template<class type_t, class allocator_t>
template<class value_t, xtd::size rank_>
xtd::size xtd::basic_array<type_t, allocator_t>::internal_compute_index(const xtd::array<value_t, rank_>& items, xtd::size rank, xtd::size index) {
  auto relative = index - items.get_lower_bound(rank);
  auto multiplier = xtd::size {1};
  for (auto r = rank + 1; r < rank_; ++r)
    multiplier *= items.get_length(r);
  return relative * multiplier;
}

template<class type_t, class allocator_t>
template<class value_t, xtd::size rank_>
xtd::string xtd::basic_array<type_t, allocator_t>::internal_to_string(const xtd::array<value_t, rank_>& items, xtd::size rank, xtd::size base_index) {
  auto result = xtd::string {"["};
  for (auto index = items.get_lower_bound(rank); index <= items.get_upper_bound(rank); ++index) {
    if (index != items.get_lower_bound(rank)) result += ", ";
    auto offset = base_index + internal_compute_index(items, rank, index);
    if (rank + 1 < rank_) result += internal_to_string(items, rank + 1, offset);
    else result += xtd::string::format("{}", items[offset]);
  }
  result += "]";
  return result;
}

template<class type_t, class allocator_t>
inline xtd::collections::object_model::read_only_collection<type_t> xtd::array<>::as_read_only(const xtd::array<type_t, 1, allocator_t>& array) {
  return xtd::collections::object_model::read_only_collection<type_t> {array};
}

template<class type_t, xtd::size rank_, class allocator_t>
inline xtd::string xtd::array<type_t, rank_, allocator_t>::to_string() const noexcept {
  return xtd::basic_array<type_t, allocator_t>::internal_to_string(self_, 0);
}

template<class type_t, class allocator_t>
inline xtd::string xtd::array<type_t, 1, allocator_t>::to_string() const noexcept {
  return xtd::basic_array<type_t, allocator_t>::internal_to_string(self_, 0);
}

template<class type_t, class allocator_t>
inline xtd::string xtd::array<type_t, 2, allocator_t>::to_string() const noexcept {
  return xtd::basic_array<type_t, allocator_t>::internal_to_string(self_, 0);
}

template<class type_t, class allocator_t>
inline xtd::string xtd::array<type_t, 3, allocator_t>::to_string() const noexcept {
  return xtd::basic_array<type_t, allocator_t>::internal_to_string(self_, 0);
}
/// @endcond
