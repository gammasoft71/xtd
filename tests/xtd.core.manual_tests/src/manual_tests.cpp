#include <xtd/collections/generic/linked_list>
#include <xtd/println>

auto main() -> int {
  auto list = linked_list<int> {12, 10, 8};

  list.add_first(14);
  list.add_last(6);
  println("list = {}", list);
  println();
  
  auto node = list.add_before(*list.first(), 18);
  println("node = {}", node.value());
  node = list.add_after(node, 16);
  println("node = {}", node.value());
  println();

  node = list.add_after(*list.last(), 2);
  println("node = {}", node.value());
  node = list.add_before(node, 4);
  println("node = {}", node.value());
  println();

  println("Iterators :");
  for (auto iterator = list.begin(); iterator != list.end(); ++iterator)
    println("  * {}", *iterator);
  println();
  

  println("Reverse :");
  for (auto node = list.last(); node; node = node->previous())
    println("  * {}", node->value());
  println();

  println("linq : {}", list.order_by([](auto v) {return v;}).select<double>([](auto v) {return as<double>(v) / 4;}));
}

// This code produces the following output :
//
// list = [14, 12, 10, 8, 6]
//
// node = 18
// node = 16
//
// node = 2
// node = 4
//
// Items :
// * 18
// * 16
// * 14
// * 12
// * 10
// * 8
// * 6
// * 4
// * 2
