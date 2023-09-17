// Hacking to remove deprecated warning.
#include <sys/cdefs.h>
#undef __deprecated
#define __deprecated
// end hacking
#include <semaphore.h>

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_semaphore.h>
#include "../../../../include/xtd/native/macos/semaphore.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>
#import <Cocoa/Cocoa.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <algorithm>

using namespace xtd::native;

intmax_t named_semaphore::create(int_least32_t initial_count, int_least32_t max_count, const std::string& name) {
  auto semaphore = sem_open(name.c_str(), O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, std::min(initial_count, max_count));
  return reinterpret_cast<intmax_t>(semaphore);
}

void named_semaphore::destroy(intmax_t handle, const std::string& name) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return;
  if (sem_close(reinterpret_cast<sem_t*>(handle)) == 0) sem_unlink(name.c_str());
}

size_t named_semaphore::max_name_size() {
  return PSEMNAMLEN;
}

intmax_t named_semaphore::open(const std::string& name) {
  auto semaphore = sem_open(name.c_str(), O_RDWR, S_IRUSR | S_IWUSR);
  return reinterpret_cast<intmax_t>(semaphore);
}

bool named_semaphore::signal(intmax_t handle, int_least32_t release_count, int_least32_t& previous_count, bool& io_error) {
  io_error = false;
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) {
    io_error = true;
    return false;
  }
  previous_count = -1;
  sem_getvalue(reinterpret_cast<sem_t*>(handle), &previous_count);
  for (auto count = 0; !io_error && count < release_count; ++count)
    if (sem_post(reinterpret_cast<sem_t*>(handle)) == -1 && errno == EINVAL) io_error = true;
  return !io_error;
}

uint_least32_t named_semaphore::wait(intmax_t handle, int_least32_t milliseconds_timeout) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return 0xFFFFFFFF;
  auto result = milliseconds_timeout == -1 ? sem_wait(reinterpret_cast<sem_t*>(handle)) : sem_milliseconds_timedwait(reinterpret_cast<sem_t*>(handle), milliseconds_timeout);
  if (result && errno == EAGAIN) return 0xFFFFFFFF;
  if (result && errno == EINVAL) return 0xFFFFFFFF;
  if (result && errno == EINTR) return 0x00000080;
  if (result && errno == ETIMEDOUT) return 0x00000102;
  return 0x00000000;
}
