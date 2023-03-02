#include <csignal>
#include <xtd/xtd.core>
#include <xtd/xtd.drawing>

using namespace xtd;

class program {
public:
  static void main() {
    //raise(SIGSEGV);
    //char* ptr = nullptr;
    //*ptr = 'a';

    environment::cancel_signal += [](signal_cancel_event_args& e) {
      console::write_line("{} signal canceled", e.signal());
      e.cancel(true);
    };

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
