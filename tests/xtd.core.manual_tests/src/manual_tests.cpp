#include <csignal>
#include <xtd/xtd.core>
#include <xtd/xtd.drawing>

using namespace xtd;

class program {
public:
  static void on_cancel_abnormal_termination(signal_cancel_event_args& e) {
    console::write_line("Abort signal canceled");
    e.cancel(true);
  }
  
  static void on_cancel_floating_point_exception(signal_cancel_event_args& e) {
    console::write_line("Floating point exception signal canceled");
    e.cancel(true);
  }
  
  static void on_cancel_illegal_instruction(signal_cancel_event_args& e) {
    console::write_line("Software illegal instruction signal canceled");
    e.cancel(true);
  }
  
  static void on_cancel_software_termination(signal_cancel_event_args& e) {
    console::write_line("Software termination signal canceled");
    e.cancel(true);
  }

  static void on_cancel_interrupt(signal_cancel_event_args& e) {
    console::write_line("Interrupt signal canceled");
    e.cancel(true);
  }
  
  static void on_cancel_segmentation_violation(signal_cancel_event_args& e) {
    console::write_line("Segmentation violation signal canceled");
    e.cancel(true);
  }

  static void main() {
    //raise(SIGSEGV);
    //char* ptr = nullptr;
    //*ptr = 'a';

    environment::cancel_abnormal_termination += on_cancel_abnormal_termination;
    environment::cancel_floating_point_exception += on_cancel_floating_point_exception;
    environment::cancel_illegal_instruction += on_cancel_illegal_instruction;
    environment::cancel_interrupt += on_cancel_interrupt;
    environment::cancel_segmentation_violation += on_cancel_segmentation_violation;
    environment::cancel_software_termination += on_cancel_software_termination;

    console::write_line("Raise SIGABRT");
    raise(SIGABRT);
    console::write_line("After SIGABRT");
    console::write_line();
    console::write_line("Raise SIGFPE");
    raise(SIGFPE);
    console::write_line("After SIGFPE");
    console::write_line();
    console::write_line("Raise SIGILL");
    raise(SIGILL);
    console::write_line("After SIGILL");
    console::write_line();
    console::write_line("Raise SIGINT");
    raise(SIGINT);
    console::write_line("After SIGINT");
    console::write_line();
    console::write_line("Raise SIGSEGV");
    raise(SIGSEGV);
    console::write_line("After SIGSEGV");
    console::write_line();
    console::write_line("Raise SIGTERM");
    raise(SIGTERM);
    console::write_line("After SIGTERM");
  }
};

startup_(program);

/*
auto main()->int {
  //raise(SIGSEGV);
  char* ptr = nullptr;
  *ptr = 'a';
  
   try {
   //raise(SIGSEGV);
   // char* ptr = nullptr;
   // *ptr = 'a';
   } catch(const system_exception& e) {
   console::write_line(e);
   }
}
*/
