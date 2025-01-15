#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

class example {
public:
  static auto main() -> void {
    // Create a new dictionary of strings, with string keys.
    //
    auto open_with = dictionary<string, string>();
    
    // Add some elements to the dictionary. There are no
    // duplicate keys, but some of the values are duplicates.
    open_with.add("txt", "notepad.exe");
    open_with.add("bmp", "paint.exe");
    open_with.add("dib", "paint.exe");
    open_with.add("rtf", "wordpad.exe");
    
    // The Add method throws an exception if the new key is
    // already in the dictionary.
    try {
      open_with.add("txt", "winword.exe");
    } catch (const argument_exception&) {
      console::write_line("An element with Key = \"txt\" already exists.");
    }
    
    // The Item property is another name for the indexer, so you
    // can omit its name when accessing elements.
    console::write_line("For key = \"rtf\", value = {0}.", xtd::as_const(open_with)["rtf"]);
    
    // The indexer can be used to change the value associated
    // with a key.
    open_with["rtf"] = "winword.exe";
    console::write_line("For key = \"rtf\", value = {0}.", xtd::as_const(open_with)["rtf"]);
    
    // If a key does not exist, setting the indexer for that key
    // adds a new key/value pair.
    open_with["doc"] = "winword.exe";
    
    // The indexer throws an exception if the requested key is not in the dictionary.
    try {
      console::write_line("For key = \"tif\", value = {0}.", xtd::as_const(open_with)["tif"]);
    } catch (const key_not_found_exception&) {
      console::write_line("Key = \"tif\" is not found.");
    }
    
    // When a program often has to try keys that turn out not to
    // be in the dictionary, TryGetValue can be a more efficient
    // way to retrieve values.
    auto value = ""_s;
    if (open_with.try_get_value("tif", value))
      console::write_line("For key = \"tif\", value = {0}.", value);
    else
      console::write_line("Key = \"tif\" is not found.");
    
    // ContainsKey can be used to test keys before inserting
    // them.
    if (!open_with.contains_key("ht")) {
      open_with.add("ht", "hypertrm.exe");
      console::write_line("Value added for key = \"ht\": {0}", xtd::as_const(open_with)["ht"]);
    }
    
    // When you use foreach to enumerate dictionary elements,
    // the elements are retrieved as KeyValuePair objects.
    console::write_line();
    for (const key_value_pair<string, string>& kvp : open_with)
      console::write_line("Key = {0}, Value = {1}", kvp.key(), kvp.value());
    
    // To get the values alone, use the Values property.
    dictionary<string, string>::value_collection values = open_with.values();
    
    // The elements of the ValueCollection are strongly typed
    // with the type that was specified for dictionary values.
    console::write_line();
    for(const string& s : values)
      console::write_line("Value = {0}", s);
    
    // To get the keys alone, use the Keys property.
    dictionary<string, string>::key_collection keys = open_with.keys();
    
    // The elements of the KeyCollection are strongly typed
    // with the type that was specified for dictionary keys.
    console::write_line();
    for(const string& s : keys)
      console::write_line("Key = {0}", s);
    
    // Use the Remove method to remove a key/value pair.
    console::write_line("\nRemove(\"doc\")");
    open_with.remove("doc");
    
    if (!open_with.contains_key("doc"))
      console::write_line("Key \"doc\" is not found.");
  }
};

startup_(example::main);

// This code produces the following output :
//
// An element with Key = "txt" already exists.
// For key = "rtf", value = wordpad.exe.
// For key = "rtf", value = winword.exe.
// Key = "tif" is not found.
// Key = "tif" is not found.
// Value added for key = "ht": hypertrm.exe
//
// Key = doc, Value = winword.exe
// Key = rtf, Value = winword.exe
// Key = bmp, Value = paint.exe
// Key = ht, Value = hypertrm.exe
// Key = dib, Value = paint.exe
// Key = txt, Value = notepad.exe
//
// Value = winword.exe
// Value = winword.exe
// Value = paint.exe
// Value = hypertrm.exe
// Value = paint.exe
// Value = notepad.exe
//
// Key = doc
// Key = rtf
// Key = bmp
// Key = ht
// Key = dib
// Key = txt
//
// Remove("doc")
// Key "doc" is not found.
