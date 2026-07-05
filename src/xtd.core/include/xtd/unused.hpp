/// @file
/// @brief Contains #__ and #unused_ keywords.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <version>

/// @cond
//#if !defined(__cpp_placeholder_variables)
#if __cplusplus <= 202302L
#  ifdef __COUNTER__
#    define xtd_unique_id_ __COUNTER__
#  else
#    define xtd_unique_id_ __LINE__
#  endif
#  define __xtd_unused_concat_hidden__(a, b) a ## b
#  define __xtd_unused_concat_(a, b) __xtd_unused_concat_hidden__(a, b)
struct [[maybe_unused]] __xtd_place_holder_variable_with_no_name_struct___ {};
#endif
/// @endcond

//#if defined(__cpp_placeholder_variables)
#if __cplusplus > 202302L
/// @brief Represents placeholder variables with no name.
/// @par Header
/// ```cpp
/// #include <xtd/unused>
/// ```
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks Same as C++26 feature [_](https://cppreference.com/cpp/language/conflicting_declarations#Potentially-conflict_declarations) but for C++20 and later.
/// @par Examples
/// The following code shows how to use #unsued_ keyword.
/// @include keyword_
#  define unused_ = _
#else
/// @brief Represents placeholder variables with no name.
/// @par Header
/// ```cpp
/// #include <xtd/unused>
/// ```
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks Same as C++26 feature [_](https://cppreference.com/cpp/language/conflicting_declarations#Potentially-conflict_declarations) but for C++20 and later.
/// @par Examples
/// The following code shows how to use #unsued_ keyword.
/// @include keyword_
#  define unused_ \
     __xtd_unused_concat_(__xtd_one_no_name__, xtd_unique_id_) = __xtd_place_holder_variable_with_no_name_struct___ {};\
    [[maybe_unused]] auto __xtd_unused_concat_(__xtd_no_name__, xtd_unique_id_)
#endif

/// @brief Represents placeholder variables with no name.
/// @par Header
/// ```cpp
/// #include <xtd/unused>
/// ```
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks Same as C++26 feature [_](https://cppreference.com/cpp/language/conflicting_declarations#Potentially-conflict_declarations) but for C++20 and later.
/// @par Examples
/// The following code shows how to use #__ keyword.
/// @include keyword_
#define __ unused_
