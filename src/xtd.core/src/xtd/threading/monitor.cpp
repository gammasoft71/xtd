#include "../../../include/xtd/threading/interlocked.h"
#include "../../../include/xtd/threading/monitor.h"
#include "../../../include/xtd/threading/mutex.h"
#include "../../../include/xtd/threading/synchronization_lock_exception.h"
#include "../../../include/xtd/threading/thread.h"
#include "../../../include/xtd/diagnostics/stopwatch.h"
#include "../../../include/xtd/not_implemented_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/condition_variable.h>
#include <xtd/native/critical_section.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <mutex>
#include <optional>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::threading;

class monitor::critical_section {
public:
  critical_section() : handle_(std::make_shared<intptr>(native::critical_section::create())) {}
  critical_section(const critical_section&) = default;
  critical_section& operator =(const critical_section&) = default;
  critical_section(critical_section&&) = default;
  ~critical_section() {if (handle_.use_count() == 1) native::critical_section::destroy(*handle_);}
  
  intptr handle() const noexcept {return *handle_;}
  
  void enter() const noexcept {native::critical_section::enter(*handle_);}
  
  void leave() const noexcept {native::critical_section::leave(*handle_);}
  
  bool try_enter(int32 milliseconds_timeout) const noexcept {
    if (milliseconds_timeout == timeout::infinite) {
      native::critical_section::enter(*handle_);
      return true;
    }
    auto sw = stopwatch::start_new();
    auto result = false;
    while (!result && sw.elapsed_milliseconds() <= milliseconds_timeout) {
      result = native::critical_section::try_enter(*handle_);
      if (!result) thread::sleep(1);
    }
    return result;
  }
  
private:
  std::shared_ptr<intptr> handle_;
};

class monitor::condition_variable {
public:
  condition_variable() : handle_(std::make_shared<intptr>(native::condition_variable::create())) {}
  condition_variable(const condition_variable&) = default;
  condition_variable& operator =(const condition_variable&) = default;
  condition_variable(condition_variable&&) = default;
  ~condition_variable() {if (handle_.use_count() == 1) native::condition_variable::destroy(*handle_);}
  
  intptr handle() const noexcept {return *handle_;}
  
  void pulse() {native::condition_variable::pulse(*handle_);}

  void pulse_all() {native::condition_variable::pulse(*handle_);}
  
  bool wait(const critical_section& critical_section, int32 milliseconds_timeout) {return native::condition_variable::wait(*handle_, critical_section.handle(), milliseconds_timeout);}
  
private:
  std::shared_ptr<intptr> handle_;
};

struct monitor::item {
  monitor::critical_section critical_section;
  int32 used_counter {0};
  std::optional<ustring> name;
  intptr thread_id {thread::invalid_thread_id};
  int32 wait_threads {0};
  monitor::condition_variable condition_variable;
};

struct monitor::static_data {
  critical_section monitor_items_critical_section;
  monitor::item_collection monitor_items;
};

void monitor::enter_ptr(object_ptr obj) {
  bool lock_taken = false;
  enter_ptr(obj, lock_taken);
}

void monitor::enter_ptr(object_ptr obj, bool& lock_taken) {
  if (!try_enter_ptr(obj, timeout::infinite, lock_taken))
    throw invalid_operation_exception {csf_};
}

void monitor::exit_ptr(object_ptr obj) {
  get_static_data().monitor_items_critical_section.enter();
  if (!is_entered_ptr(obj)) {
    get_static_data().monitor_items_critical_section.leave();
    throw synchronization_lock_exception {csf_};
  }
  
  item saved;
  item* monitor_data = &get_static_data().monitor_items[obj.first];
  if (interlocked::decrement(monitor_data->used_counter) == 0) {
    saved = get_static_data().monitor_items[obj.first];
    if (obj.second) delete reinterpret_cast<const ustring*>(obj.first);
    get_static_data().monitor_items.erase(obj.first);
    monitor_data = &saved;
  }
  monitor_data->thread_id = thread::invalid_thread_id;
  monitor_data->critical_section.leave();
  get_static_data().monitor_items_critical_section.leave();
}

intptr monitor::get_ustring_ptr(const ustring& str) {
  if (str.empty()) throw argument_exception {csf_};
  get_static_data().monitor_items_critical_section.enter();
  intptr ptr = reinterpret_cast<intptr>(&str);
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
  
  if (monitor_item == nullptr) throw invalid_operation_exception {csf_};
  if (monitor_item->thread_id != thread::current_thread().thread_id()) throw synchronization_lock_exception {csf_};

  if (monitor_item->wait_threads) monitor_item->condition_variable.pulse();
}

void monitor::pulse_all_ptr(object_ptr obj) {
  item* monitor_item = nullptr;
  get_static_data().monitor_items_critical_section.enter();
  if (is_entered_ptr(obj)) monitor_item = &get_static_data().monitor_items[obj.first];
  get_static_data().monitor_items_critical_section.leave();
  
  if (monitor_item == nullptr) throw invalid_operation_exception {csf_};
  if (monitor_item->thread_id != thread::current_thread().thread_id()) throw synchronization_lock_exception {csf_};

  while (monitor_item->wait_threads) {
    monitor_item->condition_variable.pulse_all();
  }
}

bool monitor::try_enter_ptr(object_ptr obj, int32 milliseconds_timeout, bool& lock_taken) noexcept {
  if (milliseconds_timeout < timeout::infinite) return false;
  get_static_data().monitor_items_critical_section.enter();
  if (!is_entered_ptr(obj)) {
    auto i = item {};
    if (obj.second) {
      auto str = reinterpret_cast<const ustring*>(obj.first);
      i.name = *str;
    }
    get_static_data().monitor_items.insert({obj.first, i});
  }
  item* monitor_data = &get_static_data().monitor_items[obj.first];
  interlocked::increment(monitor_data->used_counter);
  get_static_data().monitor_items_critical_section.leave();
  lock_taken = monitor_data->critical_section.try_enter(milliseconds_timeout);
  if (lock_taken) monitor_data->thread_id = thread::current_thread().thread_id();
  return lock_taken;
}

bool monitor::wait_ptr(object_ptr obj, int32 milliseconds_timeout) {
  item* monitor_item = nullptr;
  get_static_data().monitor_items_critical_section.enter();
  if (is_entered_ptr(obj)) monitor_item = &get_static_data().monitor_items[obj.first];
  get_static_data().monitor_items_critical_section.leave();
  
  if (monitor_item == nullptr) throw invalid_operation_exception {csf_};
  if (monitor_item->thread_id != thread::current_thread().thread_id()) throw synchronization_lock_exception {csf_};

  monitor_item->critical_section.leave();
  interlocked::increment(monitor_item->wait_threads);
  auto result = monitor_item->condition_variable.wait(monitor_item->critical_section, milliseconds_timeout);
  interlocked::decrement(monitor_item->wait_threads);
  monitor_item->critical_section.enter();
  return result;
}

monitor::static_data& monitor::get_static_data() {
  static static_data data;
  return data;
}
