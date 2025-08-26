#include <xtd/xtd>

auto main() -> int {
  auto stream = memory_stream {};
  auto  writer = web::css::css_writer {stream};
  
  writer.selectors()[".user_box"].properties()["display"] = web::css::property::from("none");
  writer.selectors()[".user_box"].properties()["position"] = web::css::property::from("fixed");
  writer.selectors()[".user_box"].properties()["z-index"] = web::css::property::from(100);
  writer.selectors()[".user_box"].properties()["width"] = web::css::property::from("100%");
  writer.selectors()[".user_box"].properties()["height"] = web::css::property::from("100%");
  writer.selectors()[".user_box"].properties()["left"] = web::css::property::from(300);
  writer.selectors()[".user_box"].properties()["top"] = web::css::property::from(200);
  writer.selectors()[".user_box"].properties()["background"] = web::css::property::from("#4080FA");
  writer.selectors()[".user_box"].properties()["filter"] = web::css::property::from("alpha(opacity=40)");
  writer.selectors()[".user_box"].properties()["opacity"] = web::css::property::from(0.4);
  writer.write();
  
  console::write_line("String stream :");
  console::write_line("---------------");
  stream.position(0);
  console::write_line(stream_reader(stream).read_to_end());
}

// This code produces the following output :
//
// String stream :
// ---------------
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
