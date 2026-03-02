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
template<class new_type, class current_type, class bool_t>
struct __as_enum__ {};

template<class new_type, class current_type>
struct __as_enum__<new_type, current_type, std::true_type> {
  [[nodiscard]] auto convert(const current_type& value) -> const new_type& {
    __result__ = static_cast<new_type>(value);
    return __result__;
  }
  [[nodiscard]] auto convert(current_type& value) -> new_type& {
    __result__ = static_cast<new_type>(value);
    return __result__;
  }
  thread_local inline static new_type __result__ {};
};

template<class new_type, class current_type>
struct __as_enum__<new_type, current_type, std::false_type> {
  [[nodiscard]] auto convert(const current_type& value) -> const new_type& {
    return xtd::convert_pointer::to_ref<new_type>(value);
  }
  [[nodiscard]] auto convert(current_type& value) -> new_type& {
    return xtd::convert_pointer::to_ref<new_type>(value);
  }
};
/// @endcond
