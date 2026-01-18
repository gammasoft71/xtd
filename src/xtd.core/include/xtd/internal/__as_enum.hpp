/// @file
/// @brief Contains xtd::as struct.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../convert_pointer.hpp"

/// @cond
template<class new_type_t, class current_type_t, class bool_t>
struct __as_enum__ {};

template<class new_type_t, class current_type_t>
struct __as_enum__<new_type_t, current_type_t, std::true_type> {
  [[nodiscard]] auto convert(const current_type_t& value) -> const new_type_t& {
    __result__ = static_cast<new_type_t>(value);
    return __result__;
  }
  [[nodiscard]] auto convert(current_type_t& value) -> new_type_t& {
    __result__ = static_cast<new_type_t>(value);
    return __result__;
  }
  thread_local inline static new_type_t __result__ {};
};

template<class new_type_t, class current_type_t>
struct __as_enum__<new_type_t, current_type_t, std::false_type> {
  [[nodiscard]] auto convert(const current_type_t& value) -> const new_type_t& {
    return xtd::convert_pointer::to_ref<new_type_t>(value);
  }
  [[nodiscard]] auto convert(current_type_t& value) -> new_type_t& {
    return xtd::convert_pointer::to_ref<new_type_t>(value);
  }
};
/// @endcond
