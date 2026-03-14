#include "../../../include/xtd/threading/this_thread.hpp"
#include "../../../include/xtd/date_time.hpp"

using namespace xtd;
using namespace xtd::threading;
using namespace xtd::threading::this_thread;

intptr handle() noexcept {
  return thread::current_thread().handle();
}

int32 managed_thread_id() noexcept {
  return thread::current_thread().managed_thread_id();
}

string name() noexcept {
  return thread::current_thread().name();
}

void name(const string& name) {
  thread::current_thread().name(name);
}

thread_priority priority() noexcept {
  return thread::current_thread().priority();
}

void priority(thread_priority priority) {
  thread::current_thread().priority(priority);
}

intptr thread_id() noexcept {
  return thread::current_thread().thread_id();
}

intptr get_id() noexcept {
  return thread::current_thread().thread_id();
}

void sleep_for(const time_span& sleep_duration) {
  thread::sleep(sleep_duration);
}

void sleep_until(const date_time& sleep_time) {
  thread::sleep(sleep_time - date_time::now());
}

bool yield() noexcept {
  return thread::yield();
}
