#include <xtd/xtd>

auto main() -> int {
  auto s = "💾 My string 😎 🐨";
  
  auto s1 = as<string>(s);
  println("s1 ({}) -> {} has {} chars", type_of(s1), s1.quoted(), s1.length());
  auto s2 = as<u32string>(s);
  println("s2 ({}) -> {} has {} chars", type_of(s2), s2.quoted(), s2.length());
  auto s3 = as<u16string>(s);
  println("s3 ({}) -> {} has {} chars", type_of(s3), s3.quoted(), s3.length());
  auto s4 = as<u8string>(s);
  println("s4 ({}) -> {} has {} chars", type_of(s4), s4.quoted(), s4.length());
  auto s5 = as<wstring>(s);
  println("s5 ({}) -> {} has {} chars", type_of(s5), s4.quoted(), s5.length());
  println();
  
  auto u16s = u"💾 My string 😎 🐨";
  
  auto s6 = as<string>(u16s);
  println("s6 ({}) -> {} has {} chars", type_of(s6), s6.quoted(), s6.length());
  auto s7 = as<u32string>(u16s);
  println("s7 ({}) -> {} has {} chars", type_of(s7), s7.quoted(), s7.length());
  auto s8 = as<u16string>(u16s);
  println("s8 ({}) -> {} has {} chars", type_of(s8), s8.quoted(), s8.length());
  auto s9 = as<u8string>(u16s);
  println("s9 ({}) -> {} has {} chars", type_of(s9), s9.quoted(), s9.length());
  auto s10 = as<wstring>(u16s);
  println("s10 ({}) -> {} has {} chars", type_of(s10), s10.quoted(), s10.length());
  println();
  
  auto u32s = U"💾 My string 😎 🐨";
  
  auto s11 = as<string>(u32s);
  println("s11 ({}) -> {} has {} chars", type_of(s11), s11.quoted(), s11.length());
  auto s12 = as<u32string>(u32s);
  println("s12 ({}) -> {} has {} chars", type_of(s12), s12.quoted(), s12.length());
  auto s13 = as<u16string>(u32s);
  println("s13 ({}) -> {} has {} chars", type_of(s13), s13.quoted(), s13.length());
  auto s14 = as<u8string>(u32s);
  println("s14 ({}) -> {} has {} chars", type_of(s14), s14.quoted(), s14.length());
  auto s15 = as<wstring>(u32s);
  println("s15 ({}) -> {} has {} chars", type_of(s15), s15.quoted(), s15.length());
  println();
  
  auto u8s = u8"💾 My string 😎 🐨";
  
  auto s16 = as<string>(u8s);
  println("s16 ({}) -> {} has {} chars", type_of(s16), s16.quoted(), s16.length());
  auto s17 = as<u32string>(u8s);
  println("s17 ({}) -> {} has {} chars", type_of(s17), s17.quoted(), s17.length());
  auto s18 = as<u16string>(u8s);
  println("s18 ({}) -> {} has {} chars", type_of(s18), s18.quoted(), s18.length());
  auto s19 = as<u8string>(u8s);
  println("s19 ({}) -> {} has {} chars", type_of(s19), s14.quoted(), s19.length());
  auto s20 = as<wstring>(u8s);
  println("s20 ({}) -> {} has {} chars", type_of(s20), s20.quoted(), s20.length());
  println();
  
  auto ws = L"💾 My string 😎 🐨";
  
  auto s21 = as<string>(ws);
  println("s21 ({}) -> {} has {} chars", type_of(s21), s21.quoted(), s21.length());
  auto s22 = as<u32string>(ws);
  println("s22 ({}) -> {} has {} chars", type_of(s22), s22.quoted(), s22.length());
  auto s23 = as<u16string>(ws);
  println("s23 ({}) -> {} has {} chars", type_of(s23), s23.quoted(), s23.length());
  auto s24 = as<u8string>(ws);
  println("s24 ({}) -> {} has {} chars", type_of(s24), s24.quoted(), s24.length());
  auto s25 = as<wstring>(ws);
  println("s25 ({}) -> {} has {} chars", type_of(s25), s25.quoted(), s25.length());
}

// This code produces the following output :
//
// s1 (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) -> "💾 My string 😎 🐨" has 24 chars
// s2 (xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>) -> "💾 My string 😎 🐨" has 15 chars
// s3 (xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>) -> "💾 My string 😎 🐨" has 18 chars
// s4 (xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>) -> "💾 My string 😎 🐨" has 24 chars
// s5 (xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>) -> "💾 My string 😎 🐨" has 15 chars
//
// s6 (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) -> "💾 My string 😎 🐨" has 24 chars
// s7 (xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>) -> "💾 My string 😎 🐨" has 15 chars
// s8 (xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>) -> "💾 My string 😎 🐨" has 18 chars
// s9 (xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>) -> "💾 My string 😎 🐨" has 24 chars
// s10 (xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>) -> "💾 My string 😎 🐨" has 15 chars
//
// s11 (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) -> "💾 My string 😎 🐨" has 24 chars
// s12 (xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>) -> "💾 My string 😎 🐨" has 15 chars
// s13 (xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>) -> "💾 My string 😎 🐨" has 18 chars
// s14 (xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>) -> "💾 My string 😎 🐨" has 24 chars
// s15 (xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>) -> "💾 My string 😎 🐨" has 15 chars
//
// s16 (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) -> "💾 My string 😎 🐨" has 24 chars
// s17 (xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>) -> "💾 My string 😎 🐨" has 15 chars
// s18 (xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>) -> "💾 My string 😎 🐨" has 18 chars
// s19 (xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>) -> "💾 My string 😎 🐨" has 24 chars
// s20 (xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>) -> "💾 My string 😎 🐨" has 15 chars
//
// s21 (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) -> "💾 My string 😎 🐨" has 24 chars
// s22 (xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>) -> "💾 My string 😎 🐨" has 15 chars
// s23 (xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>) -> "💾 My string 😎 🐨" has 18 chars
// s24 (xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>) -> "💾 My string 😎 🐨" has 24 chars
// s25 (xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>) -> "💾 My string 😎 🐨" has 15 chars
