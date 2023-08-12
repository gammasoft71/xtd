#include "../../../include/xtd/threading/monitor.h"
#include "../../../include/xtd/threading/mutex.h"
#include "../../../include/xtd/threading/synchronization_lock_exception.h"
#include <optional>

#include "../../../include/xtd/diagnostics/debug.h"

using namespace xtd;
using namespace xtd::threading;

struct monitor::item {
  mutex event {false};
  int32 used_counter {0};
  std::optional<ustring> name;
};

void monitor::enter_ptr(intptr ptr) {
  bool lock_taken = false;
  enter_ptr(ptr, lock_taken);
}

void monitor::enter_ptr(intptr ptr, bool& lock_taken) {
  if (!try_enter_ptr(ptr, timeout::infinite, lock_taken))
    throw invalid_operation_exception(csf_);
}

void monitor::exit_ptr(intptr ptr) {
  monitor_mutex.wait_one();
  if (!is_entered_ptr(ptr)) {
    monitor_mutex.release_mutex();
    throw synchronization_lock_exception(csf_);
  }
  
  item saved;
  item* monitor_data = &items[ptr];
  if (--monitor_data->used_counter == 0) {
    saved = items[ptr];
    items.erase(ptr);
    monitor_data = &saved;
  }
  monitor_mutex.release_mutex();
  monitor_data->event.release_mutex();
}

intptr monitor::get_ustring_ptr(const ustring& str) noexcept {
  intptr ptr = reinterpret_cast<intptr>(&str);
  monitor_mutex.wait_one();
  for (const auto& item : items)
    if (item.second.name.has_value() && item.second.name.value().equals(str)) {
      ptr = item.first;
      break;
    }
  monitor_mutex.release_mutex();
  return ptr;
}

bool monitor::is_entered_ptr(intptr ptr) noexcept {
  return items.find(ptr) != items.end();
}

void monitor::pulse_ptr(intptr ptr) {
  item* monitor_item = null;
  monitor_mutex.wait_one();
  if (is_entered_ptr(ptr)) monitor_item = &items[ptr];
  monitor_mutex.release_mutex();
  
  if (monitor_item == nullptr) throw invalid_operation_exception(csf_);
  
  monitor_item->event.release_mutex();
}

void monitor::pulse_all_ptr(intptr ptr) {
  item* monitor_item = null;
  monitor_mutex.wait_one();
  if (is_entered_ptr(ptr)) monitor_item = &items[ptr];
  monitor_mutex.release_mutex();
  
  if (monitor_item == nullptr) throw invalid_operation_exception(csf_);
  
  monitor_item->event.release_mutex();
}

bool monitor::try_enter_ptr( intptr ptr, int32 milliseconds_timeout, bool& lock_taken) noexcept {
  if (milliseconds_timeout < timeout::infinite) return false;
  monitor_mutex.wait_one();
  if (!is_entered(ptr)) items.insert({ptr, item {}});
  item* monitor_data = &items[ptr];
  ++monitor_data->used_counter;
  monitor_mutex.release_mutex();
  return lock_taken = monitor_data->event.wait_one(milliseconds_timeout);
}

monitor::item_collection monitor::items;
mutex monitor::monitor_mutex;
