/// @file
/// @brief Contains xtd::delegate::begin_invoke and xtd::delegate::end_invoke methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../threading/manual_reset_event.hpp"
#include "../delegate.hpp"

/// @cond
template<class result_t = void>
inline result_t __xtd_delegate_any_cast(std::any value) {
  return value.has_value() ? std::any_cast<result_t>(value) : result_t {};
}

template<>
inline void __xtd_delegate_any_cast<void>(std::any value) {
  return;
}

inline std::any __xtd_delegate_invoker(std::function<void()> invoke) {
  invoke();
  return std::any {};
}

template<class ...arguments_t>
inline std::any __xtd_delegate_invoker(std::function<void(arguments_t...)> invoke, arguments_t... arguments) {
  invoke(arguments...);
  return std::any {};
}

template<class result_t>
inline std::any __xtd_delegate_invoker(std::function<result_t()> invoke) {
  return std::make_any<result_t>(invoke());
}

template<class result_t, class ...arguments_t>
inline std::any __xtd_delegate_invoker(std::function<result_t(arguments_t...)> invoke, arguments_t... arguments) {
  return std::make_any<result_t>(invoke(arguments...));
}

template<class result_t>
struct xtd::delegate<result_t()>::async_result_invoke::data {
  xtd::async_callback async_callback;
  xtd::threading::manual_reset_event async_event;
  std::any async_state;
  bool is_completed = false;
  std::any result;
};

template<class result_t>
xtd::delegate<result_t()>::async_result_invoke::async_result_invoke(xtd::async_callback async_callback, std::any async_state) : data_(xtd::new_sptr<data>()) {
  data_->async_callback = async_callback;
  data_->async_state = async_state;
}

template<class result_t>
std::any xtd::delegate<result_t()>::async_result_invoke::async_state() const noexcept {
  return data_->async_state;
}

template<class result_t>
xtd::threading::wait_handle& xtd::delegate<result_t()>::async_result_invoke::async_wait_handle() noexcept {
  return data_->async_event;
}

template<class result_t>
bool xtd::delegate<result_t()>::async_result_invoke::completed_synchronously() const noexcept {
  return false;
}

template<class result_t>
bool xtd::delegate<result_t()>::async_result_invoke::is_completed() const noexcept {
  return data_->is_completed;
}

template<class result_t>
inline xtd::async_result xtd::delegate<result_t()>::begin_invoke() {
  return begin_invoke(xtd::async_callback {}, *this);
}

template<class result_t>
inline xtd::async_result xtd::delegate<result_t()>::begin_invoke(xtd::async_callback async_callback) {
  return begin_invoke(async_callback, *this);
}

template<class result_t>
xtd::async_result xtd::delegate<result_t()>::begin_invoke(xtd::async_callback async_callback, std::any async_state) {
  auto async = xtd::new_sptr<async_result_invoke>(async_callback, async_state);
  threading::thread_pool::queue_user_work_item([&, async = async] {
    async->data_->result = __xtd_delegate_invoker(function_t {std::bind(&xtd::delegate<result_t()>::invoke, this)});
    async->data_->is_completed = true;
    async->data_->async_event.set();
    async->data_->async_callback(async);
  });
  return async;
}

template<class result_t>
result_t xtd::delegate<result_t()>::end_invoke(async_result async) {
  auto async_result = as<async_result_invoke>(async);
  async_result->data_->async_event.wait_one();
  return __xtd_delegate_any_cast<result_t>(async_result->data_->result);
}

template<class result_t, class ...arguments_t>
struct xtd::delegate<result_t(arguments_t...)>::async_result_invoke::data {
  xtd::async_callback async_callback;
  xtd::threading::manual_reset_event async_event;
  std::any async_state;
  bool is_completed = false;
  std::any result;
};

template<class result_t, class ...arguments_t>
xtd::delegate<result_t(arguments_t...)>::async_result_invoke::async_result_invoke(xtd::async_callback async_callback, std::any async_state) : data_(xtd::new_sptr<data>()) {
  data_->async_callback = async_callback;
  data_->async_state = async_state;
}

template<class result_t, class ...arguments_t>
std::any xtd::delegate<result_t(arguments_t...)>::async_result_invoke::async_state() const noexcept {
  return data_->async_state;
}

template<class result_t, class ...arguments_t>
xtd::threading::wait_handle& xtd::delegate<result_t(arguments_t...)>::async_result_invoke::async_wait_handle() noexcept {
  return data_->async_event;
}

template<class result_t, class ...arguments_t>
bool xtd::delegate<result_t(arguments_t...)>::async_result_invoke::completed_synchronously() const noexcept {
  return false;
}

template<class result_t, class ...arguments_t>
bool xtd::delegate<result_t(arguments_t...)>::async_result_invoke::is_completed() const noexcept {
  return data_->is_completed;
}

template<class result_t, class ...arguments_t>
xtd::async_result xtd::delegate<result_t(arguments_t...)>::begin_invoke(arguments_t... arguments) {
  return begin_invoke(xtd::async_callback {}, *this, arguments...);
}

template<class result_t, class ...arguments_t>
xtd::async_result xtd::delegate<result_t(arguments_t...)>::begin_invoke(xtd::async_callback async_callback, arguments_t... arguments) {
  return begin_invoke(async_callback, *this, arguments...);
}

template<class result_t, class ...arguments_t>
xtd::async_result xtd::delegate<result_t(arguments_t...)>::begin_invoke(xtd::async_callback async_callback, std::any async_state, arguments_t... arguments) {
  auto async = xtd::new_sptr<async_result_invoke>(async_callback, async_state);
  threading::thread_pool::queue_user_work_item([&, async = async, ...arguments = arguments] {
    async->data_->result = __xtd_delegate_invoker(function_t {std::bind(&xtd::delegate<result_t(arguments_t...)>::invoke, this, arguments...)}, arguments...);
    async->data_->is_completed = true;
    async->data_->async_event.set();
    async->data_->async_callback(async);
  });
  return async;
}

template<class result_t, class ...arguments_t>
result_t xtd::delegate<result_t(arguments_t...)>::end_invoke(async_result async) {
  auto async_result = as<async_result_invoke>(async);
  if (!async_result->data_->is_completed) async_result->data_->async_event.wait_one();
  return __xtd_delegate_any_cast<result_t>(async_result->data_->result);
}
/// @endcond
