#include <xtd/xtd>

using namespace xtd;
using namespace xtd::web::css;

void write_selectors(const selector_map& selectors) {
  for (auto [name, contents] : selectors) {
    console::write_line("{} {{", name);
    for (auto [key, value] : contents.properties())
      xtd::console::write_line("  {}: {};", key, value);
    console::write_line("}");
  }
}

int main() {
  reader css_reader(".user_box {\n"
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
                    "}");

  console::write_line("Write all selectors and all properties :");
  console::write_line("----------------------------------------");
  write_selectors(css_reader.selectors());
  console::write_line();

  console::write_line("Get specific properties :");
  console::write_line("-------------------------");
  console::write_line("filter = {}", css_reader.selectors().at(".user_box").properties().at("filter"));
  console::write_line("opacity = {}", css_reader.selectors().at(".user_box").properties().at("opacity").to_single());
  console::write_line("z-index = {}", css_reader.selectors().at(".user_box").properties().at("z-index").to<int32_t>());
}

// This code can produces the following output :
//
// Write all selectors and all properties :
// ----------------------------------------
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
// Get specific properties :
// -------------------------
// filter = alpha(opacity=40)
// opaicty = 0.4
// z-index = 100
