# xtd_collection_indexer

Shows how to use indexing operators with [xtd::bpos](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gae5b63301b69ce281ee7db98e2e61941f) (bpos, bpos + 1, bpos + 2), [xtd::epos](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gaa99759e66edbafa9f3ed0b523c924b5c) (epos, epos - 1, epos - 2, ...) and bitwise operators (~1_z, ~2_z, ...) with xtd collections like [xtd::collections::generic::list](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1list.html).

## Sources

* [src/xtd_collection_indexer.cpp](src/xtd_collection_indexer.cpp)

* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
a[-1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 8
a[0] = 1
a[1] = 2
a[2] = 3
a[3] = 4
a[4] = 5
a[5] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 18

a[bpos-1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 25
a[bpos]   = 1
a[bpos+1] = 2
a[bpos+2] = 3
a[bpos+3] = 4
a[bpos+4] = 5
a[bpos+5] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 35

a[~0] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 42
a[~1] = 5
a[~2] = 4
a[~3] = 3
a[~4] = 2
a[~5] = 1
a[~6] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 52

a[-1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 59
a[-2] = 5
a[-3] = 4
a[-4] = 3
a[-5] = 2
a[-6] = 1
a[-7] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 69

a[epos+1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 76
a[epos]   = 5
a[epos-1] = 4
a[epos-2] = 3
a[epos-3] = 2
a[epos-4] = 1
a[epos-5] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 86

a[npos] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 93
```
