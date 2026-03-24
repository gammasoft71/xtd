#include <xtd/xtd>

auto main() -> int {
  auto now = date_time::now();

  println("C++ cast :");
  println("  i => {}", static_cast<std::int32_t>(366216421905));
  println("  s => {}", reinterpret_cast<string*>(&now)->quoted());
  auto dcp = dynamic_cast<string*>(&now);
  println("  s => {}", dcp ? *dcp : "(null)");
  println();

  println("Unsafe cast :");
  println("  i => {}", unsafe::as<std::int32_t>(366216421905));
  println("  s => {}", unsafe::as<string>(&now)->quoted());
  println();
  
  println("Safe cast :");
  try {
    println("  i => {}", as<int32>(366216421905));
  } catch (const overflow_exception& e) {
    println("  {} is greater than {}", 366216421905, xtd::int32_object::max_value);
  }
  try {
    println("  s => {}", as<string>(&now)->quoted());
  } catch (const invalid_cast_exception& e) {
    println("  {} is not a xtd::string*", type_of(&now));
  }
  println();

  println("Convert :");
  try {
    println("  i => {}", convert::to_int32(366216421905));
  } catch (const overflow_exception& e) {
    println("  {} is greater than {}", 366216421905, xtd::int32_object::max_value);
  }
  try {
    println("  s => {}", convert_pointer::to_ptr<string>(&now)->quoted());
  } catch (const invalid_cast_exception& e) {
    println("  {} is not a xtd::string*", type_of(&now));
  }
  println();
}

// This code produces the following output :
//
// C++ cast :
//   i => 1144201745
//   s => "@\317r"
//   s => (null)
//
// Unsafe cast :
//   i => 1144201745
//   s => "@\317r"
//
// Safe cast :
//   366216421905 is greater than 2147483647
//   xtd::date_time* is not a xtd::string*
//
// Convert :
//   366216421905 is greater than 2147483647
//   xtd::date_time* is not a xtd::string*
//
