#include <filesystem>
#include <csignal>
#include "../../include/xtd/system_exception.h"

using namespace std;
using namespace xtd;

namespace xtd {
  /// @todo create access_violation_exception class...
  using access_violation_exception = xtd::system_exception;
}

// try to use :
// abort();
// raise(SIGABRT);
// raise(SIGSEGV);
struct signal_catcher {
  signal_catcher() {
    signal(SIGILL, signal_catcher::signal_illegal_instruction_handler);
    signal(SIGABRT, signal_catcher::signal_abort_exception_handler);
    signal(SIGFPE, signal_catcher::signal_floating_point_exception_handler);
    signal(SIGSEGV, signal_catcher::signal_segmentation_violation_handler);
  }
  
  ~signal_catcher() {
    signal(SIGILL, SIG_DFL);
    signal(SIGABRT, SIG_DFL);
    signal(SIGFPE, SIG_DFL);
    signal(SIGSEGV, SIG_DFL);
  }
  
  static void signal_illegal_instruction_handler(int32 signal) {
    ::signal(signal, signal_catcher::signal_illegal_instruction_handler);
    throw xtd::invalid_operation_exception(csf_);
  }
  
  static void signal_abort_exception_handler(int32 signal) {
    ::signal(signal, signal_catcher::signal_abort_exception_handler);
    //throw xtd::threading::thread_abort_exception(caller_);
    exit(-1);
  }
  
  static void signal_floating_point_exception_handler(int32 signal) {
    ::signal(signal, signal_catcher::signal_floating_point_exception_handler);
    throw xtd::arithmetic_exception(csf_);
  }
  
  static void signal_segmentation_violation_handler(int32 signal) {
    ::signal(signal, signal_catcher::signal_segmentation_violation_handler);
    throw xtd::access_violation_exception(csf_);
  }
} signal_catcher;
