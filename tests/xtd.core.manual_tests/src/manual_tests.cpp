#include <csignal>
#include <xtd/xtd.core>
#include <xtd/xtd.drawing>

using namespace xtd;

auto main()->int {
  char* ptr = nullptr;
  *ptr = 'a';

  /*
  try {
    //raise(SIGSEGV);
    char* ptr = nullptr;
    *ptr = 'a';
  } catch(const system_exception& e) {
    console::write_line(e);
  }
   */
}
