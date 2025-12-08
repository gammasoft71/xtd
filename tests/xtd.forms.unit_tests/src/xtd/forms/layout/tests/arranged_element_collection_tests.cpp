#include <algorithm>
#include <xtd/string>
#include <xtd/forms/layout/arranged_element_collection>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::forms::layout;
using namespace xtd::tunit;

namespace xtd::forms::layout::tests {
  class test_class_(arranged_element_collection_tests) {
    auto test_method_(new_collection) {
      arranged_element_collection<std::string> items;
      items.item_added += [&](size_t index, std::string & value) {
        assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      assert::is_true(items.count() == 0);
    }
    
    auto test_method_(add_item) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string & value) {
        if (added_control_check == 0) {
          assert::are_equal(0_z, index);
          assert::are_equal("a", value);
          added_control_check += 1;
        } else
          assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items.add("a");
      
      assert::is_false(items.count() == 0);
      assert::are_equal(1_z, items.count());
      assert::are_equal("a", items[0]);
      assert::are_equal(1_z, added_control_check);
    }
    
    auto test_method_(add_items) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string & value) {
        if (added_control_check == 0) {
          assert::are_equal(0_z, index);
          assert::are_equal("a", value);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(1_z, index);
          assert::are_equal("b", value);
          added_control_check += 2;
        } else if (added_control_check == 3) {
          assert::are_equal(2_z, index);
          assert::are_equal("c", value);
          added_control_check += 3;
        } else
          assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items.add("a");
      items.add("b");
      items.add("c");
      
      assert::is_false(items.count() == 0);
      assert::are_equal(3_z, items.count());
      assert::are_equal("a", items[0]);
      assert::are_equal("b", items[1]);
      assert::are_equal("c", items[2]);
      assert::are_equal(6_z, added_control_check);
    }
    
    auto test_method_(add_range_item) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string & value) {
        if (added_control_check == 0) {
          assert::are_equal(0_z, index);
          assert::are_equal("a", value);
          added_control_check += 1;
        } else
          assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items.add_range({"a"});
      
      assert::is_false(items.count() == 0);
      assert::are_equal(1_z, items.count());
      assert::are_equal("a", items[0]);
      assert::are_equal(1_z, added_control_check);
    }
    
    auto test_method_(add_range_items) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string & value) {
        if (added_control_check == 0) {
          assert::are_equal(0_z, index);
          assert::are_equal("a", value);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(1_z, index);
          assert::are_equal("b", value);
          added_control_check += 2;
        } else if (added_control_check == 3) {
          assert::are_equal(2_z, index);
          assert::are_equal("c", value);
          added_control_check += 3;
        } else
          assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items.add_range({"a", "b", "c"});
      
      assert::is_false(items.count() == 0);
      assert::are_equal(3_z, items.count());
      assert::are_equal("a", items[0]);
      assert::are_equal("b", items[1]);
      assert::are_equal("c", items[2]);
      assert::are_equal(6_z, added_control_check);
    }
    
    auto test_method_(insert_item) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string & value) {
        if (added_control_check == 0) {
          assert::are_equal(0_z, index);
          assert::are_equal("a", value);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(1_z, index);
          assert::are_equal("b", value);
          added_control_check += 2;
        } else if (added_control_check == 3) {
          assert::are_equal(2_z, index);
          assert::are_equal("c", value);
          added_control_check += 3;
        } else if (added_control_check == 6) {
          assert::are_equal(1_z, index);
          assert::are_equal("z", value);
          added_control_check += 4;
        } else
          assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items.add_range({"a", "b", "c"});
      
      assert::are_equal(6_z, added_control_check);
      
      items.insert(1, "z");
      
      assert::are_equal(4_z, items.count());
      assert::are_equal("a", items[0]);
      assert::are_equal("z", items[1]);
      assert::are_equal("b", items[2]);
      assert::are_equal("c", items[3]);
      assert::are_equal(10_z, added_control_check);
    }
    
    auto test_method_(insert_item_in_first) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string & value) {
        if (added_control_check == 0) {
          assert::are_equal(0_z, index);
          assert::are_equal("a", value);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(0_z, index);
          assert::are_equal("z", value);
          added_control_check += 2;
        } else
          assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items.add("a");
      items.insert(0, "z");
      
      assert::are_equal("z", items[0]);
      assert::are_equal("a", items[1]);
      assert::are_equal(3_z, added_control_check);
    }
    
    auto test_method_(insert_item_in_last) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string & value) {
        if (added_control_check == 0) {
          assert::are_equal(0_z, index);
          assert::are_equal("a", value);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(1_z, index);
          assert::are_equal("z", value);
          added_control_check += 2;
        } else
          assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items.add("a");
      items.insert(1, "z");
      
      assert::are_equal("a", items[0]);
      assert::are_equal("z", items[1]);
      assert::are_equal(3_z, added_control_check);
    }
    
    
    auto test_method_(insert_item_width_bad_index) {
      arranged_element_collection<std::string> items;
      items.add_range({"a", "b", "c"});
      assert::throws<argument_out_of_range_exception>([&] {items.insert(items.npos, "z");});
    }
    
    auto test_method_(erase_item) {
      arranged_element_collection<std::string> items;
      items.add_range({"a", "b", "c", "d", "e"});
      size_t erased_control_check = 0;
      items.item_added += [&](size_t index, std::string & value) {
        assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        if (erased_control_check == 0) {
          assert::are_equal(1_z, index);
          assert::are_equal("b", value);
          erased_control_check += 1;
        } else
          assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items.remove_at(1);
      
      assert::are_equal("a", items[0]);
      assert::are_equal("c", items[1]);
      assert::are_equal("d", items[2]);
      assert::are_equal("e", items[3]);
      assert::are_equal(1_z, erased_control_check);
    }
    
    auto test_method_(erase_all_items) {
      arranged_element_collection<std::string> items;
      items.add_range({"a", "b", "c", "d", "e"});
      size_t erased_control_check = 0;
      items.item_added += [&](size_t index, std::string & value) {
        assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        if (erased_control_check == 0) {
          assert::are_equal(1_z, index);
          assert::are_equal("b", value);
          erased_control_check += 1;
        } else if (erased_control_check == 1) {
          assert::are_equal(2_z, index);
          assert::are_equal("d", value);
          erased_control_check += 2;
        } else if (erased_control_check == 3) {
          assert::are_equal(1_z, index);
          assert::are_equal("c", value);
          erased_control_check += 3;
        } else if (erased_control_check == 6) {
          assert::are_equal(0_z, index);
          assert::are_equal("a", value);
          erased_control_check += 4;
        } else if (erased_control_check == 10) {
          assert::are_equal(0_z, index);
          assert::are_equal("e", value);
          erased_control_check += 5;
        } else
          assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items.remove_at(1);
      items.remove_at(2);
      items.remove_at(1);
      items.remove_at(0);
      items.remove_at(0);
      
      assert::is_true(items.count() == 0);
      assert::are_equal(15_z, erased_control_check);
    }
    
    auto test_method_(erase_item_first) {
      arranged_element_collection<std::string> items;
      size_t erased_control_check = 0_z;
      items.add_range({"a", "b", "c", "d", "e"});
      items.item_added += [&](size_t index, std::string & value) {
        assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        if (erased_control_check == 0) {
          assert::are_equal(0_z, index);
          assert::are_equal("a", value);
          erased_control_check += 1;
        } else
          assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items.remove_at(0);
      
      assert::are_equal("b", items[0]);
      assert::are_equal("c", items[1]);
      assert::are_equal("d", items[2]);
      assert::are_equal("e", items[3]);
      assert::are_equal(1_z, erased_control_check);
    }
    
    auto test_method_(erase_item_last) {
      arranged_element_collection<std::string> items;
      size_t erased_control_check = 0;
      items.add_range({"a", "b", "c", "d", "e"});
      items.item_added += [&](size_t index, std::string & value) {
        assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        if (erased_control_check == 0) {
          assert::are_equal(4_z, index);
          assert::are_equal("e", value);
          erased_control_check += 1;
        } else
          assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items.remove_at(4);
      
      assert::are_equal("a", items[0]);
      assert::are_equal("b", items[1]);
      assert::are_equal("c", items[2]);
      assert::are_equal("d", items[3]);
      assert::are_equal(1_z, erased_control_check);
    }
    
    auto test_method_(remove_at_item_width_bad_index) {
      arranged_element_collection<std::string> items;
      items.add_range({"a", "b", "c"});
      assert::throws<argument_out_of_range_exception>([&] {items.remove_at(items.npos);});
    }
    
    auto test_method_(update_item) {
      arranged_element_collection<std::string> items;
      items.add_range({"a", "b", "c", "d", "e"});
      size_t updated_control_check = 0;
      items.item_added += [&](size_t index, std::string & value) {
        assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        if (updated_control_check == 0) {
          assert::are_equal(1_z, index);
          assert::are_equal("z", value);
          updated_control_check += 1;
        } else
          assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      items[1] = "z";
      
      assert::are_equal("a", items[0]);
      assert::are_equal("z", items[1]);
      assert::are_equal("c", items[2]);
      assert::are_equal("d", items[3]);
      assert::are_equal("e", items[4]);
      assert::are_equal(1_z, updated_control_check);
    }
    
    auto test_method_(using_std_sort_two_items) {
      arranged_element_collection<std::string> items;
      items.add_range({"z", "a"});
      
      items.item_added += [&](size_t index, std::string & value) {
        assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::succeed(string::format("updated index = {}, value = {}", index, value));
      };
      
      std::sort(items.items().begin(), items.items().end());
      
      assert::are_equal("a", items[0]);
      assert::are_equal("z", items[1]);
    }
    
    auto test_method_(using_std_sort_four_items) {
      arranged_element_collection<std::string> items;
      items.add_range({"d", "a", "c", "b"});
      
      items.item_added += [&](size_t index, std::string & value) {
        assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::succeed(string::format("updated index = {}, value = {}", index, value));
      };
      
      std::sort(items.items().begin(), items.items().end());
      
      assert::are_equal("a", items[0]);
      assert::are_equal("b", items[1]);
      assert::are_equal("c", items[2]);
      assert::are_equal("d", items[3]);
    }
    
    auto test_method_(using_std_sort_Twelve_items_with_duplicates) {
      arranged_element_collection<std::string> items;
      items.add_range({"d", "a", "c", "b", "g", "i", "b", "h", "f", "j", "f", "k"});
      
      items.item_added += [&](size_t index, std::string & value) {
        assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        assert::succeed(string::format("updated index = {}, value = {}", index, value));
      };
      
      std::sort(items.items().begin(), items.items().end());
      
      assert::are_equal("a", items[0]);
      assert::are_equal("b", items[1]);
      assert::are_equal("b", items[2]);
      assert::are_equal("c", items[3]);
      assert::are_equal("d", items[4]);
      assert::are_equal("f", items[5]);
      assert::are_equal("f", items[6]);
      assert::are_equal("g", items[7]);
      assert::are_equal("h", items[8]);
      assert::are_equal("i", items[9]);
      assert::are_equal("j", items[10]);
      assert::are_equal("k", items[11]);
    }
    
    auto test_method_(using_std_swap) {
      arranged_element_collection<std::string> items;
      items.add_range({"z", "a"});
      size_t updated_control_check = 0;
      
      items.item_added += [&](size_t index, std::string & value) {
        assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        if (updated_control_check == 0) {
          assert::are_equal(0_z, index);
          assert::are_equal("a", value);
          updated_control_check += 1;
        } else if (updated_control_check == 1) {
          assert::are_equal(1_z, index);
          assert::are_equal("z", value);
          updated_control_check += 2;
        } else
          assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      std::swap(items[0], items[1]);
      
      assert::are_equal("a", items[0]);
      assert::are_equal("z", items[1]);
      assert::are_equal(3_z, updated_control_check);
    }
    
    auto test_method_(using_std_double_swap) {
      arranged_element_collection<std::string> items;
      items.add_range({"z", "a"});
      size_t updated_control_check = 0;
      
      items.item_added += [&](size_t index, std::string & value) {
        assert::fail(string::format("added index = {}, value = {}", index, value));
      };
      items.item_removed += [&](size_t index, std::string & value) {
        assert::fail(string::format("erased index = {}, value = {}", index, value));
      };
      items.item_updated += [&](size_t index, std::string & value) {
        if (updated_control_check == 0) {
          assert::are_equal(0_z, index);
          assert::are_equal("a", value);
          updated_control_check += 1;
        } else if (updated_control_check == 1) {
          assert::are_equal(1_z, index);
          assert::are_equal("z", value);
          updated_control_check += 2;
        } else if (updated_control_check == 3) {
          assert::are_equal(0_z, index);
          assert::are_equal("z", value);
          updated_control_check += 3;
        } else if (updated_control_check == 6) {
          assert::are_equal(1_z, index);
          assert::are_equal("a", value);
          updated_control_check += 4;
        } else
          assert::fail(string::format("updated index = {}, value = {}", index, value));
      };
      
      std::swap(items[0], items[1]);
      std::swap(items[0], items[1]);
      
      assert::are_equal("z", items[0]);
      assert::are_equal("a", items[1]);
      assert::are_equal(10_z, updated_control_check);
    }
  };
}
