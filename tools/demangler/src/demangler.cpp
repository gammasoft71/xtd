#include <xtd/io/stream_reader>
#include <xtd/io/stream_writer>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/guid>
#include <xtd/startup>

using namespace xtd;

namespace demangler {
  class program final static_ {
  public:
    static auto main(const argument_collection& args) {
      auto input_file = string::empty_string;
      auto output_file = string::empty_string;
      auto quiet = false;
      auto show_help = false;
      auto show_version = false;
      if (!process_arguments(args, input_file, output_file, quiet, show_version, show_help)) {
        console::write_line(get_error());
        return as<int>(exit_status::failure);
      }
      
      if (show_version) {
        console::write_line(get_version());
        return as<int>(exit_status::success);
      }
      
      if (show_help) {
        console::write_line("{0}{1}{1}{2}", get_version(), environment::new_line(), get_usage());
        return as<int>(exit_status::success);
      }
      
      auto sr = io::stream_reader(input_file);
      auto sw = ptr<io::stream_writer> {};
      if (!xtd::string::is_empty(output_file)) sw = new_ptr<io::stream_writer>(output_file);
      while (!sr.end_of_stream()) {
        auto words = sr.read_line().split(' ');
        for (auto& word : words)
          word = string::demangle(word);
        auto str = string::join(" ", words);
        if (sw) sw->write_line(str);
        if (!quiet) console::write_line(str);
      }
      return as<int>(exit_status::success);
    }
    
  private:
    static auto get_error() noexcept -> string {
      return "demangler : invalid params\n"
             "Try 'demangler --help' for more information.";
    }
    
    static auto get_usage() noexcept -> string {
      return "Usage\n"
             "  demangler stack_trace_file [–o output_demangled_file]\n"
             "\n"
             "-o, --output  : Write result in output_demangled_file.\n"
             "-q, --quiet   : Do not write result on stdout.\n"
             "-v, --version : Shows version information.\n"
             "-h, --help    : Shows this help page.";
    }
    
    static auto get_version() noexcept -> string {
      return string::format("demangler version {}, (c) {} by Gammasoft", environment::version(), date_time::now().year());
    }
    
    static auto process_arguments(const array<string>& args, string& input_file, string& output_file, bool& quiet, bool& show_version, bool& show_help) noexcept -> bool {
      try {
        for (auto index = 0_z; index < args.length(); index += 1)
          if (args[index] == "-v" || args[index] == "--version") show_version = true;
          else if (args[index] == "-h" || args[index] == "--help") show_help = true;
          else if ((args[index] == "-o" || args[index] == "--output") && index < args.length()) output_file = args[++index];
          else if ((args[index] == "-q" || args[index] == "--quiet")) quiet = true;
          else input_file = args[index];
          
        return show_help || show_version || !xtd::string::is_empty(input_file);
      } catch (...) {
        return false;
      }
    }
  };
}

startup_(demangler::program::main);
