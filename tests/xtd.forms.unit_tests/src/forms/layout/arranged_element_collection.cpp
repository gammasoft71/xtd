#include <algorithm>
#include <xtd/xtd.forms>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::forms;
using namespace xtd::forms::layout;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_arranged_element_collection) {
  public:
    void test_method_(new_collection) {
      arranged_element_collection<std::string> items;
      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };
      
      assert::is_true_(items.empty());
    }
    
    void test_method_(push_back_item) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
          added_control_check += 1;
        } else
          assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };
      
      items.push_back("a");
      
      assert::is_false_(items.empty());
      assert::are_equal_(1, items.size());
      assert::are_equal_("a", items[0]);
      assert::are_equal_(1, added_control_check);
    }
    
    void test_method_(push_back_items) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal_(1, index);
          assert::are_equal_("b", value);
          added_control_check += 2;
        } else if (added_control_check == 3) {
          assert::are_equal_(2, index);
          assert::are_equal_("c", value);
          added_control_check += 3;
        } else
          assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };
      
      items.push_back("a");
      items.push_back("b");
      items.push_back("c");
      
      assert::is_false_(items.empty());
      assert::are_equal_(3, items.size());
      assert::are_equal_("a", items[0]);
      assert::are_equal_("b", items[1]);
      assert::are_equal_("c", items[2]);
      assert::are_equal_(6, added_control_check);
    }
    
    void test_method_(push_back_range_item) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
         if (added_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
           added_control_check += 1;
        } else
          assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.push_back_range({"a"});

      assert::is_false_(items.empty());
      assert::are_equal_(1, items.size());
      assert::are_equal_("a", items[0]);
      assert::are_equal_(1, added_control_check);
    }
    
    void test_method_(push_back_range_items) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal_(1, index);
          assert::are_equal_("b", value);
          added_control_check += 2;
        } else if (added_control_check == 3) {
          assert::are_equal_(2, index);
          assert::are_equal_("c", value);
          added_control_check += 3;
        } else
          assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.push_back_range({"a", "b", "c"});
      
      assert::is_false_(items.empty());
      assert::are_equal_(3, items.size());
      assert::are_equal_("a", items[0]);
      assert::are_equal_("b", items[1]);
      assert::are_equal_("c", items[2]);
      assert::are_equal_(6, added_control_check);
    }
    
    void test_method_(insert_item) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
         if (added_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
           added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal_(1, index);
          assert::are_equal_("b", value);
          added_control_check += 2;
        } else if (added_control_check == 3) {
          assert::are_equal_(2, index);
          assert::are_equal_("c", value);
          added_control_check += 3;
        } else if (added_control_check == 6) {
          assert::are_equal_(1, index);
          assert::are_equal_("z", value);
          added_control_check += 4;
        } else
          assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.push_back_range({"a", "b", "c"});
      
      assert::are_equal_(6, added_control_check);
      
      items.insert(items.cbegin() + 1, "z");
      
      assert::are_equal_(4, items.size());
      assert::are_equal_("a", items[0]);
      assert::are_equal_("z", items[1]);
      assert::are_equal_("b", items[2]);
      assert::are_equal_("c", items[3]);
      assert::are_equal_(10, added_control_check);
    }
      
    void test_method_(insert_item_in_first) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal_(0, index);
          assert::are_equal_("z", value);
          added_control_check += 2;
        } else
          assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.push_back("a");
      items.insert(items.cbegin(), "z");

      assert::are_equal_("z", items[0]);
      assert::are_equal_("a", items[1]);
      assert::are_equal_(3, added_control_check);
    }
        
    void test_method_(insert_item_in_last) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal_(1, index);
          assert::are_equal_("z", value);
          added_control_check += 2;
        } else
          assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.push_back("a");
      items.insert(items.cbegin() + 1, "z");

      assert::are_equal_("a", items[0]);
      assert::are_equal_("z", items[1]);
      assert::are_equal_(3, added_control_check);
    }

    void test_method_(insert_at_item) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
         if (added_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
           added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal_(1, index);
          assert::are_equal_("b", value);
          added_control_check += 2;
        } else if (added_control_check == 3) {
          assert::are_equal_(2, index);
          assert::are_equal_("c", value);
          added_control_check += 3;
        } else if (added_control_check == 6) {
          assert::are_equal_(1, index);
          assert::are_equal_("z", value);
          added_control_check += 4;
        } else
          assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.push_back_range({"a", "b", "c"});
      
      assert::are_equal_(6, added_control_check);
      
      items.insert_at(1, "z");
      
      assert::are_equal_(4, items.size());
      assert::are_equal_("a", items[0]);
      assert::are_equal_("z", items[1]);
      assert::are_equal_("b", items[2]);
      assert::are_equal_("c", items[3]);
      assert::are_equal_(10, added_control_check);
    }
        
    void test_method_(insert_at_item_width_bad_index) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"a", "b", "c"});
      assert::throws_(invalid_argument, [&] {items.insert_at(-1, "z");});
    }
      
    void test_method_(insert_at_item_in_first) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal_(0, index);
          assert::are_equal_("z", value);
          added_control_check += 2;
        } else
          assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.push_back("a");
      items.insert_at(0, "z");

      assert::are_equal_("z", items[0]);
      assert::are_equal_("a", items[1]);
      assert::are_equal_(3, added_control_check);
    }
        
    void test_method_(insert_at_item_in_last) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal_(1, index);
          assert::are_equal_("z", value);
          added_control_check += 2;
        } else
          assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.push_back("a");
      items.insert_at(1, "z");

      assert::are_equal_("a", items[0]);
      assert::are_equal_("z", items[1]);
      assert::are_equal_(3, added_control_check);
    }
    
    void test_method_(erase_item) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"a", "b", "c", "d", "e"});
      size_t erased_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        if (erased_control_check == 0) {
          assert::are_equal_(1, index);
          assert::are_equal_("b", value);
          erased_control_check += 1;
        } else
          assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.erase_at(1);

      assert::are_equal_("a", items[0]);
      assert::are_equal_("c", items[1]);
      assert::are_equal_("d", items[2]);
      assert::are_equal_("e", items[3]);
      assert::are_equal_(1, erased_control_check);
    }
      
    void test_method_(erase_all_items) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"a", "b", "c", "d", "e"});
      size_t erased_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        if (erased_control_check == 0) {
          assert::are_equal_(1, index);
          assert::are_equal_("b", value);
          erased_control_check += 1;
        } else if (erased_control_check == 1) {
          assert::are_equal_(2, index);
          assert::are_equal_("d", value);
          erased_control_check += 2;
        } else if (erased_control_check == 3) {
          assert::are_equal_(1, index);
          assert::are_equal_("c", value);
          erased_control_check += 3;
        } else if (erased_control_check == 6) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
          erased_control_check += 4;
        } else if (erased_control_check == 10) {
          assert::are_equal_(0, index);
          assert::are_equal_("e", value);
          erased_control_check += 5;
        } else
          assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.erase_at(1);
      items.erase_at(2);
      items.erase_at(1);
      items.erase_at(0);
      items.erase_at(0);

      assert::is_true_(items.empty());
      assert::are_equal_(15, erased_control_check);
    }
      
    void test_method_(erase_item_first) {
      arranged_element_collection<std::string> items;
      size_t erased_control_check = 0;
      items.push_back_range({"a", "b", "c", "d", "e"});
      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        if (erased_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
          erased_control_check += 1;
        } else
          assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.erase_at(0);

      assert::are_equal_("b", items[0]);
      assert::are_equal_("c", items[1]);
      assert::are_equal_("d", items[2]);
      assert::are_equal_("e", items[3]);
      assert::are_equal_(1, erased_control_check);
    }
      
    void test_method_(erase_item_last) {
      arranged_element_collection<std::string> items;
      size_t erased_control_check = 0;
      items.push_back_range({"a", "b", "c", "d", "e"});
      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        if (erased_control_check == 0) {
          assert::are_equal_(4, index);
          assert::are_equal_("e", value);
          erased_control_check += 1;
        } else
          assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items.erase_at(4);

      assert::are_equal_("a", items[0]);
      assert::are_equal_("b", items[1]);
      assert::are_equal_("c", items[2]);
      assert::are_equal_("d", items[3]);
      assert::are_equal_(1, erased_control_check);
    }
        
    void test_method_(erase_at_item_width_bad_index) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"a", "b", "c"});
      assert::throws_(invalid_argument, [&] {items.erase_at(-1);});
    }

    void test_method_(update_item) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"a", "b", "c", "d", "e"});
      size_t updated_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        if (updated_control_check == 0) {
          assert::are_equal_(1, index);
          assert::are_equal_("z", value);
          updated_control_check += 1;
        } else
          assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      items[1] = "z";

      assert::are_equal_("a", items[0]);
      assert::are_equal_("z", items[1]);
      assert::are_equal_("c", items[2]);
      assert::are_equal_("d", items[3]);
      assert::are_equal_("e", items[4]);
      assert::are_equal_(1, updated_control_check);
    }

    void test_method_(using_std_sort_two_items) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"z", "a"});

      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::succeed(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      std::sort(items.begin(), items.end());
      
      assert::are_equal_("a", items[0]);
      assert::are_equal_("z", items[1]);
    }
    
    void test_method_(using_std_sort_four_items) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"d", "a", "c", "b"});

      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::succeed(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      std::sort(items.begin(), items.end());
      
      assert::are_equal_("a", items[0]);
      assert::are_equal_("b", items[1]);
      assert::are_equal_("c", items[2]);
      assert::are_equal_("d", items[3]);
    }
    
    void test_method_(using_std_sort_Twelve_items_with_duplicates) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"d", "a", "c", "b", "g", "i", "b", "h", "f", "j", "f", "k"});

      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::succeed(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      std::sort(items.begin(), items.end());
      
      assert::are_equal_("a", items[0]);
      assert::are_equal_("b", items[1]);
      assert::are_equal_("b", items[2]);
      assert::are_equal_("c", items[3]);
      assert::are_equal_("d", items[4]);
      assert::are_equal_("f", items[5]);
      assert::are_equal_("f", items[6]);
      assert::are_equal_("g", items[7]);
      assert::are_equal_("h", items[8]);
      assert::are_equal_("i", items[9]);
      assert::are_equal_("j", items[10]);
      assert::are_equal_("k", items[11]);
    }

    void test_method_(using_std_swap) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"z", "a"});
      size_t updated_control_check = 0;

      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        if (updated_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
          updated_control_check += 1;
        } else if (updated_control_check == 1) {
          assert::are_equal_(1, index);
          assert::are_equal_("z", value);
          updated_control_check += 2;
        } else
          assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      std::swap(items[0], items[1]);
      
      assert::are_equal_("a", items[0]);
      assert::are_equal_("z", items[1]);
      assert::are_equal_(3, updated_control_check);
    }
    
    void test_method_(using_std_double_swap) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"z", "a"});
      size_t updated_control_check = 0;

      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(strings::format("added index = {}, value = {}", index, value), line_info_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(strings::format("erased index = {}, value = {}", index, value), line_info_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        if (updated_control_check == 0) {
          assert::are_equal_(0, index);
          assert::are_equal_("a", value);
          updated_control_check += 1;
        } else if (updated_control_check == 1) {
          assert::are_equal_(1, index);
          assert::are_equal_("z", value);
          updated_control_check += 2;
        } else if (updated_control_check == 3) {
          assert::are_equal_(0, index);
          assert::are_equal_("z", value);
          updated_control_check += 3;
        } else if (updated_control_check == 6) {
          assert::are_equal_(1, index);
          assert::are_equal_("a", value);
          updated_control_check += 4;
        } else
          assert::fail(strings::format("updated index = {}, value = {}", index, value), line_info_);
      };

      std::swap(items[0], items[1]);
      std::swap(items[0], items[1]);

      assert::are_equal_("z", items[0]);
      assert::are_equal_("a", items[1]);
      assert::are_equal_(10, updated_control_check);
    }
  };
}
