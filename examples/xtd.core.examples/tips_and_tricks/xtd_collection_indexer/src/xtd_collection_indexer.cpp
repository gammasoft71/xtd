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
    println("a[xtd::index::start-1] = {}", a[xtd::index::start-1]);
  } catch (const index_out_of_range_exception& e) {
    println("a[xtd::index::start-1] Throws {}", e);
  }
  println("a[xtd::index::start]   = {}", a[xtd::index::start]);
  println("a[xtd::index::start+1] = {}", a[xtd::index::start+1]);
  println("a[xtd::index::start+2] = {}", a[xtd::index::start+2]);
  println("a[xtd::index::start+3] = {}", a[xtd::index::start+3]);
  println("a[xtd::index::start+4] = {}", a[xtd::index::start+4]);
  try {
    println("a[xtd::index::start+5] = {}", a[xtd::index::start+5]);
  } catch (const index_out_of_range_exception& e) {
    println("a[xtd::index::start+5] Throws {}", e);
  }
  println();
  
  try {
    println("a[~0_i] = {}", a[~0_i]);
  } catch (const index_out_of_range_exception& e) {
    println("a[~0_i] Throws {}", e);
  }
  println("a[~1_i] = {}", a[~1_i]);
  println("a[~2_i] = {}", a[~2_i]);
  println("a[~3_i] = {}", a[~3_i]);
  println("a[~4_i] = {}", a[~4_i]);
  println("a[~5_i] = {}", a[~5_i]);
  try {
    println("a[~6_i] = {}", a[~6_i]);
  } catch (const index_out_of_range_exception& e) {
    println("a[~6_i] Throws {}", e);
  }
  println();
  
  try {
    println("a[-1_i] = {}", a[-1_i]);
  } catch (const index_out_of_range_exception& e) {
    println("a[-1_i] Throws {}", e);
  }
  println("a[-2_i] = {}", a[-2_i]);
  println("a[-3_i] = {}", a[-3_i]);
  println("a[-4_i] = {}", a[-4_i]);
  println("a[-5_i] = {}", a[-5_i]);
  println("a[-6_i] = {}", a[-6_i]);
  try {
    println("a[-7_i] = {}", a[-7_i]);
  } catch (const index_out_of_range_exception& e) {
    println("a[-7_i] Throws {}", e);
  }
  println();
  
  try {
    println("a[xtd::index::last+1] = {}", a[xtd::index::last+1]);
  } catch (const index_out_of_range_exception& e) {
    println("a[xtd::index::last+1] Throws {}", e);
  }
  println("a[xtd::index::last]   = {}", a[xtd::index::last]);
  println("a[xtd::index::last-1] = {}", a[xtd::index::last-1]);
  println("a[xtd::index::last-2] = {}", a[xtd::index::last-2]);
  println("a[xtd::index::last-3] = {}", a[xtd::index::last-3]);
  println("a[xtd::index::last-4] = {}", a[xtd::index::last-4]);
  try {
    println("a[xtd::index::last-5] = {}", a[xtd::index::last-5]);
  } catch (const index_out_of_range_exception& e) {
    println("a[xtd::index::last-5] Throws {}", e);
  }
  println();
  
  try {
    println("a[xtd::index::end] = {}", a[xtd::index::end]);
  } catch (const index_out_of_range_exception& e) {
    println("a[xtd::index::end] Throws {}", e);
  }
}

// This code produces the following output :
//
// a[-1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 6
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
//    at main in xtd_collection_indexer.cpp:line 16
//
// a[xtd::index::start-1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 23
// a[xtd::index::start]   = 1
// a[xtd::index::start+1] = 2
// a[xtd::index::start+2] = 3
// a[xtd::index::start+3] = 4
// a[xtd::index::start+4] = 5
// a[xtd::index::start+5] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 33
//
// a[~0_i] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 40
// a[~1_i] = 5
// a[~2_i] = 4
// a[~3_i] = 3
// a[~4_i] = 2
// a[~5_i] = 1
// a[~6_i] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 50
//
// a[-1_i] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 57
// a[-2_i] = 5
// a[-3_i] = 4
// a[-4_i] = 3
// a[-5_i] = 2
// a[-6_i] = 1
// a[-7_i] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 67
//
// a[xtd::index::last+1] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 74
// a[xtd::index::last]   = 5
// a[xtd::index::last-1] = 4
// a[xtd::index::last-2] = 3
// a[xtd::index::last-3] = 2
// a[xtd::index::last-4] = 1
// a[xtd::index::last-5] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 84
//
// a[xtd::index::end] Throws xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::source_location const&) in throw_helper.cpp:line 80
//    at xtd::basic_array<int, std::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 0
//    at xtd::array<int, 1ul, std::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 249
//    at main in xtd_collection_indexer.cpp:line 91
