/// @file
/// @brief Contains __polymorphic_equator__ struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.

#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../iequatable.hpp"
#include "../object.hpp"
#include <functional>
#include <type_traits>

/// @cond
template<typename type_t, typename bool_t>
struct __object_equtor__ {};

template<typename type_t>
struct __object_equtor__<type_t, std::true_type> {
  bool operator()(const type_t& a, const type_t& b) const {return static_cast<const xtd::object&>(a).equals(b);}
};

template<typename type_t>
struct __object_equtor__<type_t, std::false_type> {
  bool operator()(const type_t& a, const type_t& b) const {return std::equal_to<type_t> {}(a, b);}
};

template<typename type_t, typename bool_t>
struct __iequatable_equator__ {};

template<typename type_t>
struct __iequatable_equator__<type_t, std::true_type> {
  bool operator()(const type_t& a, const type_t& b) const {return static_cast<const xtd::iequatable<type_t>&>(a).equals(b);}
};

template<typename type_t>
struct __iequatable_equator__<type_t, std::false_type> {
  bool operator()(const type_t& a, const type_t& b) const {return __object_equtor__<type_t, typename std::is_base_of<xtd::object, type_t>::type> {}(a, b);}
};

template<class type_t, class bool_t>
struct __polymorphic_equator__ {};

template<class type_t>
struct __polymorphic_equator__<type_t, std::true_type> {
  bool operator()(const type_t& a, const type_t& b) const {return __iequatable_equator__<type_t, typename std::is_base_of<xtd::iequatable<type_t>, type_t>::type> {}(a, b);}
};

template<class type_t>
struct __polymorphic_equator__<type_t, std::false_type> {
  bool operator()(const type_t& a, const type_t& b) const {return std::equal_to<type_t> {}(a, b);}
};
/// @endcond
