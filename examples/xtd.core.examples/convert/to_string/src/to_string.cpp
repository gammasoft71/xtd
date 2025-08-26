#include <xtd/xtd>
#include <any>

auto main() -> int {
  console::write_line("Convert int to string :");
  console::write_line("-----------------------");
  auto value = 42;
  console::write_line("to_string(value)            = {}", to_string(value));
  console::write_line("as<string>(value)           = {}", as<string>(value));
  console::write_line("convert::to_string(value)   = {}", convert::to_string(value));
  console::write_line("string::format(\"{{}}\", value) = {}", string::format("{}", value));
  console::write_line();
  
  console::write_line("Convert float to string :");
  console::write_line("-------------------------");
  auto float_value = 42.5f;
  console::write_line("to_string(float_value)            = {}", to_string(float_value));
  console::write_line("as<string>(float_value)           = {}", as<string>(float_value));
  console::write_line("convert::to_string(float_value)   = {}", convert::to_string(float_value));
  console::write_line("string::format(\"{{}}\", float_value) = {}", string::format("{}", float_value));
  console::write_line();
  
  console::write_line("Convert any to string :");
  console::write_line("-----------------------");
  auto any_value = std::any(42);
  console::write_line("to_string(any_value)            = {}", to_string(any_value));
  console::write_line("as<string>(any_value)           = {}", as<string>(any_value));
  console::write_line("convert::to_string(any_value)   = {}", convert::to_string(any_value));
  console::write_line("string::format(\"{{}}\", any_value) = {}", string::format("{}", any_value));
  console::write_line();
  
  console::write_line("Convert any_object to string :");
  console::write_line("------------------------------");
  auto any_object_value = any_object(42);
  console::write_line("to_string(any_object_value)            = {}", to_string(any_object_value));
  console::write_line("as<string>(any_object_value)           = {}", as<string>(any_object_value));
  console::write_line("convert::to_string(any_object_value)   = {}", convert::to_string(any_object_value));
  console::write_line("string::format(\"{{}}\", any_object_value) = {}", string::format("{}", any_object_value));
  console::write_line();

  console::write_line("Convert const char16 to string :");
  console::write_line("--------------------------------");
  auto const_char16_value = u"A string value";
  console::write_line("to_string(wstring_value)                      = {}", to_string(const_char16_value));
  console::write_line("as<string>(const_char16_value)                = {}", as<string>(const_char16_value));
  console::write_line("convert::to_string(const_char16_value)        = {}", convert::to_string(const_char16_value));
  console::write_line("convert_string::to_string(const_char16_value) = {}", convert_string::to_string(const_char16_value));
  console::write_line("string::format(\"{{}}\", const_char16_value)      = {}", string::format("{}", const_char16_value));
  console::write_line();
  
  console::write_line("Convert const wchar to string :");
  console::write_line("-------------------------------");
  auto const_wchar_value = L"A string value";
  console::write_line("to_string(const_wchar_value)                 = {}", to_string(const_wchar_value));
  console::write_line("as<string>(const_wchar_value)                = {}", as<string>(const_wchar_value));
  console::write_line("convert::to_string(const_wchar_value)        = {}", convert::to_string(const_wchar_value));
  console::write_line("convert_string::to_string(const_wchar_value) = {}", convert_string::to_string(const_wchar_value));
  console::write_line("string::format(\"{{}}\", const_wchar_value)      = {}", string::format("{}", const_wchar_value));
}

// This code produces the following output :
//
// Convert int to string :
// -----------------------
// to_string(value)            = 42
// as<string>(value)           = 42
// convert::to_string(value)   = 42
// string::format("{}", value) = 42
//
// Convert float to string :
// -------------------------
// to_string(float_value)            = 42.5
// as<string>(float_value)           = 42.5
// convert::to_string(float_value)   = 42.5
// string::format("{}", float_value) = 42.5
//
// Convert any to string :
// -----------------------
// to_string(any_value)            = 42
// as<string>(any_value)           = 42
// convert::to_string(any_value)   = 42
// string::format("{}", any_value) = 42
//
// Convert any_object to string :
// ------------------------------
// to_string(any_object_value)            = 42
// as<string>(any_object_value)           = 42
// convert::to_string(any_object_value)   = 42
// string::format("{}", any_object_value) = 42
//
// Convert const char16 to string :
// --------------------------------
// to_string(wstring_value)                      = A string value
// as<string>(const_char16_value)                = A string value
// convert::to_string(const_char16_value)        = A string value
// convert_string::to_string(const_char16_value) = A string value
// string::format("{}", const_char16_value)      = A string value
//
// Convert const wchar to string :
// -------------------------------
// to_string(const_wchar_value)                 = A string value
// as<string>(const_wchar_value)                = A string value
// convert::to_string(const_wchar_value)        = A string value
// convert_string::to_string(const_wchar_value) = A string value
// string::format("{}", const_wchar_value)      = A string value
