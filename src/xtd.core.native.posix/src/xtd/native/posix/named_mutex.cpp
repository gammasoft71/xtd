#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_mutex>
#include "../../../../include/xtd/native/posix/semaphore.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <fcntl.h>
#include <sys/stat.h>

using namespace xtd::native;

intmax_t named_mutex::create(bool initially_owned, const std::string& name) {
  auto semaphore = sem_open(name.c_str(), O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, initially_owned ? 0 : 1);
  return reinterpret_cast<intmax_t>(semaphore);
}

void named_mutex::destroy(intmax_t handle, const std::string& name) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return;
  if (sem_close(reinterpret_cast<sem_t*>(handle)) == 0) sem_unlink(name.c_str());
}

size_t named_mutex::max_name_size() {
  return PSEMNAMLEN;
}

intmax_t named_mutex::open(const std::string& name) {
  auto semaphore = sem_open(name.c_str(), O_RDWR, S_IRUSR | S_IWUSR);
  return reinterpret_cast<intmax_t>(semaphore);
}

bool named_mutex::signal(intmax_t handle, bool& io_error) {
  io_error = false;
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) {
    io_error = true;
    return false;
  }
  if (sem_post(reinterpret_cast<sem_t*>(handle)) == -1 && errno == EINVAL) io_error = true;
  return !io_error;
}

uint_least32_t named_mutex::wait(intmax_t handle, int_least32_t milliseconds_timeout) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return 0xFFFFFFFF;
  auto result = milliseconds_timeout == -1 ? sem_wait(reinterpret_cast<sem_t*>(handle)) : sem_milliseconds_timedwait(reinterpret_cast<sem_t*>(handle), milliseconds_timeout);
  if (result && errno == EAGAIN) return 0xFFFFFFFF;
  if (result && errno == EDEADLK) return 0xFFFFFFFF;
  if (result && errno == EINTR) return 0x00000080;
  if (result && errno == EINVAL) return 0xFFFFFFFF;
  if (result && errno == ETIMEDOUT) return 0x00000102;
  return 0x00000000;
}
