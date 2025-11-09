#include <xtd/xtd>

using namespace text;

class example {
public:
  static auto main() -> void {
    // Create a new linked_list_node of type string and displays its properties.
    auto lln = linked_list_node<string> {"orange"};
    console::write_line("After creating the node ....");
    display_properties(lln);
    
    // Create a new linked_list.
    auto ll = linked_list<string> {};
    
    // Add the "orange" node and display its properties.
    ll.add_last(lln);
    console::write_line("After adding the node to the empty linked_list ....");
    display_properties(lln);
    
    // Add nodes before and after the "orange" node and display the "orange" node's properties.
    ll.add_first("red");
    ll.add_last("yellow");
    lln = *ll.find("orange");
    console::write_line("After adding red and yellow ....");
    display_properties(lln);
  }

  static void display_properties(const linked_list_node<string>& lln )  {
    if (lln.list().is_empty())
      console::write_line("   Node is not linked.");
    else
      console::write_line("   Node belongs to a linked list with {0} elements.", lln.list().get().count());
    
    if (lln.previous() == nullopt)
      console::write_line("   Previous node is null.");
    else
      console::write_line("   Value of previous node: {0}", lln.previous()->value());
    
    console::write_line("   Value of current node:  {0}", lln.value());
    
    if (lln.next() == nullopt)
      console::write_line("   Next node is null.");
    else
      console::write_line("   Value of next node:     {0}", lln.next()->value());
    
    console::write_line();
  }
};

startup_(example::main);

// This code produces the following output :
//
// After creating the node ....
//    Node is not linked.
//    Previous node is null.
//    Value of current node:  orange
//    Next node is null.
//
// After adding the node to the empty linked_list ....
//    Node belongs to a linked list with 1 elements.
//    Previous node is null.
//    Value of current node:  orange
//    Next node is null.
//
// After adding red and yellow ....
//    Node belongs to a linked list with 3 elements.
//    Value of previous node: red
//    Value of current node:  orange
//    Value of next node:     yellow
//
