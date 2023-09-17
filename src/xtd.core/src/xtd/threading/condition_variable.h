#pragma once
#include "../../../include/xtd/threading/monitor.h"
#include "../../../include/xtd/threading/thread.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/condition_variable.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "critical_section.h"
#include <memory>

class xtd::threading::monitor::condition_variable {
public:
  condition_variable() : handle_(std::make_shared<intptr>(xtd::native::condition_variable::create())) {}
  condition_variable(const condition_variable&) = default;
  condition_variable& operator =(const condition_variable& other) {
    xtd::native::condition_variable::destroy(*handle_);
    handle_ = other.handle_;
    return *this;
  }
  condition_variable(condition_variable&&) = default;
  ~condition_variable() {if (handle_.use_count() == 1) xtd::native::condition_variable::destroy(*handle_);}
  
  intptr handle() const noexcept {return *handle_;}
  
  void pulse() {xtd::native::condition_variable::pulse(*handle_);}

  void pulse_all() {xtd::native::condition_variable::pulse_all(*handle_);}
  
  bool wait(const monitor::critical_section& critical_section, int32 milliseconds_timeout) {return xtd::native::condition_variable::wait(*handle_, critical_section.handle(), milliseconds_timeout);}
  
private:
  std::shared_ptr<intptr> handle_;
};
