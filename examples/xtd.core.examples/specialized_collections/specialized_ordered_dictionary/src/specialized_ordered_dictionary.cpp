#include <xtd/xtd>

class example {
public:
  static auto main() -> void {
    // Creates and initializes a ordered_dictionary.
    auto my_ordered_dictionary = xtd::collections::specialized::ordered_dictionary {};
    my_ordered_dictionary.add("test_key1", "test_value1");
    my_ordered_dictionary.add("test_key2", "test_value2");
    my_ordered_dictionary.add("key_to_delete", "value_to_delete");
    my_ordered_dictionary.add("test_key3", "test_value3");
    
    // Display the contents using the key and value collections
    display_contents(my_ordered_dictionary.keys(), my_ordered_dictionary.values(), my_ordered_dictionary.count());
    
    // Modifying the ordered_dictionary
    if (!as<xtd::collections::idictionary>(my_ordered_dictionary).is_read_only()) {
      // Insert a new key to the beginning of the ordered_dictionary
      my_ordered_dictionary.insert(0, "inserted_key", "inserted_value1");
      
      // Modify the value of the entry with the key "test_key2"
      my_ordered_dictionary["test_key2"] = "modified_value";
      
      // Remove the last entry from the ordered_dictionary: "test_key3"
      my_ordered_dictionary.remove_at(my_ordered_dictionary.count() - 1);
      
      // Remove the "key_to_delete" entry, if it exists
      if (my_ordered_dictionary.contains_key("key_to_delete"))
        my_ordered_dictionary.remove("key_to_delete");
    }
    
    console::write_line("{0}Displaying the entries of a modified ordered_dictionary.", environment::new_line());
    display_contents(my_ordered_dictionary.keys(), my_ordered_dictionary.values(), my_ordered_dictionary.count());
    
    // Clear the ordered_dictionary and add new values
    my_ordered_dictionary.clear();
    my_ordered_dictionary.add("new_key1", "new_value1");
    my_ordered_dictionary.add("new_key2", "new_value2");
    my_ordered_dictionary.add("new_key3", "new_value3");
    
    // Display the contents of the "new" Dictionary using an enumerator
    auto my_enumerator = my_ordered_dictionary.get_enumerator();
    
    console::write_line("{0}Displaying the entries of a \"new\" ordered_dictionary.", environment::new_line());
    display_enumerator(my_enumerator);
  }

  // Displays the contents of the OrderedDictionary from its keys and values
  template<class key_t, class value_t>
  static void display_contents(const icollection<key_t>& key_collection, const icollection<value_t>& value_collection, size dictionary_size) {
    auto my_keys = array<any_object>(dictionary_size);
    auto my_values = array<any_object>(dictionary_size);
    key_collection.copy_to(my_keys, 0);
    value_collection.copy_to(my_values, 0);
    
    // Displays the contents of the OrderedDictionary
    console::write_line("   INDEX KEY                       VALUE");
    for (auto i = 0_z; i < dictionary_size; ++i)
      console::write_line("   {0,-5} {1,-25} {2}", i, my_keys[i], my_values[i]);
    console::write_line();
  }
  
  // Displays the contents of the OrderedDictionary using its enumerator
  static void display_enumerator(enumerator<xtd::collections::dictionary_entry>& my_enumerator) {
    console::write_line("   KEY                       VALUE");
    while (my_enumerator.move_next())
      console::write_line("   {0,-25} {1}", my_enumerator.current().key(), my_enumerator.current().value());
  }
};

startup_(example::main);

// This code produces the following output :
//
