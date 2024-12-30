#include <xtd/console>

using namespace xtd;

auto main() -> int {
  auto fruits = array<string> {"apple", "banana", "mango", "orange", "passionfruit", "grape"};
  
  const auto& query = fruits.select<std::tuple<size_t, string>>([](const string& fruit, size_t index) {
    return std::make_tuple(index, fruit.substring(0, index));
  });
  
  for (const auto& [index, str] : query)
    console::write_line("{{ index = {}, str = {} }}", index, str);
}

// This code produces the following output :
//
// { index = 0, str =  }
// { index = 1, str = b }
// { index = 2, str = ma }
// { index = 3, str = ora }
// { index = 4, str = pass }
// { index = 5, str = grape }
