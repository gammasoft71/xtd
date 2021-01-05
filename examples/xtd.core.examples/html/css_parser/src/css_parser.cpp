#include <xtd/xtd>

using namespace xtd;
using namespace xtd::html::css;

auto css_text =
".user_box {\n"
"  display: none;\n"
"  position: fixed;\n"
"  z-index: 100;\n"
"  width: 100%;\n"
"  height: 100%;\n"
"  left: 300;\n"
"  top: 200;\n"
"  background: #4080FA;\n"
"  filter: alpha(opacity=40);\n"
"  opacity: 0.4;\n"
"}";

void write_parser(const parser& parser) {
  for (auto selector : parser.selectors()) {
    console::write_line("{} {{", selector.first);
    for (auto property : selector.second.properties())
      xtd::console::write_line("  {}: {};", property.first, property.second);
    console::write_line("}");
  }
}

int main() {
  parser css_parser(css_text);

  console::write_line("Write all properties :");
  console::write_line("----------------------");
  write_parser(css_parser);
  console::write_line();

  console::write_line("Get specific properties :");
  console::write_line("-------------------------");
  console::write_line("opaicty = {}", css_parser.selectors().at(".user_box").properties().at("opacity").to_single());
  console::write_line("z-index = {}", css_parser.selectors().at(".user_box").properties().at("z-index").to_int32());
}

// This code can produces the following output :
//
// Write all properties :
// ----------------------
// .user_box {
//   background: #4080FA;
//   display: none;
//   filter: alpha(opacity=40);
//   height: 100%;
//   left: 300;
//   opacity: 0.4;
//   position: fixed;
//   top: 200;
//   width: 100%;
//   z-index: 100;
// }
//
// "Get specific properties :
// --------------------------
// opaicty = 0.4
// z-index = 100
