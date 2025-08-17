#include "../../../include/xtd/threading/thread_exception_event_args.hpp"

using namespace xtd;
using namespace xtd::threading;

thread_exception_event_args::thread_exception_event_args(const std::exception& exception) : exception_(&exception) {
}

const std::exception& thread_exception_event_args::exception() const noexcept {
  return *exception_;
}
