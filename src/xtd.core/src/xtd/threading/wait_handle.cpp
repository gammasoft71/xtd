#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../../include/xtd/threading/thread.h"
#include "../../../include/xtd/threading/wait_handle.h"
#include "../../../include/xtd/argument_exception.h"

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::threading;

const intptr wait_handle::invalid_handle = native::types::invalid_handle();

wait_handle::~wait_handle() {
  close();
}

void wait_handle::close() {}

bool wait_handle::signal_and_wait(wait_handle& to_signal, wait_handle& to_wait) {
  return signal_and_wait(to_signal, to_wait, timeout::infinite);
}

bool wait_handle::signal_and_wait(wait_handle& to_signal, wait_handle& to_wait, int32 milliseconds_timeout) {
  return to_signal.signal() && to_wait.wait(milliseconds_timeout);
}

bool wait_handle::signal_and_wait(wait_handle& to_signal, wait_handle& to_wait, const time_span& timeout) {
  return signal_and_wait(to_signal, to_wait, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool wait_handle::wait_all(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles){
  return wait_all(wait_handles, timeout::infinite);
}

bool wait_handle::wait_all(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  vector<wait_handle*> wait_handle_pointers;
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_all(wait_handle_pointers, milliseconds_timeout);
}

bool wait_handle::wait_all(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_all(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool wait_handle::wait_all(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles){
  return wait_all(wait_handles, timeout::infinite);
}

bool wait_handle::wait_all(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  vector<wait_handle*> wait_handle_pointers;
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_all(wait_handle_pointers, milliseconds_timeout);
}

bool wait_handle::wait_all(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_all(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool wait_handle::wait_all(const vector<shared_ptr<wait_handle>>& wait_handles) {
  return wait_all(wait_handles, timeout::infinite);
}

bool wait_handle::wait_all(const vector<shared_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  vector<wait_handle*> wait_handle_pointers;
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_all(wait_handle_pointers, milliseconds_timeout);
}

bool wait_handle::wait_all(const vector<shared_ptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_all(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool wait_handle::wait_all(const vector<unique_ptr<wait_handle>>& wait_handles) {
  return wait_all(wait_handles, timeout::infinite);
}

bool wait_handle::wait_all(const vector<unique_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  vector<wait_handle*> wait_handle_pointers;
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_all(wait_handle_pointers, milliseconds_timeout);
}

bool wait_handle::wait_all(const vector<unique_ptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_all(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

size_t wait_handle::wait_any(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles) {
  return wait_any(wait_handles, timeout::infinite);
}

size_t wait_handle::wait_any(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  vector<wait_handle*> wait_handle_pointers;
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_any(wait_handle_pointers, milliseconds_timeout);
}

size_t wait_handle::wait_any(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_any(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}
size_t wait_handle::wait_any(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles) {
  return wait_any(wait_handles, timeout::infinite);
}

size_t wait_handle::wait_any(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  vector<wait_handle*> wait_handle_pointers;
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_any(wait_handle_pointers, milliseconds_timeout);
}

size_t wait_handle::wait_any(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_any(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

size_t wait_handle::wait_any(const vector<shared_ptr<wait_handle>>& wait_handles) {
  return wait_any(wait_handles, timeout::infinite);
}

size_t wait_handle::wait_any(const vector<shared_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  vector<wait_handle*> wait_handle_pointers;
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_any(wait_handle_pointers, milliseconds_timeout);
}

size_t wait_handle::wait_any(const vector<shared_ptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_any(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

size_t wait_handle::wait_any(const vector<unique_ptr<wait_handle>>& wait_handles) {
  return wait_any(wait_handles, timeout::infinite);
}

size_t wait_handle::wait_any(const vector<unique_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  vector<wait_handle*> wait_handle_pointers;
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_any(wait_handle_pointers, milliseconds_timeout);
}

size_t wait_handle::wait_any(const vector<unique_ptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_any(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool wait_handle::wait_one() {
  return wait_one(timeout::infinite);
}

bool wait_handle::wait_one(int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw argument_exception {csf_};
  return thread::do_wait(*this, milliseconds_timeout);
}

bool wait_handle::wait_one(const time_span& timeout) {
  return wait_one(as<int32>(timeout.total_milliseconds()));
}

bool wait_handle::wait_all(const std::vector<wait_handle*>& wait_handles, int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw argument_exception {csf_};
  
  if (milliseconds_timeout == timeout::infinite) {
    for (auto item : wait_handles)
      item->wait_one();
    return true;
  }
  
  int32 timeout = milliseconds_timeout;
  int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
  for (auto& item : wait_handles) {
    if (item->wait_one(timeout) == false) return false;
    timeout = milliseconds_timeout - as<int32>(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start);
    if (timeout < 0) return false;
  }
  return true;
}

size_t wait_handle::wait_any(const std::vector<wait_handle*>& wait_handles, int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw argument_exception {csf_};
  
  if (milliseconds_timeout == timeout::infinite) {
    do {
      for (auto index = 0ul; index < wait_handles.size(); ++index) {
        if (wait_handles[index]->wait_one(0) == true) return index;
        thread::yield();
        thread::sleep(1);
      }
    } while (true);
  }
  
  int32 timeout = milliseconds_timeout;
  int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
  do {
    for (auto index = 0ul; index < wait_handles.size(); index++) {
      if (wait_handles[index]->wait_one(0) == true) return index;
      timeout = milliseconds_timeout - as<int32>(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start);
      if (timeout < 0) return wait_timeout;
      thread::yield();
      thread::sleep(1);
    }
  } while (timeout >= 0);

  return wait_timeout;
}
