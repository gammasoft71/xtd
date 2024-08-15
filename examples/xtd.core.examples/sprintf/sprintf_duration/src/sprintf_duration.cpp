#include <xtd/xtd>

using namespace xtd;

int main() {
  console::out << string::sprintf("%s", (26_h + 3_min + 32_s + 24_ms + 500_ns).to_string("")) << environment::new_line;
  console::out << string::sprintf("%s", (26_h + 3_min + 32_s + 24_ms + 500_ns).to_string("G")) << environment::new_line;
  auto duration = 2_h + 3_min + 32_s + 24_ms + 500_ns;
  console::out << string::sprintf("%s", duration.to_string("F")) << environment::new_line;
  console::out << string::sprintf("%s:%s", duration.to_string("H"), duration.to_string("M")) << environment::new_line;
  console::out << string::sprintf("%s:%s:%s:%s", duration.to_string("H"), duration.to_string("M"), duration.to_string("S"), duration.to_string("T")) << environment::new_line;
  console::out << string::sprintf("%s:%s:%s:%s", duration.to_string("h"), duration.to_string("m"), duration.to_string("s"), duration.to_string("t")) << environment::new_line;
}

// This code produces the following output :
//
// 1.02:03:32.0240005
// 1.02:03:32.0240005
// 0.02:03:32.0240005
// 02:03
// 02:03:32:0240005
// 2:3:32:240005
