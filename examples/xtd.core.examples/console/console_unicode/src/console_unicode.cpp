#include <xtd/xtd>

auto main() -> int {
  // Change current code page to UTF-8.
  console::output_code_page(65001);
  
  // Create a Char array for the modern Cyrillic alphabet, from U+0410 to U+044F.
  constexpr auto nchars = 0x044F - 0x0410 + 1;
  auto chars = list<char32_t> {nchars};
  auto code_point = U'\U00000410';
  for (auto ctr = 0_z; ctr < chars.size(); ctr++) {
    chars[ctr] = code_point;
    code_point++;
  }
  
  console::write_line("Current code page: {}\n", console::output_code_page());
  // Display the characters.
  for (auto ch : chars) {
    console::write("{0}  ", ch);
    if (console::cursor_left() >= 70)
      console::write_line();
  }
  console::write_line();
}

// This code produces the following output :
//
// Current code page: 65001
//
// А  Б  В  Г  Д  Е  Ж  З  И  Й  К  Л  М  Н  О  П  Р  С  Т  У  Ф  Х  Ц  Ч
// Ш  Щ  Ъ  Ы  Ь  Э  Ю  Я  а  б  в  г  д  е  ж  з  и  й  к  л  м  н  о  п
// р  с  т  у  ф  х  ц  ч  ш  щ  ъ  ы  ь  э  ю  я
