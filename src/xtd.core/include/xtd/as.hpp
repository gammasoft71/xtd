/// @file
/// @brief Contains xtd::as method.
#pragma once
#include "any.hpp"
#include "invalid_cast_exception.hpp"
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
#undef __XTD_CORE_INTERNAL__
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
#include "linq/enumerable.hpp"
#define __XTD_CORE_INTERNAL__
#include "internal/__enumerable_collection.hpp"
#undef __XTD_CORE_INTERNAL__

/// @cond
template<class new_type_t, class current_type_t>
new_type_t* __convert_value__(current_type_t* value) {
  return xtd::as<new_type_t>(value);
}

template<class result_t, class source_t>
inline const xtd::collections::generic::ienumerable<result_t>& xtd::linq::enumerable::cast(const xtd::collections::generic::ienumerable<source_t>& source) noexcept {
  static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<result_t> {};
  result = __opaque_xtd_linq_enumerable_collection__<result_t> {};
  for (const auto& item : source)
    result.items.push_back(xtd::as<result_t>(item));
  return static_cast<const xtd::collections::generic::ienumerable<result_t>&>(result);
}

namespace std {
  template<class type_t>
  type_t any_cast(const xtd::any_object& value) {return xtd::as<type_t>(value);}
  template<class type_t>
  type_t any_cast(xtd::any_object& value) {return xtd::as<type_t>(value);}
}
/// @endcond
