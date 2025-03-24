#include "../../../include/xtd/threading/thread.hpp"
#include "../../../include/xtd/threading/wait_handle.hpp"
#include "../../../include/xtd/diagnostics/stopwatch.hpp"
#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/invalid_handle.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::helpers;
using namespace xtd::threading;

const intptr wait_handle::invalid_handle = xtd::native::types::invalid_handle();

wait_handle::~wait_handle() {
  close();
}

void wait_handle::close() {
}

bool wait_handle::signal_and_wait(wait_handle& to_signal, wait_handle& to_wait) {
  return signal_and_wait(to_signal, to_wait, timeout::infinite);
}

bool wait_handle::signal_and_wait(wait_handle& to_signal, wait_handle& to_wait, int32 milliseconds_timeout) {
  return to_signal.signal() && to_wait.wait(milliseconds_timeout);
}

bool wait_handle::signal_and_wait(wait_handle& to_signal, wait_handle& to_wait, const time_span& timeout) {
  return signal_and_wait(to_signal, to_wait, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool wait_handle::wait_all(const std::initializer_list<xtd::sptr<wait_handle>>& wait_handles){
  return wait_all(wait_handles, timeout::infinite);
}

bool wait_handle::wait_all(const std::initializer_list<xtd::sptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  auto wait_handle_pointers = std::vector<wait_handle*> {};
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_all(wait_handle_pointers, milliseconds_timeout);
}

bool wait_handle::wait_all(const std::initializer_list<xtd::sptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_all(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool wait_handle::wait_all(const std::initializer_list<xtd::uptr<wait_handle>>& wait_handles){
  return wait_all(wait_handles, timeout::infinite);
}

bool wait_handle::wait_all(const std::initializer_list<xtd::uptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  auto wait_handle_pointers = std::vector<wait_handle*> {};
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_all(wait_handle_pointers, milliseconds_timeout);
}

bool wait_handle::wait_all(const std::initializer_list<xtd::uptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_all(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool wait_handle::wait_all(const std::vector<xtd::sptr<wait_handle>>& wait_handles) {
  return wait_all(wait_handles, timeout::infinite);
}

bool wait_handle::wait_all(const std::vector<xtd::sptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  auto wait_handle_pointers = std::vector<wait_handle*> {};
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_all(wait_handle_pointers, milliseconds_timeout);
}

bool wait_handle::wait_all(const std::vector<xtd::sptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_all(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool wait_handle::wait_all(const std::vector<xtd::uptr<wait_handle>>& wait_handles) {
  return wait_all(wait_handles, timeout::infinite);
}

bool wait_handle::wait_all(const std::vector<xtd::uptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  auto wait_handle_pointers = std::vector<wait_handle*> {};
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_all(wait_handle_pointers, milliseconds_timeout);
}

bool wait_handle::wait_all(const std::vector<xtd::uptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_all(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

size_t wait_handle::wait_any(const std::initializer_list<xtd::sptr<wait_handle>>& wait_handles) {
  return wait_any(wait_handles, timeout::infinite);
}

size_t wait_handle::wait_any(const std::initializer_list<xtd::sptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  auto wait_handle_pointers = std::vector<wait_handle*> {};
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_any(wait_handle_pointers, milliseconds_timeout);
}

size_t wait_handle::wait_any(const std::initializer_list<xtd::sptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_any(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}
size_t wait_handle::wait_any(const std::initializer_list<xtd::uptr<wait_handle>>& wait_handles) {
  return wait_any(wait_handles, timeout::infinite);
}

size_t wait_handle::wait_any(const std::initializer_list<xtd::uptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  auto wait_handle_pointers = std::vector<wait_handle*> {};
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_any(wait_handle_pointers, milliseconds_timeout);
}

size_t wait_handle::wait_any(const std::initializer_list<xtd::uptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_any(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

size_t wait_handle::wait_any(const std::vector<xtd::sptr<wait_handle>>& wait_handles) {
  return wait_any(wait_handles, timeout::infinite);
}

size_t wait_handle::wait_any(const std::vector<xtd::sptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  auto wait_handle_pointers = std::vector<wait_handle*> {};
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_any(wait_handle_pointers, milliseconds_timeout);
}

size_t wait_handle::wait_any(const std::vector<xtd::sptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_any(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

size_t wait_handle::wait_any(const std::vector<xtd::uptr<wait_handle>>& wait_handles) {
  return wait_any(wait_handles, timeout::infinite);
}

size_t wait_handle::wait_any(const std::vector<xtd::uptr<wait_handle>>& wait_handles, int32 milliseconds_timeout) {
  auto wait_handle_pointers = std::vector<wait_handle*> {};
  for (auto& wait_handle : wait_handles)
    wait_handle_pointers.push_back(wait_handle.get());
  return wait_any(wait_handle_pointers, milliseconds_timeout);
}

size_t wait_handle::wait_any(const std::vector<xtd::uptr<wait_handle>>& wait_handles, const time_span& timeout) {
  return wait_any(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool wait_handle::wait_one() {
  return wait_one(timeout::infinite);
}

bool wait_handle::wait_one(int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw_helper::throws(exception_case::argument);
  return thread::do_wait(*this, milliseconds_timeout);
}

bool wait_handle::wait_one(const time_span& timeout) {
  return wait_one(as<int32>(timeout.total_milliseconds()));
}

bool wait_handle::wait_all(const std::vector<wait_handle*>& wait_handles, int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw_helper::throws(exception_case::argument);
  
  if (milliseconds_timeout == timeout::infinite) {
    for (auto item : wait_handles)
      item->wait_one();
    return true;
  }
  
  auto sw = stopwatch::start_new();
  for (auto& item : wait_handles)
    if (sw.elapsed_milliseconds() > milliseconds_timeout || item->wait_one(milliseconds_timeout - as<int32>(sw.elapsed_milliseconds()))) return false;
  return true;
}

size_t wait_handle::wait_any(const std::vector<wait_handle*>& wait_handles, int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw_helper::throws(exception_case::argument);
  
  if (milliseconds_timeout == timeout::infinite) {
    while (true) {
      for (auto index = 0_z; index < wait_handles.size(); ++index) {
        if (wait_handles[index]->wait_one(0) == true) return index;
        thread::sleep(1);
      }
    }
  }
  
  auto sw = stopwatch::start_new();
  while (sw.elapsed_milliseconds() <= milliseconds_timeout) {
    for (auto index = 0_z; index < wait_handles.size(); index++) {
      if (wait_handles[index]->wait_one(0) == true) return index;
      thread::sleep(1);
    }
  }
  return wait_timeout;
}
