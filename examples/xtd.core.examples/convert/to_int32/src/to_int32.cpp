#include <xtd/xtd>

using namespace xtd;

int main() {
  console::write_line("Convert unsigned int to int :");
  console::write_line("-----------------------------");
  auto value = 42u;
  console::write_line("static_cast<int32_t>(value) = {}", static_cast<int32_t>(value));
  console::write_line("as<int32_t>(value)          = {}", as<int32_t>(value));
  console::write_line("convert::to_int32(value)    = {}", convert::to_int32(value));
  console::write_line();
  
  console::write_line("Convert float to int :");
  console::write_line("----------------------");
  auto float_value = 42.5f;
  console::write_line("static_cast<int32_t>(float_value) = {}", static_cast<int32_t>(float_value));
  console::write_line("as<int32_t>(float_value)          = {}", as<int32_t>(float_value));
  console::write_line("convert::to_int32(float_value)    = {}", convert::to_int32(float_value));
  console::write_line();
  
  console::write_line("Convert string to int :");
  console::write_line("-----------------------");
  auto string_value = "42";
  console::write_line("parse<int32_t>(string_value))   = {}", parse<int32_t>(string_value));
  console::write_line("as<int32_t>(string_value)       = {}", as<int32_t>(string_value));
  console::write_line("convert::to_int32(string_value) = {}", convert::to_int32(string_value));
  console::write_line();
  
  console::write_line("Convert hexa string to int :");
  console::write_line("----------------------------");
  auto string_hex_value = "0x2A";
  console::write_line("parse<int32_t>(string_hex_value, number_styles::hex_number) = {}", parse<int32_t>(string_hex_value, number_styles::hex_number));
  console::write_line("as<int32_t>(string_hex_value, 16)                           = {}", as<int32_t>(string_hex_value, 16));
  console::write_line("convert::to_int32(string_hex_value, 16))                    = {}", convert::to_int32(string_hex_value, 16));
  console::write_line();
  
  console::write_line("Convert unsigned int to int with overflow :");
  console::write_line("-------------------------------------------");
  auto overflow_value = 2147483648u;
  console::write_line("static_cast<int32_t>(overflow_value) = {}", static_cast<int32_t>(overflow_value)); // Overflow not detected
  try {
    console::write_line("as<int32_t>(overflow_value)          = {}", as<int32_t>(overflow_value));
  } catch(const overflow_exception& e) {
    console::write_line("(ERROR) as : Overflow exception");
  }
  try {
    console::write_line("convert::to_int32(overflow_value)   = {}", convert::to_int32(overflow_value));
  } catch(const overflow_exception& e) {
    console::write_line("(ERROR) convert::to_int32 : Overflow exception");
  }
  console::write_line();
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
// (ERROR) convert::to_byte : Overflow exception
