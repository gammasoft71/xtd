#include <xtd/xtd>

auto main() -> int {
  auto items = array {10, 20, 30};
  
  println(items[0]);          // print 10
  println(items[1]);          // print 20
  println(items[2]);          // print 30
  //println(items[3]);        // exception index_out_of_range_exception
  //println(items[0 - 1]);    // exception index_out_of_range_exception
  
  println(items[~1_z]);       // print 30
  println(items[~2_z]);       // print 20
  println(items[~3_z]);       // print 10
  //println(items[~4_z]);     // exception index_out_of_range_exception
  //println(items[~0_z]);     // exception index_out_of_range_exception
  
  println(items[bpos]);       // print 10
  println(items[bpos + 1]);   // print 20
  println(items[bpos + 2]);   // print 30
  //println(items[bpos + 3]); // exception index_out_of_range_exception
  //println(items[bpos - 1]); // exception index_out_of_range_exception
  
  println(items[epos]);       // print 30
  println(items[epos - 1]);   // print 20
  println(items[epos - 2]);   // print 10
  //println(items[epos - 3]); // exception index_out_of_range_exception
  //println(items[epos + 1]); // exception index_out_of_range_exception
  
  //println(items[npos]);     // exception index_out_of_range_exception
}

// This code produces the following output :
//
// 10
// 20
// 30
// 30
// 20
// 10
// 10
// 20
// 30
// 30
// 20
// 10
