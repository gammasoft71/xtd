/// @file
/// @brief Contains __polymorphic_comparer__ struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.

#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../icomparable.hpp"
#include "../int32.hpp"
#include <functional>
#include <type_traits>

/// @cond

template<typename type_t, typename bool_t>
struct __icomparable_comparer__ {};

template<typename type_t>
struct __icomparable_comparer__<type_t, std::true_type> {
  xtd::int32 operator()(const type_t& x, const type_t& y) const {return static_cast<const xtd::icomparable<type_t>&>(x).compare_to(y);}
};

template<typename type_t>
struct __icomparable_comparer__<type_t, std::false_type> {
  xtd::int32 operator()(const type_t& x, const type_t& y) const {return x < y ? -1 : (x > y ? 1 : 0);}
};

template<class type_t, class bool_t>
struct __polymorphic_comparer__ {};

template<class type_t>
struct __polymorphic_comparer__<type_t, std::true_type> {
  xtd::int32 operator()(const type_t& x, const type_t& y) const {return __icomparable_comparer__<type_t, typename std::is_base_of<xtd::icomparable<type_t>, type_t>::type> {}(x, y);}
};

template<class type_t>
struct __polymorphic_comparer__<type_t, std::false_type> {
  xtd::int32 operator()(const type_t& x, const type_t& y) const {return x < y ? -1 : (x > y ? 1 : 0);}
};
/// @endcond
