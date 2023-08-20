#include "../../../include/xtd/threading/monitor.h"
#include "../../../include/xtd/threading/mutex.h"
#include "../../../include/xtd/threading/synchronization_lock_exception.h"
#include <mutex>
#include <optional>

using namespace xtd;
using namespace xtd::threading;

namespace {
  std::recursive_mutex& monitor_mutex() {
    static auto monitor_mutex = std::recursive_mutex {};
    return monitor_mutex;
  }
}

struct monitor::item {
  mutex event {false};
  int32 used_counter {0};
  std::optional<ustring> name;
};

void monitor::enter_ptr(std::pair<intptr, bool> pair) {
  bool lock_taken = false;
  enter_ptr(pair, lock_taken);
}

void monitor::enter_ptr(std::pair<intptr, bool> pair, bool& lock_taken) {
  if (!try_enter_ptr(pair, timeout::infinite, lock_taken))
    throw invalid_operation_exception(csf_);
}

void monitor::exit_ptr(std::pair<intptr, bool> pair) {
  monitor_mutex().lock();
  if (!is_entered_ptr(pair)) {
    monitor_mutex().unlock();
    throw synchronization_lock_exception(csf_);
  }
  
  item saved;
  item* monitor_data = &items()[pair.first];
  if (--monitor_data->used_counter == 0) {
    saved = items()[pair.first];
    if (pair.second) delete reinterpret_cast<const ustring*>(pair.first);
    items().erase(pair.first);
    monitor_data = &saved;
  }
  monitor_mutex().unlock();
  monitor_data->event.release_mutex();
}

intptr monitor::get_ustring_ptr(const ustring& str) {
  if (str.empty()) throw argument_exception {csf_};
  intptr ptr = reinterpret_cast<intptr>(&str);
  monitor_mutex().lock();
  auto items = monitor::items();
  for (const auto& item : items)
    if (item.second.name.has_value() && item.second.name.value() == str) {
      ptr = item.first;
      delete &str;
      break;
    }
  monitor_mutex().unlock();
  return ptr;
}

bool monitor::is_entered_ptr(std::pair<intptr, bool> pair) noexcept {
  auto found = items().find(pair.first) != items().end();
  return found;
}

void monitor::pulse_ptr(std::pair<intptr, bool> pair) {
  item* monitor_item = null;
  monitor_mutex().lock();
  if (is_entered_ptr(pair)) monitor_item = &items()[pair.first];
  monitor_mutex().unlock();
  
  if (monitor_item == nullptr) throw invalid_operation_exception(csf_);
  
  monitor_item->event.release_mutex();
}

void monitor::pulse_all_ptr(std::pair<intptr, bool> pair) {
  item* monitor_item = null;
  monitor_mutex().lock();
  if (is_entered_ptr(pair)) monitor_item = &items()[pair.first];
  monitor_mutex().unlock();
  
  if (monitor_item == nullptr) throw invalid_operation_exception(csf_);
  
  monitor_item->event.release_mutex();
}

bool monitor::try_enter_ptr(std::pair<intptr, bool> pair, int32 milliseconds_timeout, bool& lock_taken) noexcept {
  if (milliseconds_timeout < timeout::infinite) return false;
  monitor_mutex().lock();
  if (!is_entered_ptr(pair)) {
    auto i = item {};
    if (pair.second) {
      auto str = reinterpret_cast<const ustring*>(pair.first);
      i.name = *str;
    }
    items().insert({pair.first, i});
  }
  item* monitor_data = &items()[pair.first];
  ++monitor_data->used_counter;
  monitor_mutex().unlock();
  return lock_taken = monitor_data->event.wait_one(milliseconds_timeout);
}

monitor::item_collection& monitor::items() {
  static item_collection items;
  return items;
}
