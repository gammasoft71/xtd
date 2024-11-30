/// @file
/// @brief Contains __object_hasher__ and __polymorphic_hasher__ structs.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.

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
struct __object_hasher__ {};

template<typename key_t>
struct __object_hasher__<key_t, std::true_type> {
  size_t operator()(const key_t& key) const {return static_cast<const xtd::object&>(key).get_hash_code();}
};

template<typename key_t>
struct __object_hasher__<key_t, std::false_type> {
  size_t operator()(const key_t& key) const {return std::hash<key_t> {}(key);}
};

template<typename key_t, typename bool_t>
struct __polymorphic_hasher__ {};

template<typename key_t>
struct __polymorphic_hasher__<key_t, std::true_type> {
  size_t operator()(const key_t& key) const {return __object_hasher__<key_t, typename std::is_base_of<xtd::object, key_t>::type> {}(key);}
};

template<typename key_t>
struct __polymorphic_hasher__<key_t, std::false_type> {
  size_t operator()(const key_t& key) const {return std::hash<key_t> {}(key);}
};
/// @endcond
