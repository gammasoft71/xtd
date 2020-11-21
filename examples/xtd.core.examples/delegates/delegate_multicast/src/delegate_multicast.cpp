#define TRACE
#include <xtd/xtd.core>

using namespace std;
using namespace xtd;

using write = delegate<void(const string& str)>;

void write_debug(const string& str) {
  cdebug << str << environment::new_line;
}

class tracer {
public:
  void write_trace(const string& str) {
    ctrace << str << environment::new_line;
  }

  void write_trace2(const string& str) {
    ctrace << "2 " << str << environment::new_line;
  }
};

int main() {
  ::write write;

  write += [](const string& str)  {
    console::out << str << environment::new_line;
  };
  
  write += [](auto str)  {
    console::error << str << environment::new_line;
  };
  
  write += write_debug;
  write += {tracer(), &tracer::write_trace};

  tracer t;
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

// This code produces the following output:
//
// Value to write
// Value to write
// Value to write
// Value to write
// Value to write
