#pragma once
#include "../../../include/xtd/threading/monitor"
#include "../../../include/xtd/threading/thread"
#include "../../../include/xtd/diagnostics/stopwatch"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/critical_section>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <memory>

class xtd::threading::monitor::critical_section {
public:
  critical_section() : handle_(std::make_shared<intptr>(native::critical_section::create())) {}
  critical_section(const critical_section&) = default;
  critical_section& operator =(const critical_section& other) {
    xtd::native::critical_section::destroy(*handle_);
    handle_ = other.handle_;
    return *this;
  }
  critical_section(critical_section&&) = default;
  ~critical_section() {if (handle_.use_count() == 1) xtd::native::critical_section::destroy(*handle_);}
  
  intptr handle() const noexcept {return *handle_;}
  
  void enter() const noexcept {xtd::native::critical_section::enter(*handle_);}
  
  void leave() const noexcept {xtd::native::critical_section::leave(*handle_);}
  
  bool try_enter(int32 milliseconds_timeout) const noexcept {
    if (milliseconds_timeout == timeout::infinite) {
      xtd::native::critical_section::enter(*handle_);
      return true;
    }
    auto sw = xtd::diagnostics::stopwatch::start_new();
    auto result = false;
    while (!result && sw.elapsed_milliseconds() <= milliseconds_timeout) {
      result = xtd::native::critical_section::try_enter(*handle_);
      if (!result) thread::sleep(1);
    }
    return result;
  }
  
private:
  std::shared_ptr<intptr> handle_;
};
