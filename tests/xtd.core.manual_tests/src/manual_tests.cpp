#define TRACE
#include <filesystem>
#include <csignal>
#include <xtd/xtd.core>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

namespace xtd {
  using access_violation_exception = xtd::system_exception;
}

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

class xtd_core_manual_test {
public:
  static void main() {

    //abort();
    //raise(SIGABRT);
    //raise(SIGSEGV);
    
    //assert_(false);
    //assert_(false, "User message");
    //debug::cassert_(false);
    //debug::cassert_(false, "User message");
    //debug::cassert(false, "User message");
    trace::cassert_(false, "User message");
    console::write_line("Hello, World!");
  }
};

startup_(xtd_core_manual_test);
