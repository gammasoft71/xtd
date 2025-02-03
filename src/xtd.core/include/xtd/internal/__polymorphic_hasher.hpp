/// @file
/// @brief Contains __polymorphic_hasher__ structs.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.

#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../object.hpp"
#include "../ihashable.hpp"
#include <functional>
#include <type_traits>

/// @cond
template<class key_t, class bool_t>
struct __polymorphic_hasher__ {};

template<class key_t>
struct __polymorphic_hasher__<key_t, std::true_type> {
  xtd::size operator()(const key_t& key) const {
    if (dynamic_cast<const xtd::iequatable<key_t>*>(&key)) return dynamic_cast<const xtd::ihashable&>(key).get_hash_code();
    if (dynamic_cast<const xtd::object*>(&key)) return dynamic_cast<const xtd::object&>(key).get_hash_code();
    __throw_argument_exception(__FILE__, __LINE__, __func__);
    return 0;
  }
};

template<class key_t>
struct __polymorphic_hasher__<key_t, std::false_type> {
  xtd::size operator()(const key_t& key) const {
    return std::hash<key_t> {}(key);
  }
};
/// @endcond
