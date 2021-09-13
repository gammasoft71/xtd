#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  console::write_line("Convert int to byte :");
  console::write_line("---------------------");
  auto value = 42;
  console::write_line("static_cast<byte_t>(value) = {}", static_cast<byte_t>(value));
  console::write_line("as<byte_t>(value)          = {}", as<byte_t>(value));
  console::write_line("convert::to_byte(value)    = {}", convert::to_byte(value));
  console::write_line();
  
  console::write_line("Convert float to byte :");
  console::write_line("-----------------------");
  auto float_value = 42.5f;
  console::write_line("static_cast<byte_t>(float_value) = {}", static_cast<byte_t>(float_value));
  console::write_line("as<byte_t>(float_value)          = {}", as<byte_t>(float_value));
  console::write_line("convert::to_byte(float_value)    = {}", convert::to_byte(float_value));
  console::write_line();
  
  console::write_line("Convert any to byte :");
  console::write_line("---------------------");
  auto any_value = make_any<byte_t>(42);
  console::write_line("any_cast<byte_t>(any_value) = {}", any_cast<byte_t>(any_value));
  console::write_line("as<byte_t>(any_value)       = {}", as<byte_t>(any_value));
  console::write_line("convert::to_byte(any_value) = {}", convert::to_byte(any_value));
  console::write_line();

  console::write_line("Convert string to byte :");
  console::write_line("------------------------");
  auto string_value = "42";
  console::write_line("parse<byte_t>(string_value))   = {}", parse<byte_t>(string_value));
  console::write_line("as<byte_t>(string_value)       = {}", as<byte_t>(string_value));
  console::write_line("convert::to_byte(string_value) = {}", convert::to_byte(string_value));
  console::write_line();
  
  console::write_line("Convert hexa string to byte :");
  console::write_line("-----------------------------");
  auto string_hex_value = "0x2A";
  console::write_line("parse<byte_t>(string_hex_value, number_styles::hex_number) = {}", parse<byte_t>(string_hex_value, number_styles::hex_number));
  console::write_line("as<byte_t>(string_hex_value, 16)                           = {}", as<byte_t>(string_hex_value, 16));
  console::write_line("convert::to_byte(string_hex_value, 16))                    = {}", convert::to_byte(string_hex_value, 16));
  console::write_line();
  
  console::write_line("Convert int to byte with overflow :");
  console::write_line("-----------------------------------");
  auto overflow_value = 257;
  console::write_line("static_cast<byte_t>(overflow_value) = {}", static_cast<byte_t>(overflow_value)); // Overflow not detected
  try {
    console::write_line("as<byte_t>(overflow_value)          = {}", as<byte_t>(overflow_value));
  } catch(const overflow_exception& e) {
    console::write_line("(ERROR) as : Overflow exception");
  }
  try {
    console::write_line("convert::to_byte(overflow_value)   = {}", convert::to_byte(overflow_value));
  } catch(const overflow_exception& e) {
    console::write_line("(ERROR) convert::to_byte : Overflow exception");
  }
}

// This code can produces the following output:
//
// Convert int to byte :
// ---------------------
// static_cast<byte_t>(value) = 42
// as<byte_t>(value)          = 42
// convert::to_byte(value)    = 42
//
// Convert float to byte :
// -----------------------
// static_cast<byte_t>(float_value) = 42
// as<byte_t>(float_value)          = 43
// convert::to_byte(float_value)    = 43
//
// Convert string to byte :
// ------------------------
// parse<byte_t>(string_value))   = 42
// as<byte_t>(string_value)       = 42
// convert::to_byte(string_value) = 42
//
// Convert any to byte :
// ---------------------
// any_cast<byte_t>(any_value) = 42
// as<byte_t>(any_value)       = 42
// convert::to_byte(any_value) = 42
//
// Convert hexa string to byte :
// -----------------------------
// parse<byte_t>(string_hex_value, number_styles::hex_number) = 42
// as<byte_t>(string_hex_value, 16)                           = 42
// convert::to_byte(string_hex_value, 16))                    = 42
//
// Convert int to byte with overflow :
// -----------------------------------
// static_cast<byte_t>(overflow_value) = 1
// (ERROR) as : Overflow exception
// (ERROR) convert::to_byte : Overflow exception
