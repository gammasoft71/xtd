#include "../../../include/xtd/threading/monitor.h"
#include "../../../include/xtd/threading/interlocked.h"
#include "../../../include/xtd/threading/mutex.h"
#include "../../../include/xtd/threading/thread.h"
#include "../../../include/xtd/threading/synchronization_lock_exception.h"
#include <mutex>
#include <optional>

using namespace xtd;
using namespace xtd::threading;

struct monitor::item {
  mutex event {false};
  int32 used_counter {0};
  std::optional<ustring> name;
};

struct monitor::static_data {
  std::recursive_mutex monitor_mutex;
  monitor::item_collection items;
};

thread_local monitor::item* monitor::current_locked_object = nullptr;

void monitor::enter_ptr(std::pair<intptr, bool> pair) {
  bool lock_taken = false;
  enter_ptr(pair, lock_taken);
}

void monitor::enter_ptr(std::pair<intptr, bool> pair, bool& lock_taken) {
  if (!try_enter_ptr(pair, timeout::infinite, lock_taken))
    throw invalid_operation_exception(csf_);
}

void monitor::exit_ptr(std::pair<intptr, bool> pair) {
  get_static_data().monitor_mutex.lock();
  if (!is_entered_ptr(pair)) {
    get_static_data().monitor_mutex.unlock();
    throw synchronization_lock_exception(csf_);
  }
  
  item saved;
  item* monitor_data = &get_static_data().items[pair.first];
  if (interlocked::decrement(monitor_data->used_counter) == 0) {
    saved = get_static_data().items[pair.first];
    if (pair.second) delete reinterpret_cast<const ustring*>(pair.first);
    get_static_data().items.erase(pair.first);
    monitor_data = &saved;
  }
  current_locked_object = nullptr;
  monitor_data->event.release_mutex();
  get_static_data().monitor_mutex.unlock();
}

intptr monitor::get_ustring_ptr(const ustring& str) {
  if (str.empty()) throw argument_exception {csf_};
  get_static_data().monitor_mutex.lock();
  intptr ptr = reinterpret_cast<intptr>(&str);
  for (const auto& item : get_static_data().items)
    if (item.second.name.has_value() && item.second.name.value() == str) {
      ptr = item.first;
      delete &str;
      break;
    }
  get_static_data().monitor_mutex.unlock();
  return ptr;
}

bool monitor::is_entered_ptr(std::pair<intptr, bool> pair) noexcept {
  auto found = get_static_data().items.find(pair.first) != get_static_data().items.end();
  return found;
}

void monitor::pulse_ptr(std::pair<intptr, bool> pair) {
  item* monitor_item = null;
  get_static_data().monitor_mutex.lock();
  if (is_entered_ptr(pair)) monitor_item = &get_static_data().items[pair.first];
  get_static_data().monitor_mutex.unlock();
  
  if (monitor_item == nullptr) throw invalid_operation_exception(csf_);
  
  monitor_item->event.release_mutex();
}

void monitor::pulse_all_ptr(std::pair<intptr, bool> pair) {
  while (is_entered_ptr(pair))
    pulse_ptr(pair);
}

bool monitor::try_enter_ptr(std::pair<intptr, bool> pair, int32 milliseconds_timeout, bool& lock_taken) noexcept {
  if (milliseconds_timeout < timeout::infinite) return false;
  get_static_data().monitor_mutex.lock();
  if (!is_entered_ptr(pair)) {
    auto i = item {};
    if (pair.second) {
      auto str = reinterpret_cast<const ustring*>(pair.first);
      i.name = *str;
    }
    get_static_data().items.insert({pair.first, i});
  }
  item* monitor_data = &get_static_data().items[pair.first];
  interlocked::increment(monitor_data->used_counter);
  get_static_data().monitor_mutex.unlock();
  current_locked_object = monitor_data;
  return lock_taken = monitor_data->event.wait_one(milliseconds_timeout);
}

monitor::static_data& monitor::get_static_data() {
  static static_data data;
  return data;
}
