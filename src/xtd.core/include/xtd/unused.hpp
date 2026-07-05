/// @file
/// @brief Contains #__ and #unused_ keywords.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once

#if __cplusplus > 202302L
#  define __ = _
#else
struct [[maybe_unused]] __xtd_place_holder_variable_with_no_name_struct___ {};
#  ifdef __COUNTER__
#    define xtd_unique_id_ __COUNTER__
#  else
#    define xtd_unique_id_ __LINE__
#  endif
#  define __xtd_unused_concat_hidden__(a, b) a ## b
#  define __xtd_unused_concat_(a, b) __xtd_unused_concat_hidden__(a, b)
#  define unused_ \
__xtd_unused_concat_(__xtd_one_no_name__, xtd_unique_id_) = __xtd_place_holder_variable_with_no_name_struct___ {};\
[[maybe_unused]] auto __xtd_unused_concat_(__xtd_no_name__, xtd_unique_id_)
#  define __ unused_
#endif
