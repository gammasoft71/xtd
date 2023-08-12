/// @file
/// @brief Contains __lock_guard definition.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../threading/monitor.h"

/// @cond
struct core_export_ __lock_guard final {
public:
  __lock_guard() = delete;
  template<typename object_t>
  explicit __lock_guard(const object_t& lock) : lock_(xtd::threading::monitor::get_ptr(lock)) {xtd::threading::monitor::enter_ptr(lock_);}
  ~__lock_guard() {xtd::threading::monitor::exit_ptr(lock_);}

private:
  xtd::intptr lock_;
};
/// @endcond
