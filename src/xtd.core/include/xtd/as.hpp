/// @file
/// @brief Contains xtd::as method.
#pragma once
#include "any.hpp"
#include "invalid_cast_exception.hpp"
#include "reference_wrapper_object.hpp"
#include "shared_ptr_object.hpp"
#include "types.hpp"
#include <memory>
#include <variant>
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
template<typename new_type, typename current_type>
[[nodiscard]] auto __convert_value__(current_type* value) -> new_type* {
  return xtd::as<new_type>(value);
}

template<typename result_t, xtd::forward_iterable source_t>
[[nodiscard]] inline auto xtd::linq::enumerable::cast(const source_t& source) -> xtd::collections::generic::enumerable_generator<result_t> {
  for (const auto& item : source)
    co_yield xtd::as<result_t>(item);
}

template<typename type_t>
template<typename target_t>
[[nodiscard]] auto xtd::reference_wrapper_object<type_t>::to_object() const -> target_t {
  if (is_empty()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
  return xtd::as<target_t>(to_object());
}

template<typename type_t>
template<typename target_t>
[[nodiscard]] auto xtd::reference_wrapper_object<type_t>::to_reference() const -> target_t {
  if (is_empty()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
  return xtd::as<target_t>(to_reference());
}

template<typename type_t>
template<typename target_t>
[[nodiscard]] auto xtd::shared_ptr_object<type_t>::to_object() const -> target_t {
  if (to_pointer() == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
  return xtd::as<target_t>(to_object());
}

template<typename type_t>
template<typename target_t>
[[nodiscard]] auto xtd::shared_ptr_object<type_t>::to_pointer() const -> target_t* {
  if (to_pointer() == null) return null;
  return xtd::as<target_t>(to_pointer());
}

template<typename type_t, typename deleter_t>
template<typename target_t>
[[nodiscard]] auto xtd::unique_ptr_object<type_t, deleter_t>::to_object() const -> target_t {
  if (to_pointer() == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
  return xtd::as<target_t>(to_object());
}

template<typename type_t, typename deleter_t>
template<typename target_t>
[[nodiscard]] auto xtd::unique_ptr_object<type_t, deleter_t>::to_pointer() const -> target_t* {
  if (to_pointer() == null) return null;
  return xtd::as<target_t>(to_pointer());
}

template<typename source_type_t, xtd::usize source_rank, typename source_allocator_t, typename destination_type_t, xtd::usize destination_rank, typename destination_allocator_t>
inline auto xtd::array<>::copy(const array<source_type_t, source_rank, source_allocator_t>& source_array, xtd::usize source_index, const array<destination_type_t, destination_rank, destination_allocator_t>& destination_array, xtd::usize destination_index, xtd::usize length) -> void {
  if (source_array.rank() != destination_array.rank()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::rank);
  for (auto r = xtd::usize {}; r < source_array.rank(); ++r)
    if (source_array.get_length(r) != destination_array.get_length(r)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (source_index < source_array.get_lower_bound(0) || destination_index < destination_array.get_lower_bound(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (source_index + length > source_array.length() || destination_index + length > destination_array.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  
  for (auto i = xtd::usize {}; i < length; ++i)
    destination_array.data_->items[destination_index + i] = as<destination_type_t>(source_array.data_->items[source_index + i]);
}

namespace xtd {
  template<typename type_t, typename ...args_t>
  [[nodiscard]] inline auto as(const std::variant<args_t...>& value) -> type_t {
    std::visit([&](auto&& arg) {if constexpr (!std::is_same_v<std::decay_t<decltype(arg)>, std::remove_cvref_t<type_t>>) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);}, value);
    return std::get<type_t>(value);
  }
  
  template<typename type_t, typename ...args_t>
  [[nodiscard]] inline auto as(std::variant<args_t...>& value) -> type_t {
    std::visit([&](auto&& arg) {if constexpr (!std::is_same_v<std::decay_t<decltype(arg)>, std::remove_cvref_t<type_t>>) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);}, value);
    return std::get<type_t>(value);
  }
}

namespace std {
  template<typename type_t>
  [[nodiscard]] auto any_cast(const xtd::any_object& value) -> type_t {return xtd::as<type_t>(value);}
  template<typename type_t>
  [[nodiscard]] auto any_cast(xtd::any_object& value) -> type_t {return xtd::as<type_t>(value);}
}
/// @endcond
