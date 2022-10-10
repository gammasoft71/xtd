#include <xtd/xtd.core>
#include <xtd/xtd.forms.h>

using namespace std;
using namespace xtd;

class xtd_core_manual_test {
public:
  static void main() {
    console::write_line("{}", char_object::is_punctuation('.'));
    console::write_line("{}", char8_object::is_punctuation(u8'.'));
    console::write_line("{}", char16_object::is_punctuation(u'.'));
    console::write_line("{}", char32_object::is_punctuation(U'.'));
    console::write_line("{}", wchar_object::is_punctuation(L'.'));
    console::write_line("{}", char_object::is_punctuation(".", 0));
    console::write_line("{}", char8_object::is_punctuation(u8".", 0));
    console::write_line("{}", char16_object::is_punctuation(u".", 0));
    console::write_line("{}", char32_object::is_punctuation(U".", 0));
    console::write_line("{}", wchar_object::is_punctuation(L".", 0));
    console::write_line("{}", char_object::is_punctuation('a'));
    console::write_line("{}", char8_object::is_punctuation(u8'a'));
    console::write_line("{}", char16_object::is_punctuation(u'a'));
    console::write_line("{}", char32_object::is_punctuation(U'a'));
    console::write_line("{}", wchar_object::is_punctuation(L'a'));
    console::write_line("{}", char_object::is_punctuation("a", 0));
    console::write_line("{}", char8_object::is_punctuation(u8"a", 0));
    console::write_line("{}", char16_object::is_punctuation(u"a", 0));
    console::write_line("{}", char32_object::is_punctuation(U"a", 0));
    console::write_line("{}", wchar_object::is_punctuation(L"a", 0));
  }
};

startup_(xtd_core_manual_test);
