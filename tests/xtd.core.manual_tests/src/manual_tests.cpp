#include <xtd/xtd>

using namespace xtd::collections;

template <>
struct std::hash<xtd::string> {
  std::size_t operator()(const xtd::string& k) const {return k.get_hash_code();}
};

class manual_tests static_ {
public:
  static auto entry_point(const auto& args) {
    println();
    println("argument_collection = {}", args);
    
    println();
    println("array<string>          = {}", array<string> {"one", "two", "three", "four", "five"});
    println("fixed_array<string, 5> = {}", fixed_array<string, 5> {"one", "two", "three", "four", "five"});
    println("std::array<string, 5>  = {}", std::array<string, 5> {"one", "two", "three", "four", "five"});
    
    println();
    println("bit_array         = {}", bit_array {true, true, false, false, true});
    //println("std::vector<bool> = {}", std::vector<bool> {true, true, false, false, true});
    //println("std::bit_set<5>   = {}", std::bitset<5> {"11001"});
    
    println();
    println("list<string>        = {}", list<string> {"one", "two", "three", "four", "five"});
    println("std::vector<string> = {}", std::vector<string> {"one", "two", "three", "four", "five"});
    
    println();
    println("linked_list<string>       = {}", linked_list<string> {"one", "two", "three", "four", "five"});
    println("std::forward_list<string> = {}", std::forward_list<string> {"one", "two", "three", "four", "five"});
    println("std::list<string>         = {}", std::list<string> {"one", "two", "three", "four", "five"});
    
    println();
    println("hash_set<string>                                    = {}", hash_set<string> {"one", "two", "three", "four", "five"});
    println("std::unordered_set<string>                          = {}", std::unordered_set<string> {"one", "two", "three", "four", "five"});
    println("std::unordered_set<string, helpers::hasher<string>> = {}", std::unordered_set<string, xtd::collections::generic::helpers::hasher<string>> {"one", "two", "three", "four", "five"});
    
    println();
    println("sorted_set<string>                        = {}", sorted_set<string> {"one", "two", "three", "four", "five"});
    println("std::set<string>                          = {}", std::set<string> {"one", "two", "three", "four", "five"});
    println("std::set<string, helpers::lesser<string>> = {}", std::set<string, xtd::collections::generic::helpers::lesser<string>> {"one", "two", "three", "four", "five"});
    
    println();
    foreach_(const auto& item, {"one", "two", "three", "four", "five"}) {
      print("{}, ", item);
    }
    println();
    
    //println("Hello, world!");
  }
};

startup_(manual_tests::entry_point);

// This code can produces the following output:
//
// Hello, World!
