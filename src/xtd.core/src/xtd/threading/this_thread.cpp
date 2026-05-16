#include "../../../include/xtd/threading/this_thread.hpp"
#include "../../../include/xtd/date_time.hpp"

using namespace xtd;
using namespace xtd::threading;

intptr this_thread::handle() noexcept {
  return thread::current_thread().handle();
}

int32 this_thread::managed_thread_id() noexcept {
  return thread::current_thread().managed_thread_id();
}

string this_thread::name() noexcept {
  return thread::current_thread().name();
}

void this_thread::name(const string& name) {
  thread::current_thread().name(name);
}

thread_priority this_thread::priority() noexcept {
  return thread::current_thread().priority();
}

void this_thread::priority(thread_priority priority) {
  thread::current_thread().priority(priority);
}

intptr this_thread::thread_id() noexcept {
  return thread::current_thread().thread_id();
}

intptr this_thread::get_id() noexcept {
  return thread::current_thread().thread_id();
}

void this_thread::sleep_for(const time_span& sleep_duration) {
  thread::sleep(sleep_duration);
}

void this_thread::sleep_until(const date_time& sleep_time) {
  thread::sleep(sleep_time - date_time::now());
}

bool this_thread::yield() noexcept {
  return thread::yield();
}
