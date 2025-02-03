/// @file
/// @brief Contains __polymorphic_lesser__ struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.

#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../icomparable.hpp"
#include <functional>
#include <type_traits>

/// @cond
template<class type_t, class bool_t>
struct __polymorphic_lesser__ {};

template<class type_t>
struct __polymorphic_lesser__<type_t, std::true_type> {
  bool operator()(const type_t& lhs, const type_t& rhs) const {
    if (dynamic_cast<const xtd::icomparable<type_t>*>(&lhs)) return dynamic_cast<const xtd::icomparable<type_t>&>(lhs).compare_to(rhs) < 0;
    return std::less<type_t> {}(lhs, rhs);
  }
};

template<class type_t>
struct __polymorphic_lesser__<type_t, std::false_type> {
  bool operator()(const type_t& lhs, const type_t& rhs) const {return std::less<type_t> {}(lhs, rhs);}
};
/// @endcond
