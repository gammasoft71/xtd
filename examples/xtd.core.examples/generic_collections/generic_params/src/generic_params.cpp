#include <xtd/collections/generic/list>
#include <xtd/console>
#include <xtd/startup>
#include <xtd/time_span>
#include <vector>

using namespace xtd;
using namespace xtd::collections::generic;

class program {
public:
  static auto main() -> void {
    console::write_line("params = {}", params {1, 2, 3, 4, 5});
    console::write_line("list = {}", list<int> {params {1, 2, 3, 4, 5}});
    console::write_line("vector = {}", std::vector<int> {params {1, 2, 3, 4, 5}});
    console::write_line("create_list = {}", create_list(params {"one", "two", "three", "four", "five"}));
    console::write_line("create_vector = {}", create_vector(params {3_h + 2_min + 1_s, 3_h + 2_min + 2_s, 3_h + 2_min + 3_s, 3_h + 2_min + 4_s, 3_h + 2_min + 5_s}));
  }
  
private:
  template <typename type_t>
  static list<type_t> create_list(params<type_t> items) {
    return list<type_t> {items};
  }
  
  template <typename type_t>
  static std::vector<type_t> create_vector(params<type_t> items) {
    return std::vector<type_t> {items};
  }
  
};

startup_(program::main);

// This code can produce the following output :
//
// params = [1, 2, 3, 4, 5]
// list = [1, 2, 3, 4, 5]
// vector = [1, 2, 3, 4, 5]
// create_list = [1, 2, 3, 4, 5]
// create_vector = [03:02:01, 03:02:02, 03:02:03, 03:02:04, 03:02:05]
