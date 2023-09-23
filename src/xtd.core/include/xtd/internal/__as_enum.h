/// @file
/// @brief Contains __as_enum__ struct.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../convert_pointer"

/// @cond
template<typename new_type_t, typename current_type_t, typename bool_t>
struct __as_enum__ {};

template<typename new_type_t, typename current_type_t>
struct __as_enum__<new_type_t, current_type_t, std::true_type> {
  const new_type_t& convert(const current_type_t& value) {
    __result__ = static_cast<new_type_t>(value);
    return __result__;
  }
  new_type_t& convert(current_type_t& value) {
    __result__ = static_cast<new_type_t>(value);
    return __result__;
  }
  thread_local inline static new_type_t __result__ {};
};

template<typename new_type_t, typename current_type_t>
struct __as_enum__<new_type_t, current_type_t, std::false_type> {
  const new_type_t& convert(const current_type_t& value) {
    return xtd::convert_pointer::to_ref<new_type_t>(value);
  }
  new_type_t& convert(current_type_t& value) {
    return xtd::convert_pointer::to_ref<new_type_t>(value);
  }
};
/// @endcond
