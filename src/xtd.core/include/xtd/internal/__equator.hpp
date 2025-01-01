/// @file
/// @brief Contains __object_equator__ and __polymorphic_equator__ structs.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.

#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../object"
#include <functional>
#include <type_traits>

/// @cond
template<typename key_t, typename bool_t>
struct __object_equator__ {};

template<typename key_t>
struct __object_equator__<key_t, std::true_type> {
  bool operator()(const key_t& a, const key_t& b) const {return xtd::object::equals(a, b);}
};

template<typename key_t>
struct __object_equator__<key_t, std::false_type> {
  bool operator()(const key_t& a, const key_t& b) const {return std::equal_to<key_t> {}(a, b);}
};

template<typename key_t, typename bool_t>
struct __polymorphic_equator__ {};

template<typename key_t>
struct __polymorphic_equator__<key_t, std::true_type> {
  bool operator()(const key_t& a, const key_t& b) const {return __object_equator__<key_t, typename std::is_base_of<xtd::object, key_t>::type> {}(a, b);}
};

template<typename key_t>
struct __polymorphic_equator__<key_t, std::false_type> {
  bool operator()(const key_t& a, const key_t& b) const {return std::equal_to<key_t> {}(a, b);}
};
/// @endcond
