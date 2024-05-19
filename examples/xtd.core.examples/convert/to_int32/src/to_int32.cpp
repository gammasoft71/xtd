#include <xtd/as>
#include <xtd/console>
#include <xtd/convert>
#include <any>

using namespace std;
using namespace xtd;

auto main() -> int {
  console::write_line("Convert unsigned int to int :");
  console::write_line("-----------------------------");
  auto value = 42u;
  console::write_line("static_cast<int>(value)  = {}", static_cast<int>(value));
  console::write_line("as<int>(value)           = {}", as<int>(value));
  console::write_line("convert::to_int32(value) = {}", convert::to_int32(value));
  console::write_line();
  
  console::write_line("Convert float to int :");
  console::write_line("----------------------");
  auto float_value = 42.5f;
  console::write_line("static_cast<int>(float_value)  = {}", static_cast<int>(float_value));
  console::write_line("as<int>(float_value)           = {}", as<int>(float_value));
  console::write_line("convert::to_int32(float_value) = {}", convert::to_int32(float_value));
  console::write_line();
  
  console::write_line("Convert any to int :");
  console::write_line("--------------------");
  auto any_value = make_any<int>(42);
  console::write_line("any_cast<int>(any_value)     = {}", any_cast<int>(any_value));
  console::write_line("as<int>(any_value)           = {}", as<int>(any_value));
  console::write_line("convert::to_int32(any_value) = {}", convert::to_int32(any_value));
  console::write_line();
  
  console::write_line("Convert string to int :");
  console::write_line("-----------------------");
  auto string_value = "42";
  console::write_line("parse<int>(string_value))       = {}", parse<int>(string_value));
  console::write_line("as<int>(string_value)           = {}", as<int>(string_value));
  console::write_line("convert::to_int32(string_value) = {}", convert::to_int32(string_value));
  console::write_line();
  
  console::write_line("Convert hexa string to int :");
  console::write_line("----------------------------");
  auto string_hex_value = "0x2A";
  console::write_line("parse<int>(string_hex_value, number_styles::hex_number) = {}", parse<int>(string_hex_value, number_styles::hex_number));
  console::write_line("as<int>(string_hex_value, 16)                           = {}", as<int>(string_hex_value, 16));
  console::write_line("convert::to_int32(string_hex_value, 16))                = {}", convert::to_int32(string_hex_value, 16));
  console::write_line();
  
  console::write_line("Convert unsigned int to int with overflow :");
  console::write_line("-------------------------------------------");
  auto overflow_value = 2147483648u;
  console::write_line("static_cast<int>(overflow_value) = {}", static_cast<int>(overflow_value)); // Overflow not detected
  try {
    console::write_line("as<int>(overflow_value)        = {}", as<int>(overflow_value));
  } catch (const overflow_exception&) {
    console::write_line("(ERROR) as : Overflow exception");
  }
  try {
    console::write_line("convert::to_int32(overflow_value) = {}", convert::to_int32(overflow_value));
  } catch (const overflow_exception&) {
    console::write_line("(ERROR) convert::to_int32 : Overflow exception");
  }
}

// This code can produces the following output:
//
// Convert unsigned int to int :
// -----------------------------
// static_cast<int>(value)  = 42
// as<int>(value)           = 42
// convert::to_int32(value) = 42
//
// Convert float to int :
// ----------------------
// static_cast<int>(float_value)  = 42
// as<int>(float_value)           = 43
// convert::to_int32(float_value) = 43
//
// Convert any to int :
// --------------------
// any_cast<int>(any_value)     = 42
// as<int>(any_value)           = 42
// convert::to_int32(any_value) = 42
//
// Convert string to int :
// -----------------------
// parse<int>(string_value))       = 42
// as<int>(string_value)           = 42
// convert::to_int32(string_value) = 42
//
// Convert hexa string to int :
// ----------------------------
// parse<int>(string_hex_value, number_styles::hex_number) = 42
// as<int>(string_hex_value, 16)                           = 42
// convert::to_int32(string_hex_value, 16))                = 42
//
// Convert unsigned int to int with overflow :
// -------------------------------------------
// static_cast<int>(overflow_value) = -2147483648
// (ERROR) as : Overflow exception
// (ERROR) convert::to_int32 : Overflow exception
