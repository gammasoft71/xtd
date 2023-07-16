#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>

using namespace xtd;

namespace environment_cancel_sgnal_example {
  class program static_ {
  public:
    // The main entry point for the application.
    static auto main() {
      environment::cancel_signal += [](signal_cancel_event_args& e) {
        console::write_line("A {} signal occured!", e.signal());
        e.cancel(cancel);
      };

      show_help();
      
      console::treat_control_c_as_input(true);
      while (true) {
        if (console::key_available()) {
          auto key_info = console::read_key(true);
          if (key_info.modifiers() == console_modifiers::none && key_info.key() == console_key::escape) exit();
          else if (key_info.modifiers() == console_modifiers::control && key_info.key() == console_key::c) generate_signal(signal::interrupt);
          else switch (key_info.key_char()) {
            case 'a':  generate_signal(signal::abnormal_termination); break;
            case 'c': generate_signal(signal::interrupt); break;
            case 'e': exit(); break;
            case 'f': generate_signal(signal::floating_point_exception); break;
            case 'h': show_help(); break;
            case 'i': generate_signal(signal::illegal_instruction); break;
            case 't': generate_signal(signal::software_termination); break;
            case 'u': cancel = !cancel; show_help(); break;
            case 'v': generate_signal(signal::segmentation_violation); break;
            default: break;
          }
        }
      }
    }

  private:
    static void exit() {
      console::write_line("Exit");
      environment::exit(exit_status::success);
    }
    
    static void generate_signal(xtd::signal signal) {
      console::write_line("Generate {} signal", signal);
      environment::raise(signal);
    }

    static void show_help() {
      console::clear();
      console::write_line("Select a key :");
      console::write_line("  a : Generate abort signal");
      console::write_line("  c : (or ctrl-c) Generate interrupt signal");
      console::write_line("  e : (or Escape) Exit example");
      console::write_line("  f : Generate floating point exception signal");
      console::write_line("  h : Display this help");
      console::write_line("  i : Generate illegal instruction signal");
      console::write_line("  t : Generate software termination signal");
      console::write_line("  u : Update cancel signal status");
      console::write_line("  v : Generate segmentation violation signal");
      console::write_line("The signal will {}be cancelled!", cancel ? "" : "not ");
    }

    inline static bool cancel = true;
  };
}

startup_(environment_cancel_sgnal_example::program);

// This code produces the following output :
//
// Select a key :
//   a : Generate abort signal
//   c : (or ctrl-c) Generate interrupt signal
//   e : (or Escape) Exit example
//   f : Generate floating point exception signal
//   h : Display this help
//   i : Generate illegal instruction signal
//   t : Generate software termination signal
//   u : Update cancel signal status
//   v : Generate segmentation violation signal
// The signal will be cancelled!
