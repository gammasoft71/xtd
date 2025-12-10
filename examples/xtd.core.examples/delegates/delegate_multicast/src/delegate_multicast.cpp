#define TRACE 1 // Force to trace even if example is builded with -DNTRACE.
#include <xtd/xtd>

using writer = delegate<void(const string& str)>;

auto write_debug(const string& str) -> void {
  cdebug << str << environment::new_line << std::flush;
}

class tracer {
public:
  auto write_trace(const string& str) -> void {
    ctrace << str << environment::new_line << std::flush;
  }
  
  auto write_trace2(const string& str) -> void {
    ctrace << "2 " << str << environment::new_line << std::flush;
  }
};

auto main() -> int {
  auto write = writer {};
  
  write += delegate_(const string & str)  {
    console::out << str << environment::new_line;
  };
  
  write += delegate_(auto str)  {
    console::error << str << environment::new_line;
  };
  
  write += write_debug;
  write += {tracer(), &tracer::write_trace};
  
  auto t = tracer {};
  write += {t, &tracer::write_trace2}; // add
  write -= {t, &tracer::write_trace2}; // then remove
  
  struct writer {
    writer() = default;
    void operator()(const string& str) {
      console::write_line(str);
    }
  };
  
  write += writer();
  
  write("Value to write");
}

// This code produces the following output :
//
// Value to write
// Value to write
// Value to write
// Value to write
// Value to write
