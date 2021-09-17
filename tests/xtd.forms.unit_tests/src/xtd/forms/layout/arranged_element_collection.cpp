#include <algorithm>
#include <xtd/ustring.h>
#include <xtd/forms/layout/arranged_element_collection.h>
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
        assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };
      
      assert::is_true(items.empty(), csf_);
    }
    
    void test_method_(push_back_item) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
          added_control_check += 1;
        } else
          assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };
      
      items.push_back("a");
      
      assert::is_false(items.empty(), csf_);
      assert::are_equal(1U, items.size(), csf_);
      assert::are_equal("a", items[0], csf_);
      assert::are_equal(1U, added_control_check, csf_);
    }
    
    void test_method_(push_back_items) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("b", value, csf_);
          added_control_check += 2;
        } else if (added_control_check == 3) {
          assert::are_equal(2U, index, csf_);
          assert::are_equal("c", value, csf_);
          added_control_check += 3;
        } else
          assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };
      
      items.push_back("a");
      items.push_back("b");
      items.push_back("c");
      
      assert::is_false(items.empty(), csf_);
      assert::are_equal(3U, items.size(), csf_);
      assert::are_equal("a", items[0], csf_);
      assert::are_equal("b", items[1], csf_);
      assert::are_equal("c", items[2], csf_);
      assert::are_equal(6U, added_control_check, csf_);
    }
    
    void test_method_(push_back_range_item) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
         if (added_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
           added_control_check += 1;
        } else
          assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.push_back_range({"a"});

      assert::is_false(items.empty(), csf_);
      assert::are_equal(1U, items.size(), csf_);
      assert::are_equal("a", items[0], csf_);
      assert::are_equal(1U, added_control_check, csf_);
    }
    
    void test_method_(push_back_range_items) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("b", value, csf_);
          added_control_check += 2;
        } else if (added_control_check == 3) {
          assert::are_equal(2U, index, csf_);
          assert::are_equal("c", value, csf_);
          added_control_check += 3;
        } else
          assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.push_back_range({"a", "b", "c"});
      
      assert::is_false(items.empty(), csf_);
      assert::are_equal(3U, items.size(), csf_);
      assert::are_equal("a", items[0], csf_);
      assert::are_equal("b", items[1], csf_);
      assert::are_equal("c", items[2], csf_);
      assert::are_equal(6U, added_control_check, csf_);
    }
    
    void test_method_(insert_item) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
         if (added_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
           added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("b", value, csf_);
          added_control_check += 2;
        } else if (added_control_check == 3) {
          assert::are_equal(2U, index, csf_);
          assert::are_equal("c", value, csf_);
          added_control_check += 3;
        } else if (added_control_check == 6) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("z", value, csf_);
          added_control_check += 4;
        } else
          assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.push_back_range({"a", "b", "c"});
      
      assert::are_equal(6U, added_control_check, csf_);
      
      items.insert(items.cbegin() + 1, "z");
      
      assert::are_equal(4U, items.size(), csf_);
      assert::are_equal("a", items[0], csf_);
      assert::are_equal("z", items[1], csf_);
      assert::are_equal("b", items[2], csf_);
      assert::are_equal("c", items[3], csf_);
      assert::are_equal(10U, added_control_check, csf_);
    }
      
    void test_method_(insert_item_in_first) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("z", value, csf_);
          added_control_check += 2;
        } else
          assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.push_back("a");
      items.insert(items.cbegin(), "z");

      assert::are_equal("z", items[0], csf_);
      assert::are_equal("a", items[1], csf_);
      assert::are_equal(3U, added_control_check, csf_);
    }
        
    void test_method_(insert_item_in_last) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("z", value, csf_);
          added_control_check += 2;
        } else
          assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.push_back("a");
      items.insert(items.cbegin() + 1, "z");

      assert::are_equal("a", items[0], csf_);
      assert::are_equal("z", items[1], csf_);
      assert::are_equal(3U, added_control_check, csf_);
    }

    void test_method_(insert_at_item) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
         if (added_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
           added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("b", value, csf_);
          added_control_check += 2;
        } else if (added_control_check == 3) {
          assert::are_equal(2U, index, csf_);
          assert::are_equal("c", value, csf_);
          added_control_check += 3;
        } else if (added_control_check == 6) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("z", value, csf_);
          added_control_check += 4;
        } else
          assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.push_back_range({"a", "b", "c"});
      
      assert::are_equal(6U, added_control_check, csf_);
      
      items.insert_at(1, "z");
      
      assert::are_equal(4U, items.size(), csf_);
      assert::are_equal("a", items[0], csf_);
      assert::are_equal("z", items[1], csf_);
      assert::are_equal("b", items[2], csf_);
      assert::are_equal("c", items[3], csf_);
      assert::are_equal(10U, added_control_check, csf_);
    }
        
    void test_method_(insert_at_item_width_bad_index) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"a", "b", "c"});
      assert::throws<argument_out_of_range_exception>([&] {items.insert_at(items.npos, "z");}, csf_);
    }
      
    void test_method_(insert_at_item_in_first) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("z", value, csf_);
          added_control_check += 2;
        } else
          assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.push_back("a");
      items.insert_at(0, "z");

      assert::are_equal("z", items[0], csf_);
      assert::are_equal("a", items[1], csf_);
      assert::are_equal(3U, added_control_check, csf_);
    }
        
    void test_method_(insert_at_item_in_last) {
      arranged_element_collection<std::string> items;
      size_t added_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        if (added_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
          added_control_check += 1;
        } else if (added_control_check == 1) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("z", value, csf_);
          added_control_check += 2;
        } else
          assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.push_back("a");
      items.insert_at(1, "z");

      assert::are_equal("a", items[0], csf_);
      assert::are_equal("z", items[1], csf_);
      assert::are_equal(3U, added_control_check, csf_);
    }
    
    void test_method_(erase_item) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"a", "b", "c", "d", "e"});
      size_t erased_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        if (erased_control_check == 0) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("b", value, csf_);
          erased_control_check += 1;
        } else
          assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.erase_at(1);

      assert::are_equal("a", items[0], csf_);
      assert::are_equal("c", items[1], csf_);
      assert::are_equal("d", items[2], csf_);
      assert::are_equal("e", items[3], csf_);
      assert::are_equal(1U, erased_control_check);
    }
      
    void test_method_(erase_all_items) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"a", "b", "c", "d", "e"});
      size_t erased_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        if (erased_control_check == 0) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("b", value, csf_);
          erased_control_check += 1;
        } else if (erased_control_check == 1) {
          assert::are_equal(2U, index, csf_);
          assert::are_equal("d", value, csf_);
          erased_control_check += 2;
        } else if (erased_control_check == 3) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("c", value, csf_);
          erased_control_check += 3;
        } else if (erased_control_check == 6) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
          erased_control_check += 4;
        } else if (erased_control_check == 10) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("e", value, csf_);
          erased_control_check += 5;
        } else
          assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.erase_at(1);
      items.erase_at(2);
      items.erase_at(1);
      items.erase_at(0);
      items.erase_at(0);

      assert::is_true(items.empty(), csf_);
      assert::are_equal(15U, erased_control_check);
    }
      
    void test_method_(erase_item_first) {
      arranged_element_collection<std::string> items;
      size_t erased_control_check = 0;
      items.push_back_range({"a", "b", "c", "d", "e"});
      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        if (erased_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
          erased_control_check += 1;
        } else
          assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.erase_at(0);

      assert::are_equal("b", items[0], csf_);
      assert::are_equal("c", items[1], csf_);
      assert::are_equal("d", items[2], csf_);
      assert::are_equal("e", items[3], csf_);
      assert::are_equal(1U, erased_control_check);
    }
      
    void test_method_(erase_item_last) {
      arranged_element_collection<std::string> items;
      size_t erased_control_check = 0;
      items.push_back_range({"a", "b", "c", "d", "e"});
      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        if (erased_control_check == 0) {
          assert::are_equal(4U, index, csf_);
          assert::are_equal("e", value, csf_);
          erased_control_check += 1;
        } else
          assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items.erase_at(4);

      assert::are_equal("a", items[0], csf_);
      assert::are_equal("b", items[1], csf_);
      assert::are_equal("c", items[2], csf_);
      assert::are_equal("d", items[3], csf_);
      assert::are_equal(1U, erased_control_check);
    }
        
    void test_method_(erase_at_item_width_bad_index) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"a", "b", "c"});
      assert::throws<argument_out_of_range_exception>([&] {items.erase_at(items.npos);}, csf_);
    }

    void test_method_(update_item) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"a", "b", "c", "d", "e"});
      size_t updated_control_check = 0;
      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        if (updated_control_check == 0) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("z", value, csf_);
          updated_control_check += 1;
        } else
          assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      items[1] = "z";

      assert::are_equal("a", items[0], csf_);
      assert::are_equal("z", items[1], csf_);
      assert::are_equal("c", items[2], csf_);
      assert::are_equal("d", items[3], csf_);
      assert::are_equal("e", items[4], csf_);
      assert::are_equal(1U, updated_control_check);
    }

    void test_method_(using_std_sort_two_items) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"z", "a"});

      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::succeed(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      std::sort(items.begin(), items.end());
      
      assert::are_equal("a", items[0], csf_);
      assert::are_equal("z", items[1], csf_);
    }
    
    void test_method_(using_std_sort_four_items) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"d", "a", "c", "b"});

      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::succeed(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      std::sort(items.begin(), items.end());
      
      assert::are_equal("a", items[0], csf_);
      assert::are_equal("b", items[1], csf_);
      assert::are_equal("c", items[2], csf_);
      assert::are_equal("d", items[3], csf_);
    }
    
    void test_method_(using_std_sort_Twelve_items_with_duplicates) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"d", "a", "c", "b", "g", "i", "b", "h", "f", "j", "f", "k"});

      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        assert::succeed(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      std::sort(items.begin(), items.end());
      
      assert::are_equal("a", items[0], csf_);
      assert::are_equal("b", items[1], csf_);
      assert::are_equal("b", items[2], csf_);
      assert::are_equal("c", items[3], csf_);
      assert::are_equal("d", items[4], csf_);
      assert::are_equal("f", items[5], csf_);
      assert::are_equal("f", items[6], csf_);
      assert::are_equal("g", items[7], csf_);
      assert::are_equal("h", items[8], csf_);
      assert::are_equal("i", items[9], csf_);
      assert::are_equal("j", items[10], csf_);
      assert::are_equal("k", items[11], csf_);
    }

    void test_method_(using_std_swap) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"z", "a"});
      size_t updated_control_check = 0;

      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        if (updated_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
          updated_control_check += 1;
        } else if (updated_control_check == 1) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("z", value, csf_);
          updated_control_check += 2;
        } else
          assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      std::swap(items[0], items[1]);
      
      assert::are_equal("a", items[0], csf_);
      assert::are_equal("z", items[1], csf_);
      assert::are_equal(3U, updated_control_check);
    }
    
    void test_method_(using_std_double_swap) {
      arranged_element_collection<std::string> items;
      items.push_back_range({"z", "a"});
      size_t updated_control_check = 0;

      items.item_added += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("added index = {}, value = {}", index, value), csf_);
      };
      items.item_erased += [&](size_t index, std::string& value) {
        assert::fail(ustring::format("erased index = {}, value = {}", index, value), csf_);
      };
      items.item_updated += [&](size_t index, std::string& value) {
        if (updated_control_check == 0) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("a", value, csf_);
          updated_control_check += 1;
        } else if (updated_control_check == 1) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("z", value, csf_);
          updated_control_check += 2;
        } else if (updated_control_check == 3) {
          assert::are_equal(0U, index, csf_);
          assert::are_equal("z", value, csf_);
          updated_control_check += 3;
        } else if (updated_control_check == 6) {
          assert::are_equal(1U, index, csf_);
          assert::are_equal("a", value, csf_);
          updated_control_check += 4;
        } else
          assert::fail(ustring::format("updated index = {}, value = {}", index, value), csf_);
      };

      std::swap(items[0], items[1]);
      std::swap(items[0], items[1]);

      assert::are_equal("z", items[0], csf_);
      assert::are_equal("a", items[1], csf_);
      assert::are_equal(10U, updated_control_check);
    }
  };
}
