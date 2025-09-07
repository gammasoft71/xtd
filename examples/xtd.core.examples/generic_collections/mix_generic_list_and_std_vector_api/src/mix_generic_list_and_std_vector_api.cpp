#include <xtd/xtd>

auto main() -> int {
  // Create an xtd list
  auto items = list<string> {"alpha", "beta", "gamma"};
  
  // Add an element directly via STL
  items.items().push_back("delta");
  
  // Insert a range via the xtd API
  items.insert_range(1, {"epsilon", "zeta"});
  
  // Modify an element via xtd
  items[2] = "ZETA";
  
  // Modify an element via STL
  items.items()[3] = "BETA";
  
  // Sort elements via STL
  std::sort(items.items().begin(), items.items().end());
  
  // Display the final list
  std::println("Final list: {}", string::join(", ", items).chars());
  
  // Example of protection: modification during iteration
  try {
    for (auto& item : items) {
      if (item == "alpha") items.items().erase(items.items().begin());
    }
  } catch (const invalid_operation_exception&) {
    std::println("Exception caught: modification during iteration!");
  }
}

// This code produces the following output :
//
// Final list: BETA, ZETA, alpha, delta, epsilon, gamma
// Exception caught: modification during iteration!
