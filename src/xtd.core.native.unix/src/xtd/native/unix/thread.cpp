#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/thread.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <pthread.h>

using namespace xtd::native;

bool thread::cancel(intmax_t handle) {
  if (reinterpret_cast<pthread_t>(handle)) return false;
  return pthread_cancel(reinterpret_cast<pthread_t>(handle)) == 0;
}

intmax_t thread::get_current_thread_handle() {
  return reinterpret_cast<intmax_t>(pthread_self());
}

bool thread::resume(intmax_t handle) {
  // The POSIX standard provides no mechanism by which a thread A can suspend the execution of another thread B, without cooperation from B. The only way to implement a suspend/resume mechanism is to have B check periodically some global variable for a suspend request and then suspend itself on a condition variable, which another thread can signal later to restart B.
  return false;
}

bool thread::set_current_thread_name(const std::string& name) {
  pthread_setname_np(pthread_self(), name.c_str());
  return true;
}

bool thread::set_priority(intmax_t handle, int_least32_t priority) {
  int_least32_t policy;
  sched_param schedParam;
  if (::pthread_getschedparam(reinterpret_cast<pthread_t>(handle), &policy, &schedParam) != 0)
    return false;
  
  schedParam.sched_priority = static_cast<int_least32_t>(ceil((static_cast<double>(priority) * (sched_get_priority_max(policy) - sched_get_priority_min(policy)) / 4) + sched_get_priority_min(policy)));
  return pthread_setschedparam(reinterpret_cast<pthread_t>(handle), policy, &schedParam) == 0;
}

bool thread::suspend(intmax_t handle) {
  // The POSIX standard provides no mechanism by which a thread A can suspend the execution of another thread B, without cooperation from B. The only way to implement a suspend/resume mechanism is to have B check periodically some global variable for a suspend request and then suspend itself on a condition variable, which another thread can signal later to restart B.
  return false;
}
