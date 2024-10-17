#include <xtd/console>
#include <xtd/exception>

using namespace xtd;
using namespace xtd::diagnostics;

namespace user_defined_exception {
  class employee_list_not_found_exception : public exception {
  public:
    employee_list_not_found_exception(const stack_frame& sf = stack_frame::current()) : exception {"The employee list does not exist."_t, sf} {
    }
    
    employee_list_not_found_exception(const string& message, const stack_frame& sf = stack_frame::current()) : exception {message, sf} {
    }
    
    template<typename exception_t>
    employee_list_not_found_exception(const string& message, const exception_t& inner, const stack_frame& sf = stack_frame::current()) : exception {message, inner, sf} {
    }
  };
}

auto main() -> int {
  try {
    throw user_defined_exception::employee_list_not_found_exception {};
  } catch(const exception& e) {
    console::write_line("type              = {}", e.get_type());
    console::write_line("help_link         = {}", e.help_link());
    console::write_line("h_result          = 0x{0:X8} ({0})", static_cast<uint>(e.h_result()));
    console::write_line("inner_exception   = {}", e.inner_exception());
    console::write_line("message           = {}", e.message());
    console::write_line("source            = {}", e.source());
    console::write_line("stack_trace       = {}", e.stack_trace());
  }
}

// This code can produce the following output :
//
// type              = user_defined_exception::employee_list_not_found_exception
// help_link         =
// h_result          = 0x80131500 (2148734208)
// inner_exception   = (null)
// message           = The employee list does not exist.
// source            = user_defined_exception
// stack_trace       =    at main [0x0000665C] in /!---OMITTED---!/user_defined_exception/src/user_defined_exception.cpp:line 24
