#include <xtd/xtd>

auto create_handle() -> intptr {
  return reinterpret_cast<intptr>(new guid());
}

auto destroy_handle(intptr handle) -> void {
  if (handle == 0) throw system_exception("The handle is null");
  delete reinterpret_cast<object*>(handle);
}

auto main() -> int {
  try {
    auto handle = 0l;
    // The following line is commented out so that the exception is generated.
    //handle = create_handle();
    
    destroy_handle(handle);
  } catch (const system_exception& e) {
    console::write_line("Exception occured :");
    console::write_line("-------------------");
    console::write_line(e);
  }
}

// This code can produce the following output :
//
// Exception occured :
// -------------------
// xtd::system_exception : The handle is null
//    at xtd::system_exception::system_exception(std::__1::optional<xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>> const&, xtd::diagnostics::stack_frame const&) in system_exception.cpp:line 12
//    at destroy_handle(long) in system_exception.cpp:line 8
//    at main in system_exception.cpp:line 18
