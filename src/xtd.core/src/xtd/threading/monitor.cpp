#include "critical_section.hpp"
#include "condition_variable.hpp"
#include "../../../include/xtd/threading/monitor.hpp"
#include "../../../include/xtd/threading/mutex.hpp"
#include "../../../include/xtd/threading/synchronization_lock_exception.hpp"
#include "../../../include/xtd/threading/thread.hpp"
#include "../../../include/xtd/threading/thread_local_object.hpp"
#include "../../../include/xtd/diagnostics/stopwatch.hpp"
#include "../../../include/xtd/not_implemented_exception.hpp"
#include "../../../include/xtd/optional.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/condition_variable>
#include <xtd/native/critical_section>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <atomic>
#include <mutex>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::helpers;
using namespace xtd::threading;

struct monitor::item {
  monitor::critical_section critical_section;
  xtd::sptr<std::atomic<int32>> used_count = xtd::new_sptr<std::atomic<int32>>(0);
  std::optional<string> name;
  thread_local_object<intptr> thread_id {[] {return thread::invalid_thread_id;}};
  monitor::condition_variable condition_variable;
};

struct monitor::static_data {
  critical_section monitor_items_critical_section;
  monitor::item_collection monitor_items;
};

void monitor::enter_ptr(object_ptr obj) {
  auto lock_taken = false;
  enter_ptr(obj, lock_taken);
}

void monitor::enter_ptr(object_ptr obj, bool& lock_taken) {
  if (!try_enter_ptr(obj, timeout::infinite, lock_taken))
    throw_helper::throws(exception_case::invalid_operation);
}

void monitor::exit_ptr(object_ptr obj) {
  get_static_data().monitor_items_critical_section.enter();
  if (!is_entered_ptr(obj)) {
    get_static_data().monitor_items_critical_section.leave();
    throw_helper::throws(exception_case::synchronization_lock);
  }
  
  item saved;
  item* monitor_data = &get_static_data().monitor_items[obj.first];
  if (--(*monitor_data->used_count) == 0) {
    saved = get_static_data().monitor_items[obj.first];
    if (obj.second) delete reinterpret_cast<const string*>(obj.first);
    get_static_data().monitor_items.erase(obj.first);
    monitor_data = &saved;
  }
  monitor_data->thread_id.value(thread::invalid_thread_id);
  monitor_data->critical_section.leave();
  get_static_data().monitor_items_critical_section.leave();
}

intptr monitor::get_string_ptr(const string& str) {
  if (str.empty()) throw_helper::throws(exception_case::argument);
  get_static_data().monitor_items_critical_section.enter();
  auto ptr = reinterpret_cast<intptr>(&str);
  for (const auto& item : get_static_data().monitor_items)
    if (item.second.name.has_value() && item.second.name.value() == str) {
      ptr = item.first;
      delete &str;
      break;
    }
  get_static_data().monitor_items_critical_section.leave();
  return ptr;
}

bool monitor::is_entered_ptr(object_ptr obj) noexcept {
  auto found = get_static_data().monitor_items.find(obj.first) != get_static_data().monitor_items.end();
  return found;
}

void monitor::pulse_ptr(object_ptr obj) {
  item* monitor_item = nullptr;
  get_static_data().monitor_items_critical_section.enter();
  if (is_entered_ptr(obj)) monitor_item = &get_static_data().monitor_items[obj.first];
  get_static_data().monitor_items_critical_section.leave();
  
  if (monitor_item == nullptr) throw_helper::throws(exception_case::invalid_operation);
  if (monitor_item->thread_id.value() != thread::current_thread().thread_id()) throw_helper::throws(exception_case::synchronization_lock);

  monitor_item->condition_variable.pulse();
}

void monitor::pulse_all_ptr(object_ptr obj) {
  item* monitor_item = nullptr;
  get_static_data().monitor_items_critical_section.enter();
  if (is_entered_ptr(obj)) monitor_item = &get_static_data().monitor_items[obj.first];
  get_static_data().monitor_items_critical_section.leave();
  
  if (monitor_item == nullptr) throw_helper::throws(exception_case::invalid_operation);
  if (monitor_item->thread_id.value() != thread::current_thread().thread_id()) throw_helper::throws(exception_case::synchronization_lock);

  monitor_item->condition_variable.pulse_all();
}

bool monitor::try_enter_ptr(object_ptr obj, int32 milliseconds_timeout, bool& lock_taken) noexcept {
  if (milliseconds_timeout < timeout::infinite) return false;
  get_static_data().monitor_items_critical_section.enter();
  if (!is_entered_ptr(obj)) {
    auto i = item {};
    if (obj.second) {
      auto str = reinterpret_cast<const string*>(obj.first);
      i.name = *str;
    }
    get_static_data().monitor_items.insert({obj.first, i});
  }
  item* monitor_data = &get_static_data().monitor_items[obj.first];
  ++(*monitor_data->used_count);
  get_static_data().monitor_items_critical_section.leave();
  lock_taken = monitor_data->critical_section.try_enter(milliseconds_timeout);
  if (lock_taken) monitor_data->thread_id.value(thread::current_thread().thread_id());
  return lock_taken;
}

bool monitor::wait_ptr(object_ptr obj, int32 milliseconds_timeout) {
  item* monitor_item = nullptr;
  get_static_data().monitor_items_critical_section.enter();
  if (is_entered_ptr(obj)) monitor_item = &get_static_data().monitor_items[obj.first];
  get_static_data().monitor_items_critical_section.leave();
  
  if (monitor_item == nullptr) throw_helper::throws(exception_case::invalid_operation);
  if (monitor_item->thread_id.value() != thread::current_thread().thread_id()) throw_helper::throws(exception_case::synchronization_lock);

  return monitor_item->condition_variable.wait(monitor_item->critical_section, milliseconds_timeout);
}

monitor::static_data& monitor::get_static_data() {
  static static_data data;
  return data;
}
