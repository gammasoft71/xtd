#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_semaphore.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <ctime>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>

using namespace xtd::native;

intptr_t named_semaphore::create(const std::string& name, bool& create_new) {
  sem_t* semaphore = nullptr;
  semaphore = sem_open(name.c_str(), O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
  create_new = semaphore != SEM_FAILED;
  if (semaphore == SEM_FAILED) semaphore = sem_open(name.c_str(), O_CREAT, S_IRUSR | S_IWUSR, 1);
  return semaphore != SEM_FAILED ? reinterpret_cast<intptr_t>(semaphore) : 0;
}

void named_semaphore::destroy(intptr_t handle, const std::string& name) {
  if (sem_close(reinterpret_cast<sem_t*>(handle)) == 0)
    sem_unlink(name.c_str());
}

bool named_semaphore::signal(intptr_t handle, bool& io_error) {
  io_error = false;
  if (sem_post(reinterpret_cast<sem_t*>(handle)) == -1) {
    if (errno == EINVAL) io_error = true;
    return  false;;
  }
  return true;
}

bool named_semaphore::wait(intptr_t handle, int_least32_t milliseconds_timeout, bool& io_error) {
  io_error = false;
  if (milliseconds_timeout == -1) {
    if (sem_wait(reinterpret_cast<sem_t*>(handle)) == -1) {
      if (errno == EAGAIN) return true;;
      if (errno == EINVAL) io_error = true;
      return  false;;
    }
    return true;
  }
  
  struct timespec timeout;
  clock_gettime(CLOCK_REALTIME, &timeout);
  timeout.tv_sec = milliseconds_timeout / 1000;
  timeout.tv_nsec = (milliseconds_timeout % 1000) * 1000000;
  
  if (sem_timedwait(reinterpret_cast<sem_t*>(handle), &timeout) == -1) {
    if (errno == EAGAIN) return true;
    if (errno != ETIMEDOUT) io_error = true;
    return false;
  }
  return true;
}
