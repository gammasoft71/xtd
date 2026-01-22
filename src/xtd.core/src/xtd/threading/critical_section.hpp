#pragma once
#include "../../../include/xtd/threading/monitor.hpp"
#include "../../../include/xtd/threading/thread.hpp"
#include "../../../include/xtd/diagnostics/stopwatch.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/critical_section>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <memory>

class xtd::threading::monitor::critical_section {
public:
  critical_section() : handle_(xtd::new_sptr<intptr>(native::critical_section::create())) {}
  critical_section(const critical_section&) = default;
  critical_section& operator =(const critical_section& other) {
    xtd::native::critical_section::destroy(*handle_);
    handle_ = other.handle_;
    return *this;
  }
  critical_section(critical_section&&) = default;
  ~critical_section() {if (handle_.use_count() == 1) xtd::native::critical_section::destroy(*handle_);}
  
  [[nodiscard]] auto handle() const noexcept -> intptr {return *handle_;}
  
  auto enter() const noexcept -> void {xtd::native::critical_section::enter(*handle_);}
  
  auto leave() const noexcept -> void {xtd::native::critical_section::leave(*handle_);}
  
  auto try_enter(int32 milliseconds_timeout) const noexcept -> bool {
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
  xtd::sptr<intptr> handle_;
};
