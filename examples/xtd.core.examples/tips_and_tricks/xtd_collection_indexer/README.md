# xtd_collection_indexer

Shows how to use indexing operators with [xtd::index](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gae5b63301b69ce281ee7db98e2e61941f) (xtd::index::start, xtd::index::start + 1, xtd::index::start + 2), [xtd::xtd::index::last](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gaa99759e66edbafa9f3ed0b523c924b5c) (xtd::index::last, xtd::index::last - 1, xtd::index::last - 2, ...) and bitwise operators (~1_z, ~2_z, ...) with xtd collections like [xtd::collections::generic::list](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1list.html).

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
   at main in xtd_collection_indexer.cpp:line 6
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
   at main in xtd_collection_indexer.cpp:line 16

a[xtd::index::start-1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 23
a[xtd::index::start]   = 1
a[xtd::index::start+1] = 2
a[xtd::index::start+2] = 3
a[xtd::index::start+3] = 4
a[xtd::index::start+4] = 5
a[xtd::index::start+5] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 33

a[~0] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 40
a[~1_i] = 5
a[~2_i] = 4
a[~3_i] = 3
a[~4_i] = 2
a[~5_i] = 1
a[~6_i] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 50

a[-1_i] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 57
a[-2_i] = 5
a[-3_i] = 4
a[-4_i] = 3
a[-5_i] = 2
a[-6_i] = 1
a[-7_i] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 67

a[xtd::index::last+1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 74
a[xtd::index::last]   = 5
a[xtd::index::last-1] = 4
a[xtd::index::last-2] = 3
a[xtd::index::last-3] = 2
a[xtd::index::last-4] = 1
a[xtd::index::last-5] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 84

a[xtd::index::end] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
   at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
   at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
   at main in xtd_collection_indexer.cpp:line 91
```
