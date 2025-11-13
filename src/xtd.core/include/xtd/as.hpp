/// @file
/// @brief Contains xtd::as method.
#pragma once
#include "any.hpp"
#include "invalid_cast_exception.hpp"
#include "reference_wrapper_object.hpp"
#include "shared_ptr_object.hpp"
#include "types.hpp"
#include <memory>
#define __XTD_CORE_INTERNAL__
#include "internal/__as_enum.hpp"
#include "internal/__as_generic.hpp"
#undef __XTD_CORE_INTERNAL__
#include "convert.hpp"
#define __XTD_CORE_INTERNAL__
#include "internal/__as_bool.hpp"
#include "internal/__as_byte.hpp"
#include "internal/__as_char.hpp"
#include "internal/__as_char8.hpp"
#include "internal/__as_char16.hpp"
#include "internal/__as_char32.hpp"
#include "internal/__as_decimal.hpp"
#include "internal/__as_double.hpp"
#include "internal/__as_float.hpp"
#include "internal/__as_int16.hpp"
#include "internal/__as_int32.hpp"
#include "internal/__as_int64.hpp"
#include "internal/__as_sbyte.hpp"
#include "internal/__as_slong.hpp"
#include "internal/__as_string.hpp"
#include "internal/__as_uint16.hpp"
#include "internal/__as_uint32.hpp"
#include "internal/__as_uint64.hpp"
#include "internal/__as_ulong.hpp"
#include "internal/__as_wchar.hpp"
#include "internal/__enumerable_collection.hpp"
#undef __XTD_CORE_INTERNAL__
#include "linq/enumerable.hpp"
#include "convert_pointer.hpp"
#define __XTD_CORE_INTERNAL__
#include "internal/__as_pointer.hpp"
#undef __XTD_CORE_INTERNAL__
#include "convert_string.hpp"
#define __XTD_CORE_INTERNAL__
#include "internal/__as_std_string.hpp"
#undef __XTD_CORE_INTERNAL__
#include "any_object.hpp"
#include "enum_object.hpp"
#define __XTD_CORE_INTERNAL__
#include "internal/__as_any_object.hpp"
#undef __XTD_CORE_INTERNAL__

/// @cond
template<class new_type_t, class current_type_t>
new_type_t* __convert_value__(current_type_t* value) {
  return xtd::as<new_type_t>(value);
}

template<class result_t, class source_t>
inline auto xtd::linq::enumerable::cast(const xtd::collections::generic::ienumerable<source_t>& source) noexcept {
  auto result = __opaque_xtd_linq_enumerable_collection__<result_t> {};
  result = __opaque_xtd_linq_enumerable_collection__<result_t> {};
  for (const auto& item : source)
    result.items.push_back(xtd::as<result_t>(item));
  return result;
}

template<class type_t>
template<typename target_t>
target_t xtd::reference_wrapper_object<type_t>::to_object() const {
  if (is_empty()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
  return xtd::as<target_t>(to_object());
}

template<class type_t>
template<typename target_t>
target_t xtd::reference_wrapper_object<type_t>::to_reference() const {
  if (is_empty()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
  return xtd::as<target_t>(to_reference());
}

template<class type_t>
template<typename target_t>
target_t xtd::shared_ptr_object<type_t>::to_object() const {
  if (to_pointer() == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
  return xtd::as<target_t>(to_object());
}

template<class type_t>
template<typename target_t>
target_t* xtd::shared_ptr_object<type_t>::to_pointer() const {
  if (to_pointer() == null) return null;
  return xtd::as<target_t>(to_pointer());
}

template<class type_t, class deleter_t>
template<typename target_t>
target_t xtd::unique_ptr_object<type_t, deleter_t>::to_object() const {
  if (to_pointer() == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
  return xtd::as<target_t>(to_object());
}

template<class type_t, class deleter_t>
template<typename target_t>
target_t* xtd::unique_ptr_object<type_t, deleter_t>::to_pointer() const {
  if (to_pointer() == null) return null;
  return xtd::as<target_t>(to_pointer());
}

template<class source_type_t, xtd::size source_rank, class source_allocator_t, class destination_type_t, xtd::size destination_rank, class destination_allocator_t>
inline void xtd::array<>::copy(const array<source_type_t, source_rank, source_allocator_t>& source_array, xtd::size source_index, const array<destination_type_t, destination_rank, destination_allocator_t>& destination_array, xtd::size destination_index, xtd::size length) {
  if (source_array.rank() != destination_array.rank()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::rank);
  for (auto r = xtd::size{}; r < source_array.rank(); ++r)
    if (source_array.get_length(r) != destination_array.get_length(r)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (source_index < source_array.get_lower_bound(0) || destination_index < destination_array.get_lower_bound(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (source_index + length > source_array.length() || destination_index + length > destination_array.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  
  for (auto i = xtd::size {}; i < length; ++i)
    destination_array.data_->items[destination_index + i] = as<destination_type_t>(source_array.data_->items[source_index + i]);
}

namespace std {
  template<class type_t>
  type_t any_cast(const xtd::any_object& value) {return xtd::as<type_t>(value);}
  template<class type_t>
  type_t any_cast(xtd::any_object& value) {return xtd::as<type_t>(value);}
}
/// @endcond
