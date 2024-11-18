/// @file
/// @brief Contains xtd::array class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once

#if !defined(__XTD_ARRAY_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/array> or <xtd/array.h> instead."
#endif

#include "string.h"
#include "collections/object_model/read_only_collection.h"
#include <numeric>

/// @cond
namespace xtd {
  // C++17 deduction
  // {
  template<typename type_t, xtd::size rank = 1, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  array(type_t, type_t, allocator_t = allocator_t()) -> array<type_t, rank, allocator_t>;
  
  template<typename type_t, xtd::size rank = 1, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  array(std::initializer_list<type_t>) -> array<type_t, rank, allocator_t>;
  
  template<typename type_t, xtd::size length, xtd::size rank = 1, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  array(const type_t(&a)[length]) -> array<type_t, rank, allocator_t>;
  
  template<typename type_t, xtd::size rank = 1, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  array(const xtd::collections::generic::ienumerable<type_t>&) -> array<type_t, rank, allocator_t>;
  
  template<typename type_t, xtd::size rank = 1, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  array(const xtd::collections::generic::ilist<type_t>&) -> array<type_t, rank, allocator_t>;
  
  template<typename type_t, xtd::size rank = 1, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  array(const std::vector<type_t>&) -> array<type_t, rank, allocator_t>;
  
  template<typename type_t, xtd::size rank = 1, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  array(const array<type_t, rank, allocator_t>&) -> array<type_t, rank, allocator_t>;
  
  template<typename type_t, xtd::size rank = 1, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  array(std::vector<type_t>&&) -> array<type_t, rank, allocator_t>;
  
  template<typename type_t, xtd::size rank = 1, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  array(array<type_t, rank, allocator_t>&&) -> array<type_t, rank, allocator_t>;
  // }
}

template<typename type_t, typename allocator_t>
inline const type_t& xtd::basic_array<type_t, allocator_t>::get_value(const xtd::array<xtd::size>& indexes) const {
  return operator()(indexes);
}

template<typename type_t, typename allocator_t>
inline xtd::string xtd::basic_array<type_t, allocator_t>::to_string() const noexcept {
  return xtd::string::format("[{}]", xtd::string::join(", ", *this));
}

template<typename type_t, typename allocator_t>
inline type_t& xtd::basic_array<type_t, allocator_t>::operator()(const xtd::array<xtd::size>& indexes) {
  auto position = xtd::size {0};
  for (auto index1 = xtd::size {0}; index1 < indexes.size(); ++index1) {
    if (indexes[index1] >= get_length(index1)) __throw_index_out_of_range_exception(__FILE__, __LINE__, __func__);
    auto multiplicand = xtd::size {1};
    for (auto index2 = index1 + 1; index2 < indexes.size(); ++index2)
      multiplicand *= get_length(index2);
    position += indexes[index1] * multiplicand;
  }
  if (position >= size()) __throw_index_out_of_range_exception(__FILE__, __LINE__, __func__);
  return data_->items[position];
}

template<typename type_t, typename allocator_t>
inline const type_t& xtd::basic_array<type_t, allocator_t>::operator()(const xtd::array<xtd::size>& indexes) const {
  auto position = xtd::size {0};
  for (auto index1 = xtd::size {0}; index1 < indexes.size(); ++index1) {
    if (indexes[index1] >= get_length(index1)) __throw_index_out_of_range_exception(__FILE__, __LINE__, __func__);
    auto multiplicand = xtd::size {1};
    for (auto index2 = index1 + 1; index2 < indexes.size(); ++index2)
      multiplicand *= get_length(index2);
    position += indexes[index1] * multiplicand;
  }
  if (position >= size()) __throw_index_out_of_range_exception(__FILE__, __LINE__, __func__);
  return data_->items[position];
}

template<typename type_t, typename allocator_t>
inline xtd::basic_array<type_t, allocator_t>::basic_array(const array<size_type, 1>& lengths) : data_ {xtd::new_ptr<struct data>()} {
  data_->items = base_type(std::accumulate(lengths.begin(), lengths.end(), size_type {0}));
  data_->lower_bound.clear();
  data_->upper_bound.clear();
  for (auto length : lengths) {
    data_->lower_bound.push_back(0);
    data_->upper_bound.push_back(length - 1);
  }
}

//template<>
template<typename type_t, typename allocator_t>
inline xtd::collections::object_model::read_only_collection<type_t> xtd::array<>::as_read_only(const xtd::array<type_t, 1, allocator_t>& array) {
  return xtd::collections::object_model::read_only_collection<type_t> {new_ptr<class xtd::array<type_t>>(array)};
}
/// @endcond
