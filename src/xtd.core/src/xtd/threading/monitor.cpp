#include "../../../include/xtd/threading/monitor.h"
#include "../../../include/xtd/threading/mutex.h"
#include "../../../include/xtd/threading/synchronization_lock_exception.h"
#include <mutex>
#include <optional>

using namespace xtd;
using namespace xtd::threading;

// The declaration __monitor_mutex__ mutex is in the thread_pool.cpp file (just before monitor::items_, thread::threads_, thread_pool::asynchronous_io_threads_ and thread_pool::threads_)
// to ensure allocation and deallocation order.
extern std::recursive_mutex __monitor_mutex__;

// The declaration items_ collection is in the thread_pool.cpp file (just before thread::threads_, thread_pool::asynchronous_io_threads_ and thread_pool::threads_)
// to ensure allocation and deallocation order.
//monitor::item_collection monitor::items_;

void monitor::enter_ptr(std::pair<intptr, bool> pair) {
  bool lock_taken = false;
  enter_ptr(pair, lock_taken);
}

void monitor::enter_ptr(std::pair<intptr, bool> pair, bool& lock_taken) {
  if (!try_enter_ptr(pair, timeout::infinite, lock_taken))
    throw invalid_operation_exception(csf_);
}

void monitor::exit_ptr(std::pair<intptr, bool> pair) {
  __monitor_mutex__.lock();
  if (!is_entered_ptr(pair)) {
    __monitor_mutex__.unlock();
    throw synchronization_lock_exception(csf_);
  }
  
  item saved;
  item* monitor_data = &items_[pair.first];
  if (--monitor_data->used_counter == 0) {
    saved = items_[pair.first];
    if (pair.second) delete reinterpret_cast<const ustring*>(pair.first);
    items_.erase(pair.first);
    monitor_data = &saved;
  }
  monitor_data->event.release_mutex();
  __monitor_mutex__.unlock();
}

intptr monitor::get_ustring_ptr(const ustring& str) {
  if (str.empty()) throw argument_exception {csf_};
  __monitor_mutex__.lock();
  intptr ptr = reinterpret_cast<intptr>(&str);
  for (const auto& item : items_)
    if (item.second.name.has_value() && item.second.name.value() == str) {
      ptr = item.first;
      delete &str;
      break;
    }
  __monitor_mutex__.unlock();
  return ptr;
}

bool monitor::is_entered_ptr(std::pair<intptr, bool> pair) noexcept {
  auto found = items_.find(pair.first) != items_.end();
  return found;
}

void monitor::pulse_ptr(std::pair<intptr, bool> pair) {
  item* monitor_item = null;
  __monitor_mutex__.lock();
  if (is_entered_ptr(pair)) monitor_item = &items_[pair.first];
  __monitor_mutex__.unlock();
  
  if (monitor_item == nullptr) throw invalid_operation_exception(csf_);
  
  monitor_item->event.release_mutex();
}

void monitor::pulse_all_ptr(std::pair<intptr, bool> pair) {
  item* monitor_item = null;
  __monitor_mutex__.lock();
  if (is_entered_ptr(pair)) monitor_item = &items_[pair.first];
  __monitor_mutex__.unlock();
  
  if (monitor_item == nullptr) throw invalid_operation_exception(csf_);
  
  monitor_item->event.release_mutex();
}

bool monitor::try_enter_ptr(std::pair<intptr, bool> pair, int32 milliseconds_timeout, bool& lock_taken) noexcept {
  if (milliseconds_timeout < timeout::infinite) return false;
  __monitor_mutex__.lock();
  if (!is_entered_ptr(pair)) {
    auto i = item {};
    if (pair.second) {
      auto str = reinterpret_cast<const ustring*>(pair.first);
      i.name = *str;
    }
    items_.insert({pair.first, i});
  }
  item* monitor_data = &items_[pair.first];
  ++monitor_data->used_counter;
  __monitor_mutex__.unlock();
  return lock_taken = monitor_data->event.wait_one(milliseconds_timeout);
}
