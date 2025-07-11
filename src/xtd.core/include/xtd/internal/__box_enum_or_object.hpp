/// @file
/// @brief Contains __box_enum_or_object__ struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

/// @cond
template<class type_t, class bool_t>
struct __box_enum_or_object__;

template<class type_t>
struct __box_enum_or_object__<type_t, std::true_type> {
  using type = xtd::enum_object<type_t>;
};

template<class type_t>
struct __box_enum_or_object__<type_t, std::false_type> {
  using type = typename std::conditional<std::is_base_of<xtd::object, type_t>::value, type_t, xtd::box<type_t >>::type;
};
/// @endcond
