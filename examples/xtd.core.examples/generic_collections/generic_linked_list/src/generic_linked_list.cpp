#include <xtd/xtd>

using namespace text;

class example {
public:
  static auto main() -> void {
    // Create the link list.
    auto words = array<string> { "the", "fox", "jumps", "over", "the", "dog" };
    auto sentence = linked_list<string>(words);
    display(sentence, "The linked list values:");
    
    // Add the word 'today' to the beginning of the linked list.
    sentence.add_first("today");
    display(sentence, "Test 1: Add 'today' to beginning of the list:");
    
    // Move the first node to be the last node.
    auto mark1 = sentence.first()->value();
    sentence.remove_first();
    sentence.add_last(mark1);
    display(sentence, "Test 2: Move first node to be last node:");
    
    // Change the last node to 'yesterday'.
    sentence.remove_last();
    sentence.add_last("yesterday");
    display(sentence, "Test 3: Change the last node to 'yesterday':");
    
    // Move the last node to be the first node.
    mark1 = sentence.last()->value();
    sentence.remove_last();
    sentence.add_first(mark1);
    display(sentence, "Test 4: Move last node to be first node:");
    
    // Indicate the last occurence of 'the'.
    sentence.remove_first();
    auto current = sentence.find_last("the");
    indicate_node(*current, "Test 5: Indicate last occurence of 'the':");
    
    // Add 'lazy' and 'old' after 'the' (the linked_list_node named current).
    sentence.add_after(*current, "old");
    sentence.add_after(*current, "lazy");
    indicate_node(*current, "Test 6: Add 'lazy' and 'old' after 'the':");
    
    // Indicate 'fox' node.
    current = sentence.find("fox");
    indicate_node(*current, "Test 7: Indicate the 'fox' node:");
    
    // Add 'quick' and 'brown' before 'fox':
    sentence.add_before(*current, "quick");
    sentence.add_before(*current, "brown");
    indicate_node(*current, "Test 8: Add 'quick' and 'brown' before 'fox':");
    
    // Keep a reference to the current node, 'fox',
    // and to the previous node in the list. Indicate the 'dog' node.
    mark1 = current->value();
    auto mark2 = current->previous();
    current = sentence.find("dog");
    indicate_node(*current, "Test 9: Indicate the 'dog' node:");
    
    // The AddBefore method throws an InvalidOperationException
    // if you try to add a node that already belongs to a list.
    console::write_line("Test 10: Throw exception by adding node (fox) already in the list:");
    try {
      sentence.add_before(*current, mark1);
    } catch (const invalid_operation_exception& ex) {
      console::write_line("Exception message: {0}", ex.message());
    }
    console::write_line();
    
    // Remove the node referred to by mark1, and then add it
    // before the node referred to by current.
    // Indicate the node referred to by current.
    sentence.remove(mark1);
    sentence.add_before(*current, mark1);
    indicate_node(*current, "Test 11: Move a referenced node (fox) before the current node (dog):");
    
    // Remove the node referred to by current.
    sentence.remove(*current);
    indicate_node(*current, "Test 12: Remove current node (dog) and attempt to indicate it:");
    
    // Add the node after the node referred to by mark2.
    sentence.add_after(*mark2, current->value());
    indicate_node(*current, "Test 13: Add node removed in test 12 after a referenced node (brown):");
    
    // The Remove method finds and removes the
    // first node that that has the specified value.
    sentence.remove("old");
    display(sentence, "Test 14: Remove node that has the value 'old':");
    
    // When the linked list is cast to ICollection(Of String),
    // the Add method adds a node to the end of the list.
    sentence.remove_last();
    auto& icoll = as<icollection<string>>(sentence);
    icoll.add("rhinoceros");
    display(sentence, "Test 15: Remove last node, cast to ICollection, and add 'rhinoceros':");
    
    console::write_line("Test 16: Copy the list to an array:");
    // Create an array with the same number of
    // elements as the linked list.
    auto sarray = array<string>(sentence.count());
    sentence.copy_to(sarray, 0);
    
    for (auto s : sarray)
      console::write_line(s);
    
    console::write_line("Test 17: linked list Contains 'jumps' = {0}", sentence.contains("jumps"));
    
    // Release all the nodes.
    sentence.clear();
    
    console::write_line();
    console::write_line("Test 18: Cleared linked list Contains 'jumps' = {0}", sentence.contains("jumps"));
  }
  
  static void display(const linked_list<string>& words, const string& test) {
    console::write_line(test);
    for (auto word : words)
      console::write(word + " ");
    console::write_line();
    console::write_line();
  }
  
  static void indicate_node(const linked_list_node<string>& node, const string& test) {
    console::write_line(test);
    auto l = node.list();
    if (!l) {
      console::write_line("Node '{0}' is not in the list.\n", node.value());
      return;
    }
    
    auto result = string_builder {"(" + node.value() + ")"};
    
    auto node_previous = node.previous();
    while (node_previous) {
      result.insert(0, node_previous->value() + " ");
      node_previous = node_previous->previous();
    }
    
    auto node_next = node.next();
    while (node_next) {
      result.append(" " + node.value());
      node_next = node_next->next();
    }
    
    console::write_line(result);
    console::write_line();
  }
};

startup_(example::main);

// This code produces the following output :
//
