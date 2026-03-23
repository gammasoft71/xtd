#include <xtd/xtd>

auto main() -> int {
  auto p = new string("value");
  
  println("C++ cast :");
  println("  i => {}", static_cast<std::int32_t>(366216421905));
  println("  s => \"{}\"", *reinterpret_cast<std::string*>(p));
  auto dcp = dynamic_cast<std::string*>(p);
  println("  s => {}", dcp ? *dcp : "(null)");
  println();

  println("Unsafe cast :");
  println("  i => {}", unsafe::as<std::int32_t>(366216421905));
  println("  s => \"{}\"", *unsafe::as<std::string>(p));
  println();
  
  println("Safe cast :");
  try {
    println("  i => {}", as<int32>(366216421905));
  } catch (const overflow_exception& e) {
    println("  {} is greater than {}", 366216421905, xtd::int32_object::max_value);
  }
  try {
    println("  s => {}", *as<std::string>(p));
  } catch (const invalid_cast_exception& e) {
    println("  {} is not a std::string", p->quoted());
  }
  println();

  println("Convert :");
  try {
    println("  i => {}", convert::to_int32(366216421905));
  } catch (const overflow_exception& e) {
    println("  {} is greater than {}", 366216421905, xtd::int32_object::max_value);
  }
  try {
    println("  s => {}", convert_pointer::to_ptr<std::string>(p));
  } catch (const invalid_cast_exception& e) {
    println("  {} is not a std::string", p->quoted());
  }
  println();

  delete p;
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
//   "value" is not a std::string
//
// Convert :
//   366216421905 is greater than 2147483647
//   "value" is not a std::string
//
