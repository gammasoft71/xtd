#include <xtd/as>
#include <xtd/console>
#include <xtd/convert>
#include <xtd/convert_string>
#include <any>

using namespace std;
using namespace xtd;

auto main() -> int {
  console::write_line("Convert int to ustring :");
  console::write_line("------------------------");
  auto value = 42;
  console::write_line("to_ustring(value)            = {}", to_ustring(value));
  console::write_line("as<ustring>(value)           = {}", as<ustring>(value));
  console::write_line("convert::to_ustring(value)   = {}", convert::to_ustring(value));
  console::write_line("ustring::format(\"{{}}\", value) = {}", ustring::format("{}", value));
  console::write_line();
  
  console::write_line("Convert float to ustring :");
  console::write_line("--------------------------");
  auto float_value = 42.5f;
  console::write_line("to_ustring(float_value)            = {}", to_ustring(float_value));
  console::write_line("as<ustring>(float_value)           = {}", as<ustring>(float_value));
  console::write_line("convert::to_ustring(float_value)   = {}", convert::to_ustring(float_value));
  console::write_line("ustring::format(\"{{}}\", float_value) = {}", ustring::format("{}", float_value));
  console::write_line();
  
  console::write_line("Convert any to ustring :");
  console::write_line("------------------------");
  auto any_value = make_any<int>(42);
  console::write_line("to_ustring(any_value)            = {}", to_ustring(any_value));
  console::write_line("as<ustring>(any_value)           = {}", as<ustring>(any_value));
  console::write_line("convert::to_ustring(any_value)   = {}", convert::to_ustring(any_value));
  console::write_line("ustring::format(\"{{}}\", any_value) = {}", ustring::format("{}", any_value));
  console::write_line();
  
  console::write_line("Convert const char16 to ustring :");
  console::write_line("-----------------------------------");
  auto const_char16_value = u"A string value";
  console::write_line("to_ustring(wstring_value)                      = {}", to_ustring(const_char16_value));
  console::write_line("as<ustring>(const_char16_value)                = {}", as<ustring>(const_char16_value));
  console::write_line("convert::to_ustring(const_char16_value)        = {}", convert::to_ustring(const_char16_value));
  console::write_line("convert_string::to_ustring(const_char16_value) = {}", convert_string::to_ustring(const_char16_value));
  console::write_line("ustring::format(\"{{}}\", const_char16_value)      = {}", ustring::format("{}", const_char16_value));
  console::write_line();
  
  console::write_line("Convert wstring to ustring :");
  console::write_line("----------------------------");
  wstring wstring_value = L"A string value";
  console::write_line("to_ustring(wstring_value)                 = {}", to_ustring(wstring_value));
  console::write_line("as<ustring>(wstring_value)                = {}", as<ustring>(wstring_value));
  console::write_line("convert::to_ustring(wstring_value)        = {}", convert::to_ustring(wstring_value));
  console::write_line("convert_string::to_ustring(wstring_value) = {}", convert_string::to_ustring(wstring_value));
  console::write_line("ustring::format(\"{{}}\", wstring_value)      = {}", ustring::format("{}", wstring_value));
}

// This code can produces the following output:
//
// Convert int to ustring :
// ------------------------
// to_ustring(value)            = 42
// as<ustring>(value)           = 42
// convert::to_ustring(value)   = 42
// ustring::format("{}", value) = 42
//
// Convert float to ustring :
// --------------------------
// to_ustring(float_value)            = 42.5
// as<ustring>(float_value)           = 42.5
// convert::to_ustring(float_value)   = 42.5
// ustring::format("{}", float_value) = 42.5
//
// Convert any to ustring :
// ------------------------
// to_ustring(any_value)            = 42
// as<ustring>(any_value)           = 42
// convert::to_ustring(any_value)   = 42
// ustring::format("{}", any_value) = 42
//
// Convert const char16 to ustring :
// -----------------------------------
// to_ustring(wstring_value)                      = A string value
// as<ustring>(const_char16_value)                = A string value
// convert::to_ustring(const_char16_value)        = A string value
// convert_string::to_ustring(const_char16_value) = A string value
// ustring::format("{}", const_char16_value)      = A string value
//
// Convert wstring to ustring :
// ----------------------------
// to_ustring(wstring_value)                 = A string value
// as<ustring>(wstring_value)                = A string value
// convert::to_ustring(wstring_value)        = A string value
// convert_string::to_ustring(wstring_value) = A string value
// ustring::format("{}", wstring_value)      = A string value
