#include <xtd/xtd>

auto main() -> int {
  // Create a new hash table.
  //
  auto open_with = collections::hashtable {};
  
  // Add some elements to the hash table. There are no
  // duplicate keys, but some of the values are duplicates.
  open_with["txt"] = "notepad.exe";
  open_with["bmp"] = "paint.exe";
  open_with["dib"] = "paint.exe";
  open_with["rtf"] = "wordpad.exe";
  
  // The Item property is the default property, so you
  // can omit its name when accessing elements.
  console::write_line("For key = \"rtf\", value = {0}.", open_with["rtf"]);
  
  // The default Item property can be used to change the value
  // associated with a key.
  open_with["rtf"] = "winword.exe";
  console::write_line("For key = \"rtf\", value = {0}.", open_with["rtf"]);
  
  // If a key does not exist, setting the default Item property
  // for that key adds a new key/value pair.
  open_with["doc"] = "winword.exe";
  
  // contains can be used to test keys before inserting
  // them.
  if (!open_with.contains_key("ht")) {
    open_with["ht"] = "hypertrm.exe";
    console::write_line("Value added for key = \"ht\": {0}", open_with["ht"]);
  }
  
  // When you use foreach to enumerate hash table elements,
  // the elements are retrieved as xtd::collections::generic::key_value_pair objects.
  console::write_line();
  for (auto de : open_with)
    console::write_line("Key = {0}, Value = {1}", de.first, de.second);
    
  // Use the Remove method to remove a key/value pair.
  console::write_line("\nerase(\"doc\")");
  open_with.remove("doc");
  
  if (!open_with.contains_key("doc"))
    console::write_line("Key \"doc\" is not found.");
}

// This code produces the following output :
//
// For key = "rtf", value = wordpad.exe.
// For key = "rtf", value = winword.exe.
// Value added for key = "ht": hypertrm.exe
//
// Key = ht, Value = hypertrm.exe
// Key = doc, Value = winword.exe
// Key = bmp, Value = paint.exe
// Key = rtf, Value = winword.exe
// Key = dib, Value = paint.exe
// Key = txt, Value = notepad.exe
//
// erase("doc")
// Key "doc" is not found.
