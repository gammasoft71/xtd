#include <xtd/xtd>

class program {
public:
  static auto main() -> void {
    // Creates and initializes several bit_arrays.
    auto my_ba1 = collections::bit_array(5_z);
    
    auto my_ba2 = collections::bit_array(5_z, false);
    
    auto my_bytes = array {1_u8, 2_u8, 3_u8, 4_u8, 5_u8};
    auto my_ba3 = collections::bit_array(my_bytes);
    
    auto my_bools = array {true, false, true, true, false};
    auto my_ba4 = collections::bit_array(my_bools);
    
    auto my_ints  = array {6, 7, 8, 9, 10};
    auto my_ba5 = collections::bit_array(my_ints);
    
    // Displays the properties and values of the bit_arrays.
    console::write_line("my_ba1");
    console::write_line("   count:    {0}", my_ba1.count());
    console::write_line("   length:   {0}", my_ba1.length());
    console::write_line("   values:");
    print_values(my_ba1, 8);
    
    console::write_line("my_ba2");
    console::write_line("   count:    {0}", my_ba2.count());
    console::write_line("   length:   {0}", my_ba2.length());
    console::write_line("   values:");
    print_values(my_ba2, 8);
    
    console::write_line("my_ba3");
    console::write_line("   count:    {0}", my_ba3.count());
    console::write_line("   length:   {0}", my_ba3.length());
    console::write_line("   values:");
    print_values(my_ba3, 8);
    
    console::write_line("my_ba4");
    console::write_line("   count:    {0}", my_ba4.count());
    console::write_line("   length:   {0}", my_ba4.length());
    console::write_line("   values:");
    print_values(my_ba4, 8);
    
    console::write_line("my_ba5");
    console::write_line("   count:    {0}", my_ba5.count());
    console::write_line("   length:   {0}", my_ba5.length());
    console::write_line("   values:");
    print_values(my_ba5, 8);
  }
    
  template<class object_t>
  static auto print_values(const ienumerable<object_t>& my_list, int my_width) -> void {
    auto i = my_width;
    for (auto obj : my_list) {
      if (i <= 0)  {
        i = my_width;
        console::write_line();
      }
      i--;
      console::write("{,8}", obj);
    }
    console::write_line();
  }
};

startup_(program::main);


// This code produces the following output :
//
// my_ba1
//    count:    5
//    length:   5
//    values:
//    false   false   false   false   false
// my_ba2
//    count:    5
//    length:   5
//    values:
//    false   false   false   false   false
// my_ba3
//    count:    40
//    length:   40
//    values:
//     true   false   false   false   false   false   false   false
//    false    true   false   false   false   false   false   false
//     true    true   false   false   false   false   false   false
//    false   false    true   false   false   false   false   false
//     true   false    true   false   false   false   false   false
// my_ba4
//    count:    5
//    length:   5
//    values:
//     true   false    true    true   false
// my_ba5
//    count:    160
//    length:   160
//    values:
//    false    true    true   false   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false   false   false   false   false   false   false   false
//     true    true    true   false   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false   false   false    true   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false   false   false   false   false   false   false   false
//     true   false   false    true   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false    true   false    true   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false   false   false   false   false   false   false   false
//    false   false   false   false   false   false   false   false
