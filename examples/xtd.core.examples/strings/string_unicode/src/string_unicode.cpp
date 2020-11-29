#include <xtd/xtd>

using namespace xtd;

int main() {
  auto arabic = u8"\u0627\u0644\u0643\u0644\u0645\u0629 \u0627\u0644\u0639\u0631\u0628\u064A\u0629";
  auto trad_chinese = u8"\u4E2D\u570B\u7684\u6F22\u5B57";
  auto simpl_chinese = u8"\u6C49\u8BED";
  auto french = u8"Langue fran\u00E7aise";
  auto greek = u8"\u0395\u03BB\u03BB\u03B7\u03BD\u03B9\u03BA\u03AE \u03B3\u03BB\u03CE\u03C3\u03C3\u03B1";
  auto hebrew = u8"\u05DB\u05EA\u05D1 \u05E2\u05D1\u05E8\u05D9\u05EA";
  auto hindi = u8"\u0939\u093f\u0928\u094d\u0926\u0940 \u092d\u093e\u0937\u093e";
  auto icelandic = u8"\u00CDslenska";
  auto japanese = u8"\u65E5\u672C\u8A9E\u306E\u3072\u3089\u304C\u306A, \u6F22\u5B57\u3068\u30AB\u30BF\u30AB\u30CA";
  auto korean = u8"\uB300\uD55C\uBBFC\uAD6D\uC758 \uD55C\uAE00";
  auto russian = u8"\u0420\u0443\u0441\u0441\u043A\u0438\u0439 \u044F\u0437\u044B\u043A";
  
  console::output_code_page(65001);
  console::write_line("Arabic:         {}", arabic);
  console::write_line("Trad. Chinese:  {}", trad_chinese);
  console::write_line("Simpl. Chinese: {}", simpl_chinese);
  console::write_line("French:         {}", french);
  console::write_line("Greek:          {}", greek);
  console::write_line("Hebrew:         {}", hebrew);
  console::write_line("Hindi:          {}", hindi);
  console::write_line("Icelandic:      {}", icelandic);
  console::write_line("Japanese:       {}", japanese);
  console::write_line("Korean:         {}", korean);
  console::write_line("Russian:        {}", russian);
}

// This code produces the following output:
//
// Arabic:         الكلمة العربية
// Trad. Chinese:  中國的漢字
// Simpl. Chinese: 汉语
// French:         Langue française
// Greek:          Ελληνική γλώσσα
// Hebrew:         כתב עברית
// Hindi:          हिन्दी भाषा
// Icelandic:      Íslenska
// Japanese:       日本語のひらがな, 漢字とカタカナ
// Korean:         대한민국의 한글
// Russian:        Русский язык
