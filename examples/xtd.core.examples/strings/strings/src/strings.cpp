#include <xtd/console>

using namespace xtd;

auto main() -> int {
  console::write_line("string =   \"{}\"", string {  "Hello, World!\U0001F603"});
  console::write_line("string = u8\"{}\"", string {u8"Hello, World!\U0001F603"});
  console::write_line("string =  u\"{}\"", string { u"Hello, World!\U0001F603"});
  console::write_line("string =  U\"{}\"", string { U"Hello, World!\U0001F603"});
  console::write_line("string =  L\"{}\"", string { L"Hello, World!\U0001F603"});
  console::write_line();
  
  console::write_line("u16string =   \"{}\"", u16string {  "Hello, World!\U0001F603"});
  console::write_line("u16string = u8\"{}\"", u16string {u8"Hello, World!\U0001F603"});
  console::write_line("u16string =  u\"{}\"", u16string { u"Hello, World!\U0001F603"});
  console::write_line("u16string =  U\"{}\"", u16string { U"Hello, World!\U0001F603"});
  console::write_line("u16string =  L\"{}\"", u16string { L"Hello, World!\U0001F603"});
  console::write_line();
  
  console::write_line("u32string =   \"{}\"", u32string {  "Hello, World!\U0001F603"});
  console::write_line("u32string = u8\"{}\"", u32string {u8"Hello, World!\U0001F603"});
  console::write_line("u32string =  u\"{}\"", u32string { u"Hello, World!\U0001F603"});
  console::write_line("u32string =  U\"{}\"", u32string { U"Hello, World!\U0001F603"});
  console::write_line("u32string =  L\"{}\"", u32string { L"Hello, World!\U0001F603"});
  console::write_line();
  
  console::write_line("u8string =   \"{}\"", u8string {  "Hello, World!\U0001F603"});
  console::write_line("u8string = u8\"{}\"", u8string {u8"Hello, World!\U0001F603"});
  console::write_line("u8string =  u\"{}\"", u8string { u"Hello, World!\U0001F603"});
  console::write_line("u8string =  U\"{}\"", u8string { U"Hello, World!\U0001F603"});
  console::write_line("u8string =  L\"{}\"", u8string { L"Hello, World!\U0001F603"});
  console::write_line();

  console::write_line("wstring =   \"{}\"", wstring {  "Hello, World!\U0001F603"});
  console::write_line("wstring = u8\"{}\"", wstring {u8"Hello, World!\U0001F603"});
  console::write_line("wstring =  u\"{}\"", wstring { u"Hello, World!\U0001F603"});
  console::write_line("wstring =  U\"{}\"", wstring { U"Hello, World!\U0001F603"});
  console::write_line("wstring =  L\"{}\"", wstring { L"Hello, World!\U0001F603"});
  console::write_line();
}

// This code produces the following output :
//
// string =   "Hello, World!😃"
// string = u8"Hello, World!😃"
// string =  u"Hello, World!😃"
// string =  U"Hello, World!😃"
// string =  L"Hello, World!😃"
//
// u16string =   "Hello, World!😃"
// u16string = u8"Hello, World!😃"
// u16string =  u"Hello, World!😃"
// u16string =  U"Hello, World!😃"
// u16string =  L"Hello, World!😃"
//
// u32string =   "Hello, World!😃"
// u32string = u8"Hello, World!😃"
// u32string =  u"Hello, World!😃"
// u32string =  U"Hello, World!😃"
// u32string =  L"Hello, World!😃"
//
// u8string =   "Hello, World!😃"
// u8string = u8"Hello, World!😃"
// u8string =  u"Hello, World!😃"
// u8string =  U"Hello, World!😃"
// u8string =  L"Hello, World!😃"
//
// wstring =   "Hello, World!😃"
// wstring = u8"Hello, World!😃"
// wstring =  u"Hello, World!😃"
// wstring =  U"Hello, World!😃"
// wstring =  L"Hello, World!😃"
