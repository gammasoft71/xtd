#include "../../../include/xtd/threading/monitor.h"
#include "../../../include/xtd/threading/interlocked.h"
#include "../../../include/xtd/threading/mutex.h"
#include "../../../include/xtd/threading/thread.h"
#include "../../../include/xtd/threading/synchronization_lock_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/critical_section.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <chrono>
#include <mutex>
#include <optional>

using namespace xtd;
using namespace xtd::threading;

class monitor::critical_sction {
public:
  critical_sction() : handle_(std::make_shared<intptr>(native::critical_section::create())) {}
  
  critical_sction(const critical_sction&) = default;
  critical_sction& operator =(const critical_sction&) = default;
  critical_sction(critical_sction&&) = default;
  ~critical_sction() {if (handle_.use_count() == 1) native::critical_section::destroy(*handle_);}

  void enter() const noexcept {native::critical_section::enter(*handle_);}
  
  void leave() const noexcept {native::critical_section::leave(*handle_);}
  
  bool try_enter(int32 milliseconds_timeout) const noexcept {
    if (milliseconds_timeout == timeout::infinite) {
      native::critical_section::enter(*handle_);
      return true;
    }
    int32 timeout = milliseconds_timeout;
    int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
    do {
      if (native::critical_section::try_enter(*handle_)) return true;
      timeout = milliseconds_timeout - as<int32>(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start);
      thread::yield();
      thread::sleep(1);
    } while (timeout >= 0);
    return false;
  }

private:
  std::shared_ptr<intptr> handle_;
};

struct monitor::item {
  critical_sction event;
  int32 used_counter {0};
  std::optional<ustring> name;
  intptr thread_id {thread::invalid_thread_id};
};

struct monitor::static_data {
  std::recursive_mutex monitor_mutex;
  monitor::item_collection items;
};

void monitor::enter_ptr(ptr_item ptr) {
  bool lock_taken = false;
  enter_ptr(ptr, lock_taken);
}

void monitor::enter_ptr(ptr_item ptr, bool& lock_taken) {
  if (!try_enter_ptr(ptr, timeout::infinite, lock_taken))
    throw invalid_operation_exception(csf_);
}

void monitor::exit_ptr(ptr_item ptr) {
  get_static_data().monitor_mutex.lock();
  if (!is_entered_ptr(ptr)) {
    get_static_data().monitor_mutex.unlock();
    throw synchronization_lock_exception(csf_);
  }
  
  item saved;
  item* monitor_data = &get_static_data().items[ptr.first];
  if (interlocked::decrement(monitor_data->used_counter) == 0) {
    saved = get_static_data().items[ptr.first];
    if (ptr.second) delete reinterpret_cast<const ustring*>(ptr.first);
    get_static_data().items.erase(ptr.first);
    monitor_data = &saved;
  }
  monitor_data->thread_id = thread::invalid_thread_id;
  monitor_data->event.leave();
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

bool monitor::is_entered_ptr(ptr_item ptr) noexcept {
  auto found = get_static_data().items.find(ptr.first) != get_static_data().items.end();
  return found;
}

void monitor::pulse_ptr(ptr_item ptr) {
  item* monitor_item = nullptr;
  get_static_data().monitor_mutex.lock();
  if (is_entered_ptr(ptr)) monitor_item = &get_static_data().items[ptr.first];
  get_static_data().monitor_mutex.unlock();
  
  if (monitor_item == nullptr) throw invalid_operation_exception(csf_);
  if (monitor_item->thread_id != thread::current_thread().thread_id()) throw synchronization_lock_exception {csf_};

  // make pulse...
}

void monitor::pulse_all_ptr(ptr_item ptr) {
  item* monitor_item = nullptr;
  get_static_data().monitor_mutex.lock();
  if (is_entered_ptr(ptr)) monitor_item = &get_static_data().items[ptr.first];
  get_static_data().monitor_mutex.unlock();
  
  if (monitor_item == nullptr) throw invalid_operation_exception(csf_);
  if (monitor_item->thread_id != thread::current_thread().thread_id()) throw synchronization_lock_exception {csf_};
  
  // make pulse...
}

bool monitor::try_enter_ptr(ptr_item ptr, int32 milliseconds_timeout, bool& lock_taken) noexcept {
  if (milliseconds_timeout < timeout::infinite) return false;
  get_static_data().monitor_mutex.lock();
  if (!is_entered_ptr(ptr)) {
    auto i = item {};
    if (ptr.second) {
      auto str = reinterpret_cast<const ustring*>(ptr.first);
      i.name = *str;
    }
    get_static_data().items.insert({ptr.first, i});
  }
  item* monitor_data = &get_static_data().items[ptr.first];
  interlocked::increment(monitor_data->used_counter);
  get_static_data().monitor_mutex.unlock();
  lock_taken = monitor_data->event.try_enter(milliseconds_timeout);
  if (lock_taken) monitor_data->thread_id = thread::current_thread().thread_id();
  return lock_taken;
}

bool monitor::wait_ptr(ptr_item ptr, int32 milliseconds_timeout, bool exit_context) noexcept {
  return false;
}

monitor::static_data& monitor::get_static_data() {
  static static_data data;
  return data;
}
