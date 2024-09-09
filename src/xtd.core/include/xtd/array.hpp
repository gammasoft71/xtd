/// @file
/// @brief Contains xtd::array class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once

#if !defined(__XTD_ARRAY_INTERNAL__)
#error "Do not include this file: Internal use only. Include <basic_string> or <basic_string.h> instead."
#endif

template<typename type_t, typename allocator_t>
inline const type_t& xtd::basic_array<type_t, allocator_t>::get_value(const xtd::array<xtd::size>& indexes) const {
  return operator()(indexes);
}

template<typename type_t, typename allocator_t>
inline type_t& xtd::basic_array<type_t, allocator_t>::operator()(const xtd::array<xtd::size>& indexes) {
  auto position = xtd::size {0};
  for (auto index1 = xtd::size {0}; index1 < indexes.size(); ++index1) {
    if (indexes[index1] > get_length(index1)) __throw_index_out_of_range_exception(__FILE__, __LINE__, __func__);
    auto multiplicand = xtd::size {1};
    for (auto index2 = index1 + 1; index2 < indexes.size(); ++index2)
      multiplicand *= get_length(index2);
    position += indexes[index1] * multiplicand;
  }
  return data_->items[position];
}

template<typename type_t, typename allocator_t>
inline const type_t& xtd::basic_array<type_t, allocator_t>::operator()(const xtd::array<xtd::size>& indexes) const {
  auto position = xtd::size {0};
  for (auto index1 = xtd::size {0}; index1 < indexes.size(); ++index1) {
    if (indexes[index1] > get_length(index1)) __throw_index_out_of_range_exception(__FILE__, __LINE__, __func__);
    auto multiplicand = xtd::size {1};
    for (auto index2 = index1 + 1; index2 < indexes.size(); ++index2)
      multiplicand *= get_length(index2);
    position += indexes[index1] * multiplicand;
  }
  return data_->items[position];
}
