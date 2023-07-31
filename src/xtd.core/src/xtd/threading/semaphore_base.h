#pragma once
#include "../../../include/xtd/threading/semaphore.h"

class xtd::threading::semaphore::semaphore_base {
public:
  virtual ~semaphore_base() = default;
  
  virtual intptr handle() const noexcept = 0;
  virtual void handle(intptr value) = 0;
  virtual bool create(int32 initial_count, int32 maximum_count) = 0;
  virtual bool create(int32 initial_count, int32 maximum_count, const ustring& name) = 0;
  virtual void destroy() = 0;
  virtual bool open(const ustring& name) = 0;
  virtual bool signal(bool& io_error, int32 release_count, int32& previous_count) = 0;
  virtual uint32 wait(int32 milliseconds_timeout) = 0;
};
