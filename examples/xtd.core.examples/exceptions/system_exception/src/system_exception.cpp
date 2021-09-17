#include <xtd/xtd>

using namespace xtd;

intptr_t create_handle() {
  return reinterpret_cast<intptr_t>(new guid());
}

void destroy_handle(intptr_t handle) {
  if (handle == 0) throw system_exception("The handle is null",  csf_);
  delete reinterpret_cast<object*>(handle);
}

int main() {
  try {
    intptr_t handle = 0;
    // The following line is commented out so that the exception is generated.
    //handle = create_handle();

    destroy_handle(handle);
  } catch(const system_exception& e) {
    console::write_line("Exception occured :");
    console::write_line("-------------------");
    console::write_line(e);
  }
}

// This code can produces the following output :
//
// Exception occured :
// -------------------
// xtd::system_exception : The handle is null
//    at destroy_handle(long) [0x00004B20] in /|---OMITTED---|/system_exception/src/system_exception.cpp:line 10
//    at main [0x00004DD0] in /|---OMITTED---|/system_exception/Debug/system_exception:line 0
