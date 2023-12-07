#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/thread>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <math.h>
#include <pthread.h>
#include <thread>

#define PTHREAD_FAILED ((pthread_t)-1)

using namespace xtd::native;

bool thread::cancel(intmax_t handle) {
  if (reinterpret_cast<pthread_t>(handle) == PTHREAD_FAILED) return false;
  return pthread_cancel(reinterpret_cast<pthread_t>(handle)) == 0;
}

intmax_t thread::create(std::function<void(intmax_t)> start, intmax_t obj, int_least32_t max_stack_size, bool suspended, intmax_t& id) {
  auto thread = pthread_t {};
  int error = pthread_create(&thread, nullptr, [](void* thread_arg)->void* {
    auto start_obj = reinterpret_cast<std::pair<std::function<void(intmax_t)>, intmax_t>*>(thread_arg);
    start_obj->first(start_obj->second);
    delete start_obj;
    return nullptr;
  }, reinterpret_cast<void*>( new std::pair<std::function<void(intmax_t)>, intmax_t> {start, obj}));
  if (error != 0) return reinterpret_cast<intmax_t>(PTHREAD_FAILED);
  // The POSIX standard provides no mechanism by which a thread A can suspend the execution of another thread B, without cooperation from B. The only way to implement a suspend/resume mechanism is to have B check periodically some global variable for a suspend request and then suspend itself on a condition variable, which another thread can signal later to restart B.
  id = reinterpret_cast<intmax_t>(thread);
  return reinterpret_cast<intmax_t>(thread);
}

bool thread::detach(intmax_t handle) {
  if (reinterpret_cast<pthread_t>(handle) == PTHREAD_FAILED) return false;
  return pthread_detach(reinterpret_cast<pthread_t>(handle)) == 0;
}

intmax_t thread::get_current_thread_handle() {
  return reinterpret_cast<intmax_t>(pthread_self());
}

intmax_t thread::get_thread_id(intmax_t handle) {
  return handle;
}

bool thread::join(intmax_t handle) {
  if (reinterpret_cast<pthread_t>(handle) == PTHREAD_FAILED) return false;
  return pthread_join(reinterpret_cast<pthread_t>(handle), nullptr) == 0;
}

bool thread::resume(intmax_t handle) {
  if (reinterpret_cast<pthread_t>(handle) == PTHREAD_FAILED) return false;
  // The POSIX standard provides no mechanism by which a thread A can suspend the execution of another thread B, without cooperation from B. The only way to implement a suspend/resume mechanism is to have B check periodically some global variable for a suspend request and then suspend itself on a condition variable, which another thread can signal later to restart B.
  return false;
}

bool thread::set_current_thread_name(const std::string& name) {
  pthread_setname_np(name.c_str());
  return true;
}

bool thread::set_priority(intmax_t handle, int_least32_t priority) {
  if (reinterpret_cast<pthread_t>(handle) == PTHREAD_FAILED) return false;
  auto policy = 0;
  auto schedParam = sched_param {};
  if (::pthread_getschedparam(reinterpret_cast<pthread_t>(handle), &policy, &schedParam) != 0)
    return false;
  
  schedParam.sched_priority = static_cast<int_least32_t>(std::ceil((static_cast<double>(priority) * (sched_get_priority_max(policy) - sched_get_priority_min(policy)) / 4) + sched_get_priority_min(policy)));
  return pthread_setschedparam(reinterpret_cast<pthread_t>(handle), policy, &schedParam) == 0;
}

void thread::sleep(int_least32_t milliseconds_timeout) {
  auto infinite_sleep = [] {while (true) std::this_thread::sleep_for(std::chrono::hours::max());};
  if (milliseconds_timeout == -1) infinite_sleep();
  else if (milliseconds_timeout == 0) yield();
  else std::this_thread::sleep_for(std::chrono::milliseconds {milliseconds_timeout});
}

bool thread::suspend(intmax_t handle) {
  if (reinterpret_cast<pthread_t>(handle) == PTHREAD_FAILED) return false;
  // The POSIX standard provides no mechanism by which a thread A can suspend the execution of another thread B, without cooperation from B. The only way to implement a suspend/resume mechanism is to have B check periodically some global variable for a suspend request and then suspend itself on a condition variable, which another thread can signal later to restart B.
  return false;
}

bool thread::yield() {
  std::this_thread::yield();
  return true;
}
