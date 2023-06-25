#include <xtd/xtd>

using namespace xtd;

namespace environment_cancel_sgnal_example {
  class program {
  public:
    inline static bool cancel = true;
    // The main entry point for the application.
    static auto main() {
      environment::cancel_signal += [&](signal_cancel_event_args& e) {
        switch (e.signal()) {
          case xtd::signal::abnormal_termination: console::write_line("An abnormal termination signal occured!"); break;
          case xtd::signal::floating_point_exception: console::write_line("A floating point exception signal occured!"); break;
          case xtd::signal::interrupt: console::write_line("An interrupt signal occured!"); break;
          case xtd::signal::segmentation_violation: console::write_line("A segmentation violation signal occured!"); break;
          default: console::write_line("A {} signal occured!", e.signal()); break;
        }
        e.cancel(cancel);
        //e.cancel(e.signal() == xtd::signal::interrupt || e.signal() == xtd::signal::floating_point_exception);
      };

      //console::treat_control_c_as_input(true);
      show_help();
      
      while (true) {
        if (console::key_available()) {
          console_key_info key_info = console::read_key(true);
          switch (key_info.key()) {
            case console_key::a: generate_abort_signal(); break;
            case console_key::c: generate_interrupt_signal(); break;
           case console_key::escape:
            case console_key::e: exit(); break;
            case console_key::f: generate_floating_point_exceptiont_signal(); break;
            case console_key::h: show_help(); break;
            case console_key::i: generate_illegal_instruction_signal(); break;
            case console_key::t: generate_software_termination_signal(); break;
            case console_key::u: cancel = !cancel; show_help(); break;
            case console_key::v: generate_segmentation_violation_signal(); break;
            default: break;
          }
        }
      }
    }

    static void exit() {
      console::write_line("Exit");
      environment::exit(EXIT_SUCCESS);
    }
    
    static void generate_abort_signal() {
      console::write_line("Generate abort signal");
      // raise(SIGABRT);
      abort();
    }
    
    static void generate_floating_point_exceptiont_signal() {
      console::write_line("Generate floating point exception signal");
      raise(SIGFPE);
    }
    
    static void generate_illegal_instruction_signal() {
      console::write_line("Generate illegal instruction signal");
      raise(SIGILL);
    }
    
    static void generate_interrupt_signal() {
      console::write_line("Generate interrupt signal");
      raise(SIGINT);
    }
    
    static void generate_segmentation_violation_signal() {
      console::write_line("Generate segmentation violation signal");
      // raise(SIGSEGV);
      char* ptr = nullptr;
      *ptr = 'a';
    }
    
    static void generate_software_termination_signal() {
      console::write_line("Generate software termination signal");
      raise(SIGTERM);
    }
    
    static void show_help() {
      console::clear();
      console::write_line("Select a key :");
      console::write_line("  a           : Generate abort signal");
      console::write_line("  c or ctrl-c : Generate interrupt signal");
      console::write_line("  e or Escape : Exit example");
      console::write_line("  f           : Generate floating point exception signal");
      console::write_line("  h           : Display this help");
      console::write_line("  i           : Generate illegal instruction signal");
      console::write_line("  t           : Generate software termination signal");
      console::write_line("  u           : Update cancel signal status");
      console::write_line("  v           : Generate segmentation violation signal");
      console::write_line("The signal will {}be cancelled!", cancel ? "" : "not ");
    }
  };
}

startup_(environment_cancel_sgnal_example::program);

// This code produces the following output :
//
