#include <xtd/as>
#include <xtd/console>
#include <xtd/convert>
#include <any>

using namespace xtd;

auto main() -> int {
  console::write_line("Convert int to byte :");
  console::write_line("---------------------");
  auto value = 42;
  console::write_line("static_cast<byte>(value) = {}", static_cast<byte>(value));
  console::write_line("as<byte>(value)          = {}", as<byte>(value));
  console::write_line("convert::to_byte(value)  = {}", convert::to_byte(value));
  console::write_line();
  
  console::write_line("Convert float to byte :");
  console::write_line("-----------------------");
  auto float_value = 42.5f;
  console::write_line("static_cast<byte>(float_value) = {}", static_cast<byte>(float_value));
  console::write_line("as<byte>(float_value)          = {}", as<byte>(float_value));
  console::write_line("convert::to_byte(float_value)  = {}", convert::to_byte(float_value));
  console::write_line();
  
  console::write_line("Convert any to byte :");
  console::write_line("---------------------");
  auto any_value = std::make_any<byte>(42);
  console::write_line("any_cast<byte>(any_value)   = {}", any_cast<byte>(any_value));
  console::write_line("as<byte>(any_value)         = {}", as<byte>(any_value));
  console::write_line("convert::to_byte(any_value) = {}", convert::to_byte(any_value));
  console::write_line();
  
  console::write_line("Convert string to byte :");
  console::write_line("------------------------");
  auto string_value = "42";
  console::write_line("parse<byte>(string_value))     = {}", parse<byte>(string_value));
  console::write_line("as<byte>(string_value)         = {}", as<byte>(string_value));
  console::write_line("convert::to_byte(string_value) = {}", convert::to_byte(string_value));
  console::write_line();
  
  console::write_line("Convert hexa string to byte :");
  console::write_line("-----------------------------");
  auto string_hex_value = "0x2A";
  console::write_line("parse<byte>(string_hex_value, number_styles::hex_number) = {}", parse<byte>(string_hex_value, number_styles::hex_number));
  console::write_line("as<byte>(string_hex_value, 16)                           = {}", as<byte>(string_hex_value, 16));
  console::write_line("convert::to_byte(string_hex_value, 16))                  = {}", convert::to_byte(string_hex_value, 16));
  console::write_line();
  
  console::write_line("Convert int to byte with overflow :");
  console::write_line("-----------------------------------");
  auto overflow_value = 257;
  console::write_line("static_cast<byte>(overflow_value) = {}", static_cast<byte>(overflow_value)); // Overflow not detected
  try {
    console::write_line("as<byte>(overflow_value)          = {}", as<byte>(overflow_value));
  } catch (const overflow_exception&) {
    console::write_line("(ERROR) as : Overflow exception");
  }
  try {
    console::write_line("convert::to_byte(overflow_value)  = {}", convert::to_byte(overflow_value));
  } catch (const overflow_exception&) {
    console::write_line("(ERROR) convert::to_byte : Overflow exception");
  }
}

// This code produces the following output :
//
// Convert int to byte :
// ---------------------
// static_cast<byte>(value) = 42
// as<byte>(value)          = 42
// convert::to_byte(value)  = 42
//
// Convert float to byte :
// -----------------------
// static_cast<byte>(float_value) = 42
// as<byte>(float_value)          = 43
// convert::to_byte(float_value)  = 43
//
// Convert string to byte :
// ------------------------
// parse<byte>(string_value))     = 42
// as<byte>(string_value)         = 42
// convert::to_byte(string_value) = 42
//
// Convert any to byte :
// ---------------------
// any_cast<byte>(any_value)   = 42
// as<byte>(any_value)         = 42
// convert::to_byte(any_value) = 42
//
// Convert hexa string to byte :
// -----------------------------
// parse<byte>(string_hex_value, number_styles::hex_number) = 42
// as<byte>(string_hex_value, 16)                           = 42
// convert::to_byte(string_hex_value, 16))                  = 42
//
// Convert int to byte with overflow :
// -----------------------------------
// static_cast<byte>(overflow_value) = 1
// (ERROR) as : Overflow exception
// (ERROR) convert::to_byte : Overflow exception
