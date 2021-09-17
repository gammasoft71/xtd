#define TRACE
#include <xtd/xtd>

using namespace std;
using namespace xtd;

using write = delegate<void(const ustring& str)>;

void write_debug(const ustring& str) {
  cdebug << str << environment::new_line;
}

class tracer {
public:
  void write_trace(const ustring& str) {
    ctrace << str << environment::new_line;
  }

  void write_trace2(const ustring& str) {
    ctrace << "2 " << str << environment::new_line;
  }
};

int main() {
  ::write write;

  write += [](const ustring& str)  {
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
    void operator()(const ustring& str) {
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
