#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/mutex.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>
#import <Cocoa/Cocoa.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

using namespace xtd::native;

intmax_t mutex::create(const std::string& name, bool& create_new) {
  sem_t* semaphore = nullptr;
  semaphore = sem_open(name.c_str(), O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
  create_new = semaphore != SEM_FAILED;
  if (semaphore != SEM_FAILED) semaphore = sem_open(name.c_str(), O_CREAT, S_IRUSR | S_IWUSR, 1);
  return semaphore != SEM_FAILED ? reinterpret_cast<intmax_t>(semaphore) : 0;
}

void mutex::destroy(intmax_t handle, const std::string& name) {
  if (sem_close(reinterpret_cast<sem_t*>(handle)) == 0)
    sem_unlink(name.c_str());
}

bool mutex::signal(intmax_t handle) {
  return sem_post(reinterpret_cast<sem_t*>(handle)) != -1;
}

bool mutex::wait(intmax_t handle, int_least32_t milliseconds_timeout) {
  if (milliseconds_timeout == -1) return sem_wait(reinterpret_cast<sem_t*>(handle)) != -1;
  return false;
}
