/// @file
/// @brief Contains __xtd_scope_cat__ and __xtd_scope_id__ helpers.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <exception>

/// @cond
#define __xtd_scope_cat__(name, line) name##line
#define __xtd_scope_id__(name, line) __xtd_scope_cat__(name, line)

template<class function_t>
struct __xtd_scope_exit_object__ {
  __xtd_scope_exit_object__(function_t&& f) : function(std::forward<function_t>(f)) {}
  ~__xtd_scope_exit_object__() { function(); }
  function_t function;
};

template<typename function_t>
struct __xtd_scope_fail_object__ {
  __xtd_scope_fail_object__(function_t&& f) : function(std::forward<function_t>(f)) {}
  ~__xtd_scope_fail_object__() noexcept {if (std::uncaught_exceptions() > exceptions_on_enter) function();}
  int exceptions_on_enter = std::uncaught_exceptions();
  function_t function;
};

template<typename function_t>
struct __xtd_scope_success_object__ {
  __xtd_scope_success_object__(function_t&& f) : function(std::forward<function_t>(f)) {}
  ~__xtd_scope_success_object__() noexcept {if (std::uncaught_exceptions() == exceptions_on_enter) function();}
  int exceptions_on_enter = std::uncaught_exceptions();
  function_t function;
};
/// @endcond
