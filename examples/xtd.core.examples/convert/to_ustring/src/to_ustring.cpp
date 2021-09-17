#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
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

  console::write_line("Convert const char16_t to ustring :");
  console::write_line("-----------------------------------");
  auto const_char16_t_value = u"A string value";
  console::write_line("to_ustring(wstring_value)                        = {}", to_ustring(const_char16_t_value));
  console::write_line("as<ustring>(const_char16_t_value)                = {}", as<ustring>(const_char16_t_value));
  console::write_line("convert::to_ustring(const_char16_t_value)        = {}", convert::to_ustring(const_char16_t_value));
  console::write_line("convert_string::to_ustring(const_char16_t_value) = {}", convert_string::to_ustring(const_char16_t_value));
  console::write_line("ustring::format(\"{{}}\", const_char16_t_value)      = {}", ustring::format("{}", const_char16_t_value));
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
// Convert unsigned int to int :
// -----------------------------
// static_cast<int32_t>(value) = 42
// as<int32_t>(value)          = 42
// convert::to_int32(value)    = 42
//
// Convert float to int :
// ----------------------
// static_cast<int32_t>(float_value) = 42
// as<int32_t>(float_value)          = 43
// convert::to_int32(float_value)    = 43
//
// Convert any to ustring :
// ------------------------
// to_ustring(any_value)            = 42
// as<ustring>(any_value)           = 42
// convert::to_ustring(any_value)   = 42
// ustring::format("{}", any_value) = 42
//
// Convert string to int :
// -----------------------
// parse<int32_t>(string_value))   = 42
// as<int32_t>(string_value)       = 42
// convert::to_int32(string_value) = 42
//
// Convert hexa string to int :
// ----------------------------
// parse<int32_t>(string_hex_value, number_styles::hex_number) = 42
// as<int32_t>(string_hex_value, 16)                           = 42
// convert::to_int32(string_hex_value, 16))                    = 42
//
// Convert unsigned int to int with overflow :
// -------------------------------------------
// static_cast<int32_t>(overflow_value) = -2147483648
// (ERROR) as : Overflow exception
// (ERROR) convert::to_int32 : Overflow exception
