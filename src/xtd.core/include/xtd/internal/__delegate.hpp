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
inline result_t __xtd_delegate_any_cast(const xtd::any_object& value) {
  return value.has_value() ? xtd::as<result_t>(value) : result_t {};
}

template<>
inline void __xtd_delegate_any_cast<void>(const xtd::any_object& value) {
  return;
}

template<class result_t>
inline xtd::any_object __xtd_delegate_invoker(std::function<result_t()> invoke) {
  if constexpr (!std::is_void_v<result_t>) return xtd::any_object(invoke());
  else {
    invoke();
    return xtd::any_object {};
  }
}

template<typename function_t, typename... arguments_t>
inline xtd::any_object __xtd_delegate_invoker(function_t&& invoke, arguments_t&&... arguments) {
  if constexpr (!std::is_void_v<std::invoke_result_t<function_t, arguments_t...>>)
    return xtd::any_object(std::invoke(std::forward<function_t>(invoke), std::forward<arguments_t>(arguments)...));
  else {
    std::invoke(std::forward<function_t>(invoke), std::forward<arguments_t>(arguments)...);
    return xtd::any_object {};
  }
}

template<class result_t>
struct xtd::delegate<result_t()>::async_result_invoke::data {
  xtd::async_callback async_callback;
  xtd::threading::manual_reset_event async_event;
  xtd::any_object async_state;
  bool is_completed = false;
  xtd::any_object result;
};

template<class result_t>
xtd::delegate<result_t()>::async_result_invoke::async_result_invoke(xtd::async_callback async_callback, const xtd::any_object& async_state) : data_(xtd::new_sptr<data>()) {
  data_->async_callback = async_callback;
  data_->async_state = async_state;
}

template<class result_t>
xtd::any_object xtd::delegate<result_t()>::async_result_invoke::async_state() const noexcept {
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
  return begin_invoke(xtd::async_callback {}, xtd::any_object(*this));
}

template<class result_t>
inline xtd::async_result xtd::delegate<result_t()>::begin_invoke(xtd::async_callback async_callback) {
  return begin_invoke(async_callback, xtd::any_object(*this));
}

template<class result_t>
xtd::async_result xtd::delegate<result_t()>::begin_invoke(xtd::async_callback async_callback, const xtd::any_object& async_state) {
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
  xtd::any_object async_state;
  bool is_completed = false;
  xtd::any_object result;
};

template<class result_t, class ...arguments_t>
xtd::delegate<result_t(arguments_t...)>::async_result_invoke::async_result_invoke(xtd::async_callback async_callback, const xtd::any_object& async_state) : data_(xtd::new_sptr<data>()) {
  data_->async_callback = async_callback;
  data_->async_state = async_state;
}

template<class result_t, class ...arguments_t>
xtd::any_object xtd::delegate<result_t(arguments_t...)>::async_result_invoke::async_state() const noexcept {
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
xtd::async_result xtd::delegate<result_t(arguments_t...)>::begin_invoke(arguments_t&&... arguments) {
  return begin_invoke(xtd::async_callback {}, xtd::any_object(*this), std::forward<arguments_t>(arguments)...);
}

template<class result_t, class ...arguments_t>
xtd::async_result xtd::delegate<result_t(arguments_t...)>::begin_invoke(xtd::async_callback async_callback, arguments_t&&... arguments) {
  return begin_invoke(async_callback, xtd::any_object(*this), std::forward<arguments_t>(arguments)...);
}

template<typename result_t, typename... arguments_t>
struct xtd::delegate<result_t(arguments_t...)>::delegate_async_state {
  std::shared_ptr<async_result_invoke> async;
  std::tuple<std::decay_t<arguments_t>...> arguments;
  std::function<result_t(arguments_t...)> invoker;
  delegate* self;
  std::function<xtd::any_object(std::shared_ptr<delegate_async_state>)> start = [](std::shared_ptr<delegate_async_state> state) {
    return std::apply([state](auto&&... unpacked_args)->xtd::any_object {
      return __xtd_delegate_invoker(state->invoker, std::forward<decltype(unpacked_args)>(unpacked_args)...);
    }, state->arguments);
  };
};

template<class result_t, class ...arguments_t>
xtd::async_result xtd::delegate<result_t(arguments_t...)>::begin_invoke(xtd::async_callback async_callback, const xtd::any_object& async_state, arguments_t&&... arguments) {
  auto state = std::make_shared<delegate_async_state>();

  state->async = xtd::new_sptr<async_result_invoke>(async_callback, async_state);
  state->arguments = std::make_tuple(std::forward<arguments_t>(arguments)...);
  state->invoker = [state](arguments_t... args) {return state->self->invoke(std::forward<arguments_t>(args)...);};
  state->self = this;

  threading::thread_pool::queue_user_work_item([state] {
    state->async->data_->result = state->start(state);
    state->async->data_->is_completed = true;
    state->async->data_->async_event.set();
    state->async->data_->async_callback(state->async);
  });
  return state->async;
}

template<class result_t, class ...arguments_t>
result_t xtd::delegate<result_t(arguments_t...)>::end_invoke(async_result async) {
  auto async_result = as<async_result_invoke>(async);
  if (!async_result->data_->is_completed) async_result->data_->async_event.wait_one();
  return __xtd_delegate_any_cast<result_t>(async_result->data_->result);
}
/// @endcond
