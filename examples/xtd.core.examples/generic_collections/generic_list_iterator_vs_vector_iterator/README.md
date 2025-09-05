# generic_list_iterator_vs_vector_iterator

Highlights the difference between [xtd::collections::generic::list](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1list.html) and std::vector when modifying a collection during iteration.

## Sources

[src/generic_list_iterator_vs_vector_iterator.cpp](src/generic_list_iterator_vs_vector_iterator.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
=== xtd::collections::generic::list example ===
1
2
3
Caught exception: xtd::invalid_operation_exception : Collection was modified; enumeration operation may not execute.
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, char const*, std::__1::source_location const&) in !---OMITTED---!/xtd/collections/generic/list.hpp:line 104
   at xtd::collections::generic::list<int, std::__1::allocator<int>>::__enumerator__::move_next() in list.hpp:line 0
   at xtd::collections::generic::enumerator<int>::move_next() in enumerator.hpp:line 71
   at xtd::collections::generic::extensions::enumerable_iterators<int, xtd::collections::generic::ienumerable<int>>::enumerable_iterator<xtd::collections::generic::ienumerable<int>>::operator++() in enumerable_iterators.hpp:line 82
   at main in generic_list_iterator_vs_vector_iterator.cpp:line 9

=== std::vector example ===
1
2
3
5
5

Note: std::vector modification during iteration is undefined behavior and may crash or corrupt memory, while xtd::collections::generic::list safely detects it and throws an exception.
```
