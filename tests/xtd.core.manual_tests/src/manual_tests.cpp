#include <codecvt>
#include <xtd/xtd.core>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

class xtd_core_manual_test {
public:
  static void main() {
    //console::write(stream_reader(process::start(process_start_info("xtdc", "--help").use_shell_execute(false).redirect_standard_output(true)).standard_output()).read_to_end());
    
    auto s = std::string("Hello, World!");
    auto ws = std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().from_bytes(s);
    auto u16s = std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t>().from_bytes(s);
    auto u32s = std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>().from_bytes(s);
    wconsole::write_line(ws);
  }
};

startup_(xtd_core_manual_test);
