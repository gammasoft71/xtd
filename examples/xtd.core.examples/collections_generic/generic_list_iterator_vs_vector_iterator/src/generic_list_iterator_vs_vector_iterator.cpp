#include <xtd/xtd>

auto main() -> int {
  console::write_line("=== xtd::collections::generic::list example ===");
  try {
    // xtd::collections::generic::list automatically tracks modifications
    auto my_list = list {1, 2, 3, 4, 5};
    
    for (auto item : my_list) {
      console::write_line(item);
      if (item == 3) my_list.remove(item); // modifying the list during iteration
    }
  } catch (const invalid_operation_exception& e) {
    console::write_line("Caught exception: {}", e);
  }
  
  console::write_line("\n=== std::vector example ===");
  try {
    // std::vector has no protection; modifying during iteration is undefined behavior
    auto my_vector = std::vector {1, 2, 3, 4, 5};
    
    for (auto item : my_vector) {
      console::write_line(item);
      if (item == 3) my_vector.erase(my_vector.begin() + 2); // unsafe modification
    }
  } catch (const std::exception& e) {
    console::write_line("Caught exception: {}", e);
  }
  
  console::write_line("\nNote: std::vector modification during iteration is undefined behavior and may crash or corrupt memory, while xtd::collections::generic::list safely detects it and throws an exception.");
}

// This code can produce the following output :
//
// === xtd::collections::generic::list example ===
// 1
// 2
// 3
// Caught exception: xtd::invalid_operation_exception : Collection was modified; enumeration operation may not execute.
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, char const*, std::__1::source_location const&) in !---OMITTED---!/xtd/collections/generic/list.hpp:line 104
//    at xtd::collections::generic::list<int, std::__1::allocator<int>>::__enumerator__::move_next() in list.hpp:line 0
//    at xtd::collections::generic::enumerator<int>::move_next() in enumerator.hpp:line 71
//    at xtd::collections::generic::extensions::enumerable_iterators<int, xtd::collections::generic::ienumerable<int>>::enumerable_iterator<xtd::collections::generic::ienumerable<int>>::operator++() in enumerable_iterators.hpp:line 82
//    at main in generic_list_iterator_vs_vector_iterator.cpp:line 9
//
// === std::vector example ===
// 1
// 2
// 3
// 5
// 5
//
// Note: std::vector modification during iteration is undefined behavior and may crash or corrupt memory, while xtd::collections::generic::list safely detects it and throws an exception.
