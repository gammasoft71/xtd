/// @file
/// @brief Contains internal math methods.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../decimal.hpp"

/// @cond
[[nodiscard]] static constexpr auto __get_epsilon(xtd::decimal) noexcept -> xtd::decimal {return 0;}
[[nodiscard]] static constexpr auto __get_epsilon(double) noexcept -> double {return 4.94066e-324;}
[[nodiscard]] static constexpr auto __get_epsilon(float) noexcept -> float {return 1.401298E-45f;}
/// @endcond
