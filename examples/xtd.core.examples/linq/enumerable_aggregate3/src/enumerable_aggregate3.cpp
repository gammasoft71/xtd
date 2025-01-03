#include <xtd/array>
#include <xtd/console>

using namespace xtd;

auto main() -> int {
  auto fruits = array {"apple"_s, "mango"_s, "orange"_s, "passionfruit"_s, "grape"_s};
  
  // Determine whether any string in the array is longer than "banana".
  auto longest_name =
  fruits.aggregate("bananas"_s,
                        [](const string& longest, const string& next) {return next.length() > longest.length() ? next : longest;},
                        // Return the final result as an upper case string.
                        [](const string& fruit) {return fruit.to_upper();});
  
  console::write_line("The fruit with the longest name is {}", longest_name);
}

// This code produces the following output :
//
// The fruit with the longest name is PASSIONFRUIT
