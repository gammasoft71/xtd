#include <xtd/xtd.core>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

class xtd_core_manual_test {
public:
  static void main() {
    console::write_line("Start app");
    
    trace_listener_collection tls;
    tls.push_back(make_shared<default_trace_listener>());
    tls.push_back(make_shared<console_trace_listener>());

    console::write_line();
    console::write_line("foreach : ");
    for (auto tl : tls)
      tl->write_line("Hello, world!");

    console::write_line();
    console::write_line("index operator : ");
    tls[0]->write_line("Hello, world!");
    tls[1]->write_line("Hello, world!");

    console::write_line();
    console::write_line("name operator : ");
    if (tls["default"]) tls["default"]->write_line("Hello, world!");
    if (tls["console"]) tls["console"]->write_line("Hello, world!");
    if (tls["Console"]) tls["Console"]->write_line("Hello, world!");

    console::write_line();
    
    console::write_line("End app");
  }
};

startup_(xtd_core_manual_test);
