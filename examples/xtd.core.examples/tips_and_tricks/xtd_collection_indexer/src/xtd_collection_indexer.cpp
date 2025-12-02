#include <xtd/xtd>

auto main() -> int {
  auto a = array {1, 2, 3, 4, 5};
  try {
    println("a[-1] = {}", a[-1]);
  } catch (const index_out_of_range_exception& e) {
    println("a[-1] Throws {}", e);
  }
  println("a[0] = {}", a[0]);
  println("a[1] = {}", a[1]);
  println("a[2] = {}", a[2]);
  println("a[3] = {}", a[3]);
  println("a[4] = {}", a[4]);
  try {
    println("a[5] = {}", a[5]);
  } catch (const index_out_of_range_exception& e) {
    println("a[5] Throws {}", e);
  }
  println();
  
  try {
    println("a[bpos-1] = {}", a[bpos-1]);
  } catch (const index_out_of_range_exception& e) {
    println("a[bpos-1] Throws {}", e);
  }
  println("a[bpos]   = {}", a[bpos]);
  println("a[bpos+1] = {}", a[bpos+1]);
  println("a[bpos+2] = {}", a[bpos+2]);
  println("a[bpos+3] = {}", a[bpos+3]);
  println("a[bpos+4] = {}", a[bpos+4]);
  try {
    println("a[bpos+5] = {}", a[bpos+5]);
  } catch (const index_out_of_range_exception& e) {
    println("a[bpos+5] Throws {}", e);
  }
  println();
  
  try {
    println("a[~0] = {}", a[~0]);
  } catch (const index_out_of_range_exception& e) {
    println("a[~0] Throws {}", e);
  }
  println("a[~1] = {}", a[~1]);
  println("a[~2] = {}", a[~2]);
  println("a[~3] = {}", a[~3]);
  println("a[~4] = {}", a[~4]);
  println("a[~5] = {}", a[~5]);
  try {
    println("a[~6] = {}", a[~6]);
  } catch (const index_out_of_range_exception& e) {
    println("a[~6] Throws {}", e);
  }
  println();
  
  try {
    println("a[-1] = {}", a[-1]);
  } catch (const index_out_of_range_exception& e) {
    println("a[-1] Throws {}", e);
  }
  println("a[-2] = {}", a[-2]);
  println("a[-3] = {}", a[-3]);
  println("a[-4] = {}", a[-4]);
  println("a[-5] = {}", a[-5]);
  println("a[-6] = {}", a[-6]);
  try {
    println("a[-7] = {}", a[-7]);
  } catch (const index_out_of_range_exception& e) {
    println("a[-7] Throws {}", e);
  }
  println();
  
  try {
    println("a[epos+1] = {}", a[epos+1]);
  } catch (const index_out_of_range_exception& e) {
    println("a[epos+1] Throws {}", e);
  }
  println("a[epos]   = {}", a[epos]);
  println("a[epos-1] = {}", a[epos-1]);
  println("a[epos-2] = {}", a[epos-2]);
  println("a[epos-3] = {}", a[epos-3]);
  println("a[epos-4] = {}", a[epos-4]);
  try {
    println("a[epos-5] = {}", a[epos-5]);
  } catch (const index_out_of_range_exception& e) {
    println("a[epos-5] Throws {}", e);
  }
  println();
  
  try {
    println("a[npos] = {}", a[npos]);
  } catch (const index_out_of_range_exception& e) {
    println("a[npos] Throws {}", e);
  }
}

// This code produces the following output :
//
// a[-1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 8
// a[0] = 1
// a[1] = 2
// a[2] = 3
// a[3] = 4
// a[4] = 5
// a[5] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 18
//
// a[bpos-1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 25
// a[bpos]   = 1
// a[bpos+1] = 2
// a[bpos+2] = 3
// a[bpos+3] = 4
// a[bpos+4] = 5
// a[bpos+5] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 35
//
// a[~0] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 42
// a[~1] = 5
// a[~2] = 4
// a[~3] = 3
// a[~4] = 2
// a[~5] = 1
// a[~6] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 52
//
// a[-1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 59
// a[-2] = 5
// a[-3] = 4
// a[-4] = 3
// a[-5] = 2
// a[-6] = 1
// a[-7] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 69
//
// a[epos+1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 76
// a[epos]   = 5
// a[epos-1] = 4
// a[epos-2] = 3
// a[epos-3] = 2
// a[epos-4] = 1
// a[epos-5] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 86
//
// a[npos] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 93
