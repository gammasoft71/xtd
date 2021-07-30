#include <xtd/xtd.core>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

class xtd_core_manual_test : public object {
public:
  static void main() {
    auto str = U"Hello, "_s + u"world!";
    str = str.to_upper();
    
    console::write_line(str);
    console::write_line("{}", "One"_s == U"Two");
    auto ufile = u8"élève 🐨.txt"_s;
    auto file = convert_string::to_string(ufile);
    auto u8file = convert_string::to_u8string(ufile);
    auto u16file = convert_string::to_u16string(ufile);
    auto u32file = convert_string::to_u32string(ufile);
    auto wfile = convert_string::to_wstring(ufile);
    console::write_line(io::file::read_all_text(io::path::combine(environment::get_folder_path(environment::special_folder::desktop), u32file)));
  }
};

startup_(xtd_core_manual_test);
