/// @file
/// @brief Contains xtd::delegate::begin_invoke and xtd::delegate::end_invoke methods.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "delegate"
#include "threading/manual_reset_event"

/// ___________________________________________________________________________
///                                                                      void()

template<>
struct xtd::delegate<void()>::async_result_invoke::data {
  xtd::async_callback async_callback;
  xtd::threading::manual_reset_event async_event;
  std::any async_state;
  bool is_completed = false;
};

template<>
inline xtd::delegate<void()>::async_result_invoke::async_result_invoke(xtd::async_callback async_callback, std::any async_state) : data_(std::make_shared<data>()) {
  data_->async_callback = async_callback;
  data_->async_state = async_state;
}

template<>
inline std::any xtd::delegate<void()>::async_result_invoke::async_state() const noexcept {
  return data_->async_state;
}

template<>
inline xtd::threading::wait_handle& xtd::delegate<void()>::async_result_invoke::async_wait_handle() noexcept {
  return data_->async_event;
}

template<>
inline bool xtd::delegate<void()>::async_result_invoke::completed_synchronously() const noexcept {
  return false;
}

template<>
inline bool xtd::delegate<void()>::async_result_invoke::is_completed() const noexcept {
  return data_->is_completed;
}

template<>
inline std::shared_ptr<xtd::iasync_result> xtd::delegate<void()>::begin_invoke(xtd::async_callback async_callback, std::any async_state) {
  std::shared_ptr<async_result_invoke> async = std::make_shared<async_result_invoke>(async_callback, async_state);
  threading::thread_pool::queue_user_work_item([&, data = async->data_] {
    invoke();
    data->is_completed = true;
    data->async_event.set();
  });
  return async;
}

template<>
inline std::shared_ptr<xtd::iasync_result> xtd::delegate<void()>::begin_invoke() {
  return begin_invoke({}, *this);
}

template<>
inline void xtd::delegate<void()>::end_invoke(std::shared_ptr<iasync_result> async) {
  auto async_result = as<async_result_invoke>(async);
  async_result->data_->async_event.wait_one();
  async_result->data_->async_callback(async_result);
}

/// ___________________________________________________________________________
///                                                                  result_t()

template<typename result_t>
struct xtd::delegate<result_t()>::async_result_invoke::data {
  xtd::async_callback async_callback;
  xtd::threading::manual_reset_event async_event;
  std::any async_state;
  bool is_completed = false;
  result_t result;
};

template<typename result_t>
xtd::delegate<result_t()>::async_result_invoke::async_result_invoke(xtd::async_callback async_callback, std::any async_state) : data_(std::make_shared<data>()) {
  data_->async_callback = async_callback;
  data_->async_state = async_state;
}

template<typename result_t>
std::any xtd::delegate<result_t()>::async_result_invoke::async_state() const noexcept {
  return data_->async_state;
}

template<typename result_t>
xtd::threading::wait_handle& xtd::delegate<result_t()>::async_result_invoke::async_wait_handle() noexcept {
  return data_->async_event;
}

template<typename result_t>
bool xtd::delegate<result_t()>::async_result_invoke::completed_synchronously() const noexcept {
  return false;
}

template<typename result_t>
bool xtd::delegate<result_t()>::async_result_invoke::is_completed() const noexcept {
  return data_->is_completed;
}

template<typename result_t>
std::shared_ptr<xtd::iasync_result> xtd::delegate<result_t()>::begin_invoke(xtd::async_callback async_callback, std::any async_state) {
  std::shared_ptr<async_result_invoke> async = std::make_shared<async_result_invoke>(async_callback, async_state);
  threading::thread_pool::queue_user_work_item([&, data = async->data_] {
    data->result = invoke();
    data->is_completed = true;
    data->async_event->set();
  });
  return async;
}

template<typename result_t>
inline std::shared_ptr<xtd::iasync_result> xtd::delegate<result_t()>::begin_invoke() {
  return begin_invoke({}, *this);
}

template<typename result_t>
result_t xtd::delegate<result_t()>::end_invoke(std::shared_ptr<iasync_result> async) {
  auto async_result = as<async_result_invoke>(async);
  async_result->data_->async_event.wait_one();
  async_result->data_->async_callback(async_result);
  return async_result->data_->result;
}

/// ___________________________________________________________________________
///                                                        void(arguments_t...)

/*
template<typename... arguments_t>
struct xtd::delegate<void(arguments_t...)>::async_result_invoke::data {
   xtd::async_callback async_callback;
   xtd::threading::manual_reset_event async_event;
   std::any async_state;
   bool is_completed = false;
};

template<typename... arguments_t>
inline xtd::delegate<void(arguments_t...)>::async_result_invoke::async_result_invoke(std::any async_state) : data_(std::make_shared<data>()) {
  data_->async_state = async_state;
}

template<typename... arguments_t>
inline std::any xtd::delegate<void(arguments_t...)>::async_result_invoke::async_state() const noexcept {
  return data_->async_state;
}

template<typename... arguments_t>
inline xtd::threading::wait_handle& xtd::delegate<void(arguments_t...)>::async_result_invoke::async_wait_handle() noexcept {
  return data_->async_event;
}

template<typename... arguments_t>
inline bool xtd::delegate<void(arguments_t...)>::async_result_invoke::completed_synchronously() const noexcept {
  return false;
}

template<typename... arguments_t>
inline bool xtd::delegate<void(arguments_t...)>::async_result_invoke::is_completed() const noexcept {
  return data_->is_completed;
}

template<typename... arguments_t>
inline std::shared_ptr<xtd::iasync_result> xtd::delegate<void(arguments_t...)>::begin_invoke(arguments_t... arguments) {
  std::shared_ptr<async_result_invoke> async = std::make_shared<async_result_invoke>(*this);
  threading::thread_pool::queue_user_work_item([&, data = async->data_] {
    invoke(arguments...);
    data->is_completed = true;
    data->async_event->set();
  });
  return async;
}

template<typename... arguments_t>
inline void xtd::delegate<void(arguments_t...)>::end_invoke(std::shared_ptr<iasync_result> async) {
  auto async_result = as<async_result_invoke>(async);
  async_result->data_->async_event.wait_one();
  async_result->data_->async_callback(async_result);
}
 */

/// ___________________________________________________________________________
///                                                    result_t(arguments_t...)

template<typename result_t, typename... arguments_t>
struct xtd::delegate<result_t(arguments_t...)>::async_result_invoke::data {
  xtd::async_callback async_callback;
  xtd::threading::manual_reset_event async_event;
  std::any async_state;
  bool is_completed = false;
  result_t result;
};

template<typename result_t, typename... arguments_t>
xtd::delegate<result_t(arguments_t...)>::async_result_invoke::async_result_invoke(std::any async_state) : data_(std::make_shared<data>()) {
  data_->async_state = async_state;
}

template<typename result_t, typename... arguments_t>
std::any xtd::delegate<result_t(arguments_t...)>::async_result_invoke::async_state() const noexcept {
  return data_->async_state;
}

template<typename result_t, typename... arguments_t>
xtd::threading::wait_handle& xtd::delegate<result_t(arguments_t...)>::async_result_invoke::async_wait_handle() noexcept {
  return data_->async_event;
}

template<typename result_t, typename... arguments_t>
bool xtd::delegate<result_t(arguments_t...)>::async_result_invoke::completed_synchronously() const noexcept {
  return false;
}

template<typename result_t, typename... arguments_t>
bool xtd::delegate<result_t(arguments_t...)>::async_result_invoke::is_completed() const noexcept {
  return data_->is_completed;
}

template<typename result_t, typename... arguments_t>
std::shared_ptr<xtd::iasync_result> xtd::delegate<result_t(arguments_t...)>::begin_invoke(arguments_t... arguments) {
  std::shared_ptr<async_result_invoke> async = std::make_shared<async_result_invoke>(*this);
  threading::thread_pool::queue_user_work_item([&, data = async->data_] {
    invoke(arguments...);
    data->is_completed = true;
    data->async_event->set();
  });
  return async;
}

template<typename result_t, typename... arguments_t>
result_t xtd::delegate<result_t(arguments_t...)>::end_invoke(std::shared_ptr<iasync_result> async) {
  auto async_result = as<async_result_invoke>(async);
  async_result->data_->async_event.wait_one();
  async_result->data_->async_callback(async_result);
  return async_result->data_->result;
}
