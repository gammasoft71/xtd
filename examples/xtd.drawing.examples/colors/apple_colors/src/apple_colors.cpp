#include <xtd/xtd>

using namespace xtd::drawing;

auto format = "| {,-26} | {,-7} | {,-28} | {,-27} | {,-27} | {,-24} | {,-18} | {,-8} |";
auto print_line() {
  println(::format, string('-', 26), string('-', 7), string('-', 28), string('-', 27), string('-', 27), string('-', 24), string('-', 18), string('-', 8));
}
auto print_title() {
  print_line();
  println(::format, "Name", "Hex", "CMYK", "HSL", "HSV", "HTML", "RGB", "Win32");
  print_line();
}
auto print_color(const color& color) {
  println(::format, color.name(), color_translator::to_hex(color), color_translator::to_cmyk(color), color_translator::to_hsl(color), color_translator::to_hsv(color), color_translator::to_html(color), color_translator::to_rgb(color), string::format("0x{:x6}", color_translator::to_win32(color)));
}

auto main() -> int {
  print_title();
  for (auto color : apple_colors::get_colors())
    print_color(color);
  print_line();
}

// This code produces the following output :
//
// | -------------------------- | ------- | ---------------------------- | --------------------------- | --------------------------- | ------------------------ | ------------------ | -------- |
// | Name                       | Hex     | CMYK                         | HSL                         | HSV                         | HTML                     | RGB                | Win32    |
// | -------------------------- | ------- | ---------------------------- | --------------------------- | --------------------------- | ------------------------ | ------------------ | -------- |
// | apple_black                | #000000 | cmyk(0%, 0%, 0%, 100%)       | hsl(0, 0%, 0%)              | hsv(0, 0%, 0%)              | AppleBlack               | rgb(0, 0, 0)       | 0x000000 |
// | apple_blue                 | #0000ff | cmyk(100%, 100%, 0%, 0%)     | hsl(240, 100%, 50%)         | hsv(240, 100%, 100%)        | AppleBlue                | rgb(0, 0, 255)     | 0xff0000 |
// | apple_brown                | #996633 | cmyk(0%, 33%, 67%, 40%)      | hsl(30, 50%, 40%)           | hsv(30, 67%, 67%)           | AppleBrown               | rgb(153, 102, 51)  | 0x336699 |
// | apple_cyan                 | #21ffff | cmyk(87%, 0%, 0%, 0%)        | hsl(180, 100%, 56%)         | hsv(180, 87%, 87%)          | AppleCyan                | rgb(33, 255, 255)  | 0xffff21 |
// | apple_green                | #21ff06 | cmyk(87%, 0%, 98%, 0%)       | hsl(113, 100%, 51%)         | hsv(113, 98%, 98%)          | AppleGreen               | rgb(33, 255, 6)    | 0x06ff21 |
// | apple_magenta              | #fb02ff | cmyk(2%, 99%, 0%, 0%)        | hsl(299, 100%, 50%)         | hsv(299, 99%, 99%)          | AppleMagenta             | rgb(251, 2, 255)   | 0xff02fb |
// | apple_orange               | #fd8008 | cmyk(0%, 49%, 97%, 1%)       | hsl(29, 98%, 51%)           | hsv(29, 97%, 97%)           | AppleOrange              | rgb(253, 128, 8)   | 0x0880fd |
// | apple_purple               | #800080 | cmyk(0%, 100%, 0%, 50%)      | hsl(300, 100%, 25%)         | hsv(300, 100%, 100%)        | ApplePurple              | rgb(128, 0, 128)   | 0x800080 |
// | apple_red                  | #fb0207 | cmyk(0%, 99%, 97%, 2%)       | hsl(359, 98%, 50%)          | hsv(359, 99%, 99%)          | AppleRed                 | rgb(251, 2, 7)     | 0x0702fb |
// | apple_yellow               | #ffff0a | cmyk(0%, 0%, 96%, 0%)        | hsl(60, 100%, 52%)          | hsv(60, 96%, 96%)           | AppleYellow              | rgb(255, 255, 10)  | 0x0affff |
// | apple_white                | #ffffff | cmyk(0%, 0%, 0%, 0%)         | hsl(0, 0%, 100%)            | hsv(0, 0%, 0%)              | AppleWhite               | rgb(255, 255, 255) | 0xffffff |
// | -------------------------- | ------- | ---------------------------- | --------------------------- | --------------------------- | ------------------------ | ------------------ | -------- |
