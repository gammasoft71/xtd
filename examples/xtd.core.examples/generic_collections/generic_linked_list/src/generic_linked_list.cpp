#include <xtd/xtd>

using namespace text;

class example {
public:
  static auto main() -> void {
    // Create the link list.
    auto sentence = linked_list<string> { "the", "fox", "jumps", "over", "the", "dog" };
    display(sentence, "The linked list values:");
    
    // Add the word 'today' to the beginning of the linked list.
    sentence.add_first("today");
    display(sentence, "Test 1: Add 'today' to beginning of the list:");
    
    // Move the first node to be the last node.
    auto node = *sentence.first();
    sentence.remove(node);
    sentence.add_last(node);
    display(sentence, "Test 2: Move first node to be last node:");
    
    // Change the last node to 'yesterday'.
    sentence.remove_last();
    sentence.add_last("yesterday");
    display(sentence, "Test 3: Change the last node to 'yesterday':");
    
    // Move the last node to be the first node.
    node = *sentence.last();
    sentence.remove(node);
    sentence.add_first(node);
    display(sentence, "Test 4: Move last node to be first node:");
    
    // Indicate the last occurence of 'the'.
    sentence.remove_first();
    node = *sentence.find_last("the");
    indicate_node(node, "Test 5: Indicate last occurence of 'the':");
    
    // Add 'lazy' and 'old' after 'the' (the linked_list_node named node).
    sentence.add_after(node, "old");
    sentence.add_after(*sentence.find_last("the"), "lazy");
    indicate_node(*sentence.find_last("the"), "Test 6: Add 'lazy' and 'old' after 'the':");
    
    // Indicate 'fox' node.
    node = *sentence.find_last("fox");
    indicate_node(node, "Test 7: Indicate the 'fox' node:");
    
    // Add 'quick' and 'brown' before 'fox':
    sentence.add_before(*sentence.find("fox"), "quick");
    sentence.add_before(*sentence.find("fox"), "brown");
    indicate_node(*sentence.find("fox"), "Test 8: Add 'quick' and 'brown' before 'fox':");
    
    // Keep a reference to the current node, 'fox', and to the previous node in the list. Indicate the 'dog' node.
    node = *sentence.find_last("dog")->previous();
    indicate_node(*sentence.find("dog"), "Test 9: Indicate the 'dog' node:");
    
    // The add_before method throws an invalid_operation_exception if you try to add a node that already belongs to a list.
    console::write_line("Test 10: Throw exception by adding node (fox) already in the list:");
    try {
      sentence.add_before(*sentence.find("fox"), node);
    } catch (const invalid_operation_exception& ex) {
      console::write_line("Exception message: {}", ex.message());
    }
    console::write_line();
    
    // Remove the 'fox' node, and then add it before the 'dog' node.
    // Indicate the node referred to by current.
    node = *sentence.find("fox");
    sentence.remove(node);
    sentence.add_before(*sentence.find("dog"), node);
    node = *sentence.find("dog");
    indicate_node(node, "Test 11: Move a referenced node (fox) before the current node (dog):");
    
    // Remove the node referred to by node.
    sentence.remove(node);
    node = sentence.find("dog") ? *sentence.find("dog") : linked_list_node<string>("dog");
    indicate_node(node, "Test 12: Remove current node (dog) and attempt to indicate it:");
    
    // Add the node after the 'brown' node.
    sentence.add_after(*sentence.find("brown"), node);
    indicate_node(node, "Test 13: Add node removed in test 12 after a referenced node (brown):");
    
    // The Remove method finds and removes the first node that that has the specified value.
    sentence.remove("old");
    display(sentence, "Test 14: Remove node that has the value 'old':");
    
    // When the linked list is cast to icollection(Of string), the add method adds a node to the end of the list.
    sentence.remove_last();
    auto& icoll = as<icollection<string>>(sentence);
    icoll.add("rhinoceros");
    display(sentence, "Test 15: Remove last node, cast to icollection, and add 'rhinoceros':");
    
    console::write_line("Test 16: Copy the list to an array:");
    // Create an array with the same number of elements as the linked list.
    auto sarray = array<string>(sentence.count());
    sentence.copy_to(sarray, 0);
    
    for (auto s : sarray)
      console::write_line(s);
    
    console::write_line();
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
      result.append(" " + node_next->value());
      node_next = node_next->next();
    }
    
    console::write_line(result);
    console::write_line();
  }
};

startup_(example::main);

// This code produces the following output :
//
// The linked list values:
// the fox jumps over the dog
//
// Test 1: Add 'today' to beginning of the list:
// today the fox jumps over the dog
//
// Test 2: Move first node to be last node:
// the fox jumps over the dog today
//
// Test 3: Change the last node to 'yesterday':
// the fox jumps over the dog yesterday
//
// Test 4: Move last node to be first node:
// yesterday the fox jumps over the dog
//
// Test 5: Indicate last occurence of 'the':
// the fox jumps over (the) dog
//
// Test 6: Add 'lazy' and 'old' after 'the':
// the fox jumps over (the) lazy old dog
//
// Test 7: Indicate the 'fox' node:
// the (fox) jumps over the lazy old dog
//
// Test 8: Add 'quick' and 'brown' before 'fox':
// the quick brown (fox) jumps over the lazy old dog
//
// Test 9: Indicate the 'dog' node:
// the quick brown fox jumps over the lazy old (dog)
//
// Test 10: Throw exception by adding node (fox) already in the list:
// Exception message: The linked_list node belongs a linked_list.
//
// Test 11: Move a referenced node (fox) before the current node (dog):
// the quick brown jumps over the lazy old fox (dog)
//
// Test 12: Remove current node (dog) and attempt to indicate it:
// Node 'dog' is not in the list.
//
// Test 13: Add node removed in test 12 after a referenced node (brown):
// the quick brown (dog) jumps over the lazy old fox
//
// Test 14: Remove node that has the value 'old':
// the quick brown dog jumps over the lazy fox
//
// Test 15: Remove last node, cast to icollection, and add 'rhinoceros':
// the quick brown dog jumps over the lazy rhinoceros
//
// Test 16: Copy the list to an array:
// the
// quick
// brown
// dog
// jumps
// over
// the
// lazy
// rhinoceros
//
// Test 17: linked list Contains 'jumps' = true
//
// Test 18: Cleared linked list Contains 'jumps' = false

